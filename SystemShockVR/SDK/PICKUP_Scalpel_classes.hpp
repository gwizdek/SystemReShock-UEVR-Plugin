#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PICKUP_Scalpel

#include "Basic.hpp"

#include "PICKUP_Junk_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PICKUP_Scalpel.PICKUP_Scalpel_C
// 0x0000 (0x0478 - 0x0478)
class APICKUP_Scalpel_C final : public APICKUP_Junk_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PICKUP_Scalpel_C">();
	}
	static class APICKUP_Scalpel_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APICKUP_Scalpel_C>();
	}
};
static_assert(alignof(APICKUP_Scalpel_C) == 0x000008, "Wrong alignment on APICKUP_Scalpel_C");
static_assert(sizeof(APICKUP_Scalpel_C) == 0x000478, "Wrong size on APICKUP_Scalpel_C");

}

