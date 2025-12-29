#pragma once
#include "main.hpp"

#include "SDK/_BP_VRBody_classes.hpp"

const SDK::ECollisionChannel item_selector_collision_channel{ SDK::ECollisionChannel::ECC_EngineTraceChannel1 };

class VRBody
{
private:
    SystemShockMain* m_main{ nullptr };
    SDK::A_BP_VRBody_C* m_bp_actor{ nullptr };
    SDK::FHitResult m_hit_result{};
    //SDK::UITEM_WeaponBase_C* m_equipped_weapon{ nullptr };
    //std::array<SDK::UWidgetComponent*, 4> m_hotbar_slots{};

    // memo state
    //MemoProperty<std::string> m_equipped_weapon_mesh_name{ "", "" };
    MemoProperty<SDK::UWidgetComponent*> m_highlighted_widget_component{ nullptr, nullptr };

    float m_trace_start_offset[3]{ 0.f, 0.f, 0.f };
    float m_laser_power{ -1.f };
    float m_occlusion_sample_diameter{ -1.f };
    float m_alpha{ -1.f };

public:
    VRBody(SystemShockMain* main);
    virtual ~VRBody() {};

    SDK::A_BP_VRBody_C* get_bp_actor() { return m_bp_actor; };

    // getters
    void initialize();
    void initialize_main_item_selector();
    void initialize_laser_dot();
    bool is_valid();
    void on_tick();
    void on_draw_imgui();
    void cleanup_pointers();
    static void cleanup_actors();
    void attach_grab_components();
    void log_overlapping_objects();
    void set_player_response_to_collision_channel(SDK::ECollisionChannel channel, SDK::ECollisionResponse response);
    void set_player_response_to_all_collision_channels(SDK::ECollisionResponse response);
    void attach_camera(SDK::UCameraComponent* camera);
    void set_hotbar_slot_visibility(int slot, bool visible);
    void highlight_quick_slot();
    void change_quick_slot();
    void set_primary_item_selector_visibility(bool visible);
    void unselect_all_hotbar_slots();
};
