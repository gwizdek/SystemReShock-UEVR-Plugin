#include "cyberspace_body_turn.hpp"

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"

#include <cmath>

using namespace uevr;

namespace {

constexpr float kRadToDeg = 57.2957795f;
// Below this the head turn is left in the offset, so a still head does not recenter every tick.
constexpr float kMinTurnDegrees = 0.05f;
// When the head looks almost straight up or down its yaw is not defined, so nothing is moved.
// After the first tick the head's forward stays close to the avatar's, so this only matters
// when the player enters cyberspace looking straight up or down.
constexpr float kMaxForwardUp = 0.95f;

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

// A turn of the given angle around the tracking space's right axis (+X). A positive angle turns
// the forward vector up, like an Unreal pitch.
UEVR_Quaternionf turn_around_right(float radians) {
    return { .w = std::cos(radians * 0.5f), .x = std::sin(radians * 0.5f), .y = 0.f, .z = 0.f };
}

} // namespace

void CyberspaceBodyTurn::handle(SDK::APawn* avatar, const UEVR_VRData* vr) {
    try {
        if (avatar == nullptr || !vr->is_hmd_active()) {
            return;
        }

        UEVR_Vector3f hmd_position{};
        UEVR_Quaternionf hmd_rotation{};
        UEVR_Quaternionf offset{};
        vr->get_pose(vr->get_hmd_index(), &hmd_position, &hmd_rotation);
        vr->get_rotation_offset(&offset);

        const UEVR_Vector3f forward = forward_of(multiply(offset, hmd_rotation));
        if (std::fabs(forward.y) > kMaxForwardUp) {
            return;
        }

        // Unreal yaw and pitch of the head in view space: positive when the head turns right and
        // when it looks up.
        const float yaw_radians = std::atan2(forward.x, -forward.z);
        const float pitch_radians = std::atan2(forward.y, std::sqrt(forward.x * forward.x + forward.z * forward.z));
        if (std::fabs(yaw_radians * kRadToDeg) < kMinTurnDegrees && std::fabs(pitch_radians * kRadToDeg) < kMinTurnDegrees) {
            return;
        }

        // As a local rotation the rotator turns by the yaw around the avatar's up axis, then by
        // the pitch around its new right axis, so the avatar's forward ends up where the head looks.
        SDK::FHitResult unused{};
        avatar->K2_AddActorLocalRotation({ pitch_radians * kRadToDeg, yaw_radians * kRadToDeg, 0.f }, false, &unused, false);

        // The same turn is taken out of the offset, pitch first, so the view stays where it was.
        const UEVR_Quaternionf undo = multiply(turn_around_right(-pitch_radians), turn_around_up(yaw_radians));
        const UEVR_Quaternionf new_offset = multiply(undo, offset);
        vr->set_rotation_offset(&new_offset);
    }
    catch (...) {
        API::get()->log_error("[cyberspace_body_turn][handle] Exception");
    }
}
