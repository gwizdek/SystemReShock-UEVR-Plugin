#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HANDHELD_ICadBatteryManager

#include "Basic.hpp"

#include "ITEM_HandheldBattery_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass HANDHELD_ICadBatteryManager.HANDHELD_ICadBatteryManager_C
// 0x0000 (0x0410 - 0x0410)
class UHANDHELD_ICadBatteryManager_C final : public UITEM_HandheldBattery_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"HANDHELD_ICadBatteryManager_C">();
	}
	static class UHANDHELD_ICadBatteryManager_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UHANDHELD_ICadBatteryManager_C>();
	}
};
static_assert(alignof(UHANDHELD_ICadBatteryManager_C) == 0x000008, "Wrong alignment on UHANDHELD_ICadBatteryManager_C");
static_assert(sizeof(UHANDHELD_ICadBatteryManager_C) == 0x000410, "Wrong size on UHANDHELD_ICadBatteryManager_C");

}

