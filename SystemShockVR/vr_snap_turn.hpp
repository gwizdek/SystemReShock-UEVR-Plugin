#pragma once

// Measures UEVR's snap turns, so the VR body can turn by the same angle in the same frame as
// the view.
//
// UEVR applies a snap turn in its CalculateStereoViewOffset hook (VR::process_snapturn): it adds
// the angle to the yaw of player controller 0's ControlRotation. That happens after the plugins'
// on_pre_calculate_stereo_view_offset and before their on_post_calculate_stereo_view_offset, so
// the yaw change between the two callbacks is the snap. The view of that frame was already set
// up from the old rotation; the camera turns in the next frame. So the plugin turns the body at
// the start of the next engine tick, through consume_yaw.
class VRSnapTurn final
{
public:
    // Called from the plugin's pre and post CalculateStereoViewOffset callbacks.
    static void before_view_offset();
    static void after_view_offset();
    // The snap yaw in degrees since the last call, then zero. Called once per engine tick.
    static float consume_yaw();

private:
    static float current_yaw(bool& found);

    static float s_yaw_before;
    static bool s_has_yaw_before;
    static float s_pending_yaw;
};
