#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OPTION_GameConfig_HackerGender

#include "Basic.hpp"

#include "ENUM_HackerGender_structs.hpp"


namespace SDK::Params
{

// Function OPTION_GameConfig_HackerGender.OPTION_GameConfig_HackerGender_C.PopulateUniqueSettings
// 0x0068 (0x0068 - 0x0000)
struct OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings final
{
public:
	ENUM_HackerGender                             Temp_byte_Variable;                                // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1[0x3];                                        // 0x0001(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_MakeLiteralInt_ReturnValue;               // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Temp_int_Variable;                                 // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Subtract_IntInt_ReturnValue;              // 0x000C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         CallFunc_Conv_IntToByte_ReturnValue;               // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_LessEqual_IntInt_ReturnValue;             // 0x0011(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         CallFunc_GetValidValue_ReturnValue;                // 0x0012(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_13[0x1];                                       // 0x0013(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0014(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   CallFunc_MakeLiteralText_ReturnValue;              // 0x0018(0x0018)()
	class FText                                   CallFunc_MakeLiteralText_ReturnValue_1;            // 0x0030(0x0018)()
	class FText                                   K2Node_Select_Default;                             // 0x0048(0x0018)(ConstParm)
	int32                                         CallFunc_Array_Add_ReturnValue;                    // 0x0060(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings) == 0x000008, "Wrong alignment on OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings");
static_assert(sizeof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings) == 0x000068, "Wrong size on OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, Temp_byte_Variable) == 0x000000, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::Temp_byte_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, CallFunc_MakeLiteralInt_ReturnValue) == 0x000004, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::CallFunc_MakeLiteralInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, Temp_int_Variable) == 0x000008, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::Temp_int_Variable' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, CallFunc_Subtract_IntInt_ReturnValue) == 0x00000C, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::CallFunc_Subtract_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, CallFunc_Conv_IntToByte_ReturnValue) == 0x000010, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::CallFunc_Conv_IntToByte_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, CallFunc_LessEqual_IntInt_ReturnValue) == 0x000011, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::CallFunc_LessEqual_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, CallFunc_GetValidValue_ReturnValue) == 0x000012, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::CallFunc_GetValidValue_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, CallFunc_Add_IntInt_ReturnValue) == 0x000014, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, CallFunc_MakeLiteralText_ReturnValue) == 0x000018, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::CallFunc_MakeLiteralText_ReturnValue' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, CallFunc_MakeLiteralText_ReturnValue_1) == 0x000030, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::CallFunc_MakeLiteralText_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, K2Node_Select_Default) == 0x000048, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings, CallFunc_Array_Add_ReturnValue) == 0x000060, "Member 'OPTION_GameConfig_HackerGender_C_PopulateUniqueSettings::CallFunc_Array_Add_ReturnValue' has a wrong offset!");

}

