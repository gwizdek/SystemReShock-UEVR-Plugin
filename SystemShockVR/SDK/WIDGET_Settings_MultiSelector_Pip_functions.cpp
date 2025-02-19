#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_Settings_MultiSelector_Pip

#include "Basic.hpp"

#include "WIDGET_Settings_MultiSelector_Pip_classes.hpp"
#include "WIDGET_Settings_MultiSelector_Pip_parameters.hpp"


namespace SDK
{

// Function WIDGET_Settings_MultiSelector_Pip.WIDGET_Settings_MultiSelector_Pip_C.SetSelected
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Selected                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_Settings_MultiSelector_Pip_C::SetSelected(bool Selected)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_Settings_MultiSelector_Pip_C", "SetSelected");

	Params::WIDGET_Settings_MultiSelector_Pip_C_SetSelected Parms{};

	Parms.Selected = Selected;

	UObject::ProcessEvent(Func, &Parms);
}

}

