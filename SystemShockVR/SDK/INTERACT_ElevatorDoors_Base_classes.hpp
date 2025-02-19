#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_ElevatorDoors_Base

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "INTERACT_Base_classes.hpp"
#include "ENUM_InteractionType_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass INTERACT_ElevatorDoors_Base.INTERACT_ElevatorDoors_Base_C
// 0x0038 (0x0340 - 0x0308)
class AINTERACT_ElevatorDoors_Base_C : public AINTERACT_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_INTERACT_ElevatorDoors_Base_C;      // 0x0308(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCOMP_AttribManager_C*                  COMP_AttribManager;                                // 0x0310(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCOMP_VoxelOccluder_C*                  COMP_VoxelOccluder;                                // 0x0318(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCOMP_ScannableObject_C*                COMP_ScannableObject;                              // 0x0320(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USkeletalMeshComponent*                 ElevatorDoorsMesh;                                 // 0x0328(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class AELEVATOR_Base_C*                       TargetElevator;                                    // 0x0330(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          IsPowered;                                         // 0x0338(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_INTERACT_ElevatorDoors_Base(int32 EntryPoint);
	void ReceiveBeginPlay();
	void BndEvt__INTERACT_ElevatorDoors_Base_COMP_VoxelOccluder_K2Node_ComponentBoundEvent_1_CullableVisibilitySignature__DelegateSignature(bool bVisibleState);
	void UserConstructionScript();
	void IsDoorwayFunctional(bool* Result);
	void GetElevatorSymbol(class FName* Result);
	void GetTargetElevator(class AELEVATOR_Base_C** Elevator);
	void InitializeElevatorDoor();
	void SetActiveElevator(class AELEVATOR_Base_C* Elevator);
	void SetElevatorDoorsVisible(bool VisibilityState);
	void SetTileCollisionEnabled(bool Enable, bool* Result);
	void EVENT_OnDisableAttribChanged(float CurrValue, float LastValue);
	void UpdateEmissiveStrength(float Scale, float* Result);
	void TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults);
	bool ShouldSaveActor(struct FStreamingSaveGameActorParams* Params_0);
	void SetInteractPowered(bool State, bool* Result);
	void CanModifyInteractPower(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"INTERACT_ElevatorDoors_Base_C">();
	}
	static class AINTERACT_ElevatorDoors_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AINTERACT_ElevatorDoors_Base_C>();
	}
};
static_assert(alignof(AINTERACT_ElevatorDoors_Base_C) == 0x000008, "Wrong alignment on AINTERACT_ElevatorDoors_Base_C");
static_assert(sizeof(AINTERACT_ElevatorDoors_Base_C) == 0x000340, "Wrong size on AINTERACT_ElevatorDoors_Base_C");
static_assert(offsetof(AINTERACT_ElevatorDoors_Base_C, UberGraphFrame_INTERACT_ElevatorDoors_Base_C) == 0x000308, "Member 'AINTERACT_ElevatorDoors_Base_C::UberGraphFrame_INTERACT_ElevatorDoors_Base_C' has a wrong offset!");
static_assert(offsetof(AINTERACT_ElevatorDoors_Base_C, COMP_AttribManager) == 0x000310, "Member 'AINTERACT_ElevatorDoors_Base_C::COMP_AttribManager' has a wrong offset!");
static_assert(offsetof(AINTERACT_ElevatorDoors_Base_C, COMP_VoxelOccluder) == 0x000318, "Member 'AINTERACT_ElevatorDoors_Base_C::COMP_VoxelOccluder' has a wrong offset!");
static_assert(offsetof(AINTERACT_ElevatorDoors_Base_C, COMP_ScannableObject) == 0x000320, "Member 'AINTERACT_ElevatorDoors_Base_C::COMP_ScannableObject' has a wrong offset!");
static_assert(offsetof(AINTERACT_ElevatorDoors_Base_C, ElevatorDoorsMesh) == 0x000328, "Member 'AINTERACT_ElevatorDoors_Base_C::ElevatorDoorsMesh' has a wrong offset!");
static_assert(offsetof(AINTERACT_ElevatorDoors_Base_C, TargetElevator) == 0x000330, "Member 'AINTERACT_ElevatorDoors_Base_C::TargetElevator' has a wrong offset!");
static_assert(offsetof(AINTERACT_ElevatorDoors_Base_C, IsPowered) == 0x000338, "Member 'AINTERACT_ElevatorDoors_Base_C::IsPowered' has a wrong offset!");

}

