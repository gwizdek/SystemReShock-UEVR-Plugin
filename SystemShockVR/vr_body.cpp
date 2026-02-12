#include "uevr/API.hpp"

#include "SDK/Niagara_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/CH_Hacker_AnimBP_classes.hpp"

#include "SDK/_BP_LaserDot_classes.hpp"

#include "vr_body.hpp"
#include "vr_plugin_shared.hpp"

using namespace uevr;
using namespace SDK;

// disables / enables collisions on close to body meshes to prevent unwanted collisions with the widget interation component trace
void VRBody::set_player_response_to_collision_channel(APAWN_Hacker_Implant_C* pawn, A_BP_VRBody_C* vr_body, ECollisionChannel channel, ECollisionResponse response) {
    try {
        pawn->CapsuleComponent->SetCollisionResponseToChannel(channel, response);
        pawn->Mesh->SetCollisionResponseToChannel(channel, response);
        pawn->ArmsMesh->SetCollisionResponseToChannel(channel, response);
        pawn->WeaponMesh->SetCollisionResponseToChannel(channel, response);
        vr_body->VRBodyMesh->SetCollisionResponseToChannel(channel, response);
    }
    catch (...) {
        API::get()->log_error("[vrbody][set_player_response_to_collision_channel] Exception");
    }
}

//void VRBody::set_player_response_to_all_collision_channels(ECollisionResponse response) {
//    try {
//        if (m_main == nullptr) {
//            return;
//        }
//        auto pawn = static_cast<APAWN_Hacker_Implant_C*>(m_main->get_pawn());
//        if (pawn != nullptr) {
//            pawn->CapsuleComponent->SetCollisionResponseToAllChannels(response);
//            pawn->Mesh->SetCollisionResponseToAllChannels(response);
//            pawn->ArmsMesh->SetCollisionResponseToAllChannels(response);
//            pawn->WeaponMesh->SetCollisionResponseToAllChannels(response);
//            API::get()->log_warn("[vrbody][set_player_response_to_all_collision_channels] Hacker collision changed");
//        }
//
//        if (m_bp_actor != nullptr) {
//            API::get()->log_warn("[vrbody][set_player_response_to_all_collision_channels] VRBody collision changed");
//            m_bp_actor->VRBodyMesh->SetCollisionResponseToAllChannels(response);
//        }
//    }
//    catch (...) {
//        API::get()->log_error("[vrbody][set_player_response_to_all_collision_channels] Exception");
//    }
//}

// A_BP_VRBody_C class is loaded into memory by hard-referencing it in the modified ArmsMesh AnimBP
A_BP_VRBody_C* VRBody::initialize_vr_body(APAWN_Hacker_Implant_C* pawn) {
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
        actor_tags.Data[0] = UKismetStringLibrary::Conv_StringToName(L"VRBodyActor");

        vr_body->Tags = actor_tags;
        API::get()->log_warn("[vr_body][initialize_vr_body] Added 'VRBodyActor' Tag");

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


        // HMDComponent tracks UEVR Camera offset to RootComponent (our VROrigin)
        auto hmd_state = API::UObjectHook::get_or_add_motion_controller_state((API::UObject*)vr_body->HMDComponent);
        if (hmd_state == nullptr) {
            API::get()->log_error("[vr_body][initialize_vr_body] Failed to hook HMD motion controller component");
            return nullptr;
        }
        hmd_state->set_hand(2);
        hmd_state->set_permanent(true);
        API::get()->log_warn("[vr_body][initialize_vr_body] Hooked HMD motion controller component");


        // Re-Attach Hacker Hardware
        static_cast<APAWN_Hacker_Implant_C*>(pawn)->MediaReaderMesh->K2_AttachToComponent(
            vr_body->VRBodyMesh,
            UKismetStringLibrary::Conv_StringToName(L"LeftForeArmRoll1"),
            EAttachmentRule::SnapToTarget,
            EAttachmentRule::KeepRelative,
            EAttachmentRule::KeepWorld,
            true
        );
        static_cast<APAWN_Hacker_Implant_C*>(pawn)->MediaReaderMesh->K2_SetRelativeLocationAndRotation(
            { 7.f, 3.f, 0.5f }, { 0.f, 3.f, 77.f }, false, &SweepHitResult, false
        );
        API::get()->log_warn("[vr_body][initialize_vr_body] Attached Media Reader");

        // set WidgetInteractionComponent trace channel
        vr_body->WidgetInteractionRight->TraceChannel = WIDGET_INTERACTION_TRACE_CHANNEL;

        return vr_body;
    }
    catch (...) {
        API::get()->log_error("[vr_body][initialize_vr_body] Exception");
    }
    return nullptr;
}

void VRBody::initialize_laser_dot(A_BP_VRBody_C* vr_body) {
    API::get()->log_warn("[vrbody][initialize_laser_dot] Begin");
    if (vr_body == nullptr) {
        API::get()->log_error("[vrbody][initialize_laser_dot] Invalid BP Actor");
        return;
    }

    FHitResult hit_result{};
    vr_body->LaserDot->DrawDebugSphere = false;
    vr_body->LaserDot->TraceChannel = ETraceTypeQuery::TraceTypeQuery3;
    vr_body->LaserDot->RootComponent->K2_SetRelativeLocationAndRotation({ 0.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, false, &hit_result, false);

    //vr_body->LaserDot->LaserDotComponent->Activate(true);
    vr_body->LaserDot->LaserDotComponent->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Power"), 0.5f);
    vr_body->LaserDot->LaserDotComponent->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Size"), 3.f);
    vr_body->LaserDot->EnableTrace();

    vr_body->LaserDot->LaserPointerComponent->SetFloatParameter(UKismetStringLibrary::Conv_StringToName(L"Power"), 0.1f);
    vr_body->LaserDot->LaserPointerComponent->SetColorParameter(UKismetStringLibrary::Conv_StringToName(L"LaserColour"), { 0.2f, 0.f, 0.f, 0.5f });
    vr_body->LaserDot->LaserPointerComponent->SetColorParameter(UKismetStringLibrary::Conv_StringToName(L"PrimaryColor"), { 0.2f, 0.f, 0.f, 0.5f });

    //PluginUtils::bytes_to_float("Power", 0, 0, 128, 63);
    //PluginUtils::bytes_to_float("Size", 0, 0, 192, 64);
}

void VRBody::overwrite_hacker_crouch_animations(APAWN_Hacker_Implant_C* pawn) {
    API::get()->log_warn("[vrbody][override_hacker_walk_animations] Start");

    SDK::UCH_Hacker_AnimBP_C* hacker_anim = (SDK::UCH_Hacker_AnimBP_C*)pawn->Mesh->AnimScriptInstance;
    if (hacker_anim != nullptr) {
        // make crouch animations use walk animations
        hacker_anim->AnimGraphNode_SequencePlayer_8.Sequence = hacker_anim->AnimGraphNode_SequencePlayer_7.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_5.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_2.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_6.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_1.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_11.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_8.Sequence;
        hacker_anim->AnimGraphNode_SequenceEvaluator_12.Sequence = hacker_anim->AnimGraphNode_SequenceEvaluator_7.Sequence;
    }
}

void VRBody::set_weapon_mesh_visibility(APAWN_Hacker_Implant_C* pawn, bool visible) {
    pawn->WeaponMesh->SetVisibility(visible, true);
}

void VRBody::reset_player_camera(APAWN_Hacker_Implant_C* pawn) {
    // Re-Attach Hacker Camera
    static_cast<APAWN_Hacker_Implant_C*>(pawn)->PlayerCamera->K2_AttachToComponent(
        pawn->LookPivot,
        UKismetStringLibrary::Conv_StringToName(L"None"),
        EAttachmentRule::SnapToTarget,
        EAttachmentRule::KeepRelative,
        EAttachmentRule::KeepWorld,
        true
    );

    static_cast<APAWN_Hacker_Implant_C*>(pawn)->PlayerCamera->Activate(false);
}
