#pragma once

//#include "imgui/imgui.h"
//#include "imgui/imgui_impl_dx11.h"
//#include "imgui/imgui_impl_dx12.h"
//#include "imgui/imgui_impl_win32.h"
//
//#include "rendering/d3d11.hpp"
//#include "rendering/d3d12.hpp"

#include "uevr/Plugin.hpp"
#include "uevr/API.hpp"

#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/COMP_HackerInventory_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/_BP_VRBody_classes.hpp"

#include "memo_structs.hpp"
#include "vr_plugin_shared.hpp"


#define PLUGIN_LOG_ONCE(...) { \
    static bool _logged_ = false; \
    if (!_logged_) { \
        _logged_ = true; \
        API::get()->log_info(__VA_ARGS__); \
    } }

//extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

using namespace uevr;
using namespace SDK;

SDK::A_BP_VRBody_C* g_vr_body{};

class UEVRPlugin;
extern std::unique_ptr<UEVRPlugin> g_plugin;

class UEVRPlugin : public uevr::Plugin {
    const char* MOD_VERSION = "System Shock UEVR plugin [v2.0.0-alpha.0]";

public:
    UEVRPlugin() = default;
    virtual ~UEVRPlugin() {};

// -----------------------------------------------------------------------------
// Engine Tick measurements
// -----------------------------------------------------------------------------
private:
    const int CB_DURATION_SAMPLE_RATE = 100;
    bool m_xinput_cb_processed{ false };
    int m_cb_calls_count{ 0 };
    int m_ui_xinput_duration{ 0 };              // [microseconds]
    int m_ui_pre_engine_tick_duration{ 0 };     // [microseconds]

// -----------------------------------------------------------------------------
// ImGui
// -----------------------------------------------------------------------------
//private:
//    HWND m_wnd{};
//    bool m_imgui_initialized{ false };
//    bool m_was_rendering_desktop{ false };
//
//public:
//    void on_present() override;
//    void on_device_reset() override;
//    bool on_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) override;
//    bool initialize_imgui();
//    void on_post_render_vr_framework_dx11(ID3D11DeviceContext* context, ID3D11Texture2D* texture, ID3D11RenderTargetView* rtv) override;
//    void on_post_render_vr_framework_dx12(ID3D12GraphicsCommandList* command_list, ID3D12Resource* rt, D3D12_CPU_DESCRIPTOR_HANDLE* rtv) override;
//    void internal_frame();

// -----------------------------------------------------------------------------
// UEVR overrides
// -----------------------------------------------------------------------------
public:
    void on_initialize() override;
    void on_xinput_get_state(uint32_t* retval, uint32_t user_index, XINPUT_STATE* state) override;
    void on_pre_engine_tick(API::UGameEngine* engine, float delta) override;

// -----------------------------------------------------------------------------
// UEVR props
// -----------------------------------------------------------------------------
private:
    unsigned int m_default_aim_method{ 1 };

// -----------------------------------------------------------------------------
// Mod ImGui accessible props
// -----------------------------------------------------------------------------
private:
    bool m_ui_option_show_debug_view{ true };
    int m_ui_option_look_sensitivity{ 5 };

// -----------------------------------------------------------------------------
// Pointers
// -----------------------------------------------------------------------------
private:
    UWorld* m_world{ nullptr };
    UCOMP_HackerInventory_C* m_inventory{ nullptr };
    UWIDGET_PlayerHUD_C* m_neural_hud{ nullptr };
    //A_BP_VRBody_C* m_vr_body{ nullptr };


    // motion controllers
    SDK::AActor* m_right_hand_actor{ nullptr };
    SDK::AActor* m_left_hand_actor{ nullptr };
    SDK::UMotionControllerComponent* m_rh_controller_component{ nullptr };
    SDK::UMotionControllerComponent* m_lh_controller_component{ nullptr };



// -----------------------------------------------------------------------------
// Watched props
// -----------------------------------------------------------------------------
private:
    MemoProperty<APawn*> m_pawn{ nullptr, nullptr };
    MemoProperty<EGameState> m_game_state{ GAME_STATE_UNDEFINED, GAME_STATE_UNDEFINED };
    MemoProperty<ULevel*> m_level{ nullptr, nullptr };
    MemoBoolean m_is_game_paused{ false };
    MemoBoolean m_is_crouching{ false };
    MemoProperty<bool> m_player_interacting{ false, false };
    MemoProperty<bool> m_mfd_visible{ false, false };
    MemoProperty<bool> m_is_media_display_visible{ false, false };
    MemoBoolean m_is_ads_active{ false };
    MemoBoolean m_is_melee_weapon_hot{ false };

// -----------------------------------------------------------------------------
// Controller State
// -----------------------------------------------------------------------------
private:
    MemoTriggerInput m_gamepad_right_trigger{ true, 200, 100 };
    MemoTriggerInput m_gamepad_left_trigger{ false, 200, 100 };
    MemoInput m_gamepad_right_shoulder{ XINPUT_GAMEPAD_RIGHT_SHOULDER, "RIGHT_SHOULDER" };
    MemoInput m_gamepad_left_shoulder{ XINPUT_GAMEPAD_LEFT_SHOULDER, "LEFT_SHOULDER" };
    MemoInput m_gamepad_right_thumb{ XINPUT_GAMEPAD_RIGHT_THUMB, "RIGHT_THUMB" };
    MemoInput m_gamepad_left_thumb{ XINPUT_GAMEPAD_LEFT_THUMB, "LEFT_THUMB" };
    MemoInput m_gamepad_btn_a{ XINPUT_GAMEPAD_A, "BTN_A" };
    MemoDualInput m_gamepad_btn_b{ XINPUT_GAMEPAD_B, "BTN_B" };
    MemoInput m_gamepad_btn_x{ XINPUT_GAMEPAD_X, "BTN_X" };
    MemoDualInput m_gamepad_btn_y{ XINPUT_GAMEPAD_Y, "BTN_Y" };
    // customizable actions
    MemoInput m_hotbar_selector_button{ XINPUT_GAMEPAD_RIGHT_THUMB, "HOTBAR_SELECTOR_BUTTON" };
    MemoInput m_hardware_selector_button{ XINPUT_GAMEPAD_LEFT_THUMB, "HARDWARE_SELECTOR_BUTTON" };

    // utils
    int32 m_viewport_size_x{ 1920 }, m_viewport_size_y{ 1080 };
    float m_mouse_wheel_debounce_timer{ 0.f };
    FHitResult m_reusable_hit_result{};
    bool m_gui_visible{ true };
    bool m_trigger_test_1{ false };
    bool m_trigger_test_2{ false };
    float m_melee_cooldown{ 0.f };

// -----------------------------------------------------------------------------
// Plugin
// -----------------------------------------------------------------------------
public:
    bool prepare_pointers();
    void prepare_game_state();
    void handle_smooth_turning(XINPUT_STATE* state);
    void handle_primary_item_selector(XINPUT_STATE* state, const UEVR_VRData* vr);
    void handle_game_state_change();
    void handle_level_change();
    void handle_media_display();
    void handle_mfd_interactions(XINPUT_STATE* state, const UEVR_VRData* vr);
    void handle_ads();
    void cleanup_pointers();
    void send_mouse(WORD key, bool key_up);
    bool is_valid_vr_body_hacker_implant_pawn();
    void update_trailing_rotation(float delta);
    // Motion Controllers
    void initialize_mcs(SDK::APAWN_Hacker_Implant_C* pawn);
    static void cleanup_actors();
    void SpawnCustom2DScreen();
    void toggle_gui();
    void try_melee();
    void apply_damage();
    
    // Input handlers
    void handle_xinput(XINPUT_STATE* state, const UEVR_VRData* vr);
    void handle_citadel_station_xinput(XINPUT_STATE* state, const UEVR_VRData* vr);

    SDK::AActor* Custom2DScreen{ nullptr };
};
