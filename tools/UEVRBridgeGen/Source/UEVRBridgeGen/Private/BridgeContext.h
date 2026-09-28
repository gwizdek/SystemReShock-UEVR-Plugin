#pragma once

#include "CoreMinimal.h"

#include "BridgeTypeMapper.h"

class UClass;
class UField;

// Everything the writers share for one generator run.
struct FBridgeContext
{
    // Classes, enums and structs this run generates wrappers for. Anything else is
    // expected to come from the Dumper-7 SDK.
    TSet<const UField*> Generated;

    // Generated classes, used to decide whether a wrapper may be marked final.
    TArray<const UClass*> Classes;

    // Relative include path from the output folder to the Dumper-7 SDK folder.
    FString SdkInclude;

    FBridgeTypeMapper Mapper;

    FBridgeContext()
        : Mapper(Generated)
    {
    }

    FBridgeContext(const FBridgeContext&) = delete;
    FBridgeContext& operator=(const FBridgeContext&) = delete;
};
