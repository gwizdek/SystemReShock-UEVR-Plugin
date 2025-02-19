#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_BetaGroveExterior

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function BP_BetaGroveExterior.BP_BetaGroveExterior_C.ExecuteUbergraph_BP_BetaGroveExterior
// 0x0004 (0x0004 - 0x0000)
struct BP_BetaGroveExterior_C_ExecuteUbergraph_BP_BetaGroveExterior final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_BetaGroveExterior_C_ExecuteUbergraph_BP_BetaGroveExterior) == 0x000004, "Wrong alignment on BP_BetaGroveExterior_C_ExecuteUbergraph_BP_BetaGroveExterior");
static_assert(sizeof(BP_BetaGroveExterior_C_ExecuteUbergraph_BP_BetaGroveExterior) == 0x000004, "Wrong size on BP_BetaGroveExterior_C_ExecuteUbergraph_BP_BetaGroveExterior");
static_assert(offsetof(BP_BetaGroveExterior_C_ExecuteUbergraph_BP_BetaGroveExterior, EntryPoint) == 0x000000, "Member 'BP_BetaGroveExterior_C_ExecuteUbergraph_BP_BetaGroveExterior::EntryPoint' has a wrong offset!");

// Function BP_BetaGroveExterior.BP_BetaGroveExterior_C.InitializeBetaGroveExterior
// 0x0068 (0x0068 - 0x0000)
struct BP_BetaGroveExterior_C_InitializeBetaGroveExterior final
{
public:
	float                                         GroveJettisonQuestTimestamp;                       // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ElapsedTimeSinceJettisoned;                        // 0x0004(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ElapsedTimeSinceQuestCompleted;                    // 0x0008(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGI_SinglePlayer_C*                     GameInstance;                                      // 0x0010(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_GreaterEqual_FloatFloat_ReturnValue;      // 0x0019(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1A[0x2];                                       // 0x001A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Subtract_FloatFloat_ReturnValue;          // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_FMax_ReturnValue;                         // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Subtract_FloatFloat_ReturnValue_1;        // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_TryStartGroveJettisonTimer_Result;        // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x3];                                       // 0x0029(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_GetPlayTimeInSeconds_ReturnValue;         // 0x002C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Subtract_FloatFloat_ReturnValue_2;        // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_FloatFloat_ReturnValue;              // 0x0034(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_35[0x3];                                       // 0x0035(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(class FName StoryQuestName, bool Value)> K2Node_CreateDelegate_OutputDelegate;              // 0x0038(0x0010)(ZeroConstructor, NoDestructor)
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetStoryQuestCompletionTimestamp_Timestamp; // 0x0050(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_54[0x4];                                       // 0x0054(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0058(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0060(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior) == 0x000008, "Wrong alignment on BP_BetaGroveExterior_C_InitializeBetaGroveExterior");
static_assert(sizeof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior) == 0x000068, "Wrong size on BP_BetaGroveExterior_C_InitializeBetaGroveExterior");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, GroveJettisonQuestTimestamp) == 0x000000, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::GroveJettisonQuestTimestamp' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, ElapsedTimeSinceJettisoned) == 0x000004, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::ElapsedTimeSinceJettisoned' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, ElapsedTimeSinceQuestCompleted) == 0x000008, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::ElapsedTimeSinceQuestCompleted' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, GameInstance) == 0x000010, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::GameInstance' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_Greater_FloatFloat_ReturnValue) == 0x000018, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_Greater_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_GreaterEqual_FloatFloat_ReturnValue) == 0x000019, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_GreaterEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_Subtract_FloatFloat_ReturnValue) == 0x00001C, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_Subtract_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_FMax_ReturnValue) == 0x000020, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_FMax_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_Subtract_FloatFloat_ReturnValue_1) == 0x000024, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_Subtract_FloatFloat_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_TryStartGroveJettisonTimer_Result) == 0x000028, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_TryStartGroveJettisonTimer_Result' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_GetPlayTimeInSeconds_ReturnValue) == 0x00002C, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_GetPlayTimeInSeconds_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_Subtract_FloatFloat_ReturnValue_2) == 0x000030, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_Subtract_FloatFloat_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_Less_FloatFloat_ReturnValue) == 0x000034, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_Less_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, K2Node_CreateDelegate_OutputDelegate) == 0x000038, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_GetGameInstance_ReturnValue) == 0x000048, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, CallFunc_GetStoryQuestCompletionTimestamp_Timestamp) == 0x000050, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::CallFunc_GetStoryQuestCompletionTimestamp_Timestamp' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, K2Node_DynamicCast_AsGI_Single_Player) == 0x000058, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_InitializeBetaGroveExterior, K2Node_DynamicCast_bSuccess) == 0x000060, "Member 'BP_BetaGroveExterior_C_InitializeBetaGroveExterior::K2Node_DynamicCast_bSuccess' has a wrong offset!");

// Function BP_BetaGroveExterior.BP_BetaGroveExterior_C.EVENT_OnStoryQuestChanged
// 0x0038 (0x0038 - 0x0000)
struct BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged final
{
public:
	class FName                                   StoryQuestName;                                    // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Value;                                             // 0x0008(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x3];                                        // 0x0009(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(class FName StoryQuestName, bool Value)> K2Node_CreateDelegate_OutputDelegate;              // 0x000C(0x0010)(ZeroConstructor, NoDestructor)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x0031(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_TryStartGroveJettisonTimer_Result;        // 0x0032(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_NameName_ReturnValue;          // 0x0033(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged) == 0x000008, "Wrong alignment on BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged");
static_assert(sizeof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged) == 0x000038, "Wrong size on BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged");
static_assert(offsetof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged, StoryQuestName) == 0x000000, "Member 'BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged::StoryQuestName' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged, Value) == 0x000008, "Member 'BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged::Value' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged, K2Node_CreateDelegate_OutputDelegate) == 0x00000C, "Member 'BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged, CallFunc_GetGameInstance_ReturnValue) == 0x000020, "Member 'BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged, K2Node_DynamicCast_AsGI_Single_Player) == 0x000028, "Member 'BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged, K2Node_DynamicCast_bSuccess) == 0x000030, "Member 'BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged, CallFunc_Greater_FloatFloat_ReturnValue) == 0x000031, "Member 'BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged::CallFunc_Greater_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged, CallFunc_TryStartGroveJettisonTimer_Result) == 0x000032, "Member 'BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged::CallFunc_TryStartGroveJettisonTimer_Result' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged, CallFunc_EqualEqual_NameName_ReturnValue) == 0x000033, "Member 'BP_BetaGroveExterior_C_EVENT_OnStoryQuestChanged::CallFunc_EqualEqual_NameName_ReturnValue' has a wrong offset!");

// Function BP_BetaGroveExterior.BP_BetaGroveExterior_C.TryResumeJettisonMontage
// 0x0018 (0x0018 - 0x0000)
struct BP_BetaGroveExterior_C_TryResumeJettisonMontage final
{
public:
	float                                         StartTime;                                         // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UAnimInstance*                          CallFunc_GetAnimInstance_ReturnValue;              // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Montage_Play_ReturnValue;                 // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BP_BetaGroveExterior_C_TryResumeJettisonMontage) == 0x000008, "Wrong alignment on BP_BetaGroveExterior_C_TryResumeJettisonMontage");
static_assert(sizeof(BP_BetaGroveExterior_C_TryResumeJettisonMontage) == 0x000018, "Wrong size on BP_BetaGroveExterior_C_TryResumeJettisonMontage");
static_assert(offsetof(BP_BetaGroveExterior_C_TryResumeJettisonMontage, StartTime) == 0x000000, "Member 'BP_BetaGroveExterior_C_TryResumeJettisonMontage::StartTime' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_TryResumeJettisonMontage, CallFunc_GetAnimInstance_ReturnValue) == 0x000008, "Member 'BP_BetaGroveExterior_C_TryResumeJettisonMontage::CallFunc_GetAnimInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_TryResumeJettisonMontage, CallFunc_Montage_Play_ReturnValue) == 0x000010, "Member 'BP_BetaGroveExterior_C_TryResumeJettisonMontage::CallFunc_Montage_Play_ReturnValue' has a wrong offset!");

// Function BP_BetaGroveExterior.BP_BetaGroveExterior_C.TryStartGroveJettisonTimer
// 0x0028 (0x0028 - 0x0000)
struct BP_BetaGroveExterior_C_TryStartGroveJettisonTimer final
{
public:
	float                                         Delay;                                             // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_5[0x3];                                        // 0x0005(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0008(0x0010)(ZeroConstructor, NoDestructor)
	struct FTimerHandle                           CallFunc_K2_SetTimerDelegate_ReturnValue;          // 0x0018(0x0008)(NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_K2_IsTimerActiveHandle_ReturnValue;       // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x0021(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BP_BetaGroveExterior_C_TryStartGroveJettisonTimer) == 0x000008, "Wrong alignment on BP_BetaGroveExterior_C_TryStartGroveJettisonTimer");
static_assert(sizeof(BP_BetaGroveExterior_C_TryStartGroveJettisonTimer) == 0x000028, "Wrong size on BP_BetaGroveExterior_C_TryStartGroveJettisonTimer");
static_assert(offsetof(BP_BetaGroveExterior_C_TryStartGroveJettisonTimer, Delay) == 0x000000, "Member 'BP_BetaGroveExterior_C_TryStartGroveJettisonTimer::Delay' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_TryStartGroveJettisonTimer, Result) == 0x000004, "Member 'BP_BetaGroveExterior_C_TryStartGroveJettisonTimer::Result' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_TryStartGroveJettisonTimer, K2Node_CreateDelegate_OutputDelegate) == 0x000008, "Member 'BP_BetaGroveExterior_C_TryStartGroveJettisonTimer::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_TryStartGroveJettisonTimer, CallFunc_K2_SetTimerDelegate_ReturnValue) == 0x000018, "Member 'BP_BetaGroveExterior_C_TryStartGroveJettisonTimer::CallFunc_K2_SetTimerDelegate_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_TryStartGroveJettisonTimer, CallFunc_K2_IsTimerActiveHandle_ReturnValue) == 0x000020, "Member 'BP_BetaGroveExterior_C_TryStartGroveJettisonTimer::CallFunc_K2_IsTimerActiveHandle_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_TryStartGroveJettisonTimer, CallFunc_Not_PreBool_ReturnValue) == 0x000021, "Member 'BP_BetaGroveExterior_C_TryStartGroveJettisonTimer::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");

// Function BP_BetaGroveExterior.BP_BetaGroveExterior_C.UpdateAnimInstanceState
// 0x0018 (0x0018 - 0x0000)
struct BP_BetaGroveExterior_C_UpdateAnimInstanceState final
{
public:
	class UAnimInstance*                          CallFunc_GetAnimInstance_ReturnValue;              // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UANIMBP_Grove_Armature_C*               K2Node_DynamicCast_AsANIMBP_Grove_Armature;        // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(BP_BetaGroveExterior_C_UpdateAnimInstanceState) == 0x000008, "Wrong alignment on BP_BetaGroveExterior_C_UpdateAnimInstanceState");
static_assert(sizeof(BP_BetaGroveExterior_C_UpdateAnimInstanceState) == 0x000018, "Wrong size on BP_BetaGroveExterior_C_UpdateAnimInstanceState");
static_assert(offsetof(BP_BetaGroveExterior_C_UpdateAnimInstanceState, CallFunc_GetAnimInstance_ReturnValue) == 0x000000, "Member 'BP_BetaGroveExterior_C_UpdateAnimInstanceState::CallFunc_GetAnimInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_UpdateAnimInstanceState, K2Node_DynamicCast_AsANIMBP_Grove_Armature) == 0x000008, "Member 'BP_BetaGroveExterior_C_UpdateAnimInstanceState::K2Node_DynamicCast_AsANIMBP_Grove_Armature' has a wrong offset!");
static_assert(offsetof(BP_BetaGroveExterior_C_UpdateAnimInstanceState, K2Node_DynamicCast_bSuccess) == 0x000010, "Member 'BP_BetaGroveExterior_C_UpdateAnimInstanceState::K2Node_DynamicCast_bSuccess' has a wrong offset!");

}

