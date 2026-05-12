#pragma once
#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"

#define STATIC_LOAD_ASSET_OFFSET 0x1C67740

typedef SDK::UObject* (*StaticLoadObject_t)(uevr::API::UClass* ObjectClass, uevr::API::UObject* InOuter, const wchar_t* inName, const wchar_t* Filename, int32_t LoadFlags, class UPackageMap* Sandbox, bool bAllowObjectReconciliation, const struct FLinkerInstancingContext* InstancingContext);

class PluginUtils
{
    inline static int32_t m_native_fix_tick_counter{ -1 };

public:
    static void reset_height(float offset_y);
    static SDK::AActor* spawn_actor(SDK::UWorld* world, SDK::FTransform transform, std::wstring actor_tag);
    static void destroy_actors_by_tag(SDK::UWorld* world, SDK::FName actor_tag);
    static void destroy_actors_by_class(SDK::UWorld* world, SDK::UClass* actor_class);
    static int32_t hook_vtable_fn(std::wstring_view class_name, std::wstring_view fn_name, void* destination, void** original);

    // this is the new way that uses AssetRegistry and UKismetSystemLibrary
    static SDK::UObject* load_asset(SDK::FAssetData asset_data);
    static float bytes_to_float(std::string name, uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3);
    static void print_niagara_parameter_float(std::string name, uint8_t offset, SDK::TArray<uint8_t> data);
    static float get_niagara_parameter_float(std::string name, uint8_t offset, SDK::TArray<uint8_t> data);
    static float uevr_param_to_float(const UEVR_VRData* vr, const char* key);
    static void handle_native_stereo_fix_cycler(const UEVR_VRData* vr);
    static void cycle_native_stereo_fix();

    PluginUtils() = delete;
};
