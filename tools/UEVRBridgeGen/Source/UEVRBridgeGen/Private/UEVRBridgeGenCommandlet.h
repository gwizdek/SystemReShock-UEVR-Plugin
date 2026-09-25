#pragma once

#include "Commandlets/Commandlet.h"
#include "CoreMinimal.h"

#include "UEVRBridgeGenCommandlet.generated.h"

class UUserDefinedEnum;
class UUserDefinedStruct;
struct FBridgeContext;

// Command line options. See README.md for the full list.
struct FBridgeGenOptions
{
    FString OutDir;
    TArray<FString> Paths;
    FString Prefix;
    FString SdkInclude;
    FString UevrInclude;
    FString Aggregate;
};

// Assets found by the scan, already loaded.
struct FBridgeTargets
{
    TArray<UClass*> Classes;
    TArray<UUserDefinedEnum*> Enums;
    TArray<UUserDefinedStruct*> Structs;

    bool IsEmpty() const { return Classes.Num() + Enums.Num() + Structs.Num() == 0; }
};

// Run with:
//   UE4Editor-Cmd.exe <Project>.uproject -run=UEVRBridgeGen -OutDir=<folder> [-Paths=/Game/VRMod] [-Prefix=_]
UCLASS()
class UUEVRBridgeGenCommandlet : public UCommandlet
{
    GENERATED_BODY()

public:
    UUEVRBridgeGenCommandlet();

    virtual int32 Main(const FString& Params) override;

private:
    static bool ParseOptions(const FString& Params, FBridgeGenOptions& Options);
    static void CollectTargets(const FBridgeGenOptions& Options, FBridgeTargets& Targets);
    static void AddTarget(UObject* Asset, FBridgeTargets& Targets);
    static void FillContext(const FBridgeTargets& Targets, const FBridgeGenOptions& Options, FBridgeContext& Context);
    // WarmupTypes receives the C++ name of every generated class and struct, for BridgeWarmupAll.
    static TArray<FString> WriteHeaders(const FBridgeContext& Context, const FBridgeTargets& Targets, const FBridgeGenOptions& Options, TArray<FString>& WarmupTypes);
    static bool CopyRuntimeHeader(const FBridgeGenOptions& Options);
    static void WriteAggregate(const FBridgeGenOptions& Options, TArray<FString> Headers, TArray<FString> WarmupTypes);
    static bool WriteIfChanged(const FString& Path, const FString& Content);
};
