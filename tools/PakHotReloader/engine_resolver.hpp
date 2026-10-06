#pragma once

#include <cstdint>
#include <optional>

namespace pak_hot_reload {

// Native engine functions of the running game. They are not exported, so they are
// found at start-up from two string references inside the executable.
// See documentation/pak-hot-reload.md for how that works.
struct EngineFunctions {
    // bool FPakPlatformFile::Mount(const TCHAR* pak, uint32 order, const TCHAR* mount_point, bool load_index)
    using MountFn = bool(__fastcall*)(void* self, const wchar_t* pak, uint32_t order, const wchar_t* mount_point, bool load_index);
    // FPlatformFileManager& FPlatformFileManager::Get()
    using GetManagerFn = void*(__fastcall*)();
    // IPlatformFile* FPlatformFileManager::FindPlatformFile(const TCHAR* name)
    using FindPlatformFileFn = void*(__fastcall*)(void* self, const wchar_t* name);

    MountFn mount{};
    GetManagerFn get_manager{};
    FindPlatformFileFn find_platform_file{};
};

// Finds the functions in the game executable. Returns nothing, and logs the reason,
// when a lookup is missing or not unique. Call once from on_initialize.
std::optional<EngineFunctions> resolve_engine_functions();

} // namespace pak_hot_reload
