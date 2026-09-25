#pragma once

#include "CoreMinimal.h"

#include "BridgeFunctionWriter.h"

class FBridgeHeaderBuilder;
class FProperty;
class UClass;
class UFunction;
struct FBridgeContext;
struct FBridgeType;

// Emits "<Package>_classes.hpp" for one Blueprint generated class: a data-less class
// deriving from the Dumper-7 parent, with one accessor per Blueprint variable and one
// inline method per Blueprint function.
class FBridgeClassWriter
{
public:
    explicit FBridgeClassWriter(const FBridgeContext& InContext);

    FString Write(const UClass* Class) const;

private:
    FString ClassHead(const UClass* Class, FBridgeHeaderBuilder& Header) const;
    FString StaticMembers(const UClass* Class) const;
    FString Properties(const UClass* Class, FBridgeHeaderBuilder& Header, const TSet<FString>& Reserved) const;
    FString PropertyAccessor(const FProperty* Property, const FBridgeType& Type, const FString& Name) const;
    FString Functions(const UClass* Class, FBridgeHeaderBuilder& Header) const;

    bool HasGeneratedSubclass(const UClass* Class) const;
    static bool SkipProperty(const FProperty* Property);
    static bool SkipFunction(const UFunction* Function);
    static EBridgeCallMode CallModeFor(const UClass* Class, const UFunction* Function);
    static TSet<FString> ReservedNames(const UClass* Class);

    const FBridgeContext& Context;
};
