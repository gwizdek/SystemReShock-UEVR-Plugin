#pragma once

#include "uevr/API.hpp"

using namespace uevr;

class INTERACT_Laptop_C : public API::UObject
{
public:
	using API::UObject::get_full_name;

	static API::UClass* static_class()
	{
		static API::UClass* class_ptr = nullptr;
		if (class_ptr == nullptr) {
		}
		return class_ptr;
	}

	static INTERACT_Laptop_C* get_instance()
	{
		//auto laptop_c = INTERACT_Laptop_C::static_class();
		API::UClass* laptop_c = API::get()->find_uobject<API::UClass>(L"BlueprintGeneratedClass /Game/Art/Props/Hacker_Apartment/Laptop/INTERACT_Laptop.INTERACT_Laptop_C");

		if (laptop_c != nullptr) {
			//API::get()->log_info("found class");
			std::vector<INTERACT_Laptop_C*> objs = laptop_c->get_objects_matching<INTERACT_Laptop_C>();
			//API::get()->log_info("found objects %d", objs.size());
			for (size_t i = 0; i < objs.size(); i++) {
				API::get()->log_info("object name %ls", objs[i]->get_full_name().c_str());
				if (objs[i]->get_full_name().find(L".INTERACT_Laptop_") != std::wstring::npos) {
					return objs[i];
				}
			}
			return nullptr;

			//return laptop_c->get_first_object_matching<INTERACT_Laptop_C>();
		}
		return nullptr;
	}

	bool is_interacting()
	{
		//API::get()->log_info("IS interacting");
		return get_bool_property(L"IsInteracting");
	}
};
