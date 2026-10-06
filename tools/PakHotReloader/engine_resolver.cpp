#include <windows.h>

#include <algorithm>
#include <cstring>
#include <map>
#include <string_view>
#include <vector>

#include "uevr/API.hpp"
#include "engine_resolver.hpp"

using namespace uevr;

namespace pak_hot_reload {
namespace {

struct Section {
    uintptr_t begin{};
    size_t size{};
    bool contains(uintptr_t address) const { return address >= begin && address < begin + size; }
};

struct Image {
    uintptr_t base{};
    Section text;
    Section rdata;
};

// Reads the section table of the game executable from its mapped image.
std::optional<Image> read_image() {
    const auto base = reinterpret_cast<uintptr_t>(GetModuleHandleW(nullptr));
    const auto* dos = reinterpret_cast<const IMAGE_DOS_HEADER*>(base);
    const auto* nt = reinterpret_cast<const IMAGE_NT_HEADERS64*>(base + dos->e_lfanew);
    const auto* section = IMAGE_FIRST_SECTION(nt);
    Image image{base};
    for (WORD i = 0; i < nt->FileHeader.NumberOfSections; ++i, ++section) {
        const Section s{base + section->VirtualAddress, section->Misc.VirtualSize};
        if (std::memcmp(section->Name, ".text", 6) == 0) image.text = s;
        else if (std::memcmp(section->Name, ".rdata", 7) == 0) image.rdata = s;
    }
    if (image.text.size == 0 || image.rdata.size == 0) {
        API::get()->log_error("[engine_resolver][read_image] .text or .rdata section not found");
        return std::nullopt;
    }
    return image;
}

// Addresses of every copy of `text` in the section that is bounded by NUL characters.
std::vector<uintptr_t> find_wide_strings(const Section& section, std::wstring_view text) {
    std::vector<uintptr_t> found;
    const auto* chars = reinterpret_cast<const wchar_t*>(section.begin);
    const size_t count = section.size / sizeof(wchar_t);
    const size_t len = text.size();
    for (size_t i = 1; i + len < count; ++i) {
        if (chars[i - 1] != L'\0' || chars[i + len] != L'\0') continue;
        if (std::wmemcmp(chars + i, text.data(), len) == 0) {
            found.push_back(reinterpret_cast<uintptr_t>(chars + i));
        }
    }
    return found;
}

// Start addresses of every `lea reg, [rip + disp32]` instruction that points at `target`.
std::vector<uintptr_t> find_lea_references(const Section& text, uintptr_t target) {
    std::vector<uintptr_t> found;
    const auto* bytes = reinterpret_cast<const uint8_t*>(text.begin);
    for (size_t i = 3; i + 4 <= text.size; ++i) {
        const bool rex = (bytes[i - 3] & 0xF0) == 0x40;
        const bool lea_rip_relative = bytes[i - 2] == 0x8D && (bytes[i - 1] & 0xC7) == 0x05;
        if (!rex || !lea_rip_relative) continue;
        int32_t disp = 0;
        std::memcpy(&disp, bytes + i, sizeof(disp));
        const auto next_instruction = static_cast<intptr_t>(text.begin + i + 4);
        if (next_instruction + disp == static_cast<intptr_t>(target)) found.push_back(text.begin + i - 3);
    }
    return found;
}

struct UnwindInfoHeader {
    uint8_t version_and_flags;
    uint8_t prolog_size;
    uint8_t code_count;
    uint8_t frame_register;
};

// Start of the function that holds `address`. Large functions are split into several
// unwind entries that chain back to the first one; this follows that chain.
std::optional<uintptr_t> function_start(uintptr_t address) {
    DWORD64 image_base = 0;
    const RUNTIME_FUNCTION* entry = RtlLookupFunctionEntry(address, &image_base, nullptr);
    for (int hops = 0; entry != nullptr && hops < 16; ++hops) {
        const auto* unwind = reinterpret_cast<const UnwindInfoHeader*>(image_base + entry->UnwindData);
        const bool chained = ((unwind->version_and_flags >> 3) & UNW_FLAG_CHAININFO) != 0;
        if (!chained) return static_cast<uintptr_t>(image_base + entry->BeginAddress);
        const size_t codes_size = ((unwind->code_count + 1u) & ~1u) * 2;
        entry = reinterpret_cast<const RUNTIME_FUNCTION*>(reinterpret_cast<uintptr_t>(unwind) + sizeof(UnwindInfoHeader) + codes_size);
    }
    API::get()->log_error("[engine_resolver][function_start] no unwind entry for 0x%p", reinterpret_cast<void*>(address));
    return std::nullopt;
}

// FPakPlatformFile::Mount is the only function that reads the L"_P.pak" string.
std::optional<uintptr_t> resolve_mount(const Image& image) {
    const auto strings = find_wide_strings(image.rdata, L"_P.pak");
    if (strings.size() != 1) {
        API::get()->log_error("[engine_resolver][resolve_mount] expected one L\"_P.pak\" string, found %zu", strings.size());
        return std::nullopt;
    }
    const auto references = find_lea_references(image.text, strings[0]);
    if (references.size() != 1) {
        API::get()->log_error("[engine_resolver][resolve_mount] expected one reference to L\"_P.pak\", found %zu", references.size());
        return std::nullopt;
    }
    return function_start(references[0]);
}

uintptr_t call_target(uintptr_t call_instruction) {
    int32_t rel = 0;
    std::memcpy(&rel, reinterpret_cast<const void*>(call_instruction + 1), sizeof(rel));
    return call_instruction + 5 + rel;
}

using Votes = std::map<uintptr_t, int>;

struct ManagerVotes {
    Votes get_manager;
    Votes find_platform_file;
};

// Several places in the engine run this sequence:
//   call FPlatformFileManager::Get ; mov rcx, rax ; lea rdx, [L"PakFile"] ; call FindPlatformFile
// Each `lea` site votes for the call before it and the call after it.
void vote_from_site(const Section& text, uintptr_t lea, ManagerVotes& votes) {
    const auto* b = reinterpret_cast<const uint8_t*>(lea);
    if (text.contains(lea + 7) && b[7] == 0xE8) votes.find_platform_file[call_target(lea + 7)]++;
    const bool mov_rcx_rax = b[-3] == 0x48 && b[-2] == 0x8B && b[-1] == 0xC8;
    if (text.contains(lea - 8) && mov_rcx_rax && b[-8] == 0xE8) votes.get_manager[call_target(lea - 8)]++;
}

std::optional<uintptr_t> winner(const Votes& votes, const char* what) {
    if (votes.empty()) {
        API::get()->log_error("[engine_resolver][winner] no candidate for %s", what);
        return std::nullopt;
    }
    const auto best = std::max_element(votes.begin(), votes.end(),
        [](const auto& a, const auto& b) { return a.second < b.second; });
    API::get()->log_warn("[engine_resolver][winner] %s: %d call sites agree, %zu distinct candidates", what, best->second, votes.size());
    return best->first;
}

bool resolve_manager(const Image& image, EngineFunctions& out) {
    ManagerVotes votes;
    for (const auto string_address : find_wide_strings(image.rdata, L"PakFile")) {
        for (const auto lea : find_lea_references(image.text, string_address)) vote_from_site(image.text, lea, votes);
    }
    const auto get_manager = winner(votes.get_manager, "FPlatformFileManager::Get");
    const auto find_platform_file = winner(votes.find_platform_file, "FPlatformFileManager::FindPlatformFile");
    if (!get_manager || !find_platform_file) return false;
    out.get_manager = reinterpret_cast<EngineFunctions::GetManagerFn>(*get_manager);
    out.find_platform_file = reinterpret_cast<EngineFunctions::FindPlatformFileFn>(*find_platform_file);
    return true;
}

// Calls the two manager functions once, so a wrong address fails here with a clear log line.
bool verify_pak_platform_file(const EngineFunctions& fns) {
    void* manager = fns.get_manager();
    void* pak_file = manager != nullptr ? fns.find_platform_file(manager, L"PakFile") : nullptr;
    if (pak_file == nullptr) {
        API::get()->log_error("[engine_resolver][verify_pak_platform_file] FindPlatformFile(\"PakFile\") returned null");
        return false;
    }
    API::get()->log_warn("[engine_resolver][verify_pak_platform_file] FPakPlatformFile instance at 0x%p", pak_file);
    return true;
}

void log_resolved(const Image& image, const EngineFunctions& fns) {
    const auto rva = [&](auto fn) { return static_cast<unsigned long long>(reinterpret_cast<uintptr_t>(fn) - image.base); };
    API::get()->log_warn("[engine_resolver][resolve_engine_functions] Mount=exe+0x%llX Get=exe+0x%llX FindPlatformFile=exe+0x%llX",
        rva(fns.mount), rva(fns.get_manager), rva(fns.find_platform_file));
}

} // namespace

std::optional<EngineFunctions> resolve_engine_functions() {
    const auto image = read_image();
    if (!image) return std::nullopt;
    EngineFunctions fns;
    const auto mount = resolve_mount(*image);
    if (!mount || !resolve_manager(*image, fns)) return std::nullopt;
    fns.mount = reinterpret_cast<EngineFunctions::MountFn>(*mount);
    log_resolved(*image, fns);
    if (!verify_pak_platform_file(fns)) return std::nullopt;
    return fns;
}

} // namespace pak_hot_reload
