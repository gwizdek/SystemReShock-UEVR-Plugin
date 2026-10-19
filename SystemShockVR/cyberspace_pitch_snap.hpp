#pragma once

#include <windows.h>
#include <Xinput.h>

namespace SDK
{
    class APawn;
}

// Pitch snap turn for the cyberspace avatar, set on the VR options page (Cyberspace group).
//
// While "Pitch Snap Turn" is on, the right stick no longer pitches the avatar smoothly. A push
// up or down past "Pitch Deadzone" adds 90 degrees of pitch: up pitches the nose up, and the
// game's Invert Y setting for cyberspace turns that around. The stick must come
// back under the deadzone before the next push counts. The avatar turns around its own right
// axis over "Pitch Snap Speed" seconds (0 is instant), fast at first and slower towards the end.
// A push during a snap adds 90 degrees to what is left and starts the ease again.
//
// The turn is a local actor rotation, like the game's own look input, so yaw, roll and
// movement go on during a snap.
class CyberspacePitchSnap final
{
public:
    // From the XInput callback while the game state is GAME_STATE_CYBERSPACE. Takes the right
    // stick's Y out of the state the game reads, and starts a snap on a push.
    static void handle_input(XINPUT_STATE* state);
    // Once per engine tick while the game state is GAME_STATE_CYBERSPACE. Turns the avatar by
    // this tick's part of the snap.
    static void handle_tick(SDK::APawn* avatar, float delta);

private:
    static void start_snap(float direction);
    static float game_pitch_direction(float stick_y);
    static void reset();
};
