#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TASK_CustomWait

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"
#include "ENUM_SpeedType_structs.hpp"
#include "ENUM_GameDifficulty_structs.hpp"
#include "STRUCT_CombatDifficultySettings_structs.hpp"


namespace SDK::Params
{

// Function TASK_CustomWait.TASK_CustomWait_C.ExecuteUbergraph_TASK_CustomWait
// 0x00B0 (0x00B0 - 0x0000)
struct TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0004(0x0010)(ZeroConstructor, NoDestructor)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AAIController*                          K2Node_Event_OwnerController;                      // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  K2Node_Event_ControlledPawn;                       // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetRandomWaitTime_RandomWaitTime;         // 0x0028(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2C[0x4];                                       // 0x002C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_Enemy_C*                          K2Node_DynamicCast_AsPAWN_Enemy;                   // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_39[0x7];                                       // 0x0039(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 K2Node_Event_OwnerActor;                           // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate_1;            // 0x0048(0x0010)(ZeroConstructor, NoDestructor)
	bool                                          CallFunc_LessEqual_FloatFloat_ReturnValue;         // 0x0058(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_59[0x7];                                       // 0x0059(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           CallFunc_K2_SetTimerDelegate_ReturnValue;          // 0x0060(0x0008)(NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_69[0x3];                                       // 0x0069(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_RandomFloatInRange_ReturnValue;           // 0x006C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           CallFunc_K2_SetTimerDelegate_ReturnValue_1;        // 0x0070(0x0008)(NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetActorForwardVector_ReturnValue;        // 0x0078(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue;          // 0x0084(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Multiply_VectorFloat_ReturnValue;         // 0x0090(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Add_VectorVector_ReturnValue;             // 0x009C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UOBJ_EnemyTarget_C*                     CallFunc_CreateNavTarget_Target;                   // 0x00A8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, UObjectWrapper, HasGetValueTypeHash)
};
static_assert(alignof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait) == 0x000008, "Wrong alignment on TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait");
static_assert(sizeof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait) == 0x0000B0, "Wrong size on TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, EntryPoint) == 0x000000, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::EntryPoint' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, K2Node_CreateDelegate_OutputDelegate) == 0x000004, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, K2Node_Event_OwnerController) == 0x000018, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::K2Node_Event_OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, K2Node_Event_ControlledPawn) == 0x000020, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::K2Node_Event_ControlledPawn' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_GetRandomWaitTime_RandomWaitTime) == 0x000028, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_GetRandomWaitTime_RandomWaitTime' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, K2Node_DynamicCast_AsPAWN_Enemy) == 0x000030, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::K2Node_DynamicCast_AsPAWN_Enemy' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, K2Node_DynamicCast_bSuccess) == 0x000038, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, K2Node_Event_OwnerActor) == 0x000040, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::K2Node_Event_OwnerActor' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, K2Node_CreateDelegate_OutputDelegate_1) == 0x000048, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::K2Node_CreateDelegate_OutputDelegate_1' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_LessEqual_FloatFloat_ReturnValue) == 0x000058, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_LessEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_K2_SetTimerDelegate_ReturnValue) == 0x000060, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_K2_SetTimerDelegate_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_Not_PreBool_ReturnValue) == 0x000068, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_RandomFloatInRange_ReturnValue) == 0x00006C, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_RandomFloatInRange_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_K2_SetTimerDelegate_ReturnValue_1) == 0x000070, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_K2_SetTimerDelegate_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_GetActorForwardVector_ReturnValue) == 0x000078, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_GetActorForwardVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_K2_GetActorLocation_ReturnValue) == 0x000084, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_K2_GetActorLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_Multiply_VectorFloat_ReturnValue) == 0x000090, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_Multiply_VectorFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_Add_VectorVector_ReturnValue) == 0x00009C, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_Add_VectorVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait, CallFunc_CreateNavTarget_Target) == 0x0000A8, "Member 'TASK_CustomWait_C_ExecuteUbergraph_TASK_CustomWait::CallFunc_CreateNavTarget_Target' has a wrong offset!");

// Function TASK_CustomWait.TASK_CustomWait_C.ReceiveAbort
// 0x0008 (0x0008 - 0x0000)
struct TASK_CustomWait_C_ReceiveAbort final
{
public:
	class AActor*                                 OwnerActor;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_CustomWait_C_ReceiveAbort) == 0x000008, "Wrong alignment on TASK_CustomWait_C_ReceiveAbort");
static_assert(sizeof(TASK_CustomWait_C_ReceiveAbort) == 0x000008, "Wrong size on TASK_CustomWait_C_ReceiveAbort");
static_assert(offsetof(TASK_CustomWait_C_ReceiveAbort, OwnerActor) == 0x000000, "Member 'TASK_CustomWait_C_ReceiveAbort::OwnerActor' has a wrong offset!");

// Function TASK_CustomWait.TASK_CustomWait_C.ReceiveExecuteAI
// 0x0010 (0x0010 - 0x0000)
struct TASK_CustomWait_C_ReceiveExecuteAI final
{
public:
	class AAIController*                          OwnerController;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  ControlledPawn;                                    // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_CustomWait_C_ReceiveExecuteAI) == 0x000008, "Wrong alignment on TASK_CustomWait_C_ReceiveExecuteAI");
static_assert(sizeof(TASK_CustomWait_C_ReceiveExecuteAI) == 0x000010, "Wrong size on TASK_CustomWait_C_ReceiveExecuteAI");
static_assert(offsetof(TASK_CustomWait_C_ReceiveExecuteAI, OwnerController) == 0x000000, "Member 'TASK_CustomWait_C_ReceiveExecuteAI::OwnerController' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_ReceiveExecuteAI, ControlledPawn) == 0x000008, "Member 'TASK_CustomWait_C_ReceiveExecuteAI::ControlledPawn' has a wrong offset!");

// Function TASK_CustomWait.TASK_CustomWait_C.GetRandomWaitTime
// 0x00A0 (0x00A0 - 0x0000)
struct TASK_CustomWait_C_GetRandomWaitTime final
{
public:
	float                                         RandomWaitTime;                                    // 0x0000(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Scale;                                             // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TimeToWait;                                        // 0x0008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x000C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_D[0x3];                                        // 0x000D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_CyberEnemy_C*                     K2Node_DynamicCast_AsPAWN_Cyber_Enemy;             // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_19[0x3];                                       // 0x0019(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Multiply_FloatFloat_ReturnValue;          // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_RandomFloatInRange_ReturnValue;           // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_FMin_ReturnValue;                         // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Add_FloatFloat_ReturnValue;               // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_34[0x4];                                       // 0x0034(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ENUM_GameDifficulty                           CallFunc_GetDifficultyValues_Combat;               // 0x0041(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_GameDifficulty                           CallFunc_GetDifficultyValues_Mission;              // 0x0042(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_GameDifficulty                           CallFunc_GetDifficultyValues_Puzzle;               // 0x0043(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_GameDifficulty                           CallFunc_GetDifficultyValues_Cyber;                // 0x0044(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_GameDifficulty                           K2Node_Select_Default;                             // 0x0045(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_46[0x2];                                       // 0x0046(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 CallFunc_GetEnumeratorUserFriendlyName_ReturnValue; // 0x0048(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FName                                   CallFunc_Conv_StringToName_ReturnValue;            // 0x0058(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSTRUCT_CombatDifficultySettings       CallFunc_GetDataTableRowFromName_OutRow;           // 0x0060(0x0034)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue;      // 0x0094(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_95[0x3];                                       // 0x0095(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Conv_IntToFloat_ReturnValue;              // 0x0098(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Divide_FloatFloat_ReturnValue;            // 0x009C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_CustomWait_C_GetRandomWaitTime) == 0x000008, "Wrong alignment on TASK_CustomWait_C_GetRandomWaitTime");
static_assert(sizeof(TASK_CustomWait_C_GetRandomWaitTime) == 0x0000A0, "Wrong size on TASK_CustomWait_C_GetRandomWaitTime");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, RandomWaitTime) == 0x000000, "Member 'TASK_CustomWait_C_GetRandomWaitTime::RandomWaitTime' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, Scale) == 0x000004, "Member 'TASK_CustomWait_C_GetRandomWaitTime::Scale' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, TimeToWait) == 0x000008, "Member 'TASK_CustomWait_C_GetRandomWaitTime::TimeToWait' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, Temp_bool_Variable) == 0x00000C, "Member 'TASK_CustomWait_C_GetRandomWaitTime::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, K2Node_DynamicCast_AsPAWN_Cyber_Enemy) == 0x000010, "Member 'TASK_CustomWait_C_GetRandomWaitTime::K2Node_DynamicCast_AsPAWN_Cyber_Enemy' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, K2Node_DynamicCast_bSuccess) == 0x000018, "Member 'TASK_CustomWait_C_GetRandomWaitTime::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_Multiply_FloatFloat_ReturnValue) == 0x00001C, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_Multiply_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_RandomFloatInRange_ReturnValue) == 0x000020, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_RandomFloatInRange_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_FMin_ReturnValue) == 0x000024, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_FMin_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_GetGameInstance_ReturnValue) == 0x000028, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_Add_FloatFloat_ReturnValue) == 0x000030, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_Add_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, K2Node_DynamicCast_AsGI_Single_Player) == 0x000038, "Member 'TASK_CustomWait_C_GetRandomWaitTime::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, K2Node_DynamicCast_bSuccess_1) == 0x000040, "Member 'TASK_CustomWait_C_GetRandomWaitTime::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_GetDifficultyValues_Combat) == 0x000041, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_GetDifficultyValues_Combat' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_GetDifficultyValues_Mission) == 0x000042, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_GetDifficultyValues_Mission' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_GetDifficultyValues_Puzzle) == 0x000043, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_GetDifficultyValues_Puzzle' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_GetDifficultyValues_Cyber) == 0x000044, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_GetDifficultyValues_Cyber' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, K2Node_Select_Default) == 0x000045, "Member 'TASK_CustomWait_C_GetRandomWaitTime::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_GetEnumeratorUserFriendlyName_ReturnValue) == 0x000048, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_GetEnumeratorUserFriendlyName_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_Conv_StringToName_ReturnValue) == 0x000058, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_Conv_StringToName_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_GetDataTableRowFromName_OutRow) == 0x000060, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_GetDataTableRowFromName_OutRow' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_GetDataTableRowFromName_ReturnValue) == 0x000094, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_GetDataTableRowFromName_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_Conv_IntToFloat_ReturnValue) == 0x000098, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_Conv_IntToFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_GetRandomWaitTime, CallFunc_Divide_FloatFloat_ReturnValue) == 0x00009C, "Member 'TASK_CustomWait_C_GetRandomWaitTime::CallFunc_Divide_FloatFloat_ReturnValue' has a wrong offset!");

// Function TASK_CustomWait.TASK_CustomWait_C.EVENT_OnTurnBody
// 0x00A8 (0x00A8 - 0x0000)
struct TASK_CustomWait_C_EVENT_OnTurnBody final
{
public:
	struct FVector                                NewDirection;                                      // 0x0000(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CurrentTargetDirection;                            // 0x000C(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable;                                 // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_SpeedType                                Temp_byte_Variable;                                // 0x001C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_SpeedType                                Temp_byte_Variable_1;                              // 0x001D(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_SpeedType                                Temp_byte_Variable_2;                              // 0x001E(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x001F(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	int32                                         CallFunc_RandomInteger_ReturnValue;                // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_SpeedType                                K2Node_Select_Default;                             // 0x0024(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_SetBodyRotateSpeed_Changed;               // 0x0025(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_26[0x2];                                       // 0x0026(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue;          // 0x0028(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0034(0x0010)(ZeroConstructor, NoDestructor)
	float                                         CallFunc_RandomFloatInRange_ReturnValue;           // 0x0044(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           CallFunc_K2_SetTimerDelegate_ReturnValue;          // 0x0048(0x0008)(NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Multiply_VectorFloat_ReturnValue;         // 0x0050(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Add_VectorVector_ReturnValue;             // 0x005C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_RandomFloatInRange_ReturnValue_1;         // 0x0068(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_RandomBool_ReturnValue;                   // 0x006C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_6D[0x3];                                       // 0x006D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_RandomFloatInRange_ReturnValue_2;         // 0x0070(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         K2Node_Select_Default_1;                           // 0x0074(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue_1;        // 0x0078(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_RotateAngleAxis_ReturnValue;              // 0x0084(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Get_Target_Location_Location;             // 0x0090(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetDirectionUnitVector_ReturnValue;       // 0x009C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TASK_CustomWait_C_EVENT_OnTurnBody) == 0x000008, "Wrong alignment on TASK_CustomWait_C_EVENT_OnTurnBody");
static_assert(sizeof(TASK_CustomWait_C_EVENT_OnTurnBody) == 0x0000A8, "Wrong size on TASK_CustomWait_C_EVENT_OnTurnBody");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, NewDirection) == 0x000000, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::NewDirection' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CurrentTargetDirection) == 0x00000C, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CurrentTargetDirection' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, Temp_int_Variable) == 0x000018, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::Temp_int_Variable' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, Temp_byte_Variable) == 0x00001C, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::Temp_byte_Variable' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, Temp_byte_Variable_1) == 0x00001D, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::Temp_byte_Variable_1' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, Temp_byte_Variable_2) == 0x00001E, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::Temp_byte_Variable_2' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, Temp_bool_Variable) == 0x00001F, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_RandomInteger_ReturnValue) == 0x000020, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_RandomInteger_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, K2Node_Select_Default) == 0x000024, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_SetBodyRotateSpeed_Changed) == 0x000025, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_SetBodyRotateSpeed_Changed' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_K2_GetActorLocation_ReturnValue) == 0x000028, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_K2_GetActorLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, K2Node_CreateDelegate_OutputDelegate) == 0x000034, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_RandomFloatInRange_ReturnValue) == 0x000044, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_RandomFloatInRange_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_K2_SetTimerDelegate_ReturnValue) == 0x000048, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_K2_SetTimerDelegate_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_Multiply_VectorFloat_ReturnValue) == 0x000050, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_Multiply_VectorFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_Add_VectorVector_ReturnValue) == 0x00005C, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_Add_VectorVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_RandomFloatInRange_ReturnValue_1) == 0x000068, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_RandomFloatInRange_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_RandomBool_ReturnValue) == 0x00006C, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_RandomBool_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_RandomFloatInRange_ReturnValue_2) == 0x000070, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_RandomFloatInRange_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, K2Node_Select_Default_1) == 0x000074, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::K2Node_Select_Default_1' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_K2_GetActorLocation_ReturnValue_1) == 0x000078, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_K2_GetActorLocation_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_RotateAngleAxis_ReturnValue) == 0x000084, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_RotateAngleAxis_ReturnValue' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_Get_Target_Location_Location) == 0x000090, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_Get_Target_Location_Location' has a wrong offset!");
static_assert(offsetof(TASK_CustomWait_C_EVENT_OnTurnBody, CallFunc_GetDirectionUnitVector_ReturnValue) == 0x00009C, "Member 'TASK_CustomWait_C_EVENT_OnTurnBody::CallFunc_GetDirectionUnitVector_ReturnValue' has a wrong offset!");

}

