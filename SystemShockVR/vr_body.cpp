#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "SDK/ITEM_ProjectileWeapon_Base_classes.hpp"

#include "vr_body.hpp"
#include "plugin_utils.hpp"

using namespace uevr;

VRBody::VRBody(SystemShockMain* main) {
    m_main = main;
}

bool VRBody::is_valid() {
    if (
        m_main != nullptr
        ) {
        return true;
    }
    return false;
}

void VRBody::cleanup_actors() {
    try {
        auto world = SDK::UWorld::GetWorld();
        if (!SDK::UKismetSystemLibrary::IsValid(world)) {
            API::get()->log_error("[vrbody][cleanup_actors] World invalid");
            return;
        }

        PluginUtils::destroy_actors_by_tag(world, L"VRBodyActor");
    }
    catch (...) {
        API::get()->log_error("[vrbody][cleanup_actors] Exception");
    }
}

void VRBody::initialize() {
    try {
        auto world = SDK::UWorld::GetWorld();
        SDK::APawn* pawn = world != nullptr ? SDK::UGameplayStatics::GetPlayerPawn(world, 0) : nullptr;
        if (pawn == nullptr) {
            API::get()->log_error("[vrbody][initialize] Invalid Pawn");
            return;
        }
        API::get()->log_warn("[vrbody][initialize] Loading Asset");

        //SDK::FAssetData vr_asset_data{
        //    .ObjectPath = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Mods/VRBody/VRBody.VRBody_C"),
        //    .PackageName = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Mods/VRBody/VRBody"),
        //    .PackagePath = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Mods/VRBody"),
        //    .AssetName = SDK::UKismetStringLibrary::Conv_StringToName(L"VRBody"),
        //    .AssetClass = SDK::UKismetStringLibrary::Conv_StringToName(L""),
        //};

        SDK::FAssetData vr_asset_data{
            .ObjectPath = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Mods/VRBody/BP_SSRModActor.BP_SSRModActor_C"),
            .PackageName = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Mods/VRBody/BP_SSRModActor"),
            .PackagePath = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Mods/BP_SSRModActor"),
            .AssetName = SDK::UKismetStringLibrary::Conv_StringToName(L"BP_SSRModActor"),
            .AssetClass = SDK::UKismetStringLibrary::Conv_StringToName(L""),
        };

        // keep the pointer until vr weapon init is done
        SDK::UObject* loaded_asset = PluginUtils::load_asset(vr_asset_data);
        if (loaded_asset != nullptr) {
            API::get()->log_warn("[vrbody][initialize] Loaded Asset");

            const SDK::FVector pawn_location = pawn->K2_GetActorLocation();
            SDK::FTransform pawn_transform{};
            pawn_transform.Rotation = { 0.f, 0.f, 0.f, 1.f };
            pawn_transform.Translation = { pawn_location.X, pawn_location.Y, pawn_location.Z };
            pawn_transform.Scale3D = { 1.f, 1.f, 1.f };

            try {
                m_bp_actor = (SDK::ABP_VRBody_C*)SDK::UGameplayStatics::BeginDeferredActorSpawnFromClass(
                    world, SDK::ABP_VRBody_C::StaticClass(), pawn_transform, SDK::ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr
                );
                if (m_bp_actor == nullptr) {
                    API::get()->log_error("[vrbody][initialize] Error spawning VRBody BP Actor");
                    return;
                }

                SDK::UGameplayStatics::FinishSpawningActor(m_bp_actor, pawn_transform);
                API::get()->log_warn("[vrbody][initialize] Finishied spawning VRBody BP Actor");

                SDK::TArray<SDK::FName> actor_tags{};
                actor_tags.Data = (SDK::FName*)API::FMalloc::get()->malloc(1 * sizeof(SDK::FName));
                actor_tags.NumElements = 1;
                actor_tags.MaxElements = 1;
                actor_tags.Data[0] = SDK::UKismetStringLibrary::Conv_StringToName(L"VRBodyActor");

                m_bp_actor->Tags = actor_tags;
                API::get()->log_warn("[vrbody][initialize] Added VRBodyActor Tag");

                m_bp_actor->K2_AttachRootComponentTo(
                    pawn->K2_GetRootComponent(),
                    SDK::UKismetStringLibrary::Conv_StringToName(L"None"),
                    SDK::EAttachLocation::SnapToTarget,
                    true
                );
            }
            catch (...) {
                API::get()->log_error("[vrbody][initialize] Error spawning ABP_SSRModActor_C");
            }
        }
        else {
            API::get()->log_warn("[vrbody][initialize] Failed to Load Asset");
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][initialize] Exception");
    }
}

void VRBody::cleanup_pointers() {
    API::get()->log_warn("[vrbody][cleanup_pointers] Cleanup");

}

void VRBody::on_tick() {
    try {
        if (!is_valid()) {
            return;
        }

    }
    catch (...) {
        API::get()->log_error("[vrbody][tick] Exception");
    }
}



void VRBody::on_draw_imgui() {
    try {
        if (is_valid()) {
            ImGui::SeparatorText("VR Body");
            // game state section

            ImGui::BeginGroup();
            ImGui::BeginDisabled();

            ImGui::EndDisabled();
            ImGui::EndGroup();
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][on_draw_imgui] Exception");
    }
}
