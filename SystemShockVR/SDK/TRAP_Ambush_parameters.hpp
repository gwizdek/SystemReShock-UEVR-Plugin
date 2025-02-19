#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TRAP_Ambush

#include "Basic.hpp"


namespace SDK::Params
{

// Function TRAP_Ambush.TRAP_Ambush_C.InitializeTrap
// 0x0028 (0x0028 - 0x0000)
struct TRAP_Ambush_C_InitializeTrap final
{
public:
	class APAWN_Enemy_C*                          EnemyPawn;                                         // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0014(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_HasTrapBeenTriggered_Result;              // 0x0015(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x0016(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_17[0x1];                                       // 0x0017(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_Enemy_C*                          CallFunc_Array_Get_Item;                           // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0024(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TRAP_Ambush_C_InitializeTrap) == 0x000008, "Wrong alignment on TRAP_Ambush_C_InitializeTrap");
static_assert(sizeof(TRAP_Ambush_C_InitializeTrap) == 0x000028, "Wrong size on TRAP_Ambush_C_InitializeTrap");
static_assert(offsetof(TRAP_Ambush_C_InitializeTrap, EnemyPawn) == 0x000000, "Member 'TRAP_Ambush_C_InitializeTrap::EnemyPawn' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_InitializeTrap, Temp_int_Loop_Counter_Variable) == 0x000008, "Member 'TRAP_Ambush_C_InitializeTrap::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_InitializeTrap, CallFunc_Add_IntInt_ReturnValue) == 0x00000C, "Member 'TRAP_Ambush_C_InitializeTrap::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_InitializeTrap, Temp_int_Array_Index_Variable) == 0x000010, "Member 'TRAP_Ambush_C_InitializeTrap::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_InitializeTrap, CallFunc_IsValid_ReturnValue) == 0x000014, "Member 'TRAP_Ambush_C_InitializeTrap::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_InitializeTrap, CallFunc_HasTrapBeenTriggered_Result) == 0x000015, "Member 'TRAP_Ambush_C_InitializeTrap::CallFunc_HasTrapBeenTriggered_Result' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_InitializeTrap, CallFunc_Not_PreBool_ReturnValue) == 0x000016, "Member 'TRAP_Ambush_C_InitializeTrap::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_InitializeTrap, CallFunc_Array_Get_Item) == 0x000018, "Member 'TRAP_Ambush_C_InitializeTrap::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_InitializeTrap, CallFunc_Array_Length_ReturnValue) == 0x000020, "Member 'TRAP_Ambush_C_InitializeTrap::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_InitializeTrap, CallFunc_Less_IntInt_ReturnValue) == 0x000024, "Member 'TRAP_Ambush_C_InitializeTrap::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");

// Function TRAP_Ambush.TRAP_Ambush_C.OnSpringTrap
// 0x0088 (0x0088 - 0x0000)
struct TRAP_Ambush_C_OnSpringTrap final
{
public:
	class APAWN_Hacker_Simple_C*                  Hacker;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AEnemySpawnPoint_C*                     SelectedSpawnPoint;                                // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         SelectedSpawnPointIndex;                           // 0x0010(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class AEnemySpawnPoint_C*>             SpawnPointsRemaining;                              // 0x0018(0x0010)(Edit, BlueprintVisible, DisableEditOnTemplate)
	int32                                         Temp_int_Variable;                                 // 0x0028(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x002C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0034(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_39[0x3];                                       // 0x0039(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Add_IntInt_ReturnValue_1;                 // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          CallFunc_SpawnEnemy_Enemy;                         // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AEnemySpawnPoint_C*                     CallFunc_Array_Get_Item;                           // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_51[0x3];                                       // 0x0051(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_LastIndex_ReturnValue;              // 0x0054(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_RandomIntegerInRange_ReturnValue;         // 0x0058(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x005C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_IntInt_ReturnValue;               // 0x0060(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Greater_IntInt_ReturnValue_1;             // 0x0061(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_62[0x2];                                       // 0x0062(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Subtract_IntInt_ReturnValue;              // 0x0064(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_LessEqual_IntInt_ReturnValue;             // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_69[0x7];                                       // 0x0069(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AEnemySpawnPoint_C*                     CallFunc_Array_Get_Item_1;                         // 0x0070(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Add_ReturnValue;                    // 0x0078(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_CanSpawnEnemies_Result;                   // 0x007C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_7D[0x3];                                       // 0x007D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Length_ReturnValue_1;               // 0x0080(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0084(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TRAP_Ambush_C_OnSpringTrap) == 0x000008, "Wrong alignment on TRAP_Ambush_C_OnSpringTrap");
static_assert(sizeof(TRAP_Ambush_C_OnSpringTrap) == 0x000088, "Wrong size on TRAP_Ambush_C_OnSpringTrap");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, Hacker) == 0x000000, "Member 'TRAP_Ambush_C_OnSpringTrap::Hacker' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, SelectedSpawnPoint) == 0x000008, "Member 'TRAP_Ambush_C_OnSpringTrap::SelectedSpawnPoint' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, SelectedSpawnPointIndex) == 0x000010, "Member 'TRAP_Ambush_C_OnSpringTrap::SelectedSpawnPointIndex' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, SpawnPointsRemaining) == 0x000018, "Member 'TRAP_Ambush_C_OnSpringTrap::SpawnPointsRemaining' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, Temp_int_Variable) == 0x000028, "Member 'TRAP_Ambush_C_OnSpringTrap::Temp_int_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Add_IntInt_ReturnValue) == 0x00002C, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, Temp_int_Array_Index_Variable) == 0x000030, "Member 'TRAP_Ambush_C_OnSpringTrap::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, Temp_int_Loop_Counter_Variable) == 0x000034, "Member 'TRAP_Ambush_C_OnSpringTrap::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_IsValid_ReturnValue) == 0x000038, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Add_IntInt_ReturnValue_1) == 0x00003C, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Add_IntInt_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_SpawnEnemy_Enemy) == 0x000040, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_SpawnEnemy_Enemy' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Array_Get_Item) == 0x000048, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_IsValid_ReturnValue_1) == 0x000050, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_IsValid_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Array_LastIndex_ReturnValue) == 0x000054, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Array_LastIndex_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_RandomIntegerInRange_ReturnValue) == 0x000058, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_RandomIntegerInRange_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Array_Length_ReturnValue) == 0x00005C, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Greater_IntInt_ReturnValue) == 0x000060, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Greater_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Greater_IntInt_ReturnValue_1) == 0x000061, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Greater_IntInt_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Subtract_IntInt_ReturnValue) == 0x000064, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Subtract_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_LessEqual_IntInt_ReturnValue) == 0x000068, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_LessEqual_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Array_Get_Item_1) == 0x000070, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Array_Get_Item_1' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Array_Add_ReturnValue) == 0x000078, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Array_Add_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_CanSpawnEnemies_Result) == 0x00007C, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_CanSpawnEnemies_Result' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Array_Length_ReturnValue_1) == 0x000080, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Array_Length_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnSpringTrap, CallFunc_Less_IntInt_ReturnValue) == 0x000084, "Member 'TRAP_Ambush_C_OnSpringTrap::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");

// Function TRAP_Ambush.TRAP_Ambush_C.HandleUnlocking
// 0x0038 (0x0038 - 0x0000)
struct TRAP_Ambush_C_HandleUnlocking final
{
public:
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AINTERACT_Base_C*                       CallFunc_Array_Get_Item;                           // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_19[0x7];                                       // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TScriptInterface<class IINTERF_Interactable_C> CallFunc_SetInteractLocked_self_CastInput;         // 0x0020(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_SetInteractLocked_Result;                 // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TRAP_Ambush_C_HandleUnlocking) == 0x000008, "Wrong alignment on TRAP_Ambush_C_HandleUnlocking");
static_assert(sizeof(TRAP_Ambush_C_HandleUnlocking) == 0x000038, "Wrong size on TRAP_Ambush_C_HandleUnlocking");
static_assert(offsetof(TRAP_Ambush_C_HandleUnlocking, Temp_int_Array_Index_Variable) == 0x000000, "Member 'TRAP_Ambush_C_HandleUnlocking::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleUnlocking, Temp_int_Loop_Counter_Variable) == 0x000004, "Member 'TRAP_Ambush_C_HandleUnlocking::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleUnlocking, CallFunc_Add_IntInt_ReturnValue) == 0x000008, "Member 'TRAP_Ambush_C_HandleUnlocking::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleUnlocking, CallFunc_Array_Length_ReturnValue) == 0x00000C, "Member 'TRAP_Ambush_C_HandleUnlocking::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleUnlocking, CallFunc_Array_Get_Item) == 0x000010, "Member 'TRAP_Ambush_C_HandleUnlocking::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleUnlocking, CallFunc_Less_IntInt_ReturnValue) == 0x000018, "Member 'TRAP_Ambush_C_HandleUnlocking::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleUnlocking, CallFunc_SetInteractLocked_self_CastInput) == 0x000020, "Member 'TRAP_Ambush_C_HandleUnlocking::CallFunc_SetInteractLocked_self_CastInput' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleUnlocking, CallFunc_SetInteractLocked_Result) == 0x000030, "Member 'TRAP_Ambush_C_HandleUnlocking::CallFunc_SetInteractLocked_Result' has a wrong offset!");

// Function TRAP_Ambush.TRAP_Ambush_C.HandleLocking
// 0x0050 (0x0050 - 0x0000)
struct TRAP_Ambush_C_HandleLocking final
{
public:
	class AINTERACT_Base_C*                       CurrentInteract;                                   // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TScriptInterface<class IINTERF_Interactable_C> CallFunc_SetInteractLocked_self_CastInput;         // 0x0018(0x0010)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_SetInteractLocked_Result;                 // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AINTERACT_DoorBase_C*                   K2Node_DynamicCast_AsINTERACT_Door_Base;           // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_39[0x3];                                       // 0x0039(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AINTERACT_Base_C*                       CallFunc_Array_Get_Item;                           // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TRAP_Ambush_C_HandleLocking) == 0x000008, "Wrong alignment on TRAP_Ambush_C_HandleLocking");
static_assert(sizeof(TRAP_Ambush_C_HandleLocking) == 0x000050, "Wrong size on TRAP_Ambush_C_HandleLocking");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, CurrentInteract) == 0x000000, "Member 'TRAP_Ambush_C_HandleLocking::CurrentInteract' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, Temp_int_Array_Index_Variable) == 0x000008, "Member 'TRAP_Ambush_C_HandleLocking::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, Temp_int_Loop_Counter_Variable) == 0x00000C, "Member 'TRAP_Ambush_C_HandleLocking::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, CallFunc_Add_IntInt_ReturnValue) == 0x000010, "Member 'TRAP_Ambush_C_HandleLocking::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, CallFunc_SetInteractLocked_self_CastInput) == 0x000018, "Member 'TRAP_Ambush_C_HandleLocking::CallFunc_SetInteractLocked_self_CastInput' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, CallFunc_SetInteractLocked_Result) == 0x000028, "Member 'TRAP_Ambush_C_HandleLocking::CallFunc_SetInteractLocked_Result' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, K2Node_DynamicCast_AsINTERACT_Door_Base) == 0x000030, "Member 'TRAP_Ambush_C_HandleLocking::K2Node_DynamicCast_AsINTERACT_Door_Base' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, K2Node_DynamicCast_bSuccess) == 0x000038, "Member 'TRAP_Ambush_C_HandleLocking::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, CallFunc_Array_Length_ReturnValue) == 0x00003C, "Member 'TRAP_Ambush_C_HandleLocking::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, CallFunc_Array_Get_Item) == 0x000040, "Member 'TRAP_Ambush_C_HandleLocking::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_HandleLocking, CallFunc_Less_IntInt_ReturnValue) == 0x000048, "Member 'TRAP_Ambush_C_HandleLocking::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");

// Function TRAP_Ambush.TRAP_Ambush_C.WakeUpEnemies
// 0x0038 (0x0038 - 0x0000)
struct TRAP_Ambush_C_WakeUpEnemies final
{
public:
	class APAWN_Hacker_Simple_C*                  HackerPawn;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          EnemyPawn;                                         // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_19[0x3];                                       // 0x0019(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue_1;                    // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsBehaviorDisabled_Result;                // 0x0021(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_22[0x2];                                       // 0x0022(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          CallFunc_Array_Get_Item;                           // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TRAP_Ambush_C_WakeUpEnemies) == 0x000008, "Wrong alignment on TRAP_Ambush_C_WakeUpEnemies");
static_assert(sizeof(TRAP_Ambush_C_WakeUpEnemies) == 0x000038, "Wrong size on TRAP_Ambush_C_WakeUpEnemies");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, HackerPawn) == 0x000000, "Member 'TRAP_Ambush_C_WakeUpEnemies::HackerPawn' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, EnemyPawn) == 0x000008, "Member 'TRAP_Ambush_C_WakeUpEnemies::EnemyPawn' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, Temp_int_Array_Index_Variable) == 0x000010, "Member 'TRAP_Ambush_C_WakeUpEnemies::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, Temp_int_Loop_Counter_Variable) == 0x000014, "Member 'TRAP_Ambush_C_WakeUpEnemies::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, CallFunc_IsValid_ReturnValue) == 0x000018, "Member 'TRAP_Ambush_C_WakeUpEnemies::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, CallFunc_Add_IntInt_ReturnValue) == 0x00001C, "Member 'TRAP_Ambush_C_WakeUpEnemies::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, CallFunc_IsValid_ReturnValue_1) == 0x000020, "Member 'TRAP_Ambush_C_WakeUpEnemies::CallFunc_IsValid_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, CallFunc_IsBehaviorDisabled_Result) == 0x000021, "Member 'TRAP_Ambush_C_WakeUpEnemies::CallFunc_IsBehaviorDisabled_Result' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, CallFunc_Array_Length_ReturnValue) == 0x000024, "Member 'TRAP_Ambush_C_WakeUpEnemies::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, CallFunc_Array_Get_Item) == 0x000028, "Member 'TRAP_Ambush_C_WakeUpEnemies::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_WakeUpEnemies, CallFunc_Less_IntInt_ReturnValue) == 0x000030, "Member 'TRAP_Ambush_C_WakeUpEnemies::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");

// Function TRAP_Ambush.TRAP_Ambush_C.TryBindSpawnEvents
// 0x0050 (0x0050 - 0x0000)
struct TRAP_Ambush_C_TryBindSpawnEvents final
{
public:
	class AINTERACT_LogisticsLift_C*              LogisticsLift;                                     // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UClass*                                 K2Node_ClassDynamicCast_AsPAWN_Enemy;              // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_ClassDynamicCast_bSuccess;                  // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_19[0x3];                                       // 0x0019(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(class AINTERACT_LogisticsLift_C* LogisticsLift, class AActor* CargoActor)> K2Node_CreateDelegate_OutputDelegate;              // 0x0020(0x0010)(ZeroConstructor, NoDestructor)
	class AINTERACT_Base_C*                       CallFunc_Array_Get_Item;                           // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3C[0x4];                                       // 0x003C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AINTERACT_LogisticsLift_C*              K2Node_DynamicCast_AsINTERACT_Logistics_Lift;      // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0049(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TRAP_Ambush_C_TryBindSpawnEvents) == 0x000008, "Wrong alignment on TRAP_Ambush_C_TryBindSpawnEvents");
static_assert(sizeof(TRAP_Ambush_C_TryBindSpawnEvents) == 0x000050, "Wrong size on TRAP_Ambush_C_TryBindSpawnEvents");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, LogisticsLift) == 0x000000, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::LogisticsLift' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, Temp_int_Array_Index_Variable) == 0x000008, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, Temp_int_Loop_Counter_Variable) == 0x00000C, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, K2Node_ClassDynamicCast_AsPAWN_Enemy) == 0x000010, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::K2Node_ClassDynamicCast_AsPAWN_Enemy' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, K2Node_ClassDynamicCast_bSuccess) == 0x000018, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::K2Node_ClassDynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, CallFunc_Add_IntInt_ReturnValue) == 0x00001C, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, K2Node_CreateDelegate_OutputDelegate) == 0x000020, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, CallFunc_Array_Get_Item) == 0x000030, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, CallFunc_Array_Length_ReturnValue) == 0x000038, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, K2Node_DynamicCast_AsINTERACT_Logistics_Lift) == 0x000040, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::K2Node_DynamicCast_AsINTERACT_Logistics_Lift' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, K2Node_DynamicCast_bSuccess) == 0x000048, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_TryBindSpawnEvents, CallFunc_Less_IntInt_ReturnValue) == 0x000049, "Member 'TRAP_Ambush_C_TryBindSpawnEvents::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");

// Function TRAP_Ambush.TRAP_Ambush_C.OnInitializeEnemyForAmbush
// 0x0020 (0x0020 - 0x0000)
struct TRAP_Ambush_C_OnInitializeEnemyForAmbush final
{
public:
	class APAWN_Enemy_C*                          Enemy;                                             // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Hacker_Simple_C*                  Hacker;                                            // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UAttribMod*>                     CallFunc_ApplyMods_ReturnValue;                    // 0x0010(0x0010)(ReferenceParm)
};
static_assert(alignof(TRAP_Ambush_C_OnInitializeEnemyForAmbush) == 0x000008, "Wrong alignment on TRAP_Ambush_C_OnInitializeEnemyForAmbush");
static_assert(sizeof(TRAP_Ambush_C_OnInitializeEnemyForAmbush) == 0x000020, "Wrong size on TRAP_Ambush_C_OnInitializeEnemyForAmbush");
static_assert(offsetof(TRAP_Ambush_C_OnInitializeEnemyForAmbush, Enemy) == 0x000000, "Member 'TRAP_Ambush_C_OnInitializeEnemyForAmbush::Enemy' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnInitializeEnemyForAmbush, Hacker) == 0x000008, "Member 'TRAP_Ambush_C_OnInitializeEnemyForAmbush::Hacker' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_OnInitializeEnemyForAmbush, CallFunc_ApplyMods_ReturnValue) == 0x000010, "Member 'TRAP_Ambush_C_OnInitializeEnemyForAmbush::CallFunc_ApplyMods_ReturnValue' has a wrong offset!");

// Function TRAP_Ambush.TRAP_Ambush_C.EVENT_OnAlertLogisticsLiftEnemy
// 0x0048 (0x0048 - 0x0000)
struct TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy final
{
public:
	class AINTERACT_LogisticsLift_C*              LogisticsLift;                                     // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 CargoActor;                                        // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(class AINTERACT_LogisticsLift_C* LogisticsLift, class AActor* CargoActor)> K2Node_CreateDelegate_OutputDelegate;              // 0x0010(0x0010)(ZeroConstructor, NoDestructor)
	class APAWN_Enemy_C*                          K2Node_DynamicCast_AsPAWN_Enemy;                   // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APawn*                                  CallFunc_GetPlayerPawn_ReturnValue;                // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_SystemShockCharacter_C*           K2Node_DynamicCast_AsPAWN_System_Shock_Character;  // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy) == 0x000008, "Wrong alignment on TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy");
static_assert(sizeof(TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy) == 0x000048, "Wrong size on TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy");
static_assert(offsetof(TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy, LogisticsLift) == 0x000000, "Member 'TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy::LogisticsLift' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy, CargoActor) == 0x000008, "Member 'TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy::CargoActor' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy, K2Node_CreateDelegate_OutputDelegate) == 0x000010, "Member 'TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy, K2Node_DynamicCast_AsPAWN_Enemy) == 0x000020, "Member 'TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy::K2Node_DynamicCast_AsPAWN_Enemy' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy, CallFunc_GetPlayerPawn_ReturnValue) == 0x000030, "Member 'TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy::CallFunc_GetPlayerPawn_ReturnValue' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy, K2Node_DynamicCast_AsPAWN_System_Shock_Character) == 0x000038, "Member 'TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy::K2Node_DynamicCast_AsPAWN_System_Shock_Character' has a wrong offset!");
static_assert(offsetof(TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy, K2Node_DynamicCast_bSuccess_1) == 0x000040, "Member 'TRAP_Ambush_C_EVENT_OnAlertLogisticsLiftEnemy::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");

}

