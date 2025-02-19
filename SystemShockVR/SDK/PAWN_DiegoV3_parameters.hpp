#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PAWN_DiegoV3

#include "Basic.hpp"

#include "AttributeSystem_structs.hpp"


namespace SDK::Params
{

// Function PAWN_DiegoV3.PAWN_DiegoV3_C.ExecuteUbergraph_PAWN_DiegoV3
// 0x0020 (0x0020 - 0x0000)
struct PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3 final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class APawn*                                  CallFunc_GetPlayerPawn_ReturnValue;                // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Hacker_Simple_C*                  K2Node_DynamicCast_AsPAWN_Hacker_Simple;           // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3) == 0x000008, "Wrong alignment on PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3");
static_assert(sizeof(PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3) == 0x000020, "Wrong size on PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3");
static_assert(offsetof(PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3, EntryPoint) == 0x000000, "Member 'PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3::EntryPoint' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3, CallFunc_GetPlayerPawn_ReturnValue) == 0x000008, "Member 'PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3::CallFunc_GetPlayerPawn_ReturnValue' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3, K2Node_DynamicCast_AsPAWN_Hacker_Simple) == 0x000010, "Member 'PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3::K2Node_DynamicCast_AsPAWN_Hacker_Simple' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3, K2Node_DynamicCast_bSuccess) == 0x000018, "Member 'PAWN_DiegoV3_C_ExecuteUbergraph_PAWN_DiegoV3::K2Node_DynamicCast_bSuccess' has a wrong offset!");

// Function PAWN_DiegoV3.PAWN_DiegoV3_C.OnCharacterDied
// 0x0040 (0x0040 - 0x0000)
struct PAWN_DiegoV3_C_OnCharacterDied final
{
public:
	class UOBJ_ImpactData_C*                      ImpactData;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FAttribDamageInstance                  DamageInstance;                                    // 0x0008(0x0028)(BlueprintVisible, BlueprintReadOnly, Parm)
	class AActor*                                 OtherActor;                                        // 0x0030(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0038(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_OnCharacterDied_Result;                   // 0x0039(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PAWN_DiegoV3_C_OnCharacterDied) == 0x000008, "Wrong alignment on PAWN_DiegoV3_C_OnCharacterDied");
static_assert(sizeof(PAWN_DiegoV3_C_OnCharacterDied) == 0x000040, "Wrong size on PAWN_DiegoV3_C_OnCharacterDied");
static_assert(offsetof(PAWN_DiegoV3_C_OnCharacterDied, ImpactData) == 0x000000, "Member 'PAWN_DiegoV3_C_OnCharacterDied::ImpactData' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_OnCharacterDied, DamageInstance) == 0x000008, "Member 'PAWN_DiegoV3_C_OnCharacterDied::DamageInstance' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_OnCharacterDied, OtherActor) == 0x000030, "Member 'PAWN_DiegoV3_C_OnCharacterDied::OtherActor' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_OnCharacterDied, Result) == 0x000038, "Member 'PAWN_DiegoV3_C_OnCharacterDied::Result' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_OnCharacterDied, CallFunc_OnCharacterDied_Result) == 0x000039, "Member 'PAWN_DiegoV3_C_OnCharacterDied::CallFunc_OnCharacterDied_Result' has a wrong offset!");

// Function PAWN_DiegoV3.PAWN_DiegoV3_C.TryCompleteRapierDeathAchievement
// 0x0028 (0x0028 - 0x0000)
struct PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement final
{
public:
	class UAttribDamageType*                      DamageType;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_ObjectObject_ReturnValue;      // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x7];                                        // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_TryCompleteBinaryAchievement_Result;      // 0x0021(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement) == 0x000008, "Wrong alignment on PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement");
static_assert(sizeof(PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement) == 0x000028, "Wrong size on PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement");
static_assert(offsetof(PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement, DamageType) == 0x000000, "Member 'PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement::DamageType' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement, CallFunc_EqualEqual_ObjectObject_ReturnValue) == 0x000008, "Member 'PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement::CallFunc_EqualEqual_ObjectObject_ReturnValue' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement, CallFunc_GetGameInstance_ReturnValue) == 0x000010, "Member 'PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement, K2Node_DynamicCast_AsGI_Single_Player) == 0x000018, "Member 'PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement, K2Node_DynamicCast_bSuccess) == 0x000020, "Member 'PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement, CallFunc_TryCompleteBinaryAchievement_Result) == 0x000021, "Member 'PAWN_DiegoV3_C_TryCompleteRapierDeathAchievement::CallFunc_TryCompleteBinaryAchievement_Result' has a wrong offset!");

// Function PAWN_DiegoV3.PAWN_DiegoV3_C.ForceReappear
// 0x0038 (0x0038 - 0x0000)
struct PAWN_DiegoV3_C_ForceReappear final
{
public:
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class UStaticMeshComponent*>           CallFunc_GetChildComponentsByClass_ReturnValue;    // 0x0010(0x0010)(ReferenceParm, ContainsInstancedReference)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_24[0x4];                                       // 0x0024(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UStaticMeshComponent*                   CallFunc_Array_Get_Item;                           // 0x0028(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PAWN_DiegoV3_C_ForceReappear) == 0x000008, "Wrong alignment on PAWN_DiegoV3_C_ForceReappear");
static_assert(sizeof(PAWN_DiegoV3_C_ForceReappear) == 0x000038, "Wrong size on PAWN_DiegoV3_C_ForceReappear");
static_assert(offsetof(PAWN_DiegoV3_C_ForceReappear, Temp_int_Array_Index_Variable) == 0x000000, "Member 'PAWN_DiegoV3_C_ForceReappear::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_ForceReappear, Temp_int_Loop_Counter_Variable) == 0x000004, "Member 'PAWN_DiegoV3_C_ForceReappear::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_ForceReappear, CallFunc_Add_IntInt_ReturnValue) == 0x000008, "Member 'PAWN_DiegoV3_C_ForceReappear::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_ForceReappear, CallFunc_GetChildComponentsByClass_ReturnValue) == 0x000010, "Member 'PAWN_DiegoV3_C_ForceReappear::CallFunc_GetChildComponentsByClass_ReturnValue' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_ForceReappear, CallFunc_Array_Length_ReturnValue) == 0x000020, "Member 'PAWN_DiegoV3_C_ForceReappear::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_ForceReappear, CallFunc_Array_Get_Item) == 0x000028, "Member 'PAWN_DiegoV3_C_ForceReappear::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(PAWN_DiegoV3_C_ForceReappear, CallFunc_Less_IntInt_ReturnValue) == 0x000030, "Member 'PAWN_DiegoV3_C_ForceReappear::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");

}

