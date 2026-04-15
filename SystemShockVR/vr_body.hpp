#pragma once

#include "SDK/Engine_structs.hpp"
#include "SDK/COMP_HackerInventory_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"

#include "SDK/_BP_VRBody_classes.hpp"

class VRBody final
{
private:
    static inline float m_mfd_depth{ 150.f };

public:
    static SDK::A_BP_VRBody_C* initialize_vr_body(SDK::APAWN_Hacker_Implant_C* pawn);
    static void initialize_laser_dot();
    static void overwrite_hacker_crouch_animations();
    static void set_weapon_mesh_visibility(bool visible);
    static void set_player_response_to_collision_channel(SDK::ECollisionChannel channel, SDK::ECollisionResponse response);
    static void reset_player_camera();
    static void show_vr_body();
    static void hide_vr_body();
    static bool is_valid_hacker_implant();
    static void initialize_ads();

    // Minimap / Media Display
    static void initialize_minimap(SDK::UWIDGET_PlayerHUD_C* neural_hud);
    static void set_media_display_visibility(bool visible);

    // Hacker Hardware
    static void initialize_hacker_hardware(SDK::UWIDGET_PlayerHUD_C* neural_hud);

    static void initialize_hand_item_collisions();
    static void set_debug_widget_visibility(bool visible);


    //void set_player_response_to_all_collision_channels(SDK::ECollisionResponse response);
};