#include "menu_auto_recenter.hpp"

#include <algorithm>
#include <cmath>

#include "uevr/API.hpp"

#include "vr_settings.hpp"

using namespace uevr;

namespace {

// The [general] menu_recenter_* values of system_reshock_vr_config.ini, read when a menu opens.
struct Settings
{
    // The head may turn this far from the view's forward direction, either way, without a recenter.
    float allowed_yaw_degrees{ 25.f };
    // How long the head must stay past allowed_yaw_degrees before the view recenters.
    float outside_seconds{ 2.5f };
    // How long the recenter takes. 0 recenters at once.
    float recenter_seconds{ 0.1f };
};

constexpr float kDegToRad = 0.0174532925f;
constexpr float kRadToDeg = 57.2957795f;
// When the head looks almost straight up or down its yaw is not defined, so the tick is skipped.
constexpr float kMaxForwardUp = 0.95f;

// A recenter in progress. RestShare is the part of the ease that was still to come after the
// last tick.
struct Recenter
{
    bool active{ false };
    float elapsed{ 0.f };
    float rest_share{ 1.f };
};

Settings s_settings{};
bool s_in_menu{ false };
Recenter s_recenter{};
float s_outside_seconds{ 0.f };

void read_settings() {
    s_settings = {
        .allowed_yaw_degrees = VRSettings::menu_recenter_angle(),
        .outside_seconds = VRSettings::menu_recenter_delay(),
        .recenter_seconds = VRSettings::menu_recenter_duration()
    };
    API::get()->log_warn("[menu_auto_recenter][read_settings] Angle %.1f degrees, delay %.2f s, duration %.2f s",
        s_settings.allowed_yaw_degrees, s_settings.outside_seconds, s_settings.recenter_seconds);
}

// UEVR_Quaternionf is declared w, x, y, z, so it is always filled by name.
UEVR_Quaternionf multiply(const UEVR_Quaternionf& a, const UEVR_Quaternionf& b) {
    return {
        .w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
        .x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
        .y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
        .z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
    };
}

// The forward vector of a rotation in UEVR's tracking space (OpenVR axes: -Z forward, +Y up,
// +X right), that is the rotation applied to (0, 0, -1).
UEVR_Vector3f forward_of(const UEVR_Quaternionf& q) {
    return {
        .x = -2.f * (q.x * q.z + q.w * q.y),
        .y = -2.f * (q.y * q.z - q.w * q.x),
        .z = -(1.f - 2.f * (q.x * q.x + q.y * q.y))
    };
}

// A turn of the given angle around the tracking space's up axis (+Y). A positive angle turns
// left, the opposite of an Unreal yaw.
UEVR_Quaternionf turn_around_up(float radians) {
    return { .w = std::cos(radians * 0.5f), .x = 0.f, .y = std::sin(radians * 0.5f), .z = 0.f };
}

// The head's yaw in view space in degrees, positive when the head turns right. False when the
// head looks almost straight up or down.
bool head_yaw_degrees(const UEVR_VRData* vr, float* yaw_degrees) {
    UEVR_Vector3f hmd_position{};
    UEVR_Quaternionf hmd_rotation{};
    UEVR_Quaternionf offset{};
    vr->get_pose(vr->get_hmd_index(), &hmd_position, &hmd_rotation);
    vr->get_rotation_offset(&offset);

    const UEVR_Vector3f forward = forward_of(multiply(offset, hmd_rotation));
    if (std::fabs(forward.y) > kMaxForwardUp) {
        return false;
    }
    *yaw_degrees = std::atan2(forward.x, -forward.z) * kRadToDeg;
    return true;
}

// Turning the offset by the head's yaw takes that yaw out of the view.
void turn_offset(const UEVR_VRData* vr, float yaw_degrees) {
    UEVR_Quaternionf offset{};
    vr->get_rotation_offset(&offset);
    const UEVR_Quaternionf new_offset = multiply(turn_around_up(yaw_degrees * kDegToRad), offset);
    vr->set_rotation_offset(&new_offset);
}

// Ease-out cubic: the turn starts at three times the average speed and slows to 0 at the end.
// This is the part of it still to come at Alpha.
float rest_share(float alpha) {
    const float rest = 1.f - alpha;
    return rest * rest * rest;
}

} // namespace

void MenuAutoRecenter::handle_tick(const UEVR_VRData* vr, bool in_menu, float delta) {
    try {
        if (!in_menu || !vr->is_hmd_active()) {
            reset();
            return;
        }
        if (!s_in_menu) {
            s_in_menu = true;
            read_settings();
        }
        float yaw_degrees = 0.f;
        if (!head_yaw_degrees(vr, &yaw_degrees)) {
            return;
        }
        if (s_recenter.active) {
            turn_towards_head(vr, yaw_degrees, delta);
            return;
        }
        if (std::fabs(yaw_degrees) <= s_settings.allowed_yaw_degrees) {
            s_outside_seconds = 0.f;
            return;
        }
        s_outside_seconds += delta;
        if (s_outside_seconds >= s_settings.outside_seconds) {
            start_recenter(vr, yaw_degrees);
        }
    }
    catch (...) {
        API::get()->log_error("[menu_auto_recenter][handle_tick] Exception");
    }
}

void MenuAutoRecenter::start_recenter(const UEVR_VRData* vr, float yaw_degrees) {
    s_outside_seconds = 0.f;
    API::get()->log_warn("[menu_auto_recenter][start_recenter] Head at %.0f degrees for %.1f s, recentering over %.2f s",
        yaw_degrees, s_settings.outside_seconds, s_settings.recenter_seconds);
    if (s_settings.recenter_seconds <= 0.f) {
        vr->recenter_view();
        return;
    }
    s_recenter = { .active = true, .elapsed = 0.f, .rest_share = 1.f };
}

// Each tick takes the same share of the yaw still to turn as the ease curve does, and the last
// tick turns all of it, so the view ends facing the head.
void MenuAutoRecenter::turn_towards_head(const UEVR_VRData* vr, float yaw_degrees, float delta) {
    s_recenter.elapsed += delta;
    const float alpha = (std::min)(s_recenter.elapsed / s_settings.recenter_seconds, 1.f);
    const float share = rest_share(alpha);
    const float step = alpha >= 1.f ? yaw_degrees : yaw_degrees * (1.f - share / s_recenter.rest_share);
    s_recenter.rest_share = share;
    if (alpha >= 1.f) {
        s_recenter = {};
    }
    turn_offset(vr, step);
}

void MenuAutoRecenter::reset() {
    s_in_menu = false;
    s_recenter = {};
    s_outside_seconds = 0.f;
}
