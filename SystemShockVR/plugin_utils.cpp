#include "SDK/AssetRegistry_classes.hpp"

#include "plugin_utils.hpp"


using namespace uevr;

void PluginUtils::reset_height(float offset_y) {
    const UEVR_VRData* vr = API::get()->param()->vr;
    UEVR_Vector3f origin{};
    vr->get_standing_origin(&origin);

    UEVR_Vector3f hmd_pos{};
    UEVR_Quaternionf hmd_rot{};
    vr->get_pose(vr->get_hmd_index(), &hmd_pos, &hmd_rot);

    origin.y = (hmd_pos.y) + offset_y;

    vr->set_standing_origin(&origin);
}

SDK::AActor* PluginUtils::spawn_actor(SDK::UWorld* world, SDK::FTransform transform, std::wstring actor_tag) {
    try {
        if (world == nullptr) {
            API::get()->log_error("[plugin_utils][spawn_actor] Invalid world pointer");
            return nullptr;
        }

        SDK::AActor* actor = SDK::UGameplayStatics::BeginDeferredActorSpawnFromClass(
            world, SDK::AActor::StaticClass(), transform, SDK::ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr
        );
        if (actor == nullptr) {
            API::get()->log_error("[plugin_utils][spawn_actor] Error spawning actor");
            return nullptr;
        }

        SDK::UGameplayStatics::FinishSpawningActor(actor, transform);

        SDK::TArray<SDK::FName> actor_tags{};
        actor_tags.Data = (SDK::FName*)API::FMalloc::get()->malloc(1 * sizeof(SDK::FName));
        actor_tags.NumElements = 1;
        actor_tags.MaxElements = 1;
        actor_tags.Data[0] = SDK::UKismetStringLibrary::Conv_StringToName(actor_tag.c_str());

        actor->Tags = actor_tags;

        API::get()->log_warn("[plugin_utils][spawn_actor] Spawned actor %ls", actor_tag.c_str());
        return actor;
    }
    catch (...) {
        API::get()->log_error("[plugin_utils][spawn_actor] Exception");
        return nullptr;
    }
}

// this function tries to find and destroy actors we created for attachments, even when we no longer have pointers to them
void PluginUtils::destroy_actors_by_tag(SDK::UWorld* world, std::wstring actor_tag) {
    try {
        API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Cleaning up stale Actors");

        if (world == nullptr || !SDK::UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Invalid World object");
            return;
        }

        SDK::TArray<SDK::AActor*> actors_to_destroy{};
        actors_to_destroy.Data = (SDK::AActor**)API::FMalloc::get()->malloc(16 * sizeof(SDK::AActor*));
        actors_to_destroy.NumElements = 0;
        actors_to_destroy.MaxElements = 16;

        SDK::UGameplayStatics::GetAllActorsOfClassWithTag(world, SDK::AActor::StaticClass(), SDK::UKismetStringLibrary::Conv_StringToName(actor_tag.c_str()), &actors_to_destroy);

        API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Found %d Actors to Destroy", actors_to_destroy.Num());

        // destroying actors
        for (size_t i = 0; i < actors_to_destroy.Num(); i++) {
            if (actors_to_destroy[i] != nullptr && SDK::UKismetSystemLibrary::IsValid(actors_to_destroy[i]) && actors_to_destroy[i]->IsA(SDK::AActor::StaticClass())) {
                static_cast<SDK::AActor*>(actors_to_destroy[i])->K2_DestroyActor();
                API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Destroyed Actor %ls", actor_tag.c_str());
            }
        }

        return;
    }
    catch (...) {
        API::get()->log_error("[plugin_utils][destroy_actors_by_tag] Exception");
        return;
    }
}

SDK::UObject* PluginUtils::load_asset(SDK::FAssetData asset_data) {
    try {
        API::get()->log_warn("[plugin_utils][load_asset] Loading Asset %s", asset_data.ObjectPath.GetRawString().c_str());
        SDK::FSoftObjectPath path = SDK::UAssetRegistryHelpers::ToSoftObjectPath(asset_data);
        auto obj_ref = SDK::UKismetSystemLibrary::Conv_SoftObjPathToSoftObjRef(path);
        SDK::UObject* asset = SDK::UKismetSystemLibrary::LoadAsset_Blocking(obj_ref);
        API::get()->log_warn("[plugin_utils][load_asset] Successfully Loaded Asset");
        return asset;
    }
    catch (...) {
        API::get()->log_error("[plugin_utils][load_asset] Exception");
        return nullptr;
    }
}
