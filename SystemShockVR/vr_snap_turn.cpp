#include "vr_snap_turn.hpp"

#include <cmath>

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"

using namespace uevr;

namespace {

// A snap turn is at least 10 degrees (the options page minimum). A smaller change in the
// window is something else and is ignored.
constexpr float kMinSnapYaw = 1.f;

// The difference a - b in -180..180, so a turn across the 0/360 border stays small.
float yaw_difference(float a, float b) {
    float difference = std::fmod(a - b, 360.f);
    if (difference > 180.f) difference -= 360.f;
    if (difference < -180.f) difference += 360.f;
    return difference;
}

} // anonymous namespace

float VRSnapTurn::s_yaw_before{ 0.f };
bool VRSnapTurn::s_has_yaw_before{ false };
float VRSnapTurn::s_pending_yaw{ 0.f };

// Asks UEVR for the controller each time, as UEVR itself does, so no pointer outlives a level.
float VRSnapTurn::current_yaw(bool& found) {
    auto* controller = reinterpret_cast<SDK::AController*>(API::get()->get_player_controller(0));
    found = controller != nullptr;
    return found ? controller->ControlRotation.Yaw : 0.f;
}

void VRSnapTurn::before_view_offset() {
    s_has_yaw_before = false;
    if (!API::VR::is_snap_turn_enabled()) return;
    s_yaw_before = current_yaw(s_has_yaw_before);
}

void VRSnapTurn::after_view_offset() {
    if (!s_has_yaw_before) return;
    s_has_yaw_before = false;
    bool found = false;
    const float yaw_after = current_yaw(found);
    if (!found) return;
    const float snap = yaw_difference(yaw_after, s_yaw_before);
    if (std::abs(snap) < kMinSnapYaw) return;
    s_pending_yaw += snap;
}

float VRSnapTurn::consume_yaw() {
    const float yaw = s_pending_yaw;
    s_pending_yaw = 0.f;
    return yaw;
}
