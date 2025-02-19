#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ITEM_Cybershield_Base

#include "Basic.hpp"

#include "AttributeSystem_structs.hpp"
#include "ITEM_Software_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass ITEM_Cybershield_Base.ITEM_Cybershield_Base_C
// 0x00A0 (0x0280 - 0x01E0)
class UITEM_Cybershield_Base_C final : public UITEM_Software_Base_C
{
public:
	struct FAttribModApplyData                    InvincibilityMod;                                  // 0x01E0(0x00A0)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void OnAddedToInventory();
	void Activate(class APAWN_SystemShockCharacter_C* Character, bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ITEM_Cybershield_Base_C">();
	}
	static class UITEM_Cybershield_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UITEM_Cybershield_Base_C>();
	}
};
static_assert(alignof(UITEM_Cybershield_Base_C) == 0x000008, "Wrong alignment on UITEM_Cybershield_Base_C");
static_assert(sizeof(UITEM_Cybershield_Base_C) == 0x000280, "Wrong size on UITEM_Cybershield_Base_C");
static_assert(offsetof(UITEM_Cybershield_Base_C, InvincibilityMod) == 0x0001E0, "Member 'UITEM_Cybershield_Base_C::InvincibilityMod' has a wrong offset!");

}

