#define  _CRT_SECURE_NO_WARNINGS 1
#define  _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING 1
#define _DEBUG_DURATIONS 0

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <memory>
#include <mutex>
#include <iostream>
#include <codecvt>
#include <chrono>
#include <map>
#include <set>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_dx12.h"
#include "imgui/imgui_impl_win32.h"

#include "rendering/d3d11.hpp"
#include "rendering/d3d12.hpp"

#include "SDK/Engine_classes.hpp"
#include "SDK/HeadMountedDisplay_classes.hpp"
#include "SDK/ITEM_WeaponBase_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/PAWN_Hacker_Simple_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_parameters.hpp"
#include "SDK/COMP_HackerInventory_classes.hpp"
#include "SDK/WIDGET_InventoryContextMenu_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/WIDGET_SimpleHUD_classes.hpp"
#include "SDK/WIDGET_CyberspaceHUD_classes.hpp"
#include "SDK/WIDGET_Minimap_classes.hpp"
#include "SDK/WIDGET_HotbarSlot_classes.hpp"
#include "SDK/WIDGET_Biometer_classes.hpp"
#include "SDK/WIDGET_Compass_classes.hpp"
#include "SDK/WIDGET_MainMenu_InGame_classes.hpp"
#include "SDK/WIDGET_CrosshairCursor_classes.hpp"
#include "SDK/WIDGET_BootupScreen_classes.hpp"
#include "SDK/WIDGET_CrashScreen_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/CH_Hacker_AnimBP_classes.hpp"
#include "SDK/PAWN_SystemShockCharacter_classes.hpp"
#include "SDK/CON_Hacker_classes.hpp"
#include "SDK/SAVE_Settings_classes.hpp"
#include "SDK/ENUM_OffReducedNormal_structs.hpp"
#include "SDK/CharacterAction_classes.hpp"
#include "SDK/COMP_ActionManager_classes.hpp"
#include "SDK/WEAPON_GrenadeLauncher_classes.hpp"
#include "SDK/INTERACT_Laptop_classes.hpp"

#include "mINI/ini.h"
#include "uevr/Plugin.hpp"
#include "pch.h"

#include "SceneComponent.hpp"
#include "MOVECONTROL_FocusableInteract_C.hpp"
#include "vr_plugin_shared.hpp"
#include "vr_hacker_hud.hpp"


#define PLUGIN_LOG_ONCE(...) {\
    static bool _logged_ = false; \
    if (!_logged_) { \
        _logged_ = true; \
        API::get()->log_info(__VA_ARGS__); \
    }}

#define INPUT_DEADZONE_LO  ( 0.01f * FLOAT(0x7FFF) )  // Default to 01% of the +/- 32767 range.
#define INPUT_DEADZONE_MED ( 0.45f * FLOAT(0x7FFF) )  // Default to 45% of the +/- 32767 range.
#define INPUT_DEADZONE_HI  ( 0.80f * FLOAT(0x7FFF) )  // Default to 80% of the +/- 32767 range.

#define META_QUEST      0
#define WMR             1

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

using namespace uevr;

const char* MOD_VERSION = "1.3.0";
const int CB_DURATION_SAMPLE_RATE = 100;

typedef struct _TIMER_STRUCT
{
    bool* XPressed;
    std::time_t* TimeStamp;
}   TIMER_STRUCT;

// Pawn states
typedef enum PawnState
{
    PAWN_UNKNOWN,
    PAWN_PLAYERGHOST,
    PAWN_HACKERSIMPLE,
    PAWN_HACKERIMPLANT,
    PAWN_AVATAR,
} PawnState;

const char* PawnStateNames[5] = { "PAWN_UNKNOWN", "PAWN_PLAYERGHOST", "PAWN_HACKERSIMPLE", "PAWN_HACKERIMPLANT", "PAWN_AVATAR" };

typedef enum HackerWeapon
{
    WEAPON_NONE,
    WEAPON_LEAD_PIPE,
    WEAPON_WRENCH,
    WEAPON_SHOTGUN,
    WEAPON_SKORPION,
    WEAPON_MAGNUM,
    WEAPON_ION,
    WEAPON_RAIL,
    WEAPON_PLASMA_RIFLE,
    WEAPON_MAG_PULSE,
    WEAPON_SPARQ_BEAM,
    WEAPON_MINI_PISTOL,
    WEAPON_GRENADE_LAUNCHER,
    WEAPON_ASSAULT_RIFLE,
    WEAPON_LASER_RAPIER,
    GRENADE_MANAGER,
    MEDIPATCH_MANAGER,
    STAMINUP_MANAGER,
    BERSERK_PATCH_MANAGER,
    VISION_PATCH_MANAGER,
    DETOX_PATCH_MANAGER,
    FIRST_AID_KIT_MANAGER,
    BATTERY_PACK_MANAGER,
    PROXIMITY_MINE_MANAGER
} HackerWeapon;

// Montage type
typedef enum MontageType {
    STARTING,
    ENDING,
    SINGLE,
    UNKNOWN,
    NONE,
} MontageType;

typedef std::tuple<std::string, MontageType> MontageMeta;

//  Montage name                                        type
const std::array<MontageMeta, 13> g_montages{ {
    { "CH_Hacker_No_Montage",                           NONE,       },
    { "CH_Hacker_Unknown_Montage",                      UNKNOWN,    },
    { "CH_Hacker_SurgicalBed_Right_Enter_Montage",      STARTING,   },
    { "CH_Hacker_SurgicalBed_Right_Exit_Montage",       ENDING,     },
    { "CH_Hacker_SurgicalBed_Left_Enter_Montage",       STARTING,   },
    { "CH_Hacker_SurgicalBed_Left_Exit_Montage",        ENDING,     },
    { "CH_Hacker_death_p_Montage",                      SINGLE,     },
    { "CH_Hacker_Terminal_Use_Montage",                 SINGLE,     },
    { "CH_Hacker_Terminal_Dismount_Montage",            SINGLE,     },
    { "CH_Hacker_Cryobed_Wake_Montage",                 SINGLE,     },
    { "CH_Hacker_use_radiation_treatment_Montage",      SINGLE,     },
    { "MONT_HackerRespawn",                             SINGLE,     },
} };

typedef std::tuple<std::string, bool> InteractableMeta;

//  Interactable name                       Hide arms when interacting
const std::vector<InteractableMeta> g_interactables{ {
    { "INTERACT_SalvageStation",            true,   },
    { "INTERACT_TransdermalDispenser",      true,   },
    { "INTERACT_Snacktron",                 true,   },
    { "INTERACT_Keypad",                    true,   },
    { "PUZZLE_",                            true,   },
    { "INTERACT_Ladder",                    false,  },
    { "INTERACT_SurgeryMachine",            false,  },
} };

typedef std::tuple<std::string, SDK::FVector, float> WeaponMeta;

//  HackerWeapon enum           Search string               Weapon offset               Selector distance offset
const std::map<HackerWeapon, WeaponMeta> weapons_map {
    { WEAPON_NONE,              { "None",                   { 0.0f, 0.0f, 0.0f },       0.0f    } },
    { WEAPON_LEAD_PIPE,         { "LeadPipe",               { 0.0f, 4.0f, -8.0f },      0.0f    } },    // ok
    { WEAPON_WRENCH,            { "Wrench",                 { 0.0f, 4.0f, -8.0f },      0.0f    } },    // ok
    { WEAPON_SHOTGUN,           { "Shotgun",                { -2.6f, -2.0f, -1.1f },    10.0f   } },    // ok
    { WEAPON_SKORPION,          { "Skorpion",               { 0.0f, -5.0f, -0.5f },     10.0f   } },    // ok
    { WEAPON_MAGNUM,            { "Magnum",                 { -2.0f, -0.4f, -1.43f },   0.0f    } },    // ok
    { WEAPON_ION,               { "Ion",                    { 2.5f, -4.0f, -1.5f },     10.0f   } },    // ok
    { WEAPON_RAIL,              { "Rail",                   { 3.5f, -6.4f, -4.4f },     10.0f   } },    // ok
    { WEAPON_PLASMA_RIFLE,      { "PlasmaRifle",            { 10.0f, -2.3f, -7.6f },    10.0f   } },    // ok
    { WEAPON_MAG_PULSE,         { "MagPulse",               { -2.5f, -3.5f, -2.0f },    0.0f    } },    // ok
    { WEAPON_SPARQ_BEAM,        { "SparqBeam",              { 2.75f, -3.0f, -7.25f },   0.0f    } },    // ok
    { WEAPON_MINI_PISTOL,       { "MiniPistol",             { 0.0f, -0.8f, -0.5f },     0.0f    } },    // ok
    { WEAPON_GRENADE_LAUNCHER,  { "GrenadeLauncher",        { 6.0f, -6.0f, -1.15f },    10.0f   } },    // ok
    { WEAPON_ASSAULT_RIFLE,     { "AssaultRifle",           { 6.5f, -5.0f, -1.1f },     10.0f   } },    // ok
    { WEAPON_LASER_RAPIER,      { "LaserRapier",            { -2.0f, -15.0f, 0.0f },    0.0f    } },    // ok
    { GRENADE_MANAGER,          { "GrenadeManager",         { 0.0f, -3.5f, -2.0f },     0.0f    } },    // ok
    { MEDIPATCH_MANAGER,        { "MedipatchManager",       { 0.0f, -1.5f, -3.5f },     0.0f    } },    // ok
    { STAMINUP_MANAGER,         { "StaminupManager",        { 0.0f, -1.5f, -3.5f },     0.0f    } },    // ok
    { BERSERK_PATCH_MANAGER,    { "BerserkPatchManager",    { 0.0f, -1.5f, -3.5f },     0.0f    } },    // ok
    { VISION_PATCH_MANAGER,     { "VisionPatchManager",     { 0.0f, -1.5f, -3.5f },     0.0f    } },    // ok
    { DETOX_PATCH_MANAGER,      { "DetoxPatchManager",      { 0.0f, -1.5f, -3.5f },     0.0f    } },    // ok
    { FIRST_AID_KIT_MANAGER,    { "FirstAidKitManager",     { 4.0f, -18.0f, -8.0f },    10.0f   } },    // ok
    { BATTERY_PACK_MANAGER,     { "BatteryPackManager",     { 9.0f, -17.0f, -13.0f },   0.0f    } },    // ok
    { PROXIMITY_MINE_MANAGER,   { "ProximityMineManager",   { 0.0f, -6.0f, -7.0f },     0.0f    } },    // ok
};

class SystemShockPlugin : public uevr::Plugin {
public:
    SystemShockPlugin() = default;
    virtual ~SystemShockPlugin() {
        API::get()->log_info("UEVR Plugin Closing...");
        
        // cleanup
        if (m_vr_hud != nullptr) {
            m_vr_hud->~VRHackerHUD();
        }
    }

    // utils
    std::recursive_mutex m_imgui_mutex{};
    HWND m_wnd{};
    bool m_imgui_initialized{ false };
    bool m_xinput_cb_processed{ false };
    bool m_was_rendering_desktop{ false };
    bool m_skip_hud_depth{ false };
    SDK::FHitResult m_hit_result{};
    int m_viewport_size_x{ 1920 }, m_viewport_size_y{ 1080 };

    // this set keeps events to be handled
    // if an event is successfully handled, it's removed form this set
    // usefull if you want to handle something in next engine ticks
    std::set<ModEvent> m_mod_events{};

    // convenience pointers
    API::UObject* m_pawn{ nullptr };
    SDK::UCOMP_HackerInventory_C* m_inventory{ nullptr };
    SDK::UITEM_WeaponBase_C* m_current_weapon{ nullptr };

    SDK::UWorld* m_sdk_world{ nullptr };
    SDK::APawn* m_sdk_pawn{ nullptr };
    SDK::UWIDGET_PlayerHUD_C* m_sdk_hud{ nullptr };

    // VR HUD
    VRHackerHUD* m_vr_hud{ nullptr };

    // game state
    MemoProperty <SDK::UAnimMontage*> m_current_montage{ nullptr, nullptr };
    MemoProperty <MontageType> m_montage_type{ UNKNOWN, UNKNOWN };
    SDK::FRotator m_camera_rotation{ 0.f, 0.f, 0.f };

    SDK::AINTERACT_Laptop_C* m_intro_laptop{ nullptr };
    SDK::UCharacterAction_C* m_current_action{ nullptr };
    MemoProperty<bool> m_mfd_visible{ false, false };
    MemoProperty<bool> m_main_menu_in_game_visible{ false, false };
    MemoProperty<bool> m_mfd_inventory_context_menu_visible{ false, false };
    MemoProperty<bool> m_player_alive{ true, true };
    MemoProperty<bool> m_player_interacting{ false, false };
    MemoProperty<std::string> m_channeling_interactable_name{ "", "" };
    MemoProperty<bool> m_player_crouching{ false, false };
    MemoProperty<bool> m_is_booting_up{ false, false };
    MemoProperty<bool> m_is_crashing{ false, false };
    MemoProperty<bool> m_is_using_laptop{ false, false };
    MemoProperty<bool> m_is_media_display_visible{ false, false };
    MemoProperty<PawnState> m_pawn_state{ PAWN_UNKNOWN, PAWN_UNKNOWN };
    MemoProperty<HackerWeapon> m_weapon_state{ WEAPON_NONE, WEAPON_NONE };
    MemoProperty<SDK::ULevel*> m_level{ nullptr, nullptr };
    bool m_player_sprinting{ false };
    bool m_player_jumping{ false };
    int m_cyberspace_aim_method{ 0 };

    // controller state
    MemoInput m_gamepad_right_shoulder{ XINPUT_GAMEPAD_RIGHT_SHOULDER, "RIGHT_SHOULDER" };
    MemoInput m_gamepad_left_shoulder{ XINPUT_GAMEPAD_LEFT_SHOULDER, "LEFT_SHOULDER" };
    MemoInput m_gamepad_right_thumb{ XINPUT_GAMEPAD_RIGHT_THUMB, "RIGHT_THUMB" };
    MemoInput m_gamepad_left_thumb{ XINPUT_GAMEPAD_LEFT_THUMB, "LEFT_THUMB" };
    MemoInput m_gamepad_btn_a{ XINPUT_GAMEPAD_A, "BTN_A" };
    MemoDualInput m_gamepad_btn_b{ XINPUT_GAMEPAD_B, "BTN_B" };
    MemoInput m_gamepad_btn_x{ XINPUT_GAMEPAD_X, "BTN_X" };
    MemoDualInput m_gamepad_btn_y{ XINPUT_GAMEPAD_Y, "BTN_Y" };
    MemoTriggerInput m_gamepad_trigger_right{ true, 200, 100 };
    MemoTriggerInput m_gamepad_trigger_left{ false, 200, 100 };

    // customizable actions
    MemoInput m_hotbar_selector_button{ XINPUT_GAMEPAD_RIGHT_SHOULDER, "HOTBAR_SELECTOR_BUTTON" };
    MemoInput m_hardware_selector_button{ XINPUT_GAMEPAD_RIGHT_THUMB, "HARDWARE_SELECTOR_BUTTON" };
    
    // mod options
    float m_fov{ 120.f };
    float m_ui_option_crosshair_cursor_scale{ 0.3f };
    float m_ui_option_crosshair_brackets_scale{ 0.0f };
    float m_ui_option_target_id_reticle_scale{ 0.3f };
    int m_ui_option_crosshair_depth{ 5 };
    float m_ui_option_player_height_modifier{ 0.0f };
    int m_ui_option_look_sensitivity{ 5 };
    bool m_ui_option_force_hide_compass{ true };
    bool m_ui_option_toggle_run_with_left_grip{ true };
    int m_ui_option_openxr_runtime{ META_QUEST };
    bool m_ui_option_disable_roomscale_when_aiming{ true };

    // unused
    int m_ui_option_hotbar_selector_button{ 0 };
    int m_ui_option_hardware_selector_button{ 1 };
    int m_ui_option_walk_run_toggle_button{ 1 };

    // debug
    int m_cb_calls_count{ 0 };
    bool m_ui_option_show_debug_view{ false };
    bool m_ui_option_apply_weapon_offset{ true };
    int m_ui_xinput_duration{ 0 }; // [microseconds]
    int m_ui_pre_engine_tick_duration{ 0 }; // [microseconds]

    void on_dllmain() override {}

    void on_initialize() override {
        // Logs to the appdata UnrealVRMod log.txt file
        API::get()->log_info("UEVR Initializing...");

        // load stored configuration from config file
        load_plugin_config();

        ImGui::CreateContext();

        // remove stale VR HUD actors (when re-enabling the plugin)
        VRHackerHUD::cleanup();
        m_vr_hud = new VRHackerHUD();

        m_mod_events.insert(MOD_EVENT_VR_HUD_INITIALIZE);
        
        // disable player focus (camera pull) on interactable objects like vending machines
        MOVECONTROL_FocusableInteract_C::disable_character_focusable_interactions();
    }

    void on_xinput_get_state(uint32_t* retval, uint32_t user_index, XINPUT_STATE* state) {
        PLUGIN_LOG_ONCE("XInput Get State");

        // start cb timer
        std::chrono::steady_clock::time_point begin_time;
        if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
            begin_time = std::chrono::steady_clock::now();
        }

        const UEVR_VRData* vr = API::get()->param()->vr;
        if (!vr->is_runtime_ready())
            return;

        if (!prepare_state(vr)) {
            API::get()->log_warn("State not prepared");
            return;
        }

        // handlers
        handle_pawn_changes(vr);
        handle_controller_input(state, vr);
        handle_lean();
        handle_mfd_changes(vr);

        // set it to true, so we won't process pawn again in pre_engine_tick cb
        m_xinput_cb_processed = true;

        if (state != nullptr) {
            if (
                m_pawn_state.matches_any({ PAWN_HACKERSIMPLE, PAWN_HACKERIMPLANT, PAWN_AVATAR }) &&
                !m_mfd_visible.value
            ) {
                handle_smooth_turning(state, vr);
            }
        }

        // calculate cb duration
        if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
            std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
            m_ui_xinput_duration = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - begin_time).count());
        }
    }

    void on_pre_engine_tick(API::UGameEngine * engine, float delta) override {
        PLUGIN_LOG_ONCE("Pre Engine Tick: %f", delta);

        m_cb_calls_count = m_cb_calls_count < CB_DURATION_SAMPLE_RATE ? ++m_cb_calls_count : 0;
        // start cb timer
        std::chrono::steady_clock::time_point begin_time;
        if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
            begin_time = std::chrono::steady_clock::now();
        }

        const UEVR_VRData* vr = API::get()->param()->vr;

        // if the controllers are not active, the xinput cb is not triggered.
        // normally we want the xinput cb to prepare vars as it's the first cb to be called
        // but if it wasn't called, we prepare them here
        if (!m_xinput_cb_processed) {
            if (!vr->is_runtime_ready())
                return;

            if (!prepare_state(vr)) {
                API::get()->log_info("State not prepared");
                return;
            }

            handle_pawn_changes(vr);
        }
        else {
            // reset for next cb iteration
            m_xinput_cb_processed = false;
        }

        // add delta time to dual buttons
        //m_gamepad_btn_b.add_delta(delta);
        m_gamepad_btn_y.add_delta(delta);
        
        handle_level_change(vr);

        if (m_vr_hud != nullptr) {
            m_vr_hud->handle_mod_events(&m_mod_events);

            if (m_pawn_state.value == PAWN_HACKERIMPLANT) {
                if (!m_mfd_visible.value && m_hotbar_selector_button.is_held()) {
                    m_vr_hud->update_primary_item_selector_location(delta);
                }
                if (!m_mfd_visible.value && m_hardware_selector_button.is_held()) {
                    m_vr_hud->update_secondary_item_selector_location(delta);
                }
                if (m_mfd_visible.value && !m_mod_events.contains(MOD_EVENT_SHOW_MFD)) {
                    m_vr_hud->update_mfd_mask_location(delta);
                }
            }
        }

        handle_look_pivot();
        handle_camera_lock(vr);
        handle_cyberspace_look_pivot(vr);
        handle_hud_depth(vr);
        handle_interactives_cursor_size();
        handle_animations(vr);
        handle_intro_laptop(vr);
        //handle_player_death(vr);
        handle_weapon_changes();
        handle_arms_mesh_visibility();
        handle_media_display();
        handle_player_height(vr);
        handle_in_game_menu(vr);
        handle_compass();

        // calculate cb duration
        if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
            std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
            m_ui_pre_engine_tick_duration = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - begin_time).count());
        }
    }

    // -------------------------------------------------------------------------------------
    // state setters
    // -------------------------------------------------------------------------------------

    // sets all needed pointers and state vars, so we can use them later in handlers
    bool prepare_state(const UEVR_VRData* vr) {

        // world
        m_sdk_world = SDK::UWorld::GetWorld();
        if (m_sdk_world == nullptr) {
            API::get()->log_warn("WARN: prepare_state::world = nullptr");
            return false;
        }

        // pawn
        m_sdk_pawn = SDK::UGameplayStatics::GetPlayerPawn(m_sdk_world, 0);
        if (m_sdk_pawn == nullptr) {
            API::get()->log_warn("WARN: prepare_state::m_sdk_pawn = nullptr");
            return false;
        }

        // pawn state (enums)
        if (m_sdk_pawn->GetFullName().starts_with("PAWN_Avatar")) {
            m_pawn_state.set_value(PAWN_AVATAR);
        }
        else if (m_sdk_pawn->GetFullName().starts_with("PAWN_PlayerGhost")) {
            m_pawn_state.set_value(PAWN_PLAYERGHOST);
        }
        else if (m_sdk_pawn->GetFullName().starts_with("PAWN_Hacker_Simple")) {
            m_pawn_state.set_value(PAWN_HACKERSIMPLE);
        }
        else if (m_sdk_pawn->GetFullName().starts_with("PAWN_Hacker_Implant")) {
            m_pawn_state.set_value(PAWN_HACKERIMPLANT);
        }

        // level
        m_level.set_value(m_sdk_world->PersistentLevel);
        
        // hud, vr hud, inventory context menu
        if (m_sdk_pawn->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass())) {
            static_cast<SDK::APAWN_Hacker_Implant_C*>(m_sdk_pawn)->GetNeuralHUD(&m_sdk_hud);
            if (m_sdk_hud == nullptr) {
                API::get()->log_warn("WARN: prepare_state::hud = nullptr");
                return false;
            }
            m_mfd_inventory_context_menu_visible.set_value(m_sdk_hud->WIDGET_InventoryContextMenu->IsInventoryContextMenuEnabled);
            m_is_booting_up.set_value(
                m_sdk_hud->WIDGET_BootupScreen->CurrentState != SDK::ENUM_BootupState::NewEnumerator7 &&
                m_sdk_hud->WIDGET_BootupScreen->CurrentState != SDK::ENUM_BootupState::NewEnumerator0
            );
            m_is_crashing.set_value(
                m_sdk_hud->WIDGET_CrashScreen->CurrentState != SDK::ENUM_CrashState::NewEnumerator2 &&
                m_sdk_hud->WIDGET_CrashScreen->CurrentState != SDK::ENUM_CrashState::NewEnumerator3
            );
            m_vr_hud->set_pointers(m_sdk_world, static_cast<SDK::APAWN_Hacker_Implant_C*>(m_sdk_pawn), m_sdk_hud);

            m_is_media_display_visible.consume();
            m_sdk_hud->IsMediaDisplayVisible(&m_is_media_display_visible.value);
                



        }
        else {
            m_sdk_hud = nullptr;
            m_vr_hud->set_pointers(m_sdk_world, nullptr, nullptr);
        }

        // inventory, current weapon, alive, interacting, animations
        if (
            m_sdk_pawn->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass()) ||
            m_sdk_pawn->IsA(SDK::APAWN_Hacker_Simple_C::StaticClass())
            ) {
            m_inventory = static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->COMP_HackerInventory;
            
            m_current_weapon = m_inventory->CurrentEquippedWeapon;
            m_player_alive.set_value(static_cast<SDK::APAWN_SystemShockCharacter_C*>(m_sdk_pawn)->IsAlive);
            m_player_interacting.set_value(static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->ChannelingInteractable != nullptr);

            // get channeling interactable name
            if (m_player_interacting.value) {
                m_channeling_interactable_name.set_value(static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->ChannelingInteractableName.ToString());
            } else {
                m_channeling_interactable_name.set_value("");
            }

            // animations
            const auto action_manager = static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->COMP_ActionManager;
            if (action_manager != nullptr) {
                // we do this here instead of using set_value (store old montage in prev_value and pass value to method)
                m_current_montage.consume();
                action_manager->GetCurrentMontage(&m_current_montage.value);
                action_manager->GetCurrentAction(&m_current_action);

                m_camera_rotation = static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->PlayerCamera->K2_GetComponentRotation();
            }
        }
        else {
            m_inventory = nullptr;
            m_current_weapon = nullptr;
            m_player_alive.set_value(false);
            m_player_interacting.set_value(false);
            m_channeling_interactable_name.set_value("");
            m_current_montage.set_value(nullptr);
            m_current_action = nullptr;
        }

        // ingame menu
        SDK::UWIDGET_MainMenu_InGame_C* main_menu{ nullptr };
        if (m_sdk_pawn->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass())) {
            static_cast<SDK::UWIDGET_PlayerHUD_C*>(static_cast<SDK::APAWN_Hacker_Implant_C*>(m_sdk_pawn)->PlayerHUDWidget)->GetMainMenuWidget(&main_menu);
            m_main_menu_in_game_visible.set_value(main_menu != nullptr && main_menu->IsMainMenuEnabled);
        } 
        else if (m_sdk_pawn->IsA(SDK::APAWN_Hacker_Simple_C::StaticClass())) {
            static_cast<SDK::UWIDGET_SimpleHUD_C*>(static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->PlayerHUDWidget)->GetMainMenuWidget(&main_menu);
            m_main_menu_in_game_visible.set_value(main_menu != nullptr && main_menu->IsMainMenuEnabled);
        }
        else if (m_sdk_pawn->IsA(SDK::APAWN_Avatar_C::StaticClass())) {
            API::get()->log_warn("WARN: avatar");
            static_cast<SDK::UWIDGET_CyberspaceHUD_C*>(static_cast<SDK::APAWN_Avatar_C*>(m_sdk_pawn)->CyberspaceUI)->GetMainMenuWidget(&main_menu);
            if (main_menu != nullptr) {
                API::get()->log_warn("WARN: main_menu->IsMainMenuEnabled %d", main_menu->IsMainMenuEnabled);
            }
            m_main_menu_in_game_visible.set_value(main_menu != nullptr && main_menu->IsMainMenuEnabled);
        }
        else {
            m_main_menu_in_game_visible.set_value(false);
        }

        // Introduction level laptop
        set_intro_laptop_pointer();
        if (m_intro_laptop != nullptr) {
            m_is_using_laptop.set_value(m_intro_laptop->IsInteracting);
        }

        // mfd
        m_mfd_visible.set_value(m_sdk_hud != nullptr && m_sdk_hud->bIsMFDVisible);

        // -------------- old code ------------
        // sets pointer to PAWN
        m_pawn = API::get()->get_local_pawn(0);
        if (m_pawn == nullptr) {
            API::get()->log_warn("WARN: prepare_state::m_pawn = nullptr");
            return false;
        }

        set_player_crouching_state();
        set_weapon_state();

        return true;
    }

    void set_player_crouching_state() {
        const auto move_control_manager_data = m_pawn->get_property_data<API::UObject*>(L"COMP_MoveControlManager");
        const auto move_control_manager = move_control_manager_data != nullptr ? *move_control_manager_data : nullptr;
        if (move_control_manager != nullptr) {
            m_player_crouching.set_value(move_control_manager->get_bool_property(L"IsTryingToCrouch"));
        }
        else {
            m_player_crouching.set_value(false);
        }
    }

    void set_weapon_state() {
        if (m_current_weapon != nullptr) {
            if (m_player_interacting.value) {
                m_weapon_state.set_value(WEAPON_NONE);
                return;
            }

            std::string weapon_name = m_current_weapon->GetName();

            for (auto const& [key, val] : weapons_map) {
                if (weapon_name.find(get<0>(val)) != std::string::npos) {
                    m_weapon_state.set_value(key);
                    return;
                }
            }
            m_weapon_state.set_value(WEAPON_NONE);
        }
        else {
            m_weapon_state.set_value(WEAPON_NONE);
        }
    }

    void set_intro_laptop_pointer() {
        if (m_pawn_state.value != PAWN_HACKERSIMPLE || m_intro_laptop != nullptr)
            return;

        API::UClass* laptop_c = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Art/Props/Hacker_Apartment/Laptop/INTERACT_Laptop.INTERACT_Laptop_C");
        if (laptop_c != nullptr) {
            std::vector<SDK::AINTERACT_Laptop_C*> matching_objects = laptop_c->get_objects_matching<SDK::AINTERACT_Laptop_C>();
            //API::get()->log_info("AINTERACT_Laptop_C object count: %d", matching_objects.size());

            for (size_t i = 0; i < matching_objects.size(); i++) {
                if (matching_objects[i]->GetFullName().find(".INTERACT_Laptop") != std::wstring::npos) {
                    API::get()->log_warn("AINTERACT_Laptop_C found");
                    m_intro_laptop = matching_objects[i];
                }
            }
        }
    }

    // -------------------------------------------------------------------------------------
    // handlers
    // -------------------------------------------------------------------------------------

    // handles controller state based on game context
    void handle_controller_input(XINPUT_STATE* state, const UEVR_VRData* vr) {
        m_gamepad_btn_a.set_state(state);
        m_gamepad_btn_x.set_state(state);
        m_gamepad_btn_b.set_state(state);
        m_gamepad_btn_y.set_state(state);
        m_gamepad_right_shoulder.set_state(state);
        m_gamepad_left_shoulder.set_state(state);
        m_gamepad_right_thumb.set_state(state);
        m_gamepad_left_thumb.set_state(state);
        m_gamepad_trigger_right.set_state(state);
        m_gamepad_trigger_left.set_state(state);

        m_hotbar_selector_button.set_state(state);
        m_hardware_selector_button.set_state(state);

        if (m_main_menu_in_game_visible.value) {
            // increase stick deadzone for better navigation in the menu
            if (std::abs(state->Gamepad.sThumbLX) < INPUT_DEADZONE_HI) {
                state->Gamepad.sThumbLX = 0;
            }
            if (std::abs(state->Gamepad.sThumbLY) < INPUT_DEADZONE_HI) {
                state->Gamepad.sThumbLY = 0;
            }

            // don't remap other buttons in in-game menu
            return;
        }

        // clear jumping flag
        if (m_gamepad_btn_x.is_released()) {
            m_player_jumping = false;
        }

        // normal level
        if (m_pawn_state.value == PAWN_HACKERIMPLANT) {
            // mute right stick Y axis
            state->Gamepad.sThumbRY = 0;

            // clear sprinting flag when using selected interactables (caused sporadic arms mesh misalignment)
            if (
                m_player_interacting.has_changed() &&
                m_player_interacting.value) {
                for (InteractableMeta interactable : g_interactables) {
                    if (m_channeling_interactable_name.value.find(std::get<0>(interactable)) != std::string::npos) {
                        m_player_sprinting = false;
                    }
                }
            }

            // MFD on
            if (m_mfd_visible.value) {
                handle_mfd_interactions(state, vr);
            }
            // interaction with with puzzles / vending machines / ladders
            else if (m_player_interacting.value) {
                // - make B btn exit interaction
                // - make A btn interact

                m_gamepad_btn_a.when_pressed_send(state, XINPUT_GAMEPAD_X);
                m_gamepad_btn_a.mute_state(state);

                // TODO check if this doesn't deadlock movement
                // programmatically stop interaction
                if (m_gamepad_btn_b.is_pressed()) {
                    bool result;
                    static_cast<SDK::APAWN_Hacker_Implant_C*>(m_sdk_pawn)->TryStopChannelingInteraction(&result);
                    if (result) {
                        static_cast<SDK::APAWN_Hacker_Implant_C*>(m_sdk_pawn)->TryStopFocusingOnInteract(&result);
                    }
                }
                m_gamepad_btn_b.mute_state(state);
            }
            // normal gameplay
            else {

                // disable pushback with left trigger
                if (m_ui_option_disable_roomscale_when_aiming) {
                    if (m_gamepad_trigger_left.is_held()) {
                        vr->set_mod_value("VR_RoomscaleMovement", "false");
                    }

                    if (m_gamepad_trigger_left.is_released()) {
                        vr->set_mod_value("VR_RoomscaleMovement", "true");
                    }
                }

                // prevent triggering crouch when channeling interaction stops
                if (m_gamepad_btn_b.is_held()) {
                    m_gamepad_btn_b.mute_state(state);
                }

                // disable explosives / consumables auto use
                m_gamepad_right_shoulder.mute_state(state);
                m_gamepad_left_shoulder.mute_state(state);

                if (m_gamepad_left_shoulder.is_pressed()) {
                    m_player_sprinting = !m_player_sprinting;
                }

                // use target identifier
                if (m_gamepad_trigger_left.is_held()) {
                    m_gamepad_right_thumb.force_state(state);
                }

                // sprint only when mod's toggle option is checked
                if (m_player_sprinting && m_ui_option_toggle_run_with_left_grip) {
                    m_gamepad_left_thumb.force_state(state);
                }

                // change weapon mode in long Y btn press
                //if (m_gamepad_btn_y.is_long_pressed(0.5f)) {
                //    m_gamepad_btn_y.force_state(state);
                //}
                //// toggle crouch on short Y btn press
                //else if (m_gamepad_btn_y.is_short_pressed()) {
                //    static_cast<SDK::APAWN_Hacker_Implant_C*>(m_sdk_pawn)->SetTryCrouch(true);
                //    m_gamepad_btn_y.mute_state(state);
                //}
                //else {
                //    m_gamepad_btn_y.mute_state(state);
                //}

                // swap action/jump
                m_gamepad_btn_a.mute_state(state);
                m_gamepad_btn_x.mute_state(state);

                // used 'held' so we can still hold A button to play picked up audio log files
                m_gamepad_btn_a.when_held_send(state, XINPUT_GAMEPAD_X);

                // we need to place additional condition btn X held state to prevent auto jump when using 'loot all'
                // when_held_send is only used when X button was pressed in normal walking mode and not in MFD
                if (m_gamepad_btn_x.is_pressed()) {
                    m_player_jumping = true;
                    m_player_sprinting = false;
                }
                if (m_player_jumping) {
                    m_gamepad_btn_x.when_held_send(state, XINPUT_GAMEPAD_A);
                }

                handle_primary_item_selector(state, vr);
                handle_secondary_item_selector(state, vr);
            }
        }

        // cyberspace
        if (m_pawn_state.value == PAWN_AVATAR) {

            // change control scheme on RS
            if (m_gamepad_right_thumb.is_pressed()) {
                m_cyberspace_aim_method = m_cyberspace_aim_method == 0 ? 2 : 0;

                if (m_cyberspace_aim_method == 0) {
                    vr->recenter_view();
                }

                vr->set_aim_method(m_cyberspace_aim_method);
                vr->set_decoupled_pitch_enabled(m_cyberspace_aim_method == 2);
            }

            m_gamepad_right_shoulder.when_held_send(state, XINPUT_GAMEPAD_A);
            m_gamepad_right_shoulder.mute_state(state);
            m_gamepad_left_shoulder.when_held_send(state, XINPUT_GAMEPAD_B);
            m_gamepad_left_shoulder.mute_state(state);

            if (m_cyberspace_aim_method == 2) {

                m_pawn->set_bool_property(L"bUseControllerRotationPitch", true);
                m_pawn->set_bool_property(L"bUseControllerRotationRoll", true);
                m_pawn->set_bool_property(L"bUseControllerRotationYaw", true);

                if (state->Gamepad.sThumbRY > INPUT_DEADZONE_MED) {
                    if (m_ui_option_openxr_runtime == META_QUEST) state->Gamepad.sThumbRX = 0;
                    m_gamepad_btn_a.force_state(state);
                }
                else if (state->Gamepad.sThumbRY < -INPUT_DEADZONE_MED) {
                    if (m_ui_option_openxr_runtime == META_QUEST) state->Gamepad.sThumbRX = 0;
                    m_gamepad_btn_b.force_state(state);
                }
            }
            else
            {
                if (m_ui_option_openxr_runtime == META_QUEST) {
                    m_pawn->set_bool_property(L"bUseControllerRotationPitch", false);
                    m_pawn->set_bool_property(L"bUseControllerRotationRoll", false);
                    m_pawn->set_bool_property(L"bUseControllerRotationYaw", false);
                }
                else {
                    m_pawn->set_bool_property(L"bUseControllerRotationPitch", true);
                    m_pawn->set_bool_property(L"bUseControllerRotationRoll", true);
                    m_pawn->set_bool_property(L"bUseControllerRotationYaw", true);
                }
            }
        }

        // main menu
        if (m_pawn_state.value == PAWN_PLAYERGHOST) {
            // increase stick deadzone for better navigation in the menu
            if (std::abs(state->Gamepad.sThumbLX) < INPUT_DEADZONE_HI) {
                state->Gamepad.sThumbLX = 0;
            }
            if (std::abs(state->Gamepad.sThumbLY) < INPUT_DEADZONE_HI) {
                state->Gamepad.sThumbLY = 0;
            }
        }

        // apartment intro
        if (m_pawn_state.value == PAWN_HACKERSIMPLE) {
            // swap action/jump
            m_gamepad_btn_a.mute_state(state);
            m_gamepad_btn_x.mute_state(state);

            m_gamepad_btn_a.when_held_send(state, XINPUT_GAMEPAD_X);
            m_gamepad_btn_x.when_pressed_send(state, XINPUT_GAMEPAD_A);
        }
    }

    // lock camera offsets
    void handle_camera_lock(const UEVR_VRData* vr) {
        vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
        vr->set_mod_value("VR_CameraRightOffset", "0.000000");
        vr->set_mod_value("VR_CameraUpOffset", "0.000000");
    }

    float get_current_weapon_distance_offset() {
        if (m_current_weapon != nullptr && m_weapon_state.value) {
            try {
                const WeaponMeta weapon_meta = weapons_map.at(m_weapon_state.value);
                const float distance_offset = get<2>(weapon_meta);
                return distance_offset;
            }
            catch(const std::out_of_range&) {
                return 0.f;
            }
        }
        return 0.f;
    }

    // primary item selector
    void handle_primary_item_selector(XINPUT_STATE* state, const UEVR_VRData* vr) {
        if (m_vr_hud != nullptr && m_vr_hud->get_hud_state() == VR_HUD_SUCCESS && !m_hardware_selector_button.is_held()) {

            if (m_hotbar_selector_button.is_pressed()) {
                m_vr_hud->set_primary_item_selector_visibility(true);
                // hide UEVR controlled HUD
                vr->set_mod_value("UI_Size", "0.000000");
                vr->set_mod_value("VR_RoomscaleMovement", "false");

                // show VR item selector
                m_vr_hud->set_laser_pointer_visibility(true);
                m_vr_hud->save_primary_item_selector_delta(get_current_weapon_distance_offset());

                // we will ignore Player mesh collisions on the channel that WidgetInteractionComponent uses
                // for the time the selector is active
                m_vr_hud->set_player_response_to_collision_channel(
                    item_selector_collision_channel, SDK::ECollisionResponse::ECR_Ignore
                );
                m_vr_hud->unselect_all_hotbar_slots();
            }

            if (m_hotbar_selector_button.is_released()) {
                m_vr_hud->change_quick_slot();

                // restore collisions
                m_vr_hud->set_player_response_to_collision_channel(
                    item_selector_collision_channel, SDK::ECollisionResponse::ECR_Block
                );
                m_vr_hud->set_primary_item_selector_visibility(false);
                m_vr_hud->set_laser_pointer_visibility(false);
                m_skip_hud_depth = true;

                vr->set_mod_value("VR_RoomscaleMovement", "true");
            }

            // state, when the item selector is shown
            if (m_hotbar_selector_button.is_held()) {
                m_vr_hud->update_laser_pointer_length(35.f);
                m_vr_hud->highlight_quick_slot();

                state->Gamepad.sThumbRX = 0;
            }

            m_hotbar_selector_button.mute_state(state);
        }
    }

    // secondary item selector
    void handle_secondary_item_selector(XINPUT_STATE* state, const UEVR_VRData* vr) {
        if (m_vr_hud != nullptr && m_vr_hud->get_hud_state() == VR_HUD_SUCCESS && !m_hotbar_selector_button.is_held()) {

            if (m_hardware_selector_button.is_pressed()) {
                // hide UEVR controlled HUD
                vr->set_mod_value("UI_Size", "0.000000");
                vr->set_mod_value("VR_RoomscaleMovement", "false");

                // show VR item selector
                m_vr_hud->set_secondary_item_selector_visibility(true);
                m_vr_hud->set_laser_pointer_visibility(true);
                m_vr_hud->save_secondary_item_selector_delta(get_current_weapon_distance_offset());

                // we will ignore Player mesh collisions on the channel that WidgetInteractionComponent uses
                // for the time the selector is active
                m_vr_hud->set_player_response_to_collision_channel(
                    item_selector_collision_channel, SDK::ECollisionResponse::ECR_Ignore
                );
                m_vr_hud->unselect_all_hacker_hardware();
            }

            if (m_hardware_selector_button.is_released()) {
                m_vr_hud->toggle_hardware();
                m_vr_hud->unselect_all_hacker_hardware();

                // restore collisions
                m_vr_hud->set_player_response_to_collision_channel(
                    item_selector_collision_channel, SDK::ECollisionResponse::ECR_Block
                );
                m_vr_hud->set_secondary_item_selector_visibility(false);
                m_vr_hud->set_laser_pointer_visibility(false);
                m_skip_hud_depth = true;

                vr->set_mod_value("VR_RoomscaleMovement", "true");
            }

            // state, when the item selector is shown
            if (m_hardware_selector_button.is_held()) {
                m_vr_hud->update_laser_pointer_length(35.f);
                m_vr_hud->highlight_hardware_item();

                state->Gamepad.sThumbRX = 0;
            }
        }
    }

    void handle_level_change(const UEVR_VRData* vr) {
        if (m_level.has_changed()) {
            if (m_level.value == nullptr) {
                return;
            }

            const UEVR_SDKData* sdk = API::get()->sdk();
            auto level_name = m_level.value->GetFullName();

            API::get()->log_info("New Level: %s", m_level.value->GetFullName().c_str());

            // check if it's the main menu
            if (level_name.ends_with(".00_Menu.PersistentLevel")) {
                sdk->functions->execute_command(L"r.postprocessing.disablematerials 0");
                vr->set_snap_turn_enabled(false);
            }
            else if (level_name.ends_with("Introduction.PersistentLevel")) {
                // fix intro camera r.postprocessing.disablematerials 1
                sdk->functions->execute_command(L"r.postprocessing.disablematerials 1");
                API::UObjectHook::set_disabled(false);
            }
            else if (level_name.ends_with("CitadelStation.PersistentLevel")) {
                sdk->functions->execute_command(L"r.postprocessing.disablematerials 0");

                // initialize hud
                m_mod_events.insert(MOD_EVENT_VR_HUD_INITIALIZE);

                // here it's to early to hide top/bottom dashboards, so we schedule it for VR HUD to handle
                m_mod_events.insert(MOD_EVENT_VR_HUD_HIDE_DASHBOARDS);

                if (m_sdk_hud) {
                    m_sdk_hud->WIDGET_Compass->SetCompassVisibility(false);
                    m_sdk_hud->WIDGET_Biometer->ShowBiometer(false);
                    apply_selected_crosshair_options();
                }

                // schedule vr hud init as level change has destroyed our custom actors
                // TODO rewrite to use mod events
                if (m_vr_hud != nullptr) {
                    m_vr_hud->set_hud_state(VR_HUD_PENDING_INIT);
                    m_vr_hud->clear_pointers();
                }

                m_vr_hud->set_crosshair_cursor_scale(&m_ui_option_crosshair_cursor_scale);
                m_vr_hud->set_cursor_brackets_scale(&m_ui_option_crosshair_brackets_scale);

                vr->set_aim_method(2);
                vr->set_snap_turn_enabled(true);
                vr->set_decoupled_pitch_enabled(true);
                vr->set_mod_value("VR_RoomscaleMovement", "true");
                API::UObjectHook::set_disabled(false);

                static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->PlayerCamera->bUsePawnControlRotation = true;
            }

            apply_vr_game_options();
            reset_height(vr);
        }
    }

    void handle_intro_laptop(const UEVR_VRData* vr) {
        if (m_is_using_laptop.has_changed() && m_is_using_laptop.value) {
            API::get()->log_warn("Started using intro laptop");
            reset_height(vr, 0.0f);
            API::UObjectHook::set_disabled(true);
            vr->set_mod_value("VR_RoomscaleMovement", "false");
        }
    }

    // not used
    void handle_player_death(const UEVR_VRData* vr) {
        if (m_player_alive.has_changed()) {
            
            if (!m_player_alive.value) {
                /* Disable hooks if killed to allow death animations to play in VR */
                API::UObjectHook::set_disabled(true);
                vr->set_mod_value("VR_RoomscaleMovement", "false");
                reset_height(vr);
            }
            else {
                API::UObjectHook::set_disabled(false);
                vr->set_mod_value("VR_RoomscaleMovement", "true");
            }
        }
    }

    // it sets the offset each tick - maybe can be improved but there's not much overhead
    void handle_weapon_changes() {
        if (m_pawn_state.value != PAWN_HACKERIMPLANT)
            return;

        if (m_current_weapon != nullptr && m_ui_option_apply_weapon_offset) {
            if (m_player_interacting.value) {
                return;
            }

            auto weapon_offset = m_pawn->get_property_data<SDK::FVector>(L"CurrentWeaponOffset");
            if (weapon_offset != nullptr) {
                try {
                    const WeaponMeta weapon_meta = weapons_map.at(m_weapon_state.value);
                    SDK::FVector weapon_offset_meta = get<1>(weapon_meta);

                    weapon_offset->X = weapon_offset_meta.X;
                    weapon_offset->Y = weapon_offset_meta.Y;
                    weapon_offset->Z = weapon_offset_meta.Z;
                }
                catch (const std::out_of_range&) {
                    API::get()->log_info("Tried to use unknown weapon");
                }
            }

            // hide grenade launcher ammo
            if (m_weapon_state.value == WEAPON_GRENADE_LAUNCHER) {
                if (SDK::UKismetSystemLibrary::IsValid(m_current_weapon) && m_current_weapon->IsA(SDK::UWEAPON_GrenadeLauncher_C::StaticClass())) {
                    auto grenade = static_cast<SDK::UWEAPON_GrenadeLauncher_C*>(m_current_weapon)->GrenadeMeshComponent;
                    if (grenade != nullptr) {
                        grenade->SetVisibility(false, true);
                    }
                }
            }
        }
    }

    void handle_arms_mesh_visibility() {
        if (m_pawn_state.matches_any({ PAWN_HACKERIMPLANT, PAWN_HACKERSIMPLE })) {
            // always hide arms on predefined interactables
            if (m_player_interacting.value) {
                for (InteractableMeta interactable : g_interactables) {
                    if (std::get<1>(interactable) && m_channeling_interactable_name.value.find(std::get<0>(interactable)) != std::string::npos) {
                        static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->ArmsMesh->SetVisibility(false, true);
                    }
                }
            }
            // also hide when holstered weapon and not interacting nor playing montage
            else if (m_current_weapon == nullptr && !m_player_interacting.value && m_current_montage.value == nullptr) {
                static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->ArmsMesh->SetVisibility(false, true);
            }
            // otherwise show arms
            else {
                static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->ArmsMesh->SetVisibility(true, true);
            }
        }
    }

    MontageType get_montage_type(SDK::UAnimMontage* in_montage) {
        if (in_montage == nullptr)
            return NONE;

        //API::get()->log_warn("Montage: %s", in_montage->GetName().c_str());

        for (MontageMeta montage : g_montages) {
            auto montage_name = in_montage->GetName();
            if (montage_name == std::get<0>(montage)) {
                auto type = std::get<1>(montage);
                //API::get()->log_warn("Montage Found, type: %d", type);
                return type;
            }
        }

        return UNKNOWN;
    }

    void handle_animations(const UEVR_VRData* vr) {
        if (m_pawn_state.matches_any({ PAWN_HACKERIMPLANT })) {
            // start of bootup
            if (m_is_booting_up.has_changed() && m_is_booting_up.value) {
                //API::get()->log_warn("Bootup Start");
                vr->set_aim_method(0);
                vr->recenter_view();
                API::UObjectHook::set_disabled(true);
            }

            // start of crash
            if (m_is_crashing.has_changed() && m_is_crashing.value) {
                //API::get()->log_warn("Crash Start");
                vr->set_aim_method(0);
                vr->recenter_view();
                API::UObjectHook::set_disabled(true);
            }

            if (m_is_booting_up.value || m_is_crashing.value) {
                vr->set_aim_method(0);
                vr->set_mod_value("VR_RoomscaleMovement", "false");
                vr->set_decoupled_pitch_enabled(true);
                API::UObjectHook::set_disabled(true);
            }

            if (m_current_montage.has_changed()) {
                //API::get()->log_warn("Montage Changed %s", m_current_montage.value ? "STARTED" : "ENDED");
                // get metadata about current montage from g_montages vector
                m_montage_type.set_value(get_montage_type(m_current_montage.value));

                // check the type of animation that had just ended
                if (m_montage_type.prev_value == ENDING || m_montage_type.prev_value == SINGLE) {
                    // rotate pawn to match animation rotation
                    static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->PlayerCamera->bUsePawnControlRotation = true;
                    auto pawn_controller = static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->GetController();
                    pawn_controller->SetControlRotation(m_camera_rotation);
                    //API::get()->log_info("Montage End : Setting rotation (%f, %f, %f)", m_camera_rotation.Pitch, m_camera_rotation.Roll, m_camera_rotation.Yaw);
                    //API::get()->log_warn("Montage Type: Ending / Single");
                    m_sdk_hud->SetForceHideCrosshairs(false);
                    m_sdk_hud->ShowTargetBrackets(true);
                    apply_selected_crosshair_options();
                    vr->set_aim_method(2);
                    vr->set_mod_value("VR_RoomscaleMovement", "true");
                    API::UObjectHook::set_disabled(false);
                }

                // single animation or animation sequence is starting
                if (m_montage_type.value == STARTING || m_montage_type.value == SINGLE) {

                    static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->PlayerCamera->bUsePawnControlRotation = false;

                    //API::get()->log_warn("Montage Type: Starting / Single | %s", m_current_montage.value->GetName().c_str());
                    m_sdk_hud->SetForceHideCrosshairs(true);
                    m_sdk_hud->ShowTargetBrackets(false);
                    vr->set_aim_method(0);
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_decoupled_pitch_enabled(true);
                    API::UObjectHook::set_disabled(true);
                }
            }
        }
    }

    void handle_player_height(const UEVR_VRData* vr) {
        if (m_pawn_state.matches_none({ PAWN_HACKERIMPLANT, PAWN_HACKERSIMPLE })) {
            return;
        }

        // reset player height when standing up
        if (m_player_crouching.has_changed() && !m_player_crouching.value) {
            reset_height(vr);
        }

        auto arms_mesh_data = m_pawn->get_property_data<SceneComponent*>(L"ArmsMesh");
        auto arms_mesh = arms_mesh_data != nullptr ? *arms_mesh_data : nullptr;
        if (arms_mesh == nullptr) {
            return;
        }
        auto state = API::UObjectHook::get_or_add_motion_controller_state(arms_mesh);
        if (state == nullptr) {
            return;
        }
        const auto move_control_manager_data = m_pawn->get_property_data<API::UObject*>(L"COMP_MoveControlManager");
        const auto move_control_manager = move_control_manager_data != nullptr ? *move_control_manager_data : nullptr;
        if (move_control_manager != nullptr) {
            float* crouch_progres = move_control_manager->get_property_data<float>(L"CrouchProgress");
            // offset weapon Z pos
            UEVR_Vector3f offset{ 34.0f, (139.0f - ((66.5f + m_ui_option_player_height_modifier) * (*crouch_progres))) + m_ui_option_player_height_modifier, 7.35f };
            state->set_location_offset(&offset);

            // apply player height modifier (take into account crouch progress)
            SDK::FVector look_pivot_offset{ 0.f, 0.f, m_ui_option_player_height_modifier * (1 - *crouch_progres) };
            static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->LookPivot->K2_SetRelativeLocation(look_pivot_offset, false, &m_hit_result, false);
        }
        else {
            // this is ArmsMesh component offset
            UEVR_Vector3f offset{ 34.0f, 139.0f + m_ui_option_player_height_modifier, 7.35f };
            state->set_location_offset(&offset);
        }
    }


    // handle cursor size changes when interacting with puzzles / vending machines / etc.
    void handle_interactives_cursor_size() {
        if (m_player_interacting.has_changed() && !m_mfd_visible.value) {
            if (m_player_interacting.value) {
                float scale{ 0.5f };
                m_vr_hud->set_crosshair_cursor_scale(&scale);
            }
            else {
                m_vr_hud->set_crosshair_cursor_scale(&m_ui_option_crosshair_cursor_scale);
            }
        }
    }

    void handle_in_game_menu(const UEVR_VRData* vr) {
        if (m_mod_events.contains(MOD_EVENT_SHOW_IN_GAME_MENU)) {
            // when HMD view is centered change to GAME input
            vr->set_mod_value("VR_RoomscaleMovement", "false");
            vr->set_mod_value("UI_Distance", "2.000000");
            vr->set_mod_value("UI_Size", "1.500000");
            vr->set_aim_method(0);
            vr->set_snap_turn_enabled(false); // disable rotation when in menu
            m_mod_events.extract(MOD_EVENT_SHOW_IN_GAME_MENU);
        }

        if (m_main_menu_in_game_visible.has_changed()) {
            if (m_main_menu_in_game_visible.value) {
                vr->set_mod_value("VR_DecoupledPitchUIAdjust", "false");
                // first center view to HMD
                vr->set_aim_method(1);
                m_mod_events.insert(MOD_EVENT_SHOW_IN_GAME_MENU);
            }
            else {
                vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                if (m_pawn_state.matches_any({ PAWN_HACKERIMPLANT, PAWN_HACKERSIMPLE })) {
                    vr->set_mod_value("VR_RoomscaleMovement", "true");
                    vr->set_aim_method(2);

                    char snap_angle[16] = { 0 };
                    vr->get_mod_value("VR_SnapturnTurnAngle", snap_angle, sizeof(snap_angle));
                    int snap_angle_int = atoi(snap_angle);

                    if (snap_angle_int != 359) {
                        vr->set_snap_turn_enabled(true); // reenable rotation when exiting menu
                    }
                }
                else if (m_pawn_state.value == PAWN_AVATAR) {
                    vr->set_mod_value("UI_Distance", "10.000000");
                    vr->set_mod_value("UI_Size", "10.000000");
                }
            }
        }
    }

    // force hides compass when associated option is enabled
    void handle_compass() {
        if (m_ui_option_force_hide_compass) {
            if (m_pawn_state.value == PAWN_HACKERIMPLANT && m_sdk_hud != nullptr && m_sdk_hud->WIDGET_Compass != nullptr) {
                m_sdk_hud->WIDGET_Compass->SetCompassVisibility(false);
            }
        }
    }

    // -------------------------------------------------------------------------------------
    // MFD
    // -------------------------------------------------------------------------------------
    void handle_mfd_interactions(XINPUT_STATE* state, const UEVR_VRData* vr) {
        if (m_vr_hud != nullptr && m_vr_hud->get_hud_state() == VR_HUD_SUCCESS) {
            auto ctrl = (SDK::ACON_Hacker_C*)m_sdk_pawn->Controller;
            ctrl->SetIsUsingGamepad(false);

            // mute controller A, Y buttons, we'll use them for LMB, RMB
            m_gamepad_btn_a.mute_state(state);
            m_gamepad_btn_y.mute_state(state);

            // mute sticks that move cursor
            state->Gamepad.sThumbRX = 0;
            state->Gamepad.sThumbRY = 0;

            if (m_gamepad_btn_a.has_changed()) {
                send_mouse(VK_LBUTTON, !m_gamepad_btn_a.value);
            }

            if (m_gamepad_btn_y.has_changed()) {
                send_mouse(VK_RBUTTON, !m_gamepad_btn_y.value);
            }
            ctrl->SetIsUsingGamepad(false);

            auto pos = m_vr_hud->get_2D_hit_position();
            if (pos.X != 0 && pos.Y != 0) {
                ctrl->SetMouseLocation(pos.X, pos.Y);
            }

            m_vr_hud->update_laser_pointer_length(100.f);
        }
    }

    void handle_mfd_changes(const UEVR_VRData* vr) {
        if (m_mod_events.contains(MOD_EVENT_SHOW_MFD)) {

            // prepare correct ui distance and size
            SDK::APlayerController* ctrl = SDK::UGameplayStatics::GetPlayerController(m_sdk_world, 0);
            ctrl->GetViewportSize(&m_viewport_size_x, &m_viewport_size_y);

            // get uevr world scale
            char world_scale_option[16] = { 1.0 };
            vr->get_mod_value("VR_WorldScale", world_scale_option, sizeof(world_scale_option));
            float world_scale{ 1.f };
            try {
                size_t read = 0;
                world_scale = std::stof(world_scale_option, &read);
            } catch (std::invalid_argument) {
                API::get()->log_info("Handle MFD Changes :: Error converting UEVR world scale value to float");
            }

            char ui_distance[32];
            char ui_size[32];
            int ret_ui_distance = snprintf(ui_distance, sizeof ui_distance, "%f", (1.f / world_scale) * ((m_vr_hud->get_mfd_depth() / 100.f)) );
            int ret_ui_size = snprintf(ui_size, sizeof ui_size, "%f", (float)( (1.f / world_scale) * (m_viewport_size_y / 1000.f) ) );
            if (ret_ui_distance < 0 || ret_ui_size < 0) {
                return;
            }

            // set surrounding objects to ignore our trace channel
            //m_vr_hud->disable_conflicting_collisions();

            // move MFD panel a little up
            m_vr_hud->align_mfd_panel();

            // reset mask size in case the game resolution changed
            m_vr_hud->set_mfd_mask_size(m_viewport_size_x, m_viewport_size_y);
            m_vr_hud->set_mfd_mask_delta();
            m_vr_hud->set_laser_pointer_visibility(true);
            m_vr_hud->set_mfd_mask_visibility(true);
            m_vr_hud->set_mfd_hotbar_visibility(true);
            m_vr_hud->set_player_response_to_collision_channel(
                item_selector_collision_channel, SDK::ECollisionResponse::ECR_Ignore
            );

            vr->set_mod_value("VR_RoomscaleMovement", "false");
            vr->set_mod_value("UI_Distance", ui_distance);
            vr->set_mod_value("UI_Size", ui_size);
            vr->set_aim_method(0);
            m_mod_events.extract(MOD_EVENT_SHOW_MFD);
        }

        if (m_mfd_visible.has_changed()) {
            if (m_mfd_visible.value) {
                // without reseting height, the cursor would not be aligned correctly
                reset_height(vr);
                // hide HUD and change aiming mode to head to get it in the right position
                // next tick we'll show it again with along with mfd mask
                vr->set_mod_value("UI_Size", "0.000000");
                vr->set_mod_value("UI_Y_Offset", "0.000000");
                vr->set_mod_value("VR_RoomscaleMovement", "false");
                vr->set_aim_method(1);

                // need to set scale to 1, otherwise picked up objects will be to small
                float scale{ 1.f };
                m_vr_hud->set_crosshair_cursor_scale(&scale);

                m_mod_events.insert(MOD_EVENT_SHOW_MFD);
            }
            else {
                vr->set_aim_method(2);
                vr->set_mod_value("VR_RoomscaleMovement", "true");
                vr->set_mod_value("UI_Y_Offset", "0.010000");
                m_vr_hud->set_laser_pointer_visibility(false);
                m_vr_hud->set_mfd_mask_visibility(false);
                m_vr_hud->set_mfd_hotbar_visibility(false);
                m_vr_hud->set_player_response_to_collision_channel(
                    item_selector_collision_channel, SDK::ECollisionResponse::ECR_Block
                );
                m_vr_hud->set_crosshair_cursor_scale(&m_ui_option_crosshair_cursor_scale);
            }
        }
    }

    // matches LookPivot pitch with Controller's pitch, compensates by setting AnimCameraPosition rotation
    // (compensation is needed because we attached RController to ArmsMesh - was tricky to solve)
    void handle_look_pivot() {
        if (m_pawn_state.matches_none({ PAWN_HACKERSIMPLE, PAWN_HACKERIMPLANT })) {
            return;
        }

        auto pawn_controller = m_sdk_pawn->Controller;
        if (pawn_controller != nullptr) {
            auto look_pivot_ptr = m_pawn->get_property_data<SceneComponent*>(L"LookPivot");
            auto look_pivot = look_pivot_ptr != nullptr ? *look_pivot_ptr : nullptr;

            auto anim_camera_position_ptr = m_pawn->get_property_data<SceneComponent*>(L"AnimCameraPosition");
            auto anim_camera_position = anim_camera_position_ptr != nullptr ? *anim_camera_position_ptr : nullptr;

            if (look_pivot != nullptr && anim_camera_position != nullptr) {
                SDK::FRotator controller_rotation = pawn_controller->GetControlRotation();

                SDK::FRotator look_pivot_rot = { controller_rotation.Pitch, 0.0f, 0.0f };
                SDK::FRotator anim_camera_position_rot = { -controller_rotation.Pitch, 94.700f, 0.0f };
                    
                look_pivot->K2_set_relative_rotation(look_pivot_rot);
                anim_camera_position->K2_set_relative_rotation(anim_camera_position_rot);
            }
        }
    }

    void handle_cyberspace_look_pivot(const UEVR_VRData* vr) {
        return;

        if (m_pawn_state.matches_none({ PAWN_AVATAR })) {
            return;
        }

        auto pawn_controller = m_sdk_pawn->Controller;
        if (pawn_controller != nullptr) {

        	UEVR_Vector3f right_hand_position{};
        	UEVR_Quaternionf rh_rot{};
        	vr->get_aim_pose(vr->get_right_controller_index(), (UEVR_Vector3f*)&right_hand_position, (UEVR_Quaternionf*)&rh_rot);

            SDK::FQuat quat{ rh_rot.x, rh_rot.y, rh_rot.z, rh_rot.w };
            auto vect = SDK::UKismetMathLibrary::Quat_Euler(quat);
            auto rot = SDK::UKismetMathLibrary::Quat_Rotator(quat);

            pawn_controller->SetControlRotation(SDK::FRotator(rot));
        }
    }

    void handle_hud_depth(const UEVR_VRData* vr) {
        if (m_skip_hud_depth) {
            m_skip_hud_depth = false;
            return;
        }

        if (m_mfd_visible.value || m_main_menu_in_game_visible.value || m_hotbar_selector_button.value || m_hardware_selector_button.value) {
            return;
        }

        const auto scanner_ptr = m_pawn->get_property_data<API::UObject*>(L"COMP_Scanner");
        const auto scanner = scanner_ptr != nullptr ? *scanner_ptr : nullptr;
        if (scanner != nullptr) {
            float cursor_distance = scanner->get_property<float>(L"LastCursorHitDistance");
            // just some exponential function I created to get better value for UEVR ui_distance property
            float distance = cursor_distance / (
                (std::powf((1.0f / 10.0f), ((cursor_distance / 150.0f) - 1.3f)) * 0.7f) + 80.0f + (m_ui_option_crosshair_depth * 3.0f)
            );
            distance = (distance == 0) ? 10.0f : std::fmax(distance, 0.5f);

            char ui_distance[32];
            char ui_size[32];
            int ret_ui_distance = snprintf(ui_distance, sizeof ui_distance, "%f", distance);
            int ret_ui_size = snprintf(ui_size, sizeof ui_size, "%f", distance);
            if (ret_ui_distance < 0 || ret_ui_size < 0) {
                return;
            }
            vr->set_mod_value("UI_Distance", ui_distance);
            vr->set_mod_value("UI_Size", ui_size);
        }
    }

    void handle_smooth_turning(XINPUT_STATE* state, const UEVR_VRData* vr) {
        if (m_pawn_state.matches_none({ PAWN_HACKERSIMPLE, PAWN_HACKERIMPLANT, PAWN_AVATAR })) {
            return;
        }

        char snap_angle[16] = { 0 };
        vr->get_mod_value("VR_SnapturnTurnAngle", snap_angle, sizeof(snap_angle));
        int snap_angle_int = atoi(snap_angle);

        // verify if smooth turning conditions have been met
        if ( snap_angle_int == 359 ) {
            vr->set_snap_turn_enabled(false);
            auto pawn_controller = m_sdk_pawn->Controller;
            if (pawn_controller == nullptr) {
                return;
            }

            auto control_rotation = pawn_controller->GetControlRotation();
            control_rotation.Yaw += (state->Gamepad.sThumbRX / ((11.f - m_ui_option_look_sensitivity) * 2499.0f));

            if (m_pawn_state.value == PAWN_AVATAR && m_cyberspace_aim_method == 0 && m_ui_option_openxr_runtime == WMR) {
                control_rotation.Pitch += (state->Gamepad.sThumbRY / ((11.f - m_ui_option_look_sensitivity) * 2499.0f));
            }

            if (!m_main_menu_in_game_visible.value) {
                pawn_controller->SetControlRotation(control_rotation); // disable rotation when in menu
            }
        }
    }

    void handle_pawn_changes(const UEVR_VRData* vr) {
        // handle Pawn state changes
        if (m_pawn_state.has_changed()) {
            switch (m_pawn_state.value) {
                // title screen or cutscene
                case PAWN_PLAYERGHOST:
                    API::get()->log_warn("Changed Pawn to: PAWN_PLAYERGHOST");
                    vr->set_aim_method(0);
                    vr->set_snap_turn_enabled(true);
                    vr->set_decoupled_pitch_enabled(true);
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("UI_Distance", "2.000000");
                    vr->set_mod_value("UI_Size", "2.000000");
                    vr->recenter_view();
                    
                    API::UObjectHook::set_disabled(true);
                    reset_height(vr);
                    break;

                // animation
                case PAWN_HACKERSIMPLE:
                    API::get()->log_warn("Changed Pawn to: PAWN_HACKERSIMPLE");
                    vr->set_aim_method(2);
                    vr->set_snap_turn_enabled(true);
                    vr->set_decoupled_pitch_enabled(true);
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                    vr->recenter_view();
                    
                    API::UObjectHook::set_disabled(false);
                    reset_height(vr);
                    static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->PlayerCamera->bUsePawnControlRotation = true;
                    break;

                // main game
                case PAWN_HACKERIMPLANT:
                    API::get()->log_warn("Changed Pawn to: PAWN_HACKERIMPLANT");
                    if (m_pawn != nullptr) {
                        m_pawn->set_bool_property(L"bUseControllerRotationPitch", false);
                        m_pawn->set_bool_property(L"bUseControllerRotationRoll", false);
                        m_pawn->set_bool_property(L"bUseControllerRotationYaw", false);
                    }
                    apply_selected_crosshair_options();

                    vr->set_aim_method(2);
                    vr->set_snap_turn_enabled(true);
                    vr->set_decoupled_pitch_enabled(true);
                    vr->set_mod_value("VR_RoomscaleMovement", "true");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                    vr->recenter_view();

                    // remove dashboards (dashboards are reset after exiting cyberspace?)
                    m_mod_events.insert(MOD_EVENT_VR_HUD_HIDE_DASHBOARDS);

                    API::UObjectHook::set_disabled(false);
                    reset_height(vr);
                    static_cast<SDK::APAWN_Hacker_Simple_C*>(m_sdk_pawn)->PlayerCamera->bUsePawnControlRotation = true;
                    break;

                // cyberspace
                case PAWN_AVATAR:
                    API::get()->log_warn("Changed Pawn to: PAWN_AVATAR");

                    if (m_pawn != nullptr) {
                        m_pawn->set_bool_property(L"bUseControllerRotationPitch", true);
                        m_pawn->set_bool_property(L"bUseControllerRotationRoll", true);
                        m_pawn->set_bool_property(L"bUseControllerRotationYaw", true);
                    }
                    
                    m_cyberspace_aim_method = 2;
                    vr->set_aim_method(2);
                    vr->set_snap_turn_enabled(false);
                    vr->set_decoupled_pitch_enabled(true);
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                    vr->recenter_view();
                    
                    API::UObjectHook::set_disabled(true);
                    reset_height(vr);
                    break;

                default:
                    break;
            }
        }
    }

    void handle_lean() {
        if (m_pawn_state.matches_any({ PAWN_HACKERSIMPLE, PAWN_HACKERIMPLANT })) {
            // prevent player leaning
            m_pawn->set_bool_property(L"IsTryingToLean", false);
        }
    }

    void handle_media_display() {
        if (m_pawn_state.value == PAWN_HACKERIMPLANT && m_vr_hud != nullptr && m_is_media_display_visible.has_changed()) {
            m_vr_hud->set_minimap_visibility(!m_is_media_display_visible.value);
            m_vr_hud->set_media_display_visibility(m_is_media_display_visible.value);
        }
    }

    void reset_height(const UEVR_VRData* vr, float offset_y = 0.0f) {
        UEVR_Vector3f origin{};
        vr->get_standing_origin(&origin);

        UEVR_Vector3f hmd_pos{};
        UEVR_Quaternionf hmd_rot{};
        vr->get_pose(vr->get_hmd_index(), &hmd_pos, &hmd_rot);

        origin.y = (hmd_pos.y) + offset_y;

        vr->set_standing_origin(&origin);
    }

    void apply_vr_game_options() {
        auto class_ptr = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Blueprints/UI/HUD/Widgets/Settings/SAVE_Settings.SAVE_Settings_C");
        if (class_ptr != nullptr) {
            SDK::USAVE_Settings_C* settings = class_ptr->get_first_object_matching<SDK::USAVE_Settings_C>();

            if (settings != nullptr && settings->IsA(SDK::USAVE_Settings_C::StaticClass())) {
                // Accessibility: Headbob Amount: OFF
                settings->SetHeadbobAmount(SDK::ENUM_OffReducedNormal::NewEnumerator0);
                settings->ApplyHeadbobAmount(SDK::ENUM_OffReducedNormal::NewEnumerator0);

                // Accessibility: Hotbar Style: NORMAL
                settings->SetHotbarStyle(SDK::ENUM_HotbarStyle::NewEnumerator0);
                settings->ApplyHotbarStyle(SDK::ENUM_HotbarStyle::NewEnumerator0);

                // Accessibility: HUD Curve Amount: 0.0
                // This is important for the HotbarSlots to be properly placed on the MFD after creating VR HUD
                settings->SetHUDCurvature(0.0f);
                settings->ApplyHUDCurvature(0.0f);

                // Controls: Toggle Crouch: ON
                settings->SetCrouchToggle(true);
                settings->ApplyCrouchToggle(true);

                // Controls: Toggle Aim Down Sights: OFF
                settings->SetFocusAimToggle(false);
                settings->ApplyFocusAimToggle(false);

                // Gameplay: Focus Camera On Puzzles: OFF
                settings->SetFocusOnPuzzles(false);
                settings->ApplyFocusOnPuzzles(false);

                // Gameplay: Reload Can Use Batteries: OFF
                settings->SetReloadCanUseBatteries(false);
                settings->ApplyReloadCanUseBatteries(false);

                // Display: Motion Blur: OFF
                settings->SetEnableMotionBlur(false);
                settings->ApplyEnableMotionBlur(false);

                // Display: V-Sync: OFF
                settings->SetEnableVSync(false);
                settings->ApplyEnableVSync(false);

                // Display: FOV (real/cyberspace)
                settings->SetFOV(m_fov, true);
                settings->ApplyFOV(m_fov, true);
                settings->SetFOV(m_fov, false);
                settings->ApplyFOV(m_fov, false);

                API::get()->log_info("Applied VR specific game options");
            }
            else {
                API::get()->log_error("Could not apply VR specific game options");
            }
        }
        else {
            API::get()->log_error("Could not apply VR specific game options : missing class");
        }
    }

    void apply_selected_crosshair_options() {
        if (m_vr_hud != nullptr && m_vr_hud->get_hud_state() == VRHackerHUDState::VR_HUD_SUCCESS) {
            m_vr_hud->set_crosshair_cursor_scale(&m_ui_option_crosshair_cursor_scale);
            m_vr_hud->set_cursor_brackets_scale(&m_ui_option_crosshair_brackets_scale);
            m_vr_hud->set_target_id_reticle_scale(&m_ui_option_target_id_reticle_scale);
        }
    }

    // unused
    void apply_button_mappings() {
        switch (m_ui_option_hotbar_selector_button) {
            case 0:
                m_hotbar_selector_button.set_source(XINPUT_GAMEPAD_RIGHT_SHOULDER);
                break;
            case 1:
                m_hotbar_selector_button.set_source(XINPUT_GAMEPAD_RIGHT_THUMB);
                break;
            case 2:
                m_hotbar_selector_button.set_source(XINPUT_GAMEPAD_LEFT_SHOULDER);
                break;
            case 3:
                m_hotbar_selector_button.set_source(XINPUT_GAMEPAD_LEFT_THUMB);
                break;
        }

        switch (m_ui_option_hardware_selector_button) {
            case 0:
                m_hardware_selector_button.set_source(XINPUT_GAMEPAD_RIGHT_SHOULDER);
                break;
            case 1:
                m_hardware_selector_button.set_source(XINPUT_GAMEPAD_RIGHT_THUMB);
                break;
            case 2:
                m_hardware_selector_button.set_source(XINPUT_GAMEPAD_LEFT_SHOULDER);
                break;
            case 3:
                m_hardware_selector_button.set_source(XINPUT_GAMEPAD_LEFT_THUMB);
                break;
        }
    }

    // -------------------------------------------------------------------------------------
    // ImGui logging
    // -------------------------------------------------------------------------------------
    void internal_frame() {
        if (!API::get()->param()->functions->is_drawing_ui()) {
            return;
        }

        static const auto UEVR_NAME = std::format("SystemReShock UEVR mod [rev. {}]", MOD_VERSION);
        static const auto NO_PAWN = std::format("No Pawn detected! Is your HMD running?");
        static const char* LOOK_SENSITIVITY = "Look Sensitivity";
        static const char* SHOW_DEBUG = "Show Debug View";
        static const char* CURRENT_PAWN_STATE = "Current Pawn State";
        static const char* APPLY_WEAPON_OFFSET_WEAPON = "Apply Weapon Offset";
        static const char* CURRENT_WEAPON = "Current Weapon";

        constexpr auto window_w = 500.0f;
        constexpr auto window_h = 500.0f;

        if (m_pawn == nullptr) {
            ImGui::SetNextWindowSize(ImVec2(window_w, window_h), ImGuiCond_::ImGuiCond_Once);
            if (ImGui::Begin(UEVR_NAME.c_str())) {
                ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), NO_PAWN.c_str());
            }
            ImGui::End();
            return;
        }

        ImGui::SetNextWindowSize(ImVec2(window_w, window_h), ImGuiCond_::ImGuiCond_Once);
        if (ImGui::Begin(UEVR_NAME.c_str())) {
            ImGui::PushItemWidth(200);
            if (ImGui::Button("Save Configuration")) {
                if (save_plugin_config()) {
                    ImGui::OpenPopup("succesful_save_popup");
                };
            };

            if (ImGui::BeginPopup("succesful_save_popup"))
            {
                ImGui::Text("Configuration Saved!");
                ImGui::EndPopup();
            }

            ImGui::SeparatorText("General options");
            ImGui::SliderInt(LOOK_SENSITIVITY, &m_ui_option_look_sensitivity, 1, 10);
            ImGui::SliderFloat("Player height modifier", &m_ui_option_player_height_modifier, -15.f, 15.f);
            ImGui::Checkbox("Force hide compass", &m_ui_option_force_hide_compass);
            ImGui::Checkbox("Toggle run with left grip", &m_ui_option_toggle_run_with_left_grip);
            ImGui::Checkbox("Disable roomscale when aiming", &m_ui_option_disable_roomscale_when_aiming);
            
            ImGui::Combo("HMD", &m_ui_option_openxr_runtime, "Meta Quest\0HP Reverb G2\0");
            
            //ImGui::SeparatorText("Button mappings");
            //ImGui::Combo("Hotbar selector button", &m_ui_option_hotbar_selector_button, "RGrip\0RS\0LGrip\0LS\0\0");
            //ImGui::Combo("Hardware selector button", &m_ui_option_hardware_selector_button, "RGrip\0RS\0LGrip\0LS\0\0");

            //if (m_ui_option_hotbar_selector_button == m_ui_option_hardware_selector_button) {
            //    ImGui::BeginDisabled();
            //}
            //if (ImGui::Button("Apply Mappings")) {
            //    apply_button_mappings();
            //};
            //if (m_ui_option_hotbar_selector_button == m_ui_option_hardware_selector_button) {
            //    ImGui::EndDisabled();
            //}

            ImGui::SeparatorText("Crosshair options");
            ImGui::SliderInt("Crosshair Depth", &m_ui_option_crosshair_depth, 0, 10);
            ImGui::SliderFloat("Crosshair Cursor Scale", &m_ui_option_crosshair_cursor_scale, 0.f, 1.f );
            ImGui::SliderFloat("Crosshair Brackets Scale", &m_ui_option_crosshair_brackets_scale, 0.f, 1.f);
            ImGui::SliderFloat("TargetID Reticle Scale", &m_ui_option_target_id_reticle_scale, 0.f, 1.f);
            if (ImGui::Button("Apply Crosshair Options")) {
                apply_selected_crosshair_options();
            };
            ImGui::PopItemWidth();

            ImGui::SeparatorText("Debugging");
            // game state section
            ImGui::Checkbox(SHOW_DEBUG, &m_ui_option_show_debug_view);

            ImGui::BeginGroup();
            ImGui::BeginDisabled();
            if (m_ui_option_show_debug_view) {
                if (m_vr_hud != nullptr && m_vr_hud->get_hud_state() == VR_HUD_SUCCESS) {
                    auto pos = m_vr_hud->get_2D_hit_position();
                    float poss[2] = { pos.X, pos.Y };
                    ImGui::DragFloat2("POS", poss);
                }
                
                ImGui::InputText("Current Montage", (m_current_montage.value != nullptr) ? (char*)m_current_montage.value->GetName().c_str() : (char*)"NONE", 20);
                ImGui::InputText("Current Action", (m_current_action != nullptr) ? (char*)m_current_action->GetName().c_str() : (char*)"NONE", 20);
                ImGui::InputText("Current Interactable", !m_channeling_interactable_name.value.empty() ? (char*)m_channeling_interactable_name.value.c_str() : (char*)"NONE", 20);

                ImGui::InputText(CURRENT_PAWN_STATE, (char*)PawnStateNames[m_pawn_state.value], 20);
                if (m_vr_hud != nullptr) {
                    ImGui::InputText("VR HUD Status", (char*)VRHackerHUDStateNames[m_vr_hud->get_hud_state()], 20);
                    ImGui::InputText("VR HUD Last Error", (char*)m_vr_hud->get_hud_error().c_str(), 20);
                }
                ImGui::EndDisabled();

                ImGui::Checkbox(APPLY_WEAPON_OFFSET_WEAPON, &m_ui_option_apply_weapon_offset);

                ImGui::BeginDisabled();
                if (m_current_weapon != nullptr) {
                    auto weapon_name = m_current_weapon->GetName();
                    ImGui::InputText(CURRENT_WEAPON, (char*)weapon_name.c_str(), 20);
                }
                else {
                    ImGui::InputText(CURRENT_WEAPON, (char*)"NONE", 20);
                }

                // show weapon offset
                auto weapon_offset = m_pawn->get_property_data<SDK::FVector>(L"CurrentWeaponOffset");
                if (weapon_offset != nullptr) {
                    float vec_arr[3] = { weapon_offset->X, weapon_offset->Y, weapon_offset->Z };
                    ImGui::DragFloat3("Weapon Offset", vec_arr);
                }

                //const UEVR_VRData* vr = API::get()->param()->vr;
                //if (vr != nullptr) {
                //    UEVR_Vector3f origin{};
                //    vr->get_standing_origin(&origin);
                //    float vec_arr[3] = { origin.x, origin.y, origin.z };
                //    ImGui::DragFloat3("Standing Origin", vec_arr);

                //    UEVR_Vector3f hmd_pos{};
                //    UEVR_Quaternionf hmd_rot{};
                //    vr->get_pose(vr->get_hmd_index(), &hmd_pos, &hmd_rot);

                //    float hmd_pos_arr[3] = { hmd_pos.x, hmd_pos.y, hmd_pos.z };
                //    ImGui::DragFloat3("HMD Position", hmd_pos_arr);
                //    float quat_arr[4] = { hmd_rot.w, hmd_rot.x, hmd_rot.y, hmd_rot.z };
                //    ImGui::DragFloat4("HMD Rotation", quat_arr);
                //}

                ImGui::Checkbox("Player alive", &m_player_alive.value);
                ImGui::Checkbox("Is using laptop", &m_is_using_laptop.value);
                ImGui::Checkbox("MFD visible", &m_mfd_visible.value);
                ImGui::Checkbox("Player crouching", &m_player_crouching.value);
                ImGui::Checkbox("Player interacting", &m_player_interacting.value);
                ImGui::Checkbox("Player sprinting", &m_player_sprinting);
                ImGui::Checkbox("Hacker bootup", &m_is_booting_up.value);
                ImGui::Checkbox("Hacker crash", &m_is_crashing.value);
                ImGui::Checkbox("Main Menu visible", &m_main_menu_in_game_visible.value);
                

                ImGui::PushItemWidth(100);
                ImGui::InputInt("XInput cb duration [microseconds]", &m_ui_xinput_duration);
                ImGui::InputInt("Pre Engine Tick cb duration [microseconds]", &m_ui_pre_engine_tick_duration);
                ImGui::PopItemWidth();
            }
            ImGui::EndDisabled();
            ImGui::EndGroup();
        }
        ImGui::End();
    }

    bool on_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) override {
        ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);

        return !ImGui::GetIO().WantCaptureMouse && !ImGui::GetIO().WantCaptureKeyboard;
    }

    void on_device_reset() override {
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

    void on_post_render_vr_framework_dx11(ID3D11DeviceContext* context, ID3D11Texture2D* texture, ID3D11RenderTargetView* rtv) override {
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

    void on_post_render_vr_framework_dx12(ID3D12GraphicsCommandList* command_list, ID3D12Resource* rt, D3D12_CPU_DESCRIPTOR_HANDLE* rtv) override {
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

    bool initialize_imgui() {
        if (m_imgui_initialized) {
            return true;
        }

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        static const auto imgui_ini = API::get()->get_persistent_dir(L"system_reshock_vr_imgui.ini").string();
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

    void on_present() override {
        //std::scoped_lock _{ m_imgui_mutex };

        if (!m_imgui_initialized) {
            API::get()->log_info("imgui not initialized");
            if (!initialize_imgui()) {
                API::get()->log_info("Failed to initialize imgui");
                return;
            }
            else {
                API::get()->log_info("Initialized imgui");
            }
        }

        const auto renderer_data = API::get()->param()->renderer;

        if (renderer_data->renderer_type == UEVR_RENDERER_D3D11) {
            ImGui_ImplDX11_NewFrame();
            ImGui_ImplWin32_NewFrame();
            ImGui::NewFrame();

            internal_frame();

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

            internal_frame();

            ImGui::EndFrame();
            ImGui::Render();

            g_d3d12.render_imgui();
        }
    }

    // sends mouse inputs to OS (thanks markmon)
    void send_mouse(WORD key, bool key_up) {
        INPUT input;
        ZeroMemory(&input, sizeof(INPUT));
        input.type = INPUT_MOUSE;

        // Handle mouse button events
        if (key == VK_LBUTTON) {
            input.mi.dwFlags = (key_up ? MOUSEEVENTF_LEFTUP : MOUSEEVENTF_LEFTDOWN);
        }
        else if (key == VK_RBUTTON) {
            input.mi.dwFlags = (key_up ? MOUSEEVENTF_RIGHTUP : MOUSEEVENTF_RIGHTDOWN);
        }
        else if (key == VK_MBUTTON) {
            input.mi.dwFlags = (key_up ? MOUSEEVENTF_MIDDLEUP : MOUSEEVENTF_MIDDLEDOWN);
        }
        else if (key == VK_XBUTTON1) {
            input.mi.dwFlags = (key_up ? MOUSEEVENTF_XUP : MOUSEEVENTF_XDOWN);
            input.mi.mouseData = XBUTTON1;
        }
        else if (key == VK_XBUTTON2) {
            input.mi.dwFlags = (key_up ? MOUSEEVENTF_XUP : MOUSEEVENTF_XDOWN);
            input.mi.mouseData = XBUTTON2;
        }
        // Handle mouse wheel events
        else if (key == 0x0A) { // Wheel up
            input.mi.dwFlags = MOUSEEVENTF_WHEEL;
            input.mi.mouseData = WHEEL_DELTA; // Positive for wheel up
        }
        else if (key == 0x0B) { // Wheel down
            input.mi.dwFlags = MOUSEEVENTF_WHEEL;
            input.mi.mouseData = -WHEEL_DELTA; // Negative for wheel down
        }

        SendInput(1, &input, sizeof(INPUT));
    }

    bool load_plugin_config() {
        static const auto config_filename = API::get()->get_persistent_dir(L"system_reshock_vr_config.ini").string();
        mINI::INIFile mod_config_file(config_filename);
        mINI::INIStructure mod_config;

        if (!mod_config_file.read(mod_config)) {
            API::get()->log_error("[Mod Config] Missing config file. Creating config with default values");
            save_plugin_config();
            return false;
        }

        // section validation
        if (!mod_config.has("general") || !mod_config.has("crosshair")) {
            API::get()->log_error("[Mod Config] Missing config section");
            return false;
        }

        // look_sensitivity
        if (mod_config["general"].has("look_sensitivity")) {
            std::string& look_sensitivity = mod_config["general"]["look_sensitivity"];
            try {
                m_ui_option_look_sensitivity = std::stoi(look_sensitivity);
            }
            catch (...) {
                API::get()->log_error("[Mod Config] Invalid general > look_sensitivity value.");
            }
        }
        else {
            API::get()->log_error("[Mod Config] Missing general > look_sensitivity value.");
        }

        // player_height_modifier
        if (mod_config["general"].has("player_height_modifier")) {
            std::string& player_height_modifier = mod_config["general"]["player_height_modifier"];
            try {
                m_ui_option_player_height_modifier = std::stof(player_height_modifier);
            }
            catch (...) {
                API::get()->log_error("[Mod Config] Invalid general > player_height_modifier value.");
            }
        }
        else {
            API::get()->log_error("[Mod Config] Missing general > player_height_modifier value.");
        }

        // force_hide_compass
        if (mod_config["general"].has("force_hide_compass")) {
            std::string& force_hide_compass = mod_config["general"]["force_hide_compass"];
            try {
                m_ui_option_force_hide_compass = std::stoi(force_hide_compass) == 1;
            }
            catch (...) {
                API::get()->log_error("[Mod Config] Invalid general > force_hide_compass value.");
            }
        }
        else {
            API::get()->log_error("[Mod Config] Missing general > force_hide_compass value.");
        }

        // toggle_run_with_left_grip
        if (mod_config["general"].has("toggle_run_with_left_grip")) {
            std::string& toggle_run_with_left_grip = mod_config["general"]["toggle_run_with_left_grip"];
            try {
                m_ui_option_toggle_run_with_left_grip = std::stoi(toggle_run_with_left_grip) == 1;
            }
            catch (...) {
                API::get()->log_error("[Mod Config] Invalid general > toggle_run_with_left_grip value.");
            }
        }
        else {
            API::get()->log_error("[Mod Config] Missing general > toggle_run_with_left_grip value.");
        }


        // toggle_run_with_left_grip
        if (mod_config["general"].has("disable_roomscale_when_aiming")) {
            std::string& disable_roomscale_when_aiming = mod_config["general"]["disable_roomscale_when_aiming"];
            try {
                m_ui_option_disable_roomscale_when_aiming = std::stoi(disable_roomscale_when_aiming) == 1;
            }
            catch (...) {
                API::get()->log_error("[Mod Config] Invalid general > disable_roomscale_when_aiming value.");
            }
        }
        else {
            API::get()->log_error("[Mod Config] Missing general > disable_roomscale_when_aiming value.");
        }

        // openxr_runtime
        if (mod_config["general"].has("openxr_runtime")) {
            std::string& openxr_runtime = mod_config["general"]["openxr_runtime"];
            try {
                auto _openxr_runtime = std::stoi(openxr_runtime);
                if (_openxr_runtime != 0 && _openxr_runtime != 1) {
                    m_ui_option_openxr_runtime = META_QUEST;
                    throw std::invalid_argument("Wrong value");
                }
                else {
                    m_ui_option_openxr_runtime = _openxr_runtime;
                }
            }
            catch (...) {
                API::get()->log_error("[Mod Config] Invalid general > openxr_runtime value.");
            }
        }
        else {
            API::get()->log_error("[Mod Config] Missing general > openxr_runtime value.");
        }

        // crosshair_depth
        if (mod_config["crosshair"].has("depth")) {
            std::string& crosshair_depth = mod_config["crosshair"]["depth"];
            try {
                m_ui_option_crosshair_depth = std::stoi(crosshair_depth);
            }
            catch (...) {
                API::get()->log_error("[Mod Config] Invalid crosshair > depth value.");
            }
        }
        else {
            API::get()->log_error("[Mod Config] Missing crosshair > depth value.");
        }

        // crosshair_cursor_scale
        if (mod_config["crosshair"].has("cursor_scale")) {
            std::string& crosshair_cursor_scale = mod_config["crosshair"]["cursor_scale"];
            try {
                m_ui_option_crosshair_cursor_scale = std::stof(crosshair_cursor_scale);
            }
            catch (...) {
                API::get()->log_error("[Mod Config] Invalid crosshair > cursor_scale value.");
            }
        }
        else {
            API::get()->log_error("[Mod Config] Missing crosshair > cursor_scale value.");
        }

        // crosshair_brackets_scale
        if (mod_config["crosshair"].has("brackets_scale")) {
            std::string& crosshair_brackets_scale = mod_config["crosshair"]["brackets_scale"];
            try {
                m_ui_option_crosshair_brackets_scale = std::stof(crosshair_brackets_scale);
            }
            catch (...) {
                API::get()->log_error("[Mod Config] Invalid crosshair > brackets_scale value.");
            }
        }
        else {
            API::get()->log_error("[Mod Config] Missing crosshair > brackets_scale value.");
        }

        // target_id_reticle_scale
        if (mod_config["crosshair"].has("target_id_reticle_scale")) {
            std::string& crosshair_target_id_reticle_scale = mod_config["crosshair"]["target_id_reticle_scale"];
            try {
                m_ui_option_target_id_reticle_scale = std::stof(crosshair_target_id_reticle_scale);
            }
            catch (...) {
                API::get()->log_error("[Mod Config] Invalid crosshair > target_id_reticle_scale value.");
            }
        }
        else {
            API::get()->log_error("[Mod Config] Missing crosshair > target_id_reticle_scale value.");
        }

        return true;
    }

    // saves config file (replaces the whole file with each save)
    bool save_plugin_config() {
        static const auto config_filename = API::get()->get_persistent_dir(L"system_reshock_vr_config.ini").string();
        mINI::INIFile mod_config_file(config_filename);
        mINI::INIStructure mod_config;

        mod_config["general"]["look_sensitivity"] = std::to_string(m_ui_option_look_sensitivity).c_str();
        mod_config["general"]["player_height_modifier"] = std::to_string(m_ui_option_player_height_modifier).c_str();
        mod_config["general"]["force_hide_compass"] = std::to_string(m_ui_option_force_hide_compass).c_str();
        mod_config["general"]["toggle_run_with_left_grip"] = std::to_string(m_ui_option_toggle_run_with_left_grip).c_str();
        mod_config["general"]["disable_roomscale_when_aiming"] = std::to_string(m_ui_option_disable_roomscale_when_aiming).c_str();
        mod_config["general"]["openxr_runtime"] = std::to_string(m_ui_option_openxr_runtime).c_str();

        mod_config["crosshair"]["depth"] = std::to_string(m_ui_option_crosshair_depth).c_str();
        mod_config["crosshair"]["cursor_scale"] = std::to_string(m_ui_option_crosshair_cursor_scale).c_str();
        mod_config["crosshair"]["brackets_scale"] = std::to_string(m_ui_option_crosshair_brackets_scale).c_str();
        mod_config["crosshair"]["target_id_reticle_scale"] = std::to_string(m_ui_option_target_id_reticle_scale).c_str();

        return mod_config_file.generate(mod_config, true);
    }
};

// Actually creates the plugin. Very important that this global is created.
// The fact that it's using std::unique_ptr is not important, as long as the constructor is called in some way.
std::unique_ptr<SystemShockPlugin> g_plugin{ new SystemShockPlugin() };
