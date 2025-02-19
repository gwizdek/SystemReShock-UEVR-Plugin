#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OPTION_Interface_Subtitles

#include "Basic.hpp"

#include "OPTION_Interface_Subtitles_classes.hpp"
#include "OPTION_Interface_Subtitles_parameters.hpp"


namespace SDK
{

// Function OPTION_Interface_Subtitles.OPTION_Interface_Subtitles_C.AcceptCurrentValue
// (Public, BlueprintCallable, BlueprintEvent)

void UOPTION_Interface_Subtitles_C::AcceptCurrentValue()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("OPTION_Interface_Subtitles_C", "AcceptCurrentValue");

	UObject::ProcessEvent(Func, nullptr);
}


// Function OPTION_Interface_Subtitles.OPTION_Interface_Subtitles_C.ApplyDirtyValue
// (Public, BlueprintCallable, BlueprintEvent)

void UOPTION_Interface_Subtitles_C::ApplyDirtyValue()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("OPTION_Interface_Subtitles_C", "ApplyDirtyValue");

	UObject::ProcessEvent(Func, nullptr);
}


// Function OPTION_Interface_Subtitles.OPTION_Interface_Subtitles_C.IsDirty
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Param_IsDirty_0                                        (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UOPTION_Interface_Subtitles_C::IsDirty(bool* Param_IsDirty_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("OPTION_Interface_Subtitles_C", "IsDirty");

	Params::OPTION_Interface_Subtitles_C_IsDirty Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Param_IsDirty_0 != nullptr)
		*Param_IsDirty_0 = Parms.Param_IsDirty_0;
}


// Function OPTION_Interface_Subtitles.OPTION_Interface_Subtitles_C.UpdateVisuals
// (Public, BlueprintCallable, BlueprintEvent)

void UOPTION_Interface_Subtitles_C::UpdateVisuals()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("OPTION_Interface_Subtitles_C", "UpdateVisuals");

	UObject::ProcessEvent(Func, nullptr);
}


// Function OPTION_Interface_Subtitles.OPTION_Interface_Subtitles_C.SelectDefaultValue
// (Public, BlueprintCallable, BlueprintEvent)

void UOPTION_Interface_Subtitles_C::SelectDefaultValue()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("OPTION_Interface_Subtitles_C", "SelectDefaultValue");

	UObject::ProcessEvent(Func, nullptr);
}


// Function OPTION_Interface_Subtitles.OPTION_Interface_Subtitles_C.IsDefault
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UOPTION_Interface_Subtitles_C::IsDefault(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("OPTION_Interface_Subtitles_C", "IsDefault");

	Params::OPTION_Interface_Subtitles_C_IsDefault Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

