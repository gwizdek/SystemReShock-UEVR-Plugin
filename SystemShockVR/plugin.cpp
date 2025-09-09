#include "plugin.hpp"
#include "main.hpp"

using namespace uevr;

std::unique_ptr<UEVRPlugin> g_plugin = std::make_unique<UEVRPlugin>();

UEVRPlugin::UEVRPlugin() {
}

UEVRPlugin::~UEVRPlugin() {
    m_main->~SystemShockMain();
}

void UEVRPlugin::on_initialize() {
    PLUGIN_LOG_ONCE("Plugin Initializing...");

    // cleanup stale actors
    SystemShockMain::cleanup_actors();

    m_main = new SystemShockMain();

    hook_bp_fn(L"BlueprintGeneratedClass /Game/Blueprints/Inventory/Items/Weapons/ITEM_ProjectileWeapon_Base.ITEM_ProjectileWeapon_Base_C", L"FireProjectileInDirection", (UEVR_UFunction_NativePostFn)mod_onfire_pre, NULL, false);
}

bool UEVRPlugin::hook_bp_fn(std::wstring_view class_name, std::wstring_view fn_name, UEVR_UFunction_NativePreFn pre, UEVR_UFunction_NativePostFn post, bool use_native)
{
    API::get()->log_info("Entering hook_bp_fn");
    auto obj = (API::UClass*)API::get()->find_uobject(class_name);

    if (obj == nullptr) {
        API::get()->log_info("Failed to find %ls", class_name.data());
        return false;
    }

    auto fn = obj->find_function(fn_name);

    if (fn == nullptr) {
        API::get()->log_info("Failed to find %ls", fn_name.data());
        return false;
    }

    API::get()->log_info("getting function flags");
    uint32_t flags = fn->get_function_flags();

    if (use_native)
    {
        flags = flags | 0x400;
    }
    else
    {
        flags = flags & ~0x400;
    }

    API::get()->log_info("Setting function flags to 0x%08x", flags);
    fn->set_function_flags(flags);

    API::get()->log_info("Calling hook_ptr for %ls", fn_name.data());
    return API::get()->param()->sdk->ufunction->hook_ptr((UEVR_UFunctionHandle)fn, pre, post);
}

bool UEVRPlugin::mod_onfire_pre(API::UFunction* fn, API::UObject* obj, void* locals, void* result)
{
    API::get()->log_info("In mod_onfire_post");
    //if (obj != nullptr)
    //{
    //    const auto objname = obj->get_full_name();
    //    API::get()->log_info("mod_onfire_post - Current Weapon: %ls", objname.c_str());
    //}

    //if (locals != nullptr)
    //{
    //    makeFireRequest_params* params = (makeFireRequest_params*)locals;
    //    API::get()->log_info("%s", "Params:");
    //    params->AimPosition = new UEVR_Vector3d(0.0, 90.0, 180.0);
    //    API::get()->log_info("%f", params->AimPosition.x);
    //    API::get()->log_info("%f", params->AimPosition.y);
    //    API::get()->log_info("%f", params->AimPosition.z);
    //}
    //else
    //{
    //    API::get()->log_info("mod_onfire_post - locals is null");
    //}

    API::get()->log_info("mod_onfire_post returning false");
    return true;
}


void UEVRPlugin::on_xinput_get_state(uint32_t* retval, uint32_t user_index, XINPUT_STATE* state) {
    PLUGIN_LOG_ONCE("XInput Get State");

    const UEVR_VRData* vr = API::get()->param()->vr;
    if (!vr->is_runtime_ready())
        return;

    if (m_main != nullptr) {
        // start cb timer
        std::chrono::steady_clock::time_point begin_time;
        if (m_main->get_ui_option_show_debug_view() && m_cb_calls_count == 0) {
            begin_time = std::chrono::steady_clock::now();
        }

        if (!m_main->prepare_pointers())
            return;
        m_main->prepare_state();
        m_main->prepare_game_state();
        m_main->on_xinput(state, vr);

        // set it to true, so we won't process pawn again in pre_engine_tick cb
        m_xinput_cb_processed = true;

        // calculate cb duration
        if (m_main->get_ui_option_show_debug_view() && m_cb_calls_count == 0) {
            std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
            m_main->set_ui_xinput_duration(static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - begin_time).count()));
        }
    }
}

void UEVRPlugin::on_pre_engine_tick(API::UGameEngine* engine, float delta) {
    PLUGIN_LOG_ONCE("Pre Engine Tick: %f", delta);

    const UEVR_VRData* vr = API::get()->param()->vr;
    if (!vr->is_runtime_ready())
        return;

    if (m_main != nullptr) {
        m_cb_calls_count = m_cb_calls_count < CB_DURATION_SAMPLE_RATE ? ++m_cb_calls_count : 0;
        // start cb timer
        std::chrono::steady_clock::time_point begin_time;
        if (m_main->get_ui_option_show_debug_view() && m_cb_calls_count == 0) {
            begin_time = std::chrono::steady_clock::now();
        }

        // if the controllers are not active, the xinput cb is not triggered.
        // normally we want the xinput cb to prepare vars as it's the first cb to be called
        // but if it wasn't called, we prepare them here
        if (!m_xinput_cb_processed) {
            if (!m_main->prepare_pointers())
                return;
            m_main->prepare_state();
            m_main->prepare_game_state();
        }
        else {
            // reset for next cb iteration
            m_xinput_cb_processed = false;
        }

        m_main->on_tick(delta);

        // calculate cb duration
        if (m_main->get_ui_option_show_debug_view() && m_cb_calls_count == 0) {
            std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
            m_main->set_ui_pre_engine_tick_duration(static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - begin_time).count()));
        }
    }
}

void UEVRPlugin::on_pre_calculate_stereo_view_offset(UEVR_StereoRenderingDeviceHandle, int view_index, float world_to_meters,
    UEVR_Vector3f* position, UEVR_Rotatorf* rotation, bool is_double) {
    if (m_main != nullptr && view_index == 1) {
        m_main->set_last_pos(position);
        m_main->set_last_rot(rotation);
    }
};



void UEVRPlugin::on_post_calculate_stereo_view_offset(UEVR_StereoRenderingDeviceHandle, int view_index, float world_to_meters,
    UEVR_Vector3f* position, UEVR_Rotatorf* rotation, bool is_double) {
    if (view_index != 1) {
        return;
    }
    
    if (m_main != nullptr) {
        m_main->apply_delta(position, rotation);
    }
};




// -------------------------------------------------------------------------------------
// ImGui
// -------------------------------------------------------------------------------------
bool UEVRPlugin::on_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);

    return !ImGui::GetIO().WantCaptureMouse && !ImGui::GetIO().WantCaptureKeyboard;
}

void UEVRPlugin::on_device_reset() {
    PLUGIN_LOG_ONCE("Device Reset");

    //std::scoped_lock _{ m_imgui_mutex };

    const auto renderer_data = API::get()->param()->renderer;

    if (renderer_data->renderer_type == UEVR_RENDERER_D3D11) {
        ImGui_ImplDX11_Shutdown();
        g_d3d11 = {};
    }

    if (renderer_data->renderer_type == UEVR_RENDERER_D3D12) {
        ImGui_ImplDX12_Shutdown();
        g_d3d12 = {};
    }

    m_imgui_initialized = false;
}

void UEVRPlugin::on_post_render_vr_framework_dx11(ID3D11DeviceContext* context, ID3D11Texture2D* texture, ID3D11RenderTargetView* rtv) {
    PLUGIN_LOG_ONCE("Post Render VR Framework DX11");

    const auto vr_active = API::get()->param()->vr->is_hmd_active();

    if (!m_imgui_initialized || !vr_active) {
        return;
    }

    if (m_was_rendering_desktop) {
        m_was_rendering_desktop = false;
        on_device_reset();
        return;
    }

    //std::scoped_lock _{ m_imgui_mutex };

    ImGui_ImplDX11_NewFrame();
    g_d3d11.render_imgui_vr(context, rtv);
}

void UEVRPlugin::on_post_render_vr_framework_dx12(ID3D12GraphicsCommandList* command_list, ID3D12Resource* rt, D3D12_CPU_DESCRIPTOR_HANDLE* rtv) {
    PLUGIN_LOG_ONCE("Post Render VR Framework DX12");

    const auto vr_active = API::get()->param()->vr->is_hmd_active();

    if (!m_imgui_initialized || !vr_active) {
        return;
    }

    if (m_was_rendering_desktop) {
        m_was_rendering_desktop = false;
        on_device_reset();
        return;
    }

    //std::scoped_lock _{ m_imgui_mutex };

    ImGui_ImplDX12_NewFrame();
    g_d3d12.render_imgui_vr(command_list, rtv);
}

bool UEVRPlugin::initialize_imgui() {
    if (m_imgui_initialized) {
        return true;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    static const auto imgui_ini = API::get()->get_persistent_dir(L"outer_worlds_vr_imgui.ini").string();
    ImGui::GetIO().IniFilename = imgui_ini.c_str();
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

    const auto renderer_data = API::get()->param()->renderer;

    DXGI_SWAP_CHAIN_DESC swap_desc{};
    auto swapchain = (IDXGISwapChain*)renderer_data->swapchain;
    swapchain->GetDesc(&swap_desc);

    m_wnd = swap_desc.OutputWindow;

    if (!ImGui_ImplWin32_Init(m_wnd)) {
        return false;
    }

    if (renderer_data->renderer_type == UEVR_RENDERER_D3D11) {
        if (!g_d3d11.initialize()) {
            return false;
        }
    }
    else if (renderer_data->renderer_type == UEVR_RENDERER_D3D12) {
        if (!g_d3d12.initialize()) {
            return false;
        }
    }

    m_imgui_initialized = true;
    return true;
}

void UEVRPlugin::on_present() {
    //std::scoped_lock _{ m_imgui_mutex };

    if (!m_imgui_initialized) {
        API::get()->log_warn("ImGui not initialized");
        if (!initialize_imgui()) {
            API::get()->log_error("Failed to initialize ImGui");
            return;
        }
        else {
            API::get()->log_warn("Initialized ImGui");
        }
    }

    const auto renderer_data = API::get()->param()->renderer;

    if (renderer_data->renderer_type == UEVR_RENDERER_D3D11) {
        ImGui_ImplDX11_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        if (m_main != nullptr) {
            m_main->on_draw_imgui();
        }

        ImGui::EndFrame();
        ImGui::Render();

        g_d3d11.render_imgui();
    }
    else if (renderer_data->renderer_type == UEVR_RENDERER_D3D12) {
        auto command_queue = (ID3D12CommandQueue*)renderer_data->command_queue;

        if (command_queue == nullptr) {
            return;
        }

        ImGui_ImplDX12_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        if (m_main != nullptr) {
            m_main->on_draw_imgui();
        }

        ImGui::EndFrame();
        ImGui::Render();

        g_d3d12.render_imgui();
    }
}
