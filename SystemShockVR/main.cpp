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

//#include "SDK/ANIMBP_MiniPistol_classes.hpp"
#include "SDK/_CH_Hacker_Rig_Skeleton_AnimBlueprint_classes.hpp"

#include "main.hpp"

#include "vr_body.hpp"
//#include "hud.hpp"
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
    handle_controller_input(state);
    handle_smooth_turning(state, vr);
}

void SystemShockMain::on_tick(float delta) {

    try {
        handle_game_state_changes();
        handle_level_changes();
        //handle_mod_events();
        //handle_crouch();
        //handle_weapon();

        if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
            m_vr_body->on_tick();
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

        //if (m_vr_weapon != nullptr) {
        //    m_vr_weapon->cleanup_pointers();
        //}
        //if (m_vr_hud != nullptr) {
        //    m_vr_hud->cleanup_pointers();
        //}
        //if (m_vr_controllers != nullptr) {
        //    m_vr_controllers->cleanup_pointers();
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
    }
    catch (...) {
        API::get()->log_error("[main][prepare_pointers] Exception");
        return false;
    }
    return true;
}

// sets state vars, so we can use them later in handlers
void SystemShockMain::prepare_state() {
    try {
        // level
        m_level.set_value(m_world != nullptr ? m_world->PersistentLevel : nullptr);

    }
    catch (...) {
        API::get()->log_error("[main][prepare_state] Exception");
    }
}

void SystemShockMain::prepare_game_state() {
    try {
        if (m_world == nullptr) {
            m_game_state.set_value(GAME_STATE_UNDEFINED);
            return;
        }

        if (!UKismetSystemLibrary::IsValid(m_pawn.get())) {
            m_game_state.set_value(GAME_STATE_UNDEFINED);
            return;
        }
        
        // GAME_STATE_MAIN_MENU,
        if (m_pawn.get()->IsA(APAWN_PlayerGhost_C::StaticClass())) {
            m_game_state.set_value(GAME_STATE_MAIN_MENU);
            return;
        }

        // GAME_STATE_PAUSE_MENU
        static UWIDGET_MainMenu_InGame_C* main_menu{ nullptr };

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
        static APlayerCameraManager* player_camera_manager = UGameplayStatics::GetPlayerCameraManager(m_world, 0);
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
        // TODO:

        // all previous check are false
        m_game_state.set_value(GAME_STATE_UNDEFINED);
    }
    catch (...) {
        API::get()->log_error("[main][prepare_game_state] Exception");
    }
}

// -------------------------------------------------------------------------------------
// controller input
// -------------------------------------------------------------------------------------
void SystemShockMain::handle_controller_input(XINPUT_STATE* state) {
    try {
        //m_gamepad_btn_a.set_and_mute_state(state);
        //m_gamepad_btn_x.set_state(state);
        //m_gamepad_btn_b.set_state(state);
        //m_gamepad_btn_y.set_state(state);
        //m_gamepad_right_shoulder.set_state(state);
        m_gamepad_left_shoulder.set_and_mute_state(state);
        m_gamepad_right_thumb.set_state(state);
        m_gamepad_left_thumb.set_state(state);
        m_gamepad_trigger_right.set_state(state);
        //m_gamepad_trigger_left.set_state(state);


        //if (m_gamepad_left_thumb.is_long_pressed(2.f)) {
        //    if (m_flicker_fixer->is_valid()) {
        //        m_flicker_fixer->cycle(50);
        //    }
        //}

        if (m_game_state.get() == GAME_STATE_CITADEL_STATION) {
            if (m_vr_body == nullptr) {
                return;
            }

            if (m_gamepad_left_shoulder.is_pressed()) {
                //m_vr_body->get_bp_actor()->TryGrabItemLeft();
                //UGrabComponent_C* nearest{ nullptr };
                //m_vr_body->get_bp_actor()->GetGrabComponentNearMotionController(m_vr_body->get_bp_actor()->MotionControllerLeft, &nearest);

                //m_vr_body->log_overlapping_objects();

                //API::get()->log_warn("[main][handle_controller_input] TryGrabItemLeft");
                //if (nearest != nullptr) {
                //    API::get()->log_warn("[main][handle_controller_input] FOUND");
                //}
                //else {
                //    API::get()->log_warn("[main][handle_controller_input] NOT FOUND");
                //}
                m_vr_body->get_bp_actor()->Set_Hand_Pose(E_ENUM_VRHandState::NewEnumerator1, false);
            }

            if (m_gamepad_left_shoulder.is_released()) {
                //m_vr_body->get_bp_actor()->TryReleaseItemLeft();
                //API::get()->log_warn("[main][handle_controller_input] TryReleaseItemLeft");
                m_vr_body->get_bp_actor()->Set_Hand_Pose(E_ENUM_VRHandState::NewEnumerator0, false);
            }

            //if (m_gamepad_trigger_right.is_pressed()) {
            //    m_gamepad_trigger_right.mute_state(state);
            //    m_vr_weapon->fire_weapon();
            //    return;
            //}

            //if (m_gamepad_btn_a.is_pressed()) {
            //    if (m_vr_body != nullptr && m_vr_weapon != nullptr) {
            //        m_vr_body->get_bp_actor()->PlayUnloadGunAnim();
            //        m_vr_weapon->empty_magazine();
            //    }
            //}
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_controller_input] Exception");
    }
}


void SystemShockMain::handle_smooth_turning(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        if (
            !m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass()) ||
            !m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())
            ) {
            return;
        }

        char snap_angle[16] = { 0 };
        vr->get_mod_value("VR_SnapturnTurnAngle", snap_angle, sizeof(snap_angle));
        int snap_angle_int = atoi(snap_angle);

        // verify if smooth turning conditions have been met
        if (snap_angle_int == 359) {
            vr->set_snap_turn_enabled(false);
            auto pawn_controller = m_pawn.get()->Controller;
            if (pawn_controller == nullptr) {
                return;
            }

            auto control_rotation = pawn_controller->GetControlRotation();
            control_rotation.Yaw += (state->Gamepad.sThumbRX / ((11.f - m_ui_option_look_sensitivity) * 2499.0f));
            pawn_controller->SetControlRotation(control_rotation);
            //API::get()->log_warn("[main][handle_smooth_turning] Applied Rotation");
            
            state->Gamepad.sThumbRX = 0;
            
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_smooth_turning] Exception");
    }
}

void SystemShockMain::test1()
{
    if (m_pawn.get() != nullptr && m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
        //static_cast<APAWN_Hacker_Implant_C*>(m_pawn)->SetCharacterVisible(false);
    }
}

void SystemShockMain::test2()
{
    API::get()->log_warn("[main][test2] Start");
    if (m_pawn.get() != nullptr && m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
        API::get()->log_warn("[main][test2] Step 1");
        auto anim_inst = m_vr_body->get_bp_actor()->CurrentWeapon->GetAnimInstance();

        auto pawn_anim_inst = m_vr_body->get_bp_actor()->VRBodyMesh->GetAnimInstance();
        if (pawn_anim_inst != nullptr && pawn_anim_inst->IsA(U_CH_Hacker_Rig_Skeleton_AnimBlueprint_C::StaticClass())) {
            API::get()->log_warn("[main][test2] Step 2");
            static_cast<U_CH_Hacker_Rig_Skeleton_AnimBlueprint_C*>(pawn_anim_inst)->SourceMeshComponent = static_cast<APAWN_Hacker_Implant_C*>(m_pawn.get())->Mesh;
            static_cast<U_CH_Hacker_Rig_Skeleton_AnimBlueprint_C*>(pawn_anim_inst)->LegsUseSourceMesh = true;
        }

        //static_cast<APAWN_Hacker_Implant_C*>(m_pawn)->SetCharacterVisible(true);
    }
    API::get()->log_warn("[main][test2] End");
}


//void SystemShockMain::set_component_loc_rot_to_rh_motion_controller(USceneComponent* scene_component) {
//    try {
//        scene_component->SetAbsolute(true, true, true);
//        FVector rhmc_location = get_vr_controllers()->get_rh_controller_component()->K2_GetComponentLocation();
//
//        //API::get()->log_warn("[main][set_component_loc_rot_to_rh_motion_controller] PosX: %f", rhmc_location.X);
//        //API::get()->log_warn("[main][set_component_loc_rot_to_rh_motion_controller] PosY: %f", rhmc_location.Y);
//        //API::get()->log_warn("[main][set_component_loc_rot_to_rh_motion_controller] PosZ: %f", rhmc_location.Z);
//
//        FRotator rhmc_rotation = get_vr_controllers()->get_rh_controller_component()->K2_GetComponentRotation();
//
//        scene_component->K2_SetWorldLocationAndRotation(rhmc_location, rhmc_rotation, false, &m_hit_result, false);
//    }
//    catch (...) {
//        API::get()->log_error("[set_component_loc_rot_to_rh_motion_controller] Exception");
//    }
//}

// -------------------------------------------------------------------------------------
// handlers
// -------------------------------------------------------------------------------------
void SystemShockMain::handle_game_state_changes() {
    return;

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
                PluginUtils::reset_height(0.f);
                vr->recenter_view();
                break;

            case GAME_STATE_CITADEL_STATION:
                API::UObjectHook::set_disabled(false);
                vr->set_aim_method(2);
                vr->set_decoupled_pitch_enabled(true);
                vr->set_mod_value("VR_CameraForwardOffset", "0.000000");
                vr->set_mod_value("VR_CameraUpOffset", "0.000000");
                vr->set_mod_value("UI_Distance", "2.000000");
                vr->set_mod_value("UI_Size", "1.200000");
                vr->set_mod_value("UI_Y_Offset", "0.00000");
                vr->set_mod_value("VR_RoomscaleMovement", "true");
                vr->set_mod_value("VR_DecoupledPitchUIAdjust", "true");
                PluginUtils::reset_height(0.f);
                vr->recenter_view();
                //m_vr_weapon->set_laser_pointer_visibility(true);
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
            const UEVR_VRData* vr = API::get()->param()->vr;

            auto level_name = m_level.get()->GetFullName();
            API::get()->log_warn("[main][handle_level_change] New Level: %s", level_name.c_str());

            if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
                API::get()->log_warn("[main][handle_level_change] Initialize components");

                m_vr_body->initialize();
                //load_mod_config();
            }
            else {
                API::get()->log_warn("[main][handle_level_change] Components cleanup");
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
    if (m_is_crouched.has_changed()) {
        PluginUtils::reset_height(0.f);
    }
}

void SystemShockMain::handle_weapon() {
    try {
        // equipped weapon
        //if (UKismetSystemLibrary::IsValid(m_player_character)) {
        //    auto equipment = static_cast<AIndianaPlayerCharacter_BP_C*>(m_player_character)->Equipment;
        //    if (equipment != nullptr) {
        //        m_vr_weapon->set_equipped_weapon(equipment->GetEquippedWeapon());
        //    }
        //}
    }
    catch (...) {
        API::get()->log_error("[main][handle_weapon] Exception");
    }
}


// -------------------------------------------------------------------------------------
// fixes
// -------------------------------------------------------------------------------------



// -------------------------------------------------------------------------------------
// setters
// -------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------
// hooks
// -------------------------------------------------------------------------------------
//Weapon trace hook
//void SystemShockMain::hook_onfire_fn() {
//    m_onfire_hook_id = hook_vtable_fn(L"Class /Script/GunfireRuntime.RangedWeapon", L"OnFire", on_get_onfire, (void**)&m_onfire_hook_fn);
//}

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
        static const auto NO_PAWN = std::format("No Pawn detected!");

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

            if (ImGui::Button("Test BTN1")) {
                test1();
            }
            if (ImGui::Button("Test BTN2")) {
                test2();
            }

            ImGui::PopItemWidth();

            //if (m_vr_hud != nullptr) {
            //    m_vr_hud->on_draw_imgui();
            //}

            ImGui::SeparatorText("Debugging");
            // game state section
            ImGui::Checkbox("Show debug", &m_ui_option_show_debug_view);
            if (m_ui_option_show_debug_view) {
                ImGui::BeginGroup();
                ImGui::BeginDisabled();
                ImGui::InputText("Game State", (char*)GameStateName[m_game_state.get()], 20);
                ImGui::Checkbox("IsPaused", &m_is_game_paused.value);
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


void SystemShockMain::set_last_pos(UEVR_Vector3f* position) {
    m_last_pos = { position->x, position->y, position->z };
}

void SystemShockMain::set_last_rot(UEVR_Rotatorf* rotation) {
    m_last_rot = { rotation->pitch, rotation->yaw, rotation->roll };
}

void SystemShockMain::apply_delta(UEVR_Vector3f* position, UEVR_Rotatorf* rotation) {
    try {
        //if (
        //    m_pawn != nullptr &&
        //    m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass()) ||
        //    m_pawn.get()->IsA(APAWN_Hacker_Simple_C::StaticClass())
        //    ) {

        //    //static_cast<APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->SetAbsolute(false, true, false);
        //    FRotator rot = static_cast<APAWN_Hacker_Simple_C*>(m_pawn)->WeaponMesh->K2_GetComponentRotation();
        //    static_cast<APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->K2_SetRelativeRotation(
        //        { rot.Pitch, 0.f, 0.f }, false, &m_hit_result, false
        //    );

        //    const UEVR_VRData* vr = API::get()->param()->vr;
        //    if (!vr->is_runtime_ready())
        //        return;
        //    vr->recenter_view();
        //}
    }
    catch (...) {
        API::get()->log_error("[main][set_last_pos] Exception");
    }

    //local hmdrot = hmd_component:K2_GetComponentRotation()
    //    local rotdelta = hmdrot - last_rot

    //    -- Fix up the rotation delta
    //    if rotdelta.x > 180 then
    //        rotdelta.x = rotdelta.x - 360
    //        elseif rotdelta.x < -180 then
    //        rotdelta.x = rotdelta.x + 360
    //        end

    //        if rotdelta.y > 180 then
    //            rotdelta.y = rotdelta.y - 360
    //            elseif rotdelta.y < -180 then
    //            rotdelta.y = rotdelta.y + 360
    //            end

    //            if rotdelta.z > 180 then
    //                rotdelta.z = rotdelta.z - 360
    //                elseif rotdelta.z < -180 then
    //                rotdelta.z = rotdelta.z + 360
    //                end
}