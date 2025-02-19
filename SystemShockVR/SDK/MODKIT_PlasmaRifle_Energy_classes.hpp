#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MODKIT_PlasmaRifle_Energy

#include "Basic.hpp"

#include "ITEM_WeaponModKit_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass MODKIT_PlasmaRifle_Energy.MODKIT_PlasmaRifle_Energy_C
// 0x0000 (0x0238 - 0x0238)
class UMODKIT_PlasmaRifle_Energy_C final : public UITEM_WeaponModKit_Base_C
{
public:
	void TryApplyWeaponModifications(class UITEM_WeaponBase_C* Weapon, bool DuringInitialization, bool* Result);
	void GetModifiedWeaponMode(const struct FSTRUCT_WeaponMode& WeaponMode, struct FSTRUCT_WeaponMode* ResultMode);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MODKIT_PlasmaRifle_Energy_C">();
	}
	static class UMODKIT_PlasmaRifle_Energy_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMODKIT_PlasmaRifle_Energy_C>();
	}
};
static_assert(alignof(UMODKIT_PlasmaRifle_Energy_C) == 0x000008, "Wrong alignment on UMODKIT_PlasmaRifle_Energy_C");
static_assert(sizeof(UMODKIT_PlasmaRifle_Energy_C) == 0x000238, "Wrong size on UMODKIT_PlasmaRifle_Energy_C");

}

