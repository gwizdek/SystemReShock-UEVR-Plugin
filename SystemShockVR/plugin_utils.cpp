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
void PluginUtils::destroy_actors_by_tag(SDK::UWorld* world, SDK::FName actor_tag) {
    try {
        API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Cleaning up stale %s Actors", actor_tag.GetRawString().c_str());

        if (world == nullptr || !SDK::UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Invalid World object");
            return;
        }

        SDK::TArray<SDK::AActor*> actors_to_destroy{};
        actors_to_destroy.Data = (SDK::AActor**)API::FMalloc::get()->malloc(16 * sizeof(SDK::AActor*));
        actors_to_destroy.NumElements = 0;
        actors_to_destroy.MaxElements = 16;

        SDK::UGameplayStatics::GetAllActorsOfClassWithTag(world, SDK::AActor::StaticClass(), actor_tag, &actors_to_destroy);

        API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Found %d Actors to Destroy", actors_to_destroy.Num());

        // destroying actors
        for (size_t i = 0; i < actors_to_destroy.Num(); i++) {
            if (actors_to_destroy[i] != nullptr && SDK::UKismetSystemLibrary::IsValid(actors_to_destroy[i]) && actors_to_destroy[i]->IsA(SDK::AActor::StaticClass())) {
                static_cast<SDK::AActor*>(actors_to_destroy[i])->K2_DestroyActor();
                API::get()->log_warn("[plugin_utils][destroy_actors_by_tag] Destroyed Actor %s", actor_tag.GetRawString().c_str());
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


//Find vtable real function and hook it
int32_t PluginUtils::hook_vtable_fn(std::wstring_view class_name, std::wstring_view fn_name, void* destination, void** original) {
    //auto obj = (API::UClass*)API::get()->find_uobject(class_name);

    //if (obj == nullptr) {
    //    PLUGIN_LOG_ONCE_ERROR("Failed to find %ls", class_name.data());
    //    return -1;
    //}

    //auto fn = obj->find_function(fn_name);

    //if (fn == nullptr) {
    //    PLUGIN_LOG_ONCE_ERROR("Failed to find %ls", fn_name.data());
    //    return -1;
    //}

    //auto native = fn->get_native_function();

    //if (native == nullptr) {
    //    PLUGIN_LOG_ONCE_ERROR("Failed to get native function");
    //    return -1;
    //}

    //PLUGIN_LOG_ONCE("%ls native: 0x%p", fn_name.data(), native);

    //auto default_object = obj->get_class_default_object();

    //if (default_object == nullptr) {
    //    PLUGIN_LOG_ONCE_ERROR("Failed to get default object");
    //    return -1;
    //}

    //auto insn = utility::scan_disasm((uintptr_t)native, 0x1000, "FF 90 ? ? ? ?");

    //if (!insn) {
    //    PLUGIN_LOG_ONCE_ERROR("Failed to find the instruction");
    //    return -1;
    //}

    //auto offset = *(int32_t*)(*insn + 2);

    //auto vtable = *(uintptr_t**)default_object;
    //auto real_fn = vtable[offset / sizeof(void*)];

    //PLUGIN_LOG_ONCE("Real %ls: 0x%p (index: %d, offset 0x%X)", fn_name.data(), real_fn, offset / sizeof(void*), offset);

    //return API::get()->param()->functions->register_inline_hook((void*)real_fn, (void*)destination, original);
    
    // remove me
    return 0;
}

float PluginUtils::bytes_to_float(std::string name, uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3)
{
    uint8_t bytes[4] = { b0, b1, b2, b3 };
    static_assert(sizeof(float) == 4, "float size is expected to be 4 bytes");
    float f;
    memcpy(&f, bytes, 4);
    return f;
}

void PluginUtils::print_niagara_parameter_float(std::string name, uint8_t offset, SDK::TArray<uint8_t> data) {
    float value = bytes_to_float(name, data[offset], data[offset + 1], data[offset + 2], data[offset + 3]);
    API::get()->log_warn("[plugin_utils][bytes_to_float] Name: %s | Value %f", name.c_str(), value);
}

float PluginUtils::get_niagara_parameter_float(std::string name, uint8_t offset, SDK::TArray<uint8_t> data) {
    return bytes_to_float(name, data[offset], data[offset + 1], data[offset + 2], data[offset + 3]);
}
