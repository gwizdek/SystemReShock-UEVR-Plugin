#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: InventoryFunctionLibrary

#include "Basic.hpp"

#include "ENUM_ItemType_structs.hpp"
#include "Engine_classes.hpp"
#include "ENUM_Axis_structs.hpp"
#include "ENUM_WeaponProperty_structs.hpp"
#include "ENUM_UpgradeResult_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass InventoryFunctionLibrary.InventoryFunctionLibrary_C
// 0x0000 (0x0028 - 0x0028)
class UInventoryFunctionLibrary_C final : public UBlueprintFunctionLibrary
{
public:
	static void CreateInventoryItem(const struct FSTRUCT_HardItemParams& ItemParams, class UObject* __WorldContext, class UITEM_Base_C** Item);
	static void CreateHardItemParams(const struct FSTRUCT_SoftItemParams& SoftParams, class UObject* __WorldContext, struct FSTRUCT_HardItemParams* Result);
	static void UpdateItemWidgetPosition(class UInventoryBag_C* InventoryBag, int32 SlotIndex, class UGridMeshWidget* BagMeshWidget, class UWIDGET_SlottedItem_C* ItemMeshWidget, class UObject* __WorldContext);
	static void GetItemTypePriority(ENUM_ItemType ItemType, class UObject* __WorldContext, int32* Result);
	static void GetItemWidgetPositionFromCoords(const struct FIntPoint& GridCoords, class UGridMeshWidget* BagMeshWidget, class UObject* __WorldContext, struct FVector2D* ResultPosition);
	static void IsUpgradeRecurse(class UClass* UpgradeClass, class UClass* DowngradeClass, class UObject* __WorldContext, bool* Result);
	static void GetUpgradeMessageFromResult(class UClass* ItemClass, ENUM_UpgradeResult UpgradeResult, class UObject* __WorldContext, class FText* Result);
	static void GetUpgradeVersionNumber(class UClass* UpgradeClass, class UObject* __WorldContext, int32* Version);
	static void GetPickupMessageForItemClass(class UClass* ItemClass, class UObject* __WorldContext, class FText* Result);
	static void UpdateItemWidgetPositionFromCoords(const struct FIntPoint& GridCoords, class UGridMeshWidget* BagMeshWidget, class UWIDGET_SlottedItem_C* ItemMeshWidget, class UObject* __WorldContext);
	static void GetInventoryDescriptionText(const class FText& BaseMessage, bool IsInventoryEmpty, class UObject* __WorldContext, class FText* ResultMessage);
	static void GetFormattedWeaponDamageText(const struct FSTRUCT_WeaponMode& WeaponMode, bool IsMaintain, bool ShowSecondaryDamage, bool CombineDamageValues, class UObject* __WorldContext, class FText* Result);
	static void GetWeaponModeDamageTypeText(struct FSTRUCT_WeaponMode& Mode, class UObject* __WorldContext, class FText* Text);
	static void GetWeaponModeArmorPenetrationText(struct FSTRUCT_WeaponMode& Mode, bool ShowSecondaryAP, class UObject* __WorldContext, class FText* Text);
	static void GetWeaponPropertyValueByType(struct FSTRUCT_WeaponMode& WeaponMode, ENUM_WeaponProperty PropertyType, class UObject* __WorldContext, int32* Value);
	static void GetWeaponPropertyIndexByType(struct FSTRUCT_WeaponMode& WeaponMode, ENUM_WeaponProperty PropertyType, class UObject* __WorldContext, int32* ArrayIndex);
	static void FindWeaponPropertyByType(struct FSTRUCT_WeaponMode& WeaponMode, ENUM_WeaponProperty PropertyType, class UObject* __WorldContext, bool* Exists, int32* Value);
	static void GetWeaponModeIndexForAmmo(class UClass* WeaponClass, class UClass* AmmoClass, class UObject* __WorldContext, int32* ModeIndex);
	static void GetWeaponModeNameByIndex(int32 ModeIndex, class UObject* __WorldContext, class FName* ModeName);
	static void GetIdealDistanceToPickupActor(class USceneCaptureComponent2D* CaptureComponent, class APICKUP_Base_C* PickupActor, const struct FVector& BoxHalfExtents, bool SmartDepthAdjust, class UObject* __WorldContext, float* ResultDistance);
	static void ComputePickupPackingRotation(class APICKUP_Base_C* PickupActor, class UObject* __WorldContext, struct FRotator* Rotation);
	static void ApplyPickupPackingTransform(class APICKUP_Base_C* PickupActor, class UBoxComponent* PackingVolume, const struct FSTRUCT_ItemDetailsIconParams& CustomIconParams, const struct FRotator& AdditionalRotation, bool IgnoreUniqueRotation, class UObject* __WorldContext, struct FVector* LocalMeshOrigin, struct FVector* MeshHalfExtents);
	static void GenerateItemGridIcon(class USceneCaptureComponent2D* CaptureComponent, class APICKUP_Base_C* PickupActor, class UObject* __WorldContext);
	static void GenerateItemHotbarIcon(class USceneCaptureComponent2D* CaptureComponent, class APICKUP_Base_C* PickupActor, class UObject* __WorldContext);
	static void UpdateItemDetailsTexture(class USceneCaptureComponent2D* CaptureComponent, class APICKUP_Base_C* PickupActor, float Progress, const struct FSTRUCT_ItemDetailsIconParams& CustomIconParams, class UObject* __WorldContext, struct FSTRUCT_ItemDetailsIconParams* IconParams);
	static void InitializeItemIconCaptureSettings(class USceneCaptureComponent2D* CaptureComponent, bool DetailsCapture, class UObject* __WorldContext);
	static void CreateItemIconSceneSetup(class USceneCaptureComponent2D* CaptureComponent, class UObject* __WorldContext);
	static void FixupPickupActorMaterials(class APICKUP_Base_C* PickupActor, class UObject* __WorldContext);
	static void SpawnPickupIconActorByClassCollection(class USceneCaptureComponent2D* CaptureComponent, const struct FObjectClassCollection& ClassCollection, class UObject* __WorldContext, class APICKUP_Base_C** SpawnedActor);
	static void SpawnPickupActorWithItemCount(class UClass* ItemClass, int32 ItemCount, const struct FVector& Location, const struct FVector& Velocity, class UObject* __WorldContext, class APICKUP_Base_C** Result);
	static void SpawnPickupActorFromItemInstance(class UITEM_Base_C* Item, const struct FVector& Location, const struct FVector& Velocity, class UObject* __WorldContext, class APICKUP_Base_C** Result);
	static void GetBestBatteryClassForEnergyLevel(int32 CurrentEnergy, int32 MaxEnergy, class UObject* __WorldContext, bool* IsValid, TSoftClassPtr<class UClass>* BestClass, TSoftClassPtr<class UClass>* FallbackClass);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"InventoryFunctionLibrary_C">();
	}
	static class UInventoryFunctionLibrary_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UInventoryFunctionLibrary_C>();
	}
};
static_assert(alignof(UInventoryFunctionLibrary_C) == 0x000008, "Wrong alignment on UInventoryFunctionLibrary_C");
static_assert(sizeof(UInventoryFunctionLibrary_C) == 0x000028, "Wrong size on UInventoryFunctionLibrary_C");

}

