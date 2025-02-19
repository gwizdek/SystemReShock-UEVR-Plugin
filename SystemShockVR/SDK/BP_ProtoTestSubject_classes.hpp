#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ProtoTestSubject

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_ProtoTestSubject.BP_ProtoTestSubject_C
// 0x0028 (0x0248 - 0x0220)
class ABP_ProtoTestSubject_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCOMP_VoxelCullable_C*                  COMP_VoxelCullable;                                // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USkeletalMeshComponent*                 SK_PrototypeTestSubject;                           // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointOfInterestComponent_C*            PointOfInterestComponent;                          // 0x0238(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCOMP_Descriptor_C*                     COMP_Descriptor;                                   // 0x0240(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_BP_ProtoTestSubject(int32 EntryPoint);
	void BndEvt__BP_ProtoTestSubject_COMP_VoxelCullable_K2Node_ComponentBoundEvent_0_CullableVisibilitySignature__DelegateSignature(bool bVisibleState);
	void UpdateVisibility(bool VisibilityState);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_ProtoTestSubject_C">();
	}
	static class ABP_ProtoTestSubject_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_ProtoTestSubject_C>();
	}
};
static_assert(alignof(ABP_ProtoTestSubject_C) == 0x000008, "Wrong alignment on ABP_ProtoTestSubject_C");
static_assert(sizeof(ABP_ProtoTestSubject_C) == 0x000248, "Wrong size on ABP_ProtoTestSubject_C");
static_assert(offsetof(ABP_ProtoTestSubject_C, UberGraphFrame) == 0x000220, "Member 'ABP_ProtoTestSubject_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ABP_ProtoTestSubject_C, COMP_VoxelCullable) == 0x000228, "Member 'ABP_ProtoTestSubject_C::COMP_VoxelCullable' has a wrong offset!");
static_assert(offsetof(ABP_ProtoTestSubject_C, SK_PrototypeTestSubject) == 0x000230, "Member 'ABP_ProtoTestSubject_C::SK_PrototypeTestSubject' has a wrong offset!");
static_assert(offsetof(ABP_ProtoTestSubject_C, PointOfInterestComponent) == 0x000238, "Member 'ABP_ProtoTestSubject_C::PointOfInterestComponent' has a wrong offset!");
static_assert(offsetof(ABP_ProtoTestSubject_C, COMP_Descriptor) == 0x000240, "Member 'ABP_ProtoTestSubject_C::COMP_Descriptor' has a wrong offset!");

}

