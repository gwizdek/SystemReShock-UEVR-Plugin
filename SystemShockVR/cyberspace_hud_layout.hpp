#pragma once

namespace SDK
{
    class APAWN_Avatar_C;
}

// Moves parts of the cyberspace HUD to places that suit the VR view. See "HUD layout in VR" in
// documentation/cyberspace-controls.md.
//
// The VR view is about square, while the HUD canvas is as wide as the monitor: with the UI
// scaled by the window's shorter side it is always about 1080 units tall, and wider on wide
// monitors. Parts anchored to a side of the canvas move out of the view there, so they are
// anchored to its centre line instead:
// - Connection integrity: from the top right corner to the top centre, as high as it goes.
// - The scan text (the name of what the head looks at): below connection integrity.
// - The software hotbar: down onto the bottom edge.
// The original layout of each slot is kept and set back by restore.
class CyberspaceHudLayout final
{
public:
    // Called when the VR avatar is set up.
    static void apply(SDK::APAWN_Avatar_C* pawn);
    // Called when the VR avatar is removed.
    static void restore();
};
