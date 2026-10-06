#include <windows.h>

#include <string>

#include "uevr/API.hpp"
#include "pak_mounter.hpp"

using namespace uevr;

namespace pak_hot_reload {
namespace {

// Paks in the game's Paks folder get an order below 1000. Anything above wins.
constexpr uint32_t kBaseMountOrder = 10000;
constexpr const wchar_t* kStagingSuffix = L"_P.pak";

bool ends_with(const std::wstring& text, const std::wstring& suffix) {
    return text.size() >= suffix.size() && text.compare(text.size() - suffix.size(), suffix.size(), suffix) == 0;
}

} // namespace

PakMounter::PakMounter(const EngineFunctions& functions, std::filesystem::path staging_dir)
    : m_functions(functions), m_staging_dir(std::move(staging_dir)) {}

void* PakMounter::pak_platform_file() const {
    void* manager = m_functions.get_manager();
    return manager != nullptr ? m_functions.find_platform_file(manager, L"PakFile") : nullptr;
}

// The name ends in "_<n>_P.pak". The engine reads <n> as a patch version and adds
// 100 * <n> to the order, so each new copy also wins on its own. The process id and the
// start time keep the names apart from copies of earlier sessions and of earlier loads of
// this plugin in the same session; the game keeps all of those open.
std::filesystem::path PakMounter::next_staging_path(const std::filesystem::path& source_pak) {
    static const auto session = std::to_wstring(GetCurrentProcessId()) + L"_" + std::to_wstring(GetTickCount64() / 1000);
    ++m_mount_count;
    const auto name = source_pak.stem().wstring()
        + L"_s" + session
        + L"_" + std::to_wstring(m_mount_count) + kStagingSuffix;
    return m_staging_dir / name;
}

bool PakMounter::mount_copy(const std::filesystem::path& source_pak) {
    std::error_code ec;
    if (!std::filesystem::is_regular_file(source_pak, ec)) {
        API::get()->log_error("[pak_mounter][mount_copy] source pak not found: %ls", source_pak.c_str());
        return false;
    }
    std::filesystem::create_directories(m_staging_dir, ec);
    const auto copy = next_staging_path(source_pak);
    if (!std::filesystem::copy_file(source_pak, copy, std::filesystem::copy_options::overwrite_existing, ec)) {
        API::get()->log_error("[pak_mounter][mount_copy] copy to %ls failed: %s", copy.c_str(), ec.message().c_str());
        return false;
    }
    void* pak_file = pak_platform_file();
    if (pak_file == nullptr) {
        API::get()->log_error("[pak_mounter][mount_copy] FPakPlatformFile not found");
        return false;
    }
    const uint32_t order = kBaseMountOrder + m_mount_count;
    const bool mounted = m_functions.mount(pak_file, copy.c_str(), order, nullptr, true);
    API::get()->log_warn("[pak_mounter][mount_copy] %ls order=%u -> %s", copy.c_str(), order, mounted ? "mounted" : "FAILED");
    return mounted;
}

void PakMounter::clear_staging_dir() {
    std::error_code ec;
    if (!std::filesystem::is_directory(m_staging_dir, ec)) return;
    int removed = 0;
    for (const auto& entry : std::filesystem::directory_iterator(m_staging_dir, ec)) {
        if (!entry.is_regular_file(ec) || !ends_with(entry.path().filename().wstring(), kStagingSuffix)) continue;
        if (std::filesystem::remove(entry.path(), ec)) ++removed;
    }
    API::get()->log_warn("[pak_mounter][clear_staging_dir] removed %d old copies from %ls", removed, m_staging_dir.c_str());
}

} // namespace pak_hot_reload
