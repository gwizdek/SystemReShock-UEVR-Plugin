#include "object_lookup.hpp"

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"

#include <chrono>
#include <string>
#include <unordered_map>
#include <vector>

using namespace uevr;

namespace {

// The parsed full name: the class name and the object's own name, then its outers up to the
// package.
struct NamePath {
    SDK::FName class_name{};
    std::vector<SDK::FName> chain{};
};

struct Entry {
    NamePath path{};
    int32_t index{ -1 };
    SDK::UObject* object{ nullptr };
};

// Scans that miss are logged with their duration a few times, so the cost shows up in the log.
constexpr int kLoggedScans = 5;
int s_logged_scans{ 0 };

std::unordered_map<std::wstring, Entry> s_entries{};

bool same_name(const SDK::FName& a, const SDK::FName& b) {
    return a.ComparisonIndex == b.ComparisonIndex && a.Number == b.Number;
}

SDK::FName to_fname(const std::wstring& text) {
    return SDK::UKismetStringLibrary::Conv_StringToName(text.c_str());
}

// "Function /Game/A/B.B_C.Fn" -> class "Function", chain { "Fn", "B_C", "/Game/A/B" }.
// UEVR writes both '.' and ':' between names.
NamePath parse(const std::wstring& full_name) {
    NamePath path{};
    const size_t space = full_name.find(L' ');
    path.class_name = to_fname(full_name.substr(0, space));
    size_t start = space + 1;
    while (start <= full_name.size()) {
        const size_t end = full_name.find_first_of(L".:", start);
        const size_t stop = end == std::wstring::npos ? full_name.size() : end;
        path.chain.insert(path.chain.begin(), to_fname(full_name.substr(start, stop - start)));
        if (end == std::wstring::npos) break;
        start = end + 1;
    }
    return path;
}

bool matches(const SDK::UObject* object, const NamePath& path) {
    if (object == nullptr || !same_name(object->Name, path.chain[0])) return false;
    const SDK::UObject* outer = object->Outer;
    for (size_t i = 1; i < path.chain.size(); ++i) {
        if (outer == nullptr || !same_name(outer->Name, path.chain[i])) return false;
        outer = outer->Outer;
    }
    return outer == nullptr && object->Class != nullptr && same_name(object->Class->Name, path.class_name);
}

bool still_valid(const Entry& entry) {
    if (entry.index < 0 || entry.index >= SDK::UObject::GObjects->Num()) return false;
    const SDK::UObject* object = SDK::UObject::GObjects->GetByIndex(entry.index);
    return object == entry.object && matches(object, entry.path);
}

void scan(Entry& entry, const wchar_t* full_name) {
    const auto begin = std::chrono::steady_clock::now();
    entry.index = -1;
    entry.object = nullptr;
    const int32_t count = SDK::UObject::GObjects->Num();
    for (int32_t i = 0; i < count; ++i) {
        SDK::UObject* object = SDK::UObject::GObjects->GetByIndex(i);
        if (!matches(object, entry.path)) continue;
        entry.index = i;
        entry.object = object;
        break;
    }
    if (entry.object == nullptr && s_logged_scans < kLoggedScans) {
        ++s_logged_scans;
        const auto us = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - begin).count();
        API::get()->log_warn("[object_lookup][scan] %ls not loaded, scanned %d objects in %lld us", full_name, count, us);
    }
}

} // namespace

SDK::UObject* ObjectLookup::find_object(const wchar_t* full_name) {
    try {
        auto [it, inserted] = s_entries.try_emplace(full_name);
        Entry& entry = it->second;
        if (inserted) {
            entry.path = parse(full_name);
        }
        if (!still_valid(entry)) {
            scan(entry, full_name);
        }
        return entry.object;
    }
    catch (...) {
        API::get()->log_error("[object_lookup][find_object] Exception for %ls", full_name);
        return nullptr;
    }
}
