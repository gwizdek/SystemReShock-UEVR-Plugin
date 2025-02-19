#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_Automap_Filters

#include "Basic.hpp"

#include "STRUCT_MapFilterData_structs.hpp"
#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function WIDGET_Automap_Filters.WIDGET_Automap_Filters_C.ExecuteUbergraph_WIDGET_Automap_Filters
// 0x0030 (0x0030 - 0x0000)
struct WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0004(0x0010)(ZeroConstructor, NoDestructor)
	struct FColor                                 CallFunc_GetMeshUIColor_Color;                     // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APawn*                                  CallFunc_GetPlayerPawn_ReturnValue;                // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Hacker_Implant_C*                 K2Node_DynamicCast_AsPAWN_Hacker_Implant;          // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters) == 0x000008, "Wrong alignment on WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters");
static_assert(sizeof(WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters) == 0x000030, "Wrong size on WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters");
static_assert(offsetof(WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters, EntryPoint) == 0x000000, "Member 'WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters::EntryPoint' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters, K2Node_CreateDelegate_OutputDelegate) == 0x000004, "Member 'WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters, CallFunc_GetMeshUIColor_Color) == 0x000014, "Member 'WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters::CallFunc_GetMeshUIColor_Color' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters, CallFunc_GetPlayerPawn_ReturnValue) == 0x000018, "Member 'WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters::CallFunc_GetPlayerPawn_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters, K2Node_DynamicCast_AsPAWN_Hacker_Implant) == 0x000020, "Member 'WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters::K2Node_DynamicCast_AsPAWN_Hacker_Implant' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'WIDGET_Automap_Filters_C_ExecuteUbergraph_WIDGET_Automap_Filters::K2Node_DynamicCast_bSuccess' has a wrong offset!");

// Function WIDGET_Automap_Filters.WIDGET_Automap_Filters_C.SetFiltersVisible
// 0x0050 (0x0050 - 0x0000)
struct WIDGET_Automap_Filters_C_SetFiltersVisible final
{
public:
	class FName                                   CurrentFilterRow;                                  // 0x0000(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class FName>                           FilterGroupsToDisplay;                             // 0x0008(0x0010)(Edit, BlueprintVisible)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_AddUnique_ReturnValue;              // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsAnyTagInFilterRowAvailable_Result;      // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class FName>                           CallFunc_GetOrderedRows_AvailableGroups;           // 0x0030(0x0010)(ReferenceParm)
	class FName                                   CallFunc_Array_Get_Item;                           // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0048(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x004C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_Automap_Filters_C_SetFiltersVisible) == 0x000008, "Wrong alignment on WIDGET_Automap_Filters_C_SetFiltersVisible");
static_assert(sizeof(WIDGET_Automap_Filters_C_SetFiltersVisible) == 0x000050, "Wrong size on WIDGET_Automap_Filters_C_SetFiltersVisible");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, CurrentFilterRow) == 0x000000, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::CurrentFilterRow' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, FilterGroupsToDisplay) == 0x000008, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::FilterGroupsToDisplay' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, Temp_int_Array_Index_Variable) == 0x000018, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, Temp_int_Loop_Counter_Variable) == 0x00001C, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, CallFunc_Add_IntInt_ReturnValue) == 0x000020, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, CallFunc_Array_AddUnique_ReturnValue) == 0x000024, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::CallFunc_Array_AddUnique_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, CallFunc_IsAnyTagInFilterRowAvailable_Result) == 0x000028, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::CallFunc_IsAnyTagInFilterRowAvailable_Result' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, CallFunc_GetOrderedRows_AvailableGroups) == 0x000030, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::CallFunc_GetOrderedRows_AvailableGroups' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, CallFunc_Array_Get_Item) == 0x000040, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, CallFunc_Array_Length_ReturnValue) == 0x000048, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_SetFiltersVisible, CallFunc_Less_IntInt_ReturnValue) == 0x00004C, "Member 'WIDGET_Automap_Filters_C_SetFiltersVisible::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");

// Function WIDGET_Automap_Filters.WIDGET_Automap_Filters_C.GetOrderedRows
// 0x0048 (0x0048 - 0x0000)
struct WIDGET_Automap_Filters_C_GetOrderedRows final
{
public:
	TArray<class FName>                           AvailableGroups;                                   // 0x0000(0x0010)(Parm, OutParm)
	TArray<class FName>                           Groups;                                            // 0x0010(0x0010)(Edit, BlueprintVisible)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0028(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x002C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FDataTableRowHandle                    CallFunc_Array_Get_Item;                           // 0x0030(0x0010)(NoDestructor)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_41[0x3];                                       // 0x0041(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Add_ReturnValue;                    // 0x0044(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_Automap_Filters_C_GetOrderedRows) == 0x000008, "Wrong alignment on WIDGET_Automap_Filters_C_GetOrderedRows");
static_assert(sizeof(WIDGET_Automap_Filters_C_GetOrderedRows) == 0x000048, "Wrong size on WIDGET_Automap_Filters_C_GetOrderedRows");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetOrderedRows, AvailableGroups) == 0x000000, "Member 'WIDGET_Automap_Filters_C_GetOrderedRows::AvailableGroups' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetOrderedRows, Groups) == 0x000010, "Member 'WIDGET_Automap_Filters_C_GetOrderedRows::Groups' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetOrderedRows, Temp_int_Array_Index_Variable) == 0x000020, "Member 'WIDGET_Automap_Filters_C_GetOrderedRows::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetOrderedRows, Temp_int_Loop_Counter_Variable) == 0x000024, "Member 'WIDGET_Automap_Filters_C_GetOrderedRows::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetOrderedRows, CallFunc_Add_IntInt_ReturnValue) == 0x000028, "Member 'WIDGET_Automap_Filters_C_GetOrderedRows::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetOrderedRows, CallFunc_Array_Length_ReturnValue) == 0x00002C, "Member 'WIDGET_Automap_Filters_C_GetOrderedRows::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetOrderedRows, CallFunc_Array_Get_Item) == 0x000030, "Member 'WIDGET_Automap_Filters_C_GetOrderedRows::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetOrderedRows, CallFunc_Less_IntInt_ReturnValue) == 0x000040, "Member 'WIDGET_Automap_Filters_C_GetOrderedRows::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetOrderedRows, CallFunc_Array_Add_ReturnValue) == 0x000044, "Member 'WIDGET_Automap_Filters_C_GetOrderedRows::CallFunc_Array_Add_ReturnValue' has a wrong offset!");

// Function WIDGET_Automap_Filters.WIDGET_Automap_Filters_C.IsAnyTagInFilterRowAvailable
// 0x0070 (0x0070 - 0x0000)
struct WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable final
{
public:
	class FName                                   FilterRow;                                         // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x3];                                        // 0x0009(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   CurrentTag;                                        // 0x000C(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UCOMP_VoxelScanner_C*                   ScannerComponent;                                  // 0x0018(0x0008)(Edit, BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0028(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2C[0x4];                                       // 0x002C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class APawn*                                  CallFunc_GetPlayerPawn_ReturnValue;                // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsScannableFilterTagAvailable_ReturnValue; // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_39[0x7];                                       // 0x0039(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class APAWN_Hacker_Implant_C*                 K2Node_DynamicCast_AsPAWN_Hacker_Implant;          // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_49[0x7];                                       // 0x0049(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<class FName>                           CallFunc_GetRowTags_Tags;                          // 0x0050(0x0010)(ReferenceParm)
	class FName                                   CallFunc_Array_Get_Item;                           // 0x0060(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0068(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x006C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable) == 0x000008, "Wrong alignment on WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable");
static_assert(sizeof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable) == 0x000070, "Wrong size on WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, FilterRow) == 0x000000, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::FilterRow' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, Result) == 0x000008, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::Result' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, CurrentTag) == 0x00000C, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::CurrentTag' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, ScannerComponent) == 0x000018, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::ScannerComponent' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, Temp_int_Array_Index_Variable) == 0x000020, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, Temp_int_Loop_Counter_Variable) == 0x000024, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, CallFunc_Add_IntInt_ReturnValue) == 0x000028, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, CallFunc_GetPlayerPawn_ReturnValue) == 0x000030, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::CallFunc_GetPlayerPawn_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, CallFunc_IsScannableFilterTagAvailable_ReturnValue) == 0x000038, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::CallFunc_IsScannableFilterTagAvailable_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, K2Node_DynamicCast_AsPAWN_Hacker_Implant) == 0x000040, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::K2Node_DynamicCast_AsPAWN_Hacker_Implant' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, K2Node_DynamicCast_bSuccess) == 0x000048, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, CallFunc_GetRowTags_Tags) == 0x000050, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::CallFunc_GetRowTags_Tags' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, CallFunc_Array_Get_Item) == 0x000060, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, CallFunc_Array_Length_ReturnValue) == 0x000068, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable, CallFunc_Less_IntInt_ReturnValue) == 0x00006C, "Member 'WIDGET_Automap_Filters_C_IsAnyTagInFilterRowAvailable::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");

// Function WIDGET_Automap_Filters.WIDGET_Automap_Filters_C.GetRowTags
// 0x0048 (0x0048 - 0x0000)
struct WIDGET_Automap_Filters_C_GetRowTags final
{
public:
	class FName                                   RowName;                                           // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class FName>                           Tags;                                              // 0x0008(0x0010)(Parm, OutParm)
	struct FSTRUCT_MapFilterData                  CallFunc_GetDataTableRowFromName_OutRow;           // 0x0018(0x0028)(HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue;      // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_Automap_Filters_C_GetRowTags) == 0x000008, "Wrong alignment on WIDGET_Automap_Filters_C_GetRowTags");
static_assert(sizeof(WIDGET_Automap_Filters_C_GetRowTags) == 0x000048, "Wrong size on WIDGET_Automap_Filters_C_GetRowTags");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetRowTags, RowName) == 0x000000, "Member 'WIDGET_Automap_Filters_C_GetRowTags::RowName' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetRowTags, Tags) == 0x000008, "Member 'WIDGET_Automap_Filters_C_GetRowTags::Tags' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetRowTags, CallFunc_GetDataTableRowFromName_OutRow) == 0x000018, "Member 'WIDGET_Automap_Filters_C_GetRowTags::CallFunc_GetDataTableRowFromName_OutRow' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_GetRowTags, CallFunc_GetDataTableRowFromName_ReturnValue) == 0x000040, "Member 'WIDGET_Automap_Filters_C_GetRowTags::CallFunc_GetDataTableRowFromName_ReturnValue' has a wrong offset!");

// Function WIDGET_Automap_Filters.WIDGET_Automap_Filters_C.CreateFilterElements
// 0x0048 (0x0048 - 0x0000)
struct WIDGET_Automap_Filters_C_CreateFilterElements final
{
public:
	TArray<class FName>                           FilterRows;                                        // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class APlayerController*                      CallFunc_GetPlayerController_ReturnValue;          // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   CallFunc_Array_Get_Item;                           // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UWIDGET_Automap_FilterElement_C*        CallFunc_Create_ReturnValue;                       // 0x0030(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x003C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_3D[0x3];                                       // 0x003D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UWrapBoxSlot*                           CallFunc_AddChildToWrapBox_ReturnValue;            // 0x0040(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_Automap_Filters_C_CreateFilterElements) == 0x000008, "Wrong alignment on WIDGET_Automap_Filters_C_CreateFilterElements");
static_assert(sizeof(WIDGET_Automap_Filters_C_CreateFilterElements) == 0x000048, "Wrong size on WIDGET_Automap_Filters_C_CreateFilterElements");
static_assert(offsetof(WIDGET_Automap_Filters_C_CreateFilterElements, FilterRows) == 0x000000, "Member 'WIDGET_Automap_Filters_C_CreateFilterElements::FilterRows' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_CreateFilterElements, Temp_int_Array_Index_Variable) == 0x000010, "Member 'WIDGET_Automap_Filters_C_CreateFilterElements::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_CreateFilterElements, Temp_int_Loop_Counter_Variable) == 0x000014, "Member 'WIDGET_Automap_Filters_C_CreateFilterElements::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_CreateFilterElements, CallFunc_Add_IntInt_ReturnValue) == 0x000018, "Member 'WIDGET_Automap_Filters_C_CreateFilterElements::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_CreateFilterElements, CallFunc_GetPlayerController_ReturnValue) == 0x000020, "Member 'WIDGET_Automap_Filters_C_CreateFilterElements::CallFunc_GetPlayerController_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_CreateFilterElements, CallFunc_Array_Get_Item) == 0x000028, "Member 'WIDGET_Automap_Filters_C_CreateFilterElements::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_CreateFilterElements, CallFunc_Create_ReturnValue) == 0x000030, "Member 'WIDGET_Automap_Filters_C_CreateFilterElements::CallFunc_Create_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_CreateFilterElements, CallFunc_Array_Length_ReturnValue) == 0x000038, "Member 'WIDGET_Automap_Filters_C_CreateFilterElements::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_CreateFilterElements, CallFunc_Less_IntInt_ReturnValue) == 0x00003C, "Member 'WIDGET_Automap_Filters_C_CreateFilterElements::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Automap_Filters_C_CreateFilterElements, CallFunc_AddChildToWrapBox_ReturnValue) == 0x000040, "Member 'WIDGET_Automap_Filters_C_CreateFilterElements::CallFunc_AddChildToWrapBox_ReturnValue' has a wrong offset!");

}

