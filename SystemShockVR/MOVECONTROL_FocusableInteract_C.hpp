#pragma once

#include "uevr/API.hpp"

using namespace uevr;

class MOVECONTROL_FocusableInteract_C : public API::UObject
{
public:
	using API::UObject::get_full_name;

	static API::UClass* static_class()
	{
		static API::UClass* result = nullptr;
		if (!result) {
			result = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Blueprints/Interactables/MOVECONTROL_FocusableInteract.MOVECONTROL_FocusableInteract_C");
		}
		return result;
	}

	static void disable_character_focusable_interactions()
	{
		API::get()->log_info("disable_character_focusable_interactions");
		auto klass = MOVECONTROL_FocusableInteract_C::static_class();
		if (klass) {
			API::get()->log_info("disable_character_focusable_interactions : class found");
			API::UObject* cdo = klass->get_class_default_object();
			if (cdo) {
				API::get()->log_info("disable_character_focusable_interactions : cdo found : disabling...");
				cdo->set_bool_property(L"ShouldUseCharacterMovement", true);
				cdo->set_bool_property(L"IsFinishedTransitioning", true);
			}
		}
	}

	static MOVECONTROL_FocusableInteract_C* get_instance()
	{
		auto klass = MOVECONTROL_FocusableInteract_C::static_class();
		MOVECONTROL_FocusableInteract_C* Object = nullptr;

		if (klass) {

			std::vector<MOVECONTROL_FocusableInteract_C*> List = klass->get_objects_matching<MOVECONTROL_FocusableInteract_C>();

			for (size_t i = 0; i < List.size(); i++) {
				Object = List[i];

				std::wstring ObjName = Object->get_full_name();
				// API::get()->log_info("MOVECONTROL_FocusableInteract_C: Object %d of %d, Object name: %ls", i, List.size(), ObjName.c_str());

				if (ObjName.find(L"MOVECONTROL_FocusableInteract_C") != std::wstring::npos)
				{
					return Object;
				}
			}
			return nullptr;
		}
		return nullptr;
	}

	bool get_ShouldUseCharacterMovement()
	{
		return get_bool_property(L"ShouldUseCharacterMovement");
	}

	bool get_IsExpiring()
	{
		return get_bool_property(L"IsExpiring");
	}
};
