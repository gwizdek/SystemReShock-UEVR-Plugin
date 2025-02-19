#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PICKUP_Weapon_Base

#include "Basic.hpp"

#include "PICKUP_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PICKUP_Weapon_Base.PICKUP_Weapon_Base_C
// 0x0010 (0x0488 - 0x0478)
class APICKUP_Weapon_Base_C : public APICKUP_Base_C
{
public:
	uint8                                         Pad_474[0x4];                                      // 0x0474(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UITEM_WeaponModKit_Base_C*>      AppearanceModifiers;                               // 0x0478(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void SetItem(class UITEM_Base_C* InItem);
	void SetIconClassCollection(const struct FObjectClassCollection& ClassCollection);
	void UpdateWeaponPickupAppearance();
	void GetRenderIconClassCollection(struct FObjectClassCollection* Result);
	void TryInitializeItemInstance();
	void UpdateMeshEmissiveStrength(float Scale);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PICKUP_Weapon_Base_C">();
	}
	static class APICKUP_Weapon_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APICKUP_Weapon_Base_C>();
	}
};
static_assert(alignof(APICKUP_Weapon_Base_C) == 0x000008, "Wrong alignment on APICKUP_Weapon_Base_C");
static_assert(sizeof(APICKUP_Weapon_Base_C) == 0x000488, "Wrong size on APICKUP_Weapon_Base_C");
static_assert(offsetof(APICKUP_Weapon_Base_C, AppearanceModifiers) == 0x000478, "Member 'APICKUP_Weapon_Base_C::AppearanceModifiers' has a wrong offset!");

}

