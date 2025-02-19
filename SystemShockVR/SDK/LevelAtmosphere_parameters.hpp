#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: LevelAtmosphere

#include "Basic.hpp"

#include "STRUCT_LevelInfo_structs.hpp"
#include "STRUCT_LevelAtmosphereSettings_structs.hpp"


namespace SDK::Params
{

// Function LevelAtmosphere.LevelAtmosphere_C.UserConstructionScript
// 0x0110 (0x0110 - 0x0000)
struct LevelAtmosphere_C_UserConstructionScript final
{
public:
	class FString                                 CallFunc_GetCurrentLevelName_ReturnValue;          // 0x0000(0x0010)(ZeroConstructor, HasGetValueTypeHash)
	class FName                                   CallFunc_Conv_StringToName_ReturnValue;            // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSTRUCT_LevelInfo                      CallFunc_GetDataTableRowFromName_OutRow;           // 0x0018(0x00C8)(HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue;      // 0x00E0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_E1[0x3];                                       // 0x00E1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSTRUCT_LevelAtmosphereSettings        CallFunc_GetDataTableRowFromName_OutRow_1;         // 0x00E4(0x0024)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GetDataTableRowFromName_ReturnValue_1;    // 0x0108(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(LevelAtmosphere_C_UserConstructionScript) == 0x000008, "Wrong alignment on LevelAtmosphere_C_UserConstructionScript");
static_assert(sizeof(LevelAtmosphere_C_UserConstructionScript) == 0x000110, "Wrong size on LevelAtmosphere_C_UserConstructionScript");
static_assert(offsetof(LevelAtmosphere_C_UserConstructionScript, CallFunc_GetCurrentLevelName_ReturnValue) == 0x000000, "Member 'LevelAtmosphere_C_UserConstructionScript::CallFunc_GetCurrentLevelName_ReturnValue' has a wrong offset!");
static_assert(offsetof(LevelAtmosphere_C_UserConstructionScript, CallFunc_Conv_StringToName_ReturnValue) == 0x000010, "Member 'LevelAtmosphere_C_UserConstructionScript::CallFunc_Conv_StringToName_ReturnValue' has a wrong offset!");
static_assert(offsetof(LevelAtmosphere_C_UserConstructionScript, CallFunc_GetDataTableRowFromName_OutRow) == 0x000018, "Member 'LevelAtmosphere_C_UserConstructionScript::CallFunc_GetDataTableRowFromName_OutRow' has a wrong offset!");
static_assert(offsetof(LevelAtmosphere_C_UserConstructionScript, CallFunc_GetDataTableRowFromName_ReturnValue) == 0x0000E0, "Member 'LevelAtmosphere_C_UserConstructionScript::CallFunc_GetDataTableRowFromName_ReturnValue' has a wrong offset!");
static_assert(offsetof(LevelAtmosphere_C_UserConstructionScript, CallFunc_GetDataTableRowFromName_OutRow_1) == 0x0000E4, "Member 'LevelAtmosphere_C_UserConstructionScript::CallFunc_GetDataTableRowFromName_OutRow_1' has a wrong offset!");
static_assert(offsetof(LevelAtmosphere_C_UserConstructionScript, CallFunc_GetDataTableRowFromName_ReturnValue_1) == 0x000108, "Member 'LevelAtmosphere_C_UserConstructionScript::CallFunc_GetDataTableRowFromName_ReturnValue_1' has a wrong offset!");

}

