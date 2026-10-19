#pragma once

#include "uevr/API.h"

namespace SDK
{
    class APawn;
}

// Turns the cyberspace avatar with the player's real body.
//
// The game moves the avatar along its own forward vector. With UEVR's aim method "game", UEVR
// shows the head turn in the view but never turns the avatar, so after the player turns
// around, the left stick no longer moves the avatar where the player faces. Each tick this
// takes the head's yaw in view space (rotation offset x HMD rotation), turns the avatar by it
// around its own up axis, and takes the same yaw out of UEVR's rotation offset. The view is
// avatar rotation x rotation offset x HMD rotation, so it does not change; the avatar's forward
// now points where the head points. The UEVR UI is placed by the rotation offset, so it
// follows the head's yaw too.
class CyberspaceBodyTurn final
{
public:
    // Called once per engine tick while the player flies the cyberspace avatar.
    static void handle(SDK::APawn* avatar, const UEVR_VRData* vr);
};
