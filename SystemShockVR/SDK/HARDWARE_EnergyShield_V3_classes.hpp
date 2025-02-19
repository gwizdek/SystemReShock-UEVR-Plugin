#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HARDWARE_EnergyShield_V3

#include "Basic.hpp"

#include "HARDWARE_EnergyShield_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass HARDWARE_EnergyShield_V3.HARDWARE_EnergyShield_V3_C
// 0x0000 (0x02C0 - 0x02C0)
class UHARDWARE_EnergyShield_V3_C final : public UHARDWARE_EnergyShield_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"HARDWARE_EnergyShield_V3_C">();
	}
	static class UHARDWARE_EnergyShield_V3_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UHARDWARE_EnergyShield_V3_C>();
	}
};
static_assert(alignof(UHARDWARE_EnergyShield_V3_C) == 0x000008, "Wrong alignment on UHARDWARE_EnergyShield_V3_C");
static_assert(sizeof(UHARDWARE_EnergyShield_V3_C) == 0x0002C0, "Wrong size on UHARDWARE_EnergyShield_V3_C");

}

