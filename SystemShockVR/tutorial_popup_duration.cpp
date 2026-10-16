#include "tutorial_popup_duration.hpp"

#include <cstdlib>

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/PAWN_Hacker_Simple_classes.hpp"
#include "mINI/ini.h"
#include "plugin_utils.hpp"

using namespace uevr;

namespace {

constexpr const wchar_t* kIniFileName = L"tutorial_messages.ini";
constexpr const char* kPopupSection = "popup";
constexpr const char* kDurationKey = "duration";

// The Duration that every caller of ActivateTimedTutorial passes.
constexpr float kGameDuration = 5.0f;

// Ticks between two reads of TutorialsToDisplay. The game removes an entry after 5 seconds at
// the earliest, so a fraction of a second is enough.
constexpr int kCheckTicks = 30;

} // anonymous namespace

bool TutorialPopupDuration::s_ini_read{ false };
float TutorialPopupDuration::s_duration{ 0.0f };
int TutorialPopupDuration::s_ticks_until_check{ 1 };

void TutorialPopupDuration::handle(SDK::UWorld* world) {
    if (--s_ticks_until_check > 0) return;
    s_ticks_until_check = kCheckTicks;
    try {
        if (!s_ini_read) read_ini();
        if (s_duration <= 0.0f || world == nullptr) return;
        SDK::APawn* pawn = SDK::UGameplayStatics::GetPlayerPawn(world, 0);
        if (!PluginUtils::is_a<SDK::APAWN_Hacker_Simple_C>(pawn)) return;
        extend(static_cast<SDK::APAWN_Hacker_Simple_C*>(pawn));
    }
    catch (...) {
        API::get()->log_error("[tutorial_popup_duration][handle] Exception");
    }
}

// Reads [popup] duration once. A missing file, key or a value of 0 keeps the game's duration;
// so does the game's own value, as there is nothing to change then.
void TutorialPopupDuration::read_ini() {
    s_ini_read = true;
    const std::string path = API::get()->get_persistent_dir(kIniFileName).string();
    mINI::INIFile file(path);
    mINI::INIStructure ini;
    if (file.read(ini) && ini.has(kPopupSection)) {
        s_duration = static_cast<float>(std::atof(ini.get(kPopupSection).get(kDurationKey).c_str()));
    }
    if (s_duration == kGameDuration) s_duration = 0.0f;
    if (s_duration > 0.0f) {
        API::get()->log_warn("[tutorial_popup_duration][read_ini] Timed tutorial popups stay %g seconds", s_duration);
    }
    else {
        API::get()->log_warn("[tutorial_popup_duration][read_ini] No duration in %s; timed tutorial popups keep the game's %g seconds", path.c_str(), kGameDuration);
    }
}

void TutorialPopupDuration::extend(SDK::APAWN_Hacker_Simple_C* pawn) {
    auto& tutorials = pawn->TutorialsToDisplay;
    for (int32_t i = 0; i < tutorials.Num(); ++i) {
        float& duration = tutorials[i].Duration_10_C25A60884153076CD2508D9E0114A5B4;
        if (duration == kGameDuration) duration = s_duration;
    }
}
