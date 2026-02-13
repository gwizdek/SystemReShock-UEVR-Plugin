
#include "SDK/PAWN_PlayerGhost_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/WIDGET_SimpleHUD_classes.hpp"
#include "SDK/WIDGET_CyberspaceHUD_classes.hpp"
#include "SDK/WIDGET_MainMenu_InGame_classes.hpp"
#include "SDK/CinematicCamera_classes.hpp"
#include "SDK/CON_Hacker_classes.hpp"
#include "SDK/MOVECONTROL_FocusableInteract_classes.hpp"
#include "SDK/MOVECONTROL_StationMove_classes.hpp"
#include "SDK/COMP_MoveControlManager_classes.hpp"

#include "SDK/_BP_LaserDot_classes.hpp"
#include "SDK/_BP_ItemSelector_classes.hpp"
#include "SDK/_BP_MFDMaskComponent_classes.hpp"

#include "plugin.hpp"
#include "plugin_utils.hpp"
#include "vr_body.hpp"
#include "vr_item_selector.hpp"
#include "vr_mfd.hpp"

using namespace uevr;
using namespace SDK;

std::unique_ptr<UEVRPlugin> g_plugin = std::make_unique<UEVRPlugin>();

// -------------------------------------------------------------------------------------
// UEVR Overrides
// -------------------------------------------------------------------------------------
void UEVRPlugin::on_initialize() {
    PLUGIN_LOG_ONCE("Plugin Initializing...");

    //API::get()->log_warn("[plugin][cleanup] Starting Actors Cleanup");
    //VRBody::cleanup_actors();

    // disable player focus (camera pull) on interactable objects like vending machines / keyboards
    auto move_control = SDK::UMOVECONTROL_FocusableInteract_C::GetDefaultObj();
    if (move_control != nullptr) {
        move_control->ShouldUseCharacterMovement = true;
        move_control->IsFinishedTransitioning = true;
    }

    // disable move control on doors / power stations
    auto station_move_control = SDK::UMOVECONTROL_StationMove_C::GetDefaultObj();
    if (station_move_control != nullptr) {
        station_move_control->ExpireNextTick = true;
    }
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
        handle_xinput(state, vr);

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
        }
        else {
            // reset for next cb iteration
            m_xinput_cb_processed = false;
        }

        handle_level_change();
        handle_game_state_change();
        
        //if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
        //    try_running_test_1();
        //    try_running_test_2();
        //}

        // calculate cb duration
        if (m_ui_option_show_debug_view && m_cb_calls_count == 0) {
            std::chrono::steady_clock::time_point end_time = std::chrono::steady_clock::now();
            m_ui_xinput_duration = static_cast<int>(std::chrono::duration_cast<std::chrono::microseconds>(end_time - begin_time).count());
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
        m_world = UWorld::GetWorld();
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

        if (m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())) {
            m_inventory = static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->COMP_HackerInventory;
            UCOMP_MoveControlManager_C* mcm = static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->COMP_MoveControlManager;
            if (mcm != nullptr) {
                m_is_crouching.set_value(mcm->IsTryingToCrouch);
            }
            else {
                m_is_crouching.set_value(false);
            }
        }

        if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
            static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->GetNeuralHUD(&m_neural_hud);
            if (m_neural_hud == nullptr) {
                API::get()->log_error("[plugin][prepare_pointers] Neural HUD pointer error");
                return false;
            }
        }

        // level
        m_level.set_value(m_world != nullptr ? m_world->PersistentLevel : nullptr);

        //if (!SDK::UKismetSystemLibrary::IsValid(g_vr_body)) {
        //    API::get()->log_error("[plugin][prepare_pointers] VR_Body pointer error");
        //    return false;
        //}
    }
    catch (...) {
        API::get()->log_error("[plugin][prepare_pointers] Exception");
        return false;
    }
    return true;
}

void UEVRPlugin::prepare_game_state() {
    static UWIDGET_MainMenu_InGame_C* main_menu{ nullptr };
    static APlayerCameraManager* player_camera_manager{ nullptr };
    //API::get()->log_error("[plugin][prepare_game_state] Start");
    try {
        if (m_world == nullptr) {
            m_game_state.set_value(GAME_STATE_UNDEFINED);
            return;
        }

        if (!UKismetSystemLibrary::IsValid(m_pawn.get())) {
            m_game_state.set_value(GAME_STATE_UNDEFINED);
            return;
        }

        // TODO: here we should detect Intro Drone flight (uses APAWN_PlayerGhost_C)

        // GAME_STATE_MAIN_MENU,
        if (m_pawn.get()->IsA(APAWN_PlayerGhost_C::StaticClass())) {
            m_game_state.set_value(GAME_STATE_MAIN_MENU);
            return;
        }

        // GAME_STATE_PAUSE_MENU
        if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
            static_cast<UWIDGET_PlayerHUD_C*>(static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->PlayerHUDWidget)->GetMainMenuWidget(&main_menu);
            if (main_menu != nullptr && main_menu->IsMainMenuEnabled) {
                m_game_state.set_value(GAME_STATE_PAUSE_MENU);
                return;
            }
        }
        else if (m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())) {
            static_cast<UWIDGET_SimpleHUD_C*>(static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->PlayerHUDWidget)->GetMainMenuWidget(&main_menu);
            if (main_menu != nullptr && main_menu->IsMainMenuEnabled) {
                m_game_state.set_value(GAME_STATE_PAUSE_MENU);
                return;
            }
        }
        else if (m_pawn.get()->IsA(APAWN_Avatar_C::StaticClass())) {
            static_cast<UWIDGET_CyberspaceHUD_C*>(static_cast<APAWN_Avatar_C*>(m_pawn.get())->CyberspaceUI)->GetMainMenuWidget(&main_menu);
            if (main_menu != nullptr && main_menu->IsMainMenuEnabled) {
                m_game_state.set_value(GAME_STATE_PAUSE_MENU);
                return;
            }
        }
        // TODO: add pseudospace pause menu

        // GAME_STATE_CINEMATIC
        player_camera_manager = UGameplayStatics::GetPlayerCameraManager(m_world, 0);
        if (player_camera_manager != nullptr) {
            if (
                UKismetSystemLibrary::IsValid(player_camera_manager->ViewTarget.Target) &&
                player_camera_manager->ViewTarget.Target->IsA(ACineCameraActor::StaticClass())
                ) {
                m_game_state.set_value(GAME_STATE_CINEMATIC);
                return;
            }
        }

        // GAME_STATE_MFD
        if (m_neural_hud != nullptr && m_neural_hud->bIsMFDVisible) {
            if (m_game_state.matches_none({ GAME_STATE_MFD, GAME_STATE_MFD_PRE })) {
                m_game_state.set_value(GAME_STATE_MFD_PRE);
            }
            else {
                m_game_state.set_value(GAME_STATE_MFD);
            }
            return;
        }

        // GAME_STATE_INTERACTABLE
        if (
            m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass()) ||
            m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())
            ) {
            if (static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->ChannelingInteractable != nullptr) {
                m_game_state.set_value(GAME_STATE_INTERACTABLE);
                return;
            }
        }

        // GAME_STATE_CITADEL_STATION
        if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
            m_game_state.set_value(GAME_STATE_CITADEL_STATION);
            return;
        }

        // GAME_STATE_CYBERSPACE
        if (m_pawn.get()->IsA(APAWN_Avatar_C::StaticClass())) {
            m_game_state.set_value(GAME_STATE_CYBERSPACE);
            return;
        }

        // GAME_STATE_APPARTMENT
        if (m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())) {
            m_game_state.set_value(GAME_STATE_APPARTMENT);
            return;
        }

        // GAME_STATE_PSEUDOSPACE
        // TODO: add pseudospace pawn check, but use string search
        // because PAWN_Hacker_Pseudospace is not in memory when player is not in pseudospace

        // all previous checks are false
        m_game_state.set_value(GAME_STATE_UNDEFINED);
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
    m_gamepad_btn_a.set_state(state);
    m_gamepad_btn_x.set_state(state);
    m_gamepad_btn_b.set_state(state);
    m_gamepad_btn_y.set_state(state);
    m_gamepad_right_shoulder.set_state(state);
    m_gamepad_left_shoulder.set_and_mute_state(state);
    m_gamepad_right_thumb.set_state(state);
    m_gamepad_left_thumb.set_state(state);
    m_gamepad_trigger_right.set_state(state);
    //m_gamepad_trigger_left.set_state(state);
    m_hotbar_selector_button.set_state(state);
    m_hardware_selector_button.set_state(state);

    handle_game_state_controller_input(state, vr);
    handle_smooth_turning(state, vr);
    
}

void UEVRPlugin::handle_game_state_controller_input(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        if (m_game_state.get() == GAME_STATE_INTERACTABLE) {
            auto player_controller = UGameplayStatics::GetPlayerController(m_world, 0);
            if (player_controller->IsA(ACON_Hacker_C::StaticClass())) {
                static_cast<ACON_Hacker_C*>(player_controller)->SetIsUsingGamepad(false);
            }
            if (m_gamepad_btn_x.is_pressed()) {

            }

            m_gamepad_btn_x.mute_state(state);
        }

        if (m_game_state.get() == GAME_STATE_CITADEL_STATION) {
            if (g_vr_body == nullptr) {
                return;
            }

            auto player_controller = UGameplayStatics::GetPlayerController(m_world, 0);
            if (player_controller->IsA(ACON_Hacker_C::StaticClass())) {
                static_cast<ACON_Hacker_C*>(player_controller)->SetIsUsingGamepad(false);
            }

            if (m_gamepad_btn_x.is_pressed()) {
                //API::get()->log_warn("[plugin][handle_controller_input] X-button");
            }

            if (m_gamepad_right_shoulder.is_pressed()) {
                g_vr_body->TryGrabAction(E_ENUM_VRHand::NewEnumerator1, E_ENUM_VRHandPose::NewEnumerator2);
            }
            if (m_gamepad_right_shoulder.is_released()) {
                g_vr_body->TryGrabAction(E_ENUM_VRHand::NewEnumerator1, E_ENUM_VRHandPose::NewEnumerator0);
            }
            if (m_gamepad_left_shoulder.is_pressed()) {
                g_vr_body->TryGrabAction(E_ENUM_VRHand::NewEnumerator0, E_ENUM_VRHandPose::NewEnumerator2);
            }
            if (m_gamepad_left_shoulder.is_released()) {
                g_vr_body->TryGrabAction(E_ENUM_VRHand::NewEnumerator0, E_ENUM_VRHandPose::NewEnumerator0);
            }

            handle_primary_item_selector(state, vr);
            
        }

        if (m_game_state.get() == GAME_STATE_MFD) {
            if (g_vr_body == nullptr) {
                return;
            }
            handle_mfd_interactions(state, vr);
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_controller_input] Exception");
    }
}

void UEVRPlugin::handle_smooth_turning(XINPUT_STATE* state, const UEVR_VRData* vr) {
    static SDK::AController* pawn_controller{ nullptr };
    try {
        if (!m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())) {
            return;
        }

        char snap_angle[16] = { 0 };
        vr->get_mod_value("VR_SnapturnTurnAngle", snap_angle, sizeof(snap_angle));
        int snap_angle_int = atoi(snap_angle);

        // verify if smooth turning conditions have been met
        if (snap_angle_int == 359) {
            vr->set_snap_turn_enabled(false);
            pawn_controller = m_pawn.get()->Controller;
            if (!UKismetSystemLibrary::IsValid(pawn_controller)) {
                return;
            }

            auto control_rotation = pawn_controller->GetControlRotation();
            control_rotation.Yaw += (state->Gamepad.sThumbRX / ((11.f - m_ui_option_look_sensitivity) * 2499.0f));
            pawn_controller->SetControlRotation(control_rotation);

            state->Gamepad.sThumbRX = 0;
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_smooth_turning] Exception");
    }
}

void UEVRPlugin::handle_game_state_change() {
    try {
        if (m_game_state.has_changed()) {
            API::get()->log_warn("[plugin][handle_game_state_change] New Game State: %s", GameStateName[m_game_state.get()]);
            const UEVR_VRData* vr = API::get()->param()->vr;
            API::UObjectHook::MotionControllerState* mc_state{ nullptr };

            switch (m_game_state.get()) {
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
                //PluginUtils::reset_height(0.f);
                vr->recenter_view();
                break;

            case GAME_STATE_CITADEL_STATION:
                g_vr_body->VRBodyMesh->SetVisibility(true, false);

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
                //PluginUtils::reset_height(0.f);
                vr->recenter_view();

                if (is_valid_vr_body_hacker_implant_pawn()) {
                    VRMFD::hide_mfd();
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
                if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
                    APAWN_Hacker_Implant_C* pawn = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get());
                    if (pawn->ChannelingInteractableName == UKismetStringLibrary::Conv_StringToName(L"INTERACT_SurgeryMachine")) {
                        API::get()->log_warn("[plugin][handle_game_state_change] Surgery Machine");

                        VRBody::reset_player_camera();
                        VRBody::set_weapon_mesh_visibility(false);

                        // TODO - not working?
                        static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->ArmsMesh->SetVisibility(false, false);
                        g_vr_body->VRBodyMesh->SetVisibility(false, false);

                        API::UObjectHook::set_disabled(true);
                    }
                }
                break;
            }
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_game_state_change] Exception");
    }
}

void UEVRPlugin::handle_level_change() {
    try {
        if (m_level.has_changed() && UKismetSystemLibrary::IsValid(m_level.get())) {
            API::get()->log_warn("[plugin][handle_level_change] New Level: %s", m_level.get()->GetFullName().c_str());

            // reset pointers invalidating vr_body
            API::get()->log_warn("[plugin][handle_level_change] Actors / Pointers cleanup");
            cleanup_actors();
            cleanup_pointers();

            if (
                SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) &&
                m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())
            ) {
                APAWN_Hacker_Implant_C* pawn = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get());
                g_vr_body = VRBody::initialize_vr_body(pawn);

                if (g_vr_body != nullptr) {
                    VRBody::initialize_laser_dot();
                    VRBody::overwrite_hacker_crouch_animations();
                    VRBody::initialize_minimap(m_neural_hud);
                    VRItemSelector::initialize(m_neural_hud);
                    PluginUtils::reset_height(0.f);
                }
                else {
                    API::get()->log_error("[plugin][handle_level_change] Expected valid g_vr_body");
                }
                //load_mod_config();
            }
            else {
                API::get()->log_warn("[plugin][handle_level_change] Components cleanup");
                cleanup_actors();
                cleanup_pointers();
            }
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_level_change] Exception");
    }
}

// primary item selector
void UEVRPlugin::handle_primary_item_selector(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        if (g_vr_body == nullptr) {
            API::get()->log_error("[plugin][handle_primary_item_selector] vr_body nullptr");
            return;
        }

        if (!m_hardware_selector_button.is_held()) {

            if (m_hotbar_selector_button.is_pressed()) {
                VRItemSelector::set_visibility(true);
                VRBody::set_weapon_mesh_visibility(false);
                // hide UEVR controlled HUD
                vr->set_mod_value("UI_Size", "0.000000");
                vr->set_mod_value("VR_RoomscaleMovement", "false");
                vr->set_aim_method(0);

                // show VR item selector
                //g_vr_body->set_laser_pointer_visibility(true);
                g_vr_body->ItemSelectorRight->Show(20.f);
                g_vr_body->ItemSelectorLeft->Hide();

                // we will ignore Player mesh collisions on the channel that WidgetInteractionComponent uses
                // for the time the selector is active
                //VRBody::set_player_response_to_collision_channel(
                //    static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get()),
                //    g_vr_body,
                //    item_selector_collision_channel,
                //    SDK::ECollisionResponse::ECR_Ignore
                //);
                VRItemSelector::unselect_all_hotbar_slots(m_neural_hud);
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
                g_vr_body->ItemSelectorRight->Hide();

                vr->set_mod_value("VR_RoomscaleMovement", "true");
                vr->set_aim_method(m_default_aim_method);
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

        // mute controller A, Y buttons, we'll use them for LMB, RMB
        m_gamepad_btn_a.mute_state(state);
        m_gamepad_btn_y.mute_state(state);

        // scroll up
        if (state->Gamepad.sThumbRY > INPUT_DEADZONE_HI && m_mouse_wheel_debounce_timer > MOUSE_WHEEL_DEBOUNCE_TIME) {
            send_mouse(0x0A, false);
            m_mouse_wheel_debounce_timer = 0.f;
        }
        // scroll down
        if (state->Gamepad.sThumbRY < -INPUT_DEADZONE_HI && m_mouse_wheel_debounce_timer > MOUSE_WHEEL_DEBOUNCE_TIME) {
            send_mouse(0x0B, false);
            m_mouse_wheel_debounce_timer = 0.f;
        }
        // mute sticks that move cursor
        state->Gamepad.sThumbRX = 0;
        state->Gamepad.sThumbRY = 0;

        if (m_gamepad_btn_a.is_pressed()) {
            API::get()->log_error("[plugin][handle_mfd_interactions] m_gamepad_btn_a pressed");
            SDK::FKey lmb{
                .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"LeftMouseButton")
            };
            static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->InpActEvt_Real_PrimaryAttack_K2Node_InputActionEvent_54(lmb);
            //g_vr_body->WidgetInteractionRight->PressPointerKey(lmb);
        }

        if (m_gamepad_btn_a.is_released()) {
            SDK::FKey lmb{
                .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"LeftMouseButton")
            };
            static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->InpActEvt_Real_PrimaryAttack_K2Node_InputActionEvent_54(lmb);
            //g_vr_body->WidgetInteractionRight->ReleasePointerKey(lmb);
        }
        if (m_gamepad_btn_a.has_changed()) {
            send_mouse(VK_LBUTTON, !m_gamepad_btn_a.value);
        }

        if (m_gamepad_btn_y.has_changed()) {
            send_mouse(VK_RBUTTON, !m_gamepad_btn_y.value);
        }
        ctrl->SetIsUsingGamepad(false);

        if (g_vr_body->WidgetInteractionRight->HoveredWidgetComponent != nullptr) {
            cursor_pos = g_vr_body->WidgetInteractionRight->Get2DHitLocation();
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
    }
    catch (...) {
        API::get()->log_error("[plugin][cleanup_pointers] Exception");
    }
}

void UEVRPlugin::cleanup_actors() {
    API::get()->log_warn("[plugin][cleanup] Starting Actors Cleanup");
    //VRBody::cleanup_actors();
}


//// -------------------------------------------------------------------------------------
//// ImGui
//// -------------------------------------------------------------------------------------
//bool UEVRPlugin::on_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
//    ImGui_ImplWin32_WndProcHandler(hwnd, msg, wparam, lparam);
//
//    return !ImGui::GetIO().WantCaptureMouse && !ImGui::GetIO().WantCaptureKeyboard;
//}
//
//void UEVRPlugin::on_device_reset() {
//    PLUGIN_LOG_ONCE("Device Reset");
//
//    //std::scoped_lock _{ m_imgui_mutex };
//
//    const auto renderer_data = API::get()->param()->renderer;
//
//    if (renderer_data->renderer_type == UEVR_RENDERER_D3D11) {
//        ImGui_ImplDX11_Shutdown();
//        g_d3d11 = {};
//    }
//
//    if (renderer_data->renderer_type == UEVR_RENDERER_D3D12) {
//        ImGui_ImplDX12_Shutdown();
//        g_d3d12 = {};
//    }
//
//    m_imgui_initialized = false;
//}
//
//void UEVRPlugin::on_post_render_vr_framework_dx11(ID3D11DeviceContext* context, ID3D11Texture2D* texture, ID3D11RenderTargetView* rtv) {
//    PLUGIN_LOG_ONCE("Post Render VR Framework DX11");
//
//    const auto vr_active = API::get()->param()->vr->is_hmd_active();
//
//    if (!m_imgui_initialized || !vr_active) {
//        return;
//    }
//
//    if (m_was_rendering_desktop) {
//        m_was_rendering_desktop = false;
//        on_device_reset();
//        return;
//    }
//
//    //std::scoped_lock _{ m_imgui_mutex };
//
//    ImGui_ImplDX11_NewFrame();
//    g_d3d11.render_imgui_vr(context, rtv);
//}
//
//void UEVRPlugin::on_post_render_vr_framework_dx12(ID3D12GraphicsCommandList* command_list, ID3D12Resource* rt, D3D12_CPU_DESCRIPTOR_HANDLE* rtv) {
//    PLUGIN_LOG_ONCE("Post Render VR Framework DX12");
//
//    const auto vr_active = API::get()->param()->vr->is_hmd_active();
//
//    if (!m_imgui_initialized || !vr_active) {
//        return;
//    }
//
//    if (m_was_rendering_desktop) {
//        m_was_rendering_desktop = false;
//        on_device_reset();
//        return;
//    }
//
//    //std::scoped_lock _{ m_imgui_mutex };
//
//    ImGui_ImplDX12_NewFrame();
//    g_d3d12.render_imgui_vr(command_list, rtv);
//}
//
//bool UEVRPlugin::initialize_imgui() {
//    if (m_imgui_initialized) {
//        return true;
//    }
//
//    IMGUI_CHECKVERSION();
//    ImGui::CreateContext();
//
//    static const auto imgui_ini = API::get()->get_persistent_dir(L"outer_worlds_vr_imgui.ini").string();
//    ImGui::GetIO().IniFilename = imgui_ini.c_str();
//    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
//
//    const auto renderer_data = API::get()->param()->renderer;
//
//    DXGI_SWAP_CHAIN_DESC swap_desc{};
//    auto swapchain = (IDXGISwapChain*)renderer_data->swapchain;
//    swapchain->GetDesc(&swap_desc);
//
//    m_wnd = swap_desc.OutputWindow;
//
//    if (!ImGui_ImplWin32_Init(m_wnd)) {
//        return false;
//    }
//
//    if (renderer_data->renderer_type == UEVR_RENDERER_D3D11) {
//        if (!g_d3d11.initialize()) {
//            return false;
//        }
//    }
//    else if (renderer_data->renderer_type == UEVR_RENDERER_D3D12) {
//        if (!g_d3d12.initialize()) {
//            return false;
//        }
//    }
//
//    m_imgui_initialized = true;
//    return true;
//}
//
//void UEVRPlugin::on_present() {
//    return;
//    //std::scoped_lock _{ m_imgui_mutex };
//
//    if (!m_imgui_initialized) {
//        API::get()->log_warn("ImGui not initialized");
//        if (!initialize_imgui()) {
//            API::get()->log_error("Failed to initialize ImGui");
//            return;
//        }
//        else {
//            API::get()->log_warn("Initialized ImGui");
//        }
//    }
//
//    const auto renderer_data = API::get()->param()->renderer;
//
//    if (renderer_data->renderer_type == UEVR_RENDERER_D3D11) {
//        ImGui_ImplDX11_NewFrame();
//        ImGui_ImplWin32_NewFrame();
//        ImGui::NewFrame();
//
//        //if (m_main != nullptr) {
//        //    m_main->on_draw_imgui();
//        //}
//
//        ImGui::EndFrame();
//        ImGui::Render();
//
//        g_d3d11.render_imgui();
//    }
//    else if (renderer_data->renderer_type == UEVR_RENDERER_D3D12) {
//        auto command_queue = (ID3D12CommandQueue*)renderer_data->command_queue;
//
//        if (command_queue == nullptr) {
//            return;
//        }
//
//        ImGui_ImplDX12_NewFrame();
//        ImGui_ImplWin32_NewFrame();
//        ImGui::NewFrame();
//
//        //if (m_main != nullptr) {
//        //    m_main->on_draw_imgui();
//        //}
//
//        ImGui::EndFrame();
//        ImGui::Render();
//
//        g_d3d12.render_imgui();
//    }
//}

// sends mouse inputs to OS (thanks markmon)
void UEVRPlugin::send_mouse(WORD key, bool key_up) {
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


bool UEVRPlugin::is_valid_vr_body_hacker_implant_pawn() {
    if (g_vr_body == nullptr) {
        API::get()->log_error("[plugin][is_valid_hacker_pawn] Invalid g_vr_body");
        return false;
    }

    if (g_vr_body == nullptr) {
        API::get()->log_error("[plugin][is_valid_hacker_pawn] Invalid g_vr_body");
        return false;
    }

    if (m_pawn.get() == nullptr || !m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
        API::get()->log_error("[plugin][is_valid_hacker_pawn] Invalid pawn");
        return false;
    }

    return true;
}
