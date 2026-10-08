#pragma once

#include <mutex>
#include <vector>

#include "uevr/API.h"

namespace plugin_hot_load {

// One registration slot of the UEVR C API, holding the callbacks the inner plugin registered
// for it. Registration and removal lock briefly. A dispatch takes a copy of the list and
// calls without the lock, so a callback may register or remove callbacks while it runs.
template <class Fn>
class Slot {
public:
    bool add(Fn fn) {
        if (fn == nullptr) return false;
        std::scoped_lock lock(m_mutex);
        m_callbacks.push_back(fn);
        return true;
    }

    bool remove(const void* fn) {
        std::scoped_lock lock(m_mutex);
        const auto before = m_callbacks.size();
        std::erase_if(m_callbacks, [fn](Fn f) { return reinterpret_cast<const void*>(f) == fn; });
        return m_callbacks.size() != before;
    }

    void clear() {
        std::scoped_lock lock(m_mutex);
        m_callbacks.clear();
    }

    std::vector<Fn> snapshot() const {
        std::scoped_lock lock(m_mutex);
        return m_callbacks;
    }

private:
    mutable std::mutex m_mutex;
    std::vector<Fn> m_callbacks;
};

// Every slot of UEVR_PluginCallbacks and UEVR_SDKCallbacks.
struct CallbackSlots {
    Slot<UEVR_OnPresentCb> on_present;
    Slot<UEVR_OnDeviceResetCb> on_device_reset;
    Slot<UEVR_OnMessageCb> on_message;
    Slot<UEVR_OnXInputGetStateCb> on_xinput_get_state;
    Slot<UEVR_OnXInputSetStateCb> on_xinput_set_state;
    Slot<UEVR_OnPostRenderVRFrameworkDX11Cb> on_post_render_vr_framework_dx11;
    Slot<UEVR_OnPostRenderVRFrameworkDX12Cb> on_post_render_vr_framework_dx12;
    Slot<UEVR_OnCustomEventCb> on_custom_event;

    Slot<UEVR_Engine_TickCb> on_pre_engine_tick;
    Slot<UEVR_Engine_TickCb> on_post_engine_tick;
    Slot<UEVR_Slate_DrawWindow_RenderThreadCb> on_pre_slate_draw_window;
    Slot<UEVR_Slate_DrawWindow_RenderThreadCb> on_post_slate_draw_window;
    Slot<UEVR_Stereo_CalculateStereoViewOffsetCb> on_pre_calculate_stereo_view_offset;
    Slot<UEVR_Stereo_CalculateStereoViewOffsetCb> on_post_calculate_stereo_view_offset;
    Slot<UEVR_Stereo_CalculateStereoViewOffsetCb> on_early_calculate_stereo_view_offset;
    Slot<UEVR_ViewportClient_DrawCb> on_pre_viewport_client_draw;
    Slot<UEVR_ViewportClient_DrawCb> on_post_viewport_client_draw;

    // Removes the callback from whichever slot holds it. True when one did.
    bool remove(const void* fn);
    // Empties every slot. Called before the inner plugin is unloaded.
    void clear();
};

// The one instance. The registration functions in api_proxy.cpp are plain C functions and
// reach it through this accessor.
CallbackSlots& slots();

} // namespace plugin_hot_load
