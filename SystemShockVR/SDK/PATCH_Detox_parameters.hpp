#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PATCH_Detox

#include "Basic.hpp"


namespace SDK::Params
{

// Function PATCH_Detox.PATCH_Detox_C.GetEffects
// 0x0030 (0x0030 - 0x0000)
struct PATCH_Detox_C_GetEffects final
{
public:
	class FText                                   EffectsText;                                       // 0x0000(0x0018)(Parm, OutParm)
	class FText                                   CallFunc_MakeLiteralText_ReturnValue;              // 0x0018(0x0018)()
};
static_assert(alignof(PATCH_Detox_C_GetEffects) == 0x000008, "Wrong alignment on PATCH_Detox_C_GetEffects");
static_assert(sizeof(PATCH_Detox_C_GetEffects) == 0x000030, "Wrong size on PATCH_Detox_C_GetEffects");
static_assert(offsetof(PATCH_Detox_C_GetEffects, EffectsText) == 0x000000, "Member 'PATCH_Detox_C_GetEffects::EffectsText' has a wrong offset!");
static_assert(offsetof(PATCH_Detox_C_GetEffects, CallFunc_MakeLiteralText_ReturnValue) == 0x000018, "Member 'PATCH_Detox_C_GetEffects::CallFunc_MakeLiteralText_ReturnValue' has a wrong offset!");

// Function PATCH_Detox.PATCH_Detox_C.GetDuration
// 0x0038 (0x0038 - 0x0000)
struct PATCH_Detox_C_GetDuration final
{
public:
	class FText                                   DurationText;                                      // 0x0000(0x0018)(Parm, OutParm)
	int32                                         CallFunc_Round_ReturnValue;                        // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_GetDefaultPatchDurationText_Text;         // 0x0020(0x0018)()
};
static_assert(alignof(PATCH_Detox_C_GetDuration) == 0x000008, "Wrong alignment on PATCH_Detox_C_GetDuration");
static_assert(sizeof(PATCH_Detox_C_GetDuration) == 0x000038, "Wrong size on PATCH_Detox_C_GetDuration");
static_assert(offsetof(PATCH_Detox_C_GetDuration, DurationText) == 0x000000, "Member 'PATCH_Detox_C_GetDuration::DurationText' has a wrong offset!");
static_assert(offsetof(PATCH_Detox_C_GetDuration, CallFunc_Round_ReturnValue) == 0x000018, "Member 'PATCH_Detox_C_GetDuration::CallFunc_Round_ReturnValue' has a wrong offset!");
static_assert(offsetof(PATCH_Detox_C_GetDuration, CallFunc_GetDefaultPatchDurationText_Text) == 0x000020, "Member 'PATCH_Detox_C_GetDuration::CallFunc_GetDefaultPatchDurationText_Text' has a wrong offset!");

// Function PATCH_Detox.PATCH_Detox_C.UseConsumable
// 0x0028 (0x0028 - 0x0000)
struct PATCH_Detox_C_UseConsumable final
{
public:
	class APAWN_SystemShockCharacter_C*           Character;                                         // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UITEM_ConsumableBase_C*                 ConsumedItem;                                      // 0x0008(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UITEM_ConsumableBase_C*                 CallFunc_UseConsumable_ConsumedItem;               // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCOMP_AttribManager_C*                  CallFunc_GetComponentByClass_ReturnValue;          // 0x0018(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAttribMod*                             CallFunc_ApplyMod_ReturnValue;                     // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PATCH_Detox_C_UseConsumable) == 0x000008, "Wrong alignment on PATCH_Detox_C_UseConsumable");
static_assert(sizeof(PATCH_Detox_C_UseConsumable) == 0x000028, "Wrong size on PATCH_Detox_C_UseConsumable");
static_assert(offsetof(PATCH_Detox_C_UseConsumable, Character) == 0x000000, "Member 'PATCH_Detox_C_UseConsumable::Character' has a wrong offset!");
static_assert(offsetof(PATCH_Detox_C_UseConsumable, ConsumedItem) == 0x000008, "Member 'PATCH_Detox_C_UseConsumable::ConsumedItem' has a wrong offset!");
static_assert(offsetof(PATCH_Detox_C_UseConsumable, CallFunc_UseConsumable_ConsumedItem) == 0x000010, "Member 'PATCH_Detox_C_UseConsumable::CallFunc_UseConsumable_ConsumedItem' has a wrong offset!");
static_assert(offsetof(PATCH_Detox_C_UseConsumable, CallFunc_GetComponentByClass_ReturnValue) == 0x000018, "Member 'PATCH_Detox_C_UseConsumable::CallFunc_GetComponentByClass_ReturnValue' has a wrong offset!");
static_assert(offsetof(PATCH_Detox_C_UseConsumable, CallFunc_ApplyMod_ReturnValue) == 0x000020, "Member 'PATCH_Detox_C_UseConsumable::CallFunc_ApplyMod_ReturnValue' has a wrong offset!");

}

