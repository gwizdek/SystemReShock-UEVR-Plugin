#pragma once
#include <windows.h>
#include <Xinput.h>
#include <unordered_set>
#include <map>

#include "mINI/ini.h"

#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/COMP_HackerInventory_classes.hpp"

#include "memo_structs.hpp"
#include "vr_controllers.hpp"
#include "SDK/BP_VRBody_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"

typedef enum HandPreference {
    RIGHT_HANDED,
    LEFT_HANDED
} HandPreference;

typedef enum ModEvent {
    MOD_EVENT_VR_HUD_INITIALIZE,
    MOD_EVENT_ENABLE_WORLD_RENDERING
} ModEvent;

typedef enum GameState {
    GAME_STATE_PLAYING,
    GAME_STATE_MAIN_MENU,
    GAME_STATE_PAUSE_MENU,
    GAME_STATE_LEDGER,
    GAME_STATE_WORKBENCH,
    GAME_STATE_CONVERSATION,
    GAME_STATE_CINEMATIC,
    GAME_STATE_COMPUTER_TERMINAL,
    GAME_STATE_UNDEFINED
} GameState;

static std::map<GameState, const char*> GameStateName = {
    { GAME_STATE_PLAYING, "Playing" },
    { GAME_STATE_MAIN_MENU, "Main Menu" },
    { GAME_STATE_PAUSE_MENU, "Pause Menu" },
    { GAME_STATE_LEDGER, "Ledger" },
    { GAME_STATE_WORKBENCH, "Workbench" },
    { GAME_STATE_CONVERSATION, "Conversation" },
    { GAME_STATE_CINEMATIC, "Cinematic" },
    { GAME_STATE_COMPUTER_TERMINAL, "Computer Terminal" },
    { GAME_STATE_UNDEFINED, "Undefined" }
};

using namespace uevr;

class VRHUD;
class VRWeapon;
class VRBody;

class SystemShockMain
{
private:
    const char* MOD_VERSION = "v2.0.0-alpha";

    VRControllers* m_vr_controllers{ nullptr };
    VRWeapon* m_vr_weapon{ nullptr };
    //VRHUD* m_vr_hud{ nullptr };
    VRBody* m_vr_body{ nullptr };

    bool m_ui_option_show_debug_view{ false };
    int m_ui_xinput_duration{ 0 };              // [microseconds]
    int m_ui_pre_engine_tick_duration{ 0 };     // [microseconds]

    // convenience pointers
    SDK::UWorld* m_world{ nullptr };
    SDK::APawn* m_pawn{ nullptr };
    SDK::UCOMP_HackerInventory_C* m_inventory{ nullptr };
    SDK::UWIDGET_PlayerHUD_C* m_sdk_hud{ nullptr };

    // utils
    std::unordered_set<ModEvent> m_mod_events{};
    int m_toggle_native_fix_counter{ -1 };
    SDK::FHitResult m_hit_result{};
    bool m_camera_initialized{ false };
    SDK::FVector m_last_pos{ 0.f, 0.f, 0.f };
    SDK::FRotator m_last_rot{ 0.f, 0.f, 0.f };
    bool m_initialized{ false };
    bool m_gui_visible{ true };
    void toggle_gui();

    // watched state
    MemoProperty<GameState> m_game_state{ GAME_STATE_UNDEFINED, GAME_STATE_UNDEFINED };
    MemoProperty<SDK::ULevel*> m_level{ nullptr, nullptr };
    MemoBoolean m_is_game_paused{ false };
    MemoBoolean m_is_interactable_in_range{ false };
    MemoBoolean m_is_crouched{ false };
    MemoProperty<bool> m_player_interacting{ false, false };

    // controls
    MemoTriggerInput m_gamepad_trigger_right{ true, 200, 100 };
    MemoTriggerInput m_gamepad_trigger_left{ false, 200, 100 };
    MemoInput m_gamepad_right_shoulder{ XINPUT_GAMEPAD_RIGHT_SHOULDER, "RIGHT_SHOULDER" };
    MemoInput m_gamepad_left_shoulder{ XINPUT_GAMEPAD_LEFT_SHOULDER, "LEFT_SHOULDER" };
    MemoInput m_gamepad_right_thumb{ XINPUT_GAMEPAD_RIGHT_THUMB, "RIGHT_THUMB" };
    MemoInput m_gamepad_left_thumb{ XINPUT_GAMEPAD_LEFT_THUMB, "LEFT_THUMB" };
    MemoInput m_gamepad_btn_a{ XINPUT_GAMEPAD_A, "BTN_A" };
    MemoDualInput m_gamepad_btn_b{ XINPUT_GAMEPAD_B, "BTN_B" };
    MemoInput m_gamepad_btn_x{ XINPUT_GAMEPAD_X, "BTN_X" };
    MemoDualInput m_gamepad_btn_y{ XINPUT_GAMEPAD_Y, "BTN_Y" };

    // mod options
    int m_ui_option_look_sensitivity{ 5 };

public:
    SystemShockMain();
    virtual ~SystemShockMain();

    void on_tick(float delta);
    void on_xinput(XINPUT_STATE* state, const UEVR_VRData* vr);
    void on_draw_imgui();
    bool load_mod_config();
    bool save_mod_config();
    void cleanup_pointers();
    static void cleanup_actors();

    bool prepare_pointers();
    void prepare_state();
    void prepare_game_state();
    
    // getters
    bool get_ui_option_show_debug_view() { return m_ui_option_show_debug_view; };
    VRControllers* get_vr_controllers() { return m_vr_controllers; };
    VRWeapon* get_vr_weapon() { return m_vr_weapon; };
    VRBody* get_vr_body() { return m_vr_body; };
    MemoProperty<bool>* get_is_player_interacting() { return &m_player_interacting; };
    SDK::UCOMP_HackerInventory_C* get_inventory() { return m_inventory; };
    SDK::APawn* get_pawn() { return m_pawn; };
    
    // setters
    void set_last_pos(UEVR_Vector3f* position);
    void set_last_rot(UEVR_Rotatorf* rotation);
    void set_ui_xinput_duration(int value) { m_ui_xinput_duration = value; };
    void set_ui_pre_engine_tick_duration(int value) { m_ui_pre_engine_tick_duration = value; };

    void apply_delta(UEVR_Vector3f* position, UEVR_Rotatorf* rotation);

    // handlers
    void handle_controller_input(XINPUT_STATE* state);
    void handle_level_change();
    void handle_game_state();
    void handle_mod_events();
    void handle_crouch();
    void handle_weapon();
    void set_component_loc_rot_to_rh_motion_controller(SDK::USceneComponent* scene_component);
    void handle_smooth_turning(XINPUT_STATE* state, const UEVR_VRData* vr);
};
