#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PICKUP_GasGrenade

#include "Basic.hpp"

#include "PICKUP_Explosive_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PICKUP_GasGrenade.PICKUP_GasGrenade_C
// 0x0000 (0x0498 - 0x0498)
class APICKUP_GasGrenade_C final : public APICKUP_Explosive_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PICKUP_GasGrenade_C">();
	}
	static class APICKUP_GasGrenade_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APICKUP_GasGrenade_C>();
	}
};
static_assert(alignof(APICKUP_GasGrenade_C) == 0x000008, "Wrong alignment on APICKUP_GasGrenade_C");
static_assert(sizeof(APICKUP_GasGrenade_C) == 0x000498, "Wrong size on APICKUP_GasGrenade_C");

}

