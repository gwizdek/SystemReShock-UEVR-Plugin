#pragma once

namespace SDK
{
class APAWN_Hacker_Simple_C;
class UWorld;
}

// Changes how long a timed tutorial popup stays on the HUD, as the duration key of the [popup]
// section in tutorial_messages.ini says, in seconds.
//
// PAWN_Hacker_Simple::ActivateTimedTutorial adds an STRUCT_TutorialInstance with a Timestamp and
// a Duration to the pawn's TutorialsToDisplay array. A 1 second timer calls
// TryCompleteTimedTutorials, which removes an entry once Duration is above 0 and the play time
// since its Timestamp has reached Duration. All six callers in the game pass the literal 5.0.
// Volume tutorials have Duration 0 and stay until the player leaves the volume.
//
// This class reads the array a few times per second and sets Duration of every entry that still
// holds the game's 5.0 to the ini value. A changed entry no longer matches, so each entry is
// changed once, and the plugin keeps no state about it; a plugin swap by the hot loader does not
// change an entry twice. The time still counts from the entry's own Timestamp.
class TutorialPopupDuration final
{
public:
    // Called once per engine tick, on the game thread. Does nothing while the player pawn is
    // not a PAWN_Hacker_Simple, or when the ini sets no duration.
    static void handle(SDK::UWorld* world);

private:
    static void read_ini();
    static void extend(SDK::APAWN_Hacker_Simple_C* pawn);

    static bool s_ini_read;
    static float s_duration;
    static int s_ticks_until_check;
};
