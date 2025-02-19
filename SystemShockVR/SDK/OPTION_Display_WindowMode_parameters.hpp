#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OPTION_Display_WindowMode

#include "Basic.hpp"

#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.PopulateUniqueSettings
// 0x0038 (0x0038 - 0x0000)
struct OPTION_Display_WindowMode_C_PopulateUniqueSettings final
{
public:
	int32                                         Temp_int_Array_Index_Variable;                     // 0x0000(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Loop_Counter_Variable;                    // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWindowMode                                   CallFunc_Array_Get_Item;                           // 0x000C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_D[0x3];                                        // 0x000D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Length_ReturnValue;                 // 0x0010(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_ModeToText_Result;                        // 0x0018(0x0018)()
	bool                                          CallFunc_Less_IntInt_ReturnValue;                  // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_31[0x3];                                       // 0x0031(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Add_ReturnValue;                    // 0x0034(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_WindowMode_C_PopulateUniqueSettings) == 0x000008, "Wrong alignment on OPTION_Display_WindowMode_C_PopulateUniqueSettings");
static_assert(sizeof(OPTION_Display_WindowMode_C_PopulateUniqueSettings) == 0x000038, "Wrong size on OPTION_Display_WindowMode_C_PopulateUniqueSettings");
static_assert(offsetof(OPTION_Display_WindowMode_C_PopulateUniqueSettings, Temp_int_Array_Index_Variable) == 0x000000, "Member 'OPTION_Display_WindowMode_C_PopulateUniqueSettings::Temp_int_Array_Index_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_PopulateUniqueSettings, Temp_int_Loop_Counter_Variable) == 0x000004, "Member 'OPTION_Display_WindowMode_C_PopulateUniqueSettings::Temp_int_Loop_Counter_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_PopulateUniqueSettings, CallFunc_Add_IntInt_ReturnValue) == 0x000008, "Member 'OPTION_Display_WindowMode_C_PopulateUniqueSettings::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_PopulateUniqueSettings, CallFunc_Array_Get_Item) == 0x00000C, "Member 'OPTION_Display_WindowMode_C_PopulateUniqueSettings::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_PopulateUniqueSettings, CallFunc_Array_Length_ReturnValue) == 0x000010, "Member 'OPTION_Display_WindowMode_C_PopulateUniqueSettings::CallFunc_Array_Length_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_PopulateUniqueSettings, CallFunc_ModeToText_Result) == 0x000018, "Member 'OPTION_Display_WindowMode_C_PopulateUniqueSettings::CallFunc_ModeToText_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_PopulateUniqueSettings, CallFunc_Less_IntInt_ReturnValue) == 0x000030, "Member 'OPTION_Display_WindowMode_C_PopulateUniqueSettings::CallFunc_Less_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_PopulateUniqueSettings, CallFunc_Array_Add_ReturnValue) == 0x000034, "Member 'OPTION_Display_WindowMode_C_PopulateUniqueSettings::CallFunc_Array_Add_ReturnValue' has a wrong offset!");

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.ModeToText
// 0x0028 (0x0028 - 0x0000)
struct OPTION_Display_WindowMode_C_ModeToText final
{
public:
	EWindowMode                                   Mode;                                              // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   Result;                                            // 0x0008(0x0018)(Parm, OutParm)
	bool                                          K2Node_SwitchEnum_CmpSuccess;                      // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OPTION_Display_WindowMode_C_ModeToText) == 0x000008, "Wrong alignment on OPTION_Display_WindowMode_C_ModeToText");
static_assert(sizeof(OPTION_Display_WindowMode_C_ModeToText) == 0x000028, "Wrong size on OPTION_Display_WindowMode_C_ModeToText");
static_assert(offsetof(OPTION_Display_WindowMode_C_ModeToText, Mode) == 0x000000, "Member 'OPTION_Display_WindowMode_C_ModeToText::Mode' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_ModeToText, Result) == 0x000008, "Member 'OPTION_Display_WindowMode_C_ModeToText::Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_ModeToText, K2Node_SwitchEnum_CmpSuccess) == 0x000020, "Member 'OPTION_Display_WindowMode_C_ModeToText::K2Node_SwitchEnum_CmpSuccess' has a wrong offset!");

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.ApplyDirtyValue
// 0x0010 (0x0010 - 0x0000)
struct OPTION_Display_WindowMode_C_ApplyDirtyValue final
{
public:
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsDirty_IsDirty;                          // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	EWindowMode                                   CallFunc_Array_Get_Item;                           // 0x0009(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_WindowMode_C_ApplyDirtyValue) == 0x000008, "Wrong alignment on OPTION_Display_WindowMode_C_ApplyDirtyValue");
static_assert(sizeof(OPTION_Display_WindowMode_C_ApplyDirtyValue) == 0x000010, "Wrong size on OPTION_Display_WindowMode_C_ApplyDirtyValue");
static_assert(offsetof(OPTION_Display_WindowMode_C_ApplyDirtyValue, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000000, "Member 'OPTION_Display_WindowMode_C_ApplyDirtyValue::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_ApplyDirtyValue, CallFunc_IsDirty_IsDirty) == 0x000008, "Member 'OPTION_Display_WindowMode_C_ApplyDirtyValue::CallFunc_IsDirty_IsDirty' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_ApplyDirtyValue, CallFunc_Array_Get_Item) == 0x000009, "Member 'OPTION_Display_WindowMode_C_ApplyDirtyValue::CallFunc_Array_Get_Item' has a wrong offset!");

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.IsDirty
// 0x0018 (0x0018 - 0x0000)
struct OPTION_Display_WindowMode_C_IsDirty final
{
public:
	bool                                          Param_IsDirty_0;                                   // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWindowMode                                   CallFunc_GetWindowMode_Result;                     // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWindowMode                                   CallFunc_Array_Get_Item;                           // 0x0011(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_NotEqual_ByteByte_ReturnValue;            // 0x0012(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OPTION_Display_WindowMode_C_IsDirty) == 0x000008, "Wrong alignment on OPTION_Display_WindowMode_C_IsDirty");
static_assert(sizeof(OPTION_Display_WindowMode_C_IsDirty) == 0x000018, "Wrong size on OPTION_Display_WindowMode_C_IsDirty");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDirty, Param_IsDirty_0) == 0x000000, "Member 'OPTION_Display_WindowMode_C_IsDirty::Param_IsDirty_0' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDirty, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000008, "Member 'OPTION_Display_WindowMode_C_IsDirty::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDirty, CallFunc_GetWindowMode_Result) == 0x000010, "Member 'OPTION_Display_WindowMode_C_IsDirty::CallFunc_GetWindowMode_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDirty, CallFunc_Array_Get_Item) == 0x000011, "Member 'OPTION_Display_WindowMode_C_IsDirty::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDirty, CallFunc_NotEqual_ByteByte_ReturnValue) == 0x000012, "Member 'OPTION_Display_WindowMode_C_IsDirty::CallFunc_NotEqual_ByteByte_ReturnValue' has a wrong offset!");

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.AcceptCurrentValue
// 0x0010 (0x0010 - 0x0000)
struct OPTION_Display_WindowMode_C_AcceptCurrentValue final
{
public:
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWindowMode                                   CallFunc_Array_Get_Item;                           // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_WindowMode_C_AcceptCurrentValue) == 0x000008, "Wrong alignment on OPTION_Display_WindowMode_C_AcceptCurrentValue");
static_assert(sizeof(OPTION_Display_WindowMode_C_AcceptCurrentValue) == 0x000010, "Wrong size on OPTION_Display_WindowMode_C_AcceptCurrentValue");
static_assert(offsetof(OPTION_Display_WindowMode_C_AcceptCurrentValue, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000000, "Member 'OPTION_Display_WindowMode_C_AcceptCurrentValue::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_AcceptCurrentValue, CallFunc_Array_Get_Item) == 0x000008, "Member 'OPTION_Display_WindowMode_C_AcceptCurrentValue::CallFunc_Array_Get_Item' has a wrong offset!");

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.ApplyCleanValue
// 0x0010 (0x0010 - 0x0000)
struct OPTION_Display_WindowMode_C_ApplyCleanValue final
{
public:
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWindowMode                                   CallFunc_GetWindowMode_Result;                     // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_WindowMode_C_ApplyCleanValue) == 0x000008, "Wrong alignment on OPTION_Display_WindowMode_C_ApplyCleanValue");
static_assert(sizeof(OPTION_Display_WindowMode_C_ApplyCleanValue) == 0x000010, "Wrong size on OPTION_Display_WindowMode_C_ApplyCleanValue");
static_assert(offsetof(OPTION_Display_WindowMode_C_ApplyCleanValue, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000000, "Member 'OPTION_Display_WindowMode_C_ApplyCleanValue::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_ApplyCleanValue, CallFunc_GetWindowMode_Result) == 0x000008, "Member 'OPTION_Display_WindowMode_C_ApplyCleanValue::CallFunc_GetWindowMode_Result' has a wrong offset!");

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.UpdateVisuals
// 0x0010 (0x0010 - 0x0000)
struct OPTION_Display_WindowMode_C_UpdateVisuals final
{
public:
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWindowMode                                   CallFunc_GetWindowMode_Result;                     // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_9[0x3];                                        // 0x0009(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_ModeToIndex_Result;                       // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_WindowMode_C_UpdateVisuals) == 0x000008, "Wrong alignment on OPTION_Display_WindowMode_C_UpdateVisuals");
static_assert(sizeof(OPTION_Display_WindowMode_C_UpdateVisuals) == 0x000010, "Wrong size on OPTION_Display_WindowMode_C_UpdateVisuals");
static_assert(offsetof(OPTION_Display_WindowMode_C_UpdateVisuals, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000000, "Member 'OPTION_Display_WindowMode_C_UpdateVisuals::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_UpdateVisuals, CallFunc_GetWindowMode_Result) == 0x000008, "Member 'OPTION_Display_WindowMode_C_UpdateVisuals::CallFunc_GetWindowMode_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_UpdateVisuals, CallFunc_ModeToIndex_Result) == 0x00000C, "Member 'OPTION_Display_WindowMode_C_UpdateVisuals::CallFunc_ModeToIndex_Result' has a wrong offset!");

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.ModeToIndex
// 0x000C (0x000C - 0x0000)
struct OPTION_Display_WindowMode_C_ModeToIndex final
{
public:
	EWindowMode                                   Mode;                                              // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Result;                                            // 0x0004(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_SwitchEnum_CmpSuccess;                      // 0x0008(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OPTION_Display_WindowMode_C_ModeToIndex) == 0x000004, "Wrong alignment on OPTION_Display_WindowMode_C_ModeToIndex");
static_assert(sizeof(OPTION_Display_WindowMode_C_ModeToIndex) == 0x00000C, "Wrong size on OPTION_Display_WindowMode_C_ModeToIndex");
static_assert(offsetof(OPTION_Display_WindowMode_C_ModeToIndex, Mode) == 0x000000, "Member 'OPTION_Display_WindowMode_C_ModeToIndex::Mode' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_ModeToIndex, Result) == 0x000004, "Member 'OPTION_Display_WindowMode_C_ModeToIndex::Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_ModeToIndex, K2Node_SwitchEnum_CmpSuccess) == 0x000008, "Member 'OPTION_Display_WindowMode_C_ModeToIndex::K2Node_SwitchEnum_CmpSuccess' has a wrong offset!");

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.SelectDefaultValue
// 0x0040 (0x0040 - 0x0000)
struct OPTION_Display_WindowMode_C_SelectDefaultValue final
{
public:
	EWindowMode                                   Temp_byte_Variable;                                // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Temp_int_Variable;                                 // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_1;                               // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_2;                               // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 CallFunc_GetPlatformName_ReturnValue;              // 0x0010(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 CallFunc_GetCurrentCulture_ReturnValue;            // 0x0020(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWindowMode                                   CallFunc_GetWindowModeProfileValue_Result;         // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_39[0x3];                                       // 0x0039(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         K2Node_Select_Default;                             // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_WindowMode_C_SelectDefaultValue) == 0x000008, "Wrong alignment on OPTION_Display_WindowMode_C_SelectDefaultValue");
static_assert(sizeof(OPTION_Display_WindowMode_C_SelectDefaultValue) == 0x000040, "Wrong size on OPTION_Display_WindowMode_C_SelectDefaultValue");
static_assert(offsetof(OPTION_Display_WindowMode_C_SelectDefaultValue, Temp_byte_Variable) == 0x000000, "Member 'OPTION_Display_WindowMode_C_SelectDefaultValue::Temp_byte_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_SelectDefaultValue, Temp_int_Variable) == 0x000004, "Member 'OPTION_Display_WindowMode_C_SelectDefaultValue::Temp_int_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_SelectDefaultValue, Temp_int_Variable_1) == 0x000008, "Member 'OPTION_Display_WindowMode_C_SelectDefaultValue::Temp_int_Variable_1' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_SelectDefaultValue, Temp_int_Variable_2) == 0x00000C, "Member 'OPTION_Display_WindowMode_C_SelectDefaultValue::Temp_int_Variable_2' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_SelectDefaultValue, CallFunc_GetPlatformName_ReturnValue) == 0x000010, "Member 'OPTION_Display_WindowMode_C_SelectDefaultValue::CallFunc_GetPlatformName_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_SelectDefaultValue, CallFunc_GetCurrentCulture_ReturnValue) == 0x000020, "Member 'OPTION_Display_WindowMode_C_SelectDefaultValue::CallFunc_GetCurrentCulture_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_SelectDefaultValue, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000030, "Member 'OPTION_Display_WindowMode_C_SelectDefaultValue::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_SelectDefaultValue, CallFunc_GetWindowModeProfileValue_Result) == 0x000038, "Member 'OPTION_Display_WindowMode_C_SelectDefaultValue::CallFunc_GetWindowModeProfileValue_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_SelectDefaultValue, K2Node_Select_Default) == 0x00003C, "Member 'OPTION_Display_WindowMode_C_SelectDefaultValue::K2Node_Select_Default' has a wrong offset!");

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.IsDefault
// 0x0048 (0x0048 - 0x0000)
struct OPTION_Display_WindowMode_C_IsDefault final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	EWindowMode                                   Temp_byte_Variable;                                // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2[0x2];                                        // 0x0002(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Temp_int_Variable;                                 // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_1;                               // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable_2;                               // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 CallFunc_GetPlatformName_ReturnValue;              // 0x0010(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FString                                 CallFunc_GetCurrentCulture_ReturnValue;            // 0x0020(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class USAVE_Settings_C*                       CallFunc_GetShockSettingsForCurrentUser_Settings;  // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWindowMode                                   CallFunc_GetWindowModeProfileValue_Result;         // 0x0038(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_39[0x3];                                       // 0x0039(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         K2Node_Select_Default;                             // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_IntInt_ReturnValue;            // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OPTION_Display_WindowMode_C_IsDefault) == 0x000008, "Wrong alignment on OPTION_Display_WindowMode_C_IsDefault");
static_assert(sizeof(OPTION_Display_WindowMode_C_IsDefault) == 0x000048, "Wrong size on OPTION_Display_WindowMode_C_IsDefault");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, Result) == 0x000000, "Member 'OPTION_Display_WindowMode_C_IsDefault::Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, Temp_byte_Variable) == 0x000001, "Member 'OPTION_Display_WindowMode_C_IsDefault::Temp_byte_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, Temp_int_Variable) == 0x000004, "Member 'OPTION_Display_WindowMode_C_IsDefault::Temp_int_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, Temp_int_Variable_1) == 0x000008, "Member 'OPTION_Display_WindowMode_C_IsDefault::Temp_int_Variable_1' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, Temp_int_Variable_2) == 0x00000C, "Member 'OPTION_Display_WindowMode_C_IsDefault::Temp_int_Variable_2' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, CallFunc_GetPlatformName_ReturnValue) == 0x000010, "Member 'OPTION_Display_WindowMode_C_IsDefault::CallFunc_GetPlatformName_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, CallFunc_GetCurrentCulture_ReturnValue) == 0x000020, "Member 'OPTION_Display_WindowMode_C_IsDefault::CallFunc_GetCurrentCulture_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, CallFunc_GetShockSettingsForCurrentUser_Settings) == 0x000030, "Member 'OPTION_Display_WindowMode_C_IsDefault::CallFunc_GetShockSettingsForCurrentUser_Settings' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, CallFunc_GetWindowModeProfileValue_Result) == 0x000038, "Member 'OPTION_Display_WindowMode_C_IsDefault::CallFunc_GetWindowModeProfileValue_Result' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, K2Node_Select_Default) == 0x00003C, "Member 'OPTION_Display_WindowMode_C_IsDefault::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_IsDefault, CallFunc_EqualEqual_IntInt_ReturnValue) == 0x000040, "Member 'OPTION_Display_WindowMode_C_IsDefault::CallFunc_EqualEqual_IntInt_ReturnValue' has a wrong offset!");

// Function OPTION_Display_WindowMode.OPTION_Display_WindowMode_C.InitializeMenuListItem
// 0x0020 (0x0020 - 0x0000)
struct OPTION_Display_WindowMode_C_InitializeMenuListItem final
{
public:
	class UWIDGET_MenuListBase_C*                 ParentList;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Index_0;                                           // 0x0008(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGameUserSettings*                      CallFunc_GetGameUserSettings_ReturnValue;          // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EWindowMode                                   CallFunc_GetFullscreenMode_ReturnValue;            // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_19[0x3];                                       // 0x0019(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Array_Find_ReturnValue;                   // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_Display_WindowMode_C_InitializeMenuListItem) == 0x000008, "Wrong alignment on OPTION_Display_WindowMode_C_InitializeMenuListItem");
static_assert(sizeof(OPTION_Display_WindowMode_C_InitializeMenuListItem) == 0x000020, "Wrong size on OPTION_Display_WindowMode_C_InitializeMenuListItem");
static_assert(offsetof(OPTION_Display_WindowMode_C_InitializeMenuListItem, ParentList) == 0x000000, "Member 'OPTION_Display_WindowMode_C_InitializeMenuListItem::ParentList' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_InitializeMenuListItem, Index_0) == 0x000008, "Member 'OPTION_Display_WindowMode_C_InitializeMenuListItem::Index_0' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_InitializeMenuListItem, CallFunc_GetGameUserSettings_ReturnValue) == 0x000010, "Member 'OPTION_Display_WindowMode_C_InitializeMenuListItem::CallFunc_GetGameUserSettings_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_InitializeMenuListItem, CallFunc_GetFullscreenMode_ReturnValue) == 0x000018, "Member 'OPTION_Display_WindowMode_C_InitializeMenuListItem::CallFunc_GetFullscreenMode_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_Display_WindowMode_C_InitializeMenuListItem, CallFunc_Array_Find_ReturnValue) == 0x00001C, "Member 'OPTION_Display_WindowMode_C_InitializeMenuListItem::CallFunc_Array_Find_ReturnValue' has a wrong offset!");

}

