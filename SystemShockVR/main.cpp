#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/PAWN_Hacker_Simple_classes.hpp"

#include "main.hpp"
#include "vr_weapon.hpp"
#include "vr_body.hpp"
//#include "hud.hpp"
#include "plugin_utils.hpp"

using namespace uevr;

SystemShockMain::SystemShockMain() {
    try {
        API::get()->log_warn("[main] Constructor");
        m_vr_controllers = new VRControllers();
        m_vr_weapon = new VRWeapon(this);
        m_vr_body = new VRBody(this);
        //m_vr_hud = new OuterWorldsHUD(this);
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
        handle_level_change();
        handle_game_state();
        //handle_mod_events();
        //handle_crouch();
        //handle_weapon();

        if (m_vr_weapon->is_valid()) {
            m_vr_weapon->on_tick();
        }


        //AnimCameraPosition

        //if (
        //    m_pawn->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass()) ||
        //    m_pawn->IsA(SDK::APAWN_Hacker_Simple_C::StaticClass())
        //    ) {
        //    //if (static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera == nullptr) {
        //    //    API::get()->log_warn("[main][on_tick] LookPivot nullptr");
        //    //    return;
        //    //}

        //    //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->DetachFromParent(true, false);

        //    SDK::FVector rhmc_location = get_vr_controllers()->get_rh_controller_component()->K2_GetComponentLocation();
        //    SDK::FRotator rhmc_rotation = get_vr_controllers()->get_rh_controller_component()->K2_GetComponentRotation();
        //    //API::get()->log_warn("[main][set_component_loc_rot_to_rh_motion_controller] RotX: %f", rhmc_rotation.Pitch);
        //    //API::get()->log_warn("[main][set_component_loc_rot_to_rh_motion_controller] RotY: %f", rhmc_rotation.Roll);
        //    //API::get()->log_warn("[main][set_component_loc_rot_to_rh_motion_controller] RotZ: %f", rhmc_rotation.Yaw);

        //    //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->SetAbsolute(true, true, false);
        //    //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->SetMobility(SDK::EComponentMobility::Static);
        //    if (!m_camera_initialized && static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->LookPivot->AttachParent != nullptr) {
        //        //API::get()->log_warn("[main][on_tick] WeaponMesh detaching");
        //        //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->WeaponMesh->DetachFromParent(true, false);


        //        API::get()->log_warn("[main][on_tick] LookPivot initializing");
        //        static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->LookPivot->DetachFromParent(true, true);
        //        //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->LookPivot->K2_AttachToComponent(
        //        //    static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->WeaponMesh,
        //        //    SDK::UKismetStringLibrary::Conv_StringToName(L"barrel"),
        //        //    SDK::EAttachmentRule::SnapToTarget,
        //        //    SDK::EAttachmentRule::KeepRelative,
        //        //    SDK::EAttachmentRule::KeepRelative,
        //        //    true
        //        //);
        //        m_camera_initialized = true;
        //        API::get()->log_warn("[main][on_tick] PlayerCamera initialized");
        //    }
        //    //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->K2_SetWorldRotation(rhmc_rotation, false, &m_hit_result, false);
        //    /*static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->RelativeLocation.X = rhmc_location.X;
        //    static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->RelativeLocation.Y = rhmc_location.Y;
        //    static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->RelativeLocation.Z = rhmc_location.Z;
        //    static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->RelativeRotation.Pitch = rhmc_rotation.Pitch;*/
        //    //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->PlayerCamera->RelativeRotation.Yaw = rhmc_rotation.Yaw;
        //    //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->LookPivot->RelativeRotation.Pitch = rhmc_rotation.Pitch;
        //    /*static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->LookPivot->K2_SetWorldRotation({ 0.0f, 0.0f, 90.0f }, false, &m_hit_result, false);*/

        //    if (static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->Mesh == nullptr) {
        //        API::get()->log_warn("[main][on_tick] Mesh nullptr");
        //        return;
        //    }

        //    //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->Mesh->AnimScriptInstance = nullptr;

        //    //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->AnimCameraPosition->SetAbsolute(false, true, false);
        //    //static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->AnimCameraPosition->K2_SetWorldLocation(rhmc_location, false, &m_hit_result, false);
        //}

    }
    catch (...) {
        API::get()->log_error("[main][on_tick] Exception");
        return;
    }
}

void SystemShockMain::cleanup_pointers() {
    try {
        API::get()->log_warn("[main][cleanup] Starting Pointers Cleanup");

        if (m_vr_weapon != nullptr) {
            m_vr_weapon->cleanup_pointers();
        }
        //if (m_vr_hud != nullptr) {
        //    m_vr_hud->cleanup_pointers();
        //}
        if (m_vr_controllers != nullptr) {
            m_vr_controllers->cleanup_pointers();
        }
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
    VRControllers::cleanup_actors();
    VRBody::cleanup_actors();
}

// -------------------------------------------------------------------------------------
// pointers and state
// -------------------------------------------------------------------------------------
bool SystemShockMain::prepare_pointers() {
    try {
        // world
        m_world = SDK::UWorld::GetWorld();
        // pawn
        m_pawn = m_world != nullptr ? SDK::UGameplayStatics::GetPlayerPawn(m_world, 0) : nullptr;
        if (m_pawn == nullptr) {
            API::get()->log_error("[main][prepare_pointers] Player PAWN Error");
            return false;
        }

        if (
            m_pawn->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass()) ||
            m_pawn->IsA(SDK::APAWN_Hacker_Simple_C::StaticClass())
        ) {
            m_inventory = static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->COMP_HackerInventory;
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

        // pause
        m_is_game_paused.set_value(m_world != nullptr ? SDK::UGameplayStatics::IsGamePaused(m_world) : true);

        if (
            m_pawn->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass()) ||
            m_pawn->IsA(SDK::APAWN_Hacker_Simple_C::StaticClass())
            ) {
            m_player_interacting.set_value(static_cast<SDK::APAWN_Hacker_Simple_C*>(m_pawn)->ChannelingInteractable != nullptr);
        }
    }
    catch (...) {
        API::get()->log_error("[main][prepare_state] Exception");
    }
}

void SystemShockMain::prepare_game_state() {
    try {
        if (!SDK::UKismetSystemLibrary::IsValid(m_pawn)) {
            m_game_state.set_value(GAME_STATE_UNDEFINED);
            return;
        }

        //if (SDK::UKismetSystemLibrary::IsValid(m_pawn) && m_pawn->IsA(SDK::ADefaultPawn::StaticClass())) {
        //    m_game_state.set_value(GAME_STATE_MAIN_MENU);
        //    return;
        //}

        if (m_is_game_paused.value) {
            m_game_state.set_value(GAME_STATE_PAUSE_MENU);
            return;
        }

        m_game_state.set_value(GAME_STATE_PLAYING);
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
        m_gamepad_btn_a.set_state(state);
        //m_gamepad_btn_x.set_state(state);
        //m_gamepad_btn_b.set_state(state);
        //m_gamepad_btn_y.set_state(state);
        //m_gamepad_right_shoulder.set_state(state);
        m_gamepad_left_shoulder.set_state(state);
        //m_gamepad_right_thumb.set_state(state);
        m_gamepad_left_thumb.set_state(state);
        m_gamepad_trigger_right.set_state(state);
        //m_gamepad_trigger_left.set_state(state);


        //if (m_gamepad_left_thumb.is_long_pressed(2.f)) {
        //    if (m_flicker_fixer->is_valid()) {
        //        m_flicker_fixer->cycle(50);
        //    }
        //}

        if (
            m_pawn->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass())
            ) {
            if (m_vr_body != nullptr) {
                if (m_gamepad_left_shoulder.is_held()) {
                    m_vr_body->get_bp_actor()->Set_Hand_Pose(SDK::E_VRHandState::CanGrab, false);
                }
                if (m_gamepad_left_shoulder.is_released()) {
                    m_vr_body->get_bp_actor()->Set_Hand_Pose(SDK::E_VRHandState::Open, false);
                }
                if (m_gamepad_trigger_right.is_pressed()) {
                    m_gamepad_trigger_right.mute_state(state);
                    m_vr_weapon->fire_weapon();
                    return;
                }
            }

            if (m_gamepad_left_thumb.is_pressed()) {
                API::get()->log_warn("[main][handle_controller_input] m_gamepad_left_thumb pressed");
                SDK::FKey tab_key{
                    .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"Tab")
                };

                static_cast<SDK::APAWN_Hacker_Implant_C*>(m_pawn)->InpActEvt_Gamepad_Real_ToggleMFD_K2Node_InputActionEvent_36(tab_key);
            }
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_controller_input] Exception");
    }
}


void SystemShockMain::handle_smooth_turning(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        if (
            !m_pawn->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass()) ||
            !m_pawn->IsA(SDK::APAWN_Hacker_Simple_C::StaticClass())
            ) {
            return;
        }

        char snap_angle[16] = { 0 };
        vr->get_mod_value("VR_SnapturnTurnAngle", snap_angle, sizeof(snap_angle));
        int snap_angle_int = atoi(snap_angle);

        // verify if smooth turning conditions have been met
        if (snap_angle_int == 359) {
            vr->set_snap_turn_enabled(false);
            auto pawn_controller = m_pawn->Controller;
            if (pawn_controller == nullptr) {
                return;
            }

            auto control_rotation = pawn_controller->GetControlRotation();
            control_rotation.Yaw += (state->Gamepad.sThumbRX / ((11.f - m_ui_option_look_sensitivity) * 2499.0f));
        }
    }
    catch (...) {
        API::get()->log_error("[main][handle_smooth_turning] Exception");
    }
}


void SystemShockMain::set_component_loc_rot_to_rh_motion_controller(SDK::USceneComponent* scene_component) {
    try {
        scene_component->SetAbsolute(true, true, true);
        SDK::FVector rhmc_location = get_vr_controllers()->get_rh_controller_component()->K2_GetComponentLocation();

        //API::get()->log_warn("[main][set_component_loc_rot_to_rh_motion_controller] PosX: %f", rhmc_location.X);
        //API::get()->log_warn("[main][set_component_loc_rot_to_rh_motion_controller] PosY: %f", rhmc_location.Y);
        //API::get()->log_warn("[main][set_component_loc_rot_to_rh_motion_controller] PosZ: %f", rhmc_location.Z);

        SDK::FRotator rhmc_rotation = get_vr_controllers()->get_rh_controller_component()->K2_GetComponentRotation();

        scene_component->K2_SetWorldLocationAndRotation(rhmc_location, rhmc_rotation, false, &m_hit_result, false);
    }
    catch (...) {
        API::get()->log_error("[set_component_loc_rot_to_rh_motion_controller] Exception");
    }
}

// -------------------------------------------------------------------------------------
// handlers
// -------------------------------------------------------------------------------------
void SystemShockMain::handle_game_state() {
    return;

    try {
        if (m_game_state.has_changed()) {
            API::get()->log_warn("[main][handle_game_state] New Game State: %s", GameStateName[m_game_state.value]);
            const UEVR_VRData* vr = API::get()->param()->vr;

            switch (m_game_state.value) {
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

            case GAME_STATE_PLAYING:
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
                m_vr_weapon->set_laser_pointer_visibility(true);
                break;
            }
        }
    }
    catch (...) {
        API::get()->log_error("[handle_game_state] Exception");
    }
}

void SystemShockMain::handle_level_change() {
    try {
        if (m_level.has_changed() && m_level.value != nullptr) {
            const UEVR_VRData* vr = API::get()->param()->vr;

            auto level_name = m_level.value->GetFullName();
            API::get()->log_warn("[main][handle_level_change] New Level: %s", level_name.c_str());

            if (m_game_state.value != GAME_STATE_MAIN_MENU) {
                API::get()->log_warn("[main][handle_level_change] Initialize components");

                m_vr_controllers->initialize();
                m_vr_weapon->initialize(RIGHT_HANDED);
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
                SDK::UGameplayStatics::SetEnableWorldRendering(m_world, true);
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
        //if (SDK::UKismetSystemLibrary::IsValid(m_player_character)) {
        //    auto equipment = static_cast<SDK::AIndianaPlayerCharacter_BP_C*>(m_player_character)->Equipment;
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
                ImGui::InputText("Game State", (char*)GameStateName[m_game_state.value], 20);
                ImGui::Checkbox("IsPaused", &m_is_game_paused.value);
                ImGui::EndDisabled();
                ImGui::EndGroup();

                if (m_vr_weapon != nullptr) {
                    m_vr_weapon->on_draw_imgui();
                }

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
