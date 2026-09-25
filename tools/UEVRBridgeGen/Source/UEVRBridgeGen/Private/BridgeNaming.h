#pragma once

#include "CoreMinimal.h"

class UClass;
class UEnum;
class UField;
class UObject;
class UScriptStruct;

// Produces the same identifiers Dumper-7 emits, so generated wrappers are a drop-in
// replacement for the dumped headers of the same Blueprints.
namespace BridgeNaming
{
    // Replaces characters that are not valid in a C++ identifier, guards a leading
    // digit, and suffixes C++ keywords with an underscore.
    FString Sanitize(const FString& Name);

    // "AActor", "A_BP_VRBody_C", "I_BI_VRWeapon_C", "UWidgetComponent".
    FString ClassCppName(const UClass* Class);

    // "FVector", "F_STRUCT_MontageMeta".
    FString StructCppName(const UScriptStruct* Struct);

    // "ECollisionChannel" stays. "_ENUM_VRHand" becomes "E_ENUM_VRHand".
    FString EnumCppName(const UEnum* Enum);

    // Last segment of the outermost package: "Engine", "_BP_VRBody".
    FString PackageShortName(const UField* Field);

    // "<Package>_classes.hpp" and "<Package>_structs.hpp", matching Dumper-7 file names.
    FString ClassesHeaderName(const UField* Field);
    FString StructsHeaderName(const UField* Field);

    // "BlueprintGeneratedClass /Game/VRMod/_BP_VRBody._BP_VRBody_C".
    // This is the string UEVR's find_uobject expects.
    FString ObjectSearchPath(const UObject* Object);
}
