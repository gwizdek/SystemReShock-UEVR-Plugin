#include "cyberspace_atmosphere_fix.hpp"

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/CON_Hacker_classes.hpp"
#include "SDK/GI_SinglePlayer_classes.hpp"
#include "plugin_utils.hpp"

using namespace uevr;

namespace {

// CyberspaceTransitionState after FinishCyberRiftTransition: the level is loaded, the pawn is
// possessed and the rift is closing. See the class comment for the other values.
constexpr uint8_t kStateRiftClosing = 2;

} // anonymous namespace

const void* CyberspaceAtmosphereFix::s_controller{ nullptr };
uint8_t CyberspaceAtmosphereFix::s_state{ 0 };

void CyberspaceAtmosphereFix::handle(SDK::UWorld* world) {
    try {
        if (world == nullptr) return;
        SDK::APlayerController* controller = SDK::UGameplayStatics::GetPlayerController(world, 0);
        if (!PluginUtils::is_a<SDK::ACON_Hacker_C>(controller)) {
            s_controller = nullptr;
            return;
        }

        const auto state = static_cast<uint8_t>(static_cast<SDK::ACON_Hacker_C*>(controller)->CyberspaceTransitionState);
        const bool same_controller = controller == s_controller;
        const bool entered_rift_closing = same_controller && state == kStateRiftClosing && s_state != kStateRiftClosing;
        s_controller = controller;
        s_state = state;

        if (entered_rift_closing) {
            reapply_atmosphere(world);
        }
    }
    catch (...) {
        API::get()->log_error("[cyberspace_atmosphere_fix][handle] Exception");
    }
}

void CyberspaceAtmosphereFix::reapply_atmosphere(SDK::UWorld* world) {
    SDK::UGameInstance* game_instance = world->OwningGameInstance;
    if (!PluginUtils::is_a<SDK::UGI_SinglePlayer_C>(game_instance)) {
        API::get()->log_error("[cyberspace_atmosphere_fix][reapply_atmosphere] Game instance is not a GI_SinglePlayer, atmosphere not reapplied");
        return;
    }
    static_cast<SDK::UGI_SinglePlayer_C*>(game_instance)->UpdateLevelAtmosphereToCurrent();
    API::get()->log_warn("[cyberspace_atmosphere_fix][reapply_atmosphere] Atmosphere reapplied after the cyber rift transition");
}
