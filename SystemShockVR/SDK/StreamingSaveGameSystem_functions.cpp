#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: StreamingSaveGameSystem

#include "Basic.hpp"

#include "StreamingSaveGameSystem_classes.hpp"
#include "StreamingSaveGameSystem_parameters.hpp"


namespace SDK
{

// Function StreamingSaveGameSystem.SingleplayerGameInstance.CreateSaveDataForLevel
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class ULevel*                           Level                                                  (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool USingleplayerGameInstance::CreateSaveDataForLevel(class ULevel* Level)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "CreateSaveDataForLevel");

	Params::SingleplayerGameInstance_CreateSaveDataForLevel Parms{};

	Parms.Level = Level;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.GetGameSession
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UStreamingSaveGameSession*        ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

class UStreamingSaveGameSession* USingleplayerGameInstance::GetGameSession()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "GetGameSession");

	Params::SingleplayerGameInstance_GetGameSession Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.InitializeLevelFromSaveData
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class ULevel*                           Level                                                  (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool USingleplayerGameInstance::InitializeLevelFromSaveData(class ULevel* Level)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "InitializeLevelFromSaveData");

	Params::SingleplayerGameInstance_InitializeLevelFromSaveData Parms{};

	Parms.Level = Level;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.OnControllerConnectionChange
// (Event, Public, BlueprintEvent)
// Parameters:
// bool                                    bIsConnected                                           (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   UserIndex                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void USingleplayerGameInstance::OnControllerConnectionChange(bool bIsConnected, int32 UserIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "OnControllerConnectionChange");

	Params::SingleplayerGameInstance_OnControllerConnectionChange Parms{};

	Parms.bIsConnected = bIsConnected;
	Parms.UserIndex = UserIndex;

	UObject::ProcessEvent(Func, &Parms);
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.OnFinishedLoadingGame
// (Event, Public, BlueprintEvent)

void USingleplayerGameInstance::OnFinishedLoadingGame()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "OnFinishedLoadingGame");

	UObject::ProcessEvent(Func, nullptr);
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.OnFinishedLoadingLevel
// (Event, Public, BlueprintEvent)
// Parameters:
// class FString                           MapName                                                (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void USingleplayerGameInstance::OnFinishedLoadingLevel(const class FString& MapName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "OnFinishedLoadingLevel");

	Params::SingleplayerGameInstance_OnFinishedLoadingLevel Parms{};

	Parms.MapName = std::move(MapName);

	UObject::ProcessEvent(Func, &Parms);
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.OnNewGameStarted
// (Event, Public, BlueprintEvent)
// Parameters:
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool USingleplayerGameInstance::OnNewGameStarted()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "OnNewGameStarted");

	Params::SingleplayerGameInstance_OnNewGameStarted Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.OnOnlineConnectionStatusChange
// (Event, Public, BlueprintEvent)
// Parameters:
// bool                                    bIsConnected                                           (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void USingleplayerGameInstance::OnOnlineConnectionStatusChange(bool bIsConnected)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "OnOnlineConnectionStatusChange");

	Params::SingleplayerGameInstance_OnOnlineConnectionStatusChange Parms{};

	Parms.bIsConnected = bIsConnected;

	UObject::ProcessEvent(Func, &Parms);
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.OnStartedLoadingGame
// (Event, Public, BlueprintEvent)

void USingleplayerGameInstance::OnStartedLoadingGame()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "OnStartedLoadingGame");

	UObject::ProcessEvent(Func, nullptr);
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.OnTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void USingleplayerGameInstance::OnTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "OnTick");

	Params::SingleplayerGameInstance_OnTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.SetGameDefaultDifficulty
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// int32                                   DefaultDifficulty                                      (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void USingleplayerGameInstance::SetGameDefaultDifficulty(int32 DefaultDifficulty)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "SetGameDefaultDifficulty");

	Params::SingleplayerGameInstance_SetGameDefaultDifficulty Parms{};

	Parms.DefaultDifficulty = DefaultDifficulty;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.StartNewGame
// (Final, Native, Public, BlueprintCallable)

void USingleplayerGameInstance::StartNewGame()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "StartNewGame");

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, nullptr);

	Func->FunctionFlags = Flgs;
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.GetTotalPlayTimeSeconds
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// float                                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

float USingleplayerGameInstance::GetTotalPlayTimeSeconds() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "GetTotalPlayTimeSeconds");

	Params::SingleplayerGameInstance_GetTotalPlayTimeSeconds Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.IsInGame
// (Event, Public, BlueprintEvent, Const)
// Parameters:
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool USingleplayerGameInstance::IsInGame() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "IsInGame");

	Params::SingleplayerGameInstance_IsInGame Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.SingleplayerGameInstance.IsSavePendingAsyncCompletion
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// class FString                           SaveName                                               (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool USingleplayerGameInstance::IsSavePendingAsyncCompletion(const class FString& SaveName) const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SingleplayerGameInstance", "IsSavePendingAsyncCompletion");

	Params::SingleplayerGameInstance_IsSavePendingAsyncCompletion Parms{};

	Parms.SaveName = std::move(SaveName);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameActorInterface.ReceivePendingBodyTransforms
// (Native, Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class USkeletalMeshComponent*           SkeletalMeshComponent                                  (Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// TArray<struct FTransform>               BodyTransforms                                         (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool IStreamingSaveGameActorInterface::ReceivePendingBodyTransforms(class USkeletalMeshComponent* SkeletalMeshComponent, const TArray<struct FTransform>& BodyTransforms)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameActorInterface", "ReceivePendingBodyTransforms");

	Params::StreamingSaveGameActorInterface_ReceivePendingBodyTransforms Parms{};

	Parms.SkeletalMeshComponent = SkeletalMeshComponent;
	Parms.BodyTransforms = std::move(BodyTransforms);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameActorInterface.ReceivePendingCharacterVelocity
// (Native, Event, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          Velocity                                               (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool IStreamingSaveGameActorInterface::ReceivePendingCharacterVelocity(const struct FVector& Velocity)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameActorInterface", "ReceivePendingCharacterVelocity");

	Params::StreamingSaveGameActorInterface_ReceivePendingCharacterVelocity Parms{};

	Parms.Velocity = std::move(Velocity);

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameActorInterface.ShouldSaveActor
// (Native, Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FStreamingSaveGameActorParams    Params_0                                               (Parm, OutParm, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool IStreamingSaveGameActorInterface::ShouldSaveActor(struct FStreamingSaveGameActorParams* Params_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameActorInterface", "ShouldSaveActor");

	Params::StreamingSaveGameActorInterface_ShouldSaveActor Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (Params_0 != nullptr)
		*Params_0 = std::move(Parms.Params_0);

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameComponentInterface.ShouldSaveComponent
// (Native, Event, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FStreamingSaveGameComponentParamsParams_0                                               (Parm, OutParm, NoDestructor, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool IStreamingSaveGameComponentInterface::ShouldSaveComponent(struct FStreamingSaveGameComponentParams* Params_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameComponentInterface", "ShouldSaveComponent");

	Params::StreamingSaveGameComponentInterface_ShouldSaveComponent Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	if (Params_0 != nullptr)
		*Params_0 = std::move(Parms.Params_0);

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameFunctionLibrary.CreateGameProfile
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// class UObject*                          WorldContextObject                                     (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FString                           SaveName                                               (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FString                           SaveCaption                                            (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   UserIndex                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class UStreamingSaveGameProfile*        ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

class UStreamingSaveGameProfile* UStreamingSaveGameFunctionLibrary::CreateGameProfile(class UObject* WorldContextObject, const class FString& SaveName, const class FString& SaveCaption, int32 UserIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("StreamingSaveGameFunctionLibrary", "CreateGameProfile");

	Params::StreamingSaveGameFunctionLibrary_CreateGameProfile Parms{};

	Parms.WorldContextObject = WorldContextObject;
	Parms.SaveName = std::move(SaveName);
	Parms.SaveCaption = std::move(SaveCaption);
	Parms.UserIndex = UserIndex;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameFunctionLibrary.DeleteSaveGameByName
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// class UObject*                          WorldContextObject                                     (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FString                           SaveName                                               (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   UserIndex                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UStreamingSaveGameFunctionLibrary::DeleteSaveGameByName(class UObject* WorldContextObject, const class FString& SaveName, int32 UserIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("StreamingSaveGameFunctionLibrary", "DeleteSaveGameByName");

	Params::StreamingSaveGameFunctionLibrary_DeleteSaveGameByName Parms{};

	Parms.WorldContextObject = WorldContextObject;
	Parms.SaveName = std::move(SaveName);
	Parms.UserIndex = UserIndex;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameFunctionLibrary.GetExistingSaveGameNames
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// int32                                   UserIndex                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FString                           IgnoreSaveName                                         (ConstParm, Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    bSort                                                  (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// TArray<class FString>                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, NativeAccessSpecifierPublic)

TArray<class FString> UStreamingSaveGameFunctionLibrary::GetExistingSaveGameNames(int32 UserIndex, const class FString& IgnoreSaveName, bool bSort)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("StreamingSaveGameFunctionLibrary", "GetExistingSaveGameNames");

	Params::StreamingSaveGameFunctionLibrary_GetExistingSaveGameNames Parms{};

	Parms.UserIndex = UserIndex;
	Parms.IgnoreSaveName = std::move(IgnoreSaveName);
	Parms.bSort = bSort;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameFunctionLibrary.GetPlayTimeInSeconds
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// class UObject*                          WorldContextObject                                     (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// float                                   ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

float UStreamingSaveGameFunctionLibrary::GetPlayTimeInSeconds(class UObject* WorldContextObject)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("StreamingSaveGameFunctionLibrary", "GetPlayTimeInSeconds");

	Params::StreamingSaveGameFunctionLibrary_GetPlayTimeInSeconds Parms{};

	Parms.WorldContextObject = WorldContextObject;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameFunctionLibrary.IsValidSaveName
// (Final, Native, Static, Public, BlueprintCallable, BlueprintPure)
// Parameters:
// class FString                           SaveName                                               (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   UserIndex                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UStreamingSaveGameFunctionLibrary::IsValidSaveName(const class FString& SaveName, int32 UserIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("StreamingSaveGameFunctionLibrary", "IsValidSaveName");

	Params::StreamingSaveGameFunctionLibrary_IsValidSaveName Parms{};

	Parms.SaveName = std::move(SaveName);
	Parms.UserIndex = UserIndex;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameFunctionLibrary.LoadGameProfile
// (Final, Native, Static, Public, BlueprintCallable)
// Parameters:
// class UObject*                          WorldContextObject                                     (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FString                           SaveName                                               (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   UserIndex                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class UStreamingSaveGameProfile*        ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

class UStreamingSaveGameProfile* UStreamingSaveGameFunctionLibrary::LoadGameProfile(class UObject* WorldContextObject, const class FString& SaveName, int32 UserIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("StreamingSaveGameFunctionLibrary", "LoadGameProfile");

	Params::StreamingSaveGameFunctionLibrary_LoadGameProfile Parms{};

	Parms.WorldContextObject = WorldContextObject;
	Parms.SaveName = std::move(SaveName);
	Parms.UserIndex = UserIndex;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameProfile.SetDifficulty
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// int32                                   NewDifficulty                                          (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UStreamingSaveGameProfile::SetDifficulty(int32 NewDifficulty)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameProfile", "SetDifficulty");

	Params::StreamingSaveGameProfile_SetDifficulty Parms{};

	Parms.NewDifficulty = NewDifficulty;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function StreamingSaveGameSystem.StreamingSaveGameProfile.SetIconFromImage
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UImage*                           Image                                                  (Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UStreamingSaveGameProfile::SetIconFromImage(class UImage* Image)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameProfile", "SetIconFromImage");

	Params::StreamingSaveGameProfile_SetIconFromImage Parms{};

	Parms.Image = Image;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function StreamingSaveGameSystem.StreamingSaveGameProfile.SetIconFromRenderTarget
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class UTextureRenderTarget2D*           TextureRenderTarget                                    (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UStreamingSaveGameProfile::SetIconFromRenderTarget(class UTextureRenderTarget2D* TextureRenderTarget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameProfile", "SetIconFromRenderTarget");

	Params::StreamingSaveGameProfile_SetIconFromRenderTarget Parms{};

	Parms.TextureRenderTarget = TextureRenderTarget;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function StreamingSaveGameSystem.StreamingSaveGameProfile.SetSubLevelName
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class FName                             LevelName                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

void UStreamingSaveGameProfile::SetSubLevelName(class FName LevelName)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameProfile", "SetSubLevelName");

	Params::StreamingSaveGameProfile_SetSubLevelName Parms{};

	Parms.LevelName = LevelName;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;
}


// Function StreamingSaveGameSystem.StreamingSaveGameProfile.IsValidProfile
// (Final, Native, Public, BlueprintCallable, BlueprintPure, Const)
// Parameters:
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UStreamingSaveGameProfile::IsValidProfile() const
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameProfile", "IsValidProfile");

	Params::StreamingSaveGameProfile_IsValidProfile Parms{};

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameSession.AsyncSaveGame
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class FString                           InSaveName                                             (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FString                           InSaveCaption                                          (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   UserIndex                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UStreamingSaveGameSession::AsyncSaveGame(const class FString& InSaveName, const class FString& InSaveCaption, int32 UserIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameSession", "AsyncSaveGame");

	Params::StreamingSaveGameSession_AsyncSaveGame Parms{};

	Parms.InSaveName = std::move(InSaveName);
	Parms.InSaveCaption = std::move(InSaveCaption);
	Parms.UserIndex = UserIndex;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameSession.AsyncSaveGameWithEvent
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// class FString                           InSaveName                                             (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// class FString                           InSaveCaption                                          (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   UserIndex                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// TDelegate<void(const class FString& SaveName, int32 UserIndex, bool bSuccess)>SavedDelegate                                          (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UStreamingSaveGameSession::AsyncSaveGameWithEvent(const class FString& InSaveName, const class FString& InSaveCaption, int32 UserIndex, const TDelegate<void(const class FString& SaveName, int32 UserIndex, bool bSuccess)>& SavedDelegate)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameSession", "AsyncSaveGameWithEvent");

	Params::StreamingSaveGameSession_AsyncSaveGameWithEvent Parms{};

	Parms.InSaveName = std::move(InSaveName);
	Parms.InSaveCaption = std::move(InSaveCaption);
	Parms.UserIndex = UserIndex;
	Parms.SavedDelegate = SavedDelegate;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameSession.LoadGame
// (Final, Native, Public, BlueprintCallable)
// Parameters:
// class FString                           InSaveName                                             (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   UserIndex                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UStreamingSaveGameSession::LoadGame(const class FString& InSaveName, int32 UserIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameSession", "LoadGame");

	Params::StreamingSaveGameSession_LoadGame Parms{};

	Parms.InSaveName = std::move(InSaveName);
	Parms.UserIndex = UserIndex;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameSession.LoadGameWithEvent
// (Final, Native, Public, HasOutParams, BlueprintCallable)
// Parameters:
// class FString                           InSaveName                                             (Parm, ZeroConstructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// int32                                   UserIndex                                              (Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
// TDelegate<void()>                       PreMapMoveEvent                                        (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, NoDestructor, NativeAccessSpecifierPublic)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)

bool UStreamingSaveGameSession::LoadGameWithEvent(const class FString& InSaveName, int32 UserIndex, const TDelegate<void()>& PreMapMoveEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameSession", "LoadGameWithEvent");

	Params::StreamingSaveGameSession_LoadGameWithEvent Parms{};

	Parms.InSaveName = std::move(InSaveName);
	Parms.UserIndex = UserIndex;
	Parms.PreMapMoveEvent = PreMapMoveEvent;

	auto Flgs = Func->FunctionFlags;
	Func->FunctionFlags |= 0x400;

	UObject::ProcessEvent(Func, &Parms);

	Func->FunctionFlags = Flgs;

	return Parms.ReturnValue;
}


// Function StreamingSaveGameSystem.StreamingSaveGameSession.OnPostLoad
// (Event, Protected, BlueprintEvent)

void UStreamingSaveGameSession::OnPostLoad()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("StreamingSaveGameSession", "OnPostLoad");

	UObject::ProcessEvent(Func, nullptr);
}

}

