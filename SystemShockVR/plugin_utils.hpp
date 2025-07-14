#pragma once
#include "uevr/API.hpp"
#include "SDK/Basic.hpp"
#include "SDK/Engine_classes.hpp"

class PluginUtils
{
private:

public:
    PluginUtils() = default;
    virtual ~PluginUtils() {};

    static void reset_height(float offset_y);
    static SDK::AActor* spawn_actor(SDK::UWorld* world, SDK::FTransform transform, std::wstring actor_tag);
    //static SDK::AActor* spawn_actor(SDK::UWorld* world, TSubclassOf<class AActor> ActorClass, SDK::FTransform transform, std::wstring actor_tag);
    static void destroy_actors_by_tag(SDK::UWorld* world, std::wstring actor_tag);
    static SDK::UObject* load_asset(SDK::FAssetData asset_data);
};
