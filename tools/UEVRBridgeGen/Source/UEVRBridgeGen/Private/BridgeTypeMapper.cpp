#include "BridgeTypeMapper.h"

#include "BridgeNaming.h"
#include "Engine/UserDefinedStruct.h"
#include "UObject/Class.h"
#include "UObject/UnrealType.h"

FBridgeTypeMapper::FBridgeTypeMapper(const TSet<const UField*>& InGenerated)
    : Generated(InGenerated)
{
}

bool FBridgeTypeMapper::IsUserStruct(const UScriptStruct* Struct)
{
    return Struct != nullptr && Struct->IsA<UUserDefinedStruct>();
}

FBridgeType FBridgeTypeMapper::Simple(const FString& Cpp, bool bPassByRef)
{
    FBridgeType Type;
    Type.Cpp = Cpp;
    Type.bPassByRef = bPassByRef;
    return Type;
}

FBridgeType FBridgeTypeMapper::Unsupported(const FString& Reason)
{
    FBridgeType Type;
    Type.bSupported = false;
    Type.Reason = Reason;
    return Type;
}

FBridgeType FBridgeTypeMapper::Map(const FProperty* Property, TArray<FBridgeDep>& Deps) const
{
    if (Property->IsA<FBoolProperty>())
    {
        FBridgeType Type = Simple(TEXT("bool"));
        Type.bIsBool = true;
        return Type;
    }
    if (const FEnumProperty* Enum = CastField<FEnumProperty>(Property))
    {
        return MapEnum(Enum->GetEnum(), Deps);
    }
    if (const FByteProperty* Byte = CastField<FByteProperty>(Property))
    {
        return Byte->Enum ? MapEnum(Byte->Enum, Deps) : Simple(TEXT("uint8"));
    }
    if (const FStructProperty* Struct = CastField<FStructProperty>(Property))
    {
        return MapStruct(Struct->Struct, Deps);
    }
    if (const FClassProperty* Class = CastField<FClassProperty>(Property))
    {
        return MapClassTemplate(TEXT("TSubclassOf"), Class->MetaClass, Deps);
    }
    if (const FObjectProperty* Object = CastField<FObjectProperty>(Property))
    {
        return MapClassPointer(Object->PropertyClass, Deps);
    }
    if (const FSoftClassProperty* SoftClass = CastField<FSoftClassProperty>(Property))
    {
        return MapClassTemplate(TEXT("TSoftClassPtr"), SoftClass->MetaClass, Deps);
    }
    if (const FSoftObjectProperty* SoftObject = CastField<FSoftObjectProperty>(Property))
    {
        return MapClassTemplate(TEXT("TSoftObjectPtr"), SoftObject->PropertyClass, Deps);
    }
    if (const FWeakObjectProperty* Weak = CastField<FWeakObjectProperty>(Property))
    {
        return MapClassTemplate(TEXT("TWeakObjectPtr"), Weak->PropertyClass, Deps);
    }
    if (const FLazyObjectProperty* Lazy = CastField<FLazyObjectProperty>(Property))
    {
        return MapClassTemplate(TEXT("TLazyObjectPtr"), Lazy->PropertyClass, Deps);
    }
    if (const FInterfaceProperty* Interface = CastField<FInterfaceProperty>(Property))
    {
        return MapClassTemplate(TEXT("TScriptInterface"), Interface->InterfaceClass, Deps);
    }
    if (const FArrayProperty* Array = CastField<FArrayProperty>(Property))
    {
        return MapArray(Array->Inner, Deps);
    }
    if (const FMapProperty* Map = CastField<FMapProperty>(Property))
    {
        return MapContainer(TEXT("TMap"), { Map->KeyProp, Map->ValueProp }, Deps);
    }
    if (const FSetProperty* Set = CastField<FSetProperty>(Property))
    {
        return MapContainer(TEXT("TSet"), { Set->ElementProp }, Deps);
    }
    if (const FDelegateProperty* Delegate = CastField<FDelegateProperty>(Property))
    {
        return MapDelegate(TEXT("TDelegate"), Delegate->SignatureFunction, Deps);
    }
    if (const FMulticastInlineDelegateProperty* Multicast = CastField<FMulticastInlineDelegateProperty>(Property))
    {
        return MapDelegate(TEXT("TMulticastInlineDelegate"), Multicast->SignatureFunction, Deps);
    }
    if (Property->IsA<FNameProperty>())
    {
        return Simple(TEXT("class FName"));
    }
    if (Property->IsA<FStrProperty>())
    {
        return Simple(TEXT("class FString"), true);
    }
    if (Property->IsA<FTextProperty>())
    {
        return Simple(TEXT("class FText"), true);
    }
    return MapNumeric(Property);
}

FBridgeType FBridgeTypeMapper::MapNumeric(const FProperty* Property) const
{
    if (Property->IsA<FInt8Property>()) return Simple(TEXT("int8"));
    if (Property->IsA<FInt16Property>()) return Simple(TEXT("int16"));
    if (Property->IsA<FIntProperty>()) return Simple(TEXT("int32"));
    if (Property->IsA<FInt64Property>()) return Simple(TEXT("int64"));
    if (Property->IsA<FUInt16Property>()) return Simple(TEXT("uint16"));
    if (Property->IsA<FUInt32Property>()) return Simple(TEXT("uint32"));
    if (Property->IsA<FUInt64Property>()) return Simple(TEXT("uint64"));
    if (Property->IsA<FFloatProperty>()) return Simple(TEXT("float"));
    if (Property->IsA<FDoubleProperty>()) return Simple(TEXT("double"));
    return Unsupported(Property->GetClass()->GetName());
}

FBridgeType FBridgeTypeMapper::MapEnum(const UEnum* Enum, TArray<FBridgeDep>& Deps) const
{
    if (Enum == nullptr)
    {
        return Unsupported(TEXT("enum property without enum"));
    }
    Deps.Add({ Enum, true });
    return Simple(BridgeNaming::EnumCppName(Enum));
}

FBridgeType FBridgeTypeMapper::MapStruct(const UScriptStruct* Struct, TArray<FBridgeDep>& Deps) const
{
    if (Struct == nullptr)
    {
        return Unsupported(TEXT("struct property without struct"));
    }
    Deps.Add({ Struct, true });
    if (IsUserStruct(Struct) && !Generated.Contains(Struct))
    {
        return Unsupported(TEXT("User Defined Struct outside the generated set: ") + Struct->GetPathName());
    }
    FBridgeType Type = Simple(IsUserStruct(Struct) ? BridgeNaming::StructCppName(Struct)
                                                   : TEXT("struct ") + BridgeNaming::StructCppName(Struct), true);
    Type.bIsUserStruct = IsUserStruct(Struct);
    return Type;
}

FBridgeType FBridgeTypeMapper::MapClassPointer(const UClass* Class, TArray<FBridgeDep>& Deps) const
{
    if (Class == nullptr)
    {
        return Unsupported(TEXT("object property without class"));
    }
    Deps.Add({ Class, false });
    return Simple(TEXT("class ") + BridgeNaming::ClassCppName(Class) + TEXT("*"));
}

FBridgeType FBridgeTypeMapper::MapClassTemplate(const TCHAR* Template, const UClass* Class, TArray<FBridgeDep>& Deps) const
{
    if (Class == nullptr)
    {
        return Unsupported(FString(Template) + TEXT(" without class"));
    }
    Deps.Add({ Class, false });
    return Simple(FString::Printf(TEXT("%s<class %s>"), Template, *BridgeNaming::ClassCppName(Class)));
}

FBridgeType FBridgeTypeMapper::MapArray(const FProperty* Inner, TArray<FBridgeDep>& Deps) const
{
    const FBridgeType InnerType = Map(Inner, Deps);
    if (!InnerType.bSupported)
    {
        return InnerType;
    }
    FBridgeType Type = Simple(InnerType.bIsUserStruct ? TEXT("bridge::StructArray<") + InnerType.Cpp + TEXT(">")
                                                      : TEXT("TArray<") + InnerType.Cpp + TEXT(">"), true);
    Type.bIsUserStructArray = InnerType.bIsUserStruct;
    return Type;
}

FBridgeType FBridgeTypeMapper::MapContainer(const TCHAR* Template, const TArray<const FProperty*>& Inners, TArray<FBridgeDep>& Deps) const
{
    TArray<FString> Parts;
    for (const FProperty* Inner : Inners)
    {
        const FBridgeType InnerType = Map(Inner, Deps);
        if (!InnerType.bSupported)
        {
            return InnerType;
        }
        if (InnerType.bIsUserStruct)
        {
            return Unsupported(FString(Template) + TEXT(" of a User Defined Struct"));
        }
        Parts.Add(InnerType.Cpp);
    }
    return Simple(FString::Printf(TEXT("%s<%s>"), Template, *FString::Join(Parts, TEXT(", "))), true);
}

FBridgeType FBridgeTypeMapper::MapDelegate(const TCHAR* Template, const UFunction* Signature, TArray<FBridgeDep>& Deps) const
{
    if (Signature == nullptr)
    {
        return Unsupported(FString(Template) + TEXT(" without signature"));
    }
    return Simple(FString::Printf(TEXT("%s<void(%s)>"), Template, *SignatureParams(Signature, Deps)), true);
}

FString FBridgeTypeMapper::SignatureParams(const UFunction* Signature, TArray<FBridgeDep>& Deps) const
{
    TArray<FString> Parts;
    for (TFieldIterator<FProperty> It(Signature); It; ++It)
    {
        if (!It->HasAnyPropertyFlags(CPF_Parm) || It->HasAnyPropertyFlags(CPF_ReturnParm))
        {
            continue;
        }
        const FBridgeType Type = Map(*It, Deps);
        const FString Cpp = Type.bSupported ? Type.Cpp : TEXT("void*");
        Parts.Add(Cpp + TEXT(" ") + BridgeNaming::Sanitize(It->GetName()));
    }
    return FString::Join(Parts, TEXT(", "));
}
