#include "vr_data_sampling.hpp"

using namespace uevr;

void ImGuiLogs::imgui_draw_vector(const char* label, UEVR_Vector3f* vec) {
	if (vec == nullptr) {
		return;
	}
	float vec_arr[3] = { vec->x, vec->y, vec->z };
	ImGui::DragFloat3(label, vec_arr);
	/*if (ImGui::Begin("System Shock VR")) {
	}
	ImGui::End();*/
}

void ImGuiLogs::imgui_draw_rotator(const char* label, UEVR_Rotatorf* rot) {
	if (rot == nullptr) {
		return;
	}
	float rot_arr[3] = { rot->pitch, rot->yaw, rot->roll };
	ImGui::DragFloat3(label, rot_arr);
	/*if (ImGui::Begin("System Shock VR")) {
	}
	ImGui::End();*/
}

void ImGuiLogs::imgui_draw_quaternion(const char* label, UEVR_Quaternionf* quat) {
	if (quat == nullptr) {
		return;
	}
	float quat_arr[4] = { quat->w, quat->x, quat->y, quat->z };
	if (ImGui::Begin("System Shock VR")) {
		ImGui::DragFloat4(label, quat_arr);
	}
	ImGui::End();
}

void ImGuiLogs::sample_hmd_pose(const UEVR_VRData* vr) {
	UEVR_Vector3f pos;
	UEVR_Quaternionf hmd_q;

	vr->get_pose(vr->get_hmd_index(), (UEVR_Vector3f*)&pos, (UEVR_Quaternionf*)&hmd_q);
	// vr->get_pose(vr->get_right_controller_index(), &right_position, &right_rotation);

	ImGuiLogs::imgui_draw_vector("HMD Pose - pos", &pos);
	ImGuiLogs::imgui_draw_quaternion("HMD Pose - quat", &hmd_q);
}

void ImGuiLogs::sample_vr_rot_offset(const UEVR_VRData* vr) {
	//glm::quat rot_offset{};
	UEVR_Quaternionf rot_offset;
	vr->get_rotation_offset((UEVR_Quaternionf*)&rot_offset);
	ImGuiLogs::imgui_draw_quaternion("HMD Rotation offset", &rot_offset);
}



//	const UEVR_VRData* vr = API::get()->param()->vr;
//	sample_hmd_pose(vr);
//	sample_vr_rot_offset(vr);

//	UEVR_Vector3f origin;
//	vr->get_standing_origin(&origin);
//	imgui_draw_vector("Standing origin", &origin);

//	const auto look_pivot = SceneComponent::get_look_pivot_instance();
//	if (look_pivot != nullptr) {
//		FVector location = look_pivot->K2_get_component_location();
//		UEVR_Vector3f loc = { location.X, location.Y, location.Z };
//		imgui_draw_vector("look_pivot loc", &loc);

//		FRotator rotation = look_pivot->K2_get_component_rotation();
//		UEVR_Rotatorf rot = { rotation.Pitch, rotation.Yaw, rotation.Roll };
//		imgui_draw_rotator("look_pivot rot", &rot);

//		//FRotator mod_rot = { 25.0f, rotation.Yaw, rotation.Roll };
//		//look_pivot->K2_set_world_rotation(mod_rot);
//	}

//	const auto arms_mesh = ArmsMesh::get_instance();
//	if (arms_mesh != nullptr) {
//		FVector location = arms_mesh->K2_get_component_location();
//		UEVR_Vector3f loc = { location.X, location.Y, location.Z };
//		imgui_draw_vector("arms_mesh loc", &loc);

//		FRotator rotation = arms_mesh->K2_get_component_rotation();
//		UEVR_Rotatorf rot = { rotation.Pitch, rotation.Yaw, rotation.Roll };
//		imgui_draw_rotator("arms_mesh rot", &rot);
//	}

//	if (vr->is_using_controllers()) {
//		UEVR_Vector3f right_hand_position{};
//		UEVR_Quaternionf right_hand_rotation{};
//		vr->get_grip_pose(vr->get_right_controller_index(), (UEVR_Vector3f*)&right_hand_position, (UEVR_Quaternionf*)&right_hand_rotation);

//		imgui_draw_vector("R Controller loc", &right_hand_position);
//		imgui_draw_quaternion("R Controller quat", &right_hand_rotation);


//		glm::quat q(right_hand_rotation.w, right_hand_rotation.x, right_hand_rotation.y, right_hand_rotation.z);
//		auto euler = glm::degrees(utility::math::euler_angles_from_steamvr(q));

//		UEVR_Vector3f euler_vec = { euler[0], euler[1], euler[2] };
//		imgui_draw_vector("R Controller euler", &euler_vec);
//		
//	}
//}


// ********************************************************************************************************
		//if (vr->is_using_controllers()) {
		//	UEVR_Vector3f right_hand_position{};
		//	UEVR_Quaternionf right_hand_rotation{};
		//	vr->get_grip_pose(vr->get_right_controller_index(), (UEVR_Vector3f*)&right_hand_position, (UEVR_Quaternionf*)&right_hand_rotation);

		//	const auto look_pivot = SceneComponent::get_look_pivot_instance();
		//	if (look_pivot != nullptr) {
		//		FVector location = look_pivot->K2_get_component_location();
		//		FRotator rotation = look_pivot->K2_get_component_rotation();
		//		//FRotator mod_rot = { 25.0f, rotation.Yaw, rotation.Roll };


		//		glm::quat q(right_hand_rotation.w, right_hand_rotation.x, right_hand_rotation.y, right_hand_rotation.z);
		//		auto euler = glm::degrees(utility::math::euler_angles_from_steamvr(q));
		//		FRotator mod_rot = { euler[0] - 30.0f, rotation.Yaw, rotation.Roll};
		//		//look_pivot->K2_set_world_rotation(mod_rot);
		//	}
		//}
// ********************************************************************************************************
