#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OPTION_Display_Resolution

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.ApplyDirtyValue
// 0x0018 (0x0018 - 0x0000)
struct OPTION_Display_Resolution_C_ApplyDirtyValue final
{
public:
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsDirty_IsDirty;                          // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x3];                                        // 0x0009(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FIntPoint                              CallFunc_Array_Get_Item;                           // 0x000C(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_Resolution_C_ApplyDirtyValue) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_ApplyDirtyValue");
static_assert(sizeof(OPTION_Display_Resolution_C_ApplyDirtyValue) == 0x000018, "Wrong size on OPTION_Display_Resolution_C_ApplyDirtyValue");
static_assert(offsetof(OPTION_Display_Resolution_C_ApplyDirtyValue, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000000, "Member 'OPTION_Display_Resolution_C_ApplyDirtyValue::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_ApplyDirtyValue, CallFunc_IsDirty_IsDirty) == 0x000008, "Member 'OPTION_Display_Resolution_C_ApplyDirtyValue::CallFunc_IsDirty_IsDirty' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_ApplyDirtyValue, CallFunc_Array_Get_Item) == 0x00000C, "Member 'OPTION_Display_Resolution_C_ApplyDirtyValue::CallFunc_Array_Get_Item' has a wrong offset!");

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.ApplyCleanValue
// 0x0010 (0x0010 - 0x0000)
struct OPTION_Display_Resolution_C_ApplyCleanValue final
{
public:
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_GetResolution_Result;                     // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_Resolution_C_ApplyCleanValue) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_ApplyCleanValue");
static_assert(sizeof(OPTION_Display_Resolution_C_ApplyCleanValue) == 0x000010, "Wrong size on OPTION_Display_Resolution_C_ApplyCleanValue");
static_assert(offsetof(OPTION_Display_Resolution_C_ApplyCleanValue, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000000, "Member 'OPTION_Display_Resolution_C_ApplyCleanValue::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_ApplyCleanValue, CallFunc_GetResolution_Result) == 0x000008, "Member 'OPTION_Display_Resolution_C_ApplyCleanValue::CallFunc_GetResolution_Result' has a wrong offset!");

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.PopulateUniqueSettings
// 0x0058 (0x0058 - 0x0000)
struct OPTION_Display_Resolution_C_PopulateUniqueSettings final
{
public:
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_Array_Get_Item;                           // 0x000C(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_ResolutionToText_Result;                  // 0x0018(0x0018)()
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0034(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_35[0x3];                                       // 0x0035(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Add_ReturnValue;                    // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3C[0x4];                                       // 0x003C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FIntPoint>                      CallFunc_GetSupportedFullscreenResolutions_Resolutions; // 0x0040(0x0010)(ReferenceParm)
	bool                                          CallFunc_GetSupportedFullscreenResolutions_ReturnValue; // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OPTION_Display_Resolution_C_PopulateUniqueSettings) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_PopulateUniqueSettings");
static_assert(sizeof(OPTION_Display_Resolution_C_PopulateUniqueSettings) == 0x000058, "Wrong size on OPTION_Display_Resolution_C_PopulateUniqueSettings");
static_assert(offsetof(OPTION_Display_Resolution_C_PopulateUniqueSettings, Temp_int_Array_Index_Variable) == 0x000000, "Member 'OPTION_Display_Resolution_C_PopulateUniqueSettings::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_PopulateUniqueSettings, Temp_int_Loop_Counter_Variable) == 0x000004, "Member 'OPTION_Display_Resolution_C_PopulateUniqueSettings::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_PopulateUniqueSettings, CallFunc_Add_IntInt_ReturnValue) == 0x000008, "Member 'OPTION_Display_Resolution_C_PopulateUniqueSettings::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_PopulateUniqueSettings, CallFunc_Array_Get_Item) == 0x00000C, "Member 'OPTION_Display_Resolution_C_PopulateUniqueSettings::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_PopulateUniqueSettings, CallFunc_ResolutionToText_Result) == 0x000018, "Member 'OPTION_Display_Resolution_C_PopulateUniqueSettings::CallFunc_ResolutionToText_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_PopulateUniqueSettings, CallFunc_Array_Length_ReturnValue) == 0x000030, "Member 'OPTION_Display_Resolution_C_PopulateUniqueSettings::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_PopulateUniqueSettings, CallFunc_Less_IntInt_ReturnValue) == 0x000034, "Member 'OPTION_Display_Resolution_C_PopulateUniqueSettings::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_PopulateUniqueSettings, CallFunc_Array_Add_ReturnValue) == 0x000038, "Member 'OPTION_Display_Resolution_C_PopulateUniqueSettings::CallFunc_Array_Add_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_PopulateUniqueSettings, CallFunc_GetSupportedFullscreenResolutions_Resolutions) == 0x000040, "Member 'OPTION_Display_Resolution_C_PopulateUniqueSettings::CallFunc_GetSupportedFullscreenResolutions_Resolutions' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_PopulateUniqueSettings, CallFunc_GetSupportedFullscreenResolutions_ReturnValue) == 0x000050, "Member 'OPTION_Display_Resolution_C_PopulateUniqueSettings::CallFunc_GetSupportedFullscreenResolutions_ReturnValue' has a wrong offset!");

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.ResolutionToText
// 0x00C8 (0x00C8 - 0x0000)
struct OPTION_Display_Resolution_C_ResolutionToText final
{
public:
	struct FIntPoint                              Value;                                             // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   Result;                                            // 0x0008(0x0018)(Parm, OutParm)
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0020(0x0040)(HasGetValueTypeHash)
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_1;            // 0x0060(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x00A0(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x00B0(0x0018)()
};
static_assert(alignof(OPTION_Display_Resolution_C_ResolutionToText) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_ResolutionToText");
static_assert(sizeof(OPTION_Display_Resolution_C_ResolutionToText) == 0x0000C8, "Wrong size on OPTION_Display_Resolution_C_ResolutionToText");
static_assert(offsetof(OPTION_Display_Resolution_C_ResolutionToText, Value) == 0x000000, "Member 'OPTION_Display_Resolution_C_ResolutionToText::Value' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_ResolutionToText, Result) == 0x000008, "Member 'OPTION_Display_Resolution_C_ResolutionToText::Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_ResolutionToText, K2Node_MakeStruct_FormatArgumentData) == 0x000020, "Member 'OPTION_Display_Resolution_C_ResolutionToText::K2Node_MakeStruct_FormatArgumentData' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_ResolutionToText, K2Node_MakeStruct_FormatArgumentData_1) == 0x000060, "Member 'OPTION_Display_Resolution_C_ResolutionToText::K2Node_MakeStruct_FormatArgumentData_1' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_ResolutionToText, K2Node_MakeArray_Array) == 0x0000A0, "Member 'OPTION_Display_Resolution_C_ResolutionToText::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_ResolutionToText, CallFunc_Format_ReturnValue) == 0x0000B0, "Member 'OPTION_Display_Resolution_C_ResolutionToText::CallFunc_Format_ReturnValue' has a wrong offset!");

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.TextToResolution
// 0x0078 (0x0078 - 0x0000)
struct OPTION_Display_Resolution_C_TextToResolution final
{
public:
	class FText                                   Value;                                             // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
	struct FIntPoint                              Result;                                            // 0x0018(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 CallFunc_Conv_TextToString_ReturnValue;            // 0x0020(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 CallFunc_Replace_ReturnValue;                      // 0x0030(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 CallFunc_Split_LeftS;                              // 0x0040(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 CallFunc_Split_RightS;                             // 0x0050(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	bool                                          CallFunc_Split_ReturnValue;                        // 0x0060(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_61[0x3];                                       // 0x0061(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Conv_StringToInt_ReturnValue;             // 0x0064(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Conv_StringToInt_ReturnValue_1;           // 0x0068(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              K2Node_MakeStruct_IntPoint;                        // 0x006C(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_Resolution_C_TextToResolution) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_TextToResolution");
static_assert(sizeof(OPTION_Display_Resolution_C_TextToResolution) == 0x000078, "Wrong size on OPTION_Display_Resolution_C_TextToResolution");
static_assert(offsetof(OPTION_Display_Resolution_C_TextToResolution, Value) == 0x000000, "Member 'OPTION_Display_Resolution_C_TextToResolution::Value' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_TextToResolution, Result) == 0x000018, "Member 'OPTION_Display_Resolution_C_TextToResolution::Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_TextToResolution, CallFunc_Conv_TextToString_ReturnValue) == 0x000020, "Member 'OPTION_Display_Resolution_C_TextToResolution::CallFunc_Conv_TextToString_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_TextToResolution, CallFunc_Replace_ReturnValue) == 0x000030, "Member 'OPTION_Display_Resolution_C_TextToResolution::CallFunc_Replace_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_TextToResolution, CallFunc_Split_LeftS) == 0x000040, "Member 'OPTION_Display_Resolution_C_TextToResolution::CallFunc_Split_LeftS' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_TextToResolution, CallFunc_Split_RightS) == 0x000050, "Member 'OPTION_Display_Resolution_C_TextToResolution::CallFunc_Split_RightS' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_TextToResolution, CallFunc_Split_ReturnValue) == 0x000060, "Member 'OPTION_Display_Resolution_C_TextToResolution::CallFunc_Split_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_TextToResolution, CallFunc_Conv_StringToInt_ReturnValue) == 0x000064, "Member 'OPTION_Display_Resolution_C_TextToResolution::CallFunc_Conv_StringToInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_TextToResolution, CallFunc_Conv_StringToInt_ReturnValue_1) == 0x000068, "Member 'OPTION_Display_Resolution_C_TextToResolution::CallFunc_Conv_StringToInt_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_TextToResolution, K2Node_MakeStruct_IntPoint) == 0x00006C, "Member 'OPTION_Display_Resolution_C_TextToResolution::K2Node_MakeStruct_IntPoint' has a wrong offset!");

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.AcceptCurrentValue
// 0x0010 (0x0010 - 0x0000)
struct OPTION_Display_Resolution_C_AcceptCurrentValue final
{
public:
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_Array_Get_Item;                           // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_Resolution_C_AcceptCurrentValue) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_AcceptCurrentValue");
static_assert(sizeof(OPTION_Display_Resolution_C_AcceptCurrentValue) == 0x000010, "Wrong size on OPTION_Display_Resolution_C_AcceptCurrentValue");
static_assert(offsetof(OPTION_Display_Resolution_C_AcceptCurrentValue, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000000, "Member 'OPTION_Display_Resolution_C_AcceptCurrentValue::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_AcceptCurrentValue, CallFunc_Array_Get_Item) == 0x000008, "Member 'OPTION_Display_Resolution_C_AcceptCurrentValue::CallFunc_Array_Get_Item' has a wrong offset!");

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.UpdateVisuals
// 0x0018 (0x0018 - 0x0000)
struct OPTION_Display_Resolution_C_UpdateVisuals final
{
public:
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_GetResolution_Result;                     // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Map_Find_Value;                           // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Map_Find_ReturnValue;                     // 0x0014(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OPTION_Display_Resolution_C_UpdateVisuals) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_UpdateVisuals");
static_assert(sizeof(OPTION_Display_Resolution_C_UpdateVisuals) == 0x000018, "Wrong size on OPTION_Display_Resolution_C_UpdateVisuals");
static_assert(offsetof(OPTION_Display_Resolution_C_UpdateVisuals, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000000, "Member 'OPTION_Display_Resolution_C_UpdateVisuals::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_UpdateVisuals, CallFunc_GetResolution_Result) == 0x000008, "Member 'OPTION_Display_Resolution_C_UpdateVisuals::CallFunc_GetResolution_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_UpdateVisuals, CallFunc_Map_Find_Value) == 0x000010, "Member 'OPTION_Display_Resolution_C_UpdateVisuals::CallFunc_Map_Find_Value' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_UpdateVisuals, CallFunc_Map_Find_ReturnValue) == 0x000014, "Member 'OPTION_Display_Resolution_C_UpdateVisuals::CallFunc_Map_Find_ReturnValue' has a wrong offset!");

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.IsDirty
// 0x0028 (0x0028 - 0x0000)
struct OPTION_Display_Resolution_C_IsDirty final
{
public:
	bool                                          Param_IsDirty_0;                                   // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_GetResolution_Result;                     // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_Array_Get_Item;                           // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NotEqual_IntPointIntPoint_ReturnValue;    // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OPTION_Display_Resolution_C_IsDirty) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_IsDirty");
static_assert(sizeof(OPTION_Display_Resolution_C_IsDirty) == 0x000028, "Wrong size on OPTION_Display_Resolution_C_IsDirty");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDirty, Param_IsDirty_0) == 0x000000, "Member 'OPTION_Display_Resolution_C_IsDirty::Param_IsDirty_0' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDirty, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000008, "Member 'OPTION_Display_Resolution_C_IsDirty::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDirty, CallFunc_GetResolution_Result) == 0x000010, "Member 'OPTION_Display_Resolution_C_IsDirty::CallFunc_GetResolution_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDirty, CallFunc_Array_Get_Item) == 0x000018, "Member 'OPTION_Display_Resolution_C_IsDirty::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDirty, CallFunc_NotEqual_IntPointIntPoint_ReturnValue) == 0x000020, "Member 'OPTION_Display_Resolution_C_IsDirty::CallFunc_NotEqual_IntPointIntPoint_ReturnValue' has a wrong offset!");

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.SelectDefaultValue
// 0x0038 (0x0038 - 0x0000)
struct OPTION_Display_Resolution_C_SelectDefaultValue final
{
public:
	class FString                                 CallFunc_GetPlatformName_ReturnValue;              // 0x0000(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 CallFunc_GetCurrentCulture_ReturnValue;            // 0x0010(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_GetResolutionProfileValue_Result;         // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Find_ReturnValue;                   // 0x0030(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_Resolution_C_SelectDefaultValue) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_SelectDefaultValue");
static_assert(sizeof(OPTION_Display_Resolution_C_SelectDefaultValue) == 0x000038, "Wrong size on OPTION_Display_Resolution_C_SelectDefaultValue");
static_assert(offsetof(OPTION_Display_Resolution_C_SelectDefaultValue, CallFunc_GetPlatformName_ReturnValue) == 0x000000, "Member 'OPTION_Display_Resolution_C_SelectDefaultValue::CallFunc_GetPlatformName_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_SelectDefaultValue, CallFunc_GetCurrentCulture_ReturnValue) == 0x000010, "Member 'OPTION_Display_Resolution_C_SelectDefaultValue::CallFunc_GetCurrentCulture_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_SelectDefaultValue, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000020, "Member 'OPTION_Display_Resolution_C_SelectDefaultValue::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_SelectDefaultValue, CallFunc_GetResolutionProfileValue_Result) == 0x000028, "Member 'OPTION_Display_Resolution_C_SelectDefaultValue::CallFunc_GetResolutionProfileValue_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_SelectDefaultValue, CallFunc_Array_Find_ReturnValue) == 0x000030, "Member 'OPTION_Display_Resolution_C_SelectDefaultValue::CallFunc_Array_Find_ReturnValue' has a wrong offset!");

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.IsDefault
// 0x0060 (0x0060 - 0x0000)
struct OPTION_Display_Resolution_C_IsDefault final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 CallFunc_GetPlatformName_ReturnValue;              // 0x0008(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FText                                   CallFunc_Array_Get_Item;                           // 0x0018(0x0018)()
	class FString                                 CallFunc_GetCurrentCulture_ReturnValue;            // 0x0030(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_TextToResolution_Result;                  // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_GetResolutionProfileValue_Result;         // 0x0050(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Equal_IntPointIntPoint_ReturnValue;       // 0x0058(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OPTION_Display_Resolution_C_IsDefault) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_IsDefault");
static_assert(sizeof(OPTION_Display_Resolution_C_IsDefault) == 0x000060, "Wrong size on OPTION_Display_Resolution_C_IsDefault");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDefault, Result) == 0x000000, "Member 'OPTION_Display_Resolution_C_IsDefault::Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDefault, CallFunc_GetPlatformName_ReturnValue) == 0x000008, "Member 'OPTION_Display_Resolution_C_IsDefault::CallFunc_GetPlatformName_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDefault, CallFunc_Array_Get_Item) == 0x000018, "Member 'OPTION_Display_Resolution_C_IsDefault::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDefault, CallFunc_GetCurrentCulture_ReturnValue) == 0x000030, "Member 'OPTION_Display_Resolution_C_IsDefault::CallFunc_GetCurrentCulture_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDefault, CallFunc_TextToResolution_Result) == 0x000040, "Member 'OPTION_Display_Resolution_C_IsDefault::CallFunc_TextToResolution_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDefault, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000048, "Member 'OPTION_Display_Resolution_C_IsDefault::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDefault, CallFunc_GetResolutionProfileValue_Result) == 0x000050, "Member 'OPTION_Display_Resolution_C_IsDefault::CallFunc_GetResolutionProfileValue_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_IsDefault, CallFunc_Equal_IntPointIntPoint_ReturnValue) == 0x000058, "Member 'OPTION_Display_Resolution_C_IsDefault::CallFunc_Equal_IntPointIntPoint_ReturnValue' has a wrong offset!");

// Function OPTION_Display_Resolution.OPTION_Display_Resolution_C.InitializeMenuListItem
// 0x0040 (0x0040 - 0x0000)
struct OPTION_Display_Resolution_C_InitializeMenuListItem final
{
public:
	class UWIDGET_MenuListBase_C*                 ParentList;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Index_0;                                           // 0x0008(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ResolutionFound;                                   // 0x000C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Temp_bool_True_if_break_was_hit_Variable;          // 0x000D(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x000E(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_F[0x1];                                        // 0x000F(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_GetResolution_Result;                     // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FIntPoint                              CallFunc_Array_Get_Item;                           // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Equal_IntPointIntPoint_ReturnValue;       // 0x003C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x003D(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x003E(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue_1;                // 0x003F(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OPTION_Display_Resolution_C_InitializeMenuListItem) == 0x000008, "Wrong alignment on OPTION_Display_Resolution_C_InitializeMenuListItem");
static_assert(sizeof(OPTION_Display_Resolution_C_InitializeMenuListItem) == 0x000040, "Wrong size on OPTION_Display_Resolution_C_InitializeMenuListItem");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, ParentList) == 0x000000, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::ParentList' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, Index_0) == 0x000008, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::Index_0' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, ResolutionFound) == 0x00000C, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::ResolutionFound' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, Temp_bool_True_if_break_was_hit_Variable) == 0x00000D, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::Temp_bool_True_if_break_was_hit_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, CallFunc_Not_PreBool_ReturnValue) == 0x00000E, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, Temp_int_Array_Index_Variable) == 0x000010, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, Temp_int_Loop_Counter_Variable) == 0x000014, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, CallFunc_Add_IntInt_ReturnValue) == 0x000018, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000020, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, CallFunc_GetResolution_Result) == 0x000028, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::CallFunc_GetResolution_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, CallFunc_Array_Get_Item) == 0x000030, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, CallFunc_Array_Length_ReturnValue) == 0x000038, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, CallFunc_Equal_IntPointIntPoint_ReturnValue) == 0x00003C, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::CallFunc_Equal_IntPointIntPoint_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, CallFunc_Less_IntInt_ReturnValue) == 0x00003D, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, CallFunc_BooleanAND_ReturnValue) == 0x00003E, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::CallFunc_BooleanAND_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_Resolution_C_InitializeMenuListItem, CallFunc_Not_PreBool_ReturnValue_1) == 0x00003F, "Member 'OPTION_Display_Resolution_C_InitializeMenuListItem::CallFunc_Not_PreBool_ReturnValue_1' has a wrong offset!");

}

