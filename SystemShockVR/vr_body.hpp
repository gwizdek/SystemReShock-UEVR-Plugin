#pragma once
#include "main.hpp"
#include "SDK/Niagara_classes.hpp"


class VRBody
{
private:
    SystemShockMain* m_main{ nullptr };
    SDK::ABP_VRBody_C* m_bp_actor{ nullptr };
    VRWeapon* m_vr_weapon{ nullptr };
    SDK::FHitResult m_hit_result{};

public:
    VRBody(SystemShockMain* main);
    virtual ~VRBody() {};

    SDK::ABP_VRBody_C* get_bp_actor() { return m_bp_actor; };

    // getters
    SDK::UMotionControllerComponent* get_right_controller();
    SDK::UMotionControllerComponent* get_left_controller();

    void initialize();
    bool is_valid();
    void on_tick();
    void on_draw_imgui();
    void cleanup_pointers();
    static void cleanup_actors();
    void attach_grab_components();
    void log_overlapping_objects();
    void set_player_response_to_collision_channel(SDK::ECollisionChannel channel, SDK::ECollisionResponse response);
    void set_player_response_to_all_collision_channels(SDK::ECollisionResponse response);
};
