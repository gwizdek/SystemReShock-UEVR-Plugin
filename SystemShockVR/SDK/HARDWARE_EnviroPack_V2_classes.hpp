#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HARDWARE_EnviroPack_V2

#include "Basic.hpp"

#include "HARDWARE_EnviroPack_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass HARDWARE_EnviroPack_V2.HARDWARE_EnviroPack_V2_C
// 0x0000 (0x02C0 - 0x02C0)
class UHARDWARE_EnviroPack_V2_C final : public UHARDWARE_EnviroPack_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"HARDWARE_EnviroPack_V2_C">();
	}
	static class UHARDWARE_EnviroPack_V2_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UHARDWARE_EnviroPack_V2_C>();
	}
};
static_assert(alignof(UHARDWARE_EnviroPack_V2_C) == 0x000008, "Wrong alignment on UHARDWARE_EnviroPack_V2_C");
static_assert(sizeof(UHARDWARE_EnviroPack_V2_C) == 0x0002C0, "Wrong size on UHARDWARE_EnviroPack_V2_C");

}

