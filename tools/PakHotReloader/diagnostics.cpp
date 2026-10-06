#include <windows.h>

#include <cstdint>

#include "uevr/API.hpp"
#include "diagnostics.hpp"

using namespace uevr;

namespace pak_hot_reload {
namespace {

// IPlatformFile virtual table slots in UE 4.27. GetLowerLevel (11), GetName (13) and
// OpenRead (24) were confirmed in the game's disassembly; FileExists and FileSize follow
// GetName in the header.
constexpr size_t kSlotFileExists = 14;
constexpr size_t kSlotFileSize = 15;

using FileExistsFn = bool(__fastcall*)(void* self, const wchar_t* path);
using FileSizeFn = int64_t(__fastcall*)(void* self, const wchar_t* path);

template <class Fn>
Fn virtual_function(void* object, size_t slot) {
    return reinterpret_cast<Fn>((*reinterpret_cast<void***>(object))[slot]);
}

// The UEVR log takes char. Paths and object names are ASCII in practice.
std::string narrow(const std::wstring& wide) {
    std::string out;
    out.reserve(wide.size());
    for (const wchar_t c : wide) out.push_back(c < 128 ? static_cast<char>(c) : '?');
    return out;
}

API::UClass* package_class() {
    static API::UClass* cls = API::get()->find_uobject<API::UClass>(L"Class /Script/CoreUObject.Package");
    return cls;
}

bool starts_with(const std::wstring& text, const std::wstring& prefix) {
    return text.compare(0, prefix.size(), prefix) == 0;
}

// The package at the top of the outer chain.
API::UObject* outermost(API::UObject* object) {
    while (object->get_outer() != nullptr) object = object->get_outer();
    return object;
}

// True for classes, structs, enums, functions and packages: the reflection objects
// themselves rather than instances made from them.
bool is_reflection_object(API::UObject* object) {
    static auto* field_class = API::get()->find_uobject<API::UClass>(L"Class /Script/CoreUObject.Field");
    return object->get_class() == package_class() || (field_class != nullptr && object->is_a(field_class));
}

bool is_default_object(API::UObject* object) {
    return starts_with(object->get_fname()->to_string(), L"Default__");
}

// True for component and widget templates that live inside a class object. They are part
// of the class, not instances made from it.
bool is_owned_by_class(API::UObject* object) {
    for (auto* outer = object->get_outer(); outer != nullptr; outer = outer->get_outer()) {
        if (outer->is_a(API::UClass::static_class())) return true;
    }
    return false;
}

bool class_from_prefix(API::UClass* cls, const std::wstring& prefix) {
    return cls != nullptr && starts_with(outermost(cls)->get_fname()->to_string(), prefix);
}

} // namespace

void log_file_probes(void* pak_platform_file, const std::vector<std::wstring>& file_paths, const char* when) {
    if (pak_platform_file == nullptr) return;
    for (const auto& path : file_paths) {
        const bool exists = virtual_function<FileExistsFn>(pak_platform_file, kSlotFileExists)(pak_platform_file, path.c_str());
        const int64_t size = virtual_function<FileSizeFn>(pak_platform_file, kSlotFileSize)(pak_platform_file, path.c_str());
        API::get()->log_warn("[diagnostics][log_file_probes] %s: %s exists=%d size=%lld",
            when, narrow(path).c_str(), exists ? 1 : 0, static_cast<long long>(size));
    }
}

void log_loaded_packages(const std::wstring& prefix) {
    auto* cls = package_class();
    auto* objects = API::FUObjectArray::get();
    if (cls == nullptr || objects == nullptr || prefix.empty()) return;
    int found = 0;
    int live = 0;
    const int32_t count = objects->get_object_count();
    for (int32_t i = 0; i < count; ++i) {
        auto* object = objects->get_object(i);
        if (object == nullptr) continue;
        ++live;
        if (object->get_class() != cls) continue;
        const auto name = object->get_fname()->to_string();
        if (!starts_with(name, prefix)) continue;
        ++found;
        API::get()->log_warn("[diagnostics][log_loaded_packages] still in memory: %s", narrow(name).c_str());
    }
    // The live total drops after a garbage collection; it tells whether one ran between two listings.
    API::get()->log_warn("[diagnostics][log_loaded_packages] %d package(s) under %s are loaded; those are not read from the new pak (%d live objects in total)", found, narrow(prefix).c_str(), live);
}

void log_live_instances(const std::wstring& prefix, int limit) {
    auto* objects = API::FUObjectArray::get();
    if (objects == nullptr || prefix.empty()) return;
    int found = 0;
    const int32_t count = objects->get_object_count();
    for (int32_t i = 0; i < count; ++i) {
        auto* object = objects->get_object(i);
        if (object == nullptr || is_reflection_object(object) || is_default_object(object)) continue;
        if (!class_from_prefix(object->get_class(), prefix) || is_owned_by_class(object)) continue;
        ++found;
        if (found <= limit) {
            API::get()->log_warn("[diagnostics][log_live_instances] alive: %s", narrow(object->get_full_name()).c_str());
        }
    }
    API::get()->log_warn("[diagnostics][log_live_instances] %d live instance(s) of classes under %s (%d listed)", found, narrow(prefix).c_str(), found < limit ? found : limit);
}

bool request_garbage_collection() {
    auto* library = API::get()->find_uobject<API::UClass>(L"Class /Script/Engine.KismetSystemLibrary");
    auto* instance = library != nullptr ? library->get_class_default_object() : nullptr;
    if (instance == nullptr || library->find_function(L"CollectGarbage") == nullptr) {
        API::get()->log_error("[diagnostics][request_garbage_collection] KismetSystemLibrary::CollectGarbage not found");
        return false;
    }
    instance->call_function(L"CollectGarbage", nullptr);
    API::get()->log_warn("[diagnostics][request_garbage_collection] garbage collection requested");
    return true;
}

} // namespace pak_hot_reload
