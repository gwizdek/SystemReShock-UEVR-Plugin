#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_OptionsMenu_Base

#include "Basic.hpp"

#include "WIDGET_OptionsMenu_Base_classes.hpp"
#include "WIDGET_OptionsMenu_Base_parameters.hpp"


namespace SDK
{

// Function WIDGET_OptionsMenu_Base.WIDGET_OptionsMenu_Base_C.OnMenuClose
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_OptionsMenu_Base_C::OnMenuClose()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_OptionsMenu_Base_C", "OnMenuClose");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_OptionsMenu_Base.WIDGET_OptionsMenu_Base_C.OnMenuOpen
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_OptionsMenu_Base_C::OnMenuOpen()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_OptionsMenu_Base_C", "OnMenuOpen");

	UObject::ProcessEvent(Func, nullptr);
}

}

