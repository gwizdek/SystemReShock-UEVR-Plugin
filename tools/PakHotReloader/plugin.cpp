// PakHotReloader: a development-only UEVR plugin that mounts a rebuilt mod pak into
// the running game, so a content change can be tested without restarting the game.
// See documentation/pak-hot-reload.md.

#include <windows.h>

#include <memory>
#include <optional>

#include "uevr/Plugin.hpp"
#include "config.hpp"
#include "diagnostics.hpp"
#include "engine_resolver.hpp"
#include "pak_mounter.hpp"
#include "referencers.hpp"
#include "save_loader.hpp"

using namespace uevr;
using namespace pak_hot_reload;

namespace {

constexpr const wchar_t* kConfigFile = L"PakHotReloader.ini";
constexpr const wchar_t* kStagingFolder = L"pak_hot_reload";
constexpr int kInstanceLogLimit = 60;
// Ticks between the garbage collection request and the mount. The engine collects on
// one of the following ticks; this leaves it room.
constexpr int kTicksAfterGarbageCollection = 90;

bool game_window_in_foreground() {
    DWORD pid = 0;
    GetWindowThreadProcessId(GetForegroundWindow(), &pid);
    return pid == GetCurrentProcessId();
}

} // namespace

class PakHotReloadPlugin final : public Plugin {
public:
    void on_initialize() override {
        try {
            initialize();
        } catch (...) {
            API::get()->log_error("[plugin][on_initialize] exception");
        }
    }

    // Runs on the game thread, which is where paks must be mounted and loads started.
    void on_post_engine_tick(API::UGameEngine*, float) override {
        try {
            tick();
        } catch (...) {
            API::get()->log_error("[plugin][on_post_engine_tick] exception");
            m_ticks_until_mount = -1;
        }
    }

private:
    void initialize() {
        m_config = load_config(API::get()->get_persistent_dir(kConfigFile));
        if (!m_config) return;
        const auto functions = resolve_engine_functions();
        if (!functions) {
            API::get()->log_error("[plugin][initialize] engine functions not resolved, hot reload disabled");
            return;
        }
        m_mounter = std::make_unique<PakMounter>(*functions, API::get()->get_persistent_dir(kStagingFolder));
        m_mounter->clear_staging_dir();
        API::get()->log_warn("[plugin][initialize] ready: %zu pak(s), hotkey 0x%X, load mode %s",
            m_config->paks.size(), m_config->hotkey, load_mode_name(m_config->load_mode));
    }

    // A reload has two phases: the hotkey logs the state and asks for a garbage collection;
    // the mount runs a few ticks later, so the log shows what the collection freed.
    void tick() {
        if (hotkey_pressed() && m_ticks_until_mount < 0) begin_reload();
        if (m_ticks_until_mount > 0) --m_ticks_until_mount;
        if (m_ticks_until_mount == 0) {
            m_ticks_until_mount = -1;
            finish_reload();
        }
    }

    // True once per key press, and only while the game window has focus.
    bool hotkey_pressed() {
        if (!m_config || m_mounter == nullptr) return false;
        const bool down = (GetAsyncKeyState(m_config->hotkey) & 0x8000) != 0 && game_window_in_foreground();
        const bool pressed = down && !m_key_was_down;
        m_key_was_down = down;
        return pressed;
    }

    void begin_reload() {
        API::get()->log_warn("[plugin][begin_reload] hotkey pressed, state before garbage collection:");
        log_loaded_packages(m_config->loaded_prefix);
        log_live_instances(m_config->loaded_prefix, kInstanceLogLimit);
        request_garbage_collection();
        m_ticks_until_mount = kTicksAfterGarbageCollection;
    }

    void finish_reload() {
        API::get()->log_warn("[plugin][finish_reload] state after garbage collection:");
        log_loaded_packages(m_config->loaded_prefix);
        log_live_instances(m_config->loaded_prefix, kInstanceLogLimit);
        log_referencers(m_config->loaded_prefix, kInstanceLogLimit);
        log_file_probes(m_mounter->pak_platform_file(), m_config->probe_files, "before mount");
        const bool all_mounted = mount_all();
        log_file_probes(m_mounter->pak_platform_file(), m_config->probe_files, "after mount");
        if (!all_mounted) {
            API::get()->log_error("[plugin][finish_reload] not every pak mounted, skipping the save load");
            return;
        }
        load_save(m_config->load_mode, m_config->save_name);
    }

    bool mount_all() {
        API::get()->log_warn("[plugin][mount_all] mounting %zu pak(s)", m_config->paks.size());
        bool all_mounted = !m_config->paks.empty();
        for (const auto& pak : m_config->paks) {
            all_mounted = m_mounter->mount_copy(pak) && all_mounted;
        }
        return all_mounted;
    }

    std::optional<Config> m_config;
    std::unique_ptr<PakMounter> m_mounter;
    bool m_key_was_down{false};
    int m_ticks_until_mount{-1};
};

std::unique_ptr<PakHotReloadPlugin> g_plugin = std::make_unique<PakHotReloadPlugin>();
