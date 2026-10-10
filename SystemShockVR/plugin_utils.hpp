#pragma once
#include <string>
#include <vector>

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "BridgeSDK/Bridge.hpp"

class PluginUtils
{
    inline static int32_t m_native_fix_tick_counter{ -1 };
    inline static uint32_t m_class_check_generation{ 1 };

    static void log_bridge_classes_loaded_since(const std::vector<std::wstring>& skipped_before);

public:
    // object->IsA(T::StaticClass()) for a game Blueprint class T, with the answer remembered for
    // the object's class. While T is not loaded, T::StaticClass() searches the whole object array
    // on every call and costs milliseconds; at the title screen most gameplay classes are not
    // loaded. An object's class never changes, and an object cannot be of a class that is not
    // loaded, so the answer for one class of object stays right until classes unload.
    template <class T>
    static bool is_a(const SDK::UObject* object) {
        static const SDK::UClass* last_class{ nullptr };
        static bool last_result{ false };
        static uint32_t last_generation{ 0 };
        if (object == nullptr) return false;
        if (object->Class == last_class && last_generation == m_class_check_generation) return last_result;
        SDK::UClass* type = T::StaticClass();
        last_result = type != nullptr && object->IsA(type);
        last_class = object->Class;
        last_generation = m_class_check_generation;
        return last_result;
    }
    // Drops every answer is_a() remembers. Called on level change: classes unload then, and a
    // new class can take the memory of an old one.
    static void reset_class_checks() { ++m_class_check_generation; }
    static void reset_height(float offset_y);
    static SDK::AActor* spawn_actor(SDK::UWorld* world, SDK::FTransform transform, std::wstring actor_tag);
    static void destroy_actors_by_tag(SDK::UWorld* world, SDK::FName actor_tag);
    static void destroy_actors_by_class(SDK::UWorld* world, SDK::UClass* actor_class);
    static void show_all_primitive_components(SDK::UWorld* world, SDK::USceneComponent* origin, float range, bool include_pawn = false);
    static SDK::UPanelSlot* reparent_panel_to_user_widget(SDK::UPanelWidget* panel, SDK::UUserWidget* user_widget);

    // Detaches every game widget that reparent_panel_to_user_widget moved into one of the
    // mod's live user widgets. The game's HUD outlives a level and keeps referencing those
    // panels, so without this the mod's widgets, their classes and every asset they use
    // stay in memory for the rest of the session. Call at a level change.
    static void release_game_panels_from_mod_widgets();
    static int32_t hook_vtable_fn(std::wstring_view class_name, std::wstring_view fn_name, void* destination, void** original);

    // this is the new way that uses AssetRegistry and UKismetSystemLibrary
    static SDK::UObject* load_asset(SDK::FAssetData asset_data);

    // Loads a Blueprint class by its soft class path, for example
    // L"/Game/Mods/VRBody/_BP_VRBody._BP_VRBody_C", through the pak file index. Blocks
    // the game thread until the class and everything it imports are in memory.
    // Returns nullptr when the path does not resolve.
    static SDK::UClass* load_class(const wchar_t* soft_class_path);

    // load_class for a class the BridgeSDK also caches. After the load it compares the
    // loaded class with the bridge cache for the same class and drops every bridge cache
    // when they differ, so a stale pointer from before a reload is never used. Spawn from
    // the returned class, not from the bridge lookup.
    static SDK::UClass* load_class_for_bridge(const wchar_t* soft_class_path, bridge::ClassRef& bridge_ref);
    static float bytes_to_float(std::string name, uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3);
    static void print_niagara_parameter_float(std::string name, uint8_t offset, SDK::TArray<uint8_t> data);
    static float get_niagara_parameter_float(std::string name, uint8_t offset, SDK::TArray<uint8_t> data);
    static float uevr_param_to_float(const UEVR_VRData* vr, const char* key);
    static void handle_native_stereo_fix_cycler(const UEVR_VRData* vr);
    static void cycle_native_stereo_fix();
    // Resolves every BridgeSDK class, property and function up front (see BridgeSDK.hpp).
    static void warmup_bridge();
    static void list_overlapping_components(const class SDK::UObject* world_context_object, const struct SDK::FVector& sphere_pos, float sphere_radius);

    PluginUtils() = delete;
};
