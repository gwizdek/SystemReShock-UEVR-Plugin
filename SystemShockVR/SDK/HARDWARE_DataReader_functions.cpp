#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HARDWARE_DataReader

#include "Basic.hpp"

#include "HARDWARE_DataReader_classes.hpp"
#include "HARDWARE_DataReader_parameters.hpp"


namespace SDK
{

// Function HARDWARE_DataReader.HARDWARE_DataReader_C.ExecuteUbergraph_HARDWARE_DataReader
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UHARDWARE_DataReader_C::ExecuteUbergraph_HARDWARE_DataReader(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_DataReader_C", "ExecuteUbergraph_HARDWARE_DataReader");

	Params::HARDWARE_DataReader_C_ExecuteUbergraph_HARDWARE_DataReader Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HARDWARE_DataReader.HARDWARE_DataReader_C.EnableMediaReaderDisplayMesh
// (BlueprintCallable, BlueprintEvent)

void UHARDWARE_DataReader_C::EnableMediaReaderDisplayMesh()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_DataReader_C", "EnableMediaReaderDisplayMesh");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HARDWARE_DataReader.HARDWARE_DataReader_C.OnLoaded_2B54F99340094416C6C6069C21D1072C
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                          Loaded                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UHARDWARE_DataReader_C::OnLoaded_2B54F99340094416C6C6069C21D1072C(class UObject* Loaded)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_DataReader_C", "OnLoaded_2B54F99340094416C6C6069C21D1072C");

	Params::HARDWARE_DataReader_C_OnLoaded_2B54F99340094416C6C6069C21D1072C Parms{};

	Parms.Loaded = Loaded;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HARDWARE_DataReader.HARDWARE_DataReader_C.OnLoaded_65EE3A914F0C398482905DB02E5CDD54
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                          Loaded                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UHARDWARE_DataReader_C::OnLoaded_65EE3A914F0C398482905DB02E5CDD54(class UObject* Loaded)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_DataReader_C", "OnLoaded_65EE3A914F0C398482905DB02E5CDD54");

	Params::HARDWARE_DataReader_C_OnLoaded_65EE3A914F0C398482905DB02E5CDD54 Parms{};

	Parms.Loaded = Loaded;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HARDWARE_DataReader.HARDWARE_DataReader_C.OnIncomingTransmission
// (Private, BlueprintCallable, BlueprintEvent)

void UHARDWARE_DataReader_C::OnIncomingTransmission()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_DataReader_C", "OnIncomingTransmission");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HARDWARE_DataReader.HARDWARE_DataReader_C.ReceiveAnimationMessage
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           Message                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UHARDWARE_DataReader_C::ReceiveAnimationMessage(const class FString& Message, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_DataReader_C", "ReceiveAnimationMessage");

	Params::HARDWARE_DataReader_C_ReceiveAnimationMessage Parms{};

	Parms.Message = std::move(Message);

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function HARDWARE_DataReader.HARDWARE_DataReader_C.OnAddedToInventory
// (Public, BlueprintCallable, BlueprintEvent)

void UHARDWARE_DataReader_C::OnAddedToInventory()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_DataReader_C", "OnAddedToInventory");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HARDWARE_DataReader.HARDWARE_DataReader_C.OnBeginPlay
// (Public, BlueprintCallable, BlueprintEvent)

void UHARDWARE_DataReader_C::OnBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_DataReader_C", "OnBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}

}

