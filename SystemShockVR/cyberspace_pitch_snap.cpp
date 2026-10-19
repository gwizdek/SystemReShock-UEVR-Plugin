#include "cyberspace_pitch_snap.hpp"

#include <algorithm>
#include <cmath>

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/SAVE_Settings_classes.hpp"

#include "vr_game_options.hpp"
#include "vr_settings.hpp"

using namespace uevr;

namespace {

constexpr float kSnapDegrees = 90.f;
constexpr float kStickMax = 32767.f;
// A deadzone of 0 would count stick noise as a push.
constexpr float kMinTrigger = 0.05f;
// The stick must come back below this part of the trigger value before the next push counts.
constexpr float kRearmFactor = 0.8f;

// One ease: Total degrees over Duration seconds, of which Applied are done.
struct Snap
{
    float total{ 0.f };
    float applied{ 0.f };
    float elapsed{ 0.f };
    float duration{ 0.f };
};

Snap s_snap{};
bool s_armed{ true };
SDK::APawn* s_avatar{ nullptr };

// Ease-out cubic: the turn starts at three times the average speed and slows to 0 at the end.
float ease_out(float alpha) {
    const float rest = 1.f - alpha;
    return 1.f - rest * rest * rest;
}

} // namespace

void CyberspacePitchSnap::handle_input(XINPUT_STATE* state) {
    if (!VRSettings::pitch_snap_turn()) {
        s_armed = true;
        return;
    }
    const float stick_y = state->Gamepad.sThumbRY / kStickMax;
    state->Gamepad.sThumbRY = 0;

    const float trigger = (std::max)(VRSettings::pitch_deadzone(), kMinTrigger);
    if (std::fabs(stick_y) < trigger * kRearmFactor) {
        s_armed = true;
        return;
    }
    if (!s_armed || std::fabs(stick_y) < trigger) {
        return;
    }
    s_armed = false;
    start_snap(game_pitch_direction(stick_y));
}

void CyberspacePitchSnap::handle_tick(SDK::APawn* avatar, float delta) {
    try {
        if (avatar != s_avatar) {
            s_avatar = avatar;
            reset();
        }
        if (avatar == nullptr || s_snap.total == 0.f) {
            return;
        }
        s_snap.elapsed += delta;
        const float alpha = s_snap.duration > 0.f ? (std::min)(s_snap.elapsed / s_snap.duration, 1.f) : 1.f;
        const float target = s_snap.total * ease_out(alpha);
        const float step = target - s_snap.applied;
        s_snap.applied = target;
        if (alpha >= 1.f) {
            s_snap = {};
        }

        SDK::FHitResult unused{};
        avatar->K2_AddActorLocalRotation({ step, 0.f, 0.f }, false, &unused, false);
    }
    catch (...) {
        API::get()->log_error("[cyberspace_pitch_snap][handle_tick] Exception");
    }
}

// What is left of a running snap goes into the new one, so a push during a snap adds 90 degrees
// to where the snap was heading.
void CyberspacePitchSnap::start_snap(float direction) {
    const float remaining = s_snap.total - s_snap.applied;
    s_snap = {
        .total = remaining + direction * kSnapDegrees,
        .applied = 0.f,
        .elapsed = 0.f,
        .duration = VRSettings::pitch_snap_duration()
    };
    API::get()->log_warn("[cyberspace_pitch_snap][start_snap] Pitch %+.0f, %.1f degrees over %.2f s",
        direction * kSnapDegrees, s_snap.total, s_snap.duration);
}

// Without Invert Y a push up pitches the nose up (tested in the headset). The game's Invert Y
// for cyberspace turns that around.
float CyberspacePitchSnap::game_pitch_direction(float stick_y) {
    const float pitch = stick_y > 0.f ? 1.f : -1.f;
    SDK::USAVE_Settings_C* settings = VRGameOptions::find_settings();
    const bool invert = settings != nullptr && settings->CyberspaceInvertY;
    return invert ? -pitch : pitch;
}

void CyberspacePitchSnap::reset() {
    s_snap = {};
    s_armed = true;
}
