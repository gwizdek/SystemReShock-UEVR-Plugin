#pragma once

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_dx12.h"
#include "imgui/imgui_impl_win32.h"

#include "rendering/d3d11.hpp"
#include "rendering/d3d12.hpp"

#include "uevr/Plugin.hpp"
#include "uevr/API.hpp"


#define PLUGIN_LOG_ONCE(...) { \
    static bool _logged_ = false; \
    if (!_logged_) { \
        _logged_ = true; \
        API::get()->log_info(__VA_ARGS__); \
    } }

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class UEVRPlugin;
extern std::unique_ptr<UEVRPlugin> g_plugin;

class SystemShockMain;
using namespace uevr;

class UEVRPlugin : public uevr::Plugin {
private:
    const int CB_DURATION_SAMPLE_RATE = 100;
    int m_cb_calls_count{ 0 };
    bool m_xinput_cb_processed{ false };

public:
    UEVRPlugin();
    virtual ~UEVRPlugin();

    // ImGui
    void on_present() override;
    void on_device_reset() override;
    bool on_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) override;
    bool initialize_imgui();
    void on_post_render_vr_framework_dx11(ID3D11DeviceContext* context, ID3D11Texture2D* texture, ID3D11RenderTargetView* rtv) override;
    void on_post_render_vr_framework_dx12(ID3D12GraphicsCommandList* command_list, ID3D12Resource* rt, D3D12_CPU_DESCRIPTOR_HANDLE* rtv) override;
    void on_pre_calculate_stereo_view_offset(UEVR_StereoRenderingDeviceHandle, int view_index, float world_to_meters,
        UEVR_Vector3f* position, UEVR_Rotatorf* rotation, bool is_double) override;
    void on_post_calculate_stereo_view_offset(UEVR_StereoRenderingDeviceHandle, int view_index, float world_to_meters,
        UEVR_Vector3f* position, UEVR_Rotatorf* rotation, bool is_double) override;

    void on_initialize() override;
    void on_xinput_get_state(uint32_t* retval, uint32_t user_index, XINPUT_STATE* state) override;
    void on_pre_engine_tick(uevr::API::UGameEngine* engine, float delta) override;

    SystemShockMain* m_main{ nullptr };

    // ImGui
    HWND m_wnd{};
    bool m_imgui_initialized{ false };
    bool m_was_rendering_desktop{ false };
    bool m_ui_option_show_debug_view{ false };

    bool hook_bp_fn(std::wstring_view class_name, std::wstring_view fn_name, UEVR_UFunction_NativePreFn pre, UEVR_UFunction_NativePostFn post, bool use_native);
    static bool mod_onfire_pre(API::UFunction* fn, API::UObject* obj, void* locals, void* result);
};
