#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PICKUP_AMMO_Base

#include "Basic.hpp"

#include "PICKUP_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PICKUP_AMMO_Base.PICKUP_AMMO_Base_C
// 0x0008 (0x0480 - 0x0478)
class APICKUP_AMMO_Base_C : public APICKUP_Base_C
{
public:
	uint8                                         Pad_474[0x4];                                      // 0x0474(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UBoxComponent*                          ScanBox;                                           // 0x0478(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	void GetItemDisplayName(class FText* Result);
	void GetAmmoCount(int32* Result);
	void GetDefaultDescription(class FText* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PICKUP_AMMO_Base_C">();
	}
	static class APICKUP_AMMO_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APICKUP_AMMO_Base_C>();
	}
};
static_assert(alignof(APICKUP_AMMO_Base_C) == 0x000008, "Wrong alignment on APICKUP_AMMO_Base_C");
static_assert(sizeof(APICKUP_AMMO_Base_C) == 0x000480, "Wrong size on APICKUP_AMMO_Base_C");
static_assert(offsetof(APICKUP_AMMO_Base_C, ScanBox) == 0x000478, "Member 'APICKUP_AMMO_Base_C::ScanBox' has a wrong offset!");

}

