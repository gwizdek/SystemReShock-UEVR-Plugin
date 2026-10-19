#pragma once

// Turns UEVR's roomscale sweep (VR_RoomscaleMovementSweep) off in cyberspace and restores the
// player's own value afterwards.
//
// With the sweep on, UEVR moves the pawn for a real step with a sweep, so the pawn collides.
// In cyberspace that made the avatar lose health fast when the player stepped into a wall.
// Without it a real step can pass through a wall; moving with the sticks still collides,
// because that is the game's own movement.
//
// The player's value is kept in a file in the UEVR profile folder, not only in memory, so a
// plugin swap by the hot loader or a game exit while in cyberspace does not lose it: a new
// plugin copy would otherwise read the cyberspace value, false, as the player's.
class RoomscaleSweepSetting final
{
public:
    // On entering cyberspace. Saves the current value once, then sets the sweep to false.
    static void disable_for_cyberspace();

    // On any pawn other than the cyberspace avatar. Restores a saved value, if there is one.
    static void restore();
};
