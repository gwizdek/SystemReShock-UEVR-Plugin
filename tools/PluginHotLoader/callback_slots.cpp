#include "callback_slots.hpp"

namespace plugin_hot_load {

bool CallbackSlots::remove(const void* fn) {
    return on_present.remove(fn)
        || on_device_reset.remove(fn)
        || on_message.remove(fn)
        || on_xinput_get_state.remove(fn)
        || on_xinput_set_state.remove(fn)
        || on_post_render_vr_framework_dx11.remove(fn)
        || on_post_render_vr_framework_dx12.remove(fn)
        || on_custom_event.remove(fn)
        || on_pre_engine_tick.remove(fn)
        || on_post_engine_tick.remove(fn)
        || on_pre_slate_draw_window.remove(fn)
        || on_post_slate_draw_window.remove(fn)
        || on_pre_calculate_stereo_view_offset.remove(fn)
        || on_post_calculate_stereo_view_offset.remove(fn)
        || on_early_calculate_stereo_view_offset.remove(fn)
        || on_pre_viewport_client_draw.remove(fn)
        || on_post_viewport_client_draw.remove(fn);
}

void CallbackSlots::clear() {
    on_present.clear();
    on_device_reset.clear();
    on_message.clear();
    on_xinput_get_state.clear();
    on_xinput_set_state.clear();
    on_post_render_vr_framework_dx11.clear();
    on_post_render_vr_framework_dx12.clear();
    on_custom_event.clear();
    on_pre_engine_tick.clear();
    on_post_engine_tick.clear();
    on_pre_slate_draw_window.clear();
    on_post_slate_draw_window.clear();
    on_pre_calculate_stereo_view_offset.clear();
    on_post_calculate_stereo_view_offset.clear();
    on_early_calculate_stereo_view_offset.clear();
    on_pre_viewport_client_draw.clear();
    on_post_viewport_client_draw.clear();
}

CallbackSlots& slots() {
    static CallbackSlots instance;
    return instance;
}

} // namespace plugin_hot_load
