#pragma once

#include "SDK/Engine_structs.hpp"
#include "SDK/COMP_HackerInventory_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"

#include "BridgeSDK/_BP_VRBody_classes.hpp"

class VRBody final
{
private:
    static inline float m_mfd_depth{ 150.f };

public:
    static SDK::A_BP_VRBody_C* initialize_vr_body(SDK::APAWN_Hacker_Simple_C* pawn);
    // Applies the VR options from the mod's ini to the body: after a spawn, and again when
    // the player presses Apply on the VR options page. For now that is the player height.
    static void apply_custom_vr_game_options(SDK::A_BP_VRBody_C* vr_body);
    //static SDK::A_BP_VRBody_C* initialize_vr_body(SDK::APAWN_Hacker_Implant_C* pawn);
    static void initialize_laser_dot();
    static void overwrite_hacker_crouch_animations();
    static void set_weapon_mesh_visibility(bool visible);
    static void set_player_response_to_collision_channel(SDK::ECollisionChannel channel, SDK::ECollisionResponse response);
    static void reset_player_camera();
    static void align_control_yaw_to_look_pivot(SDK::APAWN_Hacker_Simple_C* pawn);
    static void show_vr_body();
    static void hide_vr_body();
    static bool is_valid_hacker_implant();
    static void initialize_ads();

    // Minimap / Media Display
    static void initialize_minimap(SDK::UWIDGET_PlayerHUD_C* neural_hud);
    static void set_media_display_visibility(bool visible);

    // Hacker Hardware
    static void initialize_hacker_hardware(SDK::UWIDGET_PlayerHUD_C* neural_hud);

    // Active Hazard (poison / radiation) indicator reparented into a 3D widget component
    static void initialize_active_hazard(SDK::UWIDGET_PlayerHUD_C* neural_hud);

    // Unread media (email) icon: moved from the left screen edge to the top centre, under the
    // compass, where the headset shows it. Its material is replaced by the Core pak.
    static void initialize_unread_media_icon(SDK::UWIDGET_PlayerHUD_C* neural_hud);

    static void initialize_hand_item_collisions();
    static void set_debug_widget_visibility(bool visible);


    //void set_player_response_to_all_collision_channels(SDK::ECollisionResponse response);
};