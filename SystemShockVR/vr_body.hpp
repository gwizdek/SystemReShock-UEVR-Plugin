#pragma once

#include "SDK/_BP_VRBody_classes.hpp"

using namespace SDK;

class VRBody
{
private:

public:
    VRBody() = default;
    virtual ~VRBody() {};

    static A_BP_VRBody_C* initialize_vr_body(APAWN_Hacker_Implant_C* pawn);
    static void initialize_laser_dot(A_BP_VRBody_C* vr_body);
    static void overwrite_hacker_crouch_animations(APAWN_Hacker_Implant_C* pawn);
    static void set_weapon_mesh_visibility(APAWN_Hacker_Implant_C* pawn, bool visible);
    static void set_player_response_to_collision_channel(APAWN_Hacker_Implant_C* pawn, A_BP_VRBody_C* vr_body, SDK::ECollisionChannel channel, SDK::ECollisionResponse response);
    static void reset_player_camera(APAWN_Hacker_Implant_C* pawn);
    //void set_player_response_to_all_collision_channels(SDK::ECollisionResponse response);
};
