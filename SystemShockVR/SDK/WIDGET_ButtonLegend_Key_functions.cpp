#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_ButtonLegend_Key

#include "Basic.hpp"

#include "WIDGET_ButtonLegend_Key_classes.hpp"
#include "WIDGET_ButtonLegend_Key_parameters.hpp"


namespace SDK
{

// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.OnLegendKeySizedChanged__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UWIDGET_ButtonLegend_Key_C::OnLegendKeySizedChanged__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "OnLegendKeySizedChanged__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.ExecuteUbergraph_WIDGET_ButtonLegend_Key
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_ButtonLegend_Key_C::ExecuteUbergraph_WIDGET_ButtonLegend_Key(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "ExecuteUbergraph_WIDGET_ButtonLegend_Key");

	Params::WIDGET_ButtonLegend_Key_C_ExecuteUbergraph_WIDGET_ButtonLegend_Key Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.SetDecoratorColor
// (Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FColor                           Color                                                  (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_ButtonLegend_Key_C::SetDecoratorColor(const struct FColor& Color)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "SetDecoratorColor");

	Params::WIDGET_ButtonLegend_Key_C_SetDecoratorColor Parms{};

	Parms.Color = std::move(Color);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWIDGET_ButtonLegend_Key_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ButtonLegend_Key_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "PreConstruct");

	Params::WIDGET_ButtonLegend_Key_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.InitializeLegendKey
// (Protected, BlueprintCallable, BlueprintEvent)

void UWIDGET_ButtonLegend_Key_C::InitializeLegendKey()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "InitializeLegendKey");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.SetLegendKey
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FKey                             Key                                                    (BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)

void UWIDGET_ButtonLegend_Key_C::SetLegendKey(const struct FKey& Key)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "SetLegendKey");

	Params::WIDGET_ButtonLegend_Key_C_SetLegendKey Parms{};

	Parms.Key = std::move(Key);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.SetLegendInputAction
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           ActionString                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)

void UWIDGET_ButtonLegend_Key_C::SetLegendInputAction(const class FString& ActionString)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "SetLegendInputAction");

	Params::WIDGET_ButtonLegend_Key_C_SetLegendInputAction Parms{};

	Parms.ActionString = std::move(ActionString);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.SetLegendColor
// (Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FColor                           Color                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_ButtonLegend_Key_C::SetLegendColor(const struct FColor& Color)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "SetLegendColor");

	Params::WIDGET_ButtonLegend_Key_C_SetLegendColor Parms{};

	Parms.Color = std::move(Color);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.UpdateWidgetVisibility
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsUsingGamepad                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Visible                                                (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ButtonLegend_Key_C::UpdateWidgetVisibility(bool IsUsingGamepad, bool* Visible)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "UpdateWidgetVisibility");

	Params::WIDGET_ButtonLegend_Key_C_UpdateWidgetVisibility Parms{};

	Parms.IsUsingGamepad = IsUsingGamepad;

	UObject::ProcessEvent(Func, &Parms);

	if (Visible != nullptr)
		*Visible = Parms.Visible;
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.UpdateLegend
// (Protected, HasDefaults, BlueprintCallable, BlueprintEvent)

void UWIDGET_ButtonLegend_Key_C::UpdateLegend()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "UpdateLegend");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.GetKeyTextColor
// (Private, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FColor                           Color                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_ButtonLegend_Key_C::GetKeyTextColor(struct FColor* Color)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "GetKeyTextColor");

	Params::WIDGET_ButtonLegend_Key_C_GetKeyTextColor Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Color != nullptr)
		*Color = std::move(Parms.Color);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.GetKeyPanelSize
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector2D                        Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_ButtonLegend_Key_C::GetKeyPanelSize(struct FVector2D* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "GetKeyPanelSize");

	Params::WIDGET_ButtonLegend_Key_C_GetKeyPanelSize Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = std::move(Parms.Result);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.ParseInputActionFromString
// (Private, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           InputString                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// bool                                    IsUsingGamepad                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// class FName                             Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_ButtonLegend_Key_C::ParseInputActionFromString(const class FString& InputString, bool IsUsingGamepad, class FName* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "ParseInputActionFromString");

	Params::WIDGET_ButtonLegend_Key_C_ParseInputActionFromString Parms{};

	Parms.InputString = std::move(InputString);
	Parms.IsUsingGamepad = IsUsingGamepad;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.TryUpdateLegendSize
// (Private, BlueprintCallable, BlueprintEvent)

void UWIDGET_ButtonLegend_Key_C::TryUpdateLegendSize()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "TryUpdateLegendSize");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.SetHighlighted
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ButtonLegend_Key_C::SetHighlighted(bool State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "SetHighlighted");

	Params::WIDGET_ButtonLegend_Key_C_SetHighlighted Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.SetDisabled
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ButtonLegend_Key_C::SetDisabled(bool State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "SetDisabled");

	Params::WIDGET_ButtonLegend_Key_C_SetDisabled Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.EVENT_OnUsingGamepadChanged
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsUsingGamepad                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ButtonLegend_Key_C::EVENT_OnUsingGamepadChanged(bool IsUsingGamepad)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "EVENT_OnUsingGamepadChanged");

	Params::WIDGET_ButtonLegend_Key_C_EVENT_OnUsingGamepadChanged Parms{};

	Parms.IsUsingGamepad = IsUsingGamepad;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.SetAutoSwapToGamepad
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ButtonLegend_Key_C::SetAutoSwapToGamepad(bool State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "SetAutoSwapToGamepad");

	Params::WIDGET_ButtonLegend_Key_C_SetAutoSwapToGamepad Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.GetDecoratorSizeFromPayload
// (Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           Payload                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// struct FVector2D                        ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

struct FVector2D UWIDGET_ButtonLegend_Key_C::GetDecoratorSizeFromPayload(const class FString& Payload)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "GetDecoratorSizeFromPayload");

	Params::WIDGET_ButtonLegend_Key_C_GetDecoratorSizeFromPayload Parms{};

	Parms.Payload = std::move(Payload);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.InitializeDecorator
// (Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UTextMeshWidget*                  TextMeshWidget                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FColor                           Color                                                  (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)

bool UWIDGET_ButtonLegend_Key_C::InitializeDecorator(class UTextMeshWidget* TextMeshWidget, const struct FColor& Color)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ButtonLegend_Key_C", "InitializeDecorator");

	Params::WIDGET_ButtonLegend_Key_C_InitializeDecorator Parms{};

	Parms.TextMeshWidget = TextMeshWidget;
	Parms.Color = std::move(Color);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

