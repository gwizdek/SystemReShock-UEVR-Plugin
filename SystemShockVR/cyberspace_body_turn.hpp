#pragma once

#include "uevr/API.h"

namespace SDK
{
    class APawn;
}

// Turns the cyberspace avatar with the player's head, in yaw and in pitch.
//
// The game moves the avatar along its own forward vector. With UEVR's aim method "game", UEVR
// shows the head turn in the view but never turns the avatar, so after the player turns
// around or looks up, the left stick no longer moves the avatar where the player looks. Each
// tick this takes the head's yaw and pitch in view space (rotation offset x HMD rotation),
// turns the avatar by them around its own up and right axes, and takes the same turn out of
// UEVR's rotation offset. The view is avatar rotation x rotation offset x HMD rotation, so it
// does not change; the avatar's forward now points where the head looks. The head's roll stays
// in the view. The UEVR UI is placed by the rotation offset, so it follows the head's yaw and
// pitch too.
class CyberspaceBodyTurn final
{
public:
    // Called once per engine tick while the player flies the cyberspace avatar.
    static void handle(SDK::APawn* avatar, const UEVR_VRData* vr);
};
