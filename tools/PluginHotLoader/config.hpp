#pragma once

#include <filesystem>
#include <optional>

namespace plugin_hot_load {

struct Config {
    // The plugin DLL to load and watch. A copy of it is loaded, so this file is never locked.
    std::filesystem::path plugin_file;
    // How often the file's write time is checked, in milliseconds.
    int poll_ms{500};
    // How long a new write time must stay unchanged before the swap, in milliseconds.
    // A file still being written is not picked up.
    int settle_ms{1000};
};

// Reads the ini file, writing one with defaults and comments when it does not exist.
std::optional<Config> load_config(const std::filesystem::path& file, const std::filesystem::path& default_plugin_file);

} // namespace plugin_hot_load
