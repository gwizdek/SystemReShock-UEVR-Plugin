#pragma once

#include <windows.h>

#include <filesystem>

#include "uevr/API.h"

namespace plugin_hot_load {

// Loads the real plugin DLL from a staged copy and runs the same entry point protocol UEVR
// uses: uevr_plugin_required_version is checked against UEVR's version, then
// uevr_plugin_initialize is called with the proxy parameter. The copy gets a new name on
// every load, so the source file is never locked and a reload never maps the same path twice.
class InnerPlugin {
public:
    InnerPlugin(std::filesystem::path source, std::filesystem::path staging_dir);

    // Copies, loads, checks and initializes. On a failure after the module was mapped it
    // stays recorded, and the caller must empty the callback slots and call unload().
    bool load(const UEVR_PluginInitializeParam* param);

    // Frees the module and deletes its staged copy. The caller empties the callback slots
    // first and holds off every forwarder while this runs.
    void unload();

    bool loaded() const { return m_module != nullptr; }
    const std::filesystem::path& source() const { return m_source; }

    // Deletes staged copies left by earlier game sessions.
    void clear_staging_dir();

private:
    std::filesystem::path next_staging_path();
    bool stage_copy(std::filesystem::path& copy);
    bool check_version(HMODULE module, const UEVR_PluginVersion* host) const;
    bool initialize(HMODULE module, const UEVR_PluginInitializeParam* param) const;

    std::filesystem::path m_source;
    std::filesystem::path m_staging_dir;
    std::filesystem::path m_loaded_copy;
    HMODULE m_module{nullptr};
    int m_load_count{0};
};

} // namespace plugin_hot_load
