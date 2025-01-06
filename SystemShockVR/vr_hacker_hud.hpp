#pragma once

#include <set>

#include "uevr/API.hpp"

#include "SDK/Engine_classes.hpp"
#include "SDK/CoreGame_classes.hpp"
#include "SDK/SystemReShock_classes.hpp"
#include "SDK/HeadMountedDisplay_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/WIDGET_Minimap_classes.hpp"
#include "SDK/WIDGET_HotbarSlot_classes.hpp"
#include "SDK/WIDGET_VitalBars_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/INTERACT_RepulsorLift_classes.hpp"
#include "SDK/INTERACT_Lift_Base_classes.hpp"
#include "SDK/ELEVATOR_Base_classes.hpp"
#include "SDK/WIDGET_InventoryPanel_classes.hpp"
#include "SDK/WIDGET_HardwareButton_classes.hpp"

#include "vr_plugin_shared.hpp"


using namespace uevr;

typedef enum VRHackerHUDState
{
    VR_HUD_PENDING_INIT,
    VR_HUD_INITIALIZING,
    VR_HUD_SUCCESS,
    VR_HUD_ERROR
} VRHackerHUDState;

const char* VRHackerHUDStateNames[4] = { "VR_HUD_PENDING_INIT", "VR_HUD_INITIALIZING", "VR_HUD_SUCCESS", "VR_HUD_ERROR" };
const SDK::ECollisionChannel item_selector_collision_channel{ SDK::ECollisionChannel::ECC_EngineTraceChannel1 };

class VRHackerHUD
{
private:
    VRHackerHUDState m_hud_state{ VR_HUD_PENDING_INIT };
    std::string m_hud_error_msg{};
    SDK::FHitResult m_reusable_result{};

    // options
    float m_primary_item_selector_distance{ 60.f };
    float m_primary_item_selector_spread{ 1.f };
    float m_primary_item_selector_scale{ 0.12f };

    float m_secondary_item_selector_distance{ 60.f };
    float m_secondary_item_selector_spread{ 1.f };
    float m_secondary_item_selector_scale{ 0.12f };

    float m_mfd_depth{ 150.f };

    // transforms
    SDK::FVector m_active_item_selector_delta{};
    SDK::FVector m_mfd_mask_delta{};

    // convinience pointers
    SDK::UWorld* m_world{ nullptr };
    SDK::APAWN_Hacker_Implant_C* m_pawn{ nullptr };
    SDK::UWIDGET_PlayerHUD_C* m_hud{ nullptr };

    // actors
    SDK::AActor* m_hmd_actor{ nullptr };
    SDK::AActor* m_right_hand_attachments_actor{ nullptr };
    //SDK::AActor* m_left_hand_attachments_actor{ nullptr };
    SDK::AActor* m_primary_item_selector_actor{ nullptr };
    SDK::AActor* m_secondary_item_selector_actor{ nullptr };
    SDK::AActor* m_mfd_mask_actor{ nullptr };

    // motion controllers
    SDK::UMotionControllerComponent* m_rh_controller_component{ nullptr };
    SDK::UMotionControllerComponent* m_lh_controller_component{ nullptr };

    // interaction components (unused)
    MemoProperty<SDK::UWidgetComponent*> m_highlighted_widget_component{ nullptr, nullptr };
    SDK::UWidgetInteractionComponent* m_rh_interaction_component{ nullptr };
    SDK::UCapsuleComponent* m_laser_pointer_component{ nullptr };

    // scene components
    SDK::USceneComponent* m_primary_item_selector_component{ nullptr }; // parent component for hotbar slots
    SDK::USceneComponent* m_secondary_item_selector_component{ nullptr }; // parent component for hacker hardware
    SDK::USceneComponent* m_mfd_component{ nullptr };
    SDK::USceneComponent* m_hmd_component{ nullptr };

    // widget components
    SDK::UWidgetComponent* m_minimap_widget_component{ nullptr };
    SDK::UWidgetComponent* m_vital_bars_widget_component{ nullptr };
    std::array<SDK::UWidgetComponent*, 10> m_hotbar_slot_widget_components{};
    std::array<SDK::UWidgetComponent*, 5> m_hacker_hardware_widget_components{};
    SDK::UWidgetComponent* m_ui_mask_widget_component{ nullptr };

    // utils
    std::array<SDK::FTransform, 10> m_hotbar_slot_transforms{};
    std::array<SDK::FTransform, 10> m_hacker_hardware_transforms{};

    // widgets
    std::array<SDK::UWIDGET_HardwareButton_C*, 5> m_hardware_widgets{};

public:
    VRHackerHUD() {
        // prepare stansforms for slots
        for (int i = 0; i < 10; i++) {
            m_hotbar_slot_transforms[i].Rotation = { 0.f, 0.f, 1.f, 0.f };
            m_hotbar_slot_transforms[i].Scale3D = { 1.f, m_primary_item_selector_scale, m_primary_item_selector_scale };
        }

        m_hotbar_slot_transforms[1].Translation = { 0.0f, 0.f, 12.f * m_primary_item_selector_spread };
        m_hotbar_slot_transforms[2].Translation = { 0.0f, 12.f * m_primary_item_selector_spread, 0.f };
        m_hotbar_slot_transforms[3].Translation = { 0.0f, 0.f, -12.f * m_primary_item_selector_spread };
        m_hotbar_slot_transforms[4].Translation = { 0.0f, -12.f * m_primary_item_selector_spread, 0.f };
        m_hotbar_slot_transforms[5].Translation = { 0.0f, -12.f * m_primary_item_selector_spread, 24.f * m_primary_item_selector_spread };
        m_hotbar_slot_transforms[6].Translation = { 0.0f, 12.f * m_primary_item_selector_spread, 24.f * m_primary_item_selector_spread };
        m_hotbar_slot_transforms[7].Translation = { 0.0f, -24.f * m_primary_item_selector_spread, 12.f * m_primary_item_selector_spread };
        m_hotbar_slot_transforms[8].Translation = { 0.0f, -24.f * m_primary_item_selector_spread, -12.f * m_primary_item_selector_spread };
        m_hotbar_slot_transforms[9].Translation = { 0.0f, 24.f * m_primary_item_selector_spread, 12.f * m_primary_item_selector_spread };
        m_hotbar_slot_transforms[0].Translation = { 0.0f, 24.f * m_primary_item_selector_spread, -12.f * m_primary_item_selector_spread };


        for (int i = 0; i < 5; i++) {
            m_hacker_hardware_transforms[i].Rotation = { 0.f, 0.f, 1.f, 0.f };
            m_hacker_hardware_transforms[i].Scale3D = { 1.f, m_secondary_item_selector_scale, m_secondary_item_selector_scale };
        }
        m_hacker_hardware_transforms[0].Translation = { 0.0f, 0.f, 12.f * m_secondary_item_selector_spread }; // energy shield
        m_hacker_hardware_transforms[1].Translation = { 0.0f, 12.f * m_secondary_item_selector_spread, 0.f }; // vision unit
        m_hacker_hardware_transforms[2].Translation = { 0.0f, 0.f, 26.f * m_secondary_item_selector_spread }; // sense around (top)
        m_hacker_hardware_transforms[3].Translation = { 0.0f, 0.f, -12.f * m_secondary_item_selector_spread }; // enviro pack
        m_hacker_hardware_transforms[4].Translation = { 0.0f, -12.f * m_secondary_item_selector_spread, 0.f }; // turbo boots
    }

    virtual ~VRHackerHUD() {
        API::get()->log_info("VRHackerHUD :: Destructor");
    }

    // call it each tick (or reference pointers maybe?)
    void set_pointers(SDK::UWorld* world, SDK::APAWN_Hacker_Implant_C* pawn, SDK::UWIDGET_PlayerHUD_C* hud) {
        m_world = world;
        m_pawn = pawn;
        m_hud = hud;
    }

    void initialize_hud() {
        if (m_hud_state != VR_HUD_PENDING_INIT) {
            return;
        }

        API::get()->log_info("VRHackerHUD :: Initializing");
        clear_pointers();
        m_hud_error_msg = "NONE";
        m_hud_state = VR_HUD_INITIALIZING;

        if (!prepare_attachment_points()) {
            destroy_actors();
            m_hud_state = VR_HUD_ERROR;
            return;
        }

        if (!attach_minimap()) {
            destroy_actors();
            m_hud_state = VR_HUD_ERROR;
            return;
        }

        if (!attach_player_vital_bars()) {
            destroy_actors();
            m_hud_state = VR_HUD_ERROR;
            return;
        }

        if (!attach_primary_item_selector()) {
            destroy_actors();
            m_hud_state = VR_HUD_ERROR;
            return;
        }

        if (!attach_secondary_item_selector()) {
            destroy_actors();
            m_hud_state = VR_HUD_ERROR;
            return;
        }

        if (!attach_mfd_mask()) {
            destroy_actors();
            m_hud_state = VR_HUD_ERROR;
            return;
        }

        m_hud_state = VR_HUD_SUCCESS;

    }

    void handle_mod_events(std::set<ModEvent>* mod_events) {
        if (mod_events == nullptr) {
            return;
        }

        // check VR HUD specific events to handle
        if (mod_events->contains(MOD_EVENT_VR_HUD_HIDE_DASHBOARDS)) {
            if (m_hud == nullptr)
                return;

            if (m_hud->MESH_Dashboard != nullptr && m_hud->MESH_DashboardBottom != nullptr) {
                m_hud->MESH_Dashboard->SetVisibility(SDK::ESlateVisibility::Hidden);
                m_hud->MESH_DashboardBottom->SetVisibility(SDK::ESlateVisibility::Hidden);

                mod_events->extract(MOD_EVENT_VR_HUD_HIDE_DASHBOARDS);
            }
        }

        if (mod_events->contains(MOD_EVENT_VR_HUD_INITIALIZE)) {
            if (m_pawn == nullptr || m_hud == nullptr)
                return;

            initialize_hud();
            mod_events->extract(MOD_EVENT_VR_HUD_INITIALIZE);
        }
    }

    VRHackerHUDState get_hud_state() {
        return m_hud_state;
    }

    void set_hud_state(VRHackerHUDState state) {
        m_hud_state = state;
    }

    std::string get_hud_error() {
        return m_hud_error_msg;
    }

    float get_mfd_depth() {
        return m_mfd_depth;
    }

    void set_mfd_mask_size(int size_x, int size_y) {
        m_ui_mask_widget_component->SetDrawSize({ static_cast<float>(size_x), static_cast<float>(size_y) });
    }

    void log_error(std::string error_msg) {
        m_hud_error_msg = error_msg;
        API::get()->log_info(error_msg.c_str());
    }

    void clear_pointers() {
        m_right_hand_attachments_actor = nullptr;
        //m_left_hand_attachments_actor = nullptr;
        m_primary_item_selector_actor = nullptr;
        m_secondary_item_selector_actor = nullptr;
        m_hmd_actor = nullptr;
        m_mfd_mask_actor = nullptr;
        m_rh_controller_component = nullptr;
        m_lh_controller_component = nullptr;
        m_rh_interaction_component = nullptr;
        m_primary_item_selector_component = nullptr;
        m_secondary_item_selector_component = nullptr;
        m_hmd_component = nullptr;
        m_mfd_component = nullptr;
        m_minimap_widget_component = nullptr;
        m_vital_bars_widget_component = nullptr;
        m_hotbar_slot_widget_components = {};
        m_hacker_hardware_widget_components = {};
        m_laser_pointer_component = nullptr;
    }

    void destroy_actors() {
        API::get()->log_info("VRHackerHUD :: Destroying actors");

        if (SDK::UKismetSystemLibrary::IsValid(m_right_hand_attachments_actor) && m_right_hand_attachments_actor->IsA(SDK::AActor::StaticClass())) {
            m_right_hand_attachments_actor->K2_DestroyActor();
            API::get()->log_info("VRHackerHUD :: RH Actor destroyed");
        }

        //if (SDK::UKismetSystemLibrary::IsValid(m_left_hand_attachments_actor) && m_left_hand_attachments_actor->IsA(SDK::AActor::StaticClass())) {
        //    m_left_hand_attachments_actor->K2_DestroyActor();
        //    API::get()->log_info("VRHackerHUD :: LH Actor destroyed");
        //}

        if (SDK::UKismetSystemLibrary::IsValid(m_primary_item_selector_actor) && m_primary_item_selector_actor->IsA(SDK::AActor::StaticClass())) {
            m_primary_item_selector_actor->K2_DestroyActor();
            API::get()->log_info("VRHackerHUD :: Primary Item selector Actor destroyed");
        }

        if (SDK::UKismetSystemLibrary::IsValid(m_secondary_item_selector_actor) && m_secondary_item_selector_actor->IsA(SDK::AActor::StaticClass())) {
            m_secondary_item_selector_actor->K2_DestroyActor();
            API::get()->log_info("VRHackerHUD :: Secondary Item selector Actor destroyed");
        }

        if (SDK::UKismetSystemLibrary::IsValid(m_mfd_mask_actor) && m_mfd_mask_actor->IsA(SDK::AActor::StaticClass())) {
            m_mfd_mask_actor->K2_DestroyActor();
            API::get()->log_info("VRHackerHUD :: MFD mask Actor destroyed");
        }

        if (SDK::UKismetSystemLibrary::IsValid(m_hmd_actor) && m_hmd_actor->IsA(SDK::AActor::StaticClass())) {
            m_hmd_actor->K2_DestroyActor();
            API::get()->log_info("VRHackerHUD :: HMD Actor destroyed");
        }

        clear_pointers();
        m_hud_state = VR_HUD_PENDING_INIT;
    }

    SDK::AActor* spawn_actor(SDK::FTransform transform) {
        if (m_world == nullptr || m_pawn == nullptr) {
            log_error("spawn_actor :: invalid pointers");
            return nullptr;
        }

        const SDK::ESpawnActorCollisionHandlingMethod collision_method = SDK::ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

        SDK::AActor* actor = SDK::UGameplayStatics::BeginDeferredActorSpawnFromClass(m_world, SDK::AActor::StaticClass(), transform, collision_method, nullptr);
        if (actor == nullptr) {
            log_error("spawn_actor :: error spawning actor");
            return nullptr;
        }

        SDK::UGameplayStatics::FinishSpawningActor(actor, transform);
        API::get()->log_info("VRHackerHUD :: Spawned actor");

        return actor;
    }

    bool prepare_attachment_points() {
        if (
            m_pawn == nullptr ||
            m_right_hand_attachments_actor != nullptr ||
            //m_left_hand_attachments_actor != nullptr ||
            m_primary_item_selector_actor != nullptr ||
            m_secondary_item_selector_actor != nullptr ||
            m_mfd_mask_actor != nullptr ||
            m_hmd_actor != nullptr
            ) {
            log_error("Can't prepare attachment points. Pointers");
            return false;
        }

        const SDK::FVector pawn_location = m_pawn->K2_GetActorLocation();
        SDK::FTransform transform{};
        transform.Rotation = { 0.f, 0.f, 0.f, 1.f };
        transform.Translation = { pawn_location.X, pawn_location.Y, pawn_location.Z };
        transform.Scale3D = { 1.f, 1.f, 1.f };


        // --------------------------------------------------------------------
        // Right Hand
        // - Actor
        // - Motion Controller
        // - Widget Interaction Component
        // - Laser Pointer for Item Selector and MFD
        // - Minimap
        // - Vital Bars
        // --------------------------------------------------------------------

        // actor
        m_right_hand_attachments_actor = spawn_actor(transform);
        if (m_right_hand_attachments_actor == nullptr) {
            log_error("Error spawning right hand actor");
            return false;
        }

        // motion controller component
        m_rh_controller_component = static_cast<SDK::UMotionControllerComponent*>(
            m_right_hand_attachments_actor->AddComponentByClass(
                SDK::UMotionControllerComponent::StaticClass(), false, transform, false
            )
            );
        if (m_rh_controller_component == nullptr) {
            log_error("Failed to add right hand motion controller component");
            return false;
        }

        m_rh_controller_component->MotionSource = SDK::UKismetStringLibrary::Conv_StringToName(L"Right");
        m_rh_controller_component->Hand = SDK::EControllerHand::Right;
        m_right_hand_attachments_actor->FinishAddComponent(m_rh_controller_component, false, transform);

        // interaction component
        SDK::FTransform widget_interaction_transform{};
        widget_interaction_transform.Rotation = { 0.f, 0.f, 0.f, 1.f };
        widget_interaction_transform.Translation = { 0.f, 0.f, 0.f };
        widget_interaction_transform.Scale3D = { 1.f, 1.f, 1.f };

        m_rh_interaction_component = static_cast<SDK::UWidgetInteractionComponent*>(
            m_right_hand_attachments_actor->AddComponentByClass(
                SDK::UWidgetInteractionComponent::StaticClass(), false, widget_interaction_transform, false
            )
            );
        if (m_rh_interaction_component == nullptr) {
            API::get()->log_info("Failed to add right hand widget interaction component");
            return false;
        }

        m_right_hand_attachments_actor->FinishAddComponent(m_rh_interaction_component, false, widget_interaction_transform);

        m_rh_interaction_component->VirtualUserIndex = 99;
        m_rh_interaction_component->PointerIndex = 99;
        m_rh_interaction_component->TraceChannel = item_selector_collision_channel;
        m_rh_interaction_component->InteractionDistance = 300.0f;
        m_rh_interaction_component->InteractionSource = SDK::EWidgetInteractionSource::World;
        m_rh_interaction_component->bEnableHitTesting = true;
        m_rh_interaction_component->SetVisibility(false, false);
        m_rh_interaction_component->SetHiddenInGame(true, true);

        // laser pointer
        SDK::FTransform laser_pointer_transform{};
        laser_pointer_transform.Rotation = { 0.f, 1.f, 0.f, 1.f };
        laser_pointer_transform.Translation = { 0.f, 0.f, 0.f };
        laser_pointer_transform.Scale3D = { 1.f, 1.f, 1.f };

        m_laser_pointer_component = static_cast<SDK::UCapsuleComponent*>(
            m_right_hand_attachments_actor->AddComponentByClass(
                SDK::UCapsuleComponent::StaticClass(), false, laser_pointer_transform, false
            )
            );
        if (m_laser_pointer_component == nullptr) {
            API::get()->log_info("Failed to add capsule component");
            return false;
        }
        m_laser_pointer_component->SetCapsuleSize(0.1f, 0.f, true);
        m_laser_pointer_component->SetVisibility(true, true);
        m_laser_pointer_component->SetHiddenInGame(false, false);
        m_laser_pointer_component->bAutoActivate = true;
        m_laser_pointer_component->SetGenerateOverlapEvents(false);
        m_laser_pointer_component->SetCollisionEnabled(SDK::ECollisionEnabled::NoCollision);
        m_laser_pointer_component->SetRenderInMainPass(true);
        m_laser_pointer_component->bRenderInDepthPass = true;
        m_laser_pointer_component->ShapeColor = SDK::FColor{ 0, 0, 255, 255 };

        m_laser_pointer_component->SetRenderCustomDepth(true);
        m_laser_pointer_component->SetCustomDepthStencilValue(100);
        m_laser_pointer_component->SetCustomDepthStencilWriteMask(SDK::ERendererStencilMask::ERSM_255);

        m_right_hand_attachments_actor->FinishAddComponent(m_laser_pointer_component, false, laser_pointer_transform);


        // --------------------------------------------------------------------
        // Left Hand (not used)
        // - Actor
        // - Motion Controller
        // --------------------------------------------------------------------

        // actor
        //m_left_hand_attachments_actor = spawn_actor(transform);
        //if (m_left_hand_attachments_actor == nullptr) {
        //    log_error("Error spawning lH actor");
        //    return false;
        //}

        //// motion controller component
        //m_lh_controller_component = static_cast<SDK::UMotionControllerComponent*>(
        //    m_left_hand_attachments_actor->AddComponentByClass(
        //        SDK::UMotionControllerComponent::StaticClass(), false, transform, false
        //    )
        //);
        //if (m_lh_controller_component == nullptr) {
        //    log_error("Failed to add left hand motion controller component");
        //    return false;
        //}

        //m_lh_controller_component->MotionSource = SDK::UKismetStringLibrary::Conv_StringToName(L"Left");
        //m_lh_controller_component->Hand = SDK::EControllerHand::Left;
        //m_left_hand_attachments_actor->FinishAddComponent(m_lh_controller_component, false, transform);


        // --------------------------------------------------------------------
        // Primary Item Selector (Hotbar Slots)
        // - Actor
        // - Scene Component
        // --------------------------------------------------------------------

        // actor
        m_primary_item_selector_actor = spawn_actor(transform);
        if (m_primary_item_selector_actor == nullptr) {
            log_error("Error spawning primary item selector actor");
            return false;
        }

        // spawning primary item selector component
        m_primary_item_selector_component = static_cast<SDK::USceneComponent*>(
            m_primary_item_selector_actor->AddComponentByClass(SDK::USceneComponent::StaticClass(), false, transform, true)
            );
        if (m_primary_item_selector_component == nullptr) {
            log_error("Failed to add primary item selector component");
            return false;
        }

        m_primary_item_selector_actor->FinishAddComponent(m_primary_item_selector_component, false, transform);
        m_primary_item_selector_component->SetVisibility(false, false);
        m_primary_item_selector_component->SetHiddenInGame(true, true);


        // --------------------------------------------------------------------
        // Secondary Item Selector (Hacker Hardware Slots)
        // - Actor
        // - Scene Component
        // --------------------------------------------------------------------

        // actor
        m_secondary_item_selector_actor = spawn_actor(transform);
        if (m_secondary_item_selector_actor == nullptr) {
            log_error("Error spawning secondary item selector actor");
            return false;
        }

        // spawning primary item selector component
        m_secondary_item_selector_component = static_cast<SDK::USceneComponent*>(
            m_secondary_item_selector_actor->AddComponentByClass(SDK::USceneComponent::StaticClass(), false, transform, true)
            );
        if (m_secondary_item_selector_component == nullptr) {
            log_error("Failed to add secondary item selector component");
            return false;
        }

        m_secondary_item_selector_actor->FinishAddComponent(m_secondary_item_selector_component, false, transform);
        m_secondary_item_selector_component->SetVisibility(false, false);
        m_secondary_item_selector_component->SetHiddenInGame(true, true);


        // --------------------------------------------------------------------
        // MFD mask
        // - Actor
        // - Scene Component
        // --------------------------------------------------------------------

        // actor
        m_mfd_mask_actor = spawn_actor(transform);
        if (m_mfd_mask_actor == nullptr) {
            log_error("Error spawning MFD mask actor");
            return false;
        }

        // scene component
        m_mfd_component = static_cast<SDK::USceneComponent*>(
            m_mfd_mask_actor->AddComponentByClass(SDK::USceneComponent::StaticClass(), false, transform, true)
            );
        if (m_mfd_component == nullptr) {
            log_error("Failed to add MFD component");
            return false;
        }

        m_mfd_mask_actor->FinishAddComponent(m_mfd_component, false, transform);
        m_mfd_component->SetVisibility(false, false);
        m_mfd_component->SetHiddenInGame(true, true);

        // --------------------------------------------------------------------
        // HMD
        // - Actor
        // - Scene Component
        // --------------------------------------------------------------------

        // actor
        m_hmd_actor = spawn_actor(transform);
        if (m_hmd_actor == nullptr) {
            log_error("Error spawning HMD actor");
            return false;
        }

        // scene component
        m_hmd_component = static_cast<SDK::USceneComponent*>(
            m_hmd_actor->AddComponentByClass(SDK::USceneComponent::StaticClass(), false, transform, true)
            );
        if (m_hmd_component == nullptr) {
            log_error("Failed to add HMD component");
            return false;
        }

        m_hmd_actor->FinishAddComponent(m_hmd_component, false, transform);
        auto hmd_state = API::UObjectHook::get_or_add_motion_controller_state((API::UObject*)m_hmd_component);
        if (hmd_state == nullptr) {
            log_error("Failed to hook HMD motion controller component");
            return false;
        }
        hmd_state->set_hand(2);
        hmd_state->set_permanent(true);

        API::get()->log_info("VRHackerHUD :: Prepared all attachment points");
        return true;
    }

    bool attach_minimap() {
        if (m_right_hand_attachments_actor == nullptr || m_rh_controller_component == nullptr || m_hud == nullptr) {
            log_error("attach_minimap :: Pointers not valid");
            return false;
        }

        if (m_minimap_widget_component != nullptr) {
            log_error("attach_minimap :: Minimap already attached");
            return false;
        }

        if (!SDK::UKismetSystemLibrary::IsValid(m_hud->WIDGET_Minimap)) {
            log_error("attach_minimap :: Can't access Minimap");
            return false;
        }

        SDK::FTransform minimap_transform{};
        minimap_transform.Rotation = { 0.094f, 0.f, 1.f, 0.f };
        minimap_transform.Translation = { 0.f, 20.f, -5.0f };
        minimap_transform.Scale3D = { 1.f, 0.04f, 0.04f };

        m_minimap_widget_component = static_cast<SDK::UWidgetComponent*>(
            m_right_hand_attachments_actor->AddComponentByClass(
                SDK::UWidgetComponent::StaticClass(), false, minimap_transform, false
            )
            );
        if (m_minimap_widget_component == nullptr) {
            log_error("attach_minimap :: Failed to attach Minimap component");
            return false;
        }

        m_hud->WIDGET_Minimap->RemoveFromViewport();
        m_minimap_widget_component->SetWidget(m_hud->WIDGET_Minimap);
        m_minimap_widget_component->SetVisibility(true, true);
        m_minimap_widget_component->SetHiddenInGame(false, false);
        m_minimap_widget_component->SetCollisionEnabled(SDK::ECollisionEnabled::NoCollision);

        auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
            L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
        );
        SDK::FLinearColor color{ 0.4f, 0.4f, 0.4f, 0.25f };
        m_minimap_widget_component->SetMaterial(0, material);
        m_minimap_widget_component->SetTintColorAndOpacity(color);

        m_right_hand_attachments_actor->FinishAddComponent(m_minimap_widget_component, false, minimap_transform);

        API::get()->log_info("VRHackerHUD :: Attached Minimap");
        return true;
    }

    bool attach_player_vital_bars() {
        if (m_right_hand_attachments_actor == nullptr || m_rh_controller_component == nullptr || m_hud == nullptr) {
            log_error("VRHackerHUD :: Attach Vital Bars :: Pointers not valid");
            return false;
        }

        if (m_vital_bars_widget_component != nullptr) {
            log_error("VRHackerHUD :: Attach Vital Bars :: already attached");
            return false;
        }

        if (!SDK::UKismetSystemLibrary::IsValid(m_hud->WIDGET_VitalBars)) {
            log_error("VRHackerHUD :: Attach Vital Bars :: Can't access widget");
            return false;
        }

        SDK::FTransform vital_bars_transform{};
        vital_bars_transform.Rotation = { 0.094f, 0.f, 1.f, 0.f };
        vital_bars_transform.Translation = { 0.3f, 15.f, 0.f };
        vital_bars_transform.Scale3D = { 1.f, 0.03f, 0.03f };

        m_vital_bars_widget_component = static_cast<SDK::UWidgetComponent*>(
            m_right_hand_attachments_actor->AddComponentByClass(
                SDK::UWidgetComponent::StaticClass(), false, vital_bars_transform, false
            )
        );
        if (m_vital_bars_widget_component == nullptr) {
            log_error("VRHackerHUD :: Attach Vital Bars :: Failed to attach component");
            return false;
        }

        m_vital_bars_widget_component->SetWidget(m_hud->WIDGET_VitalBars);
        m_vital_bars_widget_component->SetVisibility(true, true);
        m_vital_bars_widget_component->SetHiddenInGame(false, false);
        m_vital_bars_widget_component->SetCollisionEnabled(SDK::ECollisionEnabled::NoCollision);

        auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
            L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
        );
        SDK::FLinearColor color{ 0.5f, 0.5f, 0.5f, 1.f };
        m_vital_bars_widget_component->SetMaterial(0, material);
        m_vital_bars_widget_component->SetTintColorAndOpacity(color);

        m_right_hand_attachments_actor->FinishAddComponent(m_vital_bars_widget_component, false, vital_bars_transform);

        // moved here to fix bars visual state not maching real energy/health state
        m_hud->WIDGET_VitalBars->RemoveFromViewport();

        API::get()->log_info("VRHackerHUD :: Attach Vital Bars :: Successfully Attached");
        return true;
    }

    bool attach_primary_item_selector() {
        if (m_primary_item_selector_actor == nullptr || m_hud == nullptr) {
            log_error("attach_primary_item_selector :: Pointers not valid");
            return false;
        }

        // store parent canvas panel
        auto PANEL_HotbarSlots = m_hud->HotbarSlots[1]->Slot->Parent;
        if (PANEL_HotbarSlots == nullptr) {
            log_error("attach_primary_item_selector :: Can't store PANEL_HotbarSlots");
            return false;
        }

        // canvas panel slots 
        std::array<SDK::UCanvasPanelSlot*, 10> canvas_panel_slots{};

        for (int i = 0; i < 10; i++) {
            if (m_hotbar_slot_widget_components[i] != nullptr) {
                log_error("attach_primary_item_selector :: Already attached");
                return false;
            }

            if (!SDK::UKismetSystemLibrary::IsValid(m_hud->HotbarSlots[i])) {
                log_error("attach_primary_item_selector :: Can't access native Hotbar slot");
                return false;
            }

            m_hotbar_slot_widget_components[i] = static_cast<SDK::UWidgetComponent*>(
                m_primary_item_selector_actor->AddComponentByClass(
                    SDK::UWidgetComponent::StaticClass(), false, m_hotbar_slot_transforms[i], false
                )
            );
            if (m_hotbar_slot_widget_components[i] == nullptr) {
                log_error("attach_primary_item_selector :: Failed to attach Hotbar slot component");
                return false;
            }

            // there's some going back and forth here as we want two things:
            // - a properly sized and aligned widget component for the collisions to work correctly
            // - a working hotbar slot on the MFD
            // actually the same widget instance is used in two places: MFD / VR item selector,
            // so when the player assigns an item to the hotbar on MFD, it's reflected on the VR item selector

            // save original panel slot for widget so we can later reuse it's attributes
            // change alignments and anchors before setting widget to widget component
            canvas_panel_slots[i] = (SDK::UCanvasPanelSlot*)m_hud->HotbarSlots[i]->Slot;
            canvas_panel_slots[i]->SetAlignment({ 0.5f, 0.5f });
            canvas_panel_slots[i]->SetAnchors(SDK::FAnchors{ {0.5f, 0.5f}, {0.5f, 0.5f} });

            m_hotbar_slot_widget_components[i]->SetWidget(m_hud->HotbarSlots[i]);
            
            // 150.f seems to be the correct size
            m_hotbar_slot_widget_components[i]->SetDrawSize({ 120.0f, 120.0f });
            m_hotbar_slot_widget_components[i]->SetVisibility(false, false);
            m_hotbar_slot_widget_components[i]->SetHiddenInGame(true, true);

            // set properties for collision detection
            m_hotbar_slot_widget_components[i]->SetWidgetSpace(SDK::EWidgetSpace::World);
            m_hotbar_slot_widget_components[i]->SetCollisionEnabled(SDK::ECollisionEnabled::QueryOnly);
            m_hotbar_slot_widget_components[i]->SetCollisionObjectType(item_selector_collision_channel);
            m_hotbar_slot_widget_components[i]->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
            m_hotbar_slot_widget_components[i]->SetCollisionResponseToChannel(
                item_selector_collision_channel, SDK::ECollisionResponse::ECR_Block
            );

            auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
                L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
                 //L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Opaque.Widget3DPassThrough_Opaque"
            );
            SDK::FLinearColor color{ 0.4f, 0.4f, 0.4f, 0.2f };
            m_hotbar_slot_widget_components[i]->SetMaterial(0, material);
            m_hotbar_slot_widget_components[i]->SetTintColorAndOpacity(color);

            m_primary_item_selector_actor->FinishAddComponent(m_hotbar_slot_widget_components[i], false, m_hotbar_slot_transforms[i]);

            // restore original alignments and anchors
            canvas_panel_slots[i]->SetAlignment({ 0.5f, 1.f });
            canvas_panel_slots[i]->SetAnchors(SDK::FAnchors{ {0.5f, 1.f}, {0.5f, 1.f} });

            m_hud->HotbarSlots[i]->UpdateHotbarSlot();

            set_mfd_hotbar_visibility(false);
            set_primary_item_selector_visibility(false);
        }
        API::get()->log_info("VRHackerHUD :: Attached Primary Item selector");

        return true;
    }

    bool attach_secondary_item_selector() {
        if (m_secondary_item_selector_actor == nullptr || m_hud == nullptr) {
            log_error("attach_secondary_item_selector :: Pointers not valid");
            return false;
        }

        // store pointers to hardware items in an array
        m_hardware_widgets[0] = m_hud->WIDGET_HardwareButton_EnergyShield;
        m_hardware_widgets[1] = m_hud->WIDGET_HardwareButton_VisionUnit;
        m_hardware_widgets[2] = m_hud->WIDGET_HardwareButton_Sensaround;
        m_hardware_widgets[3] = m_hud->WIDGET_HardwareButton_EnviroPack;
        m_hardware_widgets[4] = m_hud->WIDGET_HardwareButton_TurboBoots;

        // canvas panel slots
        std::array<SDK::UCanvasPanelSlot*, 4> canvas_panel_slots{};

        for (int i = 0; i < 5; i++) {
            if (m_hacker_hardware_widget_components[i] != nullptr) {
                log_error("attach_secondary_item_selector :: Already attached");
                return false;
            }

            m_hacker_hardware_widget_components[i] = static_cast<SDK::UWidgetComponent*>(
                m_secondary_item_selector_actor->AddComponentByClass(
                    SDK::UWidgetComponent::StaticClass(), false, m_hacker_hardware_transforms[i], false
            ));
            if (m_hacker_hardware_widget_components[i] == nullptr) {
                log_error("attach_secondary_item_selector :: Failed to attach hardware widget component");
                return false;
            }

            // there's some going back and forth here as we want two things:
            // - a properly sized and aligned widget component for the collisions to work correctly
            // - a working hardware slot on the MFD
            // actually the same widget instance is used in two places: MFD / VR item selector,
            // save original panel slot for widget so we can later reuse it's attributes
            canvas_panel_slots[i] = (SDK::UCanvasPanelSlot*)m_hardware_widgets[i]->Slot;

            // we're going to remove hotbar slot form parent because widget's layout would be messed up after
            // binding it with widget component if we didn't
            //m_hardware_widgets[i]->RemoveFromViewport();
            m_hacker_hardware_widget_components[i]->SetWidget(m_hardware_widgets[i]);

            // 150.f seems to be the correct size
            m_hacker_hardware_widget_components[i]->SetDrawSize({ 100.0f, 100.0f });
            m_hacker_hardware_widget_components[i]->SetVisibility(true, true);
            m_hacker_hardware_widget_components[i]->SetHiddenInGame(false, false);

            // set properties for collision detection
            m_hacker_hardware_widget_components[i]->SetWidgetSpace(SDK::EWidgetSpace::World);
            m_hacker_hardware_widget_components[i]->SetCollisionEnabled(SDK::ECollisionEnabled::QueryOnly);
            m_hacker_hardware_widget_components[i]->SetCollisionObjectType(item_selector_collision_channel);
            m_hacker_hardware_widget_components[i]->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
            //m_hacker_hardware_widget_components[i]->SetCollisionResponseToChannel(
            //    item_selector_collision_channel, SDK::ECollisionResponse::ECR_Block
            //);

            auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
                L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
                //L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Opaque.Widget3DPassThrough_Opaque"
            );
            SDK::FLinearColor color{ 0.4f, 0.4f, 0.4f, 0.2f };
            m_hacker_hardware_widget_components[i]->SetMaterial(0, material);
            m_hacker_hardware_widget_components[i]->SetTintColorAndOpacity(color);

            m_secondary_item_selector_actor->FinishAddComponent(m_hacker_hardware_widget_components[i], false, m_hacker_hardware_transforms[i]);

            // recreate panel slot for widget and place it at original position on canvas panel
            auto panel_slot = i < 4
                ? (SDK::UCanvasPanelSlot*)m_hud->PANEL_LeftHardware->AddChild(m_hardware_widgets[i])
                : (SDK::UCanvasPanelSlot*)m_hud->PANEL_RightHardware->AddChild(m_hardware_widgets[i]);
            panel_slot->SetAlignment({ 0.5f, 0.5f });
            panel_slot->SetAnchors(SDK::FAnchors{ {0.5f, 0.5f}, {0.5f, 0.5f} });
            panel_slot->SetOffsets(canvas_panel_slots[i]->GetOffsets());

        }
        API::get()->log_info("VRHackerHUD :: Attached Secondary Item selector");

        return true;
    }

    bool attach_mfd_mask() {
        if (m_mfd_mask_actor == nullptr || m_hud == nullptr) {
            log_error("attach_mfd_mask_item_selector :: Pointers not valid");
            return false;
        }

        SDK::FTransform ui_mask_transform{};
        ui_mask_transform.Rotation = { 0.f, 0.f, 1.f, 0.f };
        ui_mask_transform.Scale3D = { 1.f, 0.1f, 0.1f };
        ui_mask_transform.Translation = { 0.f, 0.f, 0.f };

        m_ui_mask_widget_component = static_cast<SDK::UWidgetComponent*>(
            m_mfd_mask_actor->AddComponentByClass(
                SDK::UWidgetComponent::StaticClass(), false, ui_mask_transform, false
            )
        );

        //m_hud->RemoveFromViewport();
        //m_ui_mask_widget_component->SetWidget(m_hud->WIDGET_MainInventoryPanel);

        SDK::APlayerController* ctrl = SDK::UGameplayStatics::GetPlayerController(m_world, 0);
        int size_x, size_y;
        ctrl->GetViewportSize(&size_x, &size_y);
        m_ui_mask_widget_component->SetDrawSize({ static_cast<float>(size_x), static_cast<float>(size_y) });
        m_ui_mask_widget_component->SetVisibility(true, true);
        m_ui_mask_widget_component->SetHiddenInGame(false, false);

        // set properties for collision detection
        m_ui_mask_widget_component->SetWidgetSpace(SDK::EWidgetSpace::World);
        m_ui_mask_widget_component->SetCollisionEnabled(SDK::ECollisionEnabled::QueryOnly);
        m_ui_mask_widget_component->SetCollisionObjectType(item_selector_collision_channel);
        m_ui_mask_widget_component->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
        m_ui_mask_widget_component->SetCollisionResponseToChannel(
            item_selector_collision_channel, SDK::ECollisionResponse::ECR_Block
        );

        auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
            L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
            //L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Opaque.Widget3DPassThrough_Opaque"
        );
        SDK::FLinearColor color{ 0.4f, 0.4f, 0.4f, 0.2f };
        m_ui_mask_widget_component->SetMaterial(0, material);
        m_ui_mask_widget_component->SetTintColorAndOpacity(color);

        m_mfd_mask_actor->FinishAddComponent(m_ui_mask_widget_component, false, ui_mask_transform);

        return true;
    }

    // disables / enables collisions on close to body meshes to prevent unwanted collisions with the widget interation component trace
    void set_player_response_to_collision_channel(SDK::ECollisionChannel channel, SDK::ECollisionResponse response) {
        m_pawn->CapsuleComponent->SetCollisionResponseToChannel(channel, response);
        m_pawn->Mesh->SetCollisionResponseToChannel(channel, response);
        m_pawn->ArmsMesh->SetCollisionResponseToChannel(channel, response);
        m_pawn->WeaponMesh->SetCollisionResponseToChannel(channel, response);
    }


    // highlights selected item
    void highlight_quick_slot() {
        m_highlighted_widget_component.set_value(m_rh_interaction_component->GetHoveredWidgetComponent());
        
        if (m_highlighted_widget_component.has_changed()) {
            // highlight current selected slot
            if (m_highlighted_widget_component.value != nullptr) {
                auto widget = m_highlighted_widget_component.value->GetWidget();
                if (widget != nullptr && widget->IsA(SDK::UWIDGET_HotbarSlot_C::StaticClass())) {
                    static_cast<SDK::UWIDGET_HotbarSlot_C*>(widget)->SetIsCurrentQuickSlot(true);
                }
            }

            // remove highlight from previous slot
            if (m_highlighted_widget_component.prev_value != nullptr) {
                auto prev_widget = m_highlighted_widget_component.prev_value->GetWidget();
                if (prev_widget != nullptr && prev_widget->IsA(SDK::UWIDGET_HotbarSlot_C::StaticClass())) {
                    static_cast<SDK::UWIDGET_HotbarSlot_C*>(prev_widget)->SetIsCurrentQuickSlot(false);
                }
            }
        }
    }

    // change active hotbar slot
    void change_quick_slot() {
        if (m_highlighted_widget_component.value != nullptr) {
            auto widget = m_highlighted_widget_component.value->GetWidget();
            if (widget != nullptr && widget->IsA(SDK::UWIDGET_HotbarSlot_C::StaticClass())) {
                SDK::int32 slot_index;
                static_cast<SDK::UWIDGET_HotbarSlot_C*>(widget)->GetSlotIndex(&slot_index);

                m_pawn->ReceiveInputForHotbarSlotByIndex(
                    slot_index + 1, true
                );
            }
        }
    }

    // highlight selected hardware item
    void highlight_hardware_item() {
        m_highlighted_widget_component.set_value(m_rh_interaction_component->GetHoveredWidgetComponent());

        if (m_highlighted_widget_component.has_changed()) {
            // highlight current selected slot
            if (m_highlighted_widget_component.value != nullptr) {
                auto widget = m_highlighted_widget_component.value->GetWidget();
                if (widget != nullptr && widget->IsA(SDK::UWIDGET_HardwareButton_C::StaticClass())) {
                    static_cast<SDK::UWIDGET_HardwareButton_C*>(widget)->SetMouseOver(true, true);
                }
            }

            // remove highlight from previous slot
            if (m_highlighted_widget_component.prev_value != nullptr) {
                auto prev_widget = m_highlighted_widget_component.prev_value->GetWidget();
                if (prev_widget != nullptr && prev_widget->IsA(SDK::UWIDGET_HardwareButton_C::StaticClass())) {
                    static_cast<SDK::UWIDGET_HardwareButton_C*>(prev_widget)->SetMouseOver(false, true);
                }
            }
        }
    }

    // toggle hardware item
    void toggle_hardware() {
        if (m_highlighted_widget_component.value != nullptr) {
            auto widget = m_highlighted_widget_component.value->GetWidget();
            if (widget != nullptr && widget->IsA(SDK::UWIDGET_HardwareButton_C::StaticClass())) {
                static_cast<SDK::UWIDGET_HardwareButton_C*>(widget)->ToggleHardware();
            }
        }
    }

    // moves hotbar item selector to reflect pawn movements
    void update_primary_item_selector_location(float delta) {
        if (m_pawn == nullptr || m_primary_item_selector_component == nullptr)
            return;

        SDK::FVector new_location = m_pawn->RootComponent->K2_GetComponentLocation() - m_active_item_selector_delta;

        m_primary_item_selector_component->K2_SetWorldLocation(
            SDK::UKismetMathLibrary::VInterpTo(
                m_primary_item_selector_component->K2_GetComponentLocation(),
                new_location,
                delta, 
                60
            ), false, &m_reusable_result, false
        );
    }

    // moves hotbar item selector to reflect pawn movements
    void update_secondary_item_selector_location(float delta) {
        if (m_pawn == nullptr || m_secondary_item_selector_component == nullptr)
            return;

        SDK::FVector new_location = m_pawn->RootComponent->K2_GetComponentLocation() - m_active_item_selector_delta;

        m_secondary_item_selector_component->K2_SetWorldLocation(
            SDK::UKismetMathLibrary::VInterpTo(
                m_secondary_item_selector_component->K2_GetComponentLocation(),
                new_location,
                delta,
                60
            ), false, &m_reusable_result, false
        );
    }

    // moves mfd mask to reflect hmd/pawn movements
    void update_mfd_mask_location(float delta) {
        if (m_pawn == nullptr || m_mfd_component == nullptr)
            return;

        SDK::FVector new_location = m_pawn->RootComponent->K2_GetComponentLocation() - m_mfd_mask_delta;

        m_mfd_component->K2_SetWorldLocation(
            SDK::UKismetMathLibrary::VInterpTo(
                m_mfd_component->K2_GetComponentLocation(),
                new_location,
                delta,
                60
            ), false, &m_reusable_result, false
        );
    }

    SDK::FRotator get_item_selector_rotation() {
        if (m_primary_item_selector_component == nullptr)
            return{};

        return m_primary_item_selector_component->K2_GetComponentRotation();
    }

    void set_item_selector_rotation(SDK::FRotator rot) {
        if (m_primary_item_selector_component == nullptr)
            return;

        m_primary_item_selector_component->K2_SetWorldRotation(rot, false, &m_reusable_result, false);
    }

    // calculates and saves translation vector between pawn position and primary item selector position
    void save_primary_item_selector_delta(float distance_offset = 0.0f) {
        if (m_pawn == nullptr || m_primary_item_selector_component == nullptr || m_rh_controller_component == nullptr)
            return;

        auto rh_rot = m_rh_controller_component->K2_GetComponentRotation();
        const auto fvec = SDK::UKismetMathLibrary::Multiply_VectorFloat(
            SDK::UKismetMathLibrary::GetForwardVector(rh_rot),
            m_primary_item_selector_distance + distance_offset
        );

        const auto item_selector_pos = m_rh_controller_component->K2_GetComponentLocation() + fvec;
        m_primary_item_selector_component->K2_SetWorldLocation(item_selector_pos, false, &m_reusable_result, false);

        rh_rot.Roll = 0.0f;
        m_primary_item_selector_component->K2_SetWorldRotation(rh_rot, false, &m_reusable_result, false);
        
        m_active_item_selector_delta = m_pawn->RootComponent->K2_GetComponentLocation() - item_selector_pos;
    }

    // calculates and saves translation vector between pawn position and secondary item selector position
    void save_secondary_item_selector_delta(float distance_offset = 0.0f) {
        if (m_pawn == nullptr || m_secondary_item_selector_component == nullptr || m_rh_controller_component == nullptr)
            return;

        auto rh_rot = m_rh_controller_component->K2_GetComponentRotation();
        const auto fvec = SDK::UKismetMathLibrary::Multiply_VectorFloat(
            SDK::UKismetMathLibrary::GetForwardVector(rh_rot),
            m_secondary_item_selector_distance + distance_offset
        );

        const auto item_selector_pos = m_rh_controller_component->K2_GetComponentLocation() + fvec;
        m_secondary_item_selector_component->K2_SetWorldLocation(item_selector_pos, false, &m_reusable_result, false);

        rh_rot.Roll = 0.0f;
        m_secondary_item_selector_component->K2_SetWorldRotation(rh_rot, false, &m_reusable_result, false);

        m_active_item_selector_delta = m_pawn->RootComponent->K2_GetComponentLocation() - item_selector_pos;
    }

    // calculates and saves translation vector between hmd position and mfd mask
    void set_mfd_mask_delta() {
        if (m_mfd_component == nullptr || m_hmd_component == nullptr)
            return;

        auto rot = m_hmd_component->K2_GetComponentRotation();
        auto mask_delta = SDK::UKismetMathLibrary::Multiply_VectorFloat(
            SDK::UKismetMathLibrary::GetForwardVector(rot),
            m_mfd_depth
        );

        const auto mfd_mask_pos = m_hmd_component->K2_GetComponentLocation() + mask_delta;
        m_mfd_component->K2_SetWorldLocation(mfd_mask_pos, false, &m_reusable_result, false);

        rot.Roll = 0.0f;
        m_mfd_component->K2_SetWorldRotation(rot, false, &m_reusable_result, false);

        m_mfd_mask_delta = m_pawn->RootComponent->K2_GetComponentLocation() - mfd_mask_pos;
    }

    void set_primary_item_selector_visibility(bool visible) {
        for (int i = 0; i < 10; i++) {
            if (m_hotbar_slot_widget_components[i] != nullptr) {
                m_hotbar_slot_widget_components[i]->SetVisibility(visible, visible);
                m_hotbar_slot_widget_components[i]->SetHiddenInGame(!visible, !visible);
                set_hotbar_slot_visibility(i, visible);

                m_hotbar_slot_widget_components[i]->SetCollisionResponseToChannel(
                    item_selector_collision_channel, visible ? SDK::ECollisionResponse::ECR_Block : SDK::ECollisionResponse::ECR_Ignore
                );
            }
        }
    }

    void set_secondary_item_selector_visibility(bool visible) {
        for (int i = 0; i < 5; i++) {
            if (m_hacker_hardware_widget_components[i] != nullptr) {
                m_hacker_hardware_widget_components[i]->SetVisibility(visible, visible);
                m_hacker_hardware_widget_components[i]->SetHiddenInGame(!visible, !visible);
                //m_hardware_widgets[i]->SetVisibility(visible ? SDK::ESlateVisibility::Visible : SDK::ESlateVisibility::Hidden);

                m_hacker_hardware_widget_components[i]->SetCollisionResponseToChannel(
                    item_selector_collision_channel, visible ? SDK::ECollisionResponse::ECR_Block : SDK::ECollisionResponse::ECR_Ignore
                );
            }
        }
        set_hacker_hardware_visibility(visible);
    }

    // TODO
    void set_mfd_mask_visibility(bool visible) {
        m_ui_mask_widget_component->SetVisibility(visible, visible);
        m_ui_mask_widget_component->SetHiddenInGame(!visible, !visible);
        m_ui_mask_widget_component->SetCollisionResponseToChannel(
            item_selector_collision_channel, visible ? SDK::ECollisionResponse::ECR_Block : SDK::ECollisionResponse::ECR_Ignore
        );
    }

    void set_hotbar_slot_visibility(int slot, bool visible) {
        if (m_hud == nullptr)
            return;

        m_hud->HotbarSlots[slot]->SetVisibility(visible ? SDK::ESlateVisibility::Visible : SDK::ESlateVisibility::Hidden);
    }

    void unselect_all_hotbar_slots() {
        if (m_hud == nullptr)
            return;

        for (int i = 0; i < 10; i++) {
            m_hud->HotbarSlots[i]->SetIsCurrentQuickSlot(false);
        }
    }

    void set_mfd_hotbar_visibility(bool visible)
    {
        for (int i = 0; i < 10; i++) {
            set_hotbar_slot_visibility(i, visible);
        }
    }

    void set_hacker_hardware_visibility(bool visible)
    {
        if (m_hud == nullptr)
            return;

        if (visible) {
            m_hud->ShowHardwareIcons();
        }
        else {
            m_hud->HideHardwareIcons();
        }
    }

    void unselect_all_hacker_hardware() {
        if (m_hud == nullptr)
            return;

        for (int i = 0; i < 5; i++) {
            m_hardware_widgets[i]->SetMouseOver(false, true);
        }
    }

    void set_laser_pointer_visibility(bool visible) {
        if (m_laser_pointer_component != nullptr) {
            m_laser_pointer_component->SetHiddenInGame(!visible, true);
        }
    }

    void update_laser_pointer_length(float no_hit_length) {
        float hit_distance = m_rh_interaction_component->GetHoveredWidgetComponent() != nullptr ? m_rh_interaction_component->GetLastHitResult().Distance - 30.f : no_hit_length;

        m_laser_pointer_component->SetCapsuleHalfHeight(hit_distance / 2, false);
        m_laser_pointer_component->K2_SetRelativeLocation({ (hit_distance / 2) + 30.f, 0.f, 0.f }, false, &m_reusable_result, false);
    }

    // -------------------------------------------------------------------------------------
    // attachments cleanup
    // -------------------------------------------------------------------------------------

    // this function tries to find and destroy actors we created for attachments, even when we no longer have pointers to them
    // TODO add mfd mask cleanup
    static int cleanup() {
        API::get()->log_info("cleanup_widget_components :: Cleaning up stale Widget Components");
        std::vector<SDK::UObject*> actors{};
        std::vector<SDK::UObject*> components{};

        auto klass = API::get()->find_uobject<API::UClass>(L"Class /Script/UMG.WidgetComponent");
        if (klass != nullptr) {
            std::vector<SDK::UWidgetComponent*> items = klass->get_objects_matching<SDK::UWidgetComponent>();
            for (size_t i = 0; i < items.size(); i++) {
                if (items[i]->Widget != nullptr) {
                    auto name = items[i]->Widget->GetFullName();
                    if (
                        name.ends_with(".WIDGET_Minimap")
                        || name.ends_with(".WIDGET_HotbarSlot1")
                        || name.ends_with(".WIDGET_HardwareButton_EnviroPack")
                        ) {
                        if (items[i]->Outer != nullptr) {
                            actors.push_back(items[i]->Outer);
                            API::get()->log_info("cleanup_widget_components :: Added an Actor for cleanup");
                        }
                        else {
                            API::get()->log_info("cleanup_widget_components :: Widget Component has no Outer actor!");
                        }
                    }
                }
            }
        }
        else {
            API::get()->log_info("cleanup_widget_components :: Could not find Widget Component class");
        }

        // removing actor duplicates if exist
        std::sort(actors.begin(), actors.end());
        actors.erase(std::unique(actors.begin(), actors.end()), actors.end());

        // destroying actors
        for (size_t i = 0; i < actors.size(); i++) {
            if (actors[i] != nullptr && SDK::UKismetSystemLibrary::IsValid(actors[i]) && actors[i]->IsA(SDK::AActor::StaticClass())) {
                static_cast<SDK::AActor*>(actors[i])->K2_DestroyActor();
                API::get()->log_info("cleanup_widget_components :: Destroyed an Actor");
            }
        }

        return actors.size();
    }

    // as of 12-07-2024 it's no longer used because using ECC_EngineTraceChannel1 doesn't conflict with game world
    // I'm going to leave it here if it's needed for something and as a sample how to use SphereOverlapComponents
    void disable_conflicting_collisions() {
        //API::get()->log_info("VRHackerHUD :: Removing Lift/RepulsorLift Collisions on Channel: % d", item_selector_collision_channel);

        // Set what actors to seek out from it's collision channel
        SDK::TArray<SDK::EObjectTypeQuery> traceObjectTypes;
        SDK::TArray<SDK::EObjectTypeQuery> object_types{};
        API::get()->log_info("VRHackerHUD :: Adding type");
        object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery32);
        API::get()->log_info("VRHackerHUD :: Added type");
        //object_types.Add(SDK::UEngineTypes::ConvertToObjectType(SDK::ECollisionChannel::ECC_GameTraceChannel18));

        SDK::UClass* component_class_filter{ SDK::UStaticMeshComponent::StaticClass() };
        const SDK::TArray<SDK::AActor*>& actors_to_ignore{};
        SDK::TArray<SDK::UPrimitiveComponent*> out_components{};

        // get overlapping components
        const bool result = SDK::UKismetSystemLibrary::SphereOverlapComponents(
            m_world,
            m_mfd_component->K2_GetComponentLocation(),
            300.f,
            object_types,
            component_class_filter,
            actors_to_ignore,
            &out_components
        );

        API::get()->log_info("VRHackerHUD :: Testing result");
        API::get()->log_info("VRHackerHUD :: Overlapped obj no: %d", out_components.Num());
        if (result) {
            for (size_t i = 0; i < out_components.Num(); i++) {
                API::get()->log_info("VRHackerHUD :: Overlapped obj: %s", out_components[i]->GetFullName().c_str());
                out_components[i]->SetCollisionResponseToChannel(item_selector_collision_channel, SDK::ECollisionResponse::ECR_Ignore);
            }
        }
        else {
            API::get()->log_info("VRHackerHUD :: Wrong overlap result");
        }

        API::UClass* class_ptr = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Blueprints/Interactables/RepulsorLift/INTERACT_RepulsorLift.INTERACT_RepulsorLift_C");
        if (class_ptr != nullptr) {
            std::vector<API::UObject*> matching_objects = class_ptr->get_objects_matching<API::UObject>();

            for (size_t i = 0; i < matching_objects.size(); i++) {
                auto obj = (SDK::UObject*)matching_objects[i];

                if (obj->IsA(SDK::AINTERACT_RepulsorLift_C::StaticClass())) {
                    //API::get()->log_info("VRHackerHUD :: Found RepulsorLift: %s", obj->GetFullName().c_str());
                    static_cast<SDK::AINTERACT_RepulsorLift_C*>(obj)->RepulsorField->SetCollisionResponseToChannel(item_selector_collision_channel, SDK::ECollisionResponse::ECR_Ignore);
                }
            }
        }

        class_ptr = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Blueprints/Interactables/Lifts/INTERACT_Lift_Base.INTERACT_Lift_Base_C");
        if (class_ptr != nullptr) {
            std::vector<API::UObject*> matching_objects = class_ptr->get_objects_matching<API::UObject>();

            for (size_t i = 0; i < matching_objects.size(); i++) {
                auto obj = (SDK::UObject*)matching_objects[i];

                if (obj->IsA(SDK::AINTERACT_Lift_Base_C::StaticClass())) {
                    //API::get()->log_info("VRHackerHUD :: Found Lift: %s", obj->GetFullName().c_str());
                    static_cast<SDK::AINTERACT_Lift_Base_C*>(obj)->PlatformCollision->SetCollisionResponseToChannel(item_selector_collision_channel, SDK::ECollisionResponse::ECR_Ignore);
                }
            }
        }

        class_ptr = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Blueprints/Interactables/Elevator/ELEVATOR_Base.ELEVATOR_Base_C");
        if (class_ptr != nullptr) {
            std::vector<API::UObject*> matching_objects = class_ptr->get_objects_matching<API::UObject>();

            for (size_t i = 0; i < matching_objects.size(); i++) {
                auto obj = (SDK::UObject*)matching_objects[i];

                if (obj->IsA(SDK::AELEVATOR_Base_C::StaticClass())) {
                    //API::get()->log_info("VRHackerHUD :: Found Elevator: %s", obj->GetFullName().c_str());
                    static_cast<SDK::AELEVATOR_Base_C*>(obj)->CompartmentSensor->SetCollisionResponseToChannel(item_selector_collision_channel, SDK::ECollisionResponse::ECR_Ignore);
                }
            }
        }
    }

    SDK::FVector2D get_2D_hit_position() {
        if (m_rh_interaction_component->HoveredWidgetComponent != nullptr) {
            return m_rh_interaction_component->Get2DHitLocation();
        }
        else {
            return { 0.f, 0.f };
        }
    }

    void set_crosshair_cursor_scale(float *scale) {
        if (m_hud != nullptr && m_hud->WIDGET_CrosshairCursor != nullptr) {
            m_hud->WIDGET_CrosshairCursor->MESH_CrosshairCursor->SetRenderScale({ *scale, *scale });
        }
    }

    void set_cursor_brackets_scale(float *scale) {
        if (m_hud != nullptr && m_hud->WIDGET_CrosshairCursor != nullptr) {
            m_hud->WIDGET_CrosshairCursor->MESH_CursorBrackets->SetRenderScale({ *scale, *scale });
        }
    }
};
