#pragma once

#include "uevr/API.h"

// Recenters the VR view in the title menu and in every pause menu when the player looks away.
//
// The menus are drawn on UEVR's UI plane, which UEVR places in front of the view's forward
// direction. A player who turns away from it in a menu would have to find the recenter button.
// Each tick this takes the head's yaw in view space (rotation offset x HMD rotation). When it
// stays above menu_recenter_angle degrees for menu_recenter_delay seconds, the view is turned
// back to the head, so the menu is in front of the player again. The three menu_recenter_* values
// are in [general] of system_reshock_vr_config.ini, with no row on the VR options page. They are
// read each time a menu opens.
//
// With menu_recenter_duration 0, UEVR's recenter_view() does it at once. Otherwise the yaw goes
// out of UEVR's rotation offset over that many seconds, fast at first and slower towards the
// end. The yaw still to turn is measured again every tick, so the turn ends facing the head even
// when the head moves meanwhile.
class MenuAutoRecenter final
{
public:
    // Once per engine tick. In_menu is true in GAME_STATE_MAIN_MENU and GAME_STATE_PAUSE_MENU.
    // Outside a menu it stops a turn and forgets the time spent looking away.
    static void handle_tick(const UEVR_VRData* vr, bool in_menu, float delta);

private:
    static void start_recenter(const UEVR_VRData* vr, float yaw_degrees);
    static void turn_towards_head(const UEVR_VRData* vr, float yaw_degrees, float delta);
    static void reset();
};
