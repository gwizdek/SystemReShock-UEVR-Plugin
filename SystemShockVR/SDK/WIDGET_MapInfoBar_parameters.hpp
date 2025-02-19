#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_MapInfoBar

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "STRUCT_LevelInfo_structs.hpp"


namespace SDK::Params
{

// Function WIDGET_MapInfoBar.WIDGET_MapInfoBar_C.ExecuteUbergraph_WIDGET_MapInfoBar
// 0x0098 (0x0098 - 0x0000)
struct WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                Temp_object_Variable;                              // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(class UObject* Loaded)>        K2Node_CreateDelegate_OutputDelegate;              // 0x0010(0x0010)(ZeroConstructor, NoDestructor)
	class UTexture2D*                             K2Node_DynamicCast_AsTexture_2D;                   // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x7];                                       // 0x0029(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void(int32 NewSecurityLevel)>       K2Node_CreateDelegate_OutputDelegate_1;            // 0x0038(0x0010)(ZeroConstructor, NoDestructor)
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess_1;                     // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_51[0x7];                                       // 0x0051(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UTexture2D>              K2Node_CustomEvent_Texture;                        // 0x0058(0x0028)(HasGetValueTypeHash)
	bool                                          CallFunc_IsValidSoftObjectReference_ReturnValue;   // 0x0080(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_81[0x7];                                       // 0x0081(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UObject*                                K2Node_CustomEvent_Loaded;                         // 0x0088(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               CallFunc_ConvertToDynamicMaterialInstance_ReturnValue; // 0x0090(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar) == 0x000008, "Wrong alignment on WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar");
static_assert(sizeof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar) == 0x000098, "Wrong size on WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, EntryPoint) == 0x000000, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::EntryPoint' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, Temp_object_Variable) == 0x000008, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::Temp_object_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, K2Node_CreateDelegate_OutputDelegate) == 0x000010, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, K2Node_DynamicCast_AsTexture_2D) == 0x000020, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::K2Node_DynamicCast_AsTexture_2D' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, K2Node_DynamicCast_bSuccess) == 0x000028, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, CallFunc_GetGameInstance_ReturnValue) == 0x000030, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, K2Node_CreateDelegate_OutputDelegate_1) == 0x000038, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::K2Node_CreateDelegate_OutputDelegate_1' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, K2Node_DynamicCast_AsGI_Single_Player) == 0x000048, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, K2Node_DynamicCast_bSuccess_1) == 0x000050, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::K2Node_DynamicCast_bSuccess_1' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, K2Node_CustomEvent_Texture) == 0x000058, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::K2Node_CustomEvent_Texture' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, CallFunc_IsValidSoftObjectReference_ReturnValue) == 0x000080, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::CallFunc_IsValidSoftObjectReference_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, K2Node_CustomEvent_Loaded) == 0x000088, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::K2Node_CustomEvent_Loaded' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar, CallFunc_ConvertToDynamicMaterialInstance_ReturnValue) == 0x000090, "Member 'WIDGET_MapInfoBar_C_ExecuteUbergraph_WIDGET_MapInfoBar::CallFunc_ConvertToDynamicMaterialInstance_ReturnValue' has a wrong offset!");

// Function WIDGET_MapInfoBar.WIDGET_MapInfoBar_C.SetIconTexture
// 0x0028 (0x0028 - 0x0000)
struct WIDGET_MapInfoBar_C_SetIconTexture final
{
public:
	TSoftObjectPtr<class UTexture2D>              Texture;                                           // 0x0000(0x0028)(BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_MapInfoBar_C_SetIconTexture) == 0x000008, "Wrong alignment on WIDGET_MapInfoBar_C_SetIconTexture");
static_assert(sizeof(WIDGET_MapInfoBar_C_SetIconTexture) == 0x000028, "Wrong size on WIDGET_MapInfoBar_C_SetIconTexture");
static_assert(offsetof(WIDGET_MapInfoBar_C_SetIconTexture, Texture) == 0x000000, "Member 'WIDGET_MapInfoBar_C_SetIconTexture::Texture' has a wrong offset!");

// Function WIDGET_MapInfoBar.WIDGET_MapInfoBar_C.OnLoaded_3740FF584BCD96FEEA1703A114E7515A
// 0x0008 (0x0008 - 0x0000)
struct WIDGET_MapInfoBar_C_OnLoaded_3740FF584BCD96FEEA1703A114E7515A final
{
public:
	class UObject*                                Loaded;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_MapInfoBar_C_OnLoaded_3740FF584BCD96FEEA1703A114E7515A) == 0x000008, "Wrong alignment on WIDGET_MapInfoBar_C_OnLoaded_3740FF584BCD96FEEA1703A114E7515A");
static_assert(sizeof(WIDGET_MapInfoBar_C_OnLoaded_3740FF584BCD96FEEA1703A114E7515A) == 0x000008, "Wrong size on WIDGET_MapInfoBar_C_OnLoaded_3740FF584BCD96FEEA1703A114E7515A");
static_assert(offsetof(WIDGET_MapInfoBar_C_OnLoaded_3740FF584BCD96FEEA1703A114E7515A, Loaded) == 0x000000, "Member 'WIDGET_MapInfoBar_C_OnLoaded_3740FF584BCD96FEEA1703A114E7515A::Loaded' has a wrong offset!");

// Function WIDGET_MapInfoBar.WIDGET_MapInfoBar_C.UpdateLevelDetails
// 0x01C8 (0x01C8 - 0x0000)
struct WIDGET_MapInfoBar_C_UpdateLevelDetails final
{
public:
	class FName                                   LevelName;                                         // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UTexture2D*                             DeckIcon;                                          // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGI_SinglePlayer_C*                     GameInstance;                                      // 0x0010(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetSecurityForLevel_Result;               // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1C[0x4];                                       // 0x001C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0020(0x0040)(HasGetValueTypeHash)
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0060(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSTRUCT_LevelInfo                      CallFunc_GetLevelInfo_LevelInfo;                   // 0x0068(0x00C8)(HasGetValueTypeHash)
	bool                                          CallFunc_GetLevelInfo_Found;                       // 0x0130(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_131[0x7];                                      // 0x0131(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0138(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0140(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_141[0x7];                                      // 0x0141(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_Conv_StringToText_ReturnValue;            // 0x0148(0x0018)()
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData_1;            // 0x0160(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x01A0(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x01B0(0x0018)()
};
static_assert(alignof(WIDGET_MapInfoBar_C_UpdateLevelDetails) == 0x000008, "Wrong alignment on WIDGET_MapInfoBar_C_UpdateLevelDetails");
static_assert(sizeof(WIDGET_MapInfoBar_C_UpdateLevelDetails) == 0x0001C8, "Wrong size on WIDGET_MapInfoBar_C_UpdateLevelDetails");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, LevelName) == 0x000000, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::LevelName' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, DeckIcon) == 0x000008, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::DeckIcon' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, GameInstance) == 0x000010, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::GameInstance' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, CallFunc_GetSecurityForLevel_Result) == 0x000018, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::CallFunc_GetSecurityForLevel_Result' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, K2Node_MakeStruct_FormatArgumentData) == 0x000020, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::K2Node_MakeStruct_FormatArgumentData' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, CallFunc_GetGameInstance_ReturnValue) == 0x000060, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, CallFunc_GetLevelInfo_LevelInfo) == 0x000068, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::CallFunc_GetLevelInfo_LevelInfo' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, CallFunc_GetLevelInfo_Found) == 0x000130, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::CallFunc_GetLevelInfo_Found' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, K2Node_DynamicCast_AsGI_Single_Player) == 0x000138, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, K2Node_DynamicCast_bSuccess) == 0x000140, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, CallFunc_Conv_StringToText_ReturnValue) == 0x000148, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::CallFunc_Conv_StringToText_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, K2Node_MakeStruct_FormatArgumentData_1) == 0x000160, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::K2Node_MakeStruct_FormatArgumentData_1' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, K2Node_MakeArray_Array) == 0x0001A0, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_UpdateLevelDetails, CallFunc_Format_ReturnValue) == 0x0001B0, "Member 'WIDGET_MapInfoBar_C_UpdateLevelDetails::CallFunc_Format_ReturnValue' has a wrong offset!");

// Function WIDGET_MapInfoBar.WIDGET_MapInfoBar_C.EVENT_OnLevelSecurityChanged
// 0x0038 (0x0038 - 0x0000)
struct WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged final
{
public:
	int32                                         SecurityLevel;                                     // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UGI_SinglePlayer_C*                     GameInstance;                                      // 0x0008(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   CallFunc_GetCurrentLevelName_Result;               // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_EqualEqual_NameName_ReturnValue;          // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_21[0x7];                                       // 0x0021(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UGI_SinglePlayer_C*                     K2Node_DynamicCast_AsGI_Single_Player;             // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged) == 0x000008, "Wrong alignment on WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged");
static_assert(sizeof(WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged) == 0x000038, "Wrong size on WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged");
static_assert(offsetof(WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged, SecurityLevel) == 0x000000, "Member 'WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged::SecurityLevel' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged, GameInstance) == 0x000008, "Member 'WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged::GameInstance' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged, CallFunc_GetCurrentLevelName_Result) == 0x000010, "Member 'WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged::CallFunc_GetCurrentLevelName_Result' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged, CallFunc_GetGameInstance_ReturnValue) == 0x000018, "Member 'WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged, CallFunc_EqualEqual_NameName_ReturnValue) == 0x000020, "Member 'WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged::CallFunc_EqualEqual_NameName_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged, K2Node_DynamicCast_AsGI_Single_Player) == 0x000028, "Member 'WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged::K2Node_DynamicCast_AsGI_Single_Player' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged, K2Node_DynamicCast_bSuccess) == 0x000030, "Member 'WIDGET_MapInfoBar_C_EVENT_OnLevelSecurityChanged::K2Node_DynamicCast_bSuccess' has a wrong offset!");

// Function WIDGET_MapInfoBar.WIDGET_MapInfoBar_C.SetSecurityLevelPercentage
// 0x0070 (0x0070 - 0x0000)
struct WIDGET_MapInfoBar_C_SetSecurityLevelPercentage final
{
public:
	int32                                         SecurityPercentage;                                // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0008(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0048(0x0010)(ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0058(0x0018)()
};
static_assert(alignof(WIDGET_MapInfoBar_C_SetSecurityLevelPercentage) == 0x000008, "Wrong alignment on WIDGET_MapInfoBar_C_SetSecurityLevelPercentage");
static_assert(sizeof(WIDGET_MapInfoBar_C_SetSecurityLevelPercentage) == 0x000070, "Wrong size on WIDGET_MapInfoBar_C_SetSecurityLevelPercentage");
static_assert(offsetof(WIDGET_MapInfoBar_C_SetSecurityLevelPercentage, SecurityPercentage) == 0x000000, "Member 'WIDGET_MapInfoBar_C_SetSecurityLevelPercentage::SecurityPercentage' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_SetSecurityLevelPercentage, K2Node_MakeStruct_FormatArgumentData) == 0x000008, "Member 'WIDGET_MapInfoBar_C_SetSecurityLevelPercentage::K2Node_MakeStruct_FormatArgumentData' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_SetSecurityLevelPercentage, K2Node_MakeArray_Array) == 0x000048, "Member 'WIDGET_MapInfoBar_C_SetSecurityLevelPercentage::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(WIDGET_MapInfoBar_C_SetSecurityLevelPercentage, CallFunc_Format_ReturnValue) == 0x000058, "Member 'WIDGET_MapInfoBar_C_SetSecurityLevelPercentage::CallFunc_Format_ReturnValue' has a wrong offset!");

}

