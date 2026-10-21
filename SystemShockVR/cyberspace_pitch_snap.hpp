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
// up or down past "Pitch Deadzone" pitches the avatar until its forward vector lies on a world
// axis (+-X, +-Y, +-Z): the nearest one in the push direction that is at least 30 degrees away,
// so a snap is never only a few degrees. Up pitches the nose up, and the game's Invert Y setting
// for cyberspace turns that around. The stick must come back under the deadzone before the next
// push counts. The avatar turns around its own right axis over "Pitch Snap Duration" seconds
// (0 is instant), fast at first and slower towards the end. A push during a snap goes on to the
// next axis and starts the ease again.
//
// The turn is a local actor rotation, like the game's own look input, so yaw, roll and
// movement go on during a snap. The angle still to turn is measured every tick, so the snap
// ends on the axis even when the body turn or the game moves the avatar meanwhile.
class CyberspacePitchSnap final
{
public:
    // From the XInput callback while the game state is GAME_STATE_CYBERSPACE. Takes the right
    // stick's Y out of the state the game reads, and queues a snap on a push.
    static void handle_input(XINPUT_STATE* state);
    // Once per engine tick while the game state is GAME_STATE_CYBERSPACE. Starts a queued snap
    // and turns the avatar by this tick's part of the snap.
    static void handle_tick(SDK::APawn* avatar, float delta);

private:
    static float game_pitch_direction(float stick_y);
    static void reset();
};
