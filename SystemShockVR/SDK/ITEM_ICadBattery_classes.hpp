#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ITEM_ICadBattery

#include "Basic.hpp"

#include "ITEM_BatteryPack_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass ITEM_ICadBattery.ITEM_ICadBattery_C
// 0x0000 (0x0280 - 0x0280)
class UITEM_ICadBattery_C final : public UITEM_BatteryPack_C
{
public:
	void GetEffects(class FText* EffectsText);
	void UseConsumable(class APAWN_SystemShockCharacter_C* Character, class UITEM_ConsumableBase_C** ConsumedItem);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ITEM_ICadBattery_C">();
	}
	static class UITEM_ICadBattery_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UITEM_ICadBattery_C>();
	}
};
static_assert(alignof(UITEM_ICadBattery_C) == 0x000008, "Wrong alignment on UITEM_ICadBattery_C");
static_assert(sizeof(UITEM_ICadBattery_C) == 0x000280, "Wrong size on UITEM_ICadBattery_C");

}

