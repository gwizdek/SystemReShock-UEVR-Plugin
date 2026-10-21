#include "cyberspace_head_steering.hpp"

#include <chrono>
#include <cmath>

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"

#include "plugin_utils.hpp"

using namespace uevr;

namespace {

constexpr float kStickMax = 32767.f;
// XInput's own left stick deadzone, as part of the full range. The game normalizes the move
// input, so a stick inside this would still fly at full speed.
constexpr float kStickDeadzone = XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE / kStickMax;
// A stick reading older than this is not used, so the avatar stops when the XInput callback
// stops, for example when the controllers sleep.
constexpr auto kMaxStickAge = std::chrono::milliseconds(250);

struct Stick
{
    float forward{ 0.f };
    float right{ 0.f };
    // +1 while A (ascend) is held, -1 while B (descend) is held, 0 for both or neither.
    float up{ 0.f };
    std::chrono::steady_clock::time_point read_at{};
};

Stick s_stick{};

// UEVR_Quaternionf is declared w, x, y, z, so it is always filled by name.
UEVR_Quaternionf multiply(const UEVR_Quaternionf& a, const UEVR_Quaternionf& b) {
    return {
        .w = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z,
        .x = a.w * b.x + a.x * b.w + a.y * b.z - a.z * b.y,
        .y = a.w * b.y - a.x * b.z + a.y * b.w + a.z * b.x,
        .z = a.w * b.z + a.x * b.y - a.y * b.x + a.z * b.w
    };
}

// The head's pitch against the avatar, in radians, positive up. The view is avatar rotation x
// rotation offset x HMD rotation, so the head's forward in the avatar's frame is the forward
// vector of offset x HMD. UEVR's tracking axes are -Z forward, +Y up, +X right.
float head_pitch(const UEVR_VRData* vr) {
    UEVR_Vector3f hmd_position{};
    UEVR_Quaternionf hmd_rotation{};
    UEVR_Quaternionf offset{};
    vr->get_pose(vr->get_hmd_index(), &hmd_position, &hmd_rotation);
    vr->get_rotation_offset(&offset);
    const UEVR_Quaternionf q = multiply(offset, hmd_rotation);
    const float x = -2.f * (q.x * q.z + q.w * q.y);
    const float y = -2.f * (q.y * q.z - q.w * q.x);
    const float z = -(1.f - 2.f * (q.x * q.x + q.y * q.y));
    return std::atan2(y, std::sqrt(x * x + z * z));
}

bool stick_is_fresh() {
    return std::chrono::steady_clock::now() - s_stick.read_at < kMaxStickAge;
}

float button_value(WORD buttons, WORD button) {
    return (buttons & button) != 0 ? 1.f : 0.f;
}

} // namespace

void CyberspaceHeadSteering::handle_input(XINPUT_STATE* state) {
    const float forward = state->Gamepad.sThumbLY / kStickMax;
    const float right = state->Gamepad.sThumbLX / kStickMax;
    const bool outside_deadzone = std::hypot(forward, right) > kStickDeadzone;
    const WORD buttons = state->Gamepad.wButtons;
    s_stick = {
        .forward = outside_deadzone ? forward : 0.f,
        .right = outside_deadzone ? right : 0.f,
        .up = button_value(buttons, XINPUT_GAMEPAD_A) - button_value(buttons, XINPUT_GAMEPAD_B),
        .read_at = std::chrono::steady_clock::now()
    };
    state->Gamepad.sThumbLX = 0;
    state->Gamepad.sThumbLY = 0;
}

void CyberspaceHeadSteering::handle_tick(SDK::APawn* avatar, const UEVR_VRData* vr) {
    try {
        if (avatar == nullptr || !PluginUtils::is_a<SDK::APAWN_Avatar_C>(avatar)) {
            return;
        }
        auto* pawn = static_cast<SDK::APAWN_Avatar_C*>(avatar);
        if (!stick_is_fresh() || !vr->is_hmd_active()) {
            pawn->PersistentRelativeInput = { 0.f, 0.f, 0.f };
            return;
        }
        // The stick's forward part goes along the head's pitch; its right part stays level.
        // A and B add straight up or down, as the game's own ascend and descend do.
        const float pitch = head_pitch(vr);
        pawn->PersistentRelativeInput = {
            s_stick.forward * std::cos(pitch),
            s_stick.right,
            s_stick.forward * std::sin(pitch) + s_stick.up
        };
    }
    catch (...) {
        API::get()->log_error("[cyberspace_head_steering][handle_tick] Exception");
    }
}
