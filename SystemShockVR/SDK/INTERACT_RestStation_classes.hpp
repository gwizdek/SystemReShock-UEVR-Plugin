#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERACT_RestStation

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "INTERACT_Base_classes.hpp"
#include "LevelVoxelization_structs.hpp"
#include "ENUM_InteractionType_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass INTERACT_RestStation.INTERACT_RestStation_C
// 0x0348 (0x0650 - 0x0308)
class AINTERACT_RestStation_C final : public AINTERACT_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_INTERACT_RestStation_C;             // 0x0308(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCOMP_AttribManager_C*                  COMP_AttribManager;                                // 0x0310(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCOMP_CullableNavModifier_C*            COMP_CullableNavModifier;                          // 0x0318(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        ToiletSoundLocation;                               // 0x0320(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        Audio_Faucet;                                      // 0x0328(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          MotionSensor_Door;                                 // 0x0330(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCapsuleComponent*                      MotionSensor_Containment;                          // 0x0338(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               P_WaterFaucet;                                     // 0x0340(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          TargetBox_sink;                                    // 0x0348(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          ScanBox_sink;                                      // 0x0350(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USpotLightComponent*                    SpotLight;                                         // 0x0358(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          TargetBox_SeatCover;                               // 0x0360(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          ScanBox_inner;                                     // 0x0368(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          ScanBox_outer;                                     // 0x0370(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          TargetBox_inner;                                   // 0x0378(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          TargetBox_outer;                                   // 0x0380(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USkeletalMeshComponent*                 SK_RestStation_SeatCover;                          // 0x0388(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USkeletalMeshComponent*                 SK_RestStation_Door;                               // 0x0390(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   RestStation_Base;                                  // 0x0398(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	bool                                          DoorStartsOpen;                                    // 0x03A0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          DoorStartsLocked;                                  // 0x03A1(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          IsBroken;                                          // 0x03A2(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          DoorIsOpen;                                        // 0x03A3(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	bool                                          DoorIsLocked;                                      // 0x03A4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	bool                                          HasBeenInitialized;                                // 0x03A5(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	bool                                          SeatCoverStartsUp;                                 // 0x03A6(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          SeatCoverIsUp;                                     // 0x03A7(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	bool                                          IsFaucetRunning;                                   // 0x03A8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3A9[0x7];                                      // 0x03A9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UAnimMontage>            DoorOpenMontage;                                   // 0x03B0(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            DoorCloseMontage;                                  // 0x03D8(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            ButtonOpenMontage;                                 // 0x0400(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            ButtonCloseMontage;                                // 0x0428(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            SeatCoverOpenMontage;                              // 0x0450(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            SeatCoverCloseMontage;                             // 0x0478(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TSoftObjectPtr<class UFXSystemAsset>          FaucetFX;                                          // 0x04A0(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               DoorMaterial;                                      // 0x04C8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               VacancyMaterial;                                   // 0x04D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               ContainmentSensorMaterial;                         // 0x04D8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DoorTransitionTimestamp;                           // 0x04E0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ButtonColorBlendDuration;                          // 0x04E4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ButtonLockStateChangedTimestamp;                   // 0x04E8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         AutoCloseDuration;                                 // 0x04EC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           AutoCloseTimerHandle;                              // 0x04F0(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class FText                                   DoorBrokenMessage;                                 // 0x04F8(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   DoorLockedMessage;                                 // 0x0510(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   DoorMovingMessage;                                 // 0x0528(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   SeatCoverToggledMessage;                           // 0x0540(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   DoorOpenedMessage;                                 // 0x0558(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   FaucetUsedMessage;                                 // 0x0570(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FTimerHandle                           DoorButtonPulseTimerHandle;                        // 0x0588(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           ContainmentBulbPulseTimerHandle;                   // 0x0590(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               FaucetOnCue;                                       // 0x0598(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               FaucetOffCue;                                      // 0x05C0(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               FaucetLoopCue;                                     // 0x05E8(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               ToiletCue;                                         // 0x0610(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	class FText                                   FaucetNotWorkingMessage;                           // 0x0638(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)

public:
	void ExecuteUbergraph_INTERACT_RestStation(int32 EntryPoint);
	void BndEvt__Interact_RestStation_COMP_CullableNavModifier_K2Node_ComponentBoundEvent_1_CullableVisibilitySignature__DelegateSignature(bool bVisibleState);
	void ReceiveTick(float DeltaSeconds);
	void BndEvt__MotionSensor_Door_K2Node_ComponentBoundEvent_3_ComponentEndOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	void BndEvt__MotionSensor_Door_K2Node_ComponentBoundEvent_2_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	void ReceiveBeginPlay();
	void UserConstructionScript();
	void GetTargetShape(class UPrimitiveComponent* CursorPrimitive, class UShapeComponent** ShapeComponent);
	void TryInteract(class AActor* SourceActor, class UPrimitiveComponent* CursorPrimitive, ENUM_InteractionType InteractionType, struct FSTRUCT_InteractResults* InteractResults);
	void InitializeRestStation();
	void InitializeAttributes();
	void InitializeOpenState(bool OpenState);
	void InitializeLockedState(bool LockedState);
	void InitializeSeatCoverState(bool SeatCoverState);
	void ToggleDoor();
	void ToggleSeatCover();
	void OnDoorButtonPulseFinished();
	void TryStartAutoCloseTimer();
	void TryStopAutoCloseTimer();
	void PlayDoorMontageForCurrentState(float StartTime);
	void OpenOrCloseDoor(bool OpenState, float MontageStartTime);
	void TryAutoCloseDoor();
	void LockOrUnlockDoor(bool LockedState);
	void OnDoorMontageFinished();
	void OnLockedMontageFinished();
	void ToggleFaucet();
	void SetFaucetState(bool FaucetState);
	void FlushToilet();
	void UpdateButtonColor(float Progress, bool LockedState);
	void UpdateVacancyColor(bool LockedState);
	void UpdateRestStation();
	void UpdateContainmentSensorLight();
	void OnContainmentBulbPulseFinished();
	void UpdateOverheadLight(bool OpenState);
	void UpdateAuxiliaryLights();
	void UpdateEmissiveStrength(float Scale);
	void TryOpenDoorWhileClosing(bool* Result);
	void EVENT_OnDisableAttribChanged(float CurrValue, float LastValue);
	void EVENT_OnDoorMontageEnded(class UAnimMontage* Montage, bool bInterrupted);
	void UpdateRestStationVisibility(bool VisibilityState);
	void IsHiddenInteractablePrimitive(class APAWN_SystemShockCharacter_C* Character, class UPrimitiveComponent* CursorPrimitive, bool* Result);
	void IsRestStationFunctional(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"INTERACT_RestStation_C">();
	}
	static class AINTERACT_RestStation_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AINTERACT_RestStation_C>();
	}
};
static_assert(alignof(AINTERACT_RestStation_C) == 0x000008, "Wrong alignment on AINTERACT_RestStation_C");
static_assert(sizeof(AINTERACT_RestStation_C) == 0x000650, "Wrong size on AINTERACT_RestStation_C");
static_assert(offsetof(AINTERACT_RestStation_C, UberGraphFrame_INTERACT_RestStation_C) == 0x000308, "Member 'AINTERACT_RestStation_C::UberGraphFrame_INTERACT_RestStation_C' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, COMP_AttribManager) == 0x000310, "Member 'AINTERACT_RestStation_C::COMP_AttribManager' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, COMP_CullableNavModifier) == 0x000318, "Member 'AINTERACT_RestStation_C::COMP_CullableNavModifier' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ToiletSoundLocation) == 0x000320, "Member 'AINTERACT_RestStation_C::ToiletSoundLocation' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, Audio_Faucet) == 0x000328, "Member 'AINTERACT_RestStation_C::Audio_Faucet' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, MotionSensor_Door) == 0x000330, "Member 'AINTERACT_RestStation_C::MotionSensor_Door' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, MotionSensor_Containment) == 0x000338, "Member 'AINTERACT_RestStation_C::MotionSensor_Containment' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, P_WaterFaucet) == 0x000340, "Member 'AINTERACT_RestStation_C::P_WaterFaucet' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, TargetBox_sink) == 0x000348, "Member 'AINTERACT_RestStation_C::TargetBox_sink' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ScanBox_sink) == 0x000350, "Member 'AINTERACT_RestStation_C::ScanBox_sink' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, SpotLight) == 0x000358, "Member 'AINTERACT_RestStation_C::SpotLight' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, TargetBox_SeatCover) == 0x000360, "Member 'AINTERACT_RestStation_C::TargetBox_SeatCover' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ScanBox_inner) == 0x000368, "Member 'AINTERACT_RestStation_C::ScanBox_inner' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ScanBox_outer) == 0x000370, "Member 'AINTERACT_RestStation_C::ScanBox_outer' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, TargetBox_inner) == 0x000378, "Member 'AINTERACT_RestStation_C::TargetBox_inner' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, TargetBox_outer) == 0x000380, "Member 'AINTERACT_RestStation_C::TargetBox_outer' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, SK_RestStation_SeatCover) == 0x000388, "Member 'AINTERACT_RestStation_C::SK_RestStation_SeatCover' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, SK_RestStation_Door) == 0x000390, "Member 'AINTERACT_RestStation_C::SK_RestStation_Door' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, RestStation_Base) == 0x000398, "Member 'AINTERACT_RestStation_C::RestStation_Base' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorStartsOpen) == 0x0003A0, "Member 'AINTERACT_RestStation_C::DoorStartsOpen' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorStartsLocked) == 0x0003A1, "Member 'AINTERACT_RestStation_C::DoorStartsLocked' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, IsBroken) == 0x0003A2, "Member 'AINTERACT_RestStation_C::IsBroken' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorIsOpen) == 0x0003A3, "Member 'AINTERACT_RestStation_C::DoorIsOpen' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorIsLocked) == 0x0003A4, "Member 'AINTERACT_RestStation_C::DoorIsLocked' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, HasBeenInitialized) == 0x0003A5, "Member 'AINTERACT_RestStation_C::HasBeenInitialized' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, SeatCoverStartsUp) == 0x0003A6, "Member 'AINTERACT_RestStation_C::SeatCoverStartsUp' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, SeatCoverIsUp) == 0x0003A7, "Member 'AINTERACT_RestStation_C::SeatCoverIsUp' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, IsFaucetRunning) == 0x0003A8, "Member 'AINTERACT_RestStation_C::IsFaucetRunning' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorOpenMontage) == 0x0003B0, "Member 'AINTERACT_RestStation_C::DoorOpenMontage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorCloseMontage) == 0x0003D8, "Member 'AINTERACT_RestStation_C::DoorCloseMontage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ButtonOpenMontage) == 0x000400, "Member 'AINTERACT_RestStation_C::ButtonOpenMontage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ButtonCloseMontage) == 0x000428, "Member 'AINTERACT_RestStation_C::ButtonCloseMontage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, SeatCoverOpenMontage) == 0x000450, "Member 'AINTERACT_RestStation_C::SeatCoverOpenMontage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, SeatCoverCloseMontage) == 0x000478, "Member 'AINTERACT_RestStation_C::SeatCoverCloseMontage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, FaucetFX) == 0x0004A0, "Member 'AINTERACT_RestStation_C::FaucetFX' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorMaterial) == 0x0004C8, "Member 'AINTERACT_RestStation_C::DoorMaterial' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, VacancyMaterial) == 0x0004D0, "Member 'AINTERACT_RestStation_C::VacancyMaterial' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ContainmentSensorMaterial) == 0x0004D8, "Member 'AINTERACT_RestStation_C::ContainmentSensorMaterial' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorTransitionTimestamp) == 0x0004E0, "Member 'AINTERACT_RestStation_C::DoorTransitionTimestamp' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ButtonColorBlendDuration) == 0x0004E4, "Member 'AINTERACT_RestStation_C::ButtonColorBlendDuration' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ButtonLockStateChangedTimestamp) == 0x0004E8, "Member 'AINTERACT_RestStation_C::ButtonLockStateChangedTimestamp' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, AutoCloseDuration) == 0x0004EC, "Member 'AINTERACT_RestStation_C::AutoCloseDuration' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, AutoCloseTimerHandle) == 0x0004F0, "Member 'AINTERACT_RestStation_C::AutoCloseTimerHandle' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorBrokenMessage) == 0x0004F8, "Member 'AINTERACT_RestStation_C::DoorBrokenMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorLockedMessage) == 0x000510, "Member 'AINTERACT_RestStation_C::DoorLockedMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorMovingMessage) == 0x000528, "Member 'AINTERACT_RestStation_C::DoorMovingMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, SeatCoverToggledMessage) == 0x000540, "Member 'AINTERACT_RestStation_C::SeatCoverToggledMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorOpenedMessage) == 0x000558, "Member 'AINTERACT_RestStation_C::DoorOpenedMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, FaucetUsedMessage) == 0x000570, "Member 'AINTERACT_RestStation_C::FaucetUsedMessage' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, DoorButtonPulseTimerHandle) == 0x000588, "Member 'AINTERACT_RestStation_C::DoorButtonPulseTimerHandle' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ContainmentBulbPulseTimerHandle) == 0x000590, "Member 'AINTERACT_RestStation_C::ContainmentBulbPulseTimerHandle' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, FaucetOnCue) == 0x000598, "Member 'AINTERACT_RestStation_C::FaucetOnCue' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, FaucetOffCue) == 0x0005C0, "Member 'AINTERACT_RestStation_C::FaucetOffCue' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, FaucetLoopCue) == 0x0005E8, "Member 'AINTERACT_RestStation_C::FaucetLoopCue' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, ToiletCue) == 0x000610, "Member 'AINTERACT_RestStation_C::ToiletCue' has a wrong offset!");
static_assert(offsetof(AINTERACT_RestStation_C, FaucetNotWorkingMessage) == 0x000638, "Member 'AINTERACT_RestStation_C::FaucetNotWorkingMessage' has a wrong offset!");

}

