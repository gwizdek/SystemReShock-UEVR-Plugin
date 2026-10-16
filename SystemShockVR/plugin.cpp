
#include "SDK/PAWN_PlayerGhost_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/PAWN_Enemy_classes.hpp"
#include "SDK/PAWN_SystemShockCharacter_classes.hpp"
#include "SDK/CORPSE_SkeletalBase_classes.hpp"
#include "SDK/WIDGET_SimpleHUD_classes.hpp"
#include "SDK/WIDGET_CyberspaceHUD_classes.hpp"
#include "SDK/WIDGET_MainMenu_InGame_classes.hpp"
#include "SDK/WIDGET_HardwareButton_classes.hpp"
#include "SDK/WIDGET_Compass_classes.hpp"
#include "SDK/WIDGET_CrosshairCursor_classes.hpp"
#include "SDK/CinematicCamera_classes.hpp"
#include "SDK/CON_Hacker_classes.hpp"
#include "SDK/MOVECONTROL_FocusableInteract_classes.hpp"
#include "SDK/MOVECONTROL_StationMove_classes.hpp"
#include "SDK/COMP_MoveControlManager_classes.hpp"
#include "SDK/STRUCT_MoveInputAction_structs.hpp"
#include "SDK/COMP_LimbManager_classes.hpp"
#include "SDK/COMP_ActionManager_classes.hpp"
#include "SDK/COMP_AttribManager_classes.hpp"
#include "SDK/HeadMountedDisplay_structs.hpp"
#include "SDK/HeadMountedDisplay_classes.hpp"
#include "SDK/ITEM_MeleeWeapon_Base_classes.hpp"
#include "SDK/ITEM_WeaponBase_classes.hpp"
#include "SDK/INTERACT_DestructibleBase_classes.hpp"
#include "SDK/INTERACT_SurgeryMachine_classes.hpp"
#include "SDK/INTERACT_RespawnChamber_classes.hpp"
#include "SDK/INTERACT_Focusable_Base_classes.hpp"
#include "SDK/CharacterAction_classes.hpp"
#include "SDK/AttributeSystem_classes.hpp"
#include "SDK/WIDGET_TargetID_Display_classes.hpp"
#include "SDK/WEAPON_LaserRapier_classes.hpp"
#include "SDK/WEAPON_LeadPipe_classes.hpp"
#include "SDK/SAVE_Settings_classes.hpp"
#include "SDK/BP_IntroDrone_classes.hpp"
#include "SDK/INTERACT_Laptop_classes.hpp"
#include "SDK/ENUM_BootupState_structs.hpp"
#include "SDK/WIDGET_BootupScreen_classes.hpp"
#include "SDK/WIDGET_CrashScreen_classes.hpp"
#include "SDK/COMP_Scanner_classes.hpp"
#include "SDK/PICKUP_Base_classes.hpp"
#include "SDK/STRUCT_InteractResults_structs.hpp"
#include "SDK/HARDWARE_HeadLamp_classes.hpp"

#include "BridgeSDK/_BP_LaserDot_classes.hpp"
#include "BridgeSDK/_BP_ItemSelector_classes.hpp"
#include "BridgeSDK/_BP_MFDMaskComponent_classes.hpp"
#include "BridgeSDK/_BP_HandInteractionComponent_classes.hpp"
//#include "BridgeSDK/_BP_VRMovementComponent_classes.hpp"
#include "BridgeSDK/_BP_VRMovementComponent_classes.hpp"
#include "BridgeSDK/_CH_Hacker_Rig_Skeleton_AnimBlueprint_classes.hpp"
#include "BridgeSDK/_BP_MeleeWeaponHandler_classes.hpp"
#include "BridgeSDK/_BP_VRMenu_classes.hpp"
#include "BridgeSDK/_BP_InteractablesHighlighter_classes.hpp"
#include "BridgeSDK/_BFL_VRModUtils_classes.hpp"
#include "BridgeSDK/_BP_DebugLog_classes.hpp"

#include "plugin.hpp"
#include "build_version.hpp"
#include "plugin_utils.hpp"
#include "sdk_bootstrap.hpp"
#include "vr_body.hpp"
#include "vr_item_selector.hpp"
#include "vr_mfd.hpp"
#include "vr_avatar.hpp"
#include "vr_options_menu.hpp"
#include "vr_snap_turn.hpp"
#include "vr_settings.hpp"
#include "cyberspace_atmosphere_fix.hpp"
#include "focus_interaction_patch.hpp"
#include "vr_input_actions.hpp"
#include "vr_button_atlas.hpp"
#include "tutorial_messages.hpp"
#include "tutorial_popup_duration.hpp"
#include "legend_icon_size_patch.hpp"
#include "vr_button_atlas_index_patch.hpp"
#include "tutorial_head_view.hpp"

#include <windows.h>
#include <chrono>
#include <ctime>

#define INPUT_DEADZONE_LO  ( 0.01f * FLOAT(0x7FFF) )  // Default to 01% of the +/- 32767 range.
#define INPUT_DEADZONE_MED ( 0.45f * FLOAT(0x7FFF) )  // Default to 45% of the +/- 32767 range.
#define INPUT_DEADZONE_HI  ( 0.80f * FLOAT(0x7FFF) )  // Default to 80% of the +/- 32767 range.

using namespace uevr;
using namespace SDK;

std::unique_ptr<UEVRPlugin> g_plugin = std::make_unique<UEVRPlugin>();

namespace {

// Nothing in the game imports these two classes. Mod Blueprints pull the function library in
// when they load, but that happens only with the first VR body spawn. Loading them here makes
// both usable from the plugin before any level, for example to create the debug log object.
void load_mod_utility_classes() {
    PluginUtils::load_class_for_bridge(
        L"/Game/Mods/Utils/_BFL_VRModUtils._BFL_VRModUtils_C", U_BFL_VRModUtils_C::BridgeClassRef());
    PluginUtils::load_class_for_bridge(
        L"/Game/Mods/Utils/_BP_DebugLog._BP_DebugLog_C", U_BP_DebugLog_C::BridgeClassRef());
}

// Menus step through their items on a small stick tilt, so the left stick only counts past a
// high threshold there. Used on the title screen and in the pause menu.
void apply_menu_stick_deadzone(XINPUT_STATE* state) {
    if (std::abs(state->Gamepad.sThumbLX) < INPUT_DEADZONE_HI) {
        state->Gamepad.sThumbLX = 0;
    }
    if (std::abs(state->Gamepad.sThumbLY) < INPUT_DEADZONE_HI) {
        state->Gamepad.sThumbLY = 0;
    }
}

// The library function needs a world context. The world is the standard one: the Blueprint
// calls GetGameInstance on it and spawns the logger under that instance, which lives for the
// whole session. Both game instance pointers are logged so a mismatch shows up in log.txt.
UObject* bp_logger_world_context() {
    UWorld* world = SdkBootstrap::get_world();
    auto* engine = reinterpret_cast<UGameEngine*>(API::get()->get_engine());
    UGameInstance* engine_instance = engine != nullptr ? engine->GameInstance : nullptr;
    UGameInstance* world_instance = world != nullptr ? world->OwningGameInstance : nullptr;
    API::get()->log_warn("[plugin][bp_logger_world_context] world=0x%p world.OwningGameInstance=0x%p engine.GameInstance=0x%p",
        world, world_instance, engine_instance);
    return world;
}

// Creates the Blueprint debug log object through _BFL_VRModUtils.CreateBPLogger.
// Returns nullptr when the library is not loaded, no context exists yet, or the call throws.
U_BP_DebugLog_C* create_bp_logger() {
    try {
        if (U_BFL_VRModUtils_C::BridgeClassRef().get() == nullptr) {
            API::get()->log_error("[plugin][create_bp_logger] _BFL_VRModUtils_C not loaded, logger not created");
            return nullptr;
        }
        UObject* context = bp_logger_world_context();
        if (context == nullptr) {
            API::get()->log_error("[plugin][create_bp_logger] no game instance or world yet, logger not created");
            return nullptr;
        }
        U_BP_DebugLog_C* logger = nullptr;
        U_BFL_VRModUtils_C::CreateBPLogger(context, &logger);
        API::get()->log_warn("[plugin][create_bp_logger] CreateBPLogger returned 0x%p (context 0x%p)", logger, context);
        if (logger == nullptr) {
            return nullptr;
        }
        // Blueprints reach the logger through Get Class Defaults, and no Blueprint node can
        // write a class default.
        U_BP_DebugLog_C::GetDefaultObj()->Instance() = logger;
        API::get()->log_warn("[plugin][create_bp_logger] stored in _BP_DebugLog_C class defaults");
        // The class default's reference does not keep the logger alive by itself: at the title
        // screen no game asset references _BP_DebugLog_C, so the collector frees the class, its
        // default object and the logger together. Rooting the logger keeps all three.
        if (!PluginUtils::add_to_root(logger)) {
            API::get()->log_error("[plugin][create_bp_logger] could not root the logger, it may be garbage collected");
        }
        return logger;
    }
    catch (...) {
        API::get()->log_error("[plugin][create_bp_logger] Exception");
        return nullptr;
    }
}

// The clock behind the Blueprint node GetAccurateRealTime: FPlatformTime::Seconds() on
// Windows is the performance counter in seconds plus 16777216.0. Reading it the same way here
// lets the plugin turn an entry's TimeSeconds and TimeFraction into its age.
double accurate_real_time_now() {
    LARGE_INTEGER counter{};
    LARGE_INTEGER frequency{};
    QueryPerformanceCounter(&counter);
    QueryPerformanceFrequency(&frequency);
    return static_cast<double>(counter.QuadPart) / static_cast<double>(frequency.QuadPart) + 16777216.0;
}

// Local time in the layout UEVR's own log lines use: "2026-10-01 19:20:27.654".
std::string format_uevr_time(std::chrono::system_clock::time_point time) {
    const auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(time.time_since_epoch()) % 1000;
    const std::time_t seconds = std::chrono::system_clock::to_time_t(time);
    std::tm local{};
    localtime_s(&local, &seconds);
    char text[32]{};
    std::strftime(text, sizeof(text), "%Y-%m-%d %H:%M:%S", &local);
    char result[40]{};
    snprintf(result, sizeof(result), "%s.%03d", text, static_cast<int>(millis.count()));
    return result;
}

// Wall-clock time of an entry: now minus the entry's age on the accurate real time clock.
// A nonsense age (negative or over a day) means the clocks do not match; then now is used.
std::chrono::system_clock::time_point bp_entry_wall_time(F_STRUCT_DebugLogEntry& entry, double now_accurate,
                                                         std::chrono::system_clock::time_point now_wall) {
    const double entry_accurate = static_cast<double>(entry.TimeSeconds()) + static_cast<double>(entry.TimeFraction());
    const double age_seconds = now_accurate - entry_accurate;
    if (age_seconds < 0.0 || age_seconds > 86400.0) {
        return now_wall;
    }
    return now_wall - std::chrono::microseconds(static_cast<long long>(age_seconds * 1000000.0));
}

// One log line per entry, at the UEVR level matching the entry's Type. The message body
// repeats UEVR's own layout, so the entry's real time stands next to the tick's time.
void log_bp_entry(F_STRUCT_DebugLogEntry& entry, const std::string& time_text) {
    const std::string message = entry.Message().ToString();
    switch (entry.Type()) {
    case E_ENUM_DebugWidgetEntryType::Error:
        API::get()->log_error("[%s] [Blueprint] [error] %s", time_text.c_str(), message.c_str());
        break;
    case E_ENUM_DebugWidgetEntryType::Warn:
        API::get()->log_warn("[%s] [Blueprint] [warning] %s", time_text.c_str(), message.c_str());
        break;
    default:
        // warn, not info: UEVR writes only warn and error from plugins to log.txt.
        API::get()->log_warn("[%s] [Blueprint] [info] %s", time_text.c_str(), message.c_str());
        break;
    }
}

} // anonymous namespace

// -------------------------------------------------------------------------------------
// UEVR Overrides
// -------------------------------------------------------------------------------------
void UEVRPlugin::on_initialize() {
    PLUGIN_LOG_ONCE("Plugin Initializing...");

    // Must run before the first StaticClass()/GetDefaultObj() call below.
    SdkBootstrap::initialize();

    // GetDefaultObj() reads through StaticClass() without a null check, and at the first
    // frame these Blueprint classes may not be loaded yet. Check the class first.
    // disable player focus (camera pull) on interactable objects like vending machines / keyboards
    if (SDK::UMOVECONTROL_FocusableInteract_C::StaticClass() != nullptr) {
        auto move_control = SDK::UMOVECONTROL_FocusableInteract_C::GetDefaultObj();
        move_control->ShouldUseCharacterMovement = true;
        move_control->IsFinishedTransitioning = true;
    }
    else {
        API::get()->log_warn("[plugin][on_initialize] MOVECONTROL_FocusableInteract_C not loaded yet, defaults not changed");
    }

    // disable move control on doors / power stations
    if (SDK::UMOVECONTROL_StationMove_C::StaticClass() != nullptr) {
        SDK::UMOVECONTROL_StationMove_C::GetDefaultObj()->ExpireNextTick = true;
    }
    else {
        API::get()->log_warn("[plugin][on_initialize] MOVECONTROL_StationMove_C not loaded yet, defaults not changed");
    }
    m_ui_option_auto_ads_enabled = VRSettings::auto_ads();
    API::get()->log_warn("[plugin][on_initialize] Done");
}

void UEVRPlugin::on_xinput_get_state(uint32_t* retval, uint32_t user_index, XINPUT_STATE* state) {
    PLUGIN_LOG_ONCE("XInput Get State");

    const UEVR_VRData* vr = API::get()->param()->vr;
    if (!vr->is_runtime_ready())
        return;

    try {
        // start cb timer
        std::chrono::steady_clock::time_point begin_time;
        if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
            begin_time = std::chrono::steady_clock::now();
        }

        if (!prepare_pointers()) {
            return;
        }
        prepare_game_state();
        // handle level change before xinput
        handle_level_change();
        handle_xinput(state, vr);
        handle_lean();
        handle_crouch();

        // set it to true, so we won't process pawn again in pre_engine_tick cb
        m_xinput_cb_processed = true;

        // calculate cb duration
        if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
            std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
            m_ui_xinput_duration = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - begin_time).count());
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][on_xinput_get_state] Exception");
    }
}

void UEVRPlugin::on_pre_engine_tick(API::UGameEngine* engine, float delta) {
    PLUGIN_LOG_ONCE("Pre Engine Tick: %f", delta);
    try {
        const UEVR_VRData* vr = API::get()->param()->vr;
        if (!vr->is_runtime_ready())
            return;

        m_cb_calls_count = m_cb_calls_count < CB_DURATION_SAMPLE_RATE ? ++m_cb_calls_count : 0;
        // start cb timer
        std::chrono::steady_clock::time_point begin_time;
        if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
            begin_time = std::chrono::steady_clock::now();
        }

        // if the controllers are not active, the xinput cb is not triggered.
        // normally we want the xinput cb to prepare vars as it's the first cb to be called
        // but if it wasn't called, we prepare them here
        if (!m_xinput_cb_processed) {
            if (!prepare_pointers())
                return;
            prepare_game_state();
            handle_level_change();
        }
        else {
            // reset for next cb iteration
            m_xinput_cb_processed = false;
        }

        m_gamepad_left_thumb.add_delta(delta);

        handle_game_state_change();
        handle_deferred_camera_reset(delta);
        handle_cyberspace_look_pivot(vr);
        handle_media_display();
        update_trailing_rotation(delta);
        handle_ads();
        handle_head_lamp();
        CyberspaceAtmosphereFix::handle(m_world);
        FocusInteractionPatch::handle();
        VRInputActions::handle();
        VRButtonAtlas::handle();
        TutorialMessages::handle();
        TutorialPopupDuration::handle(m_world);
        LegendIconSizePatch::handle();
        VRButtonAtlasIndexPatch::handle();
        TutorialHeadView::handle(m_world, g_vr_body);
        VROptionsMenu::handle(m_neural_hud, m_pawn.get());
        if (VROptionsMenu::consume_settings_change()) {
            apply_vr_options_menu_settings();
        }

        PluginUtils::handle_native_stereo_fix_cycler(vr);

        // Test function calls used for testing different things.
        // These are called from ImGui and we want them to run on main game thread (deactivated rn)
        //if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
        //    try_running_test_1();
        //    try_running_test_2();
        //}

        // calculate cb duration
        if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
            std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
            m_ui_pre_engine_tick_duration = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - begin_time).count());
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][on_pre_engine_tick] Exception");
    }
}

// -------------------------------------------------------------------------------------
// Pointers and State
// -------------------------------------------------------------------------------------
bool UEVRPlugin::prepare_pointers() {
    try {
        // world
        m_world = SdkBootstrap::get_world();
        if (m_world == nullptr) {
            API::get()->log_error("[plugin][prepare_pointers] World pointer error");
            return false;
        }
        // pawn
        m_pawn.set_value(m_world != nullptr ? UGameplayStatics::GetPlayerPawn(m_world, 0) : nullptr);
        if (!UKismetSystemLibrary::IsValid(m_pawn.get())) {
            API::get()->log_error("[plugin][prepare_pointers] Pawn pointer error");
            return false;
        }

        if (PluginUtils::is_a<APAWN_Hacker_Simple_C>(m_pawn.get())) {
            m_inventory = static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->COMP_HackerInventory;
            UCOMP_MoveControlManager_C* mcm = static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->COMP_MoveControlManager;
            if (mcm != nullptr) {
                m_is_crouching.set_value(mcm->IsTryingToCrouch);
            }
            else {
                m_is_crouching.set_value(false);
            }
        }

        if (PluginUtils::is_a<APAWN_Hacker_Implant_C>(m_pawn.get())) {
            static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->GetNeuralHUD(&m_neural_hud);
            if (m_neural_hud == nullptr) {
                API::get()->log_error("[plugin][prepare_pointers] Neural HUD pointer error");
                return false;
            }

            m_is_media_display_visible.consume();
            m_neural_hud->IsMediaDisplayVisible(&m_is_media_display_visible.value);

            // headlamp
            if (m_inventory != nullptr) {
                m_is_head_lamp_active.set_value(static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->HeadlampLight->Intensity != 0.0f);
            }

        }

        // level
        m_level.set_value(m_world != nullptr ? m_world->PersistentLevel : nullptr);
    }
    catch (...) {
        API::get()->log_error("[plugin][prepare_pointers] Exception");
        return false;
    }
    return true;
}

// TODO: Optimize order: APAWN_Hacker_Implant_C and derivatives first
void UEVRPlugin::on_pre_calculate_stereo_view_offset(UEVR_StereoRenderingDeviceHandle, int, float, UEVR_Vector3f*, UEVR_Rotatorf*, bool) {
    try {
        VRSnapTurn::before_view_offset();
    }
    catch (...) {
        API::get()->log_error("[plugin][on_pre_calculate_stereo_view_offset] Exception");
    }
}

void UEVRPlugin::on_post_calculate_stereo_view_offset(UEVR_StereoRenderingDeviceHandle, int, float, UEVR_Vector3f*, UEVR_Rotatorf*, bool) {
    try {
        VRSnapTurn::after_view_offset();
    }
    catch (...) {
        API::get()->log_error("[plugin][on_post_calculate_stereo_view_offset] Exception");
    }
}

void UEVRPlugin::on_post_engine_tick(API::UGameEngine* engine, float delta) {
    if (m_bp_logger == nullptr) {
        return;
    }
    try {
        flush_bp_log();
    }
    catch (...) {
        // A failing flush would fail again every tick, each time with a failed object search
        // and two log lines. Drop the logger; the next level change creates a new one.
        m_bp_logger = nullptr;
        API::get()->log_error("[plugin][on_post_engine_tick] Exception, Blueprint log stopped until the next level change");
    }
}

// Writes every entry the Blueprints added to the debug log since the last tick into the
// UEVR log, at the level matching the entry's Type, then empties the Blueprint array.
void UEVRPlugin::flush_bp_log() {
    bridge::StructArray<F_STRUCT_DebugLogEntry>& entries = m_bp_logger->Entries();
    if (entries.size() <= 0) {
        return;
    }
    const double now_accurate = accurate_real_time_now();
    const auto now_wall = std::chrono::system_clock::now();
    for (int32_t i = 0; i < entries.size(); ++i) {
        F_STRUCT_DebugLogEntry entry = entries[i];
        const std::string time_text = format_uevr_time(bp_entry_wall_time(entry, now_accurate, now_wall));
        log_bp_entry(entry, time_text);
    }
    m_bp_logger->Clear();
}

void UEVRPlugin::prepare_game_state() {
    static UWIDGET_MainMenu_InGame_C* main_menu{ nullptr };
    static APlayerCameraManager* player_camera_manager{ nullptr };
    static AActor* channeling_interactable{ nullptr };
    //API::get()->log_error("[plugin][prepare_game_state] Start");
    try {
        if (m_world == nullptr) {
            m_game_state.set_value(GAME_STATE_UNDEFINED);
            m_pawn_state.set_value(PAWN_UNKNOWN);
            return;
        }
        player_camera_manager = UGameplayStatics::GetPlayerCameraManager(m_world, 0);

        // trying to put APAWN_Hacker_Implant_C as early as possible (99% of engine ticks)
        if (UKismetSystemLibrary::IsValid(m_pawn.get()) && PluginUtils::is_a<APAWN_Hacker_Implant_C>(m_pawn.get())) {
            m_pawn_state.set_value(PAWN_HACKERIMPLANT);

            // GAME_STATE_CINEMATIC
            if (player_camera_manager != nullptr) {
                if (
                    UKismetSystemLibrary::IsValid(player_camera_manager->ViewTarget.Target) &&
                    player_camera_manager->ViewTarget.Target->IsA(ACineCameraActor::StaticClass())
                    ) {
                    m_game_state.set_value(GAME_STATE_CINEMATIC);
                    return;
                }
            }

            static_cast<UWIDGET_PlayerHUD_C*>(static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->PlayerHUDWidget)->GetMainMenuWidget(&main_menu);

            // PAUSE MENU
            if (main_menu != nullptr && main_menu->IsMainMenuEnabled) {
                m_game_state.set_value(GAME_STATE_PAUSE_MENU);
                return;
            }

            if (m_neural_hud != nullptr) {

                // GAME_STATE_MFD
                if (m_neural_hud->bIsMFDVisible) {
                    if (m_game_state.matches_none({ GAME_STATE_MFD, GAME_STATE_MFD_PRE })) {
                        // set a intermediate MFD state for one tick, when we center the MFD
                        m_game_state.set_value(GAME_STATE_MFD_PRE);
                        return;
                    }
                    else {
                        m_game_state.set_value(GAME_STATE_MFD);
                        return;
                    }
                }
                
                // BOOTING_UP
                if (
                    m_neural_hud->WIDGET_BootupScreen->CurrentState != SDK::ENUM_BootupState::NewEnumerator7 &&
                    m_neural_hud->WIDGET_BootupScreen->CurrentState != SDK::ENUM_BootupState::NewEnumerator0
                    ) {
                    m_game_state.set_value(GAME_STATE_BOOTING_UP);
                    return;
                }

                // CRASHING
                if (
                    m_neural_hud->WIDGET_CrashScreen->CurrentState != SDK::ENUM_CrashState::NewEnumerator2 &&
                    m_neural_hud->WIDGET_CrashScreen->CurrentState != SDK::ENUM_CrashState::NewEnumerator3
                    ) {
                    m_game_state.set_value(GAME_STATE_CRASHING);
                    return;
                }

                // GAME_STATE_INTERACTABLE
                channeling_interactable = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->ChannelingInteractable;
                if (channeling_interactable != nullptr) {
                    //if (channeling_interactable->IsA(AINTERACT_Focusable_Base_C::StaticClass())) {
                    //    API::get()->log_warn("[plugin][prepare_game_state] Focusable interaction");
                    //    static_cast<AINTERACT_Focusable_Base_C*>(channeling_interactable)->TryFinishFocusInteraction(static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get()));
                    //}
                    m_game_state.set_value(GAME_STATE_INTERACTABLE);
                    return;
                }
            }
            else {
                API::get()->log_error("[plugin][prepare_game_state] Hacker Pawn but no Neural HUD");
            }

            // NORMAL SPACE GAMEPLAY
            m_game_state.set_value(GAME_STATE_CITADEL_STATION);
            return;
        }

        if (!UKismetSystemLibrary::IsValid(m_pawn.get())) {
            m_game_state.set_value(GAME_STATE_UNDEFINED);
            m_pawn_state.set_value(PAWN_UNKNOWN);
            return;
        }

        // PLAYER GHOST
        if (PluginUtils::is_a<APAWN_PlayerGhost_C>(m_pawn.get())) {
            m_pawn_state.set_value(PAWN_PLAYERGHOST);

            // GAME_STATE_INTRO_DRONE
            if (player_camera_manager != nullptr) {
                if (
                    UKismetSystemLibrary::IsValid(player_camera_manager->ViewTarget.Target) &&
                    PluginUtils::is_a<ABP_IntroDrone_C>(player_camera_manager->ViewTarget.Target)
                    ) {
                    m_game_state.set_value(GAME_STATE_INTRO_DRONE);
                    return;
                }
            }

            // GAME_STATE_MAIN_MENU
            m_game_state.set_value(GAME_STATE_MAIN_MENU);
            return;
        }

        // HACKER AVATAR - Cyberspace
        if (PluginUtils::is_a<APAWN_Avatar_C>(m_pawn.get())) {
            m_pawn_state.set_value(PAWN_AVATAR);

            // GAME_STATE_PAUSE_MENU
            static_cast<UWIDGET_CyberspaceHUD_C*>(static_cast<APAWN_Avatar_C*>(m_pawn.get())->CyberspaceUI)->GetMainMenuWidget(&main_menu);
            if (main_menu != nullptr && main_menu->IsMainMenuEnabled) {
                m_game_state.set_value(GAME_STATE_PAUSE_MENU);
                return;
            }

            m_game_state.set_value(GAME_STATE_CYBERSPACE);
            return;
        }

        // HACKER SIMPLE - APPARTMENT INTRO
        if (PluginUtils::is_a<APAWN_Hacker_Simple_C>(m_pawn.get())) {
            m_pawn_state.set_value(PAWN_HACKERSIMPLE);
            try_set_intro_laptop_pointer();

            // GAME_STATE_INTRO_LAPTOP
            if (m_intro_laptop != nullptr && m_intro_laptop->IsInteracting) {
                m_game_state.set_value(GAME_STATE_INTRO_LAPTOP);
                return;
            }

            // GAME_STATE_PAUSE_MENU
            static_cast<UWIDGET_SimpleHUD_C*>(static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->PlayerHUDWidget)->GetMainMenuWidget(&main_menu);
            if (main_menu != nullptr && main_menu->IsMainMenuEnabled) {
                m_game_state.set_value(GAME_STATE_PAUSE_MENU);
                return;
            }

            // GAME_STATE_INTERACTABLE
            if (static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->ChannelingInteractable != nullptr) {
                m_game_state.set_value(GAME_STATE_INTERACTABLE);
                return;
            }

            m_game_state.set_value(GAME_STATE_APPARTMENT);
            return;
        }

        // GAME_STATE_PSEUDOSPACE
        // TODO: add pseudospace pause menu
        // TODO: add pseudospace pawn check, but use string search
        // because PAWN_Hacker_Pseudospace is not in memory when player is not in pseudospace

        // all previous checks are false
        m_game_state.set_value(GAME_STATE_UNDEFINED);
        m_pawn_state.set_value(PAWN_UNKNOWN);
        API::get()->log_error("[plugin][prepare_game_state] Undefined game state");
    }
    catch (...) {
        API::get()->log_error("[plugin][prepare_game_state] Exception");
    }
}


// -------------------------------------------------------------------------------------
// Handlers
// -------------------------------------------------------------------------------------

void UEVRPlugin::handle_xinput(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        // Updating controller memo states
        m_gamepad_btn_a.set_state(state);
        m_gamepad_btn_x.set_state(state);
        m_gamepad_btn_b.set_state(state);
        m_gamepad_btn_y.set_state(state);
        m_gamepad_right_shoulder.set_state(state);
        m_gamepad_left_shoulder.set_state(state);
        m_gamepad_right_thumb.set_state(state);
        m_gamepad_left_thumb.set_state(state);
        m_gamepad_right_trigger.set_state(state);
        m_gamepad_left_trigger.set_state(state);
        m_hotbar_selector_button.set_state(state);
        m_hardware_selector_button.set_state(state);

        // Citadel Station normal movement gameplay
        if (m_game_state.get() == GAME_STATE_CITADEL_STATION) {
            if (g_vr_body == nullptr) {
                return;
            }
            m_is_right_hand_reaching_backpack.set_value(g_vr_body->HandInteractionRight()->IsReachingBackpack());

            handle_vr_menu_xinput(state, vr);
            handle_citadel_station_xinput(state, vr);
            handle_smooth_turning(state);
            return;
        }

        // Pause menu
        if (m_game_state.get() == GAME_STATE_PAUSE_MENU) {
            apply_menu_stick_deadzone(state);
            if (g_vr_body == nullptr) {
                return;
            }

            if (m_gamepad_left_trigger.is_held() && m_gamepad_right_shoulder.is_pressed()) {
                open_debug_menu();
            }

            return;
        }

        // Focusable interaction
        if (m_game_state.get() == GAME_STATE_INTERACTABLE) {
            if (m_gamepad_btn_x.is_pressed()) {}

            m_gamepad_btn_x.mute_state(state);
            return;
        }

        // Apartment movement gameplay
        if (m_game_state.get() == GAME_STATE_APPARTMENT) {
            handle_vr_menu_xinput(state, vr);
            handle_appartment_xinput(state, vr);
            handle_smooth_turning(state);
            return;
        }

        // Pre MFD Visible
        if (m_game_state.get() == GAME_STATE_MFD_PRE) {
            // mute shoulders, otherwise it will auto change MFD tab
            m_gamepad_right_shoulder.mute_state(state);
            m_gamepad_left_shoulder.mute_state(state);
            return;
        }

        // MFD Visible
        if (m_game_state.get() == GAME_STATE_MFD) {
            if (g_vr_body == nullptr) {
                return;
            }

            if (m_gamepad_right_shoulder.is_pressed()) {
                if (g_vr_body->HandInteractionRight()->IsReachingSocket(UKismetStringLibrary::Conv_StringToName(L"LeftInnerWristSocket"), 7.0f)) {
                    static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_Real_ToggleMFD_K2Node_InputActionEvent_43(FKey{});
                }
            }
            
            // Left Shoulder - close MFD
            m_gamepad_left_shoulder.when_pressed_send(state, XINPUT_GAMEPAD_X);
            
            handle_mfd_interactions(state, vr);

            m_gamepad_right_shoulder.mute_state(state);
            m_gamepad_left_shoulder.mute_state(state);
            return;
        }

        if (m_game_state.get() == GAME_STATE_MAIN_MENU) {
            apply_menu_stick_deadzone(state);
            // don't remap other buttons in the title screen's menu
            return;
        }

        if (m_game_state.get() == GAME_STATE_CYBERSPACE) {

            //// change control scheme on RS
            //if (m_gamepad_right_thumb.is_pressed()) {
            //    m_cyberspace_aim_method = m_cyberspace_aim_method == 0 ? 2 : 0;

            //    if (m_cyberspace_aim_method == 0) {
            //        vr->recenter_view();
            //    }

            //    vr->set_aim_method(m_cyberspace_aim_method);
            //    vr->set_decoupled_pitch_enabled(m_cyberspace_aim_method == 2);
            //}

            handle_smooth_turning(state);

            m_gamepad_right_shoulder.when_held_send(state, XINPUT_GAMEPAD_A);
            m_gamepad_right_shoulder.mute_state(state);
            m_gamepad_left_shoulder.when_held_send(state, XINPUT_GAMEPAD_B);
            m_gamepad_left_shoulder.mute_state(state);

            if (state->Gamepad.sThumbRY > INPUT_DEADZONE_MED) {
                state->Gamepad.sThumbRX = 0;
                m_gamepad_btn_a.force_state(state);
            }
            else if (state->Gamepad.sThumbRY < -INPUT_DEADZONE_MED) {
                state->Gamepad.sThumbRX = 0;
                m_gamepad_btn_b.force_state(state);
            }

            if (m_gamepad_right_thumb.is_pressed()) {
                SDK::FKey key_name{ .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"Escape") };
                static_cast<SDK::APAWN_Avatar_C*>(m_pawn.get())->InpActEvt_Locked_Escape_K2Node_InputActionEvent_96(key_name);
            }
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_xinput] Exception");
    }
}

void UEVRPlugin::handle_vr_menu_xinput(XINPUT_STATE* state, const UEVR_VRData* vr) {
    if (g_vr_body->VRMenu()->bIsOpened()) {
        // mute sticks
        state->Gamepad.sThumbRX = 0;
        state->Gamepad.sThumbRY = 0;
        state->Gamepad.sThumbLX = 0;
        state->Gamepad.sThumbLY = 0;

        if (m_gamepad_right_trigger.is_pressed()) {
            g_vr_body->TriggerWidgetInteractionAction(true);
        }

        if (m_gamepad_right_trigger.is_released()) {
            g_vr_body->TriggerWidgetInteractionAction(false);
        }

        m_gamepad_right_trigger.mute_state(state);
    }
}

void UEVRPlugin::handle_appartment_xinput(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        // Right Trigger
        if (m_gamepad_right_trigger.is_pressed()) {
            if (g_vr_body->IsEmptyHanded()) {
                g_vr_body->HandInteractionRight()->AttachLaserPointer(true, 10.f);
            }
        }

        // Left Trigger
        if (m_gamepad_left_trigger.is_pressed()) {
            if (g_vr_body->IsEmptyHanded()) {
                g_vr_body->HandInteractionLeft()->AttachLaserPointer(true, 10.f);
            }
        }

        // Right Shoulder
        if (m_gamepad_right_shoulder.is_pressed()) {
            g_vr_body->HandInteractionRight()->TryGrab();

            if (!g_vr_body->HandInteractionRight()->IsHoldingWeapon()) {
                g_vr_body->HandInteractionRight()->SelectedPose() = E_ENUM_VRHandPose::NewEnumerator3;
            }
        }
        if (m_gamepad_right_shoulder.is_released()) {
            g_vr_body->HandInteractionRight()->TryRelease();

            if (!g_vr_body->HandInteractionRight()->IsHoldingWeapon()) {
                g_vr_body->HandInteractionRight()->SelectedPose() = E_ENUM_VRHandPose::NewEnumerator0;
            }
        }

        // Left Shoulder
        if (m_gamepad_left_shoulder.is_pressed()) {
            g_vr_body->HandInteractionLeft()->TryGrab();
            // set pointing hand pose
            g_vr_body->HandInteractionLeft()->SelectedPose() = E_ENUM_VRHandPose::NewEnumerator3;
        }
        if (m_gamepad_left_shoulder.is_released()) {
            // set undefined hand pose
            g_vr_body->HandInteractionLeft()->SelectedPose() = E_ENUM_VRHandPose::NewEnumerator0;
            // try releasing world object
            g_vr_body->HandInteractionLeft()->TryRelease();
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_appartment_xinput] Exception");
    }
}


// Opens the game's built-in debug menu through the in-game main menu widget.
// The game's own gamepad combo for this is dead code in the shipped build, so the plugin calls it directly.
void UEVRPlugin::open_debug_menu() {
    try {
        if (m_neural_hud == nullptr) {
            API::get()->log_warn("[plugin][open_debug_menu] No player HUD widget");
            return;
        }
        UWIDGET_MainMenu_InGame_C* main_menu{ nullptr };
        m_neural_hud->GetMainMenuWidget(&main_menu);
        if (main_menu == nullptr) {
            API::get()->log_warn("[plugin][open_debug_menu] No main menu widget");
            return;
        }
        API::get()->log_warn("[plugin][open_debug_menu] Opening debug menu");
        main_menu->OpenDebugMenu();
    }
    catch (...) {
        API::get()->log_error("[plugin][open_debug_menu] Exception");
    }
}


void UEVRPlugin::handle_citadel_station_xinput(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        // TODO: move it to BPs
        try_melee();

        m_gamepad_right_shoulder.mute_state(state);
        m_gamepad_left_shoulder.mute_state(state);

        // Keep play in gamepad mode, so legends and tutorial texts show controller icons. The MFD
        // handler clicks with the mouse, and Windows delivers those clicks a frame or two after the
        // MFD closed; the game counts a mouse button as keyboard and mouse input and would switch.
        auto player_controller = UGameplayStatics::GetPlayerController(m_world, 0);
        if (PluginUtils::is_a<ACON_Hacker_C>(player_controller)) {
            static_cast<ACON_Hacker_C*>(player_controller)->SetIsUsingGamepad(true);
        }

        // map jump to right thumb up
        if (state->Gamepad.sThumbRY > INPUT_DEADZONE_HI) {
            state->Gamepad.wButtons |= XINPUT_GAMEPAD_A;
        }

        // debug - open the game's debug menu (WIDGET_MainMenu_InGame::OpenDebugMenu)
        if (m_gamepad_left_trigger.is_held() && m_gamepad_right_shoulder.is_pressed()) {
            //PluginUtils::list_overlapping_components(m_world, g_vr_body->MotionControllerRight()->K2_GetComponentLocation(), 100.f);
            //PluginUtils::show_all_primitive_components(m_world, g_vr_body->MotionControllerRight(), 100.f, true);

            //if (m_neural_hud != nullptr) {
            //    //SDK::FText my_text = SDK::UKismetTextLibrary::Conv_StringToText(L"ACCESS GRANTED");
            //    //m_neural_hud->EVENT_OnFeedbackDataChanged(ENUM_InteractResultType::NewEnumerator0, my_text);
            //    API::get()->log_warn("[plugin][handle_citadel_station_xinput] Queue notification");
            //    m_neural_hud->QueueNotification(
            //        SDK::UKismetTextLibrary::Conv_StringToText(L"SHODAN is watching."),
            //        /*IsWarning=*/ false);
            //}
        }

        // pull out a gun when right hand is leaving backpack collision sphere
        if (m_is_pulling_gun_out && m_is_right_hand_reaching_backpack.disabled()) {
            if (
                !g_vr_body->HandInteractionRight()->IsHoldingWeapon() &&
                g_vr_body->HandInteractionRight()->HeldGrabComponent() == nullptr
                ) {
                SDK::FKey h_key_name{
                    .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
                };
                g_vr_body->HackerPawn()->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_64(h_key_name);
                m_is_pulling_gun_out = false;
            }
        }

        if (m_gamepad_left_trigger.is_held() && m_gamepad_left_thumb.is_pressed()) {
            
            // testing weapon physical collisions (currently held weapons)
            // normally, held weapons have disabled collisions
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->K2_AttachToComponent(
            //    g_vr_body->VRBodyMesh(),
            //    UKismetStringLibrary::Conv_StringToName(L"RightHandPipeSocket"),
            //    EAttachmentRule::SnapToTarget,
            //    EAttachmentRule::SnapToTarget,
            //    EAttachmentRule::KeepWorld,
            //    true
            //);
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel10);
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->SetCollisionProfileName(UKismetStringLibrary::Conv_StringToName(L"PickupPhysicsActor"), false);
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel4);
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_GameTraceChannel4, ECollisionResponse::ECR_Block);
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->SetEnableGravity(false);
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->SetSimulatePhysics(true);

        }

        // Right Trigger
        if (m_gamepad_right_trigger.is_pressed()) {

            // test making enemies simulate physics
            //if (g_vr_body->LaserDot()->LastLaserTargetActor()->IsA(APAWN_Enemy_C::StaticClass())) {
            //    APAWN_Enemy_C* enemy = static_cast<APAWN_Enemy_C*>(g_vr_body->LaserDot()->LastLaserTargetActor());
            //    enemy->COMP_LimbManager->SetRagdollEnabled();
            //    
            //    //static_cast<APAWN_Enemy_C*>(g_vr_body->LaserDot()->LastLaserTargetComponent())->SetSimulatePhysics(true);
            //    //static_cast<APAWN_Enemy_C*>(g_vr_body->LaserDot()->LastLaserTargetComponent())->SetEnableGravity(true);
            //    API::get()->log_error("[plugin][handle_citadel_station_xinput] Test physics");
            //}

            // attach laser pointer to an empty hand (only if both hands are empty)
            if (g_vr_body->IsEmptyHanded()) {
                g_vr_body->HandInteractionRight()->AttachLaserPointer(true, 10.f);
            }
            
            // TODO
            // Set Laser Rapier charged mode
            if (g_vr_body->MeleeWeaponHandler()->IsActive() && g_vr_body->MeleeWeaponHandler()->IsLaserRapier()) {
                m_gamepad_right_trigger.mute_state(state);
            }
        }

        // TODO
        if (m_gamepad_right_trigger.is_held()) {
            // Set Laser Rapier charged mode
            if (g_vr_body->MeleeWeaponHandler()->IsActive() && g_vr_body->MeleeWeaponHandler()->IsLaserRapier()) {
                m_gamepad_right_trigger.mute_state(state);
            }
        }

        // TODO
        if (m_gamepad_right_trigger.is_released()) {
            // Set Laser Rapier normal mode
            if (g_vr_body->MeleeWeaponHandler()->IsActive() && g_vr_body->MeleeWeaponHandler()->IsLaserRapier()) {
                m_gamepad_right_trigger.mute_state(state);
            }
        }

        if (m_gamepad_right_trigger.is_pressed() || m_gamepad_right_trigger.is_held()) {
            // don't use consumable on default action trigger
            if (g_vr_body->IsHoldingHandheldConsumable()) {
                m_gamepad_right_trigger.mute_state(state);
            }
        }

        // Left Trigger
        if (m_gamepad_left_trigger.is_pressed()) {
            // attach laser pointer to an empty hand (only if both hands are empty)
            //if (g_vr_body->IsEmptyHanded()) {
            //    g_vr_body->HandInteractionLeft()->AttachLaserPointer(true, 10.f);
            //}
        }

        // Right Shoulder
        if (m_gamepad_right_shoulder.is_pressed()) {
            // try pickup world object
            g_vr_body->HandInteractionRight()->TryGrab();

            // set hand pose: pointing
            if (!g_vr_body->HandInteractionRight()->IsHoldingWeapon()) {
                g_vr_body->HandInteractionRight()->SelectedPose() = E_ENUM_VRHandPose::NewEnumerator3;

                if (g_vr_body->HandInteractionRight()->IsReachingBackpack()) {
                    m_is_pulling_gun_out = true;
                }
            }

            if (g_vr_body->HandInteractionRight()->HeldGrabComponent() == nullptr) {
                // toggle Sensaround gesture
                if (g_vr_body->HandInteractionRight()->IsReachingSocket(UKismetStringLibrary::Conv_StringToName(L"MinimapSocket"), 5.0f)) {
                    m_neural_hud->WIDGET_HardwareButton_Sensaround->ToggleHardware();
                }
                // toggle MFD gesture
                else if (g_vr_body->HandInteractionRight()->IsReachingSocket(UKismetStringLibrary::Conv_StringToName(L"LeftInnerWristSocket"), 7.0f)) {
                    static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_Real_ToggleMFD_K2Node_InputActionEvent_43(FKey{});
                    m_gamepad_right_shoulder.mute_state(state);
                }
            }
        }
        if (m_gamepad_right_shoulder.is_released()) {
            m_is_pulling_gun_out = false;

            // toggle holster gesture
            if (
                g_vr_body->HandInteractionRight()->IsReachingBackpack() &&
                g_vr_body->HandInteractionRight()->IsHoldingWeapon() &&
                g_vr_body->HandInteractionRight()->HeldGrabComponent() == nullptr
                ) {
                // use holster weapon button: holster weapon
                SDK::FKey h_key_name{
                    .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
                };
                g_vr_body->HackerPawn()->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_64(h_key_name);
            }

            // try releasing world object
            g_vr_body->HandInteractionRight()->TryRelease();

            // set undefined hand pose if not holding a weapon
            if (!g_vr_body->HandInteractionRight()->IsHoldingWeapon()) {
                g_vr_body->HandInteractionRight()->SelectedPose() = E_ENUM_VRHandPose::NewEnumerator0;
            }
        }

        // Left Shoulder
        if (m_gamepad_left_shoulder.is_pressed()) {
            // try pickup world object
            g_vr_body->HandInteractionLeft()->TryGrab();

            // set hand pose: pointing
            g_vr_body->HandInteractionLeft()->SelectedPose() = E_ENUM_VRHandPose::NewEnumerator3;

            // toggle energy shield gesture
            if (
                g_vr_body->HandInteractionLeft()->HeldGrabComponent() == nullptr &&
                g_vr_body->HandInteractionLeft()->IsReachingSocket(UKismetStringLibrary::Conv_StringToName(L"RightInnerWristSocket"), 5.0f)
                ) {

                m_neural_hud->WIDGET_HardwareButton_EnergyShield->ToggleHardware();
            }
        }
        if (m_gamepad_left_shoulder.is_released()) {
            // set undefined hand pose
            g_vr_body->HandInteractionLeft()->SelectedPose() = E_ENUM_VRHandPose::NewEnumerator0;

            // toggle holster gesture for held condsumable (Battery Pack)
            if (
                g_vr_body->HandInteractionLeft()->IsReachingBackpack() &&
                g_vr_body->HandInteractionLeft()->HeldItemCategory() == E_ENUM_ItemCategory::NewEnumerator3 && // consumable
                g_vr_body->HandInteractionLeft()->HeldGrabComponent() == nullptr
                ) {
                // use holster weapon button: holster weapon
                SDK::FKey h_key_name{
                    .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
                };
                g_vr_body->HackerPawn()->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_64(h_key_name);
            }

            // toggle VisionUnit gesture
            if (
                g_vr_body->HandInteractionLeft()->IsReachingBackpack() &&
                g_vr_body->HandInteractionLeft()->HeldItemCategory() == E_ENUM_ItemCategory::NewEnumerator4 // None
                ) {
                API::get()->log_warn("[plugin][handle_citadel_station_xinput] Toggle VisionUnit");
                m_neural_hud->WIDGET_HardwareButton_VisionUnit->ToggleHardware();
                //m_is_head_lamp_active.set_value(static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->HeadlampLight->Intensity != 0.0f);
                //apply_head_lamp_settings();
            }

            // try releasing world object
            g_vr_body->HandInteractionLeft()->TryRelease();
        }

        // Left Thumb
        if (m_gamepad_left_thumb.is_pressed()) {
            // Reset height and recenter gesture
            if (g_vr_body->HandInteractionLeft()->IsReachingBackpack()) {
                PluginUtils::reset_height(0.f);
                vr->recenter_view();
            }
        }

        if (m_hotbar_selector_button.is_pressed() && g_vr_body->HandInteractionRight()->IsReachingSocket(UKismetStringLibrary::Conv_StringToName(L"LeftInnerWristSocket"), 7.0f)) {
            SDK::FKey key_name{
                .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"Escape")
            };
            if (PluginUtils::is_a<SDK::APAWN_Hacker_Implant_C>(m_pawn.get())) {
                static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_Locked_Escape_K2Node_InputActionEvent_118(key_name);
            }
        }
        else {
            handle_primary_item_selector(state, vr);
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_citadel_station_xinput] Exception");
    }
}

void UEVRPlugin::handle_smooth_turning(XINPUT_STATE* state) {
    static SDK::AController* pawn_controller{ nullptr };

    try {
        if (
            PluginUtils::is_a<APAWN_Hacker_Simple_C>(m_pawn.get()) ||
            PluginUtils::is_a<APAWN_Avatar_C>(m_pawn.get())
            ) {

            // UEVR's snap turn reads the stick itself. A smooth turn on top would turn the view
            // while the stick moves towards the snap turn deadzone.
            if (API::VR::is_snap_turn_enabled()) {
                state->Gamepad.sThumbRX = 0;
                return;
            }

            pawn_controller = m_pawn.get()->Controller;
            if (!UKismetSystemLibrary::IsValid(pawn_controller)) {
                return;
            }

            auto control_rotation = pawn_controller->GetControlRotation();
            float delta_rotation = (state->Gamepad.sThumbRX / ((11.f - VRSettings::look_sensitivity()) * 2499.0f));
            control_rotation.Yaw += delta_rotation;
            pawn_controller->SetControlRotation(control_rotation);

            if (g_vr_body != nullptr) {
                g_vr_body->TrailingRotationComponent()->K2_AddWorldRotation({ 0.f, delta_rotation, 0.f }, false, &m_reusable_hit_result, false);
            }

            state->Gamepad.sThumbRX = 0;
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_smooth_turning] Exception");
    }
}

// with this, we don't need to manipulate game controller bindings to mute lean button
void UEVRPlugin::handle_lean() {
    if (PluginUtils::is_a<APAWN_Hacker_Simple_C>(m_pawn.get())) {
        // prevent player leaning
        static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->IsTryingToLean = false;
    }
}

// try moving to BP
void UEVRPlugin::update_trailing_rotation(float delta) {
    try {
        // UEVR applied a snap turn to the control rotation while the last frame's view was set
        // up, after that view's rotation was taken. The camera turns in this frame, so the body
        // turns by the same angle now. Taken every tick, so a snap without a VR body is dropped.
        const float snap_yaw = VRSnapTurn::consume_yaw();
        if (g_vr_body == nullptr || m_pawn.get() == nullptr || !PluginUtils::is_a<APAWN_Hacker_Simple_C>(m_pawn.get()))
            return;

        auto pawn_controller = m_pawn.get()->Controller;
        if (!UKismetSystemLibrary::IsValid(pawn_controller)) {
            return;
        }
        auto control_rotation = pawn_controller->GetControlRotation();
        auto tc_rot = g_vr_body->TrailingRotationComponent()->K2_GetComponentRotation();
        tc_rot.Yaw += snap_yaw;

        auto pawn_speed = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->COMP_MoveControlManager->CurrentSpeed;
        auto interp_speed = pow((abs(g_vr_body->VRMovementComponent()->TrailingAngle()) / 25.f), 5.f) + pow(pawn_speed / 100.f, 2.f);

        g_vr_body->TrailingRotationComponent()->K2_SetWorldRotation(
            SDK::UKismetMathLibrary::RInterpTo(
                tc_rot,
                { 0.f, control_rotation.Yaw, 0.f },
                delta,
                interp_speed
            ),
            false, &m_reusable_hit_result, false
        );

        g_vr_body->VRBodyMesh()->K2_SetWorldRotation({ 0.f, g_vr_body->TrailingRotationComponent()->K2_GetComponentRotation().Yaw - 90.f, 0.f }, false, &m_reusable_hit_result, false);
    }
    catch (...) {
        API::get()->log_error("[plugin][update_trailing_rotation] Exception");
    }
}


void UEVRPlugin::handle_game_state_change() {
    try {
        if (m_game_state.has_changed()) {
            API::get()->log_warn("[plugin][handle_game_state_change] New Game State: %s", GameStateName[m_game_state.get()]);
            const UEVR_VRData* vr = API::get()->param()->vr;
            const UEVR_SDKData* sdk = API::get()->sdk();

            // hides UI on the monitor for selected states: it's for recording videos without UI being visible
            if (
                m_game_state.get() == GAME_STATE_CITADEL_STATION ||
                m_game_state.get() == GAME_STATE_INTERACTABLE
                ) {
                set_hacker_ui_visibility(false);
            }
            else {
                set_hacker_ui_visibility(true);
            }

            switch (m_game_state.get()) {
                case GAME_STATE_INTRO_DRONE:
                    sdk->functions->execute_command(L"r.postprocessing.disablematerials 1");
                    vr->set_decoupled_pitch_enabled(true);
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                    API::UObjectHook::set_disabled(false);
                    PluginUtils::reset_height(0.f);
                    PluginUtils::cycle_native_stereo_fix();
                    break;

                case GAME_STATE_INTRO_LAPTOP:
                    vr->set_aim_method(0);
                    vr->set_mod_value("VR_RoomscaleMovement", "false");

                    VRBody::hide_vr_body();
                    VRBody::reset_player_camera();

                    PluginUtils::reset_height(0.0f);
                    API::UObjectHook::set_disabled(true);
                    break;

                case GAME_STATE_MAIN_MENU:
                    vr->set_aim_method(0);
                    vr->set_decoupled_pitch_enabled(false);
                    vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                    vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                    vr->set_mod_value("UI_Distance", "2.000000");
                    vr->set_mod_value("UI_Size", "1.400000");
                    vr->set_mod_value("UI_Y_Offset", "0.00000");
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "false");
                    PluginUtils::reset_height(0.f);
                    vr->recenter_view();
                    API::UObjectHook::set_disabled(true);
                    // changes to game options can be applied in the main menu
                    apply_vr_game_options();
                    //PluginUtils::cycle_native_stereo_fix();
                    break;

                case GAME_STATE_PAUSE_MENU:
                    API::UObjectHook::set_disabled(false);
                    vr->set_aim_method(0);
                    vr->set_decoupled_pitch_enabled(true);
                    vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                    vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                    vr->set_mod_value("UI_Distance", "2.000000");
                    vr->set_mod_value("UI_Size", "1.400000");
                    vr->set_mod_value("UI_Y_Offset", "-0.30000");
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "false");
                    vr->recenter_view();
                    break;

                case GAME_STATE_CITADEL_STATION:
                    sdk->functions->execute_command(L"r.postprocessing.disablematerials 0");
                    if (is_valid_vr_body_hacker_implant_pawn()) {
                        m_is_pulling_gun_out = false;
                        m_pawn.get()->bUseControllerRotationPitch = false;
                        m_pawn.get()->bUseControllerRotationRoll = false;
                        m_pawn.get()->bUseControllerRotationYaw = true;
                        VRBody::show_vr_body();

                        API::UObjectHook::set_disabled(false);
                        vr->set_aim_method(m_default_aim_method);
                        vr->set_decoupled_pitch_enabled(true);
                        vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                        vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                        vr->set_mod_value("UI_Distance", "1.300000");
                        vr->set_mod_value("UI_Size", "1.000000");
                        vr->set_mod_value("UI_Y_Offset", "-0.10000");
                        vr->set_mod_value("VR_RoomscaleMovement", "true");
                        vr->set_mod_value("VR_DecoupledPitchUIAdjust", "false");
                        vr->recenter_view();

                        if (UKismetSystemLibrary::IsValid(m_neural_hud)) {
                            m_neural_hud->PANEL_Hotbar->SetVisibility(ESlateVisibility::Hidden);
                        }
                        VRMFD::hide_mfd(static_cast<ACON_Hacker_C*>(m_pawn.get()->Controller));

                    }
                    break;

                case GAME_STATE_MFD_PRE:
                    vr->set_aim_method(1);
                    // Setting VR_DecoupledPitchUIAdjust causes error if AimMethod 1 wasn't previously used for a couple of ticks
                    // using set_aim_method(1) just before this line is not enough to mitigate this problem.
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "false");
                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    break;

                case GAME_STATE_MFD:
                    char ui_distance[32], ui_size[32];
                    VRMFD::calculate_uevr_ui_params(vr, m_world, ui_distance, ui_size);

                    vr->set_mod_value("VR_RoomscaleMovement", "false");
                    vr->set_mod_value("UI_Distance", ui_distance);
                    vr->set_mod_value("UI_Size", ui_size);
                    vr->set_mod_value("UI_Y_Offset", "0.000000");
                    vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                    vr->set_aim_method(0);

                    if (is_valid_vr_body_hacker_implant_pawn()) {
                        VRMFD::show_mfd();
                    }

                    break;

                case GAME_STATE_INTERACTABLE:
                    if (PluginUtils::is_a<APAWN_Hacker_Implant_C>(m_pawn.get())) {
                        APAWN_Hacker_Implant_C* pawn = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get());
                        API::get()->log_warn("[plugin][handle_game_state_change] Interactable: %s", pawn->ChannelingInteractableName.GetRawString().c_str());
                        if (
                            pawn->ChannelingInteractable != nullptr && (
                                PluginUtils::is_a<AINTERACT_SurgeryMachine_C>(pawn->ChannelingInteractable) ||
                                PluginUtils::is_a<AINTERACT_RespawnChamber_C>(pawn->ChannelingInteractable)
                                )
                           ) {
                            vr->set_aim_method(0);                      // Game mode
                            vr->set_mod_value("VR_RoomscaleMovement", "false");
                            m_camera_reset_wait = 0.f;                  // see handle_deferred_camera_reset
                            VRBody::hide_vr_body();

                            API::UObjectHook::set_disabled(true);
                        }
                    }
                    break;

                case GAME_STATE_CYBERSPACE:
                    if (PluginUtils::is_a<APAWN_Avatar_C>(m_pawn.get())) {
                        //APAWN_Avatar_C* pawn = static_cast<APAWN_Avatar_C*>(m_pawn.get());
                        //VRAvatar::initialize_vr_avatar(pawn);
                        ////g_vr_body->VRBodyMesh()->SetVisibility(true, false);
                        //API::UObjectHook::set_disabled(false);
                        //vr->set_aim_method(0);                      // Game mode
                        //vr->set_decoupled_pitch_enabled(false);
                        //vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                        //vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                        //vr->set_mod_value("UI_Distance", "4.000000");
                        //vr->set_mod_value("UI_Size", "2.000000");
                        //vr->set_mod_value("UI_Y_Offset", "0.00000");
                        //vr->set_mod_value("VR_RoomscaleMovement", "true");
                        //vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                        //vr->set_mod_value("VR_DecoupledPitch", "false");
                        //PluginUtils::reset_height(0.f);
                        //vr->recenter_view();

                        m_pawn.get()->bUseControllerRotationPitch = true;
                        m_pawn.get()->bUseControllerRotationRoll = true;
                        m_pawn.get()->bUseControllerRotationYaw = true;

                        vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                        vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                        vr->set_mod_value("UI_Distance", "4.000000");
                        vr->set_mod_value("UI_Size", "2.000000");
                        vr->set_mod_value("UI_Y_Offset", "0.00000");
                        vr->set_aim_method(2);
                        vr->set_snap_turn_enabled(false);
                        vr->set_decoupled_pitch_enabled(true);
                        vr->set_mod_value("VR_RoomscaleMovement", "false");
                        vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                        vr->recenter_view();

                        API::UObjectHook::set_disabled(true);
                        PluginUtils::reset_height(0.f);
                    }
                    break;

                case GAME_STATE_APPARTMENT:
                    sdk->functions->execute_command(L"r.postprocessing.disablematerials 0");
                    m_intro_laptop = nullptr;
                    if (is_valid_vr_body_hacker_simple_pawn()) {
                        g_vr_body->VRBodyMesh()->SetVisibility(true, false);
                        m_pawn.get()->bUseControllerRotationPitch = false;
                        m_pawn.get()->bUseControllerRotationRoll = false;
                        m_pawn.get()->bUseControllerRotationYaw = true;

                        API::UObjectHook::set_disabled(false);
                        vr->set_aim_method(m_default_aim_method);
                        vr->set_decoupled_pitch_enabled(true);
                        vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                        vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                        vr->set_mod_value("UI_Distance", "2.000000");
                        vr->set_mod_value("UI_Size", "0.000000");
                        vr->set_mod_value("UI_Y_Offset", "0.00000");
                        vr->set_mod_value("VR_RoomscaleMovement", "true");
                        vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                        PluginUtils::reset_height(0.f);
                        vr->recenter_view();
                    }
                    break;

                case GAME_STATE_BOOTING_UP:
                    //if (UKismetSystemLibrary::IsValid(m_neural_hud)) {
                    //    m_neural_hud->SetVisibility(ESlateVisibility::Visible);
                    //}
                    vr->set_aim_method(0);
                    vr->recenter_view();
                    vr->set_mod_value("UI_Distance", "2.000000");
                    vr->set_mod_value("UI_Size", "2.000000");
                    API::UObjectHook::set_disabled(true);
                    VRBody::hide_vr_body();
                    break;

                case GAME_STATE_CRASHING:
                    //if (UKismetSystemLibrary::IsValid(m_neural_hud)) {
                    //    m_neural_hud->SetVisibility(ESlateVisibility::Visible);
                    //}
                    vr->set_aim_method(0);
                    vr->recenter_view();
                    vr->set_mod_value("UI_Distance", "2.000000");
                    vr->set_mod_value("UI_Size", "2.000000");
                    API::UObjectHook::set_disabled(true);
                    VRBody::hide_vr_body();
                    break;

                case GAME_STATE_CINEMATIC:
                    vr->set_aim_method(0);
                    vr->recenter_view();
                    API::UObjectHook::set_disabled(true);
                    break;
            }
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_game_state_change] Exception");
    }
}

// The surgery machine and the respawn chamber move the camera with their animation only while
// PlayerCamera is attached to LookPivot (PAWN_Hacker_Simple::UpdateCameraAnimationOffset). They
// also holster the weapon, and COMP_HackerInventory::OnWeaponHolsterFinished broadcasts
// OnWeaponHolstered, on which the VR body attaches PlayerCamera to the hand again
// (AttachLaserPointer). So the camera goes back to LookPivot only once the holster is over: no
// weapon waits to be holstered and neither hand holds one. Empty-handed that is the first tick.
void UEVRPlugin::handle_deferred_camera_reset(float delta) {
    static constexpr float kTimeoutSeconds = 3.f;
    try {
        if (m_camera_reset_wait < 0.f) return;
        if (m_game_state.get() != GAME_STATE_INTERACTABLE) {
            m_camera_reset_wait = -1.f;
            return;
        }
        m_camera_reset_wait += delta;
        const bool holstering = m_inventory != nullptr && m_inventory->WaitingToHolsterWeapon != nullptr;
        const bool holding = g_vr_body != nullptr && !g_vr_body->IsEmptyHanded();
        const bool timed_out = m_camera_reset_wait >= kTimeoutSeconds;
        if ((holstering || holding) && !timed_out) return;

        VRBody::reset_player_camera();
        API::get()->log_warn("[plugin][handle_deferred_camera_reset] PlayerCamera back on LookPivot after %.2f s%s",
            m_camera_reset_wait, timed_out ? " (timed out waiting for the holster)" : "");
        m_camera_reset_wait = -1.f;
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_deferred_camera_reset] Exception");
        m_camera_reset_wait = -1.f;
    }
}

void UEVRPlugin::handle_level_change() {
    try {
        if (
            (m_level.has_changed() && UKismetSystemLibrary::IsValid(m_level.get())) ||
            (m_pawn_state.has_changed())
        ) {
            API::get()->log_warn("[plugin][handle_level_change] New Level: %s", m_level.get()->GetFullName().c_str());
            API::get()->log_warn("[plugin][handle_level_change] New Pawn State: %s", PawnStateName[m_pawn_state.get()]);
            set_ui_level_name(m_level.get()->GetFullName());

            // A level change may have unloaded and reloaded the mod's Blueprint classes,
            // also from a hot-reloaded pak. Drop every cached class, property and function
            // pointer before anything below, including the cleanup, resolves against them.
            // The warm-up refills them.
            if (m_level.has_changed()) {
                bridge::invalidate();
                PluginUtils::reset_class_checks();
            }

            // The library and the logger class are imported by nothing the game loads. Load
            // them here, on the game thread. A blocking load from on_initialize runs on the
            // render thread and crashes the async loader. The logger lives for the session,
            // so this runs once; a failed attempt is repeated on the next level change.
            if (m_bp_logger == nullptr) {
                load_mod_utility_classes();
                m_bp_logger = create_bp_logger();
            }

            // reset pointers invalidating vr_body
            API::get()->log_warn("[plugin][handle_level_change] Actors / Pointers cleanup");
            cleanup_actors();
            cleanup_pointers();

            // Hacker Implant - Citadel Station (normal space)
            if (
                SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) &&
                PluginUtils::is_a<APAWN_Hacker_Implant_C>(m_pawn.get())
            ) {
                APAWN_Hacker_Implant_C* pawn = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get());
                // cleanup_pointers dropped the HUD pointer and prepare_pointers refills it only
                // next tick. The pawn is already the new one, so ask it now; the checks below need it.
                pawn->GetNeuralHUD(&m_neural_hud);
                if (m_neural_hud == nullptr) {
                    API::get()->log_error("[plugin][handle_level_change] Neural HUD pointer error");
                }
                g_vr_body = VRBody::initialize_vr_body(pawn);
                if (g_vr_body != nullptr) {
                    PluginUtils::warmup_bridge();
                    VRBody::apply_custom_vr_game_options(g_vr_body);
                }

                // modify head lamp settings
                if (m_is_head_lamp_active.get()) {
                    apply_head_lamp_settings();
                }

                if (g_vr_body != nullptr && m_neural_hud != nullptr) {
                    initialize_mcs(pawn);
                    VRBody::initialize_laser_dot();
                    VRBody::overwrite_hacker_crouch_animations();
                    VRBody::initialize_minimap(m_neural_hud);
                    VRBody::initialize_hacker_hardware(m_neural_hud);
                    VRBody::initialize_active_hazard(m_neural_hud);
                    VRBody::initialize_unread_media_icon(m_neural_hud);
                    TutorialMessages::apply_popup_size(m_neural_hud);
                    VRBody::initialize_ads();
                    VRBody::initialize_hand_item_collisions();
                    VRItemSelector::initialize(m_neural_hud);
                    PluginUtils::reset_height(0.f);

                    VRBody::set_debug_widget_visibility(false);
                    //g_vr_body->InteractablesHighlighterLeft()->Activate(true);
                    //g_vr_body->InteractablesHighlighterLeft()->Enable();

                    //PluginUtils::cycle_native_stereo_fix();
                }
                else {
                    API::get()->log_error("[plugin][handle_level_change] Expected valid g_vr_body and neural HUD (vr_body=0x%p hud=0x%p)", g_vr_body, m_neural_hud);
                }
                return;
            }

            // Hacker Simple - Appartment Intro
            if (
                SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) &&
                PluginUtils::is_a<APAWN_Hacker_Simple_C>(m_pawn.get())
                ) {
                APAWN_Hacker_Simple_C* pawn = static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get());
                g_vr_body = VRBody::initialize_vr_body(pawn);

                if (g_vr_body != nullptr) {
                    PluginUtils::warmup_bridge();
                    VRBody::apply_custom_vr_game_options(g_vr_body);
                    VRBody::initialize_laser_dot();
                    VRBody::overwrite_hacker_crouch_animations();
                    VRBody::initialize_hand_item_collisions();
                    PluginUtils::reset_height(0.f);
                    VRBody::set_debug_widget_visibility(false);

                    //PluginUtils::cycle_native_stereo_fix();
                }
                else {
                    API::get()->log_error("[plugin][handle_level_change] Expected valid g_vr_body");
                }
                return;
            }

            //PluginUtils::cycle_native_stereo_fix();
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_level_change] Exception");
    }
}

void UEVRPlugin::handle_media_display() {
    try {
        if (
            ( m_game_state.get() == GAME_STATE_CITADEL_STATION || m_game_state.get() == GAME_STATE_MFD ) &&
            m_is_media_display_visible.has_changed()
            ) {
            VRBody::set_media_display_visibility(m_is_media_display_visible.get());
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_media_display] Exception");
    }
}

// This is also prototyped in _BP_VRBody Event Graph
// try moving to BP
void UEVRPlugin::handle_ads() {
    try {
        if (g_vr_body != nullptr) {
            // With auto ADS off the value drops to false, so an active aim is released once.
            m_is_ads_active.set_value(m_ui_option_auto_ads_enabled && g_vr_body->IsAimingDownSights());

            if (m_is_ads_active.enabled()) {
                if (
                    SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) &&
                    PluginUtils::is_a<APAWN_Hacker_Simple_C>(m_pawn.get())
                    ) {
                        SDK::FKey aim_key{};
                        static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->InpActEvt_Gamepad_Real_Aim_K2Node_InputActionEvent_42(aim_key);
                }
            }

            if (m_is_ads_active.disabled()) {
                if (
                    SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) &&
                    PluginUtils::is_a<APAWN_Hacker_Simple_C>(m_pawn.get())
                    ) {
                        SDK::FKey aim_key{};
                        static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->InpActEvt_Gamepad_Real_Aim_K2Node_InputActionEvent_43(aim_key);
                }
            }
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_ads] Exception");
    }
}

// Applies the values the VR options page saved. Called after the player pressed Apply there.
void UEVRPlugin::apply_vr_options_menu_settings() {
    m_ui_option_auto_ads_enabled = VRSettings::auto_ads();
    VRBody::apply_custom_vr_game_options(g_vr_body);
}

// primary item selector
void UEVRPlugin::handle_primary_item_selector(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        if (g_vr_body == nullptr) {
            API::get()->log_error("[plugin][handle_primary_item_selector] vr_body nullptr");
            return;
        }

        if (m_hotbar_selector_button.is_pressed()) {
            VRItemSelector::set_visibility(true);

            VRBody::set_weapon_mesh_visibility(false);
            // hide UEVR controlled HUD
            //vr->set_mod_value("UI_Size", "0.000000");
            vr->set_mod_value("VR_RoomscaleMovement", "false");
            vr->set_aim_method(0);

            // show VR item selector
            g_vr_body->ItemSelectorRight()->Show(20.f);

            // we will ignore Player mesh collisions on the channel that WidgetInteractionComponent uses
            // for the time the selector is active
            //VRBody::set_player_response_to_collision_channel(
            //    static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get()),
            //    g_vr_body,
            //    item_selector_collision_channel,
            //    SDK::ECollisionResponse::ECR_Ignore
            //);
            VRItemSelector::unselect_all_hotbar_slots(m_neural_hud);

            if (m_is_head_lamp_active.value) {
                set_head_lamp_brightness(1.f);
            }
        }

        if (m_hotbar_selector_button.is_released()) {
            VRItemSelector::activate_current_quick_slot();

            // restore collisions
            //g_vr_body->set_player_response_to_collision_channel(
            //    item_selector_collision_channel, SDK::ECollisionResponse::ECR_Block
            //);
            VRItemSelector::set_visibility(false);
            VRBody::set_weapon_mesh_visibility(true);
            ////g_vr_body->set_laser_pointer_visibility(false);
            g_vr_body->ItemSelectorRight()->Hide();

            vr->set_mod_value("VR_RoomscaleMovement", "true");
            vr->set_aim_method(m_default_aim_method);

            if (m_is_head_lamp_active.value) {
                set_head_lamp_brightness(4000.f);
            }
        }

        // state, when the item selector is shown
        if (m_hotbar_selector_button.is_held()) {
            //API::get()->log_warn("[plugin][handle_primary_item_selector] Grip Held Begin");
            //g_vr_body->update_laser_pointer_length(35.f);
            VRItemSelector::set_current_quick_slot();

            state->Gamepad.sThumbRX = 0;
        }

        m_hotbar_selector_button.mute_state(state);
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_primary_item_selector] Exception");
    }
}

void UEVRPlugin::handle_mfd_interactions(XINPUT_STATE* state, const UEVR_VRData* vr) {
    static FVector2D cursor_pos{ 0.f, 0.f };
    try {
        if (g_vr_body == nullptr) {
            API::get()->log_error("[plugin][handle_mfd_interactions] vr_body nullptr");
            return;
        }

        auto ctrl = (SDK::ACON_Hacker_C*)m_pawn.get()->Controller;
        ctrl->SetIsUsingGamepad(false);

        // mute controller A, Y buttons
        m_gamepad_btn_a.mute_state(state);
        m_gamepad_btn_b.mute_state(state);
        //m_gamepad_btn_x.mute_state(state);
        m_gamepad_btn_y.mute_state(state);

        m_gamepad_right_trigger.mute_state(state);
        m_gamepad_right_shoulder.mute_state(state);

        // scroll up
        if (state->Gamepad.sThumbRY > INPUT_DEADZONE_HI && m_mouse_wheel_debounce_timer > MOUSE_WHEEL_DEBOUNCE_TIME) {
            PluginUtils::send_mouse(0x0A, false);
            m_mouse_wheel_debounce_timer = 0.f;
        }
        // scroll down
        if (state->Gamepad.sThumbRY < -INPUT_DEADZONE_HI && m_mouse_wheel_debounce_timer > MOUSE_WHEEL_DEBOUNCE_TIME) {
            PluginUtils::send_mouse(0x0B, false);
            m_mouse_wheel_debounce_timer = 0.f;
        }
        // mute sticks that move cursor
        state->Gamepad.sThumbRX = 0;
        state->Gamepad.sThumbRY = 0;

        if (m_gamepad_right_trigger.is_pressed()) {
            PluginUtils::send_mouse(VK_LBUTTON, false);
        }

        if (m_gamepad_right_trigger.is_released()) {
            PluginUtils::send_mouse(VK_LBUTTON, true);
        }

        if (m_gamepad_right_shoulder.is_pressed()) {
            PluginUtils::send_mouse(VK_RBUTTON, false);
        }

        if (m_gamepad_right_shoulder.is_released()) {
            PluginUtils::send_mouse(VK_RBUTTON, true);
        }

        ctrl->SetIsUsingGamepad(false);
        if (g_vr_body->WidgetInteractionRight()->HoveredWidgetComponent != nullptr) {
            cursor_pos = g_vr_body->WidgetInteractionRight()->Get2DHitLocation();
        }
        else {
            cursor_pos = { 0.f, 0.f };
        }
        if (cursor_pos.X != 0 && cursor_pos.Y != 0) {
            ctrl->SetMouseLocation((int32)cursor_pos.X, (int32)cursor_pos.Y);
        }

        //m_vr_hud->update_laser_pointer_length(100.f);
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_mfd_interactions] Exception");
    }
}

void UEVRPlugin::cleanup_pointers() {
    try {
        API::get()->log_warn("[plugin][cleanup] Starting Pointers Cleanup");
        if (g_vr_body != nullptr) {
            g_vr_body = nullptr;
        }
        // The HUD dies with the level; prepare_pointers finds the next one.
        m_neural_hud = nullptr;
        VROptionsMenu::reset();
    }
    catch (...) {
        API::get()->log_error("[plugin][cleanup_pointers] Exception");
    }
}

void UEVRPlugin::cleanup_actors() {
    try {
        API::get()->log_warn("[plugin][cleanup_actors] Starting Actors Cleanup");
        g_vr_body = nullptr;

        // Needs no world, and must run on every level change so the next garbage
        // collection can free the mod's widget classes (see documentation/pak-hot-reload.md).
        PluginUtils::release_game_panels_from_mod_widgets();

        auto world = SdkBootstrap::get_world();
        if (!UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_error("[plugin][cleanup_actors] Invalid World");
            return;
        }

        // Both mod actors are found by tag. A class lookup would throw when the class is
        // not loaded, which is the normal state after a trip through the title screen.
        PluginUtils::destroy_actors_by_tag(world, UKismetStringLibrary::Conv_StringToName(L"VRModActor"));
        PluginUtils::destroy_actors_by_tag(world, UKismetStringLibrary::Conv_StringToName(L"VRAvatarActor"));
    }
    catch (...) {
        API::get()->log_error("[plugin][cleanup_actors] Exception");
    }
}


// -------------------------------------------------------------------------------------
// ImGui
//
// The mod draws its own window, in its own ImGui context, next to the UEVR overlay. UEVR
// calls on_present and then on_post_render_vr_framework_* inside its present hook, on the
// render thread. The first builds the frame and draws it on the desktop back buffer; the
// second draws the same frame onto the render target UEVR shows in the headset, which is
// what makes the window visible in VR. on_device_reset runs on that thread too. on_message
// runs on the game's window thread, so m_imgui_mutex keeps its input events out of a frame
// being built.
//
// The window never touches game objects. It only shows values the game thread cached.
// -------------------------------------------------------------------------------------
namespace {

constexpr float kUiWindowWidth = 500.0f;
constexpr float kUiWindowHeight = 500.0f;

template <class Key>
const char* name_of(const std::map<Key, const char*>& names, Key key) {
    const auto it = names.find(key);
    return it != names.end() && it->second != nullptr ? it->second : "?";
}

} // namespace

void UEVRPlugin::create_imgui_context() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    static const auto imgui_ini = API::get()->get_persistent_dir(L"system_reshock_vr_imgui.ini").string();
    ImGui::GetIO().IniFilename = imgui_ini.c_str();
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
}

// Context and Win32 backend are made once. The renderer backend is made here and again
// after every device reset.
bool UEVRPlugin::initialize_imgui() {
    if (m_imgui_initialized) return true;
    if (ImGui::GetCurrentContext() == nullptr) create_imgui_context();

    const auto renderer = API::get()->param()->renderer;
    m_renderer_type = renderer->renderer_type;
    if (ImGui::GetIO().BackendPlatformUserData == nullptr) {
        DXGI_SWAP_CHAIN_DESC swap_desc{};
        static_cast<IDXGISwapChain*>(renderer->swapchain)->GetDesc(&swap_desc);
        m_wnd = swap_desc.OutputWindow;
        if (!ImGui_ImplWin32_Init(m_wnd)) {
            API::get()->log_error("[plugin][initialize_imgui] ImGui_ImplWin32_Init failed");
            return false;
        }
    }

    const bool renderer_ok = m_renderer_type == UEVR_RENDERER_D3D11 ? g_d3d11.initialize()
        : m_renderer_type == UEVR_RENDERER_D3D12 ? g_d3d12.initialize() : false;
    if (!renderer_ok) {
        API::get()->log_error("[plugin][initialize_imgui] renderer backend failed, type %d", m_renderer_type);
        return false;
    }
    m_imgui_initialized = true;
    API::get()->log_warn("[plugin][initialize_imgui] ImGui ready, renderer type %d, window 0x%p", m_renderer_type, m_wnd);
    return true;
}

// Releases the renderer backend and its device objects. The context and the Win32 backend
// stay, so a device reset only costs a renderer re-init on the next present. Checks the
// backend before calling Shutdown: ImGui's own check is an assert that is off in Release.
void UEVRPlugin::shutdown_renderer_backend() {
    if (ImGui::GetIO().BackendRendererUserData != nullptr) {
        if (m_renderer_type == UEVR_RENDERER_D3D11) ImGui_ImplDX11_Shutdown();
        else if (m_renderer_type == UEVR_RENDERER_D3D12) ImGui_ImplDX12_Shutdown();
    }
    g_d3d11 = {};
    g_d3d12 = {};
    m_imgui_initialized = false;
}

// Called from the destructor, so it must not use the UEVR API: that instance may be gone.
void UEVRPlugin::shutdown_imgui() {
    try {
        std::unique_lock lock(m_imgui_mutex);
        if (ImGui::GetCurrentContext() == nullptr) return;
        shutdown_renderer_backend();
        if (ImGui::GetIO().BackendPlatformUserData != nullptr) ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();
    }
    catch (...) {
    }
}

void UEVRPlugin::on_device_reset() {
    std::unique_lock lock(m_imgui_mutex);
    if (!m_imgui_initialized) return;
    shutdown_renderer_backend();
    API::get()->log_warn("[plugin][on_device_reset] ImGui renderer backend released, re-created on the next present");
}

// Window thread. Returning false keeps the message from the game, which is wanted only
// while the overlay is open and the mouse or keyboard is over the mod's window.
bool UEVRPlugin::on_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    std::unique_lock lock(m_imgui_mutex);
    if (ImGui::GetCurrentContext() == nullptr || ImGui::GetIO().BackendPlatformUserData == nullptr) return true;
    ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);
    if (!API::get()->param()->functions->is_drawing_ui()) return true;
    const ImGuiIO& io = ImGui::GetIO();
    return !io.WantCaptureMouse && !io.WantCaptureKeyboard;
}

void UEVRPlugin::begin_imgui_frame() {
    if (m_renderer_type == UEVR_RENDERER_D3D11) ImGui_ImplDX11_NewFrame();
    else ImGui_ImplDX12_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
}

void UEVRPlugin::on_present() {
    static bool logged = false;
    try {
        std::unique_lock lock(m_imgui_mutex);
        if (!m_imgui_initialized && !initialize_imgui()) return;
        if (m_renderer_type == UEVR_RENDERER_D3D12 && API::get()->param()->renderer->command_queue == nullptr) return;

        begin_imgui_frame();
        internal_frame();
        ImGui::Render();
        if (m_renderer_type == UEVR_RENDERER_D3D11) g_d3d11.render_imgui();
        else g_d3d12.render_imgui();
    }
    catch (...) {
        if (!logged) {
            logged = true;
            API::get()->log_error("[plugin][on_present] Exception (logged once)");
        }
    }
}

void UEVRPlugin::on_post_render_vr_framework_dx11(ID3D11DeviceContext* context, ID3D11Texture2D*, ID3D11RenderTargetView* rtv) {
    if (!m_imgui_initialized || !API::get()->param()->vr->is_hmd_active()) return;
    std::unique_lock lock(m_imgui_mutex);
    g_d3d11.render_imgui_vr(context, rtv);
}

void UEVRPlugin::on_post_render_vr_framework_dx12(ID3D12GraphicsCommandList* command_list, ID3D12Resource*, D3D12_CPU_DESCRIPTOR_HANDLE* rtv) {
    if (!m_imgui_initialized || !API::get()->param()->vr->is_hmd_active()) return;
    std::unique_lock lock(m_imgui_mutex);
    g_d3d12.render_imgui_vr(command_list, rtv);
}

// The mod's window. Shown only while the UEVR overlay is open.
void UEVRPlugin::internal_frame() {
    ImGuiIO& io = ImGui::GetIO();
    const bool drawing_ui = API::get()->param()->functions->is_drawing_ui();
    // UEVR draws its software cursor before it hands the VR render target to this plugin,
    // so the mod's window would cover it. While the mouse is over the window, this context
    // draws its own cursor on top instead; elsewhere UEVR's cursor stays the only one.
    io.MouseDrawCursor = drawing_ui && io.WantCaptureMouse;
    if (!drawing_ui) return;

    ImGui::SetNextWindowSize(ImVec2(kUiWindowWidth, kUiWindowHeight), ImGuiCond_Once);
    // Title: "System Shock UEVR plugin 2.0-beta.3 [45]", version and build index from build_version.hpp.
    static const std::string window_title = std::string("System Shock UEVR plugin ") + BuildVersion::text();
    if (ImGui::Begin(window_title.c_str())) {
        if (m_pawn.get() == nullptr) {
            ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), "No pawn. Is the HMD running?");
        }
        else {
            draw_debug_section();
        }
    }
    ImGui::End();
}

void UEVRPlugin::draw_debug_section() {
    ImGui::SeparatorText("Debugging");
    ImGui::Checkbox("Show debug", &m_ui_option_show_debug_view);
    if (!m_ui_option_show_debug_view) return;

    ImGui::Text("Game state: %s", name_of(GameStateName, m_game_state.get()));
    ImGui::Text("Pawn state: %s", name_of(PawnStateName, m_pawn_state.get()));
    ImGui::Text("Level: %s", m_ui_level_name.c_str());

    ImGui::SeparatorText("Timers [microseconds]");
    ImGui::Text("XInput: %d", m_ui_xinput_duration);
    ImGui::Text("Pre engine tick: %d", m_ui_pre_engine_tick_duration);
}

void UEVRPlugin::set_ui_level_name(const std::string& name) {
    std::unique_lock lock(m_imgui_mutex);
    m_ui_level_name = name;
}

// sends mouse inputs to OS (thanks markmon)


bool UEVRPlugin::is_valid_vr_body_hacker_implant_pawn() {
    if (g_vr_body == nullptr) {
        API::get()->log_error("[plugin][is_valid_hacker_pawn] Invalid g_vr_body");
        return false;
    }

    if (m_pawn.get() == nullptr || !PluginUtils::is_a<APAWN_Hacker_Implant_C>(m_pawn.get())) {
        API::get()->log_error("[plugin][is_valid_hacker_pawn] Invalid pawn");
        return false;
    }

    return true;
}


bool UEVRPlugin::is_valid_vr_body_hacker_simple_pawn() {
    if (g_vr_body == nullptr) {
        API::get()->log_error("[plugin][is_valid_hacker_pawn] Invalid g_vr_body");
        return false;
    }

    if (m_pawn.get() == nullptr || !PluginUtils::is_a<APAWN_Hacker_Simple_C>(m_pawn.get())) {
        API::get()->log_error("[plugin][is_valid_hacker_pawn] Invalid pawn");
        return false;
    }

    return true;
}


// VRBody asset already has motion controller components defined, but for some reason creatng one here
// and overwriting the one from UE asset, makes the hand lag less (it probably changes the order and moment of evaluating MCs transform relative to AnimBP tick)
// I'm only doing it for the right controller rn
void UEVRPlugin::initialize_mcs(APAWN_Hacker_Implant_C* pawn) {
    try {
        const SDK::FVector pawn_location = pawn->K2_GetActorLocation();
        SDK::FTransform transform{};
        transform.Rotation = { 0.f, 0.f, 0.f, 1.f };
        transform.Translation = { pawn_location.X, pawn_location.Y, pawn_location.Z };
        transform.Scale3D = { 1.f, 1.f, 1.f };


        // --------------------------------------------------------------------
        // Right Hand
        // - Actor
        // - Motion Controller
        // - Widget Interaction Component
        // - Laser Pointer for Item Selector and MFD (Capsule Component)
        // - Minimap
        // - Vital Bars
        // - Media Display
        // - TargetID
        // --------------------------------------------------------------------

        auto world = SdkBootstrap::get_world();
        if (m_world == nullptr) {
            API::get()->log_error("[plugin][initialize_mcs] World pointer error");
            return;
        }

        // actor
        m_right_hand_actor = PluginUtils::spawn_actor(world, transform, L"VRModActor");
        if (m_right_hand_actor == nullptr) {
            API::get()->log_error("[plugin][initialize_mcs] RH Actor error");
            return;
        }

        // motion controller component
        m_rh_controller_component = static_cast<SDK::UMotionControllerComponent*>(
            m_right_hand_actor->AddComponentByClass(
                SDK::UMotionControllerComponent::StaticClass(), false, transform, false
            )
            );
        if (m_rh_controller_component == nullptr) {
            API::get()->log_error("[plugin][initialize_mcs] RH Controller error");
            return;
        }

        m_rh_controller_component->MotionSource = SDK::UKismetStringLibrary::Conv_StringToName(L"Right");
        m_rh_controller_component->Hand = SDK::EControllerHand::Right;
        m_right_hand_actor->FinishAddComponent(m_rh_controller_component, false, transform);

        m_rh_controller_component->K2_AttachToComponent(
            pawn->K2_GetRootComponent(),
            UKismetStringLibrary::Conv_StringToName(L"None"),
            EAttachmentRule::SnapToTarget,
            EAttachmentRule::KeepWorld,
            EAttachmentRule::KeepWorld,
            true
        );

        g_vr_body->WristOffsetRight()->K2_AttachToComponent(
            m_rh_controller_component,
            UKismetStringLibrary::Conv_StringToName(L"None"),
            EAttachmentRule::KeepRelative,
            EAttachmentRule::KeepRelative,
            EAttachmentRule::KeepRelative,
            true
        );
        API::get()->log_warn("[plugin][initialize_mcs] Initialized MCs");
    }
    catch (...) {
        API::get()->log_error("[plugin][cleanup_actors] Exception");
    }
}

void UEVRPlugin::set_hacker_ui_visibility(bool visible) {
    try {
        if (
            UKismetSystemLibrary::IsValid(m_pawn.get()) &&
            PluginUtils::is_a<APAWN_Hacker_Implant_C>(m_pawn.get()) &&
            UKismetSystemLibrary::IsValid(m_neural_hud)
            ) {
            m_neural_hud->SetVisibility(ESlateVisibility::Visible);
            //m_neural_hud->PANEL_GameHUD->SetVisibility(visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden); 
            m_neural_hud->ShowCrosshairs(false);
            m_neural_hud->WIDGET_CrosshairCursor->MESH_Brackets->SetRenderOpacity(visible ? 1.f : 0.f);
            m_neural_hud->WIDGET_CrosshairCursor->MESH_Brackets->SetColor(visible ? FColor{1, 1, 1, 1} : FColor{ 0, 0, 0, 0 });
            m_neural_hud->PANEL_LeftHardware->SetVisibility(visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
            m_neural_hud->PANEL_RightHardware->SetVisibility(visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
            //m_neural_hud->PANEL_Hotbar->SetVisibility(ESlateVisibility::Hidden);
            m_neural_hud->WIDGET_Compass->SetVisibility(ESlateVisibility::Hidden);
            m_neural_hud->MESH_Dashboard->SetVisibility(SDK::ESlateVisibility::Hidden);
            m_neural_hud->MESH_DashboardBottom->SetVisibility(SDK::ESlateVisibility::Hidden);
            //m_neural_hud->PANEL_Notification->SetVisibility(ESlateVisibility::Visible);

        }
    }
    catch (...) {
        API::get()->log_error("[plugin][set_game_ui_visibility] Exception");
    }
}

void UEVRPlugin::try_melee() {
    static UAnimMontage* montage{ nullptr };
    try {
        if (g_vr_body != nullptr && g_vr_body->MeleeWeaponHandler() != nullptr) {
            m_UEVR_process_damage.set_value(g_vr_body->MeleeWeaponHandler()->UEVRProcessDamage());

            if (m_UEVR_process_damage.enabled()) {
                API::get()->log_warn("[plugin][try_melee] Process Montage");

                if (g_vr_body->IsTwoHandingWeapon()) {
                    //API::get()->log_warn("[plugin][try_melee] Two handed swing");
                    g_vr_body->MeleeWeaponHandler()->WeaponItemRef()->GetPowerSwingToIdleMontage(ENUM_LeftRightCenter::NewEnumerator0, &montage);
                }
                else {
                    g_vr_body->MeleeWeaponHandler()->WeaponItemRef()->GetRandomFastAttack(&montage);
                }

                if (!UKismetSystemLibrary::IsValid(montage)) {
                    API::get()->log_error("[plugin][try_melee] Invalid Montage");
                    return;
                }

                bool hit{ true };
                bool result{ true };
                bool is_finished{ false };

                // haptics
                const UEVR_PluginInitializeParam* param = API::get()->param();
                const UEVR_VRData* VR = param->vr;
                UEVR_InputSourceHandle RightController = VR->get_right_joystick_source();
                VR->trigger_haptic_vibration(0.0f, 0.1f, 1.0f, 1.0f, RightController);


                SDK::UCharacterAction_C* action{};
                auto action_manager = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->COMP_ActionManager;
                //melee_weapon->EnableDamage(&result);
                // force action, high priority
                action_manager->ForceBeginAction(montage, ENUM_ActionPriority::NewEnumerator2, &action);
                action->SetElapsedTime(0.5f, &is_finished);
                // drains player stamina
                g_vr_body->MeleeWeaponHandler()->WeaponItemRef()->OnStartedMeleeAttack(false);

                // applies damage
                // this call can also apply stamina drain mod (test it)

                // force power swing by setting IsBeserk to true, then reset it to prev value
                //prev_is_beserk = melee_weapon->IsBerserk;

                g_vr_body->MeleeWeaponHandler()->WeaponItemRef()->TryDealDamageFromHitResult(g_vr_body->MeleeWeaponHandler()->ReusableOutHit(), &hit);
                //melee_weapon->IsBerserk = prev_is_beserk;

                action->StopMontage(0.2f);
                //action_manager->UpdateActiveAction(1.f);

                g_vr_body->MeleeWeaponHandler()->WeaponItemRef()->DisableDamage(&result);
                g_vr_body->MeleeWeaponHandler()->WeaponItemRef()->HitActors.Clear();
                bool end_action_result{ false };

                action_manager->ForceEndCurrentAction(nullptr, 0.2f);
                g_vr_body->MeleeWeaponHandler()->WeaponItemRef()->DisableDamage(&result);

                if (g_vr_body->MeleeWeaponHandler()->IsLaserRapier()) {
                    g_vr_body->MeleeWeaponHandler()->TryUpdateLaserPowerLevel(0.2f);
                }
            }
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][try_melee] Exception");
    }
}

void UEVRPlugin::apply_vr_game_options() {
    auto class_ptr = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Blueprints/UI/HUD/Widgets/Settings/SAVE_Settings.SAVE_Settings_C");
    if (class_ptr != nullptr) {
        SDK::USAVE_Settings_C* settings = class_ptr->get_first_object_matching<SDK::USAVE_Settings_C>();

        if (settings != nullptr && PluginUtils::is_a<SDK::USAVE_Settings_C>(settings)) {
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
            settings->SetFOV(120.f, true);
            settings->ApplyFOV(120.f, true);
            settings->SetFOV(120.f, false);
            settings->ApplyFOV(120.f, false);

            API::get()->log_warn("[plugin][apply_vr_game_options] Applied VR specific game options");
        }
        else {
            API::get()->log_error("[plugin][apply_vr_game_options] Could not apply VR specific game options");
        }
    }
    else {
        API::get()->log_error("[plugin][apply_vr_game_options] Could not apply VR specific game options : missing class");
    }
}

void UEVRPlugin::try_set_intro_laptop_pointer() {
    try {
        if (m_intro_laptop != nullptr)
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
    catch (...) {
        API::get()->log_error("[plugin][set_intro_laptop_pointer] Exception");
    }
}

void UEVRPlugin::handle_cyberspace_look_pivot(const UEVR_VRData* vr) {
    try {
        if (m_pawn_state.matches_none({ PAWN_AVATAR })) {
            return;
        }
        // hide arrow component gizmo
        if (SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) && PluginUtils::is_a<SDK::APAWN_Avatar_C>(m_pawn.get())) {
            static_cast<SDK::APAWN_Avatar_C*>(m_pawn.get())->Arrow1->SetVisibility(false, true);
        }

        // the rest is disabled
        return;

        auto pawn_controller = m_pawn.get()->Controller;
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
    catch (...) {
        API::get()->log_error("[plugin][handle_cyberspace_look_pivot] Exception");
    }
}

void UEVRPlugin::handle_crouch() {
    try {
        if (m_is_crouching.has_changed()) {
            if (UKismetSystemLibrary::IsValid(g_vr_body)) {
                g_vr_body->VRMovementComponent()->SetCrouch(m_is_crouching.value);
            }
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][character_crouch] Exception");
    }
}

void UEVRPlugin::handle_head_lamp() {
    if (m_is_head_lamp_active.enabled()) {
        apply_head_lamp_settings();
    }
}

void UEVRPlugin::set_head_lamp_brightness(float value) {
    if (SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) && PluginUtils::is_a<SDK::APAWN_Hacker_Implant_C>(m_pawn.get())) {
        SDK::USpotLightComponent* head_lamp_light = static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->HeadlampLight;
        if (!SDK::UKismetSystemLibrary::IsValid(head_lamp_light)) {
            API::get()->log_error("[plugin][set_head_lamp_brightness] Invalid Headlight object");
            return;
        }
        head_lamp_light->SetAttenuationRadius(value);
    }
}

void UEVRPlugin::apply_head_lamp_settings() {
    if (SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) && PluginUtils::is_a<SDK::APAWN_Hacker_Implant_C>(m_pawn.get())) {
        API::get()->log_warn("[plugin][apply_head_lamp_settings] Begin");
        SDK::UITEM_Base_C* inventory_item{ nullptr };
        SDK::UHARDWARE_HeadLamp_C* head_lamp{ nullptr };

        m_inventory->FindItem(SDK::UHARDWARE_HeadLamp_C::StaticClass(), false, false, &inventory_item);
        if (SDK::UKismetSystemLibrary::IsValid(inventory_item) && PluginUtils::is_a<SDK::UHARDWARE_HeadLamp_C>(inventory_item)) {
            head_lamp = (SDK::UHARDWARE_HeadLamp_C*)inventory_item;
            API::get()->log_warn("[plugin][apply_head_lamp_settings] Headlight found");
        }
        else {
            head_lamp = nullptr;
        }

        SDK::USpotLightComponent* head_lamp_light = static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->HeadlampLight;
        if (!SDK::UKismetSystemLibrary::IsValid(head_lamp_light)) {
            API::get()->log_error("[plugin][apply_head_lamp_settings] Invalid Headlight object");
            return;
        }
        head_lamp_light->SetInnerConeAngle(2.f);
        head_lamp_light->SetOuterConeAngle(12.f);

        if (head_lamp != nullptr) {
            head_lamp->EnergyDrainModData.Value = 0.1f;
        }
        head_lamp_light->bUseInverseSquaredFalloff = false;
        head_lamp_light->SetIntensity(5.f);
        head_lamp_light->SetAttenuationRadius(4000.f);
        head_lamp_light->SetLightFunctionFadeDistance(0.f);
        head_lamp_light->SetLightFalloffExponent(10.f);
        head_lamp_light->SetVolumetricScatteringIntensity(0.1f);
        head_lamp_light->SetCastShadows(true);

        API::get()->log_warn("[plugin][apply_head_lamp_settings] Applied Headlight parameters");
    }
}