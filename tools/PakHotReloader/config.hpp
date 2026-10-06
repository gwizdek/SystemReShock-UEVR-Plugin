#pragma once

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

namespace pak_hot_reload {

// What happens after the paks are mounted.
enum class LoadMode {
    None,    // only mount
    Quick,   // GameInstance::QuickLoad(0)
    Auto,    // GameInstance::AutoLoad(0)
    Manual,  // GameInstance::ManualLoad(save_name, 0)
};

struct Config {
    std::vector<std::filesystem::path> paks;  // pak files to copy and mount, in order
    int hotkey{};                             // virtual-key code that triggers a reload
    LoadMode load_mode{LoadMode::None};
    std::wstring save_name;                   // used by LoadMode::Manual
    std::vector<std::wstring> probe_files;    // engine file paths checked before and after a mount
    std::wstring loaded_prefix;               // package name prefix listed around a mount, e.g. /Game/Mods/
};

// Reads the ini file. Writes a commented default file first when none exists.
// Returns nothing, and logs the reason, when the file cannot be read.
std::optional<Config> load_config(const std::filesystem::path& file);

const char* load_mode_name(LoadMode mode);

} // namespace pak_hot_reload
