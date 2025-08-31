#pragma once
#include "SDK/HeadMountedDisplay_classes.hpp"

class OuterWorldsMain;

class VRControllers
{
private:
    bool m_initialized{ false };
    //OuterWorldsMain* m_main{ nullptr };
    
    // actors
    SDK::AActor* m_hmd_actor{ nullptr };
    SDK::AActor* m_right_hand_actor{ nullptr };
    SDK::AActor* m_left_hand_actor{ nullptr };

    // motion controllers
    SDK::UMotionControllerComponent* m_rh_controller_component{ nullptr };
    SDK::UMotionControllerComponent* m_lh_controller_component{ nullptr };

    // scene components
    SDK::USceneComponent* m_hmd_component{ nullptr };

public:
    //VRControllers(OuterWorldsMain* main) { m_main = main; };
    VRControllers() = default;
    virtual ~VRControllers();

    // getters
    SDK::AActor* get_hmd_actor() { return m_hmd_actor; };
    SDK::AActor* get_right_hand_actor() { return m_right_hand_actor; };
    SDK::AActor* get_left_hand_actor() { return m_left_hand_actor; };
    SDK::UMotionControllerComponent* get_rh_controller_component() { return m_rh_controller_component; };
    SDK::UMotionControllerComponent* get_lh_controller_component() { return m_lh_controller_component; };
    SDK::USceneComponent* get_hmd_component() { return m_hmd_component; };

    bool is_valid();
    bool is_initialized() const { return m_initialized; };
    bool initialize();
    void cleanup_pointers();
    void destroy_actors();
    static void cleanup_actors();
};
