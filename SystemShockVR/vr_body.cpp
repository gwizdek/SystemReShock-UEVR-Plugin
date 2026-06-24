#include "uevr/API.hpp"

#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/Niagara_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/COMP_HackerInventory_classes.hpp"
#include "SDK/CH_Hacker_AnimBP_classes.hpp"
#include "SDK/WIDGET_VitalBars_classes.hpp"
#include "SDK/WIDGET_MediaDisplay_classes.hpp"
#include "SDK/WIDGET_Minimap_classes.hpp"
#include "SDK/WIDGET_HardwareButton_classes.hpp"
#include "SDK/WIDGET_UnreadMediaIcon_classes.hpp"
#include "SDK/WIDGET_Subtitles_classes.hpp"
#include "SDK/_BP_AccessCard_classes.hpp"

#include "SDK/_BP_VRBody_classes.hpp"
#include "SDK/_BP_LaserDot_classes.hpp"
#include "SDK/_BP_MFDMaskComponent_classes.hpp"
#include "SDK/_BP_HackerHardware_classes.hpp"
#include "SDK/_BP_DebugWidgetComponent_classes.hpp"
#include "SDK/_WIDGET_VRHUD_classes.hpp"

#include "vr_body.hpp"
#include "vr_plugin_shared.hpp"
#include "plugin_utils.hpp"

extern SDK::A_BP_VRBody_C* g_vr_body;

using namespace uevr;
using namespace SDK;

// disables / enables collisions on close to body meshes to prevent unwanted collisions with the widget interation component trace
void VRBody::set_player_response_to_collision_channel(ECollisionChannel channel, ECollisionResponse response) {
    if (!UKismetSystemLibrary::IsValid(g_vr_body)) {
        API::get()->log_error("[vrbody][set_player_response_to_collision_channel] Invalid vr_body");
        return;
    }

    try {
        g_vr_body->HackerPawn->CapsuleComponent->SetCollisionResponseToChannel(channel, response);
        g_vr_body->HackerPawn->Mesh->SetCollisionResponseToChannel(channel, response);
        g_vr_body->HackerPawn->ArmsMesh->SetCollisionResponseToChannel(channel, response);
        g_vr_body->HackerPawn->WeaponMesh->SetCollisionResponseToChannel(channel, response);
        g_vr_body->VRBodyMesh->SetCollisionResponseToChannel(channel, response);
    }
    catch (...) {
        API::get()->log_error("[vrbody][set_player_response_to_collision_channel] Exception");
    }
}


// A_BP_VRBody_C class is loaded into memory by hard-referencing it in the modified ArmsMesh AnimBP
A_BP_VRBody_C* VRBody::initialize_vr_body(APAWN_Hacker_Simple_C* pawn) {
    try {
        API::get()->log_warn("[vr_body][initialize_vr_body] Begin");
        auto world = UWorld::GetWorld();

        const FVector pawn_location = pawn->K2_GetActorLocation();
        FTransform pawn_transform{};
        pawn_transform.Rotation = { 0.f, 0.f, 0.f, 1.f };
        pawn_transform.Translation = { pawn_location.X, pawn_location.Y, pawn_location.Z };
        pawn_transform.Scale3D = { 1.f, 1.f, 1.f };

        API::get()->log_warn("[vr_body][initialize_vr_body] Spawning VRBody BP actor");
        A_BP_VRBody_C* vr_body = (A_BP_VRBody_C*)UGameplayStatics::BeginDeferredActorSpawnFromClass(
            world, A_BP_VRBody_C::StaticClass(), pawn_transform, ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr
        );
        if (vr_body == nullptr) {
            API::get()->log_error("[vr_body][initialize_vr_body] Error spawning VRBody BP Actor");
            return nullptr;
        }

        UGameplayStatics::FinishSpawningActor(vr_body, pawn_transform);
        API::get()->log_warn("[vr_body][initialize_vr_body] Finishied spawning VRBody BP Actor");

        TArray<FName> actor_tags{};
        actor_tags.Data = (FName*)API::FMalloc::get()->malloc(1 * sizeof(FName));
        actor_tags.NumElements = 1;
        actor_tags.MaxElements = 1;
        actor_tags.Data[0] = UKismetStringLibrary::Conv_StringToName(L"VRModActor");

        vr_body->Tags = actor_tags;
        API::get()->log_warn("[vr_body][initialize_vr_body] Added 'VRModActor' Tag");

        vr_body->K2_AttachRootComponentTo(
            pawn->K2_GetRootComponent(),
            UKismetStringLibrary::Conv_StringToName(L"None"),
            EAttachLocation::SnapToTarget,
            true
        );

        FHitResult SweepHitResult{};
        // move vr actor down to the bottom of the collision capsule
        vr_body->K2_GetRootComponent()->K2_SetRelativeLocation({ 0.0f, 0.0f, -80.0f }, false, &SweepHitResult, false);
        API::get()->log_warn("[vr_body][initialize_vr_body] Attached to Hacker's root component");

        vr_body->TrailingRotationComponent->K2_SetWorldRotation(vr_body->DefaultSceneRoot->K2_GetComponentRotation(), false, &SweepHitResult, false);

        // HMDComponent tracks UEVR Camera offset to RootComponent (our VROrigin)
        auto hmd_state = API::UObjectHook::get_or_add_motion_controller_state((API::UObject*)vr_body->HMDComponent);
        if (hmd_state == nullptr) {
            API::get()->log_error("[vr_body][initialize_vr_body] Failed to hook HMD motion controller component");
            return nullptr;
        }
        hmd_state->set_hand(2);
        hmd_state->set_permanent(true);

        API::get()->log_warn("[vr_body][initialize_vr_body] Hooked HMD motion controller component");

        static_cast<APAWN_Hacker_Simple_C*>(pawn)->HeadRangedCollision->SphereRadius = 7.f;

        // an attempt to disable collisions on arms that don't allow laser pointer to go through (unsuccessful)
        static_cast<APAWN_Hacker_Simple_C*>(pawn)->ArmsMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
        static_cast<APAWN_Hacker_Simple_C*>(pawn)->ArmsMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        static_cast<APAWN_Hacker_Simple_C*>(pawn)->ArmsMesh->SetCollisionObjectType(ECollisionChannel::ECC_EngineTraceChannel6);
        static_cast<APAWN_Hacker_Simple_C*>(pawn)->ArmsMesh->SetVisibility(false, false);

        //
        // Hacker Implant Pawn
        //
        if (!pawn->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
            API::get()->log_warn("[vr_body][initialize_vr_body] Not a APAWN_Hacker_Implant. Returning.");
            return vr_body;
        }

        // The rest of initialization is done only for HackerImplant pawn
        // Re-Attach Hacker Hardware
        static_cast<APAWN_Hacker_Implant_C*>(pawn)->MediaReaderMesh->K2_AttachToComponent(
            vr_body->VRBodyMesh,
            UKismetStringLibrary::Conv_StringToName(L"MediaReaderSocket"),
            EAttachmentRule::SnapToTarget,
            EAttachmentRule::SnapToTarget,
            EAttachmentRule::KeepWorld,
            true
        );

        API::get()->log_warn("[vr_body][initialize_vr_body] Attached Media Reader");

        static_cast<APAWN_Hacker_Implant_C*>(pawn)->BioScannerMesh->K2_AttachToComponent(
            vr_body->VRBodyMesh,
            UKismetStringLibrary::Conv_StringToName(L"BioScannerSocket"),
            EAttachmentRule::SnapToTarget,
            EAttachmentRule::SnapToTarget,
            EAttachmentRule::KeepWorld,
            true
        );
        API::get()->log_warn("[vr_body][initialize_vr_body] Attached Bio Scanner");

        // set WidgetInteractionComponent trace channel
        vr_body->WidgetInteractionRight->TraceChannel = WIDGET_INTERACTION_TRACE_CHANNEL;

        vr_body->MFDMaskComponent->SetCollisionResponseToChannel(
            WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Ignore
        );

        vr_body->WidgetInteractionChannel = WIDGET_INTERACTION_TRACE_CHANNEL;

        UWIDGET_PlayerHUD_C* neural_hud{ nullptr };
        static_cast<APAWN_Hacker_Implant_C*>(pawn)->GetNeuralHUD(&neural_hud);
        if (neural_hud != nullptr) {
            vr_body->MinimapWidgetComponent->SetWidget(neural_hud->WIDGET_Minimap);
            neural_hud->WIDGET_Minimap->RemoveFromViewport();

            vr_body->VitalBarsWidgetComponent->SetWidget(neural_hud->WIDGET_VitalBars);
            neural_hud->WIDGET_VitalBars->RemoveFromViewport();

            vr_body->MediaDisplayWidgetComponent->SetWidget(neural_hud->WIDGET_MediaDisplay);
            neural_hud->WIDGET_MediaDisplay->RemoveFromViewport();

            //vr_body->UnreadMediaIcon->SetWidget(neural_hud->WIDGET_UnreadMediaIcon);
            //neural_hud->WIDGET_MediaDisplay->RemoveFromViewport();

            vr_body->Subtitles->SetVisibility(false, true);
            //vr_body->Subtitles->SetWidget(neural_hud->WIDGET_Subtitles);
            //neural_hud->WIDGET_Subtitles->RemoveFromViewport();

            PluginUtils::reparent_panel_to_user_widget(neural_hud->PANEL_Notification, vr_body->VRHUD->GetWidget());
            vr_body->VRHUD->SetVisibility(false, true);
            vr_body->VRHUD->SetVisibility(true, true);

        }
        else {
            API::get()->log_error("[vr_body][initialize_vr_body] Neural HUD pointer error");
        }

        return vr_body;
    }
    catch (...) {
        API::get()->log_error("[vr_body][initialize_vr_body] Exception");
    }
    return nullptr;
}

void VRBody::initialize_laser_dot() {
    API::get()->log_warn("[vrbody][initialize_laser_dot] Begin");
    if (!UKismetSystemLibrary::IsValid(g_vr_body)) {
        API::get()->log_error("[vrbody][initialize_laser_dot] Invalid vr_body");
        return;
    }

    FHitResult hit_result{};
    g_vr_body->LaserDot->TraceChannel = ETraceTypeQuery::TraceTypeQuery3;
    g_vr_body->LaserDot->RootComponent->K2_SetRelativeLocationAndRotation({ 0.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, false, &hit_result, false);

    //vr_body->LaserDot->LaserDotComponent->Activate(true);
    g_vr_body->LaserDot->LaserDotComponent->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Power"), 0.5f);
    g_vr_body->LaserDot->LaserDotComponent->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Size"), 3.f);

    g_vr_body->LaserDot->LaserPointerComponent->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Power"), 0.1f);
    g_vr_body->LaserDot->LaserPointerComponent->SetColorParameter(UKismetStringLibrary::Conv_StringToName(L"LaserColour"), { 0.2f, 0.f, 0.f, 0.5f });
    g_vr_body->LaserDot->LaserPointerComponent->SetColorParameter(UKismetStringLibrary::Conv_StringToName(L"PrimaryColor"), { 0.2f, 0.f, 0.f, 0.5f });

    //g_vr_body->LaserPointerLeft->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Power"), 10.05f);
    //g_vr_body->LaserPointerLeft->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Alpha"), 10.05f);
    //g_vr_body->LaserPointerLeft->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"LaserPower"), 10.05f);
    //g_vr_body->LaserPointerLeft->SetVectorParameter(UKismetStringLibrary::Conv_StringToName(L"TraceStartOffset"), { 20.0f, 0.f, 0.f });
    //g_vr_body->LaserPointerLeft->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"OcclusionSampleDiameter"), 50.f);

    //PluginUtils::bytes_to_float("Power", 0, 0, 128, 63);
    //PluginUtils::bytes_to_float("Size", 0, 0, 192, 64);
}

void VRBody::overwrite_hacker_crouch_animations() {
    API::get()->log_warn("[vrbody][override_hacker_walk_animations] Start");

    SDK::UCH_Hacker_AnimBP_C* hacker_anim = (SDK::UCH_Hacker_AnimBP_C*)g_vr_body->HackerPawn->Mesh->AnimScriptInstance;
    if (hacker_anim != nullptr) {
        // make crouch animations use walk animations
        hacker_anim->AnimGraphNode_SequencePlayer_8.Sequence = hacker_anim->AnimGraphNode_SequencePlayer_7.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_5.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_2.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_6.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_1.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_11.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_8.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_12.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_7.Sequence;
    }
}

void VRBody::set_weapon_mesh_visibility(bool visible) {
    g_vr_body->HackerPawn->WeaponMesh->SetVisibility(visible, true);
}

void VRBody::reset_player_camera() {
    try {
        // Re-Attach Hacker Camera to original location
        g_vr_body->HackerPawn->PlayerCamera->K2_AttachToComponent(
            g_vr_body->HackerPawn->LookPivot,
            UKismetStringLibrary::Conv_StringToName(L"None"),
            EAttachmentRule::SnapToTarget,
            EAttachmentRule::KeepRelative,
            EAttachmentRule::KeepWorld,
            true
        );

        g_vr_body->HackerPawn->PlayerCamera->Activate(false);
    }
    catch (...) {
        API::get()->log_error("[vr_body][reset_player_camera] Exception");
    }
}

void VRBody::show_vr_body() {
    try {
        g_vr_body->VRBodyMesh->SetVisibility(true, true);
        if (g_vr_body->AccessCard != nullptr) {
            g_vr_body->AccessCard->SetActorHiddenInGame(false);
        }
        g_vr_body->HackerPawn->WeaponMesh->SetVisibility(true, true);
    }
    catch (...) {
        API::get()->log_error("[vr_body][show_vr_body] Exception");
    }
}


void VRBody::hide_vr_body() {
    try {
        g_vr_body->VRBodyMesh->SetVisibility(false, true);
        if (g_vr_body->AccessCard != nullptr) {
            g_vr_body->AccessCard->SetActorHiddenInGame(true);
        }
        g_vr_body->HackerPawn->WeaponMesh->SetVisibility(false, true);
    }
    catch (...) {
        API::get()->log_error("[vr_body][hide_vr_body] Exception");
    }
}


void VRBody::initialize_minimap(UWIDGET_PlayerHUD_C* neural_hud) {
    // Setting WidgetComponent like this causes masive UObject creation when looking at the Minimap
    //g_vr_body->MinimapWidgetComponent->SetWidget(neural_hud->WIDGET_Minimap);

    //auto minimap = static_cast<UWIDGET_Minimap_C*>(g_vr_body->MinimapWidgetComponent->GetWidget());
    //if (minimap != nullptr) {
    //    minimap->PlayerHUD = neural_hud;
    //    minimap->EVENT_OnLevelChanged();
    //    minimap->EVENT_OnLevelRegionChanged();
    //    minimap->UpdateMinimap();
    //}
}

bool VRBody::is_valid_hacker_implant() {
    if (!UKismetSystemLibrary::IsValid(g_vr_body)) {
        API::get()->log_error("[vrbody][is_valid_hacker_implant] Invalid vr_body");
        return false;
    }

    if (!UKismetSystemLibrary::IsValid(g_vr_body->HackerPawn)) {
        API::get()->log_error("[vrbody][is_valid_hacker_implant] Invalid hacker pawn");
        return false;
    }

    if (!g_vr_body->HackerPawn->IsA(APAWN_Hacker_Implant_C::StaticClass())) {
        API::get()->log_error("[vrbody][is_valid_hacker_implant] Not a hacker implant pawn");
        return false;
    }

    return true;
}

void VRBody::set_media_display_visibility(bool visible) {
    if (is_valid_hacker_implant()) {
        g_vr_body->MediaDisplayWidgetComponent->SetVisibility(visible, true);
        g_vr_body->MediaDisplayWidgetComponent->SetHiddenInGame(!visible, true);

        g_vr_body->MinimapWidgetComponent->SetVisibility(!visible, true);
        g_vr_body->MinimapWidgetComponent->SetHiddenInGame(visible, true);
    }
}


void VRBody::initialize_ads() {
    try {
        API::get()->log_warn("[vr_body][initialize_ads] Initializing");
        g_vr_body->ADSTriggerCollision->SetCollisionObjectType(ADS_TRACE_CHANNEL);
        g_vr_body->ADSTriggerCollision->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
        g_vr_body->ADSTriggerCollision->SetCollisionResponseToChannel(
            ADS_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Overlap
        );

        g_vr_body->ADSZone->SetCollisionObjectType(ADS_TRACE_CHANNEL);
        g_vr_body->ADSZone->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
        g_vr_body->ADSZone->SetCollisionResponseToChannel(
            ADS_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Overlap
        );
    }
    catch (...) {
        API::get()->log_error("[vr_body][initialize_ads] Exception");
    }
}


void VRBody::initialize_hacker_hardware(UWIDGET_PlayerHUD_C* neural_hud) {
    try {
        std::array<SDK::UWIDGET_HardwareButton_C*, 4> hardware_widgets{};
        std::array<SDK::UWidgetComponent*, 4> hardware_widget_components{};
        // canvas panel slots
        std::array<SDK::UCanvasPanelSlot*, 4> canvas_panel_slots{};

        // store pointers to hardware items in an array
        API::get()->log_warn("[vr_body][initialize_hacker_hardware] set hardware widgets");
        hardware_widgets[0] = neural_hud->WIDGET_HardwareButton_EnergyShield;
        hardware_widgets[1] = neural_hud->WIDGET_HardwareButton_Sensaround;
        hardware_widgets[2] = neural_hud->WIDGET_HardwareButton_EnviroPack;
        hardware_widgets[3] = neural_hud->WIDGET_HardwareButton_TurboBoots;

        API::get()->log_warn("[vr_body][initialize_hacker_hardware] set hardware widget components");
        hardware_widget_components[0] = g_vr_body->HackerHardware->EnergyShieldWidgetComponent;
        hardware_widget_components[1] = g_vr_body->HackerHardware->SensaroundWidgetComponent;
        hardware_widget_components[2] = g_vr_body->HackerHardware->EnviroPakWidgetComponent;
        hardware_widget_components[3] = g_vr_body->HackerHardware->TurboBootsWidgetComponent;


        for (int i = 0; i < 4; i++) {
            // there's some going back and forth here as we want two things:
            // - a properly sized and aligned widget component for the collisions to work correctly
            // - a working hardware slot on the MFD
            // actually the same widget instance is used in two places: MFD / VR item selector,
            // save original panel slot for widget so we can later reuse it's attributes
            canvas_panel_slots[i] = (SDK::UCanvasPanelSlot*)hardware_widgets[i]->Slot;

            // we're going to remove hotbar slot form parent because widget's layout would be messed up after
            // binding it with widget component if we didn't
            //m_hardware_widgets[i]->RemoveFromViewport();
            API::get()->log_warn("[vr_body][initialize_hacker_hardware] exec SetWidget");
            hardware_widget_components[i]->SetWidget(hardware_widgets[i]);

            // set properties for collision detection
            hardware_widget_components[i]->SetCollisionObjectType(WIDGET_INTERACTION_TRACE_CHANNEL);
            hardware_widget_components[i]->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
            hardware_widget_components[i]->SetCollisionResponseToChannel(
                WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Overlap
            );

            auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
                L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
                //L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Opaque.Widget3DPassThrough_Opaque"
            );
            SDK::FLinearColor color{ 0.5f, 0.5f, 0.5f, 1.0f };
            hardware_widget_components[i]->SetMaterial(0, material);
            hardware_widget_components[i]->SetTintColorAndOpacity(color);
            hardware_widget_components[i]->BlendMode = EWidgetBlendMode::Masked;

            API::get()->log_warn("[vr_body][initialize_hacker_hardware] reseting PANELs");
            // recreate panel slot for widget and place it at original position on canvas panel
            // don't do it for right side buttons (Turbo Boots)
            auto panel_slot = i < 3
                ? (SDK::UCanvasPanelSlot*)neural_hud->PANEL_LeftHardware->AddChild(hardware_widgets[i])
                : (SDK::UCanvasPanelSlot*)neural_hud->PANEL_RightHardware->AddChild(hardware_widgets[i]);
            panel_slot->SetAlignment({ 0.5f, 0.5f });
            panel_slot->SetAnchors(SDK::FAnchors{ {0.5f, 0.5f}, {0.5f, 0.5f} });
            panel_slot->SetOffsets(canvas_panel_slots[i]->GetOffsets());
            hardware_widgets[i]->SetVisibility(SDK::ESlateVisibility::Visible);
        }

        API::get()->log_warn("[vr_body][initialize_hacker_hardware] Initialized");
    }
    catch (...) {
        API::get()->log_error("[vr_body][initialize_hacker_hardware] Exception");
    }
}

// Reparents PANEL_ActiveHazard (the poison / radiation readout) out of the flat PlayerHUD
// and into the dedicated ActiveHazard widget component so it renders in 3D space.
//
// Visibility is intentionally NOT hooked: PANEL_ActiveHazard stays a member of
// WIDGET_PlayerHUD, so the game's WIDGET_PlayerHUD::UpdateHazardLevel() keeps driving the
// panel's own visibility (Collapsed when safe, un-collapsed while a hazard is active) even
// after we move it. As long as the ActiveHazard component live-ticks, it mirrors that
// show/hide automatically.
//
// Requires: A_BP_VRBody_C must expose `UWidgetComponent* ActiveHazard` (add the component in
// the BP and regenerate the Dumper-7 SDK), and its assigned widget must have a UPanelWidget
// (CanvasPanel) root - e.g. the same _WIDGET_VRHUD_C used by VRHUD.
void VRBody::initialize_active_hazard(UWIDGET_PlayerHUD_C* neural_hud) {
    if (!UKismetSystemLibrary::IsValid(g_vr_body)) {
        API::get()->log_error("[vr_body][initialize_active_hazard] Invalid vr_body");
        return;
    }
    if (neural_hud == nullptr || !UKismetSystemLibrary::IsValid(neural_hud)) {
        API::get()->log_error("[vr_body][initialize_active_hazard] Invalid neural_hud");
        return;
    }
    if (!UKismetSystemLibrary::IsValid(g_vr_body->ActiveHazard)) {
        API::get()->log_error("[vr_body][initialize_active_hazard] Invalid ActiveHazard component");
        return;
    }

    try {
        UPanelWidget* hazard_panel = neural_hud->PANEL_ActiveHazard;
        if (!UKismetSystemLibrary::IsValid(hazard_panel)) {
            API::get()->log_error("[vr_body][initialize_active_hazard] Invalid PANEL_ActiveHazard");
            return;
        }

        // We only want the numeric level + icon, so drop the "Radiation Poisoning" type label.
        // Collapsed = gone; canvas children are positioned independently, so this does NOT reflow
        // TEXT_HazardLevel / MESH_HazardIcon - their position follows the PANEL width instead (below).
        if (UKismetSystemLibrary::IsValid(neural_hud->TEXT_HazardType)) {
            neural_hud->TEXT_HazardType->SetVisibility(ESlateVisibility::Collapsed);
        }

        // Surface now only needs the 120px-wide level value (right-anchored) + ~30px icon overhang:
        // 130px panel body + 30px icon -> 160px wide; two 28px rows + margin -> 48px tall.
        // (DrawSize is resolution; physical size / placement is the ActiveHazard component's BP transform.)
        g_vr_body->ActiveHazard->SetDrawSize(FVector2D{ 160.0f, 48.0f });
        g_vr_body->ActiveHazard->SetTwoSided(true);
        g_vr_body->ActiveHazard->BlendMode = EWidgetBlendMode::Transparent; // text/icon have soft alpha

        UPanelSlot* new_slot = PluginUtils::reparent_panel_to_user_widget(
            hazard_panel, g_vr_body->ActiveHazard->GetWidget()
        );
        if (new_slot == nullptr) {
            API::get()->log_error("[vr_body][initialize_active_hazard] Reparent failed");
            return;
        }

        // reparent_panel_to_user_widget defaults the new slot to full-stretch, which would put
        // the panel's right edge at the surface edge and clip MESH_HazardIcon (anchored beyond it).
        // Pin the panel to a 130x40 box at top-left: TEXT_HazardLevel (right-anchored, 120 wide)
        // lands at ~[10,130] and the icon at ~[132,160], leaving the right 30px of the 160px surface
        // for it. For a point anchor, FMargin reads as { posX, posY, sizeX, sizeY }.
        if (new_slot->IsA(UCanvasPanelSlot::StaticClass())) {
            UCanvasPanelSlot* canvas_slot = static_cast<UCanvasPanelSlot*>(new_slot);
            canvas_slot->SetAnchors(FAnchors{ { 0.0f, 0.0f }, { 0.0f, 0.0f } });
            canvas_slot->SetAlignment(FVector2D{ 0.0f, 0.0f });
            canvas_slot->SetOffsets(FMargin{ 0.0f, 4.0f, 130.0f, 40.0f });
        }

        // Do NOT force the panel Visible here - it ships Collapsed and the game un-collapses it
        // only while a hazard is active; forcing it on would show an empty frame. Just nudge the
        // component to rebuild its Slate tree with the new child (same off/on trick used for the
        // notification panel in initialize_vr_body).
        g_vr_body->ActiveHazard->SetVisibility(false, true);
        g_vr_body->ActiveHazard->SetVisibility(true, true);

        API::get()->log_warn("[vr_body][initialize_active_hazard] Initialized");
    }
    catch (...) {
        API::get()->log_error("[vr_body][initialize_active_hazard] Exception");
    }
}

void VRBody::initialize_hand_item_collisions() {
    // Index Finger Overlappers
    g_vr_body->LeftIndexFingerCollision->SetCollisionObjectType(WIDGET_INTERACTION_TRACE_CHANNEL);
    g_vr_body->LeftIndexFingerCollision->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
    g_vr_body->LeftIndexFingerCollision->SetCollisionResponseToChannel(
        WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Overlap
    );

    g_vr_body->RightIndexFingerCollision->SetCollisionObjectType(WIDGET_INTERACTION_TRACE_CHANNEL);
    g_vr_body->RightIndexFingerCollision->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
    g_vr_body->RightIndexFingerCollision->SetCollisionResponseToChannel(
        WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Overlap
    );
    g_vr_body->RightIndexFingerCollision->SetCollisionResponseToChannel(
        SDK::ECollisionChannel::ECC_GameTraceChannel1, SDK::ECollisionResponse::ECR_Overlap // Scanner
    );

    // Hand Item Collision Boxes
    g_vr_body->HandheldConsumableCollision->SetCollisionObjectType(WIDGET_INTERACTION_TRACE_CHANNEL);
    g_vr_body->HandheldConsumableCollision->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
    g_vr_body->HandheldConsumableCollision->SetCollisionResponseToChannel(
        WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Overlap
    );
}

void VRBody::set_debug_widget_visibility(bool visible) {
    if (g_vr_body != nullptr) {
        g_vr_body->DebugWidgetComponent->SetVisibility(visible, true);
    }
}
