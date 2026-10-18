#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/WIDGET_CyberspaceHUD_classes.hpp"
#include "BridgeSDK/_WIDGET_AimReticle_classes.hpp"

#include "plugin_utils.hpp"
#include "sdk_bootstrap.hpp"
#include "vr_avatar.hpp"

#include <cmath>

using namespace SDK;
using namespace uevr;

bool VRAvatar::s_reticle_brush_applied{ false };
A_BP_VRAvatar_C* VRAvatar::s_vr_avatar{ nullptr };
APAWN_Avatar_C* VRAvatar::s_pawn{ nullptr };
UCameraComponent* VRAvatar::s_game_camera{ nullptr };
UCameraComponent* VRAvatar::s_aim_camera{ nullptr };
USceneComponent* VRAvatar::s_aim_pivot{ nullptr };

namespace {

// Size of the reticle widget in pixels; one pixel is one world unit at scale 1.
constexpr float kReticleDrawSize = 80.f;
// World size of the reticle at kReticleNearDistance, in world units (centimetres).
constexpr float kReticleNearSize = 7.f;
constexpr float kReticleNearDistance = 50.f;
// The world size grows with distance to this power. Below 1 the reticle covers a smaller angle
// when it is far: about 8 degrees at 50 cm, 4.5 at 5 m and 3 at 25 m. With a constant angle a
// far reticle looks much bigger than a near one.
constexpr float kReticleSizeExponent = 0.75f;
// The reticle is never further from the controller than this, in world units (centimetres).
constexpr float kReticleMaxDistance = 2500.f;

bool is_alive(void* object) {
    return object != nullptr && API::UObjectHook::exists(reinterpret_cast<API::UObject*>(object));
}

void attach_keep_world(USceneComponent* component, USceneComponent* parent) {
    component->K2_AttachToComponent(
        parent,
        UKismetStringLibrary::Conv_StringToName(L"None"),
        EAttachmentRule::KeepWorld,
        EAttachmentRule::KeepWorld,
        EAttachmentRule::KeepWorld,
        true
    );
}

// Turns a vector that UEVR placed with the yaw of the view into the same vector placed with
// the full view rotation. See VRAvatar::corrected_controller_pose.
FVector yaw_to_full_view(const FVector& vector, const FRotator& view, const FRotator& view_yaw) {
    return UKismetMathLibrary::GreaterGreater_VectorRotator(
        UKismetMathLibrary::LessLess_VectorRotator(vector, view_yaw), view
    );
}

// The trace ignores the avatar and the VR avatar. The array is allocated once and reused,
// because the engine keeps no reference to it.
TArray<AActor*>& aim_trace_ignored_actors(AActor* pawn, AActor* vr_avatar) {
    static TArray<AActor*> ignored{};
    if (ignored.Data == nullptr) {
        ignored.Data = (AActor**)API::FMalloc::get()->malloc(2 * sizeof(AActor*));
        ignored.MaxElements = 2;
    }
    ignored.Data[0] = pawn;
    ignored.Data[1] = vr_avatar;
    ignored.NumElements = 2;
    return ignored;
}

} // namespace

A_BP_VRAvatar_C* VRAvatar::initialize_vr_avatar(APAWN_Avatar_C* pawn) {
    try {
        API::get()->log_warn("[vr_avatar][initialize_vr_avatar] Begin");
        restore_game_camera();

        A_BP_VRAvatar_C* vr_avatar = spawn_vr_avatar(pawn);
        if (vr_avatar == nullptr) {
            return nullptr;
        }

        UCameraComponent* aim_camera = create_aim_camera(vr_avatar);
        if (aim_camera == nullptr) {
            return nullptr;
        }

        use_aim_camera(pawn, aim_camera);
        set_hud_crosshair_visible(pawn, false);
        if (vr_avatar->AimReticle() != nullptr) {
            vr_avatar->AimReticle()->SetDrawSize({ kReticleDrawSize, kReticleDrawSize });
            // The Blueprint puts it under MotionControllerRight, which UEVR moves with the
            // uncorrected pose late in the frame. update_aim places it in world space instead.
            attach_keep_world(vr_avatar->AimReticle(), vr_avatar->DefaultSceneRoot());
        }
        s_vr_avatar = vr_avatar;
        API::get()->log_warn("[vr_avatar][initialize_vr_avatar] VRAvatar Initialized");
        return vr_avatar;
    }
    catch (...) {
        API::get()->log_error("[vr_avatar][initialize_vr_avatar] Exception");
    }
    return nullptr;
}

// Nothing in the game imports A_BP_VRAvatar_C, so the plugin loads the class itself before
// the spawn, the same way VRBody::initialize_vr_body does for the VR body.
A_BP_VRAvatar_C* VRAvatar::spawn_vr_avatar(APAWN_Avatar_C* pawn) {
    UClass* vr_avatar_class = PluginUtils::load_class_for_bridge(
        L"/Game/Mods/VRAvatar/_BP_VRAvatar._BP_VRAvatar_C", A_BP_VRAvatar_C::BridgeClassRef()
    );
    if (vr_avatar_class == nullptr) {
        API::get()->log_error("[vr_avatar][spawn_vr_avatar] VR avatar class not loaded");
        return nullptr;
    }

    auto world = SdkBootstrap::get_world();
    // By tag, not by class: a stale avatar may come from a class that is no longer loaded.
    PluginUtils::destroy_actors_by_tag(world, UKismetStringLibrary::Conv_StringToName(L"VRAvatarActor"));

    FTransform pawn_transform{};
    pawn_transform.Rotation = { 0.f, 0.f, 0.f, 1.f };
    pawn_transform.Translation = pawn->K2_GetActorLocation();
    pawn_transform.Scale3D = { 1.f, 1.f, 1.f };

    auto* vr_avatar = static_cast<A_BP_VRAvatar_C*>(UGameplayStatics::BeginDeferredActorSpawnFromClass(
        world, vr_avatar_class, pawn_transform, ESpawnActorCollisionHandlingMethod::AlwaysSpawn, nullptr
    ));
    if (vr_avatar == nullptr) {
        API::get()->log_error("[vr_avatar][spawn_vr_avatar] Error spawning VRAvatar BP Actor");
        return nullptr;
    }
    UGameplayStatics::FinishSpawningActor(vr_avatar, pawn_transform);

    TArray<FName> actor_tags{};
    actor_tags.Data = (FName*)API::FMalloc::get()->malloc(1 * sizeof(FName));
    actor_tags.NumElements = 1;
    actor_tags.MaxElements = 1;
    actor_tags.Data[0] = UKismetStringLibrary::Conv_StringToName(L"VRAvatarActor");
    vr_avatar->Tags = actor_tags;

    // The avatar's root is CollisionCylinder, as on the station pawn, so the profile's
    // camera_state.json path resolves to this actor's UEVRCameraAttachComponent.
    vr_avatar->K2_AttachRootComponentTo(
        pawn->K2_GetRootComponent(),
        UKismetStringLibrary::Conv_StringToName(L"None"),
        EAttachLocation::SnapToTarget,
        true
    );
    vr_avatar->Pawn() = pawn;
    API::get()->log_warn("[vr_avatar][spawn_vr_avatar] Spawned and attached to the avatar");
    return vr_avatar;
}

// A camera that is never the view: it belongs to the VR avatar, not to the pawn, so the
// pawn's CalcCamera does not find it, and it is deactivated besides.
//
// It hangs on a pivot that update_aim moves to the corrected pose of the right controller each
// tick. The avatar Blueprint writes the camera's own relative rotation (UpdateCameraRotation,
// a tilt that is 0 here) and relative location (UpdateCameraShake) every tick, after
// update_aim, so the camera cannot be placed directly: it would snap back to its parent before
// the timer-driven autofire shots read it. The pivot hangs on the VR avatar's root, so it turns
// and moves with the avatar during the tick, like the view does.
UCameraComponent* VRAvatar::create_aim_camera(A_BP_VRAvatar_C* vr_avatar) {
    FTransform identity{};
    identity.Rotation = { 0.f, 0.f, 0.f, 1.f };
    identity.Scale3D = { 1.f, 1.f, 1.f };

    auto* aim_pivot = static_cast<USceneComponent*>(
        vr_avatar->AddComponentByClass(USceneComponent::StaticClass(), true, identity, false)
    );
    auto* aim_camera = static_cast<UCameraComponent*>(
        vr_avatar->AddComponentByClass(UCameraComponent::StaticClass(), true, identity, false)
    );
    if (aim_pivot == nullptr || aim_camera == nullptr) {
        API::get()->log_error("[vr_avatar][create_aim_camera] Could not add the aim pivot or camera");
        return nullptr;
    }

    attach_keep_world(aim_pivot, vr_avatar->DefaultSceneRoot());
    aim_camera->Deactivate();
    aim_camera->bLockToHmd = false;
    aim_camera->K2_AttachToComponent(
        aim_pivot,
        UKismetStringLibrary::Conv_StringToName(L"None"),
        EAttachmentRule::SnapToTarget,
        EAttachmentRule::SnapToTarget,
        EAttachmentRule::KeepWorld,
        true
    );
    s_aim_pivot = aim_pivot;
    API::get()->log_warn("[vr_avatar][create_aim_camera] Aim pivot and camera added");
    return aim_camera;
}

// The avatar Blueprint also writes a small tilt (strafe roll, climb pitch) to the relative
// rotation of whatever Camera points at. On the aim camera that would bend the shots away
// from the controller, so the tilt is set to 0.
void VRAvatar::use_aim_camera(APAWN_Avatar_C* pawn, UCameraComponent* aim_camera) {
    s_pawn = pawn;
    s_aim_camera = aim_camera;
    s_game_camera = static_cast<UCameraComponent*>(pawn->GetComponentByClass(UCameraComponent::StaticClass()));
    pawn->CameraRoll_Strafe_Max = 0.f;
    pawn->CameraPitch_Move_Max = 0.f;
    pawn->Camera = aim_camera;
    API::get()->log_warn("[vr_avatar][use_aim_camera] Avatar aims with the right controller");
}

void VRAvatar::restore_game_camera() {
    if (is_alive(s_pawn) && is_alive(s_game_camera)) {
        s_pawn->Camera = s_game_camera;
        set_hud_crosshair_visible(s_pawn, true);
        API::get()->log_warn("[vr_avatar][restore_game_camera] Avatar aims with its own camera again");
    }
    s_vr_avatar = nullptr;
    s_pawn = nullptr;
    s_game_camera = nullptr;
    s_aim_camera = nullptr;
    s_aim_pivot = nullptr;
    s_reticle_brush_applied = false;
}

bool VRAvatar::is_active() {
    return is_alive(s_vr_avatar);
}

// The HUD draws its crosshair at the screen centre, which is where the head looks, not where
// the controller aims. Render opacity hides it: ShowCrosshairs(false) would also change the
// input mode and show the mouse cursor, and the HUD sets the panel's visibility itself.
void VRAvatar::set_hud_crosshair_visible(APAWN_Avatar_C* pawn, bool visible) {
    auto* hud = static_cast<UWIDGET_CyberspaceHUD_C*>(pawn->CyberspaceUI);
    if (!is_alive(hud) || hud->PANEL_Crosshairs == nullptr) {
        return;
    }
    hud->PANEL_Crosshairs->SetRenderOpacity(visible ? 1.f : 0.f);
}

void VRAvatar::update_aim() {
    try {
        if (!is_alive(s_vr_avatar) || !is_alive(s_aim_pivot) || !is_alive(s_game_camera)) {
            return;
        }
        const AimPose aim = corrected_controller_pose();
        FHitResult unused{};
        s_aim_pivot->K2_SetWorldLocationAndRotation(
            aim.location, UKismetMathLibrary::MakeRotFromXZ(aim.forward, aim.up), false, &unused, false
        );
        place_reticle(aim);
    }
    catch (...) {
        API::get()->log_error("[vr_avatar][update_aim] Exception");
    }
}

// UObjectHook places MotionControllerRight with the yaw of the view only
// (UObjectHook::tick_attachments uses view_quat_inverse_flat). That is right while the view is
// level, as on the station. In cyberspace the game view also pitches and rolls, and UEVR
// renders the head with the full view rotation, so the controller would be off by exactly that
// pitch and roll. Both poses hang off the same point, the game camera, so turning the
// controller's offset and axes back by the view yaw and on by the full view rotation gives
// the controller's real pose. This runs before the world tick, when the camera is still where
// UEVR last placed the controller from.
VRAvatar::AimPose VRAvatar::corrected_controller_pose() {
    auto* controller = reinterpret_cast<USceneComponent*>(s_vr_avatar->MotionControllerRight());
    const FVector view_location = s_game_camera->K2_GetComponentLocation();
    const FRotator view = s_game_camera->K2_GetComponentRotation();
    const FRotator view_yaw{ 0.f, view.Yaw, 0.f };

    AimPose aim{};
    aim.location = view_location + yaw_to_full_view(controller->K2_GetComponentLocation() - view_location, view, view_yaw);
    aim.forward = yaw_to_full_view(controller->GetForwardVector(), view, view_yaw);
    aim.up = yaw_to_full_view(controller->GetUpVector(), view, view_yaw);
    return aim;
}

// The reticle sits on the aim line, where the line hits something but never further than
// kReticleMaxDistance, faces back along the line and grows with its distance, less than the
// distance does.
void VRAvatar::place_reticle(const AimPose& aim) {
    UWidgetComponent* reticle = s_vr_avatar->AimReticle();
    if (reticle == nullptr) {
        return;
    }
    if (!s_reticle_brush_applied) {
        s_reticle_brush_applied = apply_reticle_brush(reticle);
    }

    const float distance = trace_aim_distance(aim.location, aim.forward);
    const float size = kReticleNearSize * std::pow(distance / kReticleNearDistance, kReticleSizeExponent);
    const float scale = size / kReticleDrawSize;
    const FVector back{ -aim.forward.X, -aim.forward.Y, -aim.forward.Z };
    FHitResult unused{};
    reticle->K2_SetWorldLocationAndRotation(
        aim.location + aim.forward * distance, UKismetMathLibrary::MakeRotFromXZ(back, aim.up), false, &unused, false
    );
    reticle->SetWorldScale3D({ scale, scale, scale });
}

// _WIDGET_AimReticle holds one image with a placeholder brush. It gets the material of the
// HUD crosshair, MAT_CrosshairCursor, taken from the HUD's own image, so nothing has to be
// loaded. The widget component creates its widget on BeginPlay; until then this returns false
// and is tried again on the next tick.
bool VRAvatar::apply_reticle_brush(UWidgetComponent* reticle) {
    auto* widget = static_cast<U_WIDGET_AimReticle_C*>(reticle->GetUserWidgetObject());
    auto* hud = static_cast<UWIDGET_CyberspaceHUD_C*>(s_pawn->CyberspaceUI);
    if (!is_alive(widget) || !is_alive(hud) || hud->IMAGE_CrosshairCursor == nullptr) {
        return false;
    }
    UObject* material = hud->IMAGE_CrosshairCursor->Brush.ResourceObject;
    UImage* image = widget->IMAGE_Reticle();
    if (material == nullptr || image == nullptr) {
        return false;
    }
    image->SetBrushResourceObject(material);
    API::get()->log_warn("[vr_avatar][apply_reticle_brush] Reticle shows %s", material->GetName().c_str());
    return true;
}

// Distance along the aim line to the first thing the Visibility channel hits, or
// kReticleMaxDistance when nothing is hit before it.
float VRAvatar::trace_aim_distance(const FVector& start, const FVector& direction) {
    const FVector end = start + direction * kReticleMaxDistance;
    FHitResult hit{};
    const bool has_hit = UKismetSystemLibrary::LineTraceSingle(
        s_vr_avatar, start, end, ETraceTypeQuery::TraceTypeQuery1, false,
        aim_trace_ignored_actors(s_pawn, s_vr_avatar), EDrawDebugTrace::None, &hit,
        true, {}, {}, 0.f
    );
    return has_hit ? hit.Distance : kReticleMaxDistance;
}
