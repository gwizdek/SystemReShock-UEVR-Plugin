#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/PAWN_Hacker_Simple_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/WIDGET_SimpleHUD_classes.hpp"

#include "main.hpp"

#include "vr_mfd.hpp"

using namespace uevr;
using namespace SDK;

VRMFD::VRMFD() {
    try {
        API::get()->log_warn("[vr_mfd] Constructor");
    }
    catch (...) {
        API::get()->log_error("[vr_mfd][constructor] Exception");
        return;
    }
};

VRMFD::~VRMFD() {
    API::get()->log_warn("[vr_mfd] Destructor");
}

void VRMFD::on_xinput(XINPUT_STATE* state, const UEVR_VRData* vr) {
    handle_controller_input(state, vr);
    handle_smooth_turning(state, vr);
}

void VRMFD::on_tick(float delta) {

    try {
        handle_game_state_changes();
        handle_level_changes();
        //handle_mod_events();
        //handle_crouch();
        //handle_weapon();

        if (m_pawn.get()->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
            if (m_skip_tick_count > 0) {
                API::get()->log_warn("[main][on_tick] Skipping Tick");
                m_skip_tick_count--;
                return;
            }

            //try_running_test_1();
            //try_running_test_2();

            if (m_vr_body != nullptr && m_vr_body->is_valid()) {
                m_vr_body->on_tick();
            }
        }
    }
    catch (...) {
        API::get()->log_error("[main][on_tick] Exception");
        return;
    }
}

void VRMFD::cleanup_pointers() {
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

void VRMFD::cleanup_actors() {
    API::get()->log_warn("[main][cleanup] Starting Actors Cleanup");
    VRBody::cleanup_actors();
}



void VRMFD::handle_mod_events() {
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


// -------------------------------------------------------------------------------------
// MFD
// -------------------------------------------------------------------------------------
void VRMFD::handle_mfd_interactions(XINPUT_STATE* state, const UEVR_VRData* vr) {
    try {
        if (m_vr_hud != nullptr && m_vr_hud->get_hud_state() == VR_HUD_SUCCESS) {
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
    catch (...) {
        API::get()->log_error("[main][handle_mfd_interactions] Exception");
    }
}

void VRMFD::handle_mfd_changes(const UEVR_VRData* vr) {
    try {
        static int m_viewport_size_x = 0;
        static int m_viewport_size_y = 0;
        if (m_pawn_state.value != PAWN_HACKERIMPLANT) {
            return;
        }

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
            }
            catch (std::invalid_argument) {
                API::get()->log_info("Handle MFD Changes :: Error converting UEVR world scale value to float");
            }

            char ui_distance[32];
            char ui_size[32];
            int ret_ui_distance = snprintf(ui_distance, sizeof ui_distance, "%f", (1.f / world_scale) * ((m_vr_hud->get_mfd_depth() / 100.f)));
            int ret_ui_size = snprintf(ui_size, sizeof ui_size, "%f", (float)((1.f / world_scale) * (m_viewport_size_y / 1000.f)));
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
    catch (...) {
        API::get()->log_error("[main][handle_mfd_changes] Exception");
    }
}

// sends mouse inputs to OS (thanks markmon)
void VRMFD::send_mouse(WORD key, bool key_up) {
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