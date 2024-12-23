#pragma once

#include "uevr/API.hpp"

using namespace uevr;

class SceneComponent : public API::UObject
{
public:
	using API::UObject::get_full_name;

	static API::UClass* static_class()
	{
		static API::UClass* class_ptr = nullptr;
		if (!class_ptr) {
			class_ptr = API::get()->find_uobject<API::UClass>(L"Class /Script/Engine.SceneComponent");
		}
		return class_ptr;
	}

	static SceneComponent* get_look_pivot_instance()
	{
		SceneComponent* camera = get_player_camera_instance();
		if (camera != nullptr) {
			// look_pivot is the atach parent of player camera
			return camera->get_attach_parent();
		}

		return nullptr;
	}

	static SceneComponent* get_player_camera_instance()
	{
		// get look_pivot traversing from camera component as there are far less instances than scene components
		API::UClass* class_ptr = API::get()->find_uobject<API::UClass>(L"Class /Script/Engine.CameraComponent");
		if (class_ptr == nullptr) {
			return nullptr;
		}

		std::vector<SceneComponent*> objects_matching = class_ptr->get_objects_matching<SceneComponent>();
		for (size_t i = 0; i < objects_matching.size(); i++) {
			std::wstring obj_name = objects_matching[i]->get_full_name();
			if (obj_name.ends_with(L".PlayerCamera"))
			{
				return objects_matching[i];
			}
		}
		return nullptr;
	}

	// Very slow !!
	static SceneComponent* get_collision_cylinder_instance()
	{
		auto class_ptr = SceneComponent::static_class();
		SceneComponent* obj_ptr = nullptr;

		if (class_ptr) {
			std::vector<SceneComponent*> objects_matching = class_ptr->get_objects_matching<SceneComponent>();
			for (size_t i = 0; i < objects_matching.size(); i++) {
				obj_ptr = objects_matching[i];

				std::wstring obj_name = obj_ptr->get_full_name();
				if (obj_name.ends_with(L".CollisionCylinder"))
				{
					return obj_ptr;
				}
			}
		}
		return nullptr;
	}

	SceneComponent* get_attach_parent()
	{
		static const auto func = SceneComponent::static_class()->find_function(L"GetAttachParent");
		if (!func) {
			API::get()->log_info("GetAttachParent not found");
			return nullptr;
		}

		struct
		{
			SceneComponent* parent;
		} params{ 0 };

		process_event(func, &params);
		return params.parent;
	}

	void detach_from_parent()
	{
		static const auto func = SceneComponent::static_class()->find_function(L"DetachFromParent");
		if (!func) {
			API::get()->log_info("DetachFromParent not found");
			return;
		}

		struct
		{
			bool bMaintainWorldPosition;
			bool bCallModify;
		} params{ .bMaintainWorldPosition = true, .bCallModify = false };

		process_event(func, &params);
	}

	void atach_to_parent(SceneComponent* parent)
	{
		static const auto atc_func = SceneComponent::static_class()->find_function(L"K2_AttachToComponent");
		if (!atc_func) {
			API::get()->log_info("K2_AttachToComponent not found");
			return;
		}

		struct
		{
			SceneComponent* parent;
			std::wstring socket_name;
			int location_rule;
			int rotation_rule;
			int scale_rule;
			bool weld_simulated_bodies;
		} params{
			.parent = parent,
			.socket_name = L"none",
			.location_rule = 2,
			.rotation_rule = 2,
			.scale_rule = 2,
			.weld_simulated_bodies = true
		};

		process_event(atc_func, &params);
	}

	void set_visibility(bool visible)
	{
		static const auto func = SceneComponent::static_class()->find_function(L"SetVisibility");
		if (!func) {
			API::get()->log_info("SetVisibility not found");
			return;
		}

		struct
		{
			bool bNewSetVisibility;
			bool bPropagateToChildren;
		} params{ .bNewSetVisibility = visible, .bPropagateToChildren = true };

		process_event(func, &params);
	}

	SDK::FRotator K2_get_component_rotation()
	{
		static const auto func = SceneComponent::static_class()->find_function(L"K2_GetComponentRotation");
		if (!func) {
			API::get()->log_error("K2_GetComponentRotation not found");
			return { 0 };
		}

		struct
		{
			SDK::FRotator rotation;
		} params{ 0 };

		process_event(func, &params);
		return params.rotation;
	}

	SDK::FVector K2_get_component_location()
	{
		static const auto func = SceneComponent::static_class()->find_function(L"K2_GetComponentLocation");
		if (!func) {
			API::get()->log_error("K2_GetComponentLocation not found");
			return { 0 };
		}

		struct
		{
			SDK::FVector location;
		} params{ 0 };

		process_event(func, &params);
		return params.location;
	}

	void K2_set_relative_rotation(const SDK::FRotator new_rotation, const bool sweep = false, const bool teleport = false)
	{
		static auto fn = SceneComponent::static_class()->find_function(L"K2_SetRelativeRotation");

		static const auto fhitresult =
			API::get()->find_uobject<API::UScriptStruct>(L"ScriptStruct /Script/Engine.HitResult");

		if (fn == nullptr) {
			API::get()->log_error("K2_SetRelativeRotation not found");
			return;
		}

		std::vector<uint8_t> rot_pitch{};
		rot_pitch.resize(sizeof(float));
		std::memcpy(rot_pitch.data(), &new_rotation.Pitch, sizeof(&new_rotation.Pitch));

		std::vector<uint8_t> rot_roll{};
		rot_roll.resize(sizeof(float));
		std::memcpy(rot_roll.data(), &new_rotation.Roll, sizeof(&new_rotation.Roll));

		std::vector<uint8_t> rot_yaw{};
		rot_yaw.resize(sizeof(float));
		std::memcpy(rot_yaw.data(), &new_rotation.Yaw, sizeof(&new_rotation.Yaw));

		// Need to dynamically allocate the params because of unknown FHitResult size
		std::vector<uint8_t> params{};

		params.insert(params.end(), rot_pitch.begin(), rot_pitch.end());
		params.insert(params.end(), rot_roll.begin(), rot_roll.end());
		params.insert(params.end(), rot_yaw.begin(), rot_yaw.end());

		// add a bool
		params.insert(params.end(), (uint8_t*)&sweep, (uint8_t*)&sweep + sizeof(bool));

		// align up to 8 based on size
		if (params.size() % sizeof(void*) != 0) {
			params.insert(params.end(), sizeof(void*) - (params.size() % sizeof(void*)), 0);
		}

		// add a FHitResult
		params.insert(params.end(), fhitresult->get_struct_size(), 0);

		// add a bool
		params.insert(params.end(), (uint8_t*)&teleport, (uint8_t*)&teleport + sizeof(bool));

		process_event(fn, params.data());
	}

	void K2_set_relative_location(const SDK::FVector new_location, const bool sweep = false, const bool teleport = false)
	{
		static auto fn = SceneComponent::static_class()->find_function(L"K2_SetRelativeLocation");

		static const auto fhitresult =
			API::get()->find_uobject<API::UScriptStruct>(L"ScriptStruct /Script/Engine.HitResult");

		if (fn == nullptr) {
			API::get()->log_error("K2_SetRelativeLocation not found");
			return;
		}

		std::vector<uint8_t> pos_x{};
		pos_x.resize(sizeof(float));
		std::memcpy(pos_x.data(), &new_location.X, sizeof(&new_location.X));

		std::vector<uint8_t> pos_y{};
		pos_y.resize(sizeof(float));
		std::memcpy(pos_y.data(), &new_location.Y, sizeof(&new_location.Y));

		std::vector<uint8_t> pos_z{};
		pos_z.resize(sizeof(float));
		std::memcpy(pos_z.data(), &new_location.Z, sizeof(&new_location.Z));

		// Need to dynamically allocate the params because of unknown FHitResult size
		std::vector<uint8_t> params{};
		params.insert(params.end(), pos_x.begin(), pos_x.end());
		params.insert(params.end(), pos_y.begin(), pos_y.end());
		params.insert(params.end(), pos_z.begin(), pos_z.end());

		// add a bool
		params.insert(params.end(), (uint8_t*)&sweep, (uint8_t*)&sweep + sizeof(bool));

		// align up to 8 based on size
		if (params.size() % sizeof(void*) != 0) {
			params.insert(params.end(), sizeof(void*) - (params.size() % sizeof(void*)), 0);
		}

		// add a FHitResult
		params.insert(params.end(), fhitresult->get_struct_size(), 0);

		// add a bool
		params.insert(params.end(), (uint8_t*)&teleport, (uint8_t*)&teleport + sizeof(bool));

		// align up to 8 based on size
		if (params.size() % sizeof(void*) != 0) {
			params.insert(params.end(), sizeof(void*) - (params.size() % sizeof(void*)), 0);
		}

		process_event(fn, params.data());
	}

	void K2_set_world_location(const SDK::FVector new_location, const bool sweep = false, const bool teleport = false)
	{
		static auto fn = SceneComponent::static_class()->find_function(L"K2_SetWorldLocation");

		static const auto fhitresult =
			API::get()->find_uobject<API::UScriptStruct>(L"ScriptStruct /Script/Engine.HitResult");

		if (fn == nullptr) {
			API::get()->log_error("K2_SetWorldLocation not found");
			return;
		}

		std::vector<uint8_t> pos_x{};
		pos_x.resize(sizeof(float));
		std::memcpy(pos_x.data(), &new_location.X, sizeof(&new_location.X));

		std::vector<uint8_t> pos_y{};
		pos_y.resize(sizeof(float));
		std::memcpy(pos_y.data(), &new_location.Y, sizeof(&new_location.Y));

		std::vector<uint8_t> pos_z{};
		pos_z.resize(sizeof(float));
		std::memcpy(pos_z.data(), &new_location.Z, sizeof(&new_location.Z));

		// Need to dynamically allocate the params because of unknown FHitResult size
		std::vector<uint8_t> params{};
		params.insert(params.end(), pos_x.begin(), pos_x.end());
		params.insert(params.end(), pos_y.begin(), pos_y.end());
		params.insert(params.end(), pos_z.begin(), pos_z.end());

		// add a bool
		params.insert(params.end(), (uint8_t*)&sweep, (uint8_t*)&sweep + sizeof(bool));

		// align up to 8 based on size
		if (params.size() % sizeof(void*) != 0) {
			params.insert(params.end(), sizeof(void*) - (params.size() % sizeof(void*)), 0);
		}

		// add a FHitResult
		params.insert(params.end(), fhitresult->get_struct_size(), 0);

		// add a bool
		params.insert(params.end(), (uint8_t*)&teleport, (uint8_t*)&teleport + sizeof(bool));

		// align up to 8 based on size
		if (params.size() % sizeof(void*) != 0) {
			params.insert(params.end(), sizeof(void*) - (params.size() % sizeof(void*)), 0);
		}

		process_event(fn, params.data());
	}

	void K2_set_world_rotation(const SDK::FRotator new_rotation, const bool sweep = false, const bool teleport = false)
	{
		static auto fn = SceneComponent::static_class()->find_function(L"K2_SetWorldRotation");

		static const auto fhitresult =
			API::get()->find_uobject<API::UScriptStruct>(L"ScriptStruct /Script/Engine.HitResult");

		if (fn == nullptr) {
			API::get()->log_error("K2_SetWorldRotation not found");
			return;
		}

		std::vector<uint8_t> rot_pitch{};
		rot_pitch.resize(sizeof(float));
		std::memcpy(rot_pitch.data(), &new_rotation.Pitch, sizeof(&new_rotation.Pitch));

		std::vector<uint8_t> rot_roll{};
		rot_roll.resize(sizeof(float));
		std::memcpy(rot_roll.data(), &new_rotation.Roll, sizeof(&new_rotation.Roll));

		std::vector<uint8_t> rot_yaw{};
		rot_yaw.resize(sizeof(float));
		std::memcpy(rot_yaw.data(), &new_rotation.Yaw, sizeof(&new_rotation.Yaw));

		// Need to dynamically allocate the params because of unknown FHitResult size
		std::vector<uint8_t> params{};

		params.insert(params.end(), rot_pitch.begin(), rot_pitch.end());
		params.insert(params.end(), rot_roll.begin(), rot_roll.end());
		params.insert(params.end(), rot_yaw.begin(), rot_yaw.end());

		// add a bool
		params.insert(params.end(), (uint8_t*)&sweep, (uint8_t*)&sweep + sizeof(bool));

		// align up to 8 based on size
		if (params.size() % sizeof(void*) != 0) {
			params.insert(params.end(), sizeof(void*) - (params.size() % sizeof(void*)), 0);
		}

		// add a FHitResult
		params.insert(params.end(), fhitresult->get_struct_size(), 0);

		// add a bool
		params.insert(params.end(), (uint8_t*)&teleport, (uint8_t*)&teleport + sizeof(bool));

		// align up to 8 based on size
		if (params.size() % sizeof(void*) != 0) {
			params.insert(params.end(), sizeof(void*) - (params.size() % sizeof(void*)), 0);
		}

		process_event(fn, params.data());
	}
};
