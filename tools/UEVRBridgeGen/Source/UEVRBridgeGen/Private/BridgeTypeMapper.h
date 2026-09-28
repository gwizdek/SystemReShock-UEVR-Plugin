#pragma once

#include "CoreMinimal.h"

class FProperty;
class UClass;
class UEnum;
class UField;
class UFunction;
class UScriptStruct;

// A type another header must provide. bComplete means the full definition is needed
// (by-value structs, enums, parent classes); otherwise a forward declaration is enough.
struct FBridgeDep
{
    const UField* Field = nullptr;
    bool bComplete = false;
};

// The C++ spelling of one reflected property type, plus what the writers need to know
// to read or pass a value of that type.
struct FBridgeType
{
    FString Cpp;
    bool bSupported = true;
    FString Reason;

    // Value of a User Defined Struct: accessed through a generated view type.
    bool bIsUserStruct = false;
    // TArray of a User Defined Struct: accessed through bridge::StructArray<View>.
    bool bIsUserStructArray = false;
    // Needs FBoolProperty accessors instead of a plain reference.
    bool bIsBool = false;
    // Passed by const reference in a function signature.
    bool bPassByRef = false;
};

// Maps FProperty subclasses to Dumper-7 compatible C++ type strings.
class FBridgeTypeMapper
{
public:
    explicit FBridgeTypeMapper(const TSet<const UField*>& InGenerated);

    FBridgeType Map(const FProperty* Property, TArray<FBridgeDep>& Deps) const;

    // "class UITEM_WeaponBase_C* Weapon, float Delta" for a delegate signature.
    FString SignatureParams(const UFunction* Signature, TArray<FBridgeDep>& Deps) const;

    static bool IsUserStruct(const UScriptStruct* Struct);

private:
    FBridgeType MapEnum(const UEnum* Enum, TArray<FBridgeDep>& Deps) const;
    FBridgeType MapStruct(const UScriptStruct* Struct, TArray<FBridgeDep>& Deps) const;
    FBridgeType MapClassPointer(const UClass* Class, TArray<FBridgeDep>& Deps) const;
    FBridgeType MapClassTemplate(const TCHAR* Template, const UClass* Class, TArray<FBridgeDep>& Deps) const;
    FBridgeType MapArray(const FProperty* Inner, TArray<FBridgeDep>& Deps) const;
    FBridgeType MapContainer(const TCHAR* Template, const TArray<const FProperty*>& Inners, TArray<FBridgeDep>& Deps) const;
    FBridgeType MapDelegate(const TCHAR* Template, const UFunction* Signature, TArray<FBridgeDep>& Deps) const;
    FBridgeType MapNumeric(const FProperty* Property) const;

    static FBridgeType Simple(const FString& Cpp, bool bPassByRef = false);
    static FBridgeType Unsupported(const FString& Reason);

    const TSet<const UField*>& Generated;
};
