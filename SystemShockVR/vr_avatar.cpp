#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"

#include "plugin_utils.hpp"
#include "vr_avatar.hpp"

using namespace SDK;
using namespace uevr;

A_BP_VRAvatar_C* VRAvatar::initialize_vr_avatar(APAWN_Avatar_C* pawn) {
    try {
        API::get()->log_warn("[vr_avatar][initialize_vr_avatar] Begin");

        auto world = UWorld::GetWorld();
        PluginUtils::destroy_actors_by_class(world, A_BP_VRAvatar_C::StaticClass());

        const FVector pawn_location = pawn->K2_GetActorLocation();
        FTransform pawn_transform{};
        pawn_transform.Rotation = { 0.f, 0.f, 0.f, 1.f };
        pawn_transform.Translation = { pawn_location.X, pawn_location.Y, pawn_location.Z };
        pawn_transform.Scale3D = { 1.f, 1.f, 1.f };

        API::get()->log_warn("[vr_avatar][initialize_vr_avatar] Spawning VRAvatar BP actor");
        A_BP_VRAvatar_C* vr_avatar = (A_BP_VRAvatar_C*)UGameplayStatics::BeginDeferredActorSpawnFromClass(
            world, A_BP_VRAvatar_C::StaticClass(), pawn_transform, ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr
        );
        if (vr_avatar == nullptr) {
            API::get()->log_error("[vr_avatar][initialize_vr_avatar] Error spawning VRAvatar BP Actor");
            return nullptr;
        }

        UGameplayStatics::FinishSpawningActor(vr_avatar, pawn_transform);
        API::get()->log_warn("[vr_avatar][initialize_vr_avatar] Finishied spawning VRAvatar BP Actor");

        TArray<FName> actor_tags{};
        actor_tags.Data = (FName*)API::FMalloc::get()->malloc(1 * sizeof(FName));
        actor_tags.NumElements = 1;
        actor_tags.MaxElements = 1;
        actor_tags.Data[0] = UKismetStringLibrary::Conv_StringToName(L"VRAvatarActor");

        vr_avatar->Tags = actor_tags;
        API::get()->log_warn("[vr_avatar][initialize_vr_avatar] Added 'VRAvatarActor' Tag");

        vr_avatar->K2_AttachRootComponentTo(
            pawn->K2_GetRootComponent(),
            UKismetStringLibrary::Conv_StringToName(L"None"),
            EAttachLocation::SnapToTarget,
            true
        );

        //pawn->Camera->K2_AttachToComponent(
        //    (USceneComponent*)vr_avatar->MotionControllerRight,
        //    UKismetStringLibrary::Conv_StringToName(L"None"),
        //    EAttachmentRule::SnapToTarget,
        //    EAttachmentRule::SnapToTarget,
        //    EAttachmentRule::KeepWorld,
        //    true
        //);

        //pawn->Camera->Deactivate();
        API::get()->log_warn("[vr_avatar][initialize_vr_avatar] VRAvatar Initialized");
    }
    catch (...) {
        API::get()->log_error("[vr_avatar][initialize_vr_avatar] Exception");
    }
    return nullptr;
}