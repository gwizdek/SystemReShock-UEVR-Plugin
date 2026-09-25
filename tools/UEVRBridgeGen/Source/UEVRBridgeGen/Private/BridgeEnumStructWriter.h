#pragma once

#include "CoreMinimal.h"

class UUserDefinedEnum;
class UUserDefinedStruct;
struct FBridgeContext;

// Emits "<Package>_structs.hpp" for User Defined Enums and User Defined Structs.
// Enums become a plain enum class. Structs become a view over raw memory with
// name-resolved accessors, because their layout is not fixed.
class FBridgeEnumStructWriter
{
public:
    explicit FBridgeEnumStructWriter(const FBridgeContext& InContext);

    FString WriteEnum(const UUserDefinedEnum* Enum) const;
    FString WriteStruct(const UUserDefinedStruct* Struct) const;

private:
    FString EnumEntries(const UUserDefinedEnum* Enum) const;
    FString StructStatics(const UUserDefinedStruct* Struct) const;

    const FBridgeContext& Context;
};
