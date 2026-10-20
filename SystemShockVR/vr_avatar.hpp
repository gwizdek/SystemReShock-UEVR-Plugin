#pragma once

#include "uevr/API.h"
#include "SDK/Engine_structs.hpp"
#include "SDK/COMP_HackerInventory_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "BridgeSDK/_BP_VRAvatar_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"

// The VR side of the cyberspace avatar. See documentation/cyberspace-controls.md.
//
// The game spawns cyberspace projectiles at the avatar's Camera component, along its forward
// vector. The plugin spawns _BP_VRAvatar on the avatar, adds an aim camera to its right motion
// controller and points the avatar's Camera property at it, so shots follow the controller.
// The view does not change: the avatar's own camera component stays the active one.
class VRAvatar final
{
public:
    // Spawns _BP_VRAvatar, attaches it to the avatar's root and sets up the aim camera.
    // Returns nullptr when anything failed; the avatar then keeps its own camera for aiming.
    static SDK::A_BP_VRAvatar_C* initialize_vr_avatar(SDK::APAWN_Avatar_C* pawn);

    // Points the avatar's Camera property back at its own camera. Called before the VR
    // avatar is destroyed, so the game never aims with a destroyed component.
    static void restore_game_camera();

    // True while a VR avatar spawned by initialize_vr_avatar is alive.
    static bool is_active();

    // Called once per engine tick, before the world tick. Moves the aim camera to the real
    // pose of the right controller, and the AimReticle widget onto the aim line.
    static void update_aim(const UEVR_VRData* vr, float delta);

    // Called from the stereo view offset callback with the engine's world to meters scale,
    // which UEVR multiplies by its world scale to place the controllers.
    static void set_world_to_meters(float world_to_meters);

private:
    struct AimPose {
        SDK::FVector location;
        SDK::FVector forward;
        SDK::FVector up;
        // The view's up vector (camera rotation x rotation offset, without the HMD), so the
        // reticle rolls neither with the controller nor with the head.
        SDK::FVector view_up;
    };

    static AimPose controller_pose_from_tracking(const UEVR_VRData* vr, float delta);
    static void place_reticle(const AimPose& aim);
    static SDK::A_BP_VRAvatar_C* spawn_vr_avatar(SDK::APAWN_Avatar_C* pawn);
    static SDK::UCameraComponent* create_aim_camera(SDK::A_BP_VRAvatar_C* vr_avatar);
    static void use_aim_camera(SDK::APAWN_Avatar_C* pawn, SDK::UCameraComponent* aim_camera);
    static void set_hud_crosshair_visible(SDK::APAWN_Avatar_C* pawn, bool visible);
    static void set_hud_dashboards_visible(SDK::APAWN_Avatar_C* pawn, bool visible);
    static void set_hud_decorations_visible(SDK::APAWN_Avatar_C* pawn, bool visible);
    static float trace_aim_distance(const SDK::FVector& start, const SDK::FVector& direction);
    static bool apply_reticle_brush(SDK::UWidgetComponent* reticle);

    static bool s_reticle_brush_applied;
    static SDK::A_BP_VRAvatar_C* s_vr_avatar;
    static SDK::APAWN_Avatar_C* s_pawn;
    static SDK::UCameraComponent* s_game_camera;
    static SDK::UCameraComponent* s_aim_camera;
    static SDK::USceneComponent* s_aim_pivot;
    static float s_world_to_meters;
};
