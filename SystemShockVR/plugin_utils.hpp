#pragma once
#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"

#define STATIC_LOAD_ASSET_OFFSET 0x1C67740

typedef SDK::UObject* (*StaticLoadObject_t)(uevr::API::UClass* ObjectClass, uevr::API::UObject* InOuter, const wchar_t* inName, const wchar_t* Filename, int32_t LoadFlags, struct UPackageMap* Sandbox, bool bAllowObjectReconciliation, const struct FLinkerInstancingContext* InstancingContext);

class PluginUtils
{
private:

public:
    PluginUtils() = default;
    virtual ~PluginUtils() {};

    static void reset_height(float offset_y);
    static SDK::AActor* spawn_actor(SDK::UWorld* world, SDK::FTransform transform, std::wstring actor_tag);
    static void destroy_actors_by_tag(SDK::UWorld* world, SDK::FName actor_tag);
    static int32_t hook_vtable_fn(std::wstring_view class_name, std::wstring_view fn_name, void* destination, void** original);

    // this is the new way that uses AssetRegistry and UKismetSystemLibrary
    static SDK::UObject* load_asset(SDK::FAssetData asset_data);
};
