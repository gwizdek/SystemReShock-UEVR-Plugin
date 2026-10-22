#pragma once

namespace SDK
{
    class APAWN_Avatar_C;
    class APAWN_Hacker_Simple_C;
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
// Connection integrity and the hotbar's panel are also drawn at 3/4 of their size. The
// original layout of each slot and render transform of each widget are kept and set back by
// restore.
//
// Pseudospace has its own HUD with its own connection integrity (WIDGET_PseudoHealth), also in
// the top right corner. It is moved to the top centre the same way, at full size.
class CyberspaceHudLayout final
{
public:
    // Called when the VR avatar is set up.
    static void apply(SDK::APAWN_Avatar_C* pawn);
    // Called every tick in pseudospace. The HUD can appear after the pawn, so the layout is
    // applied once it exists, and again only for a new HUD.
    static void handle_pseudospace(SDK::APAWN_Hacker_Simple_C* pawn);
    // Called when the VR avatar is removed.
    static void restore();
};
