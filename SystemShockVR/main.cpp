#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "SDK/PAWN_PlayerGhost_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/PAWN_Hacker_Simple_classes.hpp"
#include "SDK/PAWN_Hacker_Pseudospace_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/WIDGET_SimpleHUD_classes.hpp"
#include "SDK/WIDGET_CyberspaceHUD_classes.hpp"
#include "SDK/WIDGET_MainMenu_InGame_classes.hpp"
#include "SDK/CinematicCamera_classes.hpp"
#include "SDK/CON_Hacker_classes.hpp"
#include "SDK/UMG_classes.hpp"

#include "SDK/_CH_Hacker_Rig_Skeleton_AnimBlueprint_classes.hpp"
#include "SDK/_BP_ItemSelector_classes.hpp"
#include "SDK/_BP_DebugWidgetComponent_classes.hpp"
#include "SDK/_BP_VRMovementComponent_classes.hpp"

#include "main.hpp"
#include "vr_body.hpp"
#include "plugin_utils.hpp"

using namespace uevr;
using namespace SDK;

SystemShockMain::SystemShockMain() {
    try {
        API::get()->log_warn("[main] Constructor");
        m_vr_body = new VRBody(this);
    }
    catch (...) {
        API::get()->log_error("[main][constructor] Exception");
        return;
    }
};

SystemShockMain::~SystemShockMain() {
    API::get()->log_warn("[main] Destructor");
}

void SystemShockMain::on_xinput(XINPUT_STATE* state, const UEVR_VRData* vr) {
    //auto player_controller = UGameplayStatics::GetPlayerController(m_world, 0);
    //if (player_controller != nullptr && player_controller->IsA(ACON_Hacker_C::StaticClass())) {
    //    static_cast<ACON_Hacker_C*>(player_controller)->SetIsUsingGamepad(false);
    //    static_cast<ACON_Hacker_C*>(player_controller)->WasUsingGamepad = true;
    //}

    handle_controller_input(state, vr);
    handle_smooth_turning(state, vr);
}
 
void SystemShockMain::on_tick(float delta) {
    //auto player_controller = UGameplayStatics::GetPlayerController(m_world, 0);
    //if (player_controller != nullptr && player_controller->IsA(ACON_Hacker_C::StaticClass())) {
    //    static_cast<ACON_Hacker_C*>(player_controller)->SetIsUsingGamepad(false);
    //    static_cast<ACON_Hacker_C*>(player_controller)->WasUsingGamepad = true;
    //}

    try {
        handle_game_state_changes();
        handle_level_changes();
        //handle_mod_events();
        handle_crouch();

        if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
            try_running_test_1();
            try_running_test_2();
            if (m_vr_body != nullptr) {
                //float offset{ 0.f };
                //m_vr_body->get_bp_actor()->GetHipsOffset(&offset);
                //if (offset >= 70.f) {
                //    offset = 70.f;
                //}
                //float alpha = 1.0f - ((70.f - offset) / 70.0f);
                //if (alpha < 0.f) {
                //    alpha = 0.f;
                //}
                ////m_vr_body->get_bp_actor()->CalibratedEyeHeight = 150.5f;
                //m_vr_body->get_bp_actor()->FinalHipsOffset = { 0.f, offset, 0.f };

            }

            //if (m_vr_body != nullptr && m_vr_body->is_valid()) {
            //    m_vr_body->on_tick();
            //}
        }
    }
    catch (...) {
        API::get()->log_error("[main][on_tick] Exception");
        return;
    }
}

void SystemShockMain::cleanup_pointers() {
    try {
        API::get()->log_warn("[main][cleanup] Starting Pointers Cleanup");
        //if (m_vr_hud != nullptr) {
        //    m_vr_hud->cleanup_pointers();
        //}
        if (m_vr_body != nullptr) {
            m_vr_body->cleanup_pointers();
        }
    }
    catch (...) {
        API::get()->log_error("[main][cleanup_pointers] Exception");
    }
}

void SystemShockMain::cleanup_actors() {
    API::get()->log_warn("[main][cleanup] Starting Actors Cleanup");
    VRBody::cleanup_actors();
}

// -------------------------------------------------------------------------------------
// pointers and state
// -------------------------------------------------------------------------------------
bool SystemShockMain::prepare_pointers() {
    try {
        //API::get()->log_error("[main][prepare_pointers] Start");
        // world
        m_world = UWorld::GetWorld();
        if (m_world == nullptr) {
            API::get()->log_error("[main][prepare_pointers] World pointer error");
            return false;
        }
        // pawn
        m_pawn.set_value(m_world != nullptr ? UGameplayStatics::GetPlayerPawn(m_world, 0) : nullptr);
        if (m_pawn.get() == nullptr) {
            API::get()->log_error("[main][prepare_pointers] Pawn pointer error");
            return false;
        }

        if (!UKismetSystemLibrary::IsValid(m_pawn.get())) {
            API::get()->log_error("[main][prepare_pointers] Pawn invalid");
            return false;
        }

        if (m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())) {
            m_inventory = static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->COMP_HackerInventory;
        }

        if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
            static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->GetNeuralHUD(&m_neural_hud);
            if (m_neural_hud == nullptr) {
                API::get()->log_error("[main][prepare_pointers] Neural HUD pointer error");
                return false;
            }
        }

        // level
        m_level.set_value(m_world != nullptr ? m_world->PersistentLevel : nullptr);
        //API::get()->log_error("[main][prepare_pointers] End");

        auto uevr_pawn = API::get()->get_local_pawn(0);
        const auto move_control_manager_data = uevr_pawn->get_property_data<API::UObject*>(L"COMP_MoveControlManager");
        const auto move_control_manager = move_control_manager_data != nullptr ? *move_control_manager_data : nullptr;
        if (move_control_manager != nullptr) {
            m_is_crouching.set_value(move_control_manager->get_bool_property(L"IsTryingToCrouch"));
        }
        else {
            m_is_crouching.set_value(false);
        }
    }
    catch (...) {
        API::get()->log_error("[main][prepare_pointers] Exception");
        return false;
    }
    return true;
}

void SystemShockMain::prepare_game_state() {
    static UWIDGET_MainMenu_InGame_C* main_menu{ nullptr };
    static APlayerCameraManager* player_camera_manager{ nullptr };
    //API::get()->log_error("[main][prepare_game_state] Start");
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
            m_game_state.set_value(GAME_STATE_MFD);
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
    }
    catch (...) {
        API::get()->log_error("[main][prepare_game_state] Exception");
    }
}

// -------------------------------------------------------------------------------------
// controller input
// -------------------------------------------------------------------------------------
void SystemShockMain::handle_controller_input(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
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


        //if (m_gamepad_left_thumb.is_long_pressed(2.f)) {
        //    if (m_flicker_fixer->is_valid()) {
        //        m_flicker_fixer->cycle(50);
        //    }
        //}

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
            if (m_vr_body == nullptr) {
                return;
            }

            auto player_controller = UGameplayStatics::GetPlayerController(m_world, 0);
            if (player_controller->IsA(ACON_Hacker_C::StaticClass())) {
                static_cast<ACON_Hacker_C*>(player_controller)->SetIsUsingGamepad(false);
            }

            if (m_gamepad_btn_x.is_pressed()) {
                API::get()->log_warn("[main][handle_controller_input] X-button");
                // map B-button to F-key press
                SDK::FKey f_key_name{
                    .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"F")
                };
                SDK::FKey r_key_name{
                    .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"R")
                };

                SDK::FKey gp_key_name{
                    .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"Gamepad_FaceButton_Left")
                };
                //static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_Gamepad_Real_Interact_K2Node_InputActionEvent_59(gp_key_name);
                // 
                //static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_Real_Interact_K2Node_InputActionEvent_57(f_key_name);
                //static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_Real_Reload_K2Node_InputActionEvent_52(r_key_name);
                //static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_Real_Accept_K2Node_InputActionEvent_35(key_name);
                //static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_AnyKey_K2Node_InputKeyEvent_28(f_key_name);
                //static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_AnyKey_K2Node_InputKeyEvent_28(r_key_name);
                //static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_Real_Interact_K2Node_InputActionEvent_58(key_name);
                //static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_Real_Accept_K2Node_InputActionEvent_36(key_name);
            }

            if (m_gamepad_right_shoulder.is_pressed()) {
                m_vr_body->get_bp_actor()->TryGrabAction(E_ENUM_VRHand::NewEnumerator1, E_ENUM_VRHandPose::NewEnumerator2);
            }
            if (m_gamepad_right_shoulder.is_released()) {
                m_vr_body->get_bp_actor()->TryGrabAction(E_ENUM_VRHand::NewEnumerator1, E_ENUM_VRHandPose::NewEnumerator0);
            }
            if (m_gamepad_left_shoulder.is_pressed()) {
                m_vr_body->get_bp_actor()->TryGrabAction(E_ENUM_VRHand::NewEnumerator0, E_ENUM_VRHandPose::NewEnumerator2);
            }
            if (m_gamepad_left_shoulder.is_released()) {
                m_vr_body->get_bp_actor()->TryGrabAction(E_ENUM_VRHand::NewEnumerator0, E_ENUM_VRHandPose::NewEnumerator0);
            }

            handle_primary_item_selector(state, vr);
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_controller_input] Exception");
    }
}


void SystemShockMain::handle_smooth_turning(XINPUT_STATE* state, const UEVR_VRData* vr) {
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
        API::get()->log_error("[main][handle_smooth_turning] Exception");
    }
}

// primary item selector
void SystemShockMain::handle_primary_item_selector(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        if (m_vr_body != nullptr && !m_hardware_selector_button.is_held()) {

            if (m_hotbar_selector_button.is_pressed()) {
                m_vr_body->set_primary_item_selector_visibility(true);
                // hide UEVR controlled HUD
                vr->set_mod_value("UI_Size", "0.000000");
                vr->set_mod_value("VR_RoomscaleMovement", "false");
                vr->set_aim_method(0);

                // show VR item selector
                //m_vr_body->set_laser_pointer_visibility(true);
                m_vr_body->get_bp_actor()->ItemSelectorRight->Show(20.f);
                m_vr_body->get_bp_actor()->ItemSelectorLeft->Hide();

                // we will ignore Player mesh collisions on the channel that WidgetInteractionComponent uses
                // for the time the selector is active
                m_vr_body->set_player_response_to_collision_channel(
                    item_selector_collision_channel, SDK::ECollisionResponse::ECR_Ignore
                );
                m_vr_body->unselect_all_hotbar_slots();
                //API::get()->log_warn("[main][handle_primary_item_selector] Grip Pressed");
            }

            if (m_hotbar_selector_button.is_released()) {
                m_vr_body->change_quick_slot();

                // restore collisions
                //m_vr_body->set_player_response_to_collision_channel(
                //    item_selector_collision_channel, SDK::ECollisionResponse::ECR_Block
                //);
                m_vr_body->set_primary_item_selector_visibility(false);
                ////m_vr_body->set_laser_pointer_visibility(false);
                m_vr_body->get_bp_actor()->ItemSelectorRight->Hide();

                vr->set_mod_value("VR_RoomscaleMovement", "true");
                vr->set_aim_method(m_default_aim_method);
                //API::get()->log_warn("[main][handle_primary_item_selector] Grip Released");
            }

            // state, when the item selector is shown
            if (m_hotbar_selector_button.is_held()) {
                //API::get()->log_warn("[main][handle_primary_item_selector] Grip Held Begin");
                //m_vr_body->update_laser_pointer_length(35.f);
                m_vr_body->highlight_quick_slot();

                state->Gamepad.sThumbRX = 0;
                //API::get()->log_warn("[main][handle_primary_item_selector] Grip Held End");
            }

            m_hotbar_selector_button.mute_state(state);
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_primary_item_selector] Exception");
    }
}


// -------------------------------------------------------------------------------------
// handlers
// -------------------------------------------------------------------------------------
void SystemShockMain::handle_game_state_changes() {
    try {
        if (m_game_state.has_changed()) {
            API::get()->log_warn("[main][handle_game_state] New Game State: %s", GameStateName[m_game_state.get()]);
            const UEVR_VRData* vr = API::get()->param()->vr;

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
                break;

            case GAME_STATE_MFD:
                API::UObjectHook::set_disabled(false);
                vr->set_aim_method(0);
                vr->set_decoupled_pitch_enabled(true);
                vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                vr->set_mod_value("UI_Distance", "2.000000");
                vr->set_mod_value("UI_Size", "1.400000");
                vr->set_mod_value("UI_Y_Offset", "0.00000");
                vr->set_mod_value("VR_RoomscaleMovement", "true");
                vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                //PluginUtils::reset_height(0.f);
                vr->recenter_view();
                break;
            }
        }
    }
    catch (...) {
        API::get()->log_error("[handle_game_state] Exception");
    }
}

void SystemShockMain::handle_level_changes() {
    try {
        if (m_level.has_changed() && UKismetSystemLibrary::IsValid(m_level.get())) {
            API::get()->log_warn("[main][handle_level_change] New Level: %s", m_level.get()->GetFullName().c_str());

            // reset pointers invalidating vr_body
            API::get()->log_warn("[main][handle_level_change] Actors / Pointers cleanup");
            cleanup_actors();
            cleanup_pointers();

            if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
                if (m_vr_body != nullptr) {
                    m_vr_body->initialize();
                    PluginUtils::reset_height(0.f);
                }
                else {
                    API::get()->log_error("[main][handle_level_change] Expected valid m_vr_body");
                }
                //load_mod_config();
            }
            else {
                API::get()->log_warn("[main][handle_level_change] Components cleanup");
                cleanup_actors();
                cleanup_pointers();
            }
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_level_change] Exception");
    }
}

void SystemShockMain::handle_mod_events() {
    try {
        if (m_mod_events.contains(MOD_EVENT_ENABLE_WORLD_RENDERING)) {
            if (m_world != nullptr) {
                API::get()->log_warn("[main][handle_mod_events] SetEnableWorldRendering");
                UGameplayStatics::SetEnableWorldRendering(m_world, true);
                m_mod_events.extract(MOD_EVENT_ENABLE_WORLD_RENDERING);
            }
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_mod_events] Exception");
    }
}

void SystemShockMain::handle_crouch() {
    if (m_is_crouching.disabled()) {
        PluginUtils::reset_height(0.f);
    }
}


void SystemShockMain::toggle_gui() {
    m_gui_visible = !m_gui_visible;
    if (UKismetSystemLibrary::IsValid(m_neural_hud)) {
        m_neural_hud->SetVisibility(m_gui_visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
    }
}


// -------------------------------------------------------------------------------------
// ImGui
// -------------------------------------------------------------------------------------
void SystemShockMain::on_draw_imgui() {
    try {
        if (!API::get()->param()->functions->is_drawing_ui()) {
            return;
        }

        static const auto UEVR_NAME = std::format("System Shock UEVR plugin [rev. {}]", MOD_VERSION);
        static const auto NO_CHARACTER = std::format("No Player Character detected! Is it Main Menu?");
        //static const auto NO_PAWN = std::format("No Pawn detected!");

        static constexpr auto window_w = 500.0f;
        static constexpr auto window_h = 500.0f;

        ImGui::SetNextWindowSize(ImVec2(window_w, window_h), ImGuiCond_::ImGuiCond_Once);

        if (ImGui::Begin(UEVR_NAME.c_str())) {
            ImGui::PushItemWidth(200);
            if (ImGui::Button("Save Configuration")) {
                if (save_mod_config()) {
                    ImGui::OpenPopup("succesful_save_popup");
                }
            }
            if (ImGui::BeginPopup("succesful_save_popup"))
            {
                ImGui::Text("Configuration Saved!");
                ImGui::EndPopup();
            }

            if (ImGui::Button("Toggle GUI")) {
                toggle_gui();
            }

            //if (ImGui::Button("Test BTN1")) {
            if (ImGui::Button("Modify Movement")) {
                m_trigger_test_1 = true;
            }
            if (ImGui::Button("Set Camera Height")) {
                m_trigger_test_2 = true;
            }

            ImGui::PopItemWidth();

            if (m_vr_body != nullptr && m_vr_body->get_bp_actor() != nullptr) {
                m_vr_body->on_draw_imgui();
                if (ImGui::SliderFloat("Player Height", &m_vr_body->get_bp_actor()->VRMovementComponent->PlayerHeight, 170.f, 183.f, "%1.0f")) {
                    m_vr_body->get_bp_actor()->VRMovementComponent->AdjustComponentsToPlayerHeight(m_vr_body->get_bp_actor()->VRMovementComponent->PlayerHeight);
                    PluginUtils::reset_height(0.f);
                }
            }


            ImGui::SeparatorText("Debugging");
            // game state section
            ImGui::Checkbox("Show debug", &m_ui_option_show_debug_view);
            if (m_ui_option_show_debug_view) {
                ImGui::BeginGroup();
                ImGui::BeginDisabled();
                ImGui::InputText("Game State", (char*)GameStateName[m_game_state.get()], 20);

                if (m_vr_body != nullptr && m_vr_body->get_bp_actor() != nullptr) {
                    float half_size = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->CapsuleComponent->CapsuleHalfHeight;
                    float vr_origin_rel_loc_z = m_vr_body->get_bp_actor()->RootComponent->RelativeLocation.Z;
                    float base_eye_height = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->BaseEyeHeight;
                    float hmd_component_rel_loc_z = m_vr_body->get_bp_actor()->HMDComponent->RelativeLocation.Z;
                    float final_hips_offset_y = m_vr_body->get_bp_actor()->VRMovementComponent->FinalHipsOffset.Y;
                    float final_hips_offset_z = m_vr_body->get_bp_actor()->VRMovementComponent->FinalHipsOffset.Z;

                    //m_vr_body->get_bp_actor()->Calibrate();
                    ImGui::PushItemWidth(100);
                    
                    ImGui::InputFloat("Pawn Collision Half-Size", &half_size);
                    ImGui::InputFloat("VRBody RootComponent RelLoc-Z", &vr_origin_rel_loc_z);
                    ImGui::InputFloat("Pawn BaseEyeHeight", &base_eye_height);
                    ImGui::InputFloat("HMDComponent RelLoc-Z", &hmd_component_rel_loc_z);
                    ImGui::InputFloat("Final Hips Offset-Y", &final_hips_offset_y);
                    ImGui::InputFloat("Final Hips Offset-Z", &final_hips_offset_z);
                    ImGui::PopItemWidth();
                }

                ImGui::EndDisabled();
                ImGui::EndGroup();

                ImGui::SeparatorText("Timers [microseconds]");
                ImGui::BeginGroup();
                ImGui::BeginDisabled();
                ImGui::PushItemWidth(50);
                ImGui::InputInt("XInput duration", &m_ui_xinput_duration, 0, 0);
                ImGui::InputInt("PreEngineTick duration", &m_ui_pre_engine_tick_duration, 0, 0);
                ImGui::PopItemWidth();
                ImGui::EndDisabled();
                ImGui::EndGroup();
            }
        }
        ImGui::End();
    }
    catch (...) {
        API::get()->log_error("[main][on_draw_imgui] Exception");
    }
}

// -------------------------------------------------------------------------------------
// mod config
// -------------------------------------------------------------------------------------
bool SystemShockMain::load_mod_config() {
    try {
        API::get()->log_warn("[main][load_mod_config] Loading...");
        static const auto config_filename = API::get()->get_persistent_dir(L"outer_worlds_vr_config.ini").string();
        mINI::INIFile mod_config_file(config_filename);
        mINI::INIStructure mod_config;

        if (!mod_config_file.read(mod_config)) {
            API::get()->log_error("[main][load_mod_config] Missing config file. Creating config with default values");
            return save_mod_config();
        }

        //m_vr_hud->on_load_config(mod_config);
        return true;
    }
    catch (...) {
        API::get()->log_error("[plugin_config][load_mod_config] Exception");
        return false;
    }
}

bool SystemShockMain::save_mod_config() {
    try {
        API::get()->log_warn("[main][save_mod_config] Saving...");
        static const auto config_filename = API::get()->get_persistent_dir(L"outer_worlds_vr_config.ini").string();
        mINI::INIFile mod_config_file(config_filename);
        mINI::INIStructure mod_config;

        //m_vr_hud->on_save_config(mod_config);

        return mod_config_file.write(mod_config, true);
    }
    catch (...) {
        API::get()->log_error("[main][save_mod_config] Exception");
        return false;
    }
}




void SystemShockMain::try_running_test_1()
{
    if (m_trigger_test_1) {
        m_trigger_test_1 = false;
        API::get()->log_warn("[main][test1] Start");

        API::UClass* class_ptr = API::get()->find_uobject<API::UClass>(L"Class /Script/Engine.ShapeComponent");
        if (class_ptr != nullptr) {
            std::vector<API::UObject*> matching_objects = class_ptr->get_objects_matching<API::UObject>();

            for (size_t i = 0; i < matching_objects.size(); i++) {
                auto obj = (SDK::UObject*)matching_objects[i];

                if (obj->IsA(SDK::UShapeComponent::StaticClass())) {
                    //API::get()->log_info("VRHackerHUD :: Found Lift: %s", obj->GetFullName().c_str());
                    static_cast<SDK::UShapeComponent*>(obj)->SetHiddenInGame(false, false);
                }
                //if (obj->IsA(SDK::UArrowComponent::StaticClass())) {
                //    //API::get()->log_info("VRHackerHUD :: Found Lift: %s", obj->GetFullName().c_str());
                //    static_cast<SDK::UArrowComponent*>(obj)->SetHiddenInGame(true, true);
                //}
            }
        }

        API::get()->log_warn("[main][test1] End");
    }
}

void SystemShockMain::try_running_test_2()
{
    if (m_trigger_test_2) {
        API::get()->log_warn("[main][test2] Start");
        m_trigger_test_2 = false;
        PluginUtils::reset_height(0.f);
        if (m_vr_body != nullptr) {
            m_vr_body->get_bp_actor()->UEVRCameraAttachComponent->RelativeLocation.Z = 140.0f;
        }

        //if (m_pawn.get() != nullptr && m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
        //    if (m_vr_body != nullptr && SDK::UKismetSystemLibrary::IsValid(m_vr_body->get_bp_actor())) {
        //        auto vr_body_actor = m_vr_body->get_bp_actor();
        //        auto is_visible = vr_body_actor->MCDebugSphereLeft->IsVisible();
        //        vr_body_actor->MCDebugSphereLeft->SetVisibility(!is_visible, true);
        //    }
        //}
        API::get()->log_warn("[main][test2] End");
    }
}