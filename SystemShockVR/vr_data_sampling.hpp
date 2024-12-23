#pragma once

#include "uevr/API.hpp"
#include "Math.hpp"

#include "imgui/imgui.h"

namespace ImGuiLogs {

	void imgui_draw_vector(const char* label, UEVR_Vector3f* vec);
	void imgui_draw_rotator(const char* label, UEVR_Rotatorf* rot);
	void imgui_draw_quaternion(const char* label, UEVR_Quaternionf* quat);
	void sample_hmd_pose(const UEVR_VRData* vr);
	void sample_vr_rot_offset(const UEVR_VRData* vr);

}
