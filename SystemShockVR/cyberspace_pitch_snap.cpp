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

constexpr float kRadToDeg = 57.2957795f;
constexpr float kStickMax = 32767.f;
// A deadzone of 0 would count stick noise as a push.
constexpr float kMinTrigger = 0.05f;
// The stick must come back below this part of the trigger value before the next push counts.
constexpr float kRearmFactor = 0.8f;
// A snap never ends on a world axis closer than this to where it starts.
constexpr float kMinSnapDegrees = 30.f;
// A world axis this close to the avatar's right axis cannot be reached by pitching.
constexpr float kMinAxisInPlane = 0.5f;

const SDK::FVector kWorldAxes[] = {
    { 1.f, 0.f, 0.f }, { -1.f, 0.f, 0.f },
    { 0.f, 1.f, 0.f }, { 0.f, -1.f, 0.f },
    { 0.f, 0.f, 1.f }, { 0.f, 0.f, -1.f },
};

// A snap to one world axis. Remaining is the pitch still to turn, in degrees, measured again
// every tick, so it can be more than 180 after several pushes. RestShare is the part of the
// ease that was still to come after the last tick.
struct Snap
{
    bool active{ false };
    SDK::FVector axis{};
    float remaining{ 0.f };
    float elapsed{ 0.f };
    float duration{ 0.f };
    float rest_share{ 1.f };
};

// The avatar's pitch plane: Forward and Up, both at right angles to the right axis that a pitch
// turns around.
struct PitchPlane
{
    SDK::FVector forward{};
    SDK::FVector up{};
};

Snap s_snap{};
bool s_armed{ true };
float s_pending_direction{ 0.f };
SDK::APawn* s_avatar{ nullptr };

float dot(const SDK::FVector& a, const SDK::FVector& b) {
    return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}

PitchPlane pitch_plane_of(SDK::APawn* avatar) {
    return { avatar->GetActorForwardVector(), avatar->GetActorUpVector() };
}

// The pitch from the avatar's forward to the axis, in degrees, positive up, -180 to 180.
float pitch_to(const PitchPlane& plane, const SDK::FVector& axis) {
    return std::atan2(dot(axis, plane.up), dot(axis, plane.forward)) * kRadToDeg;
}

bool is_in_reach(const PitchPlane& plane, const SDK::FVector& axis) {
    return std::hypot(dot(axis, plane.forward), dot(axis, plane.up)) >= kMinAxisInPlane;
}

// The angle in -180..180 plus the whole turns that bring it closest to Expected.
float unwrap_near(float angle, float expected) {
    return angle + 360.f * std::round((expected - angle) / 360.f);
}

// Ease-out cubic: the turn starts at three times the average speed and slows to 0 at the end.
// This is the part of it still to come at Alpha.
float rest_share(float alpha) {
    const float rest = 1.f - alpha;
    return rest * rest * rest;
}

// Picks the nearest world axis in the push direction that is at least kMinSnapDegrees away.
// During a snap it counts from the snap's axis, so a push goes on to the next axis.
void start_snap(const PitchPlane& plane, float direction) {
    const float from = s_snap.active ? s_snap.remaining : 0.f;
    float best_turn = 0.f;
    const SDK::FVector* best_axis = nullptr;
    for (const SDK::FVector& axis : kWorldAxes) {
        if (!is_in_reach(plane, axis)) continue;
        float turn = std::fmod((pitch_to(plane, axis) - from) * direction, 360.f);
        if (turn < 0.f) turn += 360.f;
        if (turn < kMinSnapDegrees) turn += 360.f;
        if (best_axis == nullptr || turn < best_turn) {
            best_turn = turn;
            best_axis = &axis;
        }
    }
    if (best_axis == nullptr) {
        API::get()->log_warn("[cyberspace_pitch_snap][start_snap] No world axis in the pitch plane, push ignored");
        return;
    }
    s_snap = {
        .active = true,
        .axis = *best_axis,
        .remaining = from + direction * best_turn,
        .elapsed = 0.f,
        .duration = VRSettings::pitch_snap_duration(),
        .rest_share = 1.f
    };
    API::get()->log_warn("[cyberspace_pitch_snap][start_snap] To axis (%.0f, %.0f, %.0f), %.1f degrees over %.2f s",
        best_axis->X, best_axis->Y, best_axis->Z, s_snap.remaining, s_snap.duration);
}

// The pitch still to turn is measured again each tick, because the game and the body turn can
// move the avatar during a snap. Each tick takes the same share of it as the ease curve does,
// and the last tick turns all of it, so the snap ends on the axis.
void turn_towards_axis(SDK::APawn* avatar, const PitchPlane& plane, float delta) {
    if (!is_in_reach(plane, s_snap.axis)) {
        API::get()->log_warn("[cyberspace_pitch_snap][turn_towards_axis] Axis left the pitch plane, snap stopped");
        s_snap = {};
        return;
    }
    const float remaining = unwrap_near(pitch_to(plane, s_snap.axis), s_snap.remaining);
    s_snap.elapsed += delta;
    const float alpha = s_snap.duration > 0.f ? (std::min)(s_snap.elapsed / s_snap.duration, 1.f) : 1.f;
    const float share = rest_share(alpha);
    const float step = alpha >= 1.f ? remaining : remaining * (1.f - share / s_snap.rest_share);
    s_snap.rest_share = share;
    s_snap.remaining = remaining - step;
    if (alpha >= 1.f) {
        s_snap = {};
    }

    SDK::FHitResult unused{};
    avatar->K2_AddActorLocalRotation({ step, 0.f, 0.f }, false, &unused, false);
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
    s_pending_direction = game_pitch_direction(stick_y);
}

void CyberspacePitchSnap::handle_tick(SDK::APawn* avatar, float delta) {
    try {
        if (avatar != s_avatar) {
            s_avatar = avatar;
            reset();
        }
        if (avatar == nullptr) {
            return;
        }
        const PitchPlane plane = pitch_plane_of(avatar);
        if (s_pending_direction != 0.f) {
            start_snap(plane, s_pending_direction);
            s_pending_direction = 0.f;
        }
        if (s_snap.active) {
            turn_towards_axis(avatar, plane, delta);
        }
    }
    catch (...) {
        API::get()->log_error("[cyberspace_pitch_snap][handle_tick] Exception");
    }
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
    s_pending_direction = 0.f;
}
