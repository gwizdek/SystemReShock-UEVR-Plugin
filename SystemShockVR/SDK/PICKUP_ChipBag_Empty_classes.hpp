#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PICKUP_ChipBag_Empty

#include "Basic.hpp"

#include "PICKUP_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PICKUP_ChipBag_Empty.PICKUP_ChipBag_Empty_C
// 0x0000 (0x0478 - 0x0478)
class APICKUP_ChipBag_Empty_C final : public APICKUP_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PICKUP_ChipBag_Empty_C">();
	}
	static class APICKUP_ChipBag_Empty_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APICKUP_ChipBag_Empty_C>();
	}
};
static_assert(alignof(APICKUP_ChipBag_Empty_C) == 0x000008, "Wrong alignment on APICKUP_ChipBag_Empty_C");
static_assert(sizeof(APICKUP_ChipBag_Empty_C) == 0x000478, "Wrong size on APICKUP_ChipBag_Empty_C");

}

