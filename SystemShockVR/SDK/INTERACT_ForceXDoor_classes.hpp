#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_ForceXDoor

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "INTERACT_DoorBase_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass INTERACT_ForceXDoor.INTERACT_ForceXDoor_C
// 0x00B0 (0x0708 - 0x0658)
class AINTERACT_ForceXDoor_C final : public AINTERACT_DoorBase_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_INTERACT_ForceXDoor_C;              // 0x0658(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCOMP_VoxelAudio_C*                     IdleAudio;                                         // 0x0660(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          TileCollision_Lower;                               // 0x0668(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          TileCollision_Right;                               // 0x0670(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          TileCollision_Left;                                // 0x0678(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          TileCollision_Upper;                               // 0x0680(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   DoorFrame;                                         // 0x0688(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          LaserBlock;                                        // 0x0690(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               ForceXMaterialInstance;                            // 0x0698(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               ForceMaterialInstance;                             // 0x06A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               LaserMaterialInstance;                             // 0x06A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         GlowTransitionDuration;                            // 0x06B0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         GlowTransitionStartTime;                           // 0x06B4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               OpeningCue;                                        // 0x06B8(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               ClosingCue;                                        // 0x06E0(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_INTERACT_ForceXDoor(int32 EntryPoint);
	void ReceiveTick(float DeltaSeconds);
	void CloseDoor();
	void OpenDoor(class AActor* SourceActor);
	void ReceiveBeginPlay();
	void IsSafeToClose(bool* Result);
	void UpdateMaterial();
	void UpdateAnimBP();
	void EVENT_OnStateFinished();
	void GetActiveMontageDuration(float* Duration);
	void UpdateDoorEmissiveStrength(float Scale, float* Strength);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"INTERACT_ForceXDoor_C">();
	}
	static class AINTERACT_ForceXDoor_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AINTERACT_ForceXDoor_C>();
	}
};
static_assert(alignof(AINTERACT_ForceXDoor_C) == 0x000008, "Wrong alignment on AINTERACT_ForceXDoor_C");
static_assert(sizeof(AINTERACT_ForceXDoor_C) == 0x000708, "Wrong size on AINTERACT_ForceXDoor_C");
static_assert(offsetof(AINTERACT_ForceXDoor_C, UberGraphFrame_INTERACT_ForceXDoor_C) == 0x000658, "Member 'AINTERACT_ForceXDoor_C::UberGraphFrame_INTERACT_ForceXDoor_C' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, IdleAudio) == 0x000660, "Member 'AINTERACT_ForceXDoor_C::IdleAudio' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, TileCollision_Lower) == 0x000668, "Member 'AINTERACT_ForceXDoor_C::TileCollision_Lower' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, TileCollision_Right) == 0x000670, "Member 'AINTERACT_ForceXDoor_C::TileCollision_Right' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, TileCollision_Left) == 0x000678, "Member 'AINTERACT_ForceXDoor_C::TileCollision_Left' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, TileCollision_Upper) == 0x000680, "Member 'AINTERACT_ForceXDoor_C::TileCollision_Upper' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, DoorFrame) == 0x000688, "Member 'AINTERACT_ForceXDoor_C::DoorFrame' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, LaserBlock) == 0x000690, "Member 'AINTERACT_ForceXDoor_C::LaserBlock' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, ForceXMaterialInstance) == 0x000698, "Member 'AINTERACT_ForceXDoor_C::ForceXMaterialInstance' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, ForceMaterialInstance) == 0x0006A0, "Member 'AINTERACT_ForceXDoor_C::ForceMaterialInstance' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, LaserMaterialInstance) == 0x0006A8, "Member 'AINTERACT_ForceXDoor_C::LaserMaterialInstance' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, GlowTransitionDuration) == 0x0006B0, "Member 'AINTERACT_ForceXDoor_C::GlowTransitionDuration' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, GlowTransitionStartTime) == 0x0006B4, "Member 'AINTERACT_ForceXDoor_C::GlowTransitionStartTime' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, OpeningCue) == 0x0006B8, "Member 'AINTERACT_ForceXDoor_C::OpeningCue' has a wrong offset!");
static_assert(offsetof(AINTERACT_ForceXDoor_C, ClosingCue) == 0x0006E0, "Member 'AINTERACT_ForceXDoor_C::ClosingCue' has a wrong offset!");

}

