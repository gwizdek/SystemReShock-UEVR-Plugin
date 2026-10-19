#pragma once

#include <windows.h>
#include <Xinput.h>

#include "uevr/API.h"

namespace SDK
{
    class APawn;
}

// Flies the cyberspace avatar where the head looks, in pitch: looking up while moving forward
// moves the avatar up.
//
// The avatar keeps its own rotation; only the move direction follows the head. The game adds
// the left stick to FrameRelativeInput (X forward, Y right) and, in UpdateMovement, adds
// PersistentRelativeInput to it, normalizes the sum and turns it by the avatar's rotation. So
// the plugin takes the left stick away from the game and writes it into
// PersistentRelativeInput instead, with its forward part turned up or down by the head's pitch
// against the avatar. Strafing stays level with the avatar. Body turn (CyberspaceBodyTurn)
// already turns the avatar with the head's yaw.
//
// Turning the avatar itself by the head's pitch, as body turn does for the yaw, does not work:
// a head that turns to the side while it looks up also turns a little around its line of
// sight, and that turn either rolls the world or builds up as a rolled view.
class CyberspaceHeadSteering final
{
public:
    // From the XInput callback while the game state is GAME_STATE_CYBERSPACE. Takes the left
    // stick out of the state the game reads and keeps it for handle_tick.
    static void handle_input(XINPUT_STATE* state);
    // Once per engine tick while the game state is GAME_STATE_CYBERSPACE. Writes the move
    // direction for this tick into the avatar's PersistentRelativeInput.
    static void handle_tick(SDK::APawn* avatar, const UEVR_VRData* vr);
};
