#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/PICKUP_Base_classes.hpp"
#include "SDK/GrabComponent_classes.hpp"
#include "SDK/ITEM_ProjectileWeapon_Base_classes.hpp"

#include "SDK/WEAPON_LaserRapier_classes.hpp"
#include "SDK/WEAPON_MiniPistol_classes.hpp"
#include "SDK/WEAPON_AssaultRifle_classes.hpp"

#include "SDK/ANIMBP_MiniPistol_classes.hpp"

#include "vr_body.hpp"
#include "vr_weapon.hpp"
#include "plugin_utils.hpp"

using namespace uevr;

VRBody::VRBody(SystemShockMain* main) {
    m_main = main;
    m_vr_weapon = new VRWeapon(this);
}

bool VRBody::is_valid() {
    return m_main != nullptr && m_bp_actor != nullptr && m_vr_weapon != nullptr;
}

void VRBody::on_tick() {
    try {
        if (!is_valid()) {
            return;
        }

        if (m_main->get_pawn() == nullptr || !m_main->get_pawn()->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass())) {
            return;
        }

        SDK::APAWN_Hacker_Implant_C* hacker_implant_pawn = static_cast<SDK::APAWN_Hacker_Implant_C*>(m_main->get_pawn());


        if (hacker_implant_pawn->WeaponMesh != m_vr_weapon->get_equipped_weapon_mesh_component()) {
            API::get()->log_warn("[vr_body][on_tick] Detected Weapon Mesh Change");
            m_vr_weapon->set_equipped_weapon_mesh_component(hacker_implant_pawn->WeaponMesh);

            if (hacker_implant_pawn->WeaponMesh != nullptr) {
                // new weapon / consumable / grenade
                auto inventory = m_main->get_inventory();
                if (inventory != nullptr) {
                    if (m_vr_weapon->get_equipped_weapon() != inventory->CurrentEquippedWeapon) {
                        m_vr_weapon->change_equipped_weapon(inventory->CurrentEquippedWeapon);
                    }

                    // pass mesh to the BP
                    m_bp_actor->CurrentWeapon = hacker_implant_pawn->WeaponMesh;

                    // change hand pose
                    if (inventory->CurrentEquippedWeapon->IsA(SDK::UWEAPON_LaserRapier_C::StaticClass())) {
                        API::get()->log_warn("[vr_body][on_tick] Equipping LaserRapier");
                        m_bp_actor->EquipLaserRapier();
                    }
                    else if (inventory->CurrentEquippedWeapon->IsA(SDK::UWEAPON_MiniPistol_C::StaticClass())) {
                        API::get()->log_warn("[vr_body][on_tick] Equipping MiniPistol");
                        m_bp_actor->EquipMinipistol();
                        auto anim_inst = m_bp_actor->CurrentWeapon->GetAnimInstance();
                        if (anim_inst != nullptr && anim_inst->IsA(SDK::UANIMBP_MiniPistol_C::StaticClass())) {
                            API::get()->log_warn("[vr_body][on_tick] Changing MiniPistol Anim params");
                            //static_cast<SDK::UANIMBP_MiniPistol_C*>(anim_inst)->Source_Mesh_Component = hacker_implant_pawn->Mesh;
                            //static_cast<SDK::UANIMBP_MiniPistol_C*>(anim_inst)->UsePoseFromExternalMesh = true;
                        }
                    }
                    else if (inventory->CurrentEquippedWeapon->IsA(SDK::UWEAPON_AssaultRifle_C::StaticClass())) {
                        API::get()->log_warn("[vr_body][on_tick] Equipping AssaultRifle");
                        m_bp_actor->EquipAssaultRifle();
                    }
                    else {
                        API::get()->log_warn("[vr_body][on_tick] Equipping Other");
                        static_cast<SDK::APAWN_Hacker_Implant_C*>(m_main->get_pawn())->WeaponMesh->K2_AttachToComponent(
                            m_bp_actor->VRBodyMesh,
                            SDK::UKismetStringLibrary::Conv_StringToName(L"RightHandGunSocket"),
                            SDK::EAttachmentRule::SnapToTarget,
                            SDK::EAttachmentRule::KeepRelative,
                            SDK::EAttachmentRule::KeepRelative,
                            false
                        );
                        m_bp_actor->Set_Hand_Pose(SDK::E_VRHandState::NewEnumerator5, true);
                    }
                }
                else {
                    API::get()->log_error("[vr_body][on_tick] WeaponMesh not null but Inventory is null");
                }

                //hacker_implant_pawn->WeaponMesh->DetachFromParent(true, true);
                m_vr_weapon->attach_camera(hacker_implant_pawn->PlayerCamera);
                m_vr_weapon->attach_laser();

                API::get()->log_warn("[vr_body][on_tick] New Weapon Mesh: %s", hacker_implant_pawn->WeaponMesh->SkeletalMesh->GetFullName().c_str());
            }
            else {
                // nothing in hand
                m_vr_weapon->change_equipped_weapon(nullptr);

                // hand pose
                //m_bp_actor->UnequipWeapon();
            }
        }



        // tick weapon
        m_vr_weapon->on_tick();

        //log_overlapping_objects();
    }
    catch (...) {
        API::get()->log_error("[vrbody][on_tick] Exception");
    }
}

SDK::UMotionControllerComponent* VRBody::get_right_controller()
{
    return m_bp_actor != nullptr ? m_bp_actor->MotionControllerRight : nullptr;
}

SDK::UMotionControllerComponent* VRBody::get_left_controller()
{
    return m_bp_actor != nullptr ? m_bp_actor->MotionControllerLeft : nullptr;
}

// disables / enables collisions on close to body meshes to prevent unwanted collisions with the widget interation component trace
void VRBody::set_player_response_to_collision_channel(SDK::ECollisionChannel channel, SDK::ECollisionResponse response) {
    try {
        if (m_main == nullptr) {
            return;
        }
        auto pawn = static_cast<SDK::APAWN_Hacker_Implant_C*>(m_main->get_pawn());
        if (pawn != nullptr) {
            pawn->CapsuleComponent->SetCollisionResponseToChannel(channel, response);
            pawn->Mesh->SetCollisionResponseToChannel(channel, response);
            pawn->ArmsMesh->SetCollisionResponseToChannel(channel, response);
            pawn->WeaponMesh->SetCollisionResponseToChannel(channel, response);
            API::get()->log_warn("[vrbody][set_player_response_to_collision_channel] Hacker collision changed");
        }

        if (m_bp_actor != nullptr) {
            API::get()->log_warn("[vrbody][set_player_response_to_collision_channel] VRBody collision changed");
            m_bp_actor->VRBodyMesh->SetCollisionResponseToChannel(channel, response);
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][set_player_response_to_collision_channel] Exception");
    }
}

void VRBody::set_player_response_to_all_collision_channels(SDK::ECollisionResponse response) {
    try {
        if (m_main == nullptr) {
            return;
        }
        auto pawn = static_cast<SDK::APAWN_Hacker_Implant_C*>(m_main->get_pawn());
        if (pawn != nullptr) {
            pawn->CapsuleComponent->SetCollisionResponseToAllChannels(response);
            pawn->Mesh->SetCollisionResponseToAllChannels(response);
            pawn->ArmsMesh->SetCollisionResponseToAllChannels(response);
            pawn->WeaponMesh->SetCollisionResponseToAllChannels(response);
            API::get()->log_warn("[vrbody][set_player_response_to_collision_channel] Hacker collision changed");
        }

        if (m_bp_actor != nullptr) {
            API::get()->log_warn("[vrbody][set_player_response_to_collision_channel] VRBody collision changed");
            m_bp_actor->VRBodyMesh->SetCollisionResponseToAllChannels(response);
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][set_player_response_to_collision_channel] Exception");
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

        SDK::FAssetData vr_grab_component{
            .ObjectPath = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/VRTemplate/Blueprints/GrabComponent.GrabComponent_C"),
            .PackageName = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/VRTemplate/Blueprints/GrabComponent"),
            .PackagePath = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/VRTemplate/GrabComponent"),
            .AssetName = SDK::UKismetStringLibrary::Conv_StringToName(L"GrabComponent"),
            .AssetClass = SDK::UKismetStringLibrary::Conv_StringToName(L""),
        };
        SDK::UObject* loaded_gc_asset = PluginUtils::load_asset(vr_grab_component);
        if (loaded_gc_asset != nullptr) {
            API::get()->log_warn("[vrbody][initialize] Loaded GrabComponent");
        }

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

                m_bp_actor->SetActorEnableCollision(false);

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

                API::get()->log_warn("[vrbody][initialize] Set GrabObjectTypes");
                SDK::TArray<SDK::EObjectTypeQuery> grab_object_types{};

                grab_object_types.Data = (SDK::EObjectTypeQuery*)API::FMalloc::get()->malloc(1 * sizeof(SDK::EObjectTypeQuery));
                grab_object_types.NumElements = 1;
                grab_object_types.MaxElements = 1;
                grab_object_types[0] = SDK::EObjectTypeQuery::ObjectTypeQuery17;


                m_bp_actor->GrabObjectTypes = grab_object_types;

                set_player_response_to_collision_channel(
                    SDK::ECollisionChannel::ECC_GameTraceChannel3,
                    SDK::ECollisionResponse::ECR_Ignore
                );


                if (pawn->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass())) {
                    API::get()->log_warn("[vrbody][initialize] Attach MediaReader");
                    static_cast<SDK::APAWN_Hacker_Implant_C*>(pawn)->MediaReaderMesh->K2_AttachToComponent(
                        m_bp_actor->VRBodyMesh,
                        SDK::UKismetStringLibrary::Conv_StringToName(L"LeftForeArmRoll1"),
                        SDK::EAttachmentRule::SnapToTarget,
                        SDK::EAttachmentRule::KeepRelative,
                        SDK::EAttachmentRule::KeepRelative,
                        true
                    );

                    SDK::FHitResult SweepHitResult{};

                    static_cast<SDK::APAWN_Hacker_Implant_C*>(pawn)->MediaReaderMesh->K2_SetRelativeLocationAndRotation(
                        { 7.f, 3.f, 0.5f }, { 0.f, 3.f, 77.f }, false, &SweepHitResult, false
                    );
                }

                attach_grab_components();
                m_vr_weapon->initialize();

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

void VRBody::attach_grab_components() {
    try {
        API::get()->log_warn("[vrbody][attach_grab_components] Searching for pickups");
        // Set what actors to seek out from it's collision channel
        SDK::TArray<SDK::EObjectTypeQuery> traceObjectTypes;
        SDK::TArray<SDK::EObjectTypeQuery> object_types{};
        API::get()->log_info("VRHackerHUD :: Adding type");
        object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery32);
        API::get()->log_info("VRHackerHUD :: Added type");
        //object_types.Add(SDK::UEngineTypes::ConvertToObjectType(SDK::ECollisionChannel::ECC_GameTraceChannel18));

        //SDK::UClass* component_class_filter{ SDK::APICKUP_Base_C::StaticClass() };
        SDK::UClass* component_class_filter{ SDK::UStaticMeshComponent::StaticClass() };
        const SDK::TArray<SDK::AActor*>& actors_to_ignore{};
        SDK::TArray<SDK::UPrimitiveComponent*> out_components{};
        auto world = SDK::UWorld::GetWorld();
        // get overlapping components
        const bool result = SDK::UKismetSystemLibrary::SphereOverlapComponents(
            world,
            m_bp_actor->VRBodyMesh->K2_GetComponentLocation(),
            500.f,
            object_types,
            component_class_filter,
            actors_to_ignore,
            &out_components
        );

        API::get()->log_warn("[vrbody][attach_grab_components] Overlapped obj no: %d", out_components.Num());

        if (result) {
            for (size_t i = 0; i < out_components.Num(); i++) {
                API::get()->log_warn("[vrbody][attach_grab_components] Overlapped obj: %s", out_components[i]->GetFullName().c_str());
                std::string obj_name = out_components[i]->GetFullName();
                if (obj_name.find(".PICKUP_") != std::wstring::npos) {
                    API::get()->log_warn("[vrbody][attach_grab_components] Pickup Found !!");
                    SDK::FTransform zero_transform{};
                    zero_transform.Rotation = { 0.f, 0.f, 0.f, 1.f };
                    zero_transform.Translation = { 0.f, 0.f, 0.f };
                    zero_transform.Scale3D = { 1.f, 1.f, 1.f };
                    SDK::AActor* pickup_actor = (SDK::AActor*)out_components[i]->Outer;
                    if (pickup_actor != nullptr && SDK::UKismetSystemLibrary::IsValid(pickup_actor)) {
                        // check if it already has a grab component
                        auto old_grab_component = pickup_actor->GetComponentByClass(SDK::UGrabComponent_C::StaticClass());
                        if (old_grab_component == nullptr) {
                            out_components[i]->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
                            out_components[i]->SetCollisionResponseToChannel(
                                SDK::ECollisionChannel::ECC_GameTraceChannel3,
                                SDK::ECollisionResponse::ECR_Block
                            );
                            auto component = static_cast<SDK::UGrabComponent_C*>(
                                pickup_actor->AddComponentByClass(
                                    SDK::UGrabComponent_C::StaticClass(), false, zero_transform, false
                                )
                                );
                            component->K2_AttachToComponent(
                                out_components[i],
                                SDK::UKismetStringLibrary::Conv_StringToName(L"None"),
                                SDK::EAttachmentRule::SnapToTarget,
                                SDK::EAttachmentRule::KeepRelative,
                                SDK::EAttachmentRule::KeepRelative,
                                true
                            );
                            component->SetRelativeScale3D({ 4.f, 4.f, 4.f });
                            component->GrabType = 1;
                            API::get()->log_warn("[vrbody][attach_grab_components] GrabComponent attached !!");
                        }
                        else {
                            API::get()->log_warn("[vrbody][attach_grab_components] Already has a GrabComponent");
                        }

                    }
                }

                //if (SDK::UKismetMathLibrary::ClassIsChildOf(out_components[i]->clasClass, SDK::APICKUP_Base_C::StaticClass())) {
                //}
            }
        }
        else {
            API::get()->log_warn("VRHackerHUD :: Wrong overlap result");
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][attach_grab_components] Exception");
    }
}

void VRBody::log_overlapping_objects()
{
    try {
        API::get()->log_warn("[vrbody][log_overlapping_objects] Searching GrabComponents");
        SDK::TArray<SDK::EObjectTypeQuery> object_types{};

        object_types.Data = (SDK::EObjectTypeQuery*)API::FMalloc::get()->malloc(1 * sizeof(SDK::EObjectTypeQuery));
        object_types.NumElements = 1;
        object_types.MaxElements = 1;
        object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery17);
        /*object_types.Data[0] = SDK::UKismetStringLibrary::Conv_StringToName(actor_tag.c_str());*/

        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery1);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery2);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery3);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery4);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery5);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery6);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery7);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery8);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery9);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery10);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery11);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery12);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery13);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery14);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery15);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery16);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery17);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery18);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery19);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery20);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery21);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery22);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery23);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery24);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery25);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery26);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery27);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery28);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery29);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery30);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery31);
        //object_types.Add(SDK::EObjectTypeQuery::ObjectTypeQuery32);
        //object_types.Add(SDK::UEngineTypes::ConvertToObjectType(SDK::ECollisionChannel::ECC_GameTraceChannel18));

        //SDK::UClass* component_class_filter{ SDK::APICKUP_Base_C::StaticClass() };
        //SDK::UClass* component_class_filter{ SDK::UGrabComponent_C::StaticClass() };
        SDK::UClass* component_class_filter{ SDK::UStaticMeshComponent::StaticClass() };
        const SDK::TArray<SDK::AActor*>& actors_to_ignore{};

        SDK::TArray<SDK::UPrimitiveComponent*> out_components{};
        auto world = SDK::UWorld::GetWorld();
        // get overlapping components
        auto locat = m_bp_actor->MotionControllerLeft->K2_GetComponentLocation();
        auto locat_start = SDK::UKismetMathLibrary::Add_VectorVector(locat, SDK::FVector{ 0.f, 0.f, 0.f });
        auto locat_end = SDK::UKismetMathLibrary::Add_VectorVector(locat_start, SDK::FVector{ 0.f, 0.f, 0.1f });
        API::get()->log_warn("[vrbody][log_overlapping_objects] From: X: %f, Y: %f, Z: %f", locat_start.X, locat_start.Y, locat_start.Z);
        API::get()->log_warn("[vrbody][log_overlapping_objects] To: X: %f, Y: %f, Z: %f", locat_end.X, locat_end.Y, locat_end.Z);

        //const bool result = SDK::UKismetSystemLibrary::SphereOverlapComponents(
        //    world,
        //    locat_start,
        //    100.f,
        //    object_types,
        //    component_class_filter,
        //    actors_to_ignore,
        //    &out_components
        //);

        //if (out_components.Num() > 0) {
        //    for (size_t i = 0; i < out_components.Num(); i++) {
        //        out_components[i]->r
        //    }
        //        API::get()->log_warn("[vrbody][attach_grab_components] Overlapped obj: %s", out_components[i]->GetFullName().c_str());
        //        std::string obj_name = out_components[i]->GetFullName();
        //    API::get()->log_warn("[vrbody][log_overlapping_objects] HIT GrabComponent");
        //}

        bool hit = SDK::UKismetSystemLibrary::SphereTraceSingleForObjects(
            world,
            locat_start,
            locat_end,
            40.f,
            object_types,
            false,
            actors_to_ignore,
            SDK::EDrawDebugTrace::None,
            &m_hit_result,
            true,
            { 255.f, 0.f, 0.f, 1.0f },
            { 255.f, 0.f, 0.f, 1.0f },
            10.0f
        );

        if (hit) {
            API::get()->log_warn("[vrbody][log_overlapping_objects] HIT %s", m_hit_result.Actor->GetFullName().c_str());
        }


        //for (SDK::uint8 i = 0; i < 32; i++) {
        //    API::get()->log_warn("[vrbody][log_overlapping_objects] TRY TYPE: %d", i);
        //    SDK::TArray<SDK::EObjectTypeQuery> object_types{};
        //    object_types.Add((SDK::EObjectTypeQuery)i);

        //    bool hit = SDK::UKismetSystemLibrary::SphereTraceSingleForObjects(
        //        world,
        //        locat_start,
        //        locat_end,
        //        500.f,
        //        object_types,
        //        false,
        //        actors_to_ignore,
        //        SDK::EDrawDebugTrace::None,
        //        &m_hit_result,
        //        true,
        //        { 255.f, 0.f, 0.f, 1.0f },
        //        { 255.f, 0.f, 0.f, 1.0f },
        //        10.0f
        //    );

        //    if (hit) {
        //        API::get()->log_warn("[vrbody][log_overlapping_objects] HIT TYPE: %d", i);
        //    }
        //}
        //if (m_hit_result.Actor != nullptr) {
        //    auto grab_component = m_hit_result.Actor->GetComponentByClass(SDK::UGrabComponent_C::StaticClass());
        //    if (grab_component != nullptr) {
        //        API::get()->log_warn("[vrbody][log_overlapping_objects] HIT GrabComponent");
        //    }
        //}


        //TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypesArray;
        //ObjectTypesArray.Reserve(1);
        //ObjectTypesArray.Emplace(ECollisionChannel::ECC_GameTraceChannel1);
    }
    catch (...) {
        API::get()->log_error("[vrbody][log_overlapping_objects] Exception");
    }
}

void VRBody::cleanup_pointers() {
    API::get()->log_warn("[vrbody][cleanup_pointers] Cleanup");

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

void VRBody::on_draw_imgui() {
    try {
        if (is_valid()) {
            ImGui::SeparatorText("VR Body");
            // game state section

            ImGui::BeginGroup();
            ImGui::BeginDisabled();

            ImGui::EndDisabled();
            ImGui::EndGroup();

            if (m_vr_weapon->is_valid()) {
                m_vr_weapon->on_draw_imgui();
            }
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][on_draw_imgui] Exception");
    }
}
