#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PICKUP_EMPGrenade

#include "Basic.hpp"

#include "PICKUP_Explosive_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PICKUP_EMPGrenade.PICKUP_EMPGrenade_C
// 0x0000 (0x0498 - 0x0498)
class APICKUP_EMPGrenade_C final : public APICKUP_Explosive_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PICKUP_EMPGrenade_C">();
	}
	static class APICKUP_EMPGrenade_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APICKUP_EMPGrenade_C>();
	}
};
static_assert(alignof(APICKUP_EMPGrenade_C) == 0x000008, "Wrong alignment on APICKUP_EMPGrenade_C");
static_assert(sizeof(APICKUP_EMPGrenade_C) == 0x000498, "Wrong size on APICKUP_EMPGrenade_C");

}

