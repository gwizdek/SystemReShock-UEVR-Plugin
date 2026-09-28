#include "BridgeEnumStructWriter.h"

#include "BridgeContext.h"
#include "BridgeHeaderBuilder.h"
#include "BridgeNaming.h"
#include "Engine/UserDefinedEnum.h"
#include "Engine/UserDefinedStruct.h"
#include "UObject/UnrealType.h"

FBridgeEnumStructWriter::FBridgeEnumStructWriter(const FBridgeContext& InContext)
    : Context(InContext)
{
}

FString FBridgeEnumStructWriter::WriteEnum(const UUserDefinedEnum* Enum) const
{
    FBridgeHeaderBuilder Header(Context, Enum);
    const FString Name = BridgeNaming::EnumCppName(Enum);

    FString Body;
    Body += FString::Printf(TEXT("// %s\n"), *BridgeNaming::ObjectSearchPath(Enum));
    Body += FString::Printf(TEXT("enum class %s : uint8\n{\n"), *Name);
    Body += EnumEntries(Enum);
    Body += TEXT("};\n");
    return Header.Build(BridgeNaming::ObjectSearchPath(Enum), Body);
}

FString FBridgeEnumStructWriter::EnumEntries(const UUserDefinedEnum* Enum) const
{
    const FString Name = BridgeNaming::EnumCppName(Enum);
    const int32 Count = Enum->NumEnums();
    const int32 MaxIndex = Enum->ContainsExistingMax() ? Count - 1 : INDEX_NONE;

    TSet<FString> Used;
    FString Display;
    FString Internal;
    for (int32 i = 0; i < Count; ++i)
    {
        const int64 Value = Enum->GetValueByIndex(i);
        if (i == MaxIndex)
        {
            Display += FString::Printf(TEXT("\t%s_MAX = %lld,\n"), *Name, Value);
            continue;
        }
        const FString Friendly = BridgeNaming::Sanitize(Enum->GetDisplayNameTextByIndex(i).ToString());
        const FString Raw = BridgeNaming::Sanitize(Enum->GetNameStringByIndex(i));
        if (!Used.Contains(Friendly))
        {
            Used.Add(Friendly);
            Display += FString::Printf(TEXT("\t%s = %lld,\n"), *Friendly, Value);
        }
        if (!Used.Contains(Raw))
        {
            Used.Add(Raw);
            Internal += FString::Printf(TEXT("\t%s = %lld,\n"), *Raw, Value);
        }
    }
    if (!Internal.IsEmpty())
    {
        Internal = TEXT("\n\t// Internal enumerator names, as Dumper-7 spells them.\n") + Internal;
    }
    return Display + Internal;
}

FString FBridgeEnumStructWriter::WriteStruct(const UUserDefinedStruct* Struct) const
{
    FBridgeHeaderBuilder Header(Context, Struct);
    const FString Name = BridgeNaming::StructCppName(Struct);

    FString Body;
    Body += FString::Printf(TEXT("// %s\n"), *BridgeNaming::ObjectSearchPath(Struct));
    Body += FString::Printf(TEXT("struct %s\n{\n"), *Name);
    Body += StructStatics(Struct);
    Body += TEXT("\tuint8_t* Data;\n\n");

    TArray<FString> WarmProps;
    for (TFieldIterator<FProperty> It(Struct); It; ++It)
    {
        TArray<FBridgeDep> Deps;
        const FBridgeType Type = Context.Mapper.Map(*It, Deps);
        if (!Type.bSupported)
        {
            Body += FString::Printf(TEXT("\t// skipped %s: %s\n"), *It->GetAuthoredName(), *Type.Reason);
            continue;
        }
        Header.AddDeps(Deps);
        // The authored name is what the editor shows. The real FName carries a GUID suffix.
        const FString AccessorName = BridgeNaming::Sanitize(It->GetAuthoredName());
        Body += FString::Printf(TEXT("\tstatic bridge::Prop& BridgeProp_%s() { static bridge::Prop Ref{ L\"%s\" }; return Ref; }\n"),
            *AccessorName, *It->GetName());
        Body += FString::Printf(TEXT("\t%s& %s() { return BridgeProp_%s().ref<%s>(Data, BridgeStruct()); }\n"),
            *Type.Cpp, *AccessorName, *AccessorName, *Type.Cpp);
        WarmProps.Add(TEXT("BridgeProp_") + AccessorName);
    }
    Body += StructWarmup(WarmProps);
    Body += TEXT("};\n");
    return Header.Build(BridgeNaming::ObjectSearchPath(Struct), Body);
}

FString FBridgeEnumStructWriter::StructStatics(const UUserDefinedStruct* Struct) const
{
    FString Out;
    Out += FString::Printf(TEXT("\tstatic constexpr const wchar_t* BridgeStructPath = L\"%s\";\n\n"),
        *BridgeNaming::ObjectSearchPath(Struct));
    Out += TEXT("\tstatic bridge::StructRef& BridgeStructRef()\n\t{\n");
    Out += TEXT("\t\tstatic bridge::StructRef Ref{ BridgeStructPath };\n\t\treturn Ref;\n\t}\n");
    Out += TEXT("\tstatic uevr::API::UScriptStruct* BridgeStruct() { return BridgeStructRef().require(); }\n");
    Out += TEXT("\tstatic int32_t StaticSize()\n\t{\n");
    Out += TEXT("\t\tstatic const int32_t Size = bridge::struct_size(BridgeStruct());\n\t\treturn Size;\n\t}\n\n");
    return Out;
}

FString FBridgeEnumStructWriter::StructWarmup(const TArray<FString>& WarmProps) const
{
    FString Out;
    Out += TEXT("\n\t// Resolves the struct, its size and every field above, so no first use pays the\n");
    Out += TEXT("\t// lookup mid-game. Returns false when the struct is not loaded yet or a name did\n");
    Out += TEXT("\t// not resolve; whatever is missing resolves on first use as usual.\n");
    Out += TEXT("\tstatic bool BridgeWarmup()\n\t{\n");
    Out += TEXT("\t\tuevr::API::UScriptStruct* Owner = BridgeStructRef().get();\n");
    Out += TEXT("\t\tif (Owner == nullptr) { bridge::warm_skipped(BridgeStructPath); return false; }\n");
    Out += TEXT("\t\tStaticSize();\n");
    if (WarmProps.Num() == 0)
    {
        Out += TEXT("\t\treturn true;\n\t}\n");
        return Out;
    }
    Out += TEXT("\t\treturn bridge::warm(Owner, {\n");
    for (const FString& Name : WarmProps)
    {
        Out += FString::Printf(TEXT("\t\t\t&%s(),\n"), *Name);
    }
    Out += TEXT("\t\t});\n\t}\n");
    return Out;
}
