#pragma once
#include <map>

#define INPUT_DEADZONE_LO  ( 0.01f * FLOAT(0x7FFF) )  // Default to 01% of the +/- 32767 range.
#define INPUT_DEADZONE_MED ( 0.45f * FLOAT(0x7FFF) )  // Default to 45% of the +/- 32767 range.
#define INPUT_DEADZONE_HI  ( 0.80f * FLOAT(0x7FFF) )  // Default to 80% of the +/- 32767 range.
#define MOUSE_WHEEL_DEBOUNCE_TIME 0.066f

// this engine channel shouldn't be used, but would need to change all defined collision profiles to ignore my own dedicated game channel
// anyway, this one works
const SDK::ECollisionChannel WIDGET_INTERACTION_TRACE_CHANNEL{ SDK::ECollisionChannel::ECC_EngineTraceChannel1 };

const SDK::ECollisionChannel ADS_TRACE_CHANNEL{ SDK::ECollisionChannel::ECC_EngineTraceChannel2 };

typedef enum ModEvent {
    MOD_EVENT_VR_HUD_HIDE_DASHBOARDS,
    MOD_EVENT_VR_HUD_INITIALIZE,
    MOD_EVENT_SHOW_MFD,
    MOD_EVENT_SHOW_IN_GAME_MENU,
    MOD_EVENT_MOUSE_ACTIVE,
    MOD_EVENT_ENABLE_WORLD_RENDERING
} ModEvent;

enum EGameState : uint8_t {
    GAME_STATE_UNDEFINED = 0,
    GAME_STATE_MAIN_MENU = 1,
    GAME_STATE_PAUSE_MENU = 2,
    GAME_STATE_CINEMATIC = 3,
    GAME_STATE_APPARTMENT = 4,
    GAME_STATE_CITADEL_STATION = 5,
    GAME_STATE_CYBERSPACE = 6,
    GAME_STATE_PSEUDOSPACE = 7,
    GAME_STATE_MFD_PRE = 8, // one tick state when MFD is drawn based on HMD rotation
    GAME_STATE_MFD = 9,
    GAME_STATE_INTERACTABLE = 10,
    GAME_STATE_INTRO_DRONE = 11,
    GAME_STATE_BOOTING_UP = 12,
    GAME_STATE_CRASHING = 13,
    GAME_STATE_INTRO_LAPTOP = 14
};

static std::map<EGameState, const char*> GameStateName = {
    { GAME_STATE_UNDEFINED, "Undefined" },
    { GAME_STATE_MAIN_MENU, "Main Menu" },
    { GAME_STATE_PAUSE_MENU, "Pause Menu" },
    { GAME_STATE_CINEMATIC, "Cinematic" },
    { GAME_STATE_APPARTMENT, "Appartment" },
    { GAME_STATE_CITADEL_STATION, "Citadel Station" },
    { GAME_STATE_CYBERSPACE, "Cyberspace" },
    { GAME_STATE_PSEUDOSPACE, "Pseudeospace" },
    { GAME_STATE_MFD_PRE, "MFD Pre" },
    { GAME_STATE_MFD, "MFD" },
    { GAME_STATE_INTERACTABLE, "Interactable" },
    { GAME_STATE_INTRO_DRONE, "Intro Drone" },
    { GAME_STATE_BOOTING_UP, "Booting Up" },
    { GAME_STATE_CRASHING, "Crashing" },
    { GAME_STATE_INTRO_LAPTOP, "Intro Laptop" }
};


// Pawn states
enum EPawnState : uint8_t {
    PAWN_UNKNOWN = 0,
    PAWN_PLAYERGHOST = 1,
    PAWN_HACKERSIMPLE = 2,
    PAWN_HACKERIMPLANT = 3,
    PAWN_AVATAR = 4,
    PAWN_PSEUDOSPACE = 5
};

static std::map<EPawnState, const char*> PawnStateName = {
    { PAWN_UNKNOWN, "Unknown" },
    { PAWN_PLAYERGHOST, "Player Ghost" },
    { PAWN_HACKERSIMPLE, "Hacker Simple" },
    { PAWN_HACKERIMPLANT, "Hacker Implant" },
    { PAWN_AVATAR, "Avatar" },
    { PAWN_PSEUDOSPACE, "Pseudospace" }
};
