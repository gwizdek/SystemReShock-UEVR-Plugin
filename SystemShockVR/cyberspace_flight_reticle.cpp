#include "cyberspace_flight_reticle.hpp"
#include "object_lookup.hpp"

#include <cmath>
#include <cstdint>

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"
#include "SDK/WIDGET_CyberspaceHUD_classes.hpp"
#include "SDK/WIDGET_FlightReticle_classes.hpp"

#include "plugin_utils.hpp"

using namespace uevr;

namespace {

constexpr const wchar_t* kRotateUpward =
    L"Function /Game/Blueprints/UI/Cyberspace/WIDGET_FlightReticle.WIDGET_FlightReticle_C.RotateUpward";

// Ticks between two checks of the patch.
constexpr int kCheckTicks = 600;

// Below this length of world up on the screen plane (about 1 degree from straight up or down)
// its direction is not used.
constexpr float kMinUpOnScreen = 0.02f;

constexpr float kRadToDeg = 57.29578f;

// UStruct::Script, the bytecode of a Blueprint function, in UE 4.27: a TArray<uint8> at 0x60.
constexpr size_t kScriptOffset = 0x60;

struct ScriptArray
{
    uint8_t* data;
    int32_t num;
    int32_t max;
};

// Blueprint VM opcodes (EExprToken).
constexpr uint8_t EX_Return = 0x04;
constexpr uint8_t EX_Jump = 0x06;
constexpr uint8_t EX_Nothing = 0x0B;
constexpr uint8_t EX_EndOfScript = 0x53;

// "Return Nothing" followed by "EndOfScript", the end of every compiled function.
constexpr int32_t kEpilogueSize = 3;

// Jump with a 32 bit target; the 5 bytes the patch writes at the start of the script.
constexpr int32_t kJumpSize = 1 + 4;

// The offset of the final "Return Nothing", or -1.
int32_t find_final_return(const ScriptArray& script) {
    if (script.data == nullptr || script.num <= kJumpSize + kEpilogueSize || script.num > script.max) return -1;
    const int32_t at = script.num - kEpilogueSize;
    const uint8_t* p = script.data + at;
    if (p[0] != EX_Return || p[1] != EX_Nothing || p[2] != EX_EndOfScript) return -1;
    return at;
}

int32_t jump_target(const uint8_t* at) {
    return *reinterpret_cast<const int32_t*>(at + 1);
}

} // anonymous namespace

int CyberspaceFlightReticle::s_ticks_until_check{ 0 };
float CyberspaceFlightReticle::s_angle{ 0.f };

void CyberspaceFlightReticle::handle(SDK::UWorld* world, SDK::APawn* avatar) {
    try {
        if (--s_ticks_until_check <= 0) {
            s_ticks_until_check = kCheckTicks;
            patch();
        }
        update_angle(world, avatar);
    }
    catch (...) {
        API::get()->log_error("[cyberspace_flight_reticle][handle] Exception");
    }
}

void CyberspaceFlightReticle::patch() {
    auto* function = ObjectLookup::find<API::UFunction>(kRotateUpward);
    if (function == nullptr) return;   // class not loaded yet
    auto& script = *reinterpret_cast<ScriptArray*>(reinterpret_cast<uint8_t*>(function) + kScriptOffset);
    const int32_t target = find_final_return(script);
    if (target < 0) {
        API::get()->log_error("[cyberspace_flight_reticle][patch] RotateUpward does not end with 'Return Nothing', not patched");
        return;
    }
    if (script.data[0] == EX_Jump && jump_target(script.data) == target) return;
    script.data[0] = EX_Jump;
    *reinterpret_cast<int32_t*>(script.data + 1) = target;
    API::get()->log_warn("[cyberspace_flight_reticle][patch] RotateUpward now returns at once (jump to offset %d)", target);
}

void CyberspaceFlightReticle::update_angle(SDK::UWorld* world, SDK::APawn* avatar) {
    if (world == nullptr || avatar == nullptr || !PluginUtils::is_a<SDK::APAWN_Avatar_C>(avatar)) {
        return;
    }
    auto* hud = static_cast<SDK::APAWN_Avatar_C*>(avatar)->CyberspaceUI;
    if (hud == nullptr || !SDK::UKismetSystemLibrary::IsValid(hud)) {
        return;
    }
    auto* reticle = hud->WIDGET_FlightReticle;
    if (reticle == nullptr || reticle->MESH_FlightReticle == nullptr) {
        return;
    }
    auto* camera_manager = SDK::UGameplayStatics::GetPlayerCameraManager(world, 0);
    if (camera_manager == nullptr) {
        return;
    }

    const SDK::FVector up = SDK::UKismetMathLibrary::LessLess_VectorRotator(
        { 0.f, 0.f, 1.f }, camera_manager->GetCameraRotation()
    );
    if (std::hypot(up.Y, up.Z) >= kMinUpOnScreen) {
        // Render angles turn clockwise; world up to the right of screen up is a positive angle.
        s_angle = std::atan2(up.Y, up.Z) * kRadToDeg;
    }
    reticle->CurrentAngle = s_angle;
    reticle->MESH_FlightReticle->SetRenderTransformAngle(s_angle);
}
