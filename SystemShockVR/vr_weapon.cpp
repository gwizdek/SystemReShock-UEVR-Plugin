#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "SDK/ITEM_ProjectileWeapon_Base_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/ANIMBP_Magnum_classes.hpp"
#include "SDK/ANIMBP_Sparqbeam_classes.hpp"
#include "SDK/WEAPON_MagnumPistol_classes.hpp"

#include "vr_weapon.hpp"
#include "vr_body.hpp"
#include "plugin_utils.hpp"

using namespace uevr;

VRWeapon::VRWeapon(VRBody* vr_body) {
    m_vr_body = vr_body;
}

bool VRWeapon::is_valid() {
    if (
        m_vr_body != nullptr &&
        m_laser_sight_component != nullptr
        ) {
        return true;
    }
    return false;
}

void VRWeapon::initialize() {
    try {
        spawn_laser_pointer();
    }
    catch (...) {
        API::get()->log_error("[vr_weapon][initialize] Exception");
    }
}

//void VRWeapon::set_weapon_state() {
//    try {
//        if (!is_valid()) {
//            return;
//        }
//
//        if (m_equipped_weapon != nullptr) {
//            //if (m_main->get_is_player_interacting()->value) {
//            //    m_weapon_state.set_value(WEAPON_NONE);
//            //    return;
//            //}
//
//            std::string weapon_name = m_equipped_weapon->GetName();
//
//            for (auto const& [key, val] : weapons_map) {
//                if (weapon_name.find(get<0>(val)) != std::string::npos) {
//                    m_weapon_state.set_value(key);
//                    return;
//                }
//            }
//            m_weapon_state.set_value(WEAPON_NONE);
//        }
//        else {
//            m_weapon_state.set_value(WEAPON_NONE);
//        }
//    }
//    catch (...) {
//        API::get()->log_error("[main][set_weapon_state] Exception");
//    }
//}

void VRWeapon::cleanup_pointers() {
    API::get()->log_warn("[vr_weapon][cleanup_pointers] Cleanup");

    m_laser_dot_component = nullptr;
    m_laser_sight_component = nullptr;
    m_equipped_weapon = nullptr;
    m_weapon_type = WEAPON_TYPE_UNKNOWN;
}

void VRWeapon::on_tick() {
    try {
        if (!is_valid()) {
            return;
        }
    }
    catch (...) {
        API::get()->log_error("[vr_weapon][tick] Exception");
    }
}

void VRWeapon::set_weapon(SDK::UITEM_WeaponBase_C* equipped_weapon) {
    try {
        if (m_equipped_weapon != equipped_weapon) {
            if (equipped_weapon != nullptr) {
                if (equipped_weapon->WeaponMeshComponent == nullptr) {
                    m_weapon_state.set_value(WEAPON_NONE);
                }

                //if (m_player_interacting.value) {
                //    m_weapon_state.set_value(WEAPON_NONE);
                //    return;
                //}

                std::string weapon_name = equipped_weapon->GetName();

                for (auto const& [key, val] : weapons_map) {
                    if (weapon_name.find(get<0>(val)) != std::string::npos) {
                        m_weapon_state.set_value(key);
                        return;
                    }
                }
                m_weapon_state.set_value(WEAPON_NONE);
            }
            else {
                m_weapon_state.set_value(WEAPON_NONE);
            }

            m_equipped_weapon = equipped_weapon;
        }
    }
    catch (...) {
        API::get()->log_error("[main][set_weapon_state] Exception");
    }
}

void VRWeapon::attach_camera(SDK::UCameraComponent* camera) {
    try {
        if (camera == nullptr) {
            API::get()->log_warn("[vr_weapon][attach_camera] PlayerCamera nullptr");
            return;
        }

        camera->DetachFromParent(true, false);
        camera->Deactivate();
        API::get()->log_warn("[vr_weapon][attach_camera] PlayerCamera detached and deactivated");

        camera->K2_AttachToComponent(
            static_cast<SDK::UITEM_WeaponBase_C*>(m_equipped_weapon)->WeaponMeshComponent,
            static_cast<SDK::UITEM_WeaponBase_C*>(m_equipped_weapon)->BarrelSocketName,
            SDK::EAttachmentRule::SnapToTarget,
            SDK::EAttachmentRule::KeepRelative,
            SDK::EAttachmentRule::KeepRelative,
            true
        );
        API::get()->log_warn("[vr_weapon][attach_camera] PlayerCamera attached to Weapon");
    }
    catch (...) {
        API::get()->log_error("[vr_weapon][tick] Exception");
    }
}

void VRWeapon::attach_laser() {
    try {
        API::get()->log_warn("[vr_weapon][attach_laser] Setting up Laser Sight");
        if (m_laser_sight_component != nullptr) {
            m_laser_sight_component->K2_AttachToComponent(
                static_cast<SDK::UITEM_WeaponBase_C*>(m_equipped_weapon)->WeaponMeshComponent,
                static_cast<SDK::UITEM_WeaponBase_C*>(m_equipped_weapon)->BarrelSocketName,
                SDK::EAttachmentRule::SnapToTarget,
                SDK::EAttachmentRule::KeepRelative,
                SDK::EAttachmentRule::KeepRelative,
                true
            );
            API::get()->log_warn("[vr_weapon][attach_laser] Laser Sight attached to Weapon");
        }
    }
    catch (...) {
        API::get()->log_error("[vr_weapon][attach_laser] Exception");
    }
}

void VRWeapon::handle_weapon_change() {
    //if (m_laser_sight_component != nullptr) {
    //    API::get()->log_warn("[vr_weapon][handle_weapon_change] Setting up Laset Sight");
    //    m_laser_sight_component->DetachFromParent(true, true);
    //    m_laser_sight_component->K2_AttachToComponent(
    //        static_cast<SDK::APAWN_Hacker_Simple_C*>(pawn)->WeaponMesh,
    //        static_cast<SDK::UITEM_WeaponBase_C*>(m_equipped_weapon)->BarrelSocketName,
    //        SDK::EAttachmentRule::SnapToTarget,
    //        SDK::EAttachmentRule::KeepRelative,
    //        SDK::EAttachmentRule::KeepRelative,
    //        true
    //    );
    //    API::get()->log_warn("[vr_weapon][handle_weapon_change] Laset Sight attached to Weapon");
    //}

    //API::get()->log_warn("[vr_weapon][handle_weapon_change] Try SetAnimClass nullptr");
    //static_cast<SDK::APAWN_Hacker_Simple_C*>(pawn)->WeaponMesh->SetAnimClass(nullptr);
    //API::get()->log_warn("[vr_weapon][handle_weapon_change] Success SetAnimClass nullptr");

    //static_cast<SDK::APAWN_Hacker_Simple_C*>(pawn)->WeaponMesh->K2_AttachToComponent(
    //    vr_body->get_bp_actor()->VRBodyMesh,
    //    SDK::UKismetStringLibrary::Conv_StringToName(L"RightHandGunSocket"),
    //    SDK::EAttachmentRule::SnapToTarget,
    //    SDK::EAttachmentRule::KeepRelative,
    //    SDK::EAttachmentRule::KeepRelative,
    //    false
    //);

    //if (m_weapon_state.value == WEAPON_MAGNUM) {
    //if (m_equipped_weapon->IsA(SDK::UWEAPON_MagnumPistol_C::StaticClass())) {
    //    API::get()->log_warn("[vr_weapon][handle_weapon_change] Changing ABP for Magnum 1");
    //    //SDK::TWeakObjectPtr<SDK::USkeletalMeshComponent> mesh = static_cast<SDK::APAWN_Hacker_Simple_C*>(pawn)->ArmsMesh

    //    SDK::UAnimInstance* anim_inst = static_cast<SDK::APAWN_Hacker_Simple_C*>(pawn)->WeaponMesh->AnimScriptInstance;
    //    if (anim_inst->IsA(SDK::UANIMBP_Magnum_C::StaticClass())) {
    //        API::get()->log_warn("[vr_weapon][handle_weapon_change] Changing ABP for Magnum 2");
    //        static_cast<SDK::APAWN_Hacker_Simple_C*>(pawn)->WeaponMesh->SetAnimClass(SDK::UANIMBP_Magnum_C::StaticClass());
    //        //static_cast<SDK::APAWN_Hacker_Simple_C*>(pawn)->WeaponMesh->SetAnimClass(SDK::UANIMBP_Sparqbeam_C::StaticClass());


    //        API::get()->log_warn("[vr_weapon][handle_weapon_change] Changing ABP for Magnum 3");
    //        static_cast<SDK::UANIMBP_Magnum_C*>(anim_inst)->AnimGraphNode_CopyPoseFromMesh.bUseAttachedParent = 1;
    //        static_cast<SDK::UANIMBP_Magnum_C*>(anim_inst)->AnimGraphNode_CopyPoseFromMesh.RootBoneToCopy = SDK::UKismetStringLibrary::Conv_StringToName(L"PropRoot");
    //        //static_cast<SDK::UANIMBP_Magnum_C*>(anim_inst)->BlueprintInitializeAnimation();
    //        //static_cast<SDK::UANIMBP_Magnum_C*>(anim_inst)->BlueprintBeginPlay();
    //        API::get()->log_warn("[vr_weapon][handle_weapon_change] Changing ABP for Magnum End");
    //    }
    //}


    //API::get()->log_warn("[vr_weapon][handle_weapon_change] Weapon attached to VR Body");
    //vr_body->get_bp_actor()->Set_Hand_Pose(SDK::E_VRHandState::HoldItem, true);

    //m_main->get_vr_body()->get_bp_actor()->Set_Hand_Pose(SDK::E_VRHandState::HoldItem, true);
    //if (m_main->get_pawn()->IsA(SDK::APAWN_Hacker_Implant_C::StaticClass())) {
    //    static_cast<SDK::APAWN_Hacker_Implant_C*>(m_main->get_pawn())->WeaponMesh->DetachFromParent(true, true);
    //}
    //
    //m_equipped_weapon->WeaponMeshComponent->DetachFromParent(true, true);

}

void VRWeapon::change_equipped_weapon(SDK::UITEM_WeaponBase_C* weapon) {
    m_equipped_weapon = weapon;

    if (weapon == nullptr) {
        API::get()->log_warn("[vr_weapon][change_equipped_weapon] New Weapon: NONE");
    }
    else {
        API::get()->log_warn("[vr_weapon][change_equipped_weapon] New Weapon: %s", weapon->GetFullName().c_str());
    }
}

void VRWeapon::reload() {
    if (
        m_equipped_weapon != nullptr &&
        SDK::UKismetMathLibrary::ClassIsChildOf(m_equipped_weapon->Class, SDK::UITEM_ProjectileWeapon_Base_C::StaticClass())
        ) {
        API::get()->log_warn("[vr_weapon][reload] Reload");
        static_cast<SDK::UITEM_ProjectileWeapon_Base_C*>(m_equipped_weapon)->QueueReloading();
    }
}

void VRWeapon::empty_magazine() {
    if (
        m_equipped_weapon != nullptr &&
        SDK::UKismetMathLibrary::ClassIsChildOf(m_equipped_weapon->Class, SDK::UITEM_ProjectileWeapon_Base_C::StaticClass())
        ) {
        API::get()->log_warn("[vr_weapon][reload] Reload");
        static_cast<SDK::UITEM_ProjectileWeapon_Base_C*>(m_equipped_weapon)->TryEmptyMagazine();
    }
}


void VRWeapon::fire_weapon() {
    try {
        API::get()->log_warn("[vr_weapon][fire_weapon] Trying to Fire");
        if (
            m_equipped_weapon != nullptr &&
            SDK::UKismetMathLibrary::ClassIsChildOf(m_equipped_weapon->Class, SDK::UITEM_ProjectileWeapon_Base_C::StaticClass())
            //&& m_equipped_weapon->IsA(SDK::UITEM_ProjectileWeapon_Base_C::StaticClass())
            ) {
            API::get()->log_warn("[vr_weapon][fire_weapon] Fire");
            SDK::AActor* fired_projectile{ nullptr };
            SDK::FVector direction{};
            SDK::FVector projectile_direction{ };

            SDK::FVector barrel_location = static_cast<SDK::UITEM_ProjectileWeapon_Base_C*>(m_equipped_weapon)->WeaponMeshComponent->GetSocketLocation(
                static_cast<SDK::UITEM_ProjectileWeapon_Base_C*>(m_equipped_weapon)->BarrelSocketName
            );

            //SDK::FVector barrel_location_end = barrel_location;
            //barrel_location_end.Y += 100.0f;

            //auto start = static_cast<SDK::UITEM_ProjectileWeapon_Base_C*>(m_current_weapon)->WeaponMeshComponent->K2_GetComponentLocation();
            //auto rot = static_cast<SDK::UITEM_ProjectileWeapon_Base_C*>(m_current_weapon)->WeaponMeshComponent->K2_GetComponentRotation();
            //auto barrel_location_end = barrel_location + (SDK::UKismetMathLibrary::Conv_RotatorToVector(rot) * 100.f);
            auto forward_vector = static_cast<SDK::UITEM_ProjectileWeapon_Base_C*>(m_equipped_weapon)->WeaponMeshComponent->GetRightVector();
            forward_vector.X = -forward_vector.X;
            forward_vector.Y = -forward_vector.Y;
            forward_vector.Z = -forward_vector.Z;

            static_cast<SDK::UITEM_ProjectileWeapon_Base_C*>(m_equipped_weapon)->FireProjectileInDirection(
                barrel_location,
                forward_vector,
                &fired_projectile,
                &direction
            );

            //static_cast<SDK::UITEM_ProjectileWeapon_Base_C*>(m_current_weapon)->FireProjectile(&fired_projectile, &direction);

            API::get()->log_warn("[vr_weapon][fire_weapon] X: %f", direction.X);
            API::get()->log_warn("[vr_weapon][fire_weapon] Y: %f", direction.Y);
            API::get()->log_warn("[vr_weapon][fire_weapon] Z: %f", direction.Z);
        }
    }
    catch (...) {
        API::get()->log_error("[vr_weapon][fire_weapon] Exception");
    }
}

//void VRWeapon::set_weapon_type() {
//    try {
//        API::get()->log_warn("[vr_weapon][set_weapon_type] Weapon Type: %s", VRWeaponTypeName[m_weapon_type]);
//    }
//    catch (...) {
//        API::get()->log_error("[vr_weapon][set_weapon_type] Exception");
//    }
//}

void VRWeapon::set_laser_pointer_visibility(bool visible) {
    try {
        if (m_laser_dot_component != nullptr) {
            m_laser_dot_component->SetVisibility(visible, false);
        }
        if (m_laser_sight_component != nullptr) {
            m_laser_sight_component->SetVisibility(visible, false);
        }
    }
    catch (...) {
        API::get()->log_error("[vr_weapon][set_laser_pointer_visibility] Exception");
    }
}

void VRWeapon::spawn_laser_pointer() {

    try {
        API::get()->log_warn("[vr_weapon][spawn_laser_pointer] Spawning Particle Pointer - Begin");

        //if (!is_valid()) {
        //    API::get()->log_error("[vr_weapon][spawn_laser_pointer] VR Weapon not initialized");
        //    return;
        //}

        SDK::FAssetData simple_laser_asset_data{
            .ObjectPath = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Art/ParticleEffects/Niagara/Laser/NS_SimpleLaser.NS_SimpleLaser"),
            .PackageName = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Art/ParticleEffects/Niagara/Laser/NS_SimpleLaser"),
            .PackagePath = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Art/ParticleEffects/Niagara/Laser"),
            .AssetName = SDK::UKismetStringLibrary::Conv_StringToName(L"NS_SimpleLaser"),
            .AssetClass = SDK::UKismetStringLibrary::Conv_StringToName(L"NiagaraSystem"),
        };

        SDK::FAssetData laser_dot_asset_data{
            .ObjectPath = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Art/ParticleEffects/Niagara/Laser/NS_LaserDot.NS_LaserDot"),
            .PackageName = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Art/ParticleEffects/Niagara/Laser/NS_LaserDot"),
            .PackagePath = SDK::UKismetStringLibrary::Conv_StringToName(L"/Game/Art/ParticleEffects/Niagara/Laser"),
            .AssetName = SDK::UKismetStringLibrary::Conv_StringToName(L"NS_LaserDot"),
            .AssetClass = SDK::UKismetStringLibrary::Conv_StringToName(L"NiagaraSystem"),
        };

        SDK::UNiagaraSystem* simple_laser_ns = (SDK::UNiagaraSystem*)PluginUtils::load_asset(simple_laser_asset_data);
        SDK::UNiagaraSystem* laser_dot_ns = (SDK::UNiagaraSystem*)PluginUtils::load_asset(laser_dot_asset_data);

        if (simple_laser_ns == nullptr || laser_dot_ns == nullptr) {
            API::get()->log_error("[vr_weapon][spawn_simple_laser] SimpleLaser or LaserDot NiagaraSystem not found or RH controller not set up");
            return;
        }

        if (m_laser_sight_component != nullptr || m_laser_dot_component != nullptr) {
            API::get()->log_error("[vr_weapon][spawn_simple_laser] Laser Pointer Component already set up");
            return;
        }

        SDK::FTransform laser_sight_zero_transform{
            .Rotation = { 0.f, 0.f, 0.f, 1.f },
            .Translation = { 0.f, 0.f, 0.f },
            .Scale3D = { 1.f, 1.f, 1.f }
        };

        m_laser_sight_component = static_cast<SDK::UNiagaraComponent*>(
            m_vr_body->get_bp_actor()->AddComponentByClass(
                SDK::UNiagaraComponent::StaticClass(), false, laser_sight_zero_transform, false
            ));
        if (m_laser_sight_component == nullptr) {
            API::get()->log_error("Failed to add Laser Sight Component");
            return;
        }

        m_vr_body->get_bp_actor()->FinishAddComponent(m_laser_sight_component, false, laser_sight_zero_transform);

        m_laser_sight_component->SetAsset(simple_laser_ns, true);
        m_laser_sight_component->ReinitializeSystem();
        m_laser_sight_component->SetRenderInMainPass(true);

        API::get()->log_warn("[vr_weapon][spawn_laser_pointer] Setting up Laset Sight");
        m_laser_sight_component->K2_AttachToComponent(
            m_vr_body->get_right_controller(),
            SDK::UKismetStringLibrary::Conv_StringToName(L"None"),
            SDK::EAttachmentRule::SnapToTarget,
            SDK::EAttachmentRule::KeepRelative,
            SDK::EAttachmentRule::KeepRelative,
            true
        );
        API::get()->log_warn("[vr_weapon][spawn_laser_pointer] Laset Sight attached to RH Controller");

        //SDK::FTransform laser_dot_zero_transform{
        //    .Rotation = { 0.f, 0.f, 0.f, 1.f },
        //    .Translation = { 0.f, 0.f, 0.f },
        //    .Scale3D = { 1.f, 1.f, 1.f }
        //};

        //m_laser_dot_component = static_cast<SDK::UNiagaraComponent*>(
        //    m_main->get_vr_controllers()->get_right_hand_actor()->AddComponentByClass(
        //        SDK::UNiagaraComponent::StaticClass(), false, laser_dot_zero_transform, false
        //    ));
        //if (m_laser_dot_component == nullptr) {
        //    API::get()->log_error("Failed to add Laser Dot Component");
        //    return;
        //}

        //m_main->get_vr_controllers()->get_right_hand_actor()->FinishAddComponent(m_laser_dot_component, false, laser_dot_zero_transform);

        //m_laser_dot_component->SetAsset(laser_dot_ns, true);
        //m_laser_dot_component->ReinitializeSystem();
        //m_laser_dot_component->SetRenderInMainPass(true);
        //m_laser_dot_component->SetAbsolute(true, true, true);

        //SDK::FHitResult h_result{};
        //m_laser_dot_component->K2_SetWorldLocation({ -150.0f, 2000.0f, 200.0f }, false, &h_result, false);

        API::get()->log_warn("[vr_weapon][spawn_laser_pointer] Spawning Laser Pointer - End");
        return;
    }
    catch (...) {
        API::get()->log_error("[vr_weapon][spawn_laser_pointer] Exception");
        return;
    }
}

void VRWeapon::update_laser_pointer() {
    try {
        static SDK::FHitResult h_result{};
        //static SDK::FHitResult lt_result{};
        //if (m_laser_pointer_offset_component != nullptr) {
        //    set_offset_component_relative_location();

        //    //m_laser_pointer_offset_component->K2_SetRelativeLocation(m_laser_pointer_offset, false, &h_result, false);
        //    auto start = m_laser_pointer_offset_component->K2_GetComponentLocation();
        //    auto rot = m_laser_pointer_offset_component->K2_GetComponentRotation();
        //    auto end = start + (SDK::UKismetMathLibrary::Conv_RotatorToVector(rot) * 400.f);
        //    SDK::FLinearColor color{ 1.0f, 1.0f, 1.0f, 1.0f };

        //    // adding player character to be ignored in line trace
        //    SDK::TArray<SDK::AActor*> actors_to_ignore{};
        //    actors_to_ignore.Data = (SDK::AActor**)API::FMalloc::get()->malloc(1 * sizeof(SDK::AActor*));
        //    actors_to_ignore.NumElements = 1;
        //    actors_to_ignore.MaxElements = 1;
        //    actors_to_ignore.Data[0] = (SDK::AActor*)m_main->get_player_character();

        //    SDK::UKismetSystemLibrary::LineTraceSingle(
        //        SDK::UWorld::GetWorld(),
        //        start,
        //        end,
        //        SDK::ETraceTypeQuery::TraceTypeQuery6,
        //        //SDK::ETraceTypeQuery::TraceTypeQuery1,
        //        true,
        //        actors_to_ignore,
        //        SDK::EDrawDebugTrace::None,
        //        &lt_result,
        //        true, color, color, 0.0f);

            //if (m_reusable_result.Actor.Get() != nullptr) {
            //    auto traced_actor = m_reusable_result.Actor.Get();

            //    // take character components
            //    if (SDK::UKismetMathLibrary::ClassIsChildOf(traced_actor->Class, SDK::AIndianaCharacter::StaticClass())) {
            //        API::get()->log_warn("[VR HUD][update_laser_pointer] Found Character");

            //        static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetAllBodiesBelowSimulatePhysics(SDK::UKismetStringLibrary::Conv_StringToName(L"pelvis"), true, true);
            //        //static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetAllBodiesBelowPhysicsBlendWeight(SDK::UKismetStringLibrary::Conv_StringToName(L"pelvis"), 0.5f, false, false);
            //        static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
            //        //static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetCollisionObjectType(SDK::ECollisionChannel::ECC_WorldStatic);
            //        //static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_PhysicsBody, SDK::ECollisionResponse::ECR_Block);
            //        //static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Block);

            //        for (auto child : static_cast<SDK::AIndianaCharacter*>(traced_actor)->Mesh->AttachChildren) {
            //            if (child->IsA(SDK::USkeletalMeshComponent::StaticClass())) {

            //                static_cast<SDK::USkeletalMeshComponent*>(child)->SetSimulatePhysics(true);
            //                //static_cast<SDK::USkeletalMeshComponent*>(child)->SetAllBodiesBelowSimulatePhysics(SDK::UKismetStringLibrary::Conv_StringToName(L"pelvis"), true, true);
            //                //static_cast<SDK::USkeletalMeshComponent*>(child)->SetAllBodiesBelowPhysicsBlendWeight(SDK::UKismetStringLibrary::Conv_StringToName(L"pelvis"), 0.5f, false, false);
            //                static_cast<SDK::USkeletalMeshComponent*>(child)->SetCollisionEnabled(SDK::ECollisionEnabled::QueryAndPhysics);
            //                //static_cast<SDK::USkeletalMeshComponent*>(child)->SetCollisionObjectType(SDK::ECollisionChannel::ECC_WorldStatic);
            //                //static_cast<SDK::USkeletalMeshComponent*>(child)->SetCollisionResponseToChannel(SDK::ECollisionChannel::ECC_PhysicsBody, SDK::ECollisionResponse::ECR_Block);
            //                static_cast<SDK::USkeletalMeshComponent*>(child)->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Block);
            //            }
            //        }
            //    }

            //    //API::get()->log_warn("[VR HUD][update_laser_pointer] Object: %s", m_reusable_result.Component.Get()->Name.ToString().c_str());
            //    //m_reusable_result.Component.Get()->SetSimulatePhysics(true);
            //}

            //if (m_laser_pointer_component != nullptr) {
            //    if (lt_result.Distance <= 1.f) {
            //        m_laser_pointer_component->SetVisibility(false, false);
            //    }

            //    m_laser_pointer_component->K2_SetRelativeLocation({ lt_result.Distance - 0.5f, 0.f, 0.f }, false, &h_result, false);

            //    if (lt_result.Distance > 1.f) {
            //        m_laser_pointer_component->SetVisibility(true, false);
            //    }
            //}
        //}
    }
    catch (...) {
        API::get()->log_error("[vr_weapon][update_laser_pointer] Exception");
    }
}

void VRWeapon::on_draw_imgui() {
    try {
        if (is_valid()) {
            ImGui::SeparatorText("Equipped Weapon");
            // game state section

            ImGui::BeginGroup();
            ImGui::BeginDisabled();

            ImGui::InputText("Name", (m_equipped_weapon != nullptr) ? (char*)m_equipped_weapon->GetName().c_str() : (char*)"Unknown", 20);
            ImGui::InputText("Type", (char*)VRWeaponTypeName[m_weapon_type], 20);

            //if (m_weapon_type == WEAPON_TYPE_RANGED) {
            //    SDK::FVector aiming_direction = static_cast<SDK::URangedMode*>(m_equipped_weapon->GetCurrentMode())->GetAimingDirection();
            //    float ad_vec3f[3] = { aiming_direction.X, aiming_direction.Y, aiming_direction.Z };
            //    ImGui::InputFloat3("Aiming Direction", ad_vec3f);

            //    SDK::FVector aiming_up_direction = static_cast<SDK::URangedMode*>(m_equipped_weapon->GetCurrentMode())->GetAimingUpDirection();
            //    float aud_vec3f[3] = { aiming_up_direction.X, aiming_up_direction.Y, aiming_up_direction.Z };
            //    ImGui::InputFloat3("Aiming Up Direction", aud_vec3f);

            //    /*SDK::UKismetMathLibrary::*/

            //    SDK::FVector muzzle_location{};
            //    SDK::FRotator muzzle_rotation{};

            //    static_cast<SDK::URangedMode*>(m_equipped_weapon->GetCurrentMode())->GetMuzzleLocationAndRotation(&muzzle_location, &muzzle_rotation);

            //    //SDK::FVector muzzle_location = static_cast<SDK::URangedMode*>(m_equipped_weapon->GetCurrentMode())->GetMuzzleLocation();
            //    float ml_vec3f[3] = { muzzle_location.X, muzzle_location.Y, muzzle_location.Z };
            //    ImGui::InputFloat3("Muzzle Location", ml_vec3f);
            //    float mr_vec3f[3] = { muzzle_rotation.Pitch, muzzle_rotation.Roll, muzzle_rotation.Yaw };
            //    ImGui::InputFloat3("Muzzle Rotation", mr_vec3f);

            //    auto vec_from_rot = SDK::UKismetMathLibrary::Conv_RotatorToVector(muzzle_rotation);
            //    float vfr_vec3f[3] = { vec_from_rot.X, vec_from_rot.Y, vec_from_rot.Z };
            //    ImGui::InputFloat3("Vector from rotator", vfr_vec3f);
            //}

            ImGui::EndDisabled();
            ImGui::EndGroup();
        }
    }
    catch (...) {
        API::get()->log_error("[vr_weapon][on_draw_imgui] Exception");
    }
}
