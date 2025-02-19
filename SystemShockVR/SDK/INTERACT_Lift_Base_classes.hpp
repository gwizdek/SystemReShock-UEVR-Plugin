#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_Lift_Base

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "INTERACT_Base_classes.hpp"
#include "ENUM_InteractionType_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass INTERACT_Lift_Base.INTERACT_Lift_Base_C
// 0x00D0 (0x03D8 - 0x0308)
class AINTERACT_Lift_Base_C : public AINTERACT_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_INTERACT_Lift_Base_C;               // 0x0308(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCOMP_AttribManager_C*                  COMP_AttribManager;                                // 0x0310(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCOMP_CullableNavModifier_C*            COMP_CullableNavModifier;                          // 0x0318(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCOMP_VoxelOccluder_C*                  COMP_VoxelOccluder;                                // 0x0320(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          SafetySensor;                                      // 0x0328(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          PlatformCollision;                                 // 0x0330(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   LiftMesh;                                          // 0x0338(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class APatrolNode_C*                          StartNode;                                         // 0x0340(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MaxSpeed;                                          // 0x0348(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         AccelerationTime;                                  // 0x034C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APatrolNode_C*                          CurrentNode;                                       // 0x0350(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HasBeenInitialized;                                // 0x0358(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	bool                                          IsDisabled;                                        // 0x0359(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	bool                                          IsMoving;                                          // 0x035A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	uint8                                         Pad_35B[0x1];                                      // 0x035B(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                MovementDirection;                                 // 0x035C(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TotalMovementDistance;                             // 0x0368(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CurrentMovementTime;                               // 0x036C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          StartsEnabled;                                     // 0x0370(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_371[0x7];                                      // 0x0371(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   ActivateMessage;                                   // 0x0378(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   BusyMessage;                                       // 0x0390(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   NotSafeMessage;                                    // 0x03A8(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   LiftDisabledMessage;                               // 0x03C0(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void ExecuteUbergraph_INTERACT_Lift_Base(int32 EntryPoint);
	void ReceiveTick(float DeltaSeconds);
	void ReceiveBeginPlay();
	void UserConstructionScript();
	void GetTargetShape(class UPrimitiveComponent* CursorPrimitive, class UShapeComponent** ShapeComponent);
	void TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults);
	void InitializeLift();
	void InitializeAttributes();
	void UpdateEmissiveStrength(float Scale);
	void ComputeLiftMoveParameters();
	void BeginLiftMovement();
	void TryUpdateLiftMovement(float Elapsed_Time, bool* Result);
	void UpdateLiftMovement(float Elapsed_Time);
	void UpdateLiftLocation(float Displacement);
	void FinishLiftMovement();
	void PlayStartFX();
	void PlayStopFX();
	void IsLiftFunctional(bool* Result);
	void IsSafeToMove(bool* Result);
	void SetInteractLocked(bool Locked, bool* Result);
	void GetInteractLocked(class AActor* SourceActor, bool* Result, class FText* LockMessage);
	void IsLiftEnabled(bool* Result);
	void GetInteractBusy(bool* Result, class FText* BusyMessage_0);
	void IsLiftMoving(bool* Result);
	void GetMoveDirection(struct FVector* Result);
	void GetTargetLocation(struct FVector* Location);
	void GetTargetRotation(struct FRotator* Rotation);
	void IsInteractActivated(bool* Result);
	void EVENT_OnDisableAttribChanged(float CurrValue, float LastValue);
	void GetCurrentMovementTime(float* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"INTERACT_Lift_Base_C">();
	}
	static class AINTERACT_Lift_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AINTERACT_Lift_Base_C>();
	}
};
static_assert(alignof(AINTERACT_Lift_Base_C) == 0x000008, "Wrong alignment on AINTERACT_Lift_Base_C");
static_assert(sizeof(AINTERACT_Lift_Base_C) == 0x0003D8, "Wrong size on AINTERACT_Lift_Base_C");
static_assert(offsetof(AINTERACT_Lift_Base_C, UberGraphFrame_INTERACT_Lift_Base_C) == 0x000308, "Member 'AINTERACT_Lift_Base_C::UberGraphFrame_INTERACT_Lift_Base_C' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, COMP_AttribManager) == 0x000310, "Member 'AINTERACT_Lift_Base_C::COMP_AttribManager' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, COMP_CullableNavModifier) == 0x000318, "Member 'AINTERACT_Lift_Base_C::COMP_CullableNavModifier' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, COMP_VoxelOccluder) == 0x000320, "Member 'AINTERACT_Lift_Base_C::COMP_VoxelOccluder' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, SafetySensor) == 0x000328, "Member 'AINTERACT_Lift_Base_C::SafetySensor' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, PlatformCollision) == 0x000330, "Member 'AINTERACT_Lift_Base_C::PlatformCollision' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, LiftMesh) == 0x000338, "Member 'AINTERACT_Lift_Base_C::LiftMesh' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, StartNode) == 0x000340, "Member 'AINTERACT_Lift_Base_C::StartNode' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, MaxSpeed) == 0x000348, "Member 'AINTERACT_Lift_Base_C::MaxSpeed' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, AccelerationTime) == 0x00034C, "Member 'AINTERACT_Lift_Base_C::AccelerationTime' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, CurrentNode) == 0x000350, "Member 'AINTERACT_Lift_Base_C::CurrentNode' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, HasBeenInitialized) == 0x000358, "Member 'AINTERACT_Lift_Base_C::HasBeenInitialized' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, IsDisabled) == 0x000359, "Member 'AINTERACT_Lift_Base_C::IsDisabled' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, IsMoving) == 0x00035A, "Member 'AINTERACT_Lift_Base_C::IsMoving' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, MovementDirection) == 0x00035C, "Member 'AINTERACT_Lift_Base_C::MovementDirection' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, TotalMovementDistance) == 0x000368, "Member 'AINTERACT_Lift_Base_C::TotalMovementDistance' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, CurrentMovementTime) == 0x00036C, "Member 'AINTERACT_Lift_Base_C::CurrentMovementTime' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, StartsEnabled) == 0x000370, "Member 'AINTERACT_Lift_Base_C::StartsEnabled' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, ActivateMessage) == 0x000378, "Member 'AINTERACT_Lift_Base_C::ActivateMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, BusyMessage) == 0x000390, "Member 'AINTERACT_Lift_Base_C::BusyMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, NotSafeMessage) == 0x0003A8, "Member 'AINTERACT_Lift_Base_C::NotSafeMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_Lift_Base_C, LiftDisabledMessage) == 0x0003C0, "Member 'AINTERACT_Lift_Base_C::LiftDisabledMessage' has a wrong offset!");

}

