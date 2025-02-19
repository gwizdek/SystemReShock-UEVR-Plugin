#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SERV_Combat_EvaluatePosition

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "AIModule_classes.hpp"
#include "ENUM_SpeedType_structs.hpp"
#include "ENUM_PreferredCombatStyle_structs.hpp"
#include "ENUM_MoveSpeed_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass SERV_Combat_EvaluatePosition.SERV_Combat_EvaluatePosition_C
// 0x0038 (0x00D0 - 0x0098)
class USERV_Combat_EvaluatePosition_C final : public UBTService_BlueprintBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0098(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class APAWN_Enemy_C*                          OwnerPawn;                                         // 0x00A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UOBJ_EnemyTarget_C*                     MoveDirectionTarget;                               // 0x00A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DesireToGetNewNavTarget;                           // 0x00B0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DesireToReposition;                                // 0x00B4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UVoxelSpatialNavigationQuery*           NavQuery;                                          // 0x00B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DisplayDebugInfo;                                  // 0x00C0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_C1[0x3];                                       // 0x00C1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         LastUpdatedTimestamp;                              // 0x00C4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ManeuverRetryTimestamp;                            // 0x00C8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_SERV_Combat_EvaluatePosition(int32 EntryPoint);
	void ReceiveActivationAI(class AAIController* OwnerController, class APawn* ControlledPawn);
	void ReceiveTickAI(class AAIController* OwnerController, class APawn* ControlledPawn, float DeltaSeconds);
	void IsMoving(bool* Result);
	void GetFrameDesireForNewNavTarget(float DeltaSeconds, float* FrameDesire);
	void GetFrameDesireToMoveCloser(float DeltaSeconds, float* FrameDesire);
	void GetSkillTargetAgentLocation(struct FVector* TargetLocation);
	void UpdateState(float DeltaSeconds);
	void UpdateTargetLocation(float DeltaSeconds);
	void InitializeMovement();
	void GetFrameDesireToMoveAway(float DeltaSeconds, float* FrameDesire);
	void GetDistanceToSkillTarget(float* Distance);
	void GetDistanceToManeuverLocation(float* Distance);
	void GetDistanceFromNavToSkillTarget(float* Distance);
	void GetDistanceFromManeuverLocToSkillLoc(float* Distance);
	void GetPawnTouchingDistance(float* Distance);
	void GetPerfectDistance(float* Distance);
	void GetWalkDistance(float* Distance);
	void GetJogDistance(float* Distance);
	void GetSprintDistance(float* Distance);
	void IsNavigatingDirectlyToSkillTarget(bool* Result);
	void GetNavTargetLocation(struct FVector* Location);
	void MakeGroundManeuverEQSQuery(class UVoxelSpatialNavigationQuery** Query);
	void EVENT_OnManeuverQueryFinished(bool bResult, const TArray<struct FVector4>& WeightedWorldLocations);
	void GetPerfectDistanceBufferRange(float* BufferRange);
	void GetDirectionToManeuverTarget(struct FVector* Direction);
	void GetDirectionToSkillTarget(struct FVector* Direction);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SERV_Combat_EvaluatePosition_C">();
	}
	static class USERV_Combat_EvaluatePosition_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USERV_Combat_EvaluatePosition_C>();
	}
};
static_assert(alignof(USERV_Combat_EvaluatePosition_C) == 0x000008, "Wrong alignment on USERV_Combat_EvaluatePosition_C");
static_assert(sizeof(USERV_Combat_EvaluatePosition_C) == 0x0000D0, "Wrong size on USERV_Combat_EvaluatePosition_C");
static_assert(offsetof(USERV_Combat_EvaluatePosition_C, UberGraphFrame) == 0x000098, "Member 'USERV_Combat_EvaluatePosition_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(USERV_Combat_EvaluatePosition_C, OwnerPawn) == 0x0000A0, "Member 'USERV_Combat_EvaluatePosition_C::OwnerPawn' has a wrong offset!");
static_assert(offsetof(USERV_Combat_EvaluatePosition_C, MoveDirectionTarget) == 0x0000A8, "Member 'USERV_Combat_EvaluatePosition_C::MoveDirectionTarget' has a wrong offset!");
static_assert(offsetof(USERV_Combat_EvaluatePosition_C, DesireToGetNewNavTarget) == 0x0000B0, "Member 'USERV_Combat_EvaluatePosition_C::DesireToGetNewNavTarget' has a wrong offset!");
static_assert(offsetof(USERV_Combat_EvaluatePosition_C, DesireToReposition) == 0x0000B4, "Member 'USERV_Combat_EvaluatePosition_C::DesireToReposition' has a wrong offset!");
static_assert(offsetof(USERV_Combat_EvaluatePosition_C, NavQuery) == 0x0000B8, "Member 'USERV_Combat_EvaluatePosition_C::NavQuery' has a wrong offset!");
static_assert(offsetof(USERV_Combat_EvaluatePosition_C, DisplayDebugInfo) == 0x0000C0, "Member 'USERV_Combat_EvaluatePosition_C::DisplayDebugInfo' has a wrong offset!");
static_assert(offsetof(USERV_Combat_EvaluatePosition_C, LastUpdatedTimestamp) == 0x0000C4, "Member 'USERV_Combat_EvaluatePosition_C::LastUpdatedTimestamp' has a wrong offset!");
static_assert(offsetof(USERV_Combat_EvaluatePosition_C, ManeuverRetryTimestamp) == 0x0000C8, "Member 'USERV_Combat_EvaluatePosition_C::ManeuverRetryTimestamp' has a wrong offset!");

}

