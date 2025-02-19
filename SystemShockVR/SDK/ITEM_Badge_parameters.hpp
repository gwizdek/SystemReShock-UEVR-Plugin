#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ITEM_Badge

#include "Basic.hpp"

#include "STRUCT_BadgeInfo_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function ITEM_Badge.ITEM_Badge_C.SetBadgeInformationFromRowHandle
// 0x0010 (0x0010 - 0x0000)
struct ITEM_Badge_C_SetBadgeInformationFromRowHandle final
{
public:
	struct FDataTableRowHandle                    RowHandle;                                         // 0x0000(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
};
static_assert(alignof(ITEM_Badge_C_SetBadgeInformationFromRowHandle) == 0x000008, "Wrong alignment on ITEM_Badge_C_SetBadgeInformationFromRowHandle");
static_assert(sizeof(ITEM_Badge_C_SetBadgeInformationFromRowHandle) == 0x000010, "Wrong size on ITEM_Badge_C_SetBadgeInformationFromRowHandle");
static_assert(offsetof(ITEM_Badge_C_SetBadgeInformationFromRowHandle, RowHandle) == 0x000000, "Member 'ITEM_Badge_C_SetBadgeInformationFromRowHandle::RowHandle' has a wrong offset!");

// Function ITEM_Badge.ITEM_Badge_C.GetDescription
// 0x0160 (0x0160 - 0x0000)
struct ITEM_Badge_C_GetDescription final
{
public:
	class FText                                   Result;                                            // 0x0000(0x0018)(Parm, OutParm)
	struct FSTRUCT_BadgeInfo                      CallFunc_GetDataTableRowFromName_OutRow;           // 0x0018(0x0060)(ZeroConstructor, HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue;      // 0x0078(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0079(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_7A[0x6];                                       // 0x007A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_Conv_StringToText_ReturnValue;            // 0x0080(0x0018)()
	class FText                                   CallFunc_Conv_StringToText_ReturnValue_1;          // 0x0098(0x0018)()
	class FText                                   CallFunc_Conv_StringToText_ReturnValue_2;          // 0x00B0(0x0018)()
	class FText                                   CallFunc_Conv_StringToText_ReturnValue_3;          // 0x00C8(0x0018)()
	class FText                                   CallFunc_GetStandardName_Result;                   // 0x00E0(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x00F8(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0138(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0148(0x0018)()
};
static_assert(alignof(ITEM_Badge_C_GetDescription) == 0x000008, "Wrong alignment on ITEM_Badge_C_GetDescription");
static_assert(sizeof(ITEM_Badge_C_GetDescription) == 0x000160, "Wrong size on ITEM_Badge_C_GetDescription");
static_assert(offsetof(ITEM_Badge_C_GetDescription, Result) == 0x000000, "Member 'ITEM_Badge_C_GetDescription::Result' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, CallFunc_GetDataTableRowFromName_OutRow) == 0x000018, "Member 'ITEM_Badge_C_GetDescription::CallFunc_GetDataTableRowFromName_OutRow' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, CallFunc_GetDataTableRowFromName_ReturnValue) == 0x000078, "Member 'ITEM_Badge_C_GetDescription::CallFunc_GetDataTableRowFromName_ReturnValue' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, CallFunc_IsValid_ReturnValue) == 0x000079, "Member 'ITEM_Badge_C_GetDescription::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, CallFunc_Conv_StringToText_ReturnValue) == 0x000080, "Member 'ITEM_Badge_C_GetDescription::CallFunc_Conv_StringToText_ReturnValue' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, CallFunc_Conv_StringToText_ReturnValue_1) == 0x000098, "Member 'ITEM_Badge_C_GetDescription::CallFunc_Conv_StringToText_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, CallFunc_Conv_StringToText_ReturnValue_2) == 0x0000B0, "Member 'ITEM_Badge_C_GetDescription::CallFunc_Conv_StringToText_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, CallFunc_Conv_StringToText_ReturnValue_3) == 0x0000C8, "Member 'ITEM_Badge_C_GetDescription::CallFunc_Conv_StringToText_ReturnValue_3' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, CallFunc_GetStandardName_Result) == 0x0000E0, "Member 'ITEM_Badge_C_GetDescription::CallFunc_GetStandardName_Result' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, K2Node_MakeStruct_FormatArgumentData) == 0x0000F8, "Member 'ITEM_Badge_C_GetDescription::K2Node_MakeStruct_FormatArgumentData' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, K2Node_MakeArray_Array) == 0x000138, "Member 'ITEM_Badge_C_GetDescription::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(ITEM_Badge_C_GetDescription, CallFunc_Format_ReturnValue) == 0x000148, "Member 'ITEM_Badge_C_GetDescription::CallFunc_Format_ReturnValue' has a wrong offset!");

}

