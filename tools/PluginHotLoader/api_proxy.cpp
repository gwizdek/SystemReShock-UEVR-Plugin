#include <atomic>

#include "uevr/API.hpp"
#include "api_proxy.hpp"
#include "callback_slots.hpp"

using namespace uevr;

namespace plugin_hot_load {
namespace {

// The real tables, for the wrappers below. Plain C function pointers cannot capture state.
const UEVR_PluginFunctions* g_real_functions{nullptr};
const UEVR_UFunctionFunctions* g_real_ufunction{nullptr};
std::atomic<bool> g_pinned{false};

void pin(const char* reason) {
    if (!g_pinned.exchange(true)) {
        API::get()->log_error("[api_proxy][pin] the inner plugin called %s; the loader cannot remove that hook, so it will not swap this plugin again. Use \"Reload Plugins\" in the UEVR overlay to clear it.", reason);
    }
}

// UEVR_PluginCallbacks
bool reg_on_present(UEVR_OnPresentCb cb) { return slots().on_present.add(cb); }
bool reg_on_device_reset(UEVR_OnDeviceResetCb cb) { return slots().on_device_reset.add(cb); }
bool reg_on_message(UEVR_OnMessageCb cb) { return slots().on_message.add(cb); }
bool reg_on_xinput_get_state(UEVR_OnXInputGetStateCb cb) { return slots().on_xinput_get_state.add(cb); }
bool reg_on_xinput_set_state(UEVR_OnXInputSetStateCb cb) { return slots().on_xinput_set_state.add(cb); }
bool reg_on_post_render_vr_framework_dx11(UEVR_OnPostRenderVRFrameworkDX11Cb cb) { return slots().on_post_render_vr_framework_dx11.add(cb); }
bool reg_on_post_render_vr_framework_dx12(UEVR_OnPostRenderVRFrameworkDX12Cb cb) { return slots().on_post_render_vr_framework_dx12.add(cb); }
bool reg_on_custom_event(UEVR_OnCustomEventCb cb) { return slots().on_custom_event.add(cb); }

// UEVR_SDKCallbacks
bool reg_on_pre_engine_tick(UEVR_Engine_TickCb cb) { return slots().on_pre_engine_tick.add(cb); }
bool reg_on_post_engine_tick(UEVR_Engine_TickCb cb) { return slots().on_post_engine_tick.add(cb); }
bool reg_on_pre_slate_draw_window(UEVR_Slate_DrawWindow_RenderThreadCb cb) { return slots().on_pre_slate_draw_window.add(cb); }
bool reg_on_post_slate_draw_window(UEVR_Slate_DrawWindow_RenderThreadCb cb) { return slots().on_post_slate_draw_window.add(cb); }
bool reg_on_pre_calculate_stereo_view_offset(UEVR_Stereo_CalculateStereoViewOffsetCb cb) { return slots().on_pre_calculate_stereo_view_offset.add(cb); }
bool reg_on_post_calculate_stereo_view_offset(UEVR_Stereo_CalculateStereoViewOffsetCb cb) { return slots().on_post_calculate_stereo_view_offset.add(cb); }
bool reg_on_early_calculate_stereo_view_offset(UEVR_Stereo_CalculateStereoViewOffsetCb cb) { return slots().on_early_calculate_stereo_view_offset.add(cb); }
bool reg_on_pre_viewport_client_draw(UEVR_ViewportClient_DrawCb cb) { return slots().on_pre_viewport_client_draw.add(cb); }
bool reg_on_post_viewport_client_draw(UEVR_ViewportClient_DrawCb cb) { return slots().on_post_viewport_client_draw.add(cb); }

// UEVR_PluginFunctions
bool remove_callback(void* cb) {
    return slots().remove(cb);
}

int register_inline_hook(void* target, void* dst, void** original) {
    const int id = g_real_functions->register_inline_hook(target, dst, original);
    if (id >= 0) pin("register_inline_hook");
    return id;
}

// UEVR_UFunctionFunctions
bool hook_ptr(UEVR_UFunctionHandle function, UEVR_UFunction_NativePreFn pre_hook, UEVR_UFunction_NativePostFn post_hook) {
    const bool hooked = g_real_ufunction->hook_ptr(function, pre_hook, post_hook);
    if (hooked) pin("UFunction::hook_ptr");
    return hooked;
}

} // namespace

void ApiProxy::initialize(const UEVR_PluginInitializeParam* real) {
    g_real_functions = real->functions;
    g_real_ufunction = real->sdk->ufunction;

    m_callbacks.on_present = &reg_on_present;
    m_callbacks.on_device_reset = &reg_on_device_reset;
    m_callbacks.on_message = &reg_on_message;
    m_callbacks.on_xinput_get_state = &reg_on_xinput_get_state;
    m_callbacks.on_xinput_set_state = &reg_on_xinput_set_state;
    m_callbacks.on_post_render_vr_framework_dx11 = &reg_on_post_render_vr_framework_dx11;
    m_callbacks.on_post_render_vr_framework_dx12 = &reg_on_post_render_vr_framework_dx12;
    m_callbacks.on_custom_event = &reg_on_custom_event;

    m_sdk_callbacks.on_pre_engine_tick = &reg_on_pre_engine_tick;
    m_sdk_callbacks.on_post_engine_tick = &reg_on_post_engine_tick;
    m_sdk_callbacks.on_pre_slate_draw_window_render_thread = &reg_on_pre_slate_draw_window;
    m_sdk_callbacks.on_post_slate_draw_window_render_thread = &reg_on_post_slate_draw_window;
    m_sdk_callbacks.on_pre_calculate_stereo_view_offset = &reg_on_pre_calculate_stereo_view_offset;
    m_sdk_callbacks.on_post_calculate_stereo_view_offset = &reg_on_post_calculate_stereo_view_offset;
    m_sdk_callbacks.on_early_calculate_stereo_view_offset = &reg_on_early_calculate_stereo_view_offset;
    m_sdk_callbacks.on_pre_viewport_client_draw = &reg_on_pre_viewport_client_draw;
    m_sdk_callbacks.on_post_viewport_client_draw = &reg_on_post_viewport_client_draw;

    m_functions = *real->functions;
    m_functions.remove_callback = &remove_callback;
    m_functions.register_inline_hook = &register_inline_hook;

    m_ufunction = *real->sdk->ufunction;
    m_ufunction.hook_ptr = &hook_ptr;

    m_sdk = *real->sdk;
    m_sdk.callbacks = &m_sdk_callbacks;
    m_sdk.ufunction = &m_ufunction;

    m_param = *real;
    m_param.functions = &m_functions;
    m_param.callbacks = &m_callbacks;
    m_param.sdk = &m_sdk;
}

bool is_pinned() {
    return g_pinned.load();
}

void clear_pin() {
    g_pinned.store(false);
}

} // namespace plugin_hot_load
