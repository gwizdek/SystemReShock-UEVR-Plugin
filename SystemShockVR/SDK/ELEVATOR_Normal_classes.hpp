#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ELEVATOR_Normal

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "ELEVATOR_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass ELEVATOR_Normal.ELEVATOR_Normal_C
// 0x00B8 (0x0758 - 0x06A0)
class AELEVATOR_Normal_C final : public AELEVATOR_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_ELEVATOR_Normal_C;                  // 0x06A0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class USceneComponent*                        CineMountNode;                                     // 0x06A8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          ControlButton3_TargetBox;                          // 0x06B0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          ControlButton2_TargetBox;                          // 0x06B8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          ControlButton1_TargetBox;                          // 0x06C0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   ElevatorControlsMesh;                              // 0x06C8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class URectLightComponent*                    RectLight1;                                        // 0x06D0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          RightDoorCollision;                                // 0x06D8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          LeftDoorCollision;                                 // 0x06E0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   PointLight6;                                       // 0x06E8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   PointLight11;                                      // 0x06F0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   PointLight10;                                      // 0x06F8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   PointLight9;                                       // 0x0700(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   PointLight8;                                       // 0x0708(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   PointLight7;                                       // 0x0710(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        ButtonParent;                                      // 0x0718(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class FName                                   DeckDisplayParam;                                  // 0x0720(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               ScreenMaterial;                                    // 0x0728(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMOVECONTROL_WorldMove_C*               CinematicMoveControl;                              // 0x0730(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CinematicMoveDuration;                             // 0x0738(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_73C[0x4];                                      // 0x073C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInstanceDynamic*               BroadcastMaterialInstance;                         // 0x0740(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UWidgetComponent*                       BroadcastWidgetComponent;                          // 0x0748(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UBROADCAST_Base_C*                      CurrentBroadcastContent;                           // 0x0750(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void UpdateControlLockState(bool IsLocked);
	void UpdateEmissiveStrength(float Scale);
	void OnCinematicLevelLoaded();
	void CreateCinematicMoveControl();
	void UpdateCinematicBroadcast(float DeltaTime);
	void PlayCinematicBroadcast();
	void SetElevatorTargetLevel(class UPrimitiveComponent* CursorPrimitive, class FName NewTargetLevel);
	void GetControlsMeshComponent(class UStaticMeshComponent** MeshComponent);
	void SetElevatorEnabled(bool Enabled);
	void SetElevatorVisibility(bool VisibilityState);
	void UpdateCurrentScreenFloorPosition();
	void SetScreenFloorPosition(int32 DeckNumber);
	void InitializeElevatorControls();
	void UserConstructionScript();
	void StreamInCinematicLevel();
	void StreamOutCinematicLevel();
	void UpdateBroadcastRenderTarget();
	void ReceiveTick(float DeltaSeconds);
	void ExecuteUbergraph_ELEVATOR_Normal(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ELEVATOR_Normal_C">();
	}
	static class AELEVATOR_Normal_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AELEVATOR_Normal_C>();
	}
};
static_assert(alignof(AELEVATOR_Normal_C) == 0x000008, "Wrong alignment on AELEVATOR_Normal_C");
static_assert(sizeof(AELEVATOR_Normal_C) == 0x000758, "Wrong size on AELEVATOR_Normal_C");
static_assert(offsetof(AELEVATOR_Normal_C, UberGraphFrame_ELEVATOR_Normal_C) == 0x0006A0, "Member 'AELEVATOR_Normal_C::UberGraphFrame_ELEVATOR_Normal_C' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, CineMountNode) == 0x0006A8, "Member 'AELEVATOR_Normal_C::CineMountNode' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, ControlButton3_TargetBox) == 0x0006B0, "Member 'AELEVATOR_Normal_C::ControlButton3_TargetBox' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, ControlButton2_TargetBox) == 0x0006B8, "Member 'AELEVATOR_Normal_C::ControlButton2_TargetBox' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, ControlButton1_TargetBox) == 0x0006C0, "Member 'AELEVATOR_Normal_C::ControlButton1_TargetBox' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, ElevatorControlsMesh) == 0x0006C8, "Member 'AELEVATOR_Normal_C::ElevatorControlsMesh' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, RectLight1) == 0x0006D0, "Member 'AELEVATOR_Normal_C::RectLight1' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, RightDoorCollision) == 0x0006D8, "Member 'AELEVATOR_Normal_C::RightDoorCollision' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, LeftDoorCollision) == 0x0006E0, "Member 'AELEVATOR_Normal_C::LeftDoorCollision' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, PointLight6) == 0x0006E8, "Member 'AELEVATOR_Normal_C::PointLight6' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, PointLight11) == 0x0006F0, "Member 'AELEVATOR_Normal_C::PointLight11' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, PointLight10) == 0x0006F8, "Member 'AELEVATOR_Normal_C::PointLight10' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, PointLight9) == 0x000700, "Member 'AELEVATOR_Normal_C::PointLight9' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, PointLight8) == 0x000708, "Member 'AELEVATOR_Normal_C::PointLight8' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, PointLight7) == 0x000710, "Member 'AELEVATOR_Normal_C::PointLight7' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, ButtonParent) == 0x000718, "Member 'AELEVATOR_Normal_C::ButtonParent' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, DeckDisplayParam) == 0x000720, "Member 'AELEVATOR_Normal_C::DeckDisplayParam' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, ScreenMaterial) == 0x000728, "Member 'AELEVATOR_Normal_C::ScreenMaterial' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, CinematicMoveControl) == 0x000730, "Member 'AELEVATOR_Normal_C::CinematicMoveControl' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, CinematicMoveDuration) == 0x000738, "Member 'AELEVATOR_Normal_C::CinematicMoveDuration' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, BroadcastMaterialInstance) == 0x000740, "Member 'AELEVATOR_Normal_C::BroadcastMaterialInstance' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, BroadcastWidgetComponent) == 0x000748, "Member 'AELEVATOR_Normal_C::BroadcastWidgetComponent' has a wrong offset!");
static_assert(offsetof(AELEVATOR_Normal_C, CurrentBroadcastContent) == 0x000750, "Member 'AELEVATOR_Normal_C::CurrentBroadcastContent' has a wrong offset!");

}

