#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/WIDGET_CyberspaceHUD_classes.hpp"
#include "SDK/WIDGET_CyberspaceGreeble_classes.hpp"
#include "SDK/WIDGET_CyberspaceOccularRing_classes.hpp"
#include "BridgeSDK/_WIDGET_AimReticle_classes.hpp"

#include "plugin_utils.hpp"
#include "sdk_bootstrap.hpp"
#include "vr_avatar.hpp"
#include "vr_lock_on.hpp"
#include "cyberspace_hud_layout.hpp"
#include "vr_settings.hpp"

#include <algorithm>
#include <cmath>
#include <cstring>

using namespace SDK;
using namespace uevr;

bool VRAvatar::s_reticle_brush_applied{ false };
A_BP_VRAvatar_C* VRAvatar::s_vr_avatar{ nullptr };
APAWN_Avatar_C* VRAvatar::s_pawn{ nullptr };
UCameraComponent* VRAvatar::s_game_camera{ nullptr };
UCameraComponent* VRAvatar::s_aim_camera{ nullptr };
USceneComponent* VRAvatar::s_aim_pivot{ nullptr };
float VRAvatar::s_world_to_meters{ 100.f };

namespace {

// Size of the reticle widget in pixels; one pixel is one world unit at scale 1.
constexpr float kReticleDrawSize = 80.f;
// World size of the reticle at kReticleNearDistance, in world units (centimetres), is the
// "Crosshair Scale" setting divided by this: 20 at 100 percent, 10 at 50 and 30 at 150.
constexpr float kCrosshairScaleToNearSize = 5.f;
constexpr float kReticleNearDistance = 50.f;
// The world size grows with distance to this power. Below 1 the reticle covers a smaller angle
// when it is far: at 100 percent about 23 degrees at 50 cm, 13 at 5 m and 8.6 at 25 m. With a
// constant angle a far reticle looks much bigger than a near one.
constexpr float kReticleSizeExponent = 0.75f;
// The reticle is never further from the controller than this, in world units (centimetres).
constexpr float kReticleMaxDistance = 2500.f;
// The masked reticle is depth tested, so it is placed this part of its own size in front of
// the surface the aim hits. At 0.75 it stays clear of a wall hit at up to about 56 degrees
// from straight on (half its size times tan 56 is 0.75 of its size).
constexpr float kReticleSurfaceGap = 0.75f;
// The engine's masked widget material. A masked reticle writes depth and motion vectors, so a
// temporal upscaler such as DLSS keeps it stable; a translucent one smears and shimmers.
constexpr const wchar_t* kMaskedWidgetMaterial =
    L"/Engine/EngineMaterials/Widget3DPassThrough_Masked.Widget3DPassThrough_Masked";

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

// UEVR_Quaternionf is declared w, x, y, z, so it is always filled by name.
UEVR_Quaternionf multiply(const UEVR_Quaternionf& a, const UEVR_Quaternionf& b) {
    return {
        .w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
        .x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
        .y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
        .z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
    };
}

UEVR_Vector3f rotate(const UEVR_Quaternionf& q, const UEVR_Vector3f& v) {
    const UEVR_Quaternionf p{ .w = 0.f, .x = v.x, .y = v.y, .z = v.z };
    const UEVR_Quaternionf conjugate{ .w = q.w, .x = -q.x, .y = -q.y, .z = -q.z };
    const UEVR_Quaternionf r = multiply(multiply(q, p), conjugate);
    return { r.x, r.y, r.z };
}

// UEVR's tracking axes are -Z forward, +Y up, +X right; Unreal's are X forward, Y right, Z up.
FVector to_unreal(const UEVR_Vector3f& v) {
    return { -v.z, v.x, v.y };
}

FVector turned_by_view(const UEVR_Vector3f& tracking_vector, const FRotator& view) {
    return UKismetMathLibrary::GreaterGreater_VectorRotator(to_unreal(tracking_vector), view);
}

float dot(const UEVR_Quaternionf& a, const UEVR_Quaternionf& b) {
    return a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
}

// Spherical interpolation along the shorter way, like glm::slerp.
UEVR_Quaternionf slerp(const UEVR_Quaternionf& a, UEVR_Quaternionf b, float t) {
    float cosine = dot(a, b);
    if (cosine < 0.f) {
        b = { .w = -b.w, .x = -b.x, .y = -b.y, .z = -b.z };
        cosine = -cosine;
    }
    float weight_a = 1.f - t;
    float weight_b = t;
    if (cosine < 0.9995f) {
        const float angle = std::acos(cosine);
        weight_a = std::sin(weight_a * angle) / std::sin(angle);
        weight_b = std::sin(weight_b * angle) / std::sin(angle);
    }
    const UEVR_Quaternionf r{
        .w = weight_a * a.w + weight_b * b.w,
        .x = weight_a * a.x + weight_b * b.x,
        .y = weight_a * a.y + weight_b * b.y,
        .z = weight_a * a.z + weight_b * b.z
    };
    const float length = std::sqrt(dot(r, r));
    return { .w = r.w / length, .x = r.x / length, .y = r.y / length, .z = r.z / length };
}

bool mod_value_is_true(const UEVR_VRData* vr, const char* key) {
    char value[16] = {};
    vr->get_mod_value(key, value, sizeof(value));
    return std::strcmp(value, "true") == 0;
}

// The aim follows the controller this many times faster than UEVR's attach lerp speed. At 1 it
// is smoothed as much as the hands UObjectHook places; above 1 less, below 1 more.
constexpr float kAimLerpSpeedFactor = 1.0f;

// The right controller's grip position and aim rotation in tracking space, smoothed like
// UObjectHook smooths the hands it places (UObjectHook::tick_attachments, "attach lerp"), with
// the same two UEVR settings and kAimLerpSpeedFactor.
struct ControllerTracking {
    UEVR_Vector3f position{};
    UEVR_Quaternionf rotation{ .w = 1.f, .x = 0.f, .y = 0.f, .z = 0.f };
};

ControllerTracking s_smoothed{};
bool s_has_smoothed{ false };

ControllerTracking smoothed(const ControllerTracking& raw, float delta, const UEVR_VRData* vr) {
    if (!s_has_smoothed || !mod_value_is_true(vr, "UObjectHook_AttachLerpEnabled")) {
        s_smoothed = raw;
        s_has_smoothed = true;
        return s_smoothed;
    }
    const float lerp_speed = PluginUtils::uevr_param_to_float(vr, "UObjectHook_AttachLerpSpeed") * kAimLerpSpeedFactor * delta;

    const float rotation_t = std::min(1.f, lerp_speed * std::fabs(dot(raw.rotation, s_smoothed.rotation)));
    s_smoothed.rotation = slerp(s_smoothed.rotation, raw.rotation, rotation_t);

    const UEVR_Vector3f moved{
        raw.position.x - s_smoothed.position.x, raw.position.y - s_smoothed.position.y, raw.position.z - s_smoothed.position.z
    };
    const float distance = std::sqrt(moved.x * moved.x + moved.y * moved.y + moved.z * moved.z);
    const float position_t = std::min(1.f, lerp_speed * std::max(1.f, distance));
    s_smoothed.position = {
        s_smoothed.position.x + moved.x * position_t,
        s_smoothed.position.y + moved.y * position_t,
        s_smoothed.position.z + moved.z * position_t
    };
    return s_smoothed;
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
        set_hud_dashboards_visible(pawn, false);
        set_hud_decorations_visible(pawn, false);
        CyberspaceHudLayout::apply(pawn);
        if (vr_avatar->AimReticle() != nullptr) {
            vr_avatar->AimReticle()->SetDrawSize({ kReticleDrawSize, kReticleDrawSize });
            // The Blueprint puts it under MotionControllerRight, which UEVR moves with the
            // uncorrected pose late in the frame. update_aim places it in world space instead.
            attach_keep_world(vr_avatar->AimReticle(), vr_avatar->DefaultSceneRoot());
            use_masked_reticle_material(vr_avatar->AimReticle());
        }
        VRLockOn::attach(vr_avatar, pawn);
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
    VRLockOn::restore();
    CyberspaceHudLayout::restore();
    if (is_alive(s_pawn) && is_alive(s_game_camera)) {
        s_pawn->Camera = s_game_camera;
        set_hud_crosshair_visible(s_pawn, true);
        set_hud_dashboards_visible(s_pawn, true);
        set_hud_decorations_visible(s_pawn, true);
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

// The bands across the top and the bottom of the HUD (MESH_Dashboard in PANEL_DashboardTop,
// MESH_DashboardBottom) are hidden in VR. The scan text in the top panel stays. Render opacity
// on the meshes hides them, like the crosshair.
void VRAvatar::set_hud_dashboards_visible(APAWN_Avatar_C* pawn, bool visible) {
    auto* hud = static_cast<UWIDGET_CyberspaceHUD_C*>(pawn->CyberspaceUI);
    if (!is_alive(hud)) {
        return;
    }
    for (UWidget* dashboard : { static_cast<UWidget*>(hud->MESH_Dashboard), static_cast<UWidget*>(hud->MESH_DashboardBottom) }) {
        if (dashboard != nullptr) {
            dashboard->SetRenderOpacity(visible ? 1.f : 0.f);
        }
    }
}

// Two decorations of the HUD are hidden in VR: the large arcs at its sides
// (WIDGET_CyberspaceOccularRing) and the position, rotation, data rate and VIRT readout at the
// bottom left (WIDGET_CyberspaceGreeble). Render opacity on a user widget does not reach its
// mesh widgets, so their visibility is set instead. No game code changes that visibility; the
// assets' default is Visible.
void VRAvatar::set_hud_decorations_visible(APAWN_Avatar_C* pawn, bool visible) {
    auto* hud = static_cast<UWIDGET_CyberspaceHUD_C*>(pawn->CyberspaceUI);
    if (!is_alive(hud)) {
        return;
    }
    const ESlateVisibility visibility = visible ? ESlateVisibility::Visible : ESlateVisibility::Hidden;
    for (UWidget* decoration : { static_cast<UWidget*>(hud->WIDGET_CyberspaceOccularRing), static_cast<UWidget*>(hud->WIDGET_CyberspaceGreeble) }) {
        if (decoration != nullptr) {
            decoration->SetVisibility(visibility);
        }
    }
}

void VRAvatar::update_aim(const UEVR_VRData* vr, float delta) {
    try {
        if (!is_alive(s_vr_avatar) || !is_alive(s_aim_pivot) || !is_alive(s_game_camera)) {
            s_has_smoothed = false;
            return;
        }
        const AimPose aim = controller_pose_from_tracking(vr, delta);
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

void VRAvatar::set_world_to_meters(float world_to_meters) {
    if (world_to_meters > 0.f) {
        s_world_to_meters = world_to_meters;
    }
}

// UEVR renders the head at the game camera, turned by the full view rotation: camera rotation
// x rotation offset x HMD pose. This builds the right controller's pose the same way, from the
// controller's tracking pose: grip position, aim rotation, smoothed, as UObjectHook uses them.
//
// MotionControllerRight cannot be used. UObjectHook places it with the yaw of the view only
// (view_quat_inverse_flat), and turning it back by the view's yaw is not possible when the
// view looks straight up or down: the yaw is then undefined, and the yaw of the camera's
// rotator differs from the one UEVR flattened with. The aim then pointed up to 90 degrees away
// from the controller.
//
// The pose only depends on the camera rotation times the rotation offset, which body turn
// leaves unchanged, so it does not matter where in the tick this runs.
VRAvatar::AimPose VRAvatar::controller_pose_from_tracking(const UEVR_VRData* vr, float delta) {
    ControllerTracking raw{};
    UEVR_Quaternionf grip_rotation{};
    UEVR_Vector3f aim_position{};
    UEVR_Vector3f standing_origin{};
    UEVR_Quaternionf offset{};
    const UEVR_TrackedDeviceIndex index = vr->get_right_controller_index();
    vr->get_grip_pose(index, &raw.position, &grip_rotation);
    vr->get_aim_pose(index, &aim_position, &raw.rotation);
    vr->get_standing_origin(&standing_origin);
    vr->get_rotation_offset(&offset);
    const ControllerTracking controller = smoothed(raw, delta, vr);

    const FRotator view = s_game_camera->K2_GetComponentRotation();
    const float units_per_meter = s_world_to_meters * PluginUtils::uevr_param_to_float(vr, "VR_WorldScale");
    const UEVR_Vector3f from_origin{
        controller.position.x - standing_origin.x,
        controller.position.y - standing_origin.y,
        controller.position.z - standing_origin.z
    };
    const UEVR_Quaternionf rotation = multiply(offset, controller.rotation);

    AimPose aim{};
    aim.location = s_game_camera->K2_GetComponentLocation() + turned_by_view(rotate(offset, from_origin), view) * units_per_meter;
    aim.forward = turned_by_view(rotate(rotation, { 0.f, 0.f, -1.f }), view);
    aim.up = turned_by_view(rotate(rotation, { 0.f, 1.f, 0.f }), view);
    aim.view_up = turned_by_view(rotate(offset, { 0.f, 1.f, 0.f }), view);
    return aim;
}

// The reticle sits on the aim line, where the line hits something but never further than
// kReticleMaxDistance, faces back along the line and grows with its distance, less than the
// distance does. Its up is the view's up, so it rolls neither with the controller nor with
// the head; only a roll of the avatar turns it.
void VRAvatar::place_reticle(const AimPose& aim) {
    UWidgetComponent* reticle = s_vr_avatar->AimReticle();
    if (reticle == nullptr) {
        return;
    }
    if (!s_reticle_brush_applied) {
        s_reticle_brush_applied = apply_reticle_brush(reticle);
    }

    const float distance = trace_aim_distance(aim.location, aim.forward);
    const float near_size = VRSettings::crosshair_scale() / kCrosshairScaleToNearSize;
    const float size = near_size * std::pow(distance / kReticleNearDistance, kReticleSizeExponent);
    const float scale = size / kReticleDrawSize;
    const float placed_at = std::max(0.f, distance - size * kReticleSurfaceGap);
    const FVector back{ -aim.forward.X, -aim.forward.Y, -aim.forward.Z };
    const FVector location = aim.location + aim.forward * placed_at;
    const FRotator rotation = UKismetMathLibrary::MakeRotFromXZ(back, aim.view_up);
    FHitResult unused{};
    reticle->K2_SetWorldLocationAndRotation(location, rotation, false, &unused, false);
    reticle->SetWorldScale3D({ scale, scale, scale });
    VRLockOn::place(location, rotation, scale);
}

// _BP_VRAvatar gives AimReticle a translucent material without depth test, so walls could not
// hide it. Under DLSS that smears and shimmers, so the engine's masked widget material
// replaces it; place_reticle keeps the masked reticle in front of the surface instead.
void VRAvatar::use_masked_reticle_material(UWidgetComponent* reticle) {
    const FSoftObjectPath path = UKismetSystemLibrary::MakeSoftObjectPath(kMaskedWidgetMaterial);
    auto* material = static_cast<UMaterialInterface*>(
        UKismetSystemLibrary::LoadAsset_Blocking(UKismetSystemLibrary::Conv_SoftObjPathToSoftObjRef(path))
    );
    if (material == nullptr) {
        API::get()->log_error("[vr_avatar][use_masked_reticle_material] %ls not loaded, reticle stays translucent", kMaskedWidgetMaterial);
        return;
    }
    reticle->SetMaterial(0, material);
    API::get()->log_warn("[vr_avatar][use_masked_reticle_material] Reticle uses the masked widget material");
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
