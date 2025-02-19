#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AMMO_ITEM_Base

#include "Basic.hpp"

#include "ITEM_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass AMMO_ITEM_Base.AMMO_ITEM_Base_C
// 0x0038 (0x0138 - 0x0100)
class UAMMO_ITEM_Base_C : public UITEM_Base_C
{
public:
	TSoftClassPtr<class UClass>                   LargePickupClass;                                  // 0x0100(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TArray<TSoftClassPtr<class UClass>>           UsedByWeapons;                                     // 0x0128(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void GetInventoryItemDetailsClass(class UClass** InventoryItemDetailsWidget);
	void GetBestPickupClass(class UClass** Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AMMO_ITEM_Base_C">();
	}
	static class UAMMO_ITEM_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAMMO_ITEM_Base_C>();
	}
};
static_assert(alignof(UAMMO_ITEM_Base_C) == 0x000008, "Wrong alignment on UAMMO_ITEM_Base_C");
static_assert(sizeof(UAMMO_ITEM_Base_C) == 0x000138, "Wrong size on UAMMO_ITEM_Base_C");
static_assert(offsetof(UAMMO_ITEM_Base_C, LargePickupClass) == 0x000100, "Member 'UAMMO_ITEM_Base_C::LargePickupClass' has a wrong offset!");
static_assert(offsetof(UAMMO_ITEM_Base_C, UsedByWeapons) == 0x000128, "Member 'UAMMO_ITEM_Base_C::UsedByWeapons' has a wrong offset!");

}

