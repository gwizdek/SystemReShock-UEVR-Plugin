#include "cyberspace_body_turn.hpp"

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"

#include <cmath>

using namespace uevr;

namespace {

constexpr float kRadToDeg = 57.2957795f;
// Below this the head yaw is left in the offset, so a still head does not recenter every tick.
constexpr float kMinYawDegrees = 0.05f;
// When the head looks almost straight up or down its yaw is not defined, so nothing is moved.
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

        // Unreal yaw of the head in view space: positive when the head turns right.
        const float yaw_radians = std::atan2(forward.x, -forward.z);
        if (std::fabs(yaw_radians * kRadToDeg) < kMinYawDegrees) {
            return;
        }

        SDK::FHitResult unused{};
        avatar->K2_AddActorLocalRotation({ 0.f, yaw_radians * kRadToDeg, 0.f }, false, &unused, false);

        // Turning the offset by the same yaw the other way keeps the view where it was.
        const UEVR_Quaternionf new_offset = multiply(turn_around_up(yaw_radians), offset);
        vr->set_rotation_offset(&new_offset);
    }
    catch (...) {
        API::get()->log_error("[cyberspace_body_turn][handle] Exception");
    }
}
