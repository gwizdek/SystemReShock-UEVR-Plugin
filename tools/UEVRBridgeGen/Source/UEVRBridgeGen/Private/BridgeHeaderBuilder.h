#pragma once

#include "CoreMinimal.h"

#include "BridgeTypeMapper.h"

struct FBridgeContext;
class UField;

// Collects the includes and forward declarations one generated header needs and
// wraps the body in the SDK namespace.
class FBridgeHeaderBuilder
{
public:
    FBridgeHeaderBuilder(const FBridgeContext& InContext, const UField* InSelf);

    void AddDep(const FBridgeDep& Dep);
    void AddDeps(const TArray<FBridgeDep>& Deps);

    // Banner is one line describing the source asset. Body is the class, enum or
    // struct definition, already indented for the namespace.
    FString Build(const FString& Banner, const FString& Body) const;

private:
    FString IncludeFor(const UField* Field) const;

    const FBridgeContext& Context;
    const UField* Self;
    TSet<FString> Includes;
    TSet<FString> ForwardDecls;
};
