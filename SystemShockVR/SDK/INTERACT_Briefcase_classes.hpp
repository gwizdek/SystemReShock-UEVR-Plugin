#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_Briefcase

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "INTERACT_Base_classes.hpp"
#include "ENUM_InteractionType_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass INTERACT_Briefcase.INTERACT_Briefcase_C
// 0x00D0 (0x03D8 - 0x0308)
class AINTERACT_Briefcase_C final : public AINTERACT_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_INTERACT_Briefcase_C;               // 0x0308(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCOMP_AttribManager_C*                  COMP_AttribManager;                                // 0x0310(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCOMP_VoxelCullable_C*                  COMP_VoxelCullable;                                // 0x0318(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          BaseCollisionBox;                                  // 0x0320(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          ScanBox;                                           // 0x0328(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          TargetBox;                                         // 0x0330(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USkeletalMeshComponent*                 SkeletalMesh;                                      // 0x0338(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	bool                                          IsOpen;                                            // 0x0340(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	uint8                                         Pad_341[0x7];                                      // 0x0341(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UAnimMontage>            OpenMontage;                                       // 0x0348(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            CloseMontage;                                      // 0x0370(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	class FText                                   OpenMessage;                                       // 0x0398(0x0018)(Edit, BlueprintVisible)
	class FText                                   CloseMessage;                                      // 0x03B0(0x0018)(Edit, BlueprintVisible)
	struct FDataTableRowHandle                    CompleteTutorialOnOpen;                            // 0x03C8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)

public:
	void ExecuteUbergraph_INTERACT_Briefcase(int32 EntryPoint);
	void BndEvt__COMP_VoxelCullable_K2Node_ComponentBoundEvent_0_CullableVisibilitySignature__DelegateSignature(bool bVisibleState);
	void ReceiveBeginPlay();
	void UserConstructionScript();
	void TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults);
	void GetTargetShape(class UPrimitiveComponent* CursorPrimitive, class UShapeComponent** ShapeComponent);
	void InitializeBriefcase();
	void InitializeAttributes();
	void ToggleBriefcase();
	void UpdateBriefcaseVisibility(bool VisibilityState);
	void TryCompleteOpenTutorial();
	bool ShouldSaveActor(struct FStreamingSaveGameActorParams* Params_0);
	void UpdateAnimationState();
	void EVENT_OnDisableAttribChanged(float CurrValue, float LastValue);
	void UpdateEmissiveStrength(float Scale);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"INTERACT_Briefcase_C">();
	}
	static class AINTERACT_Briefcase_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AINTERACT_Briefcase_C>();
	}
};
static_assert(alignof(AINTERACT_Briefcase_C) == 0x000008, "Wrong alignment on AINTERACT_Briefcase_C");
static_assert(sizeof(AINTERACT_Briefcase_C) == 0x0003D8, "Wrong size on AINTERACT_Briefcase_C");
static_assert(offsetof(AINTERACT_Briefcase_C, UberGraphFrame_INTERACT_Briefcase_C) == 0x000308, "Member 'AINTERACT_Briefcase_C::UberGraphFrame_INTERACT_Briefcase_C' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, COMP_AttribManager) == 0x000310, "Member 'AINTERACT_Briefcase_C::COMP_AttribManager' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, COMP_VoxelCullable) == 0x000318, "Member 'AINTERACT_Briefcase_C::COMP_VoxelCullable' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, BaseCollisionBox) == 0x000320, "Member 'AINTERACT_Briefcase_C::BaseCollisionBox' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, ScanBox) == 0x000328, "Member 'AINTERACT_Briefcase_C::ScanBox' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, TargetBox) == 0x000330, "Member 'AINTERACT_Briefcase_C::TargetBox' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, SkeletalMesh) == 0x000338, "Member 'AINTERACT_Briefcase_C::SkeletalMesh' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, IsOpen) == 0x000340, "Member 'AINTERACT_Briefcase_C::IsOpen' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, OpenMontage) == 0x000348, "Member 'AINTERACT_Briefcase_C::OpenMontage' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, CloseMontage) == 0x000370, "Member 'AINTERACT_Briefcase_C::CloseMontage' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, OpenMessage) == 0x000398, "Member 'AINTERACT_Briefcase_C::OpenMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, CloseMessage) == 0x0003B0, "Member 'AINTERACT_Briefcase_C::CloseMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_Briefcase_C, CompleteTutorialOnOpen) == 0x0003C8, "Member 'AINTERACT_Briefcase_C::CompleteTutorialOnOpen' has a wrong offset!");

}

