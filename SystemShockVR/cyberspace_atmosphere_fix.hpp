#pragma once

#include <cstdint>

namespace SDK
{
    class UWorld;
}

// Reapplies the level's atmosphere settings when a cyber rift transition ends.
//
// GI_SinglePlayer applies a level's atmosphere settings (UpdateLevelAtmosphereToCurrent) only
// after a level load with a loading screen. The cyber rift transition into and out of
// cyberspace loads its levels without that path, so after leaving cyberspace the deck keeps the
// cyberspace atmosphere. CON_Hacker tracks the transition in CyberspaceTransitionState:
// TryBeginCyberRiftTransition sets 1, BeginUnloadingLevelForCyberTransition sets 3,
// FinishCyberRiftTransition sets 2 once the level is loaded and the new pawn is possessed, and
// CyberspaceTransitionTick sets 0 when the rift has closed. This class reads that field once per
// engine tick and calls UpdateLevelAtmosphereToCurrent when it enters 2. That is the call the
// game is missing; it runs one tick after FinishCyberRiftTransition, behind the rift effect.
class CyberspaceAtmosphereFix final
{
public:
    // Called once per engine tick, on the game thread. Does nothing while the player
    // controller is not a CON_Hacker.
    static void handle(SDK::UWorld* world);

private:
    static void reapply_atmosphere(SDK::UWorld* world);

    // The controller the remembered state belongs to, and the state seen on the last tick. A
    // controller seen for the first time only records its state, so it never counts as a change.
    static const void* s_controller;
    static uint8_t s_state;
};
