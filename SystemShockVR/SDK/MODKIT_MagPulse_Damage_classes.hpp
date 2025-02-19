#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MODKIT_MagPulse_Damage

#include "Basic.hpp"

#include "ITEM_WeaponModKit_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass MODKIT_MagPulse_Damage.MODKIT_MagPulse_Damage_C
// 0x0000 (0x0238 - 0x0238)
class UMODKIT_MagPulse_Damage_C final : public UITEM_WeaponModKit_Base_C
{
public:
	void TryApplyWeaponModifications(class UITEM_WeaponBase_C* Weapon, bool DuringInitialization, bool* Result);
	void HasAppearanceChange(bool* Result);
	void GetModifiedWeaponMode(const struct FSTRUCT_WeaponMode& WeaponMode, struct FSTRUCT_WeaponMode* ResultMode);
	void TryModifyPickupAppearance(class APICKUP_Weapon_Base_C* WeaponPickup, bool* Result);
	void GetFirstPersonAttachment(class UStaticMesh** Mesh, struct FTransform* Transform, class FName* SocketName);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MODKIT_MagPulse_Damage_C">();
	}
	static class UMODKIT_MagPulse_Damage_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMODKIT_MagPulse_Damage_C>();
	}
};
static_assert(alignof(UMODKIT_MagPulse_Damage_C) == 0x000008, "Wrong alignment on UMODKIT_MagPulse_Damage_C");
static_assert(sizeof(UMODKIT_MagPulse_Damage_C) == 0x000238, "Wrong size on UMODKIT_MagPulse_Damage_C");

}

