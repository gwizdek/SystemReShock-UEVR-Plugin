#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PICKUP_CrewCap

#include "Basic.hpp"

#include "PICKUP_Junk_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PICKUP_CrewCap.PICKUP_CrewCap_C
// 0x0000 (0x0478 - 0x0478)
class APICKUP_CrewCap_C final : public APICKUP_Junk_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PICKUP_CrewCap_C">();
	}
	static class APICKUP_CrewCap_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APICKUP_CrewCap_C>();
	}
};
static_assert(alignof(APICKUP_CrewCap_C) == 0x000008, "Wrong alignment on APICKUP_CrewCap_C");
static_assert(sizeof(APICKUP_CrewCap_C) == 0x000478, "Wrong size on APICKUP_CrewCap_C");

}

