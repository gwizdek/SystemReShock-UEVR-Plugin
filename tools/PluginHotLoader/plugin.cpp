// PluginHotLoader: a development-only UEVR plugin that loads the real plugin DLL from a copy
// and swaps it for a new build while the game runs. UEVR sees only this loader; every
// callback the real plugin registers goes through the forwarders below. See
// documentation/plugin-hot-reload.md.

#include <windows.h>

#include <chrono>
#include <memory>
#include <mutex>
#include <optional>
#include <shared_mutex>

#include "uevr/API.hpp"
#include "api_proxy.hpp"
#include "callback_slots.hpp"
#include "config.hpp"
#include "file_watch.hpp"
#include "inner_plugin.hpp"

using namespace uevr;
using namespace plugin_hot_load;

namespace {

constexpr const wchar_t* kConfigFile = L"PluginHotLoader.ini";
constexpr const wchar_t* kStagingFolder = L"plugin_hot_load";
constexpr const wchar_t* kDefaultPluginFolder = L"hot_plugins";
constexpr const wchar_t* kDefaultPluginName = L"SystemReShockVR.dll";

// Held shared by every forwarder while it calls into the inner plugin, and exclusively
// while the inner plugin is unloaded. So FreeLibrary never runs under a live call.
std::shared_mutex g_lifetime;
std::optional<Config> g_config;
ApiProxy g_proxy;
std::unique_ptr<InnerPlugin> g_inner;
std::unique_ptr<FileWatch> g_watch;
std::chrono::steady_clock::time_point g_last_poll{};

// Logs one line per call site, so a callback that throws every frame does not fill the log.
void log_once(bool& logged, const char* name, const char* detail) {
    if (logged) return;
    logged = true;
    try {
        API::get()->log_error("[plugin][forward] exception in the inner plugin's %s callback: %s (further ones are not logged)", name, detail);
    } catch (...) {
    }
}

// Calls every callback in the slot with the arguments, skipping one that throws.
template <class Fn, class... Args>
void forward(Slot<Fn>& slot, const char* name, Args... args) {
    static bool logged = false;
    std::shared_lock lock(g_lifetime);
    for (Fn fn : slot.snapshot()) {
        try {
            fn(args...);
        } catch (const std::exception& e) {
            log_once(logged, name, e.what());
        } catch (...) {
            log_once(logged, name, "not a C++ exception, likely an access violation");
        }
    }
}

// Unloads whatever load() left behind, with the forwarders held off.
void unload_inner() {
    std::unique_lock lock(g_lifetime);
    slots().clear();
    g_inner->unload();
}

void load_inner() {
    if (g_inner->load(g_proxy.param())) return;
    // A failed initialize may have registered some callbacks before it gave up.
    unload_inner();
    API::get()->log_error("[plugin][load_inner] the inner plugin is not loaded; fix the build and deploy again, the loader keeps watching");
}

void swap_inner() {
    API::get()->log_warn("[plugin][swap_inner] %ls changed, swapping", g_inner->source().c_str());
    unload_inner();
    load_inner();
}

// Runs on the present thread, the same thread UEVR initializes plugins on.
void poll_for_swap() {
    if (!g_config || g_inner == nullptr || g_watch == nullptr) return;
    const auto now = std::chrono::steady_clock::now();
    if (now - g_last_poll < std::chrono::milliseconds(g_config->poll_ms)) return;
    g_last_poll = now;
    if (!g_watch->changed_and_settled()) return;
    g_watch->accept();
    if (is_pinned()) {
        API::get()->log_error("[plugin][poll_for_swap] new build found but the loaded plugin is pinned by a hook; use \"Reload Plugins\" in the UEVR overlay");
        return;
    }
    swap_inner();
}

void poll_for_swap_guarded() {
    static bool logged = false;
    try {
        poll_for_swap();
    } catch (const std::exception& e) {
        log_once(logged, "poll_for_swap", e.what());
    } catch (...) {
        log_once(logged, "poll_for_swap", "not a C++ exception");
    }
}

// Forwarders registered with UEVR. One per slot, same signatures as the C API.
void fwd_on_present() { poll_for_swap_guarded(); forward(slots().on_present, "on_present"); }
void fwd_on_device_reset() { forward(slots().on_device_reset, "on_device_reset"); }
void fwd_on_xinput_get_state(unsigned int* retval, unsigned int user_index, void* state) { forward(slots().on_xinput_get_state, "on_xinput_get_state", retval, user_index, state); }
void fwd_on_xinput_set_state(unsigned int* retval, unsigned int user_index, void* vibration) { forward(slots().on_xinput_set_state, "on_xinput_set_state", retval, user_index, vibration); }
void fwd_on_post_render_vr_framework_dx11(void* context, void* texture, void* rtv) { forward(slots().on_post_render_vr_framework_dx11, "on_post_render_vr_framework_dx11", context, texture, rtv); }
void fwd_on_post_render_vr_framework_dx12(void* command_list, void* rt, void* rtv) { forward(slots().on_post_render_vr_framework_dx12, "on_post_render_vr_framework_dx12", command_list, rt, rtv); }
void fwd_on_custom_event(const char* event_name, const char* event_data) { forward(slots().on_custom_event, "on_custom_event", event_name, event_data); }

void fwd_on_pre_engine_tick(UEVR_UGameEngineHandle engine, float delta) { forward(slots().on_pre_engine_tick, "on_pre_engine_tick", engine, delta); }
void fwd_on_post_engine_tick(UEVR_UGameEngineHandle engine, float delta) { forward(slots().on_post_engine_tick, "on_post_engine_tick", engine, delta); }
void fwd_on_pre_slate_draw_window(UEVR_FSlateRHIRendererHandle renderer, UEVR_FViewportInfoHandle info) { forward(slots().on_pre_slate_draw_window, "on_pre_slate_draw_window", renderer, info); }
void fwd_on_post_slate_draw_window(UEVR_FSlateRHIRendererHandle renderer, UEVR_FViewportInfoHandle info) { forward(slots().on_post_slate_draw_window, "on_post_slate_draw_window", renderer, info); }
void fwd_on_pre_calculate_stereo_view_offset(UEVR_StereoRenderingDeviceHandle device, int view_index, float world_to_meters, UEVR_Vector3f* position, UEVR_Rotatorf* rotation, bool is_double) {
    forward(slots().on_pre_calculate_stereo_view_offset, "on_pre_calculate_stereo_view_offset", device, view_index, world_to_meters, position, rotation, is_double);
}
void fwd_on_post_calculate_stereo_view_offset(UEVR_StereoRenderingDeviceHandle device, int view_index, float world_to_meters, UEVR_Vector3f* position, UEVR_Rotatorf* rotation, bool is_double) {
    forward(slots().on_post_calculate_stereo_view_offset, "on_post_calculate_stereo_view_offset", device, view_index, world_to_meters, position, rotation, is_double);
}
void fwd_on_early_calculate_stereo_view_offset(UEVR_StereoRenderingDeviceHandle device, int view_index, float world_to_meters, UEVR_Vector3f* position, UEVR_Rotatorf* rotation, bool is_double) {
    forward(slots().on_early_calculate_stereo_view_offset, "on_early_calculate_stereo_view_offset", device, view_index, world_to_meters, position, rotation, is_double);
}
void fwd_on_pre_viewport_client_draw(UEVR_UGameViewportClientHandle client, UEVR_FViewportHandle viewport, UEVR_FCanvasHandle canvas) { forward(slots().on_pre_viewport_client_draw, "on_pre_viewport_client_draw", client, viewport, canvas); }
void fwd_on_post_viewport_client_draw(UEVR_UGameViewportClientHandle client, UEVR_FViewportHandle viewport, UEVR_FCanvasHandle canvas) { forward(slots().on_post_viewport_client_draw, "on_post_viewport_client_draw", client, viewport, canvas); }

// on_message is the one callback with a result: the first false stops the chain, as in UEVR.
bool fwd_on_message(void* hwnd, unsigned int msg, unsigned long long wparam, long long lparam) {
    std::shared_lock lock(g_lifetime);
    for (UEVR_OnMessageCb fn : slots().on_message.snapshot()) {
        try {
            if (!fn(hwnd, msg, wparam, lparam)) return false;
        } catch (...) {
            API::get()->log_error("[plugin][fwd_on_message] exception in the inner plugin's on_message callback");
        }
    }
    return true;
}

void register_forwarders(const UEVR_PluginInitializeParam* param) {
    const auto* cb = param->callbacks;
    cb->on_present(&fwd_on_present);
    cb->on_device_reset(&fwd_on_device_reset);
    cb->on_message(&fwd_on_message);
    cb->on_xinput_get_state(&fwd_on_xinput_get_state);
    cb->on_xinput_set_state(&fwd_on_xinput_set_state);
    cb->on_post_render_vr_framework_dx11(&fwd_on_post_render_vr_framework_dx11);
    cb->on_post_render_vr_framework_dx12(&fwd_on_post_render_vr_framework_dx12);
    cb->on_custom_event(&fwd_on_custom_event);

    const auto* sdk = param->sdk->callbacks;
    sdk->on_pre_engine_tick(&fwd_on_pre_engine_tick);
    sdk->on_post_engine_tick(&fwd_on_post_engine_tick);
    sdk->on_pre_slate_draw_window_render_thread(&fwd_on_pre_slate_draw_window);
    sdk->on_post_slate_draw_window_render_thread(&fwd_on_post_slate_draw_window);
    sdk->on_pre_calculate_stereo_view_offset(&fwd_on_pre_calculate_stereo_view_offset);
    sdk->on_post_calculate_stereo_view_offset(&fwd_on_post_calculate_stereo_view_offset);
    sdk->on_early_calculate_stereo_view_offset(&fwd_on_early_calculate_stereo_view_offset);
    sdk->on_pre_viewport_client_draw(&fwd_on_pre_viewport_client_draw);
    sdk->on_post_viewport_client_draw(&fwd_on_post_viewport_client_draw);
}

void initialize(const UEVR_PluginInitializeParam* param) {
    const auto default_plugin = API::get()->get_persistent_dir(kDefaultPluginFolder) / kDefaultPluginName;
    g_config = load_config(API::get()->get_persistent_dir(kConfigFile), default_plugin);
    if (!g_config) return;

    g_proxy.initialize(param);
    register_forwarders(param);

    g_inner = std::make_unique<InnerPlugin>(g_config->plugin_file, API::get()->get_persistent_dir(kStagingFolder));
    g_inner->clear_staging_dir();
    g_watch = std::make_unique<FileWatch>(g_config->plugin_file, std::chrono::milliseconds(g_config->settle_ms));
    g_watch->accept();
    API::get()->log_warn("[plugin][initialize] watching %ls every %d ms, settle %d ms", g_config->plugin_file.c_str(), g_config->poll_ms, g_config->settle_ms);
    load_inner();
}

} // namespace

extern "C" __declspec(dllexport) void uevr_plugin_required_version(UEVR_PluginVersion* version) {
    version->major = UEVR_PLUGIN_VERSION_MAJOR;
    version->minor = UEVR_PLUGIN_VERSION_MINOR;
    version->patch = UEVR_PLUGIN_VERSION_PATCH;
}

// Returns true even when the inner plugin failed, so the loader stays alive and picks up the
// next build.
extern "C" __declspec(dllexport) bool uevr_plugin_initialize(const UEVR_PluginInitializeParam* param) {
    API::initialize(param);
    try {
        initialize(param);
    } catch (const std::exception& e) {
        API::get()->log_error("[plugin][uevr_plugin_initialize] exception: %s", e.what());
    } catch (...) {
        API::get()->log_error("[plugin][uevr_plugin_initialize] exception (not a C++ exception, likely an access violation)");
    }
    return true;
}

// UEVR's own "Reload Plugins" frees this loader without notice. The inner module is left
// loaded on purpose: FreeLibrary inside DllMain is not allowed, and nothing in UEVR points
// at the inner plugin any more once this loader's forwarders are gone.
BOOL APIENTRY DllMain(HANDLE, DWORD, LPVOID) {
    return TRUE;
}
