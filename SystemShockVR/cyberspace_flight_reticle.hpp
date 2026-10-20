#pragma once

namespace SDK
{
    class APawn;
    class UWIDGET_FlightReticle_C;
    class UWorld;
}

// Turns the cyberspace HUD's ring (WIDGET_FlightReticle, the "gyroscope") so it points to
// world up.
//
// The game turns the ring in WIDGET_FlightReticle::RotateUpward, which the HUD calls every
// tick from UpdateGryoscope: angle = -Roll of the pawn's rotation, smoothed. The pitch snap
// can leave the avatar at exactly 90 degrees up or down, and there a rotator's yaw and roll are
// not defined: Unreal can split the same rotation into any pair of them. The ring then pointed
// anywhere, and changed when the split changed.
//
// RotateUpward is only called from other Blueprint code, which UEVR's UFunction hook does not
// see, so the plugin patches its bytecode: the first instruction becomes a jump to the final
// return. The plugin then sets the ring's angle itself every tick. With UI_FollowView off,
// UEVR keeps the HUD quad turned with the game camera, so the angle is the direction of world
// up in the camera's frame: screen right is the camera's Y axis, screen up its Z axis. When the
// camera looks straight up or down, world up has no direction on the screen, and the ring
// keeps its last angle.
//
// In VR the Core pak leaves only the ring's top triangle in its texture, the "up" marker. The
// plugin also shows the reticle at full render opacity; the HUD asset dims it.
//
// The patch lives in the loaded class, so it holds until the game exits, and it is checked
// again now and then in case the class was loaded anew.
class CyberspaceFlightReticle final
{
public:
    // Once per engine tick while the game state is GAME_STATE_CYBERSPACE.
    static void handle(SDK::UWorld* world, SDK::APawn* avatar);

private:
    static void patch();
    static void update_angle(SDK::UWorld* world, SDK::APawn* avatar);
    static void show_at_full_opacity(SDK::UWIDGET_FlightReticle_C* reticle);

    static int s_ticks_until_check;
    static float s_angle;
};
