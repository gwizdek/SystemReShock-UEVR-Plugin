
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
#include "SDK/CinematicCamera_classes.hpp"
#include "SDK/CON_Hacker_classes.hpp"
#include "SDK/MOVECONTROL_FocusableInteract_classes.hpp"
#include "SDK/MOVECONTROL_StationMove_classes.hpp"
#include "SDK/COMP_MoveControlManager_classes.hpp"
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

#include "SDK/_BP_LaserDot_classes.hpp"
#include "SDK/_BP_ItemSelector_classes.hpp"
#include "SDK/_BP_MFDMaskComponent_classes.hpp"
#include "SDK/_BP_HandInteractionComponent_classes.hpp"
#include "SDK/_BP_VRMovementComponent_classes.hpp"
#include "SDK/_CH_Hacker_Rig_Skeleton_AnimBlueprint_classes.hpp"
#include "SDK/_BP_MeleeWeaponHandler_classes.hpp"
#include "SDK/_BP_VRMenu_classes.hpp"
#include "SDK/_BP_InteractablesHighlighter_classes.hpp"

#include "plugin.hpp"
#include "plugin_utils.hpp"
#include "vr_body.hpp"
#include "vr_item_selector.hpp"
#include "vr_mfd.hpp"
#include "vr_avatar.hpp"

#define INPUT_DEADZONE_LO  ( 0.01f * FLOAT(0x7FFF) )  // Default to 01% of the +/- 32767 range.
#define INPUT_DEADZONE_MED ( 0.45f * FLOAT(0x7FFF) )  // Default to 45% of the +/- 32767 range.
#define INPUT_DEADZONE_HI  ( 0.80f * FLOAT(0x7FFF) )  // Default to 80% of the +/- 32767 range.

using namespace uevr;
using namespace SDK;

std::unique_ptr<UEVRPlugin> g_plugin = std::make_unique<UEVRPlugin>();

// -------------------------------------------------------------------------------------
// UEVR Overrides
// -------------------------------------------------------------------------------------
void UEVRPlugin::on_initialize() {
    PLUGIN_LOG_ONCE("Plugin Initializing...");

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
        // handle level change before xinput
        handle_level_change();
        handle_xinput(state, vr);
        handle_lean();

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
        handle_media_display();
        update_trailing_rotation(delta);
        handle_ads();

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

            m_is_media_display_visible.consume();
            m_neural_hud->IsMediaDisplayVisible(&m_is_media_display_visible.value);

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
void UEVRPlugin::prepare_game_state() {
    static UWIDGET_MainMenu_InGame_C* main_menu{ nullptr };
    static APlayerCameraManager* player_camera_manager{ nullptr };
    //API::get()->log_error("[plugin][prepare_game_state] Start");
    try {
        if (m_world == nullptr) {
            m_game_state.set_value(GAME_STATE_UNDEFINED);
            m_pawn_state.set_value(PAWN_UNKNOWN);
            return;
        }

        if (!UKismetSystemLibrary::IsValid(m_pawn.get())) {
            m_game_state.set_value(GAME_STATE_UNDEFINED);
            m_pawn_state.set_value(PAWN_UNKNOWN);
            return;
        }

        player_camera_manager = UGameplayStatics::GetPlayerCameraManager(m_world, 0);

        // GAME_STATE_MAIN_MENU,
        if (m_pawn.get()->IsA(APAWN_PlayerGhost_C::StaticClass())) {
            m_pawn_state.set_value(PAWN_PLAYERGHOST);
            if (player_camera_manager != nullptr) {
                if (
                    UKismetSystemLibrary::IsValid(player_camera_manager->ViewTarget.Target) &&
                    player_camera_manager->ViewTarget.Target->IsA(ABP_IntroDrone_C::StaticClass())
                    ) {
                    m_game_state.set_value(GAME_STATE_INTRO_DRONE);
                    return;
                }
            }

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

        // BOOTING_UP
        if (m_neural_hud != nullptr) {
            if (
                m_neural_hud->WIDGET_BootupScreen->CurrentState != SDK::ENUM_BootupState::NewEnumerator7 &&
                m_neural_hud->WIDGET_BootupScreen->CurrentState != SDK::ENUM_BootupState::NewEnumerator0
                ) {
                m_game_state.set_value(GAME_STATE_BOOTING_UP);
                return;
            }
        }

        // CRASHING
        if (m_neural_hud != nullptr) {
            if (
                m_neural_hud->WIDGET_CrashScreen->CurrentState != SDK::ENUM_CrashState::NewEnumerator2 &&
                m_neural_hud->WIDGET_CrashScreen->CurrentState != SDK::ENUM_CrashState::NewEnumerator3
                ) {
                m_game_state.set_value(GAME_STATE_CRASHING);
                return;
            }
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
            m_pawn_state.set_value(PAWN_HACKERIMPLANT);
            return;
        }

        // GAME_STATE_CYBERSPACE
        if (m_pawn.get()->IsA(APAWN_Avatar_C::StaticClass())) {
            m_game_state.set_value(GAME_STATE_CYBERSPACE);
            m_pawn_state.set_value(PAWN_AVATAR);
            return;
        }

        // GAME_STATE_APPARTMENT
        if (m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())) {
            m_pawn_state.set_value(PAWN_HACKERSIMPLE);
            m_game_state.set_value(GAME_STATE_APPARTMENT);
            try_set_intro_laptop_pointer();

            // handle intro laptop
            if (m_intro_laptop != nullptr) {
                m_is_using_laptop.set_value(m_intro_laptop->IsInteracting);
            }

            if (m_is_using_laptop.enabled()) {
                API::get()->log_warn("Started using intro laptop");
                const UEVR_VRData* vr = API::get()->param()->vr;
                vr->set_aim_method(0);
                vr->set_mod_value("VR_RoomscaleMovement", "false");

                if (g_vr_body != nullptr) {
                    VRBody::hide_vr_body();
                    VRBody::reset_player_camera();
                }
                PluginUtils::reset_height(0.0f);
                API::UObjectHook::set_disabled(true);
            }
            return;
        }

        // GAME_STATE_PSEUDOSPACE
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
            m_is_right_hand_reaching_backpack.set_value(g_vr_body->HandInteractionRight->IsReachingBackpack);

            handle_vr_menu_xinput(state, vr);
            handle_citadel_station_xinput(state, vr);
            handle_smooth_turning(state);
            return;
        }

        // Focusable interaction
        if (m_game_state.get() == GAME_STATE_INTERACTABLE) {
            auto player_controller = UGameplayStatics::GetPlayerController(m_world, 0);
            if (player_controller->IsA(ACON_Hacker_C::StaticClass())) {
                static_cast<ACON_Hacker_C*>(player_controller)->SetIsUsingGamepad(false);
            }
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
                if (g_vr_body->HandInteractionRight->IsReachingSocket(UKismetStringLibrary::Conv_StringToName(L"LeftInnerWristSocket"), 7.0f)) {
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
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_xinput] Exception");
    }
}

void UEVRPlugin::handle_vr_menu_xinput(XINPUT_STATE* state, const UEVR_VRData* vr) {
    if (g_vr_body->VRMenu->bIsOpened) {
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
                g_vr_body->HandInteractionRight->AttachLaserPointer(true, 10.f);
            }
        }

        // Left Trigger
        if (m_gamepad_left_trigger.is_pressed()) {
            if (g_vr_body->IsEmptyHanded()) {
                g_vr_body->HandInteractionLeft->AttachLaserPointer(true, 10.f);
            }
        }

        // Right Shoulder
        if (m_gamepad_right_shoulder.is_pressed()) {
            g_vr_body->TryGrabAction(E_ENUM_VRHand::NewEnumerator1, E_ENUM_VRHandPose::NewEnumerator2);

            if (!g_vr_body->HandInteractionRight->IsHoldingWeapon) {
                g_vr_body->HandInteractionRight->SelectedPose = E_ENUM_VRHandPose::NewEnumerator3;
            }
        }
        if (m_gamepad_right_shoulder.is_released()) {
            g_vr_body->TryGrabAction(E_ENUM_VRHand::NewEnumerator1, E_ENUM_VRHandPose::NewEnumerator0);

            if (!g_vr_body->HandInteractionRight->IsHoldingWeapon) {
                g_vr_body->HandInteractionRight->SelectedPose = E_ENUM_VRHandPose::NewEnumerator0;
            }
        }

        // Left Shoulder
        if (m_gamepad_left_shoulder.is_pressed()) {
            g_vr_body->TryGrabAction(E_ENUM_VRHand::NewEnumerator0, E_ENUM_VRHandPose::NewEnumerator2);
            // set pointing hand pose
            g_vr_body->HandInteractionLeft->SelectedPose = E_ENUM_VRHandPose::NewEnumerator3;
        }
        if (m_gamepad_left_shoulder.is_released()) {
            // set undefined hand pose
            g_vr_body->HandInteractionLeft->SelectedPose = E_ENUM_VRHandPose::NewEnumerator0;
            // try releasing world object
            g_vr_body->TryGrabAction(E_ENUM_VRHand::NewEnumerator0, E_ENUM_VRHandPose::NewEnumerator0);
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_appartment_xinput] Exception");
    }
}


void UEVRPlugin::handle_citadel_station_xinput(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        // TODO: move it to BPs
        try_melee();

        m_gamepad_right_shoulder.mute_state(state);
        m_gamepad_left_shoulder.mute_state(state);

        auto player_controller = UGameplayStatics::GetPlayerController(m_world, 0);
        if (player_controller->IsA(ACON_Hacker_C::StaticClass())) {
            static_cast<ACON_Hacker_C*>(player_controller)->SetIsUsingGamepad(false);
        }

        // map jump to right thumb up
        if (state->Gamepad.sThumbRY > INPUT_DEADZONE_HI) {
            state->Gamepad.wButtons |= XINPUT_GAMEPAD_A;
        }

        // debug - show all primitive components in range
        if (m_gamepad_left_trigger.is_held() && m_gamepad_right_shoulder.is_pressed()) {
            PluginUtils::show_all_primitive_components(m_world, g_vr_body->MotionControllerRight, 100.f);
        }

        // pull out a gun when right hand is leaving backpack collision sphere
        if (m_is_pulling_out_gun && m_is_right_hand_reaching_backpack.disabled()) {
            if (
                !g_vr_body->HandInteractionRight->IsHoldingWeapon &&
                g_vr_body->HandInteractionRight->HeldGrabComponent == nullptr
                ) {
                SDK::FKey h_key_name{
                    .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
                };
                g_vr_body->HackerPawn->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_64(h_key_name);
                m_is_pulling_out_gun = false;
            }
        }

        if (m_gamepad_left_trigger.is_held() && m_gamepad_left_thumb.is_pressed()) {
            
            // testing weapon physical collisions (currently held weapons)
            // normally, held weapons have disabled collisions
            //static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->WeaponMesh->K2_AttachToComponent(
            //    g_vr_body->VRBodyMesh,
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
            //if (g_vr_body->LaserDot->LastLaserTargetActor->IsA(APAWN_Enemy_C::StaticClass())) {
            //    APAWN_Enemy_C* enemy = static_cast<APAWN_Enemy_C*>(g_vr_body->LaserDot->LastLaserTargetActor);
            //    enemy->COMP_LimbManager->SetRagdollEnabled();
            //    
            //    //static_cast<APAWN_Enemy_C*>(g_vr_body->LaserDot->LastLaserTargetComponent)->SetSimulatePhysics(true);
            //    //static_cast<APAWN_Enemy_C*>(g_vr_body->LaserDot->LastLaserTargetComponent)->SetEnableGravity(true);
            //    API::get()->log_error("[plugin][handle_citadel_station_xinput] Test physics");
            //}

            // attach laser pointer to an empty hand (only if both hands are empty)
            if (g_vr_body->IsEmptyHanded()) {
                g_vr_body->HandInteractionRight->AttachLaserPointer(true, 10.f);
            }
            
            // TODO
            // Set Laser Rapier charged mode
            if (g_vr_body->MeleeWeaponHandler->IsActive && g_vr_body->MeleeWeaponHandler->IsLaserRapier) {
                m_gamepad_right_trigger.mute_state(state);
            }
        }

        // TODO
        if (m_gamepad_right_trigger.is_held()) {
            // Set Laser Rapier charged mode
            if (g_vr_body->MeleeWeaponHandler->IsActive && g_vr_body->MeleeWeaponHandler->IsLaserRapier) {
                m_gamepad_right_trigger.mute_state(state);
            }
        }

        // TODO
        if (m_gamepad_right_trigger.is_released()) {
            // Set Laser Rapier normal mode
            if (g_vr_body->MeleeWeaponHandler->IsActive && g_vr_body->MeleeWeaponHandler->IsLaserRapier) {
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
            if (g_vr_body->IsEmptyHanded()) {
                g_vr_body->HandInteractionLeft->AttachLaserPointer(true, 10.f);
            }
        }

        // Right Shoulder
        if (m_gamepad_right_shoulder.is_pressed()) {
            // try pickup world object
            g_vr_body->HandInteractionRight->TryGrab();

            // set hand pose: pointing
            if (!g_vr_body->HandInteractionRight->IsHoldingWeapon) {
                g_vr_body->HandInteractionRight->SelectedPose = E_ENUM_VRHandPose::NewEnumerator3;

                if (g_vr_body->HandInteractionRight->IsReachingBackpack) {
                    m_is_pulling_out_gun = true;
                }
            }

            if (g_vr_body->HandInteractionRight->HeldGrabComponent == nullptr) {
                // toggle Sensaround gesture
                if (g_vr_body->HandInteractionRight->IsReachingSocket(UKismetStringLibrary::Conv_StringToName(L"MinimapSocket"), 5.0f)) {
                    m_neural_hud->WIDGET_HardwareButton_Sensaround->ToggleHardware();
                }
                // toggle MFD gesture
                else if (g_vr_body->HandInteractionRight->IsReachingSocket(UKismetStringLibrary::Conv_StringToName(L"LeftInnerWristSocket"), 7.0f)) {
                    static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->InpActEvt_Real_ToggleMFD_K2Node_InputActionEvent_43(FKey{});
                    m_gamepad_right_shoulder.mute_state(state);
                }
            }
        }
        if (m_gamepad_right_shoulder.is_released()) {
            m_is_pulling_out_gun = false;

            // toggle holster gesture
            if (
                g_vr_body->HandInteractionRight->IsReachingBackpack &&
                g_vr_body->HandInteractionRight->IsHoldingWeapon &&
                g_vr_body->HandInteractionRight->HeldGrabComponent == nullptr
                ) {
                // use holster weapon button: holster weapon
                SDK::FKey h_key_name{
                    .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
                };
                g_vr_body->HackerPawn->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_64(h_key_name);
            }

            // try releasing world object
            g_vr_body->HandInteractionRight->TryRelease();

            // set undefined hand pose if not holding a weapon
            if (!g_vr_body->HandInteractionRight->IsHoldingWeapon) {
                g_vr_body->HandInteractionRight->SelectedPose = E_ENUM_VRHandPose::NewEnumerator0;
            }
        }

        // Left Shoulder
        if (m_gamepad_left_shoulder.is_pressed()) {
            // try pickup world object
            g_vr_body->HandInteractionLeft->TryGrab();

            // set hand pose: pointing
            g_vr_body->HandInteractionLeft->SelectedPose = E_ENUM_VRHandPose::NewEnumerator3;

            // toggle energy shield gesture
            if (
                g_vr_body->HandInteractionLeft->HeldGrabComponent == nullptr &&
                g_vr_body->HandInteractionLeft->IsReachingSocket(UKismetStringLibrary::Conv_StringToName(L"RightInnerWristSocket"), 5.0f)
                ) {
                m_neural_hud->WIDGET_HardwareButton_EnergyShield->ToggleHardware();
            }
        }
        if (m_gamepad_left_shoulder.is_released()) {
            // set undefined hand pose
            g_vr_body->HandInteractionLeft->SelectedPose = E_ENUM_VRHandPose::NewEnumerator0;

            // toggle VisionUnit gesture
            if (
                g_vr_body->HandInteractionLeft->IsReachingBackpack &&
                g_vr_body->HandInteractionLeft->HeldItemCategory == E_ENUM_ItemCategory::NewEnumerator4 // None
                ) {
                API::get()->log_warn("[plugin][handle_citadel_station_xinput] Toggle VisionUnit");
                m_neural_hud->WIDGET_HardwareButton_VisionUnit->ToggleHardware();
            }

            // try releasing world object
            g_vr_body->HandInteractionLeft->TryRelease();
        }

        // Left Thumb
        if (m_gamepad_left_thumb.is_pressed()) {
            // Reset height and recenter gesture
            if (g_vr_body->HandInteractionLeft->IsReachingBackpack) {
                PluginUtils::reset_height(0.f);
                vr->recenter_view();
                if (g_vr_body->VRMenu->bIsOpened) {
                    g_vr_body->VRMenu->Close();
                    if (VRMFD::m_had_equipped_weapon && g_vr_body->IsWeaponHolstered()) {
                        VRMFD::m_had_equipped_weapon = false;
                        // use holster weapon button: take out weapon
                        SDK::FKey h_key_name{
                            .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
                        };
                        g_vr_body->HackerPawn->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_64(h_key_name);
                    }
                }
            }
        }
        if (m_gamepad_left_thumb.is_long_pressed(1.f) && g_vr_body->HandInteractionLeft->IsReachingBackpack) {
            // Open / Close VR Menu
            API::get()->log_warn("[plugin][handle_citadel_station_xinput] Left thumb long press");
            if (!g_vr_body->VRMenu->bIsOpened) {
                if (!g_vr_body->IsWeaponHolstered()) {
                    // use holster weapon button: holster weapon
                    SDK::FKey h_key_name{
                        .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
                    };
                    g_vr_body->HackerPawn->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_64(h_key_name);
                    VRMFD::m_had_equipped_weapon = true;
                }
                g_vr_body->VRMenu->Open();
            }
        }

        handle_primary_item_selector(state, vr);
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_citadel_station_xinput] Exception");
    }
}

void UEVRPlugin::handle_smooth_turning(XINPUT_STATE* state) {
    static SDK::AController* pawn_controller{ nullptr };

    try {
        if (!m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())) {
            return;
        }

        if (g_vr_body == nullptr) {
            return;
        }

        pawn_controller = m_pawn.get()->Controller;
        if (!UKismetSystemLibrary::IsValid(pawn_controller)) {
            return;
        }

        auto control_rotation = pawn_controller->GetControlRotation();
        float delta_rotation = (state->Gamepad.sThumbRX / ((11.f - m_ui_option_look_sensitivity) * 2499.0f));
        control_rotation.Yaw += delta_rotation;
        pawn_controller->SetControlRotation(control_rotation);

        g_vr_body->TrailingRotationComponent->K2_AddWorldRotation( {0.f, delta_rotation, 0.f}, false, &m_reusable_hit_result, false);

        state->Gamepad.sThumbRX = 0;
    }
    catch (...) {
        API::get()->log_error("[plugin][handle_smooth_turning] Exception");
    }
}

// with this, we don't need to manipulate game controller bindings to mute lean button
void UEVRPlugin::handle_lean() {
    if (m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())) {
        // prevent player leaning
        static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->IsTryingToLean = false;
    }
}

// try moving to BP
void UEVRPlugin::update_trailing_rotation(float delta) {
    try {
        if (g_vr_body == nullptr || m_pawn.get() == nullptr || !m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass()))
            return;

        auto pawn_controller = m_pawn.get()->Controller;
        if (!UKismetSystemLibrary::IsValid(pawn_controller)) {
            return;
        }
        auto control_rotation = pawn_controller->GetControlRotation();
        auto tc_rot = g_vr_body->TrailingRotationComponent->K2_GetComponentRotation();

        auto pawn_speed = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->COMP_MoveControlManager->CurrentSpeed;
        auto interp_speed = pow((abs(g_vr_body->VRMovementComponent->TrailingAngle) / 25.f), 5.f) + pow(pawn_speed / 100.f, 2.f);

        g_vr_body->TrailingRotationComponent->K2_SetWorldRotation(
            SDK::UKismetMathLibrary::RInterpTo(
                tc_rot,
                { 0.f, control_rotation.Yaw, 0.f },
                delta,
                interp_speed
            ),
            false, &m_reusable_hit_result, false
        );

        g_vr_body->VRBodyMesh->K2_SetWorldRotation({ 0.f, g_vr_body->TrailingRotationComponent->K2_GetComponentRotation().Yaw - 90.f, 0.f }, false, &m_reusable_hit_result, false);
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
                m_game_state.get() == GAME_STATE_APPARTMENT ||
                m_game_state.get() == GAME_STATE_CYBERSPACE
                ) {
                set_game_ui_visibility(false);
            }
            else {
                set_game_ui_visibility(true);
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
                    PluginUtils::cycle_native_stereo_fix();
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
                        m_is_pulling_out_gun = false;
                        VRBody::show_vr_body();
                        static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->bUseControllerRotationYaw = true;

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
                        vr->recenter_view();

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
                        if (UKismetSystemLibrary::IsValid(m_neural_hud)) {
                            m_neural_hud->SetVisibility(ESlateVisibility::Visible);
                        }
                        VRMFD::show_mfd();
                    }

                    break;

                case GAME_STATE_INTERACTABLE:
                    if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
                        APAWN_Hacker_Implant_C* pawn = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get());
                        API::get()->log_warn("[plugin][handle_game_state_change] Interactable: %s", pawn->ChannelingInteractableName.GetRawString().c_str());
                        if (
                            pawn->ChannelingInteractable != nullptr && (
                                pawn->ChannelingInteractable->IsA(AINTERACT_SurgeryMachine_C::StaticClass()) ||
                                pawn->ChannelingInteractable->IsA(AINTERACT_RespawnChamber_C::StaticClass())
                                )
                           ) {
                            vr->set_aim_method(0);                      // Game mode
                            vr->set_mod_value("VR_RoomscaleMovement", "false");
                            VRBody::reset_player_camera();
                            VRBody::hide_vr_body();

                            API::UObjectHook::set_disabled(true);
                        }
                    }
                    break;

                case GAME_STATE_CYBERSPACE:
                    if (m_pawn.get()->IsA(APAWN_Avatar_C::StaticClass())) {
                        APAWN_Avatar_C* pawn = static_cast<APAWN_Avatar_C*>(m_pawn.get());
                        VRAvatar::initialize_vr_avatar(pawn);
                        //g_vr_body->VRBodyMesh->SetVisibility(true, false);
                        API::UObjectHook::set_disabled(false);
                        vr->set_aim_method(0);                      // Game mode
                        vr->set_decoupled_pitch_enabled(false);
                        vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                        vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                        vr->set_mod_value("UI_Distance", "4.000000");
                        vr->set_mod_value("UI_Size", "2.000000");
                        vr->set_mod_value("UI_Y_Offset", "0.00000");
                        vr->set_mod_value("VR_RoomscaleMovement", "true");
                        vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                        vr->set_mod_value("VR_DecoupledPitch", "false");
                        PluginUtils::reset_height(0.f);
                        vr->recenter_view();
                    }
                    break;

                case GAME_STATE_APPARTMENT:
                    sdk->functions->execute_command(L"r.postprocessing.disablematerials 0");
                    m_intro_laptop = nullptr;
                    if (is_valid_vr_body_hacker_simple_pawn()) {
                        g_vr_body->VRBodyMesh->SetVisibility(true, false);
                        static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->bUseControllerRotationYaw = true;

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
                    if (UKismetSystemLibrary::IsValid(m_neural_hud)) {
                        m_neural_hud->SetVisibility(ESlateVisibility::Visible);
                    }
                    vr->set_aim_method(0);
                    vr->recenter_view();
                    vr->set_mod_value("UI_Distance", "2.000000");
                    vr->set_mod_value("UI_Size", "2.000000");
                    API::UObjectHook::set_disabled(true);
                    VRBody::hide_vr_body();
                    break;

                case GAME_STATE_CRASHING:
                    if (UKismetSystemLibrary::IsValid(m_neural_hud)) {
                        m_neural_hud->SetVisibility(ESlateVisibility::Visible);
                    }
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

void UEVRPlugin::handle_level_change() {
    try {
        if (
            (m_level.has_changed() && UKismetSystemLibrary::IsValid(m_level.get())) ||
            (m_pawn_state.has_changed())
        ) {
            API::get()->log_warn("[plugin][handle_level_change] New Level: %s", m_level.get()->GetFullName().c_str());
            API::get()->log_warn("[plugin][handle_level_change] New Pawn State: %s", PawnStateName[m_pawn_state.get()]);

            // reset pointers invalidating vr_body
            API::get()->log_warn("[plugin][handle_level_change] Actors / Pointers cleanup");
            cleanup_actors();
            cleanup_pointers();

            // Hacker Implant - Citadel Station (normal space)
            if (
                SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) &&
                m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())
            ) {
                APAWN_Hacker_Implant_C* pawn = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get());
                g_vr_body = VRBody::initialize_vr_body(pawn);

                if (g_vr_body != nullptr && m_neural_hud != nullptr) {
                    initialize_mcs(pawn);
                    VRBody::initialize_laser_dot();
                    VRBody::overwrite_hacker_crouch_animations();
                    VRBody::initialize_minimap(m_neural_hud);
                    VRBody::initialize_hacker_hardware(m_neural_hud);
                    VRBody::initialize_ads();
                    VRBody::initialize_hand_item_collisions();
                    VRItemSelector::initialize(m_neural_hud);
                    PluginUtils::reset_height(0.f);
                    
                    //VRBody::set_debug_widget_visibility(false);
                    //g_vr_body->InteractablesHighlighterLeft->Activate(true);
                    //g_vr_body->InteractablesHighlighterLeft->Enable();

                    PluginUtils::cycle_native_stereo_fix();
                }
                else {
                    API::get()->log_error("[plugin][handle_level_change] Expected valid g_vr_body");
                }
                return;
            }

            // Hacker Simple - Appartment Intro
            if (
                SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) &&
                m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())
                ) {
                APAWN_Hacker_Simple_C* pawn = static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get());
                g_vr_body = VRBody::initialize_vr_body(pawn);

                if (g_vr_body != nullptr) {
                    VRBody::initialize_laser_dot();
                    VRBody::overwrite_hacker_crouch_animations();
                    VRBody::initialize_hand_item_collisions();
                    PluginUtils::reset_height(0.f);
                    VRBody::set_debug_widget_visibility(false);

                    PluginUtils::cycle_native_stereo_fix();
                }
                else {
                    API::get()->log_error("[plugin][handle_level_change] Expected valid g_vr_body");
                }
                return;
            }

            PluginUtils::cycle_native_stereo_fix();
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
            m_is_ads_active.set_value(g_vr_body->IsAimingDownSights());

            if (m_is_ads_active.enabled()) {
                if (
                    SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) &&
                    m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())
                    ) {
                    SDK::FKey aim_key{};
                    static_cast<APAWN_Hacker_Simple_C*>(m_pawn.get())->InpActEvt_Gamepad_Real_Aim_K2Node_InputActionEvent_42(aim_key);
                }
            }

            if (m_is_ads_active.disabled()) {
                if (
                    SDK::UKismetSystemLibrary::IsValid(m_pawn.get()) &&
                    m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())
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
            vr->set_mod_value("UI_Size", "0.000000");
            vr->set_mod_value("VR_RoomscaleMovement", "false");
            vr->set_aim_method(0);

            // show VR item selector
            //g_vr_body->set_laser_pointer_visibility(true);
            g_vr_body->ItemSelectorRight->Show(20.f);
            //g_vr_body->ItemSelectorLeft->Hide();

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

        if (m_gamepad_right_trigger.is_pressed()) {
            send_mouse(VK_LBUTTON, false);
        }

        if (m_gamepad_right_trigger.is_released()) {
            send_mouse(VK_LBUTTON, true);
        }

        if (m_gamepad_right_shoulder.is_pressed()) {
            send_mouse(VK_RBUTTON, false);
        }

        if (m_gamepad_right_shoulder.is_released()) {
            send_mouse(VK_RBUTTON, true);
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
    try {
        API::get()->log_warn("[plugin][cleanup_actors] Starting Actors Cleanup");
        auto world = UWorld::GetWorld();
        if (!UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_error("[plugin][cleanup_actors] Invalid World");
            return;
        }

        PluginUtils::destroy_actors_by_tag(world, UKismetStringLibrary::Conv_StringToName(L"VRModActor"));
        PluginUtils::destroy_actors_by_class(world, A_BP_VRAvatar_C::StaticClass());

        g_vr_body = nullptr;
    }
    catch (...) {
        API::get()->log_error("[plugin][cleanup_actors] Exception");
    }
}


//// -------------------------------------------------------------------------------------
//// ImGui
//// -------------------------------------------------------------------------------------
//void UEVRPlugin::internal_frame() {
//    try {
//        if (!API::get()->param()->functions->is_drawing_ui()) {
//            return;
//        }
//        static const char* MOD_NAME = "System Shock UEVR plugin [v2.0.0-alpha.0]";
//        static const auto NO_PAWN = std::format("Invalid Pawn");
//        static const char* LOOK_SENSITIVITY = "Look Sensitivity";
//        static const char* SHOW_DEBUG = "Show Debug View";
//        static const char* CURRENT_PAWN_STATE = "Current Pawn State";
//        static const char* APPLY_WEAPON_OFFSET_WEAPON = "Apply Weapon Offset";
//        static const char* CURRENT_WEAPON = "Current Weapon";
//
//        constexpr auto window_w = 500.0f;
//        constexpr auto window_h = 500.0f;
//
//        if (m_pawn.get() == nullptr) {
//            ImGui::SetNextWindowSize(ImVec2(window_w, window_h), ImGuiCond_::ImGuiCond_Once);
//            if (ImGui::Begin(MOD_NAME)) {
//                ImGui::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), NO_PAWN.c_str());
//            }
//            ImGui::End();
//            return;
//        }
//
//        ImGui::SetNextWindowSize(ImVec2(window_w, window_h), ImGuiCond_::ImGuiCond_Once);
//        if (ImGui::Begin(MOD_VERSION)) {
//
//            ImGui::SeparatorText("General options");
//            if (g_vr_body != nullptr) {
//                if (ImGui::SliderFloat("Player Height", &g_vr_body->VRMovementComponent->PlayerHeight, 170.f, 183.f, "%1.0f")) {
//                    g_vr_body->VRMovementComponent->AdjustComponentsToPlayerHeight(g_vr_body->VRMovementComponent->PlayerHeight);
//                    PluginUtils::reset_height(0.f);
//                }
//            }
//
//            ImGui::SeparatorText("Debugging");
//            ImGui::Checkbox("Show debug", &m_ui_option_show_debug_view);
//            if (m_ui_option_show_debug_view) {
//                ImGui::BeginGroup();
//                ImGui::BeginDisabled();
//                
//                ImGui::InputText("Game State", (char*)GameStateName[m_game_state.get()], 20);
//                
//                ImGui::EndDisabled();
//                ImGui::EndGroup();
//
//                // timers
//                ImGui::SeparatorText("Timers [microseconds]");
//                ImGui::BeginGroup();
//                ImGui::BeginDisabled();
//                ImGui::PushItemWidth(50);
//                ImGui::InputInt("XInput duration", &m_ui_xinput_duration, 0, 0);
//                ImGui::InputInt("PreEngineTick duration", &m_ui_pre_engine_tick_duration, 0, 0);
//                ImGui::PopItemWidth();
//                ImGui::EndDisabled();
//                ImGui::EndGroup();
//            }
//        }
//        ImGui::End();
//    }
//    catch (...) {
//        API::get()->log_error("[plugin][internal_frame] Exception");
//    }
//}
//
//
//
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
//        internal_frame();
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
//        internal_frame();
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

    if (m_pawn.get() == nullptr || !m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
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

    if (m_pawn.get() == nullptr || !m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())) {
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

        auto world = UWorld::GetWorld();
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

        g_vr_body->WristOffsetRight->K2_AttachToComponent(
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

void UEVRPlugin::set_game_ui_visibility(bool visible) {
    if (UKismetSystemLibrary::IsValid(m_neural_hud)) {
        m_neural_hud->SetVisibility(visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
    }
}

void UEVRPlugin::try_melee() {
    static UAnimMontage* montage{ nullptr };
    try {
        if (g_vr_body != nullptr && g_vr_body->MeleeWeaponHandler != nullptr) {
            m_UEVR_process_damage.set_value(g_vr_body->MeleeWeaponHandler->UEVRProcessDamage);

            if (m_UEVR_process_damage.enabled()) {
                API::get()->log_warn("[plugin][try_melee] Process Montage");

                if (g_vr_body->IsTwoHandingWeapon()) {
                    //API::get()->log_warn("[plugin][try_melee] Two handed swing");
                    g_vr_body->MeleeWeaponHandler->WeaponItemRef->GetPowerSwingToIdleMontage(ENUM_LeftRightCenter::NewEnumerator0, &montage);
                }
                else {
                    g_vr_body->MeleeWeaponHandler->WeaponItemRef->GetRandomFastAttack(&montage);
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
                g_vr_body->MeleeWeaponHandler->WeaponItemRef->OnStartedMeleeAttack(false);

                // applies damage
                // this call can also apply stamina drain mod (test it)

                // force power swing by setting IsBeserk to true, then reset it to prev value
                //prev_is_beserk = melee_weapon->IsBerserk;

                g_vr_body->MeleeWeaponHandler->WeaponItemRef->TryDealDamageFromHitResult(g_vr_body->MeleeWeaponHandler->ReusableOutHit, &hit);
                //melee_weapon->IsBerserk = prev_is_beserk;

                action->StopMontage(0.2f);
                //action_manager->UpdateActiveAction(1.f);

                g_vr_body->MeleeWeaponHandler->WeaponItemRef->DisableDamage(&result);
                g_vr_body->MeleeWeaponHandler->WeaponItemRef->HitActors.Clear();
                bool end_action_result{ false };

                action_manager->ForceEndCurrentAction(nullptr, 0.2f);
                g_vr_body->MeleeWeaponHandler->WeaponItemRef->DisableDamage(&result);

                if (g_vr_body->MeleeWeaponHandler->IsLaserRapier) {
                    g_vr_body->MeleeWeaponHandler->TryUpdateLaserPowerLevel(0.2f);
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
        API::get()->log_error("[main][set_intro_laptop_pointer] Exception");
    }
}
