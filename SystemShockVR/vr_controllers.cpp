#include "plugin_utils.hpp"
#include "vr_controllers.hpp"

using namespace uevr;

VRControllers::~VRControllers() {
};

bool VRControllers::initialize() {
    try {
        API::get()->log_warn("[vr_controllers][initialize] Initializing VR controllers");
        auto world = SDK::UWorld::GetWorld();
        if (!SDK::UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_error("[vr_controllers][initialize] World not valid");
            return false;
        }

        auto pawn = SDK::UGameplayStatics::GetPlayerPawn(world, 0);
        if (!SDK::UKismetSystemLibrary::IsValid(pawn)) {
            API::get()->log_error("[vr_controllers][initialize] Pawn not valid");
            return false;
        }

        const SDK::FVector pawn_location = pawn->K2_GetActorLocation();
        SDK::FTransform pawn_transform{
            .Rotation = { 0.f, 0.f, 0.f, 1.f },
            .Translation = { pawn_location.X, pawn_location.Y, pawn_location.Z },
            .Scale3D = { 1.f, 1.f, 1.f }
        };

        SDK::FTransform zero_transform{
            .Rotation = { 0.f, 0.f, 0.f, 1.f },
            .Translation = { 0.f, 0.f, 0.f },
            .Scale3D = { 1.f, 1.f, 1.f }
        };

        // --------------------------------------------------------------------
        // Right Hand
        // - Actor
        // - Motion Controller
        // --------------------------------------------------------------------
        m_right_hand_actor = PluginUtils::spawn_actor(world, pawn_transform, L"VRControllerActor");
        if (m_right_hand_actor == nullptr) {
            API::get()->log_error("[vr_controllers][initialize] Error spawning RH Actor");
            return false;
        }

        // motion controller component
        m_rh_controller_component = static_cast<SDK::UMotionControllerComponent*>(
            m_right_hand_actor->AddComponentByClass(
                SDK::UMotionControllerComponent::StaticClass(), false, zero_transform, false
            ));
        if (m_rh_controller_component == nullptr) {
            API::get()->log_error("[vr_controllers][initialize] Failed to add RH MotionControllerComponent");
            return false;
        }

        m_rh_controller_component->MotionSource = SDK::UKismetStringLibrary::Conv_StringToName(L"Right");
        m_rh_controller_component->Hand = SDK::EControllerHand::Right;
        m_right_hand_actor->FinishAddComponent(m_rh_controller_component, false, zero_transform);
        API::get()->log_warn("[vr_controllers][initialize] Added RH MotionControllerComponent");

        // --------------------------------------------------------------------
        // Left Hand
        // - Actor
        // - Motion Controller
        // --------------------------------------------------------------------
        m_left_hand_actor = PluginUtils::spawn_actor(world, pawn_transform, L"VRControllerActor");
        if (m_left_hand_actor == nullptr) {
            API::get()->log_error("[vr_controllers][initialize] Error spawning LH Actor");
            return false;
        }

        // motion controller component
        m_lh_controller_component = static_cast<SDK::UMotionControllerComponent*>(
            m_left_hand_actor->AddComponentByClass(
                SDK::UMotionControllerComponent::StaticClass(), false, zero_transform, false
            ));
        if (m_lh_controller_component == nullptr) {
            API::get()->log_error("[vr_controllers][initialize] Failed to add LH MotionControllerComponent");
            return false;
        }

        m_lh_controller_component->MotionSource = SDK::UKismetStringLibrary::Conv_StringToName(L"Left");
        m_lh_controller_component->Hand = SDK::EControllerHand::Left;
        m_left_hand_actor->FinishAddComponent(m_lh_controller_component, false, zero_transform);
        API::get()->log_warn("[vr_controllers][initialize] Added LH MotionControllerComponent");

        // --------------------------------------------------------------------
        // HMD
        // - Actor
        // - Scene Component
        // --------------------------------------------------------------------
        m_hmd_actor = PluginUtils::spawn_actor(world, pawn_transform, L"VRControllerActor");
        if (m_hmd_actor == nullptr) {
            API::get()->log_error("[vr_controllers][initialize] Error spawning HMD Actor");
            return false;
        }

        // scene component
        m_hmd_component = static_cast<SDK::USceneComponent*>(
            m_hmd_actor->AddComponentByClass(SDK::USceneComponent::StaticClass(), false, zero_transform, true)
        );
        if (m_hmd_component == nullptr) {
            API::get()->log_error("[vr_controllers][initialize] Failed to add HMD SceneComponent");
            return false;
        }

        m_hmd_actor->FinishAddComponent(m_hmd_component, false, zero_transform);
        auto hmd_state = API::UObjectHook::get_or_add_motion_controller_state((API::UObject*)m_hmd_component);
        if (hmd_state == nullptr) {
            API::get()->log_error("[vr_controllers][initialize] Failed to hook HMD SceneComponent");
            return false;
        }
        hmd_state->set_hand(2);
        hmd_state->set_permanent(true);

        API::get()->log_warn("[vr_controllers][initialize] Added HMD SceneComponent");

        m_initialized = true;
        return true;
    }
    catch (...) {
        API::get()->log_error("[vr_controllers][initialize] Exception");
        return false;
    }
}

bool VRControllers::is_valid() {
    try {
        if (
            //!SDK::UKismetSystemLibrary::IsValid(m_hmd_actor) ||
            //!SDK::UKismetSystemLibrary::IsValid(m_hmd_component) ||
            !SDK::UKismetSystemLibrary::IsValid(m_right_hand_actor) ||
            !SDK::UKismetSystemLibrary::IsValid(m_rh_controller_component) ||
            !SDK::UKismetSystemLibrary::IsValid(m_left_hand_actor) ||
            !SDK::UKismetSystemLibrary::IsValid(m_lh_controller_component)
            ) {
            return false;
        }
        return true;
    }
    catch (...) {
        API::get()->log_error("[vr_controllers][is_valid] Exception");
        return false;
    }
}


void VRControllers::cleanup_pointers() {
    API::get()->log_warn("[vr_controllers][cleanup_pointers] Cleanup");
    // actors
    m_right_hand_actor = nullptr;
    m_left_hand_actor = nullptr;
    m_hmd_actor = nullptr;

    // components
    m_rh_controller_component = nullptr;
    m_lh_controller_component = nullptr;
    m_hmd_component = nullptr;
}

// unused
void VRControllers::destroy_actors() {
    try {
        API::get()->log_warn("[vr_controllers][destroy_actors] Destroying actors");

        if (SDK::UKismetSystemLibrary::IsValid(m_right_hand_actor)) {
            m_right_hand_actor->K2_DestroyActor();
            API::get()->log_warn("[vr_controllers][destroy_actors] RH Actor destroyed");
        }

        if (SDK::UKismetSystemLibrary::IsValid(m_left_hand_actor)) {
            m_left_hand_actor->K2_DestroyActor();
            API::get()->log_warn("[vr_controllers][destroy_actors] LH Actor destroyed");
        }

        //if (SDK::UKismetSystemLibrary::IsValid(m_hmd_actor)) {
        //    m_hmd_actor->K2_DestroyActor();
        //    API::get()->log_warn("[vr_controllers][destroy_actors] HMD Actor destroyed");
        //}
    }
    catch (...) {
        API::get()->log_error("[vr_controllers][destroy_actors] Exception");
    }
}

void VRControllers::cleanup_actors() {
    try {
        auto world = SDK::UWorld::GetWorld();
        if (!SDK::UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_error("[vr_controllers][cleanup_actors] World invalid");
            return;
        }

        //PluginUtils::destroy_actors_by_tag(world, L"VRControllerActor");
    }
    catch (...) {
        API::get()->log_error("[vr_controllers][cleanup_actors] Exception");
    }
}