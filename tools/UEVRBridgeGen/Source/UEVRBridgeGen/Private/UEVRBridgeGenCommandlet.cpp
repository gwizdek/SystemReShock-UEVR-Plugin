#include "UEVRBridgeGenCommandlet.h"

#include "AssetRegistryModule.h"
#include "BridgeClassWriter.h"
#include "BridgeContext.h"
#include "BridgeEnumStructWriter.h"
#include "BridgeGenLog.h"
#include "BridgeNaming.h"
#include "Engine/Blueprint.h"
#include "Engine/UserDefinedEnum.h"
#include "Engine/UserDefinedStruct.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"

UUEVRBridgeGenCommandlet::UUEVRBridgeGenCommandlet()
{
    IsClient = false;
    IsServer = false;
    IsEditor = true;
    LogToConsole = true;
}

int32 UUEVRBridgeGenCommandlet::Main(const FString& Params)
{
    FBridgeGenOptions Options;
    if (!ParseOptions(Params, Options))
    {
        return 1;
    }

    FBridgeTargets Targets;
    CollectTargets(Options, Targets);
    if (Targets.IsEmpty())
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("No Blueprint, enum or struct assets matched. Check -Paths and -Prefix."));
        return 1;
    }

    FBridgeContext Context;
    FillContext(Targets, Options, Context);

    const TArray<FString> Headers = WriteHeaders(Context, Targets, Options);
    if (!CopyRuntimeHeader(Options))
    {
        return 1;
    }
    WriteAggregate(Options, Headers);

    UE_LOG(LogUEVRBridgeGen, Display, TEXT("Generated %d classes, %d enums, %d structs into %s"),
        Targets.Classes.Num(), Targets.Enums.Num(), Targets.Structs.Num(), *Options.OutDir);
    return 0;
}

bool UUEVRBridgeGenCommandlet::ParseOptions(const FString& Params, FBridgeGenOptions& Options)
{
    if (!FParse::Value(*Params, TEXT("OutDir="), Options.OutDir) || Options.OutDir.IsEmpty())
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("-OutDir=<folder> is required."));
        return false;
    }
    Options.OutDir = FPaths::ConvertRelativePathToFull(Options.OutDir);

    FString PathList = TEXT("/Game");
    FParse::Value(*Params, TEXT("Paths="), PathList);
    PathList.ParseIntoArray(Options.Paths, TEXT(","), true);

    FParse::Value(*Params, TEXT("Prefix="), Options.Prefix);

    Options.SdkInclude = TEXT("../SDK");
    FParse::Value(*Params, TEXT("SdkInclude="), Options.SdkInclude);

    Options.UevrInclude = TEXT("../uevr/API.hpp");
    FParse::Value(*Params, TEXT("UevrInclude="), Options.UevrInclude);

    Options.Aggregate = TEXT("BridgeSDK.hpp");
    FParse::Value(*Params, TEXT("Aggregate="), Options.Aggregate);
    return true;
}

void UUEVRBridgeGenCommandlet::CollectTargets(const FBridgeGenOptions& Options, FBridgeTargets& Targets)
{
    IAssetRegistry& Registry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();
    Registry.SearchAllAssets(true);

    FARFilter Filter;
    for (const FString& Path : Options.Paths)
    {
        Filter.PackagePaths.Add(*Path);
    }
    Filter.bRecursivePaths = true;
    Filter.bRecursiveClasses = true;
    Filter.ClassNames.Add(UBlueprint::StaticClass()->GetFName());
    Filter.ClassNames.Add(UUserDefinedEnum::StaticClass()->GetFName());
    Filter.ClassNames.Add(UUserDefinedStruct::StaticClass()->GetFName());

    TArray<FAssetData> Found;
    Registry.GetAssets(Filter, Found);
    for (const FAssetData& Data : Found)
    {
        if (!Options.Prefix.IsEmpty() && !Data.AssetName.ToString().StartsWith(Options.Prefix))
        {
            continue;
        }
        AddTarget(Data.GetAsset(), Targets);
    }
}

void UUEVRBridgeGenCommandlet::AddTarget(UObject* Asset, FBridgeTargets& Targets)
{
    if (UBlueprint* Blueprint = Cast<UBlueprint>(Asset))
    {
        if (Blueprint->GeneratedClass == nullptr)
        {
            UE_LOG(LogUEVRBridgeGen, Warning, TEXT("%s has no generated class, skipping."), *Blueprint->GetPathName());
            return;
        }
        Targets.Classes.Add(Blueprint->GeneratedClass);
    }
    else if (UUserDefinedEnum* Enum = Cast<UUserDefinedEnum>(Asset))
    {
        Targets.Enums.Add(Enum);
    }
    else if (UUserDefinedStruct* Struct = Cast<UUserDefinedStruct>(Asset))
    {
        Targets.Structs.Add(Struct);
    }
}

void UUEVRBridgeGenCommandlet::FillContext(const FBridgeTargets& Targets, const FBridgeGenOptions& Options, FBridgeContext& Context)
{
    Context.SdkInclude = Options.SdkInclude;
    for (UClass* Class : Targets.Classes)
    {
        Context.Generated.Add(Class);
        Context.Classes.Add(Class);
    }
    for (UUserDefinedEnum* Enum : Targets.Enums)
    {
        Context.Generated.Add(Enum);
    }
    for (UUserDefinedStruct* Struct : Targets.Structs)
    {
        Context.Generated.Add(Struct);
    }
}

TArray<FString> UUEVRBridgeGenCommandlet::WriteHeaders(const FBridgeContext& Context, const FBridgeTargets& Targets, const FBridgeGenOptions& Options)
{
    const FBridgeClassWriter ClassWriter(Context);
    const FBridgeEnumStructWriter EnumStructWriter(Context);
    TArray<FString> Headers;

    for (UClass* Class : Targets.Classes)
    {
        const FString Name = BridgeNaming::ClassesHeaderName(Class);
        WriteIfChanged(Options.OutDir / Name, ClassWriter.Write(Class));
        Headers.Add(Name);
    }
    for (UUserDefinedEnum* Enum : Targets.Enums)
    {
        const FString Name = BridgeNaming::StructsHeaderName(Enum);
        WriteIfChanged(Options.OutDir / Name, EnumStructWriter.WriteEnum(Enum));
        Headers.Add(Name);
    }
    for (UUserDefinedStruct* Struct : Targets.Structs)
    {
        const FString Name = BridgeNaming::StructsHeaderName(Struct);
        WriteIfChanged(Options.OutDir / Name, EnumStructWriter.WriteStruct(Struct));
        Headers.Add(Name);
    }
    return Headers;
}

bool UUEVRBridgeGenCommandlet::CopyRuntimeHeader(const FBridgeGenOptions& Options)
{
    const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("UEVRBridgeGen"));
    if (!Plugin.IsValid())
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Plugin UEVRBridgeGen not found by the plugin manager."));
        return false;
    }
    const FString Source = Plugin->GetBaseDir() / TEXT("Resources/Bridge.hpp");
    FString Content;
    if (!FFileHelper::LoadFileToString(Content, *Source))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot read %s"), *Source);
        return false;
    }
    Content.ReplaceInline(TEXT("@UEVR_API_INCLUDE@"), *Options.UevrInclude);
    WriteIfChanged(Options.OutDir / TEXT("Bridge.hpp"), Content);
    return true;
}

void UUEVRBridgeGenCommandlet::WriteAggregate(const FBridgeGenOptions& Options, TArray<FString> Headers)
{
    Headers.Sort();
    FString Content = TEXT("#pragma once\n\n// Generated by UEVRBridgeGen. Includes every generated wrapper header.\n\n");
    for (const FString& Header : Headers)
    {
        Content += FString::Printf(TEXT("#include \"%s\"\n"), *Header);
    }
    WriteIfChanged(Options.OutDir / Options.Aggregate, Content);
}

bool UUEVRBridgeGenCommandlet::WriteIfChanged(const FString& Path, const FString& Content)
{
    FString Existing;
    if (FFileHelper::LoadFileToString(Existing, *Path) && Existing == Content)
    {
        return false;
    }
    if (!FFileHelper::SaveStringToFile(Content, *Path, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot write %s"), *Path);
        return false;
    }
    UE_LOG(LogUEVRBridgeGen, Display, TEXT("Wrote %s"), *Path);
    return true;
}
