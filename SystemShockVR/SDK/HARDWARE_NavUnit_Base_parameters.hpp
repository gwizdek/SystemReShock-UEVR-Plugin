#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HARDWARE_NavUnit_Base

#include "Basic.hpp"

#include "STRUCT_HardwareFeature_structs.hpp"


namespace SDK::Params
{

// Function HARDWARE_NavUnit_Base.HARDWARE_NavUnit_Base_C.SetVoxelScannerActive
// 0x0030 (0x0030 - 0x0000)
struct HARDWARE_NavUnit_Base_C_SetVoxelScannerActive final
{
public:
	bool                                          Active;                                            // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UCOMP_Inventory_C*                      CallFunc_GetInventory_Inventory;                   // 0x0008(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AActor*                                 CallFunc_GetOwner_ReturnValue;                     // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCOMP_Inventory_C*                      CallFunc_GetInventory_Inventory_1;                 // 0x0018(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Hacker_Implant_C*                 K2Node_DynamicCast_AsPAWN_Hacker_Implant;          // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0029(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(HARDWARE_NavUnit_Base_C_SetVoxelScannerActive) == 0x000008, "Wrong alignment on HARDWARE_NavUnit_Base_C_SetVoxelScannerActive");
static_assert(sizeof(HARDWARE_NavUnit_Base_C_SetVoxelScannerActive) == 0x000030, "Wrong size on HARDWARE_NavUnit_Base_C_SetVoxelScannerActive");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_SetVoxelScannerActive, Active) == 0x000000, "Member 'HARDWARE_NavUnit_Base_C_SetVoxelScannerActive::Active' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_SetVoxelScannerActive, CallFunc_GetInventory_Inventory) == 0x000008, "Member 'HARDWARE_NavUnit_Base_C_SetVoxelScannerActive::CallFunc_GetInventory_Inventory' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_SetVoxelScannerActive, CallFunc_GetOwner_ReturnValue) == 0x000010, "Member 'HARDWARE_NavUnit_Base_C_SetVoxelScannerActive::CallFunc_GetOwner_ReturnValue' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_SetVoxelScannerActive, CallFunc_GetInventory_Inventory_1) == 0x000018, "Member 'HARDWARE_NavUnit_Base_C_SetVoxelScannerActive::CallFunc_GetInventory_Inventory_1' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_SetVoxelScannerActive, K2Node_DynamicCast_AsPAWN_Hacker_Implant) == 0x000020, "Member 'HARDWARE_NavUnit_Base_C_SetVoxelScannerActive::K2Node_DynamicCast_AsPAWN_Hacker_Implant' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_SetVoxelScannerActive, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'HARDWARE_NavUnit_Base_C_SetVoxelScannerActive::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_SetVoxelScannerActive, CallFunc_IsValid_ReturnValue) == 0x000029, "Member 'HARDWARE_NavUnit_Base_C_SetVoxelScannerActive::CallFunc_IsValid_ReturnValue' has a wrong offset!");

// Function HARDWARE_NavUnit_Base.HARDWARE_NavUnit_Base_C.UpdateAvailableMapFilterTags
// 0x0070 (0x0070 - 0x0000)
struct HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags final
{
public:
	class UCOMP_VoxelScanner_C*                   VoxelScanner;                                      // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  CallFunc_GetPlayerPawn_ReturnValue;                // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSet<class FName>                             CallFunc_GetMapFilterTags_Tags;                    // 0x0010(0x0050)()
	class APAWN_Hacker_Implant_C*                 K2Node_DynamicCast_AsPAWN_Hacker_Implant;          // 0x0060(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0068(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags) == 0x000008, "Wrong alignment on HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags");
static_assert(sizeof(HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags) == 0x000070, "Wrong size on HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags, VoxelScanner) == 0x000000, "Member 'HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags::VoxelScanner' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags, CallFunc_GetPlayerPawn_ReturnValue) == 0x000008, "Member 'HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags::CallFunc_GetPlayerPawn_ReturnValue' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags, CallFunc_GetMapFilterTags_Tags) == 0x000010, "Member 'HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags::CallFunc_GetMapFilterTags_Tags' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags, K2Node_DynamicCast_AsPAWN_Hacker_Implant) == 0x000060, "Member 'HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags::K2Node_DynamicCast_AsPAWN_Hacker_Implant' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags, K2Node_DynamicCast_bSuccess) == 0x000068, "Member 'HARDWARE_NavUnit_Base_C_UpdateAvailableMapFilterTags::K2Node_DynamicCast_bSuccess' has a wrong offset!");

// Function HARDWARE_NavUnit_Base.HARDWARE_NavUnit_Base_C.GetMapFilterTags
// 0x0050 (0x0050 - 0x0000)
struct HARDWARE_NavUnit_Base_C_GetMapFilterTags final
{
public:
	TSet<class FName>                             Tags;                                              // 0x0000(0x0050)(Parm, OutParm)
};
static_assert(alignof(HARDWARE_NavUnit_Base_C_GetMapFilterTags) == 0x000008, "Wrong alignment on HARDWARE_NavUnit_Base_C_GetMapFilterTags");
static_assert(sizeof(HARDWARE_NavUnit_Base_C_GetMapFilterTags) == 0x000050, "Wrong size on HARDWARE_NavUnit_Base_C_GetMapFilterTags");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_GetMapFilterTags, Tags) == 0x000000, "Member 'HARDWARE_NavUnit_Base_C_GetMapFilterTags::Tags' has a wrong offset!");

// Function HARDWARE_NavUnit_Base.HARDWARE_NavUnit_Base_C.UpdateHardwareState
// 0x0018 (0x0018 - 0x0000)
struct HARDWARE_NavUnit_Base_C_UpdateHardwareState final
{
public:
	bool                                          IsEnabled;                                         // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2[0x6];                                        // 0x0002(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class UCOMP_VoxelScanner_C*                   Scanner;                                           // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_UpdateHardwareState_Result;               // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(HARDWARE_NavUnit_Base_C_UpdateHardwareState) == 0x000008, "Wrong alignment on HARDWARE_NavUnit_Base_C_UpdateHardwareState");
static_assert(sizeof(HARDWARE_NavUnit_Base_C_UpdateHardwareState) == 0x000018, "Wrong size on HARDWARE_NavUnit_Base_C_UpdateHardwareState");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_UpdateHardwareState, IsEnabled) == 0x000000, "Member 'HARDWARE_NavUnit_Base_C_UpdateHardwareState::IsEnabled' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_UpdateHardwareState, Result) == 0x000001, "Member 'HARDWARE_NavUnit_Base_C_UpdateHardwareState::Result' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_UpdateHardwareState, Scanner) == 0x000008, "Member 'HARDWARE_NavUnit_Base_C_UpdateHardwareState::Scanner' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_UpdateHardwareState, CallFunc_UpdateHardwareState_Result) == 0x000010, "Member 'HARDWARE_NavUnit_Base_C_UpdateHardwareState::CallFunc_UpdateHardwareState_Result' has a wrong offset!");

// Function HARDWARE_NavUnit_Base.HARDWARE_NavUnit_Base_C.OnUpgradedItem
// 0x0180 (0x0180 - 0x0000)
struct HARDWARE_NavUnit_Base_C_OnUpgradedItem final
{
public:
	class UITEM_UpgradeBase_C*                    PreviousItem;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x7];                                        // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TSet<class FName>                             CurrentAvailableTags;                              // 0x0010(0x0050)(Edit, BlueprintVisible)
	TSet<class FName>                             PreviousActiveRows;                                // 0x0060(0x0050)(Edit, BlueprintVisible)
	TSet<class FName>                             PreviousAvailableRows;                             // 0x00B0(0x0050)(Edit, BlueprintVisible)
	class FName                                   CurrentRow;                                        // 0x0100(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   CurrentTag;                                        // 0x0108(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSet<class FName>                             PreviousAvailableTags;                             // 0x0110(0x0050)(Edit, BlueprintVisible)
	TArray<class FName>                           PreviousActiveTags;                                // 0x0160(0x0010)(Edit, BlueprintVisible)
	class UCOMP_VoxelScanner_C*                   VoxelScanner;                                      // 0x0170(0x0008)(Edit, BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_OnUpgradedItem_Result;                    // 0x0178(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(HARDWARE_NavUnit_Base_C_OnUpgradedItem) == 0x000008, "Wrong alignment on HARDWARE_NavUnit_Base_C_OnUpgradedItem");
static_assert(sizeof(HARDWARE_NavUnit_Base_C_OnUpgradedItem) == 0x000180, "Wrong size on HARDWARE_NavUnit_Base_C_OnUpgradedItem");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, PreviousItem) == 0x000000, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::PreviousItem' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, Result) == 0x000008, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::Result' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, CurrentAvailableTags) == 0x000010, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::CurrentAvailableTags' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, PreviousActiveRows) == 0x000060, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::PreviousActiveRows' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, PreviousAvailableRows) == 0x0000B0, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::PreviousAvailableRows' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, CurrentRow) == 0x000100, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::CurrentRow' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, CurrentTag) == 0x000108, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::CurrentTag' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, PreviousAvailableTags) == 0x000110, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::PreviousAvailableTags' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, PreviousActiveTags) == 0x000160, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::PreviousActiveTags' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, VoxelScanner) == 0x000170, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::VoxelScanner' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnUpgradedItem, CallFunc_OnUpgradedItem_Result) == 0x000178, "Member 'HARDWARE_NavUnit_Base_C_OnUpgradedItem::CallFunc_OnUpgradedItem_Result' has a wrong offset!");

// Function HARDWARE_NavUnit_Base.HARDWARE_NavUnit_Base_C.GetHardwareFeatures
// 0x0058 (0x0058 - 0x0000)
struct HARDWARE_NavUnit_Base_C_GetHardwareFeatures final
{
public:
	TArray<struct FSTRUCT_HardwareFeature>        Result;                                            // 0x0000(0x0010)(Parm, OutParm)
	class FText                                   CallFunc_ReplaceHardwareInputActionStringInText_Result; // 0x0010(0x0018)()
	struct FSTRUCT_HardwareFeature                K2Node_MakeStruct_STRUCT_HardwareFeature;          // 0x0028(0x0020)(HasGetValueTypeHash)
	TArray<struct FSTRUCT_HardwareFeature>        K2Node_MakeArray_Array;                            // 0x0048(0x0010)(ReferenceParm)
};
static_assert(alignof(HARDWARE_NavUnit_Base_C_GetHardwareFeatures) == 0x000008, "Wrong alignment on HARDWARE_NavUnit_Base_C_GetHardwareFeatures");
static_assert(sizeof(HARDWARE_NavUnit_Base_C_GetHardwareFeatures) == 0x000058, "Wrong size on HARDWARE_NavUnit_Base_C_GetHardwareFeatures");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_GetHardwareFeatures, Result) == 0x000000, "Member 'HARDWARE_NavUnit_Base_C_GetHardwareFeatures::Result' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_GetHardwareFeatures, CallFunc_ReplaceHardwareInputActionStringInText_Result) == 0x000010, "Member 'HARDWARE_NavUnit_Base_C_GetHardwareFeatures::CallFunc_ReplaceHardwareInputActionStringInText_Result' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_GetHardwareFeatures, K2Node_MakeStruct_STRUCT_HardwareFeature) == 0x000028, "Member 'HARDWARE_NavUnit_Base_C_GetHardwareFeatures::K2Node_MakeStruct_STRUCT_HardwareFeature' has a wrong offset!");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_GetHardwareFeatures, K2Node_MakeArray_Array) == 0x000048, "Member 'HARDWARE_NavUnit_Base_C_GetHardwareFeatures::K2Node_MakeArray_Array' has a wrong offset!");

// Function HARDWARE_NavUnit_Base.HARDWARE_NavUnit_Base_C.OnAddedToInventory
// 0x0008 (0x0008 - 0x0000)
struct HARDWARE_NavUnit_Base_C_OnAddedToInventory final
{
public:
	class UCOMP_VoxelScanner_C*                   VoxelScanner;                                      // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(HARDWARE_NavUnit_Base_C_OnAddedToInventory) == 0x000008, "Wrong alignment on HARDWARE_NavUnit_Base_C_OnAddedToInventory");
static_assert(sizeof(HARDWARE_NavUnit_Base_C_OnAddedToInventory) == 0x000008, "Wrong size on HARDWARE_NavUnit_Base_C_OnAddedToInventory");
static_assert(offsetof(HARDWARE_NavUnit_Base_C_OnAddedToInventory, VoxelScanner) == 0x000000, "Member 'HARDWARE_NavUnit_Base_C_OnAddedToInventory::VoxelScanner' has a wrong offset!");

}

