#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MODKIT_Minipistol_Burst

#include "Basic.hpp"

#include "ITEM_WeaponModKit_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass MODKIT_Minipistol_Burst.MODKIT_Minipistol_Burst_C
// 0x0000 (0x0238 - 0x0238)
class UMODKIT_Minipistol_Burst_C final : public UITEM_WeaponModKit_Base_C
{
public:
	void TryApplyWeaponModifications(class UITEM_WeaponBase_C* Weapon, bool DuringInitialization, bool* Result);
	void GetModifiedWeaponMode(const struct FSTRUCT_WeaponMode& WeaponMode, struct FSTRUCT_WeaponMode* ResultMode);
	void TryModifyPickupAppearance(class APICKUP_Weapon_Base_C* WeaponPickup, bool* Result);
	void GetFirstPersonAttachment(class UStaticMesh** Mesh, struct FTransform* Transform, class FName* SocketName);
	void HasAppearanceChange(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MODKIT_Minipistol_Burst_C">();
	}
	static class UMODKIT_Minipistol_Burst_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMODKIT_Minipistol_Burst_C>();
	}
};
static_assert(alignof(UMODKIT_Minipistol_Burst_C) == 0x000008, "Wrong alignment on UMODKIT_Minipistol_Burst_C");
static_assert(sizeof(UMODKIT_Minipistol_Burst_C) == 0x000238, "Wrong size on UMODKIT_Minipistol_Burst_C");

}

