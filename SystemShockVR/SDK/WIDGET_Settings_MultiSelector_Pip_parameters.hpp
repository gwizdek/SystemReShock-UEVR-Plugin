#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_Settings_MultiSelector_Pip

#include "Basic.hpp"


namespace SDK::Params
{

// Function WIDGET_Settings_MultiSelector_Pip.WIDGET_Settings_MultiSelector_Pip_C.SetSelected
// 0x0018 (0x0018 - 0x0000)
struct WIDGET_Settings_MultiSelector_Pip_C_SetSelected final
{
public:
	bool                                          Selected;                                          // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInstanceDynamic*               CallFunc_GetDynamicMaterial_ReturnValue;           // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               CallFunc_GetDynamicMaterial_ReturnValue_1;         // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_Settings_MultiSelector_Pip_C_SetSelected) == 0x000008, "Wrong alignment on WIDGET_Settings_MultiSelector_Pip_C_SetSelected");
static_assert(sizeof(WIDGET_Settings_MultiSelector_Pip_C_SetSelected) == 0x000018, "Wrong size on WIDGET_Settings_MultiSelector_Pip_C_SetSelected");
static_assert(offsetof(WIDGET_Settings_MultiSelector_Pip_C_SetSelected, Selected) == 0x000000, "Member 'WIDGET_Settings_MultiSelector_Pip_C_SetSelected::Selected' has a wrong offset!");
static_assert(offsetof(WIDGET_Settings_MultiSelector_Pip_C_SetSelected, CallFunc_GetDynamicMaterial_ReturnValue) == 0x000008, "Member 'WIDGET_Settings_MultiSelector_Pip_C_SetSelected::CallFunc_GetDynamicMaterial_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_Settings_MultiSelector_Pip_C_SetSelected, CallFunc_GetDynamicMaterial_ReturnValue_1) == 0x000010, "Member 'WIDGET_Settings_MultiSelector_Pip_C_SetSelected::CallFunc_GetDynamicMaterial_ReturnValue_1' has a wrong offset!");

}

