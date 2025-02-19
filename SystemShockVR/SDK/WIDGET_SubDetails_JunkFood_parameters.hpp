#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_SubDetails_JunkFood

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function WIDGET_SubDetails_JunkFood.WIDGET_SubDetails_JunkFood_C.ExecuteUbergraph_WIDGET_SubDetails_JunkFood
// 0x0004 (0x0004 - 0x0000)
struct WIDGET_SubDetails_JunkFood_C_ExecuteUbergraph_WIDGET_SubDetails_JunkFood final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_SubDetails_JunkFood_C_ExecuteUbergraph_WIDGET_SubDetails_JunkFood) == 0x000004, "Wrong alignment on WIDGET_SubDetails_JunkFood_C_ExecuteUbergraph_WIDGET_SubDetails_JunkFood");
static_assert(sizeof(WIDGET_SubDetails_JunkFood_C_ExecuteUbergraph_WIDGET_SubDetails_JunkFood) == 0x000004, "Wrong size on WIDGET_SubDetails_JunkFood_C_ExecuteUbergraph_WIDGET_SubDetails_JunkFood");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ExecuteUbergraph_WIDGET_SubDetails_JunkFood, EntryPoint) == 0x000000, "Member 'WIDGET_SubDetails_JunkFood_C_ExecuteUbergraph_WIDGET_SubDetails_JunkFood::EntryPoint' has a wrong offset!");

// Function WIDGET_SubDetails_JunkFood.WIDGET_SubDetails_JunkFood_C.ShouldShowDetailedHealthText
// 0x0058 (0x0058 - 0x0000)
struct WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText final
{
public:
	class UITEM_JunkFood_Base_C*                  JunkFood;                                          // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x7];                                        // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UHARDWARE_Bioscan_Base_C*               BioscanHardware;                                   // 0x0010(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UInventoryBag_C*                        HardwareBag;                                       // 0x0018(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCOMP_Inventory_C*                      CallFunc_GetInventory_Inventory;                   // 0x0020(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UInventoryBag_C*                        CallFunc_GetBagByType_Bag;                         // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_HasAdvancedBioScanner_Result;             // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_39[0x7];                                       // 0x0039(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UITEM_Base_C*                           CallFunc_FindItem_FoundItem;                       // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UHARDWARE_Bioscan_Base_C*               K2Node_DynamicCast_AsHARDWARE_Bioscan_Base;        // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_GetIsActivated_Result;                    // 0x0051(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText) == 0x000008, "Wrong alignment on WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText");
static_assert(sizeof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText) == 0x000058, "Wrong size on WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, JunkFood) == 0x000000, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::JunkFood' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, Result) == 0x000008, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::Result' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, BioscanHardware) == 0x000010, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::BioscanHardware' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, HardwareBag) == 0x000018, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::HardwareBag' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, CallFunc_GetInventory_Inventory) == 0x000020, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::CallFunc_GetInventory_Inventory' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, CallFunc_IsValid_ReturnValue) == 0x000028, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, CallFunc_GetBagByType_Bag) == 0x000030, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::CallFunc_GetBagByType_Bag' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, CallFunc_HasAdvancedBioScanner_Result) == 0x000038, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::CallFunc_HasAdvancedBioScanner_Result' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, CallFunc_FindItem_FoundItem) == 0x000040, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::CallFunc_FindItem_FoundItem' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, K2Node_DynamicCast_AsHARDWARE_Bioscan_Base) == 0x000048, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::K2Node_DynamicCast_AsHARDWARE_Bioscan_Base' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, K2Node_DynamicCast_bSuccess) == 0x000050, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText, CallFunc_GetIsActivated_Result) == 0x000051, "Member 'WIDGET_SubDetails_JunkFood_C_ShouldShowDetailedHealthText::CallFunc_GetIsActivated_Result' has a wrong offset!");

// Function WIDGET_SubDetails_JunkFood.WIDGET_SubDetails_JunkFood_C.GetServingSizeText
// 0x0178 (0x0178 - 0x0000)
struct WIDGET_SubDetails_JunkFood_C_GetServingSizeText final
{
public:
	class UITEM_JunkFood_Base_C*                  JunkFood;                                          // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   Text;                                              // 0x0008(0x0018)(Parm, OutParm)
	class UITEM_Soda_Base_C*                      K2Node_DynamicCast_AsITEM_Soda_Base;               // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0030(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0070(0x0010)(ReferenceParm)
	float                                         CallFunc_Multiply_FloatFloat_ReturnValue;          // 0x0080(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_84[0x4];                                       // 0x0084(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0088(0x0018)()
	class FText                                   CallFunc_Conv_FloatToText_ReturnValue;             // 0x00A0(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_1;            // 0x00B8(0x0040)(HasGetValueTypeHash)
	class FText                                   CallFunc_Conv_FloatToText_ReturnValue_1;           // 0x00F8(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_2;            // 0x0110(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array_1;                          // 0x0150(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue_1;                     // 0x0160(0x0018)()
};
static_assert(alignof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText) == 0x000008, "Wrong alignment on WIDGET_SubDetails_JunkFood_C_GetServingSizeText");
static_assert(sizeof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText) == 0x000178, "Wrong size on WIDGET_SubDetails_JunkFood_C_GetServingSizeText");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, JunkFood) == 0x000000, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::JunkFood' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, Text) == 0x000008, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::Text' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, K2Node_DynamicCast_AsITEM_Soda_Base) == 0x000020, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::K2Node_DynamicCast_AsITEM_Soda_Base' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, K2Node_MakeStruct_FormatArgumentData) == 0x000030, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::K2Node_MakeStruct_FormatArgumentData' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, K2Node_MakeArray_Array) == 0x000070, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, CallFunc_Multiply_FloatFloat_ReturnValue) == 0x000080, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::CallFunc_Multiply_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, CallFunc_Format_ReturnValue) == 0x000088, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::CallFunc_Format_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, CallFunc_Conv_FloatToText_ReturnValue) == 0x0000A0, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::CallFunc_Conv_FloatToText_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, K2Node_MakeStruct_FormatArgumentData_1) == 0x0000B8, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::K2Node_MakeStruct_FormatArgumentData_1' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, CallFunc_Conv_FloatToText_ReturnValue_1) == 0x0000F8, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::CallFunc_Conv_FloatToText_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, K2Node_MakeStruct_FormatArgumentData_2) == 0x000110, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::K2Node_MakeStruct_FormatArgumentData_2' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, K2Node_MakeArray_Array_1) == 0x000150, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::K2Node_MakeArray_Array_1' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetServingSizeText, CallFunc_Format_ReturnValue_1) == 0x000160, "Member 'WIDGET_SubDetails_JunkFood_C_GetServingSizeText::CallFunc_Format_ReturnValue_1' has a wrong offset!");

// Function WIDGET_SubDetails_JunkFood.WIDGET_SubDetails_JunkFood_C.GetNutritionLabelText
// 0x0040 (0x0040 - 0x0000)
struct WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText final
{
public:
	class UITEM_JunkFood_Base_C*                  JunkFood;                                          // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   Text;                                              // 0x0008(0x0018)(Parm, OutParm)
	class UITEM_Soda_Base_C*                      K2Node_DynamicCast_AsITEM_Soda_Base;               // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UITEM_ChipBag_Base_C*                   K2Node_DynamicCast_AsITEM_Chip_Bag_Base;           // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText) == 0x000008, "Wrong alignment on WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText");
static_assert(sizeof(WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText) == 0x000040, "Wrong size on WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText, JunkFood) == 0x000000, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText::JunkFood' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText, Text) == 0x000008, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText::Text' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText, K2Node_DynamicCast_AsITEM_Soda_Base) == 0x000020, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText::K2Node_DynamicCast_AsITEM_Soda_Base' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText, K2Node_DynamicCast_AsITEM_Chip_Bag_Base) == 0x000030, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText::K2Node_DynamicCast_AsITEM_Chip_Bag_Base' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText, K2Node_DynamicCast_bSuccess_1) == 0x000038, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionLabelText::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");

// Function WIDGET_SubDetails_JunkFood.WIDGET_SubDetails_JunkFood_C.GetNutritionDetailsText
// 0x0178 (0x0178 - 0x0000)
struct WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText final
{
public:
	class UITEM_JunkFood_Base_C*                  JunkFood;                                          // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   Text;                                              // 0x0008(0x0018)(Parm, OutParm)
	class UITEM_Soda_Base_C*                      K2Node_DynamicCast_AsITEM_Soda_Base;               // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0030(0x0040)(HasGetValueTypeHash)
	class UITEM_ChipBag_Base_C*                   K2Node_DynamicCast_AsITEM_Chip_Bag_Base;           // 0x0070(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0078(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_79[0x7];                                       // 0x0079(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0080(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0090(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_1;            // 0x00A8(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array_1;                          // 0x00E8(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue_1;                     // 0x00F8(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_2;            // 0x0110(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array_2;                          // 0x0150(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue_2;                     // 0x0160(0x0018)()
};
static_assert(alignof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText) == 0x000008, "Wrong alignment on WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText");
static_assert(sizeof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText) == 0x000178, "Wrong size on WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, JunkFood) == 0x000000, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::JunkFood' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, Text) == 0x000008, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::Text' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, K2Node_DynamicCast_AsITEM_Soda_Base) == 0x000020, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::K2Node_DynamicCast_AsITEM_Soda_Base' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, K2Node_MakeStruct_FormatArgumentData) == 0x000030, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::K2Node_MakeStruct_FormatArgumentData' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, K2Node_DynamicCast_AsITEM_Chip_Bag_Base) == 0x000070, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::K2Node_DynamicCast_AsITEM_Chip_Bag_Base' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, K2Node_DynamicCast_bSuccess_1) == 0x000078, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, K2Node_MakeArray_Array) == 0x000080, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, CallFunc_Format_ReturnValue) == 0x000090, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::CallFunc_Format_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, K2Node_MakeStruct_FormatArgumentData_1) == 0x0000A8, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::K2Node_MakeStruct_FormatArgumentData_1' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, K2Node_MakeArray_Array_1) == 0x0000E8, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::K2Node_MakeArray_Array_1' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, CallFunc_Format_ReturnValue_1) == 0x0000F8, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::CallFunc_Format_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, K2Node_MakeStruct_FormatArgumentData_2) == 0x000110, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::K2Node_MakeStruct_FormatArgumentData_2' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, K2Node_MakeArray_Array_2) == 0x000150, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::K2Node_MakeArray_Array_2' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText, CallFunc_Format_ReturnValue_2) == 0x000160, "Member 'WIDGET_SubDetails_JunkFood_C_GetNutritionDetailsText::CallFunc_Format_ReturnValue_2' has a wrong offset!");

// Function WIDGET_SubDetails_JunkFood.WIDGET_SubDetails_JunkFood_C.GetAmmoDetails
// 0x000C (0x000C - 0x0000)
struct WIDGET_SubDetails_JunkFood_C_GetAmmoDetails final
{
public:
	bool                                          ShowAmmo;                                          // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CountInClip;                                       // 0x0004(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CountInInventory;                                  // 0x0008(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_SubDetails_JunkFood_C_GetAmmoDetails) == 0x000004, "Wrong alignment on WIDGET_SubDetails_JunkFood_C_GetAmmoDetails");
static_assert(sizeof(WIDGET_SubDetails_JunkFood_C_GetAmmoDetails) == 0x00000C, "Wrong size on WIDGET_SubDetails_JunkFood_C_GetAmmoDetails");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetAmmoDetails, ShowAmmo) == 0x000000, "Member 'WIDGET_SubDetails_JunkFood_C_GetAmmoDetails::ShowAmmo' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetAmmoDetails, CountInClip) == 0x000004, "Member 'WIDGET_SubDetails_JunkFood_C_GetAmmoDetails::CountInClip' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_GetAmmoDetails, CountInInventory) == 0x000008, "Member 'WIDGET_SubDetails_JunkFood_C_GetAmmoDetails::CountInInventory' has a wrong offset!");

// Function WIDGET_SubDetails_JunkFood.WIDGET_SubDetails_JunkFood_C.InitializeItemDetails
// 0x0178 (0x0178 - 0x0000)
struct WIDGET_SubDetails_JunkFood_C_InitializeItemDetails final
{
public:
	class UITEM_Base_C*                           Item;                                              // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UWIDGET_InventoryDetails_C*             InventoryDetails;                                  // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0010(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_11[0x7];                                       // 0x0011(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UITEM_JunkFood_Base_C*                  JunkFood;                                          // 0x0018(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_21[0x7];                                       // 0x0021(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UITEM_JunkFood_Base_C*                  K2Node_DynamicCast_AsITEM_Junk_Food_Base;          // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_31[0x7];                                       // 0x0031(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   Temp_text_Variable;                                // 0x0038(0x0018)()
	bool                                          CallFunc_ShouldShowDetailedHealthText_Result;      // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_51[0x7];                                       // 0x0051(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_GetNutritionLabelText_Text;               // 0x0058(0x0018)()
	class FText                                   CallFunc_GetNutritionDetailsText_Text;             // 0x0070(0x0018)()
	class FText                                   CallFunc_GetServingSizeText_Text;                  // 0x0088(0x0018)()
	class FText                                   CallFunc_Conv_IntToText_ReturnValue;               // 0x00A0(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x00B8(0x0040)(HasGetValueTypeHash)
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_1;            // 0x00F8(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0138(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0148(0x0018)()
	class FText                                   K2Node_Select_Default;                             // 0x0160(0x0018)()
};
static_assert(alignof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails) == 0x000008, "Wrong alignment on WIDGET_SubDetails_JunkFood_C_InitializeItemDetails");
static_assert(sizeof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails) == 0x000178, "Wrong size on WIDGET_SubDetails_JunkFood_C_InitializeItemDetails");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, Item) == 0x000000, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::Item' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, InventoryDetails) == 0x000008, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::InventoryDetails' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, Result) == 0x000010, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::Result' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, JunkFood) == 0x000018, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::JunkFood' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, Temp_bool_Variable) == 0x000020, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, K2Node_DynamicCast_AsITEM_Junk_Food_Base) == 0x000028, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::K2Node_DynamicCast_AsITEM_Junk_Food_Base' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, K2Node_DynamicCast_bSuccess) == 0x000030, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, Temp_text_Variable) == 0x000038, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::Temp_text_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, CallFunc_ShouldShowDetailedHealthText_Result) == 0x000050, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::CallFunc_ShouldShowDetailedHealthText_Result' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, CallFunc_GetNutritionLabelText_Text) == 0x000058, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::CallFunc_GetNutritionLabelText_Text' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, CallFunc_GetNutritionDetailsText_Text) == 0x000070, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::CallFunc_GetNutritionDetailsText_Text' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, CallFunc_GetServingSizeText_Text) == 0x000088, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::CallFunc_GetServingSizeText_Text' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, CallFunc_Conv_IntToText_ReturnValue) == 0x0000A0, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::CallFunc_Conv_IntToText_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, K2Node_MakeStruct_FormatArgumentData) == 0x0000B8, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::K2Node_MakeStruct_FormatArgumentData' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, K2Node_MakeStruct_FormatArgumentData_1) == 0x0000F8, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::K2Node_MakeStruct_FormatArgumentData_1' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, K2Node_MakeArray_Array) == 0x000138, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, CallFunc_Format_ReturnValue) == 0x000148, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::CallFunc_Format_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_InitializeItemDetails, K2Node_Select_Default) == 0x000160, "Member 'WIDGET_SubDetails_JunkFood_C_InitializeItemDetails::K2Node_Select_Default' has a wrong offset!");

// Function WIDGET_SubDetails_JunkFood.WIDGET_SubDetails_JunkFood_C.ShowExtendedDetails
// 0x0001 (0x0001 - 0x0000)
struct WIDGET_SubDetails_JunkFood_C_ShowExtendedDetails final
{
public:
	bool                                          Show;                                              // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_SubDetails_JunkFood_C_ShowExtendedDetails) == 0x000001, "Wrong alignment on WIDGET_SubDetails_JunkFood_C_ShowExtendedDetails");
static_assert(sizeof(WIDGET_SubDetails_JunkFood_C_ShowExtendedDetails) == 0x000001, "Wrong size on WIDGET_SubDetails_JunkFood_C_ShowExtendedDetails");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShowExtendedDetails, Show) == 0x000000, "Member 'WIDGET_SubDetails_JunkFood_C_ShowExtendedDetails::Show' has a wrong offset!");

// Function WIDGET_SubDetails_JunkFood.WIDGET_SubDetails_JunkFood_C.ShowBars
// 0x0001 (0x0001 - 0x0000)
struct WIDGET_SubDetails_JunkFood_C_ShowBars final
{
public:
	bool                                          Show;                                              // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_SubDetails_JunkFood_C_ShowBars) == 0x000001, "Wrong alignment on WIDGET_SubDetails_JunkFood_C_ShowBars");
static_assert(sizeof(WIDGET_SubDetails_JunkFood_C_ShowBars) == 0x000001, "Wrong size on WIDGET_SubDetails_JunkFood_C_ShowBars");
static_assert(offsetof(WIDGET_SubDetails_JunkFood_C_ShowBars, Show) == 0x000000, "Member 'WIDGET_SubDetails_JunkFood_C_ShowBars::Show' has a wrong offset!");

}

