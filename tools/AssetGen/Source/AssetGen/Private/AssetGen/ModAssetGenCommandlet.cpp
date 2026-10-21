#include "ModAssetGenCommandlet.h"

#include "AssetGenContext.h"
#include "AssetGenLog.h"
#include "AssetGenTint.h"
#include "AssetRegistryModule.h"
#include "ButtonAtlasGen/ButtonAtlasGen.h"
#include "CyberHudGen/CyberHudGen.h"
#include "HudIconGen/HudIconGen.h"
#include "MenuGen/MenuGen.h"
#include "Modules/ModuleManager.h"

namespace
{
struct FAssetGenerator
{
    const TCHAR* Name;
    TFunction<bool(const FAssetGenContext&)> Generate;
};

// In run order. A new generator adds one line here.
TArray<FAssetGenerator> Generators(const FString& ModRoot)
{
    return {
        { TEXT("Menu"), [ModRoot](const FAssetGenContext& Context) { return MenuGen::Generate(Context, ModRoot); } },
        { TEXT("HudIcon"), &HudIconGen::Generate },
        { TEXT("ButtonAtlas"), &ButtonAtlasGen::Generate },
        { TEXT("CyberHud"), &CyberHudGen::Generate },
    };
}

// An empty -Only runs every generator.
bool CheckOnly(const TArray<FAssetGenerator>& All, const TArray<FString>& Only)
{
    for (const FString& Name : Only)
    {
        if (!All.ContainsByPredicate([&](const FAssetGenerator& G) { return Name == G.Name; }))
        {
            UE_LOG(LogAssetGen, Error, TEXT("Unknown generator %s in -Only"), *Name);
            return false;
        }
    }
    return true;
}

bool RunGenerators(const TArray<FAssetGenerator>& All, const TArray<FString>& Only, const FAssetGenContext& Context)
{
    for (const FAssetGenerator& Generator : All)
    {
        if (Only.Num() > 0 && !Only.Contains(Generator.Name)) continue;
        UE_LOG(LogAssetGen, Display, TEXT("Generator %s"), Generator.Name);
        if (!Generator.Generate(Context))
        {
            UE_LOG(LogAssetGen, Error, TEXT("Generator %s failed."), Generator.Name);
            return false;
        }
    }
    return true;
}
} // namespace

UModAssetGenCommandlet::UModAssetGenCommandlet()
{
    IsClient = false;
    IsServer = false;
    IsEditor = true;
    LogToConsole = true;
}

int32 UModAssetGenCommandlet::Main(const FString& Params)
{
    FString ModRoot = TEXT("/Game/Mods/UI/Options");
    FParse::Value(*Params, TEXT("ModRoot="), ModRoot);
    FString OnlyList;
    FParse::Value(*Params, TEXT("Only="), OnlyList);
    TArray<FString> Only;
    OnlyList.ParseIntoArray(Only, TEXT(","));
    FAssetGenContext Context;
    Context.bOverwrite = FParse::Param(*Params, TEXT("Overwrite"));
    UE_LOG(LogAssetGen, Display, TEXT("Mod asset generator: only %s, mod root %s, overwrite %d"),
        OnlyList.IsEmpty() ? TEXT("(all)") : *OnlyList, *ModRoot, Context.bOverwrite);

    const TArray<FAssetGenerator> All = Generators(ModRoot);
    if (!CheckOnly(All, Only)) return 1;

    FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get().SearchAllAssets(true);
    Context.TintCollection = AssetGenTint::MakeCollection(Context.bOverwrite);
    if (Context.TintCollection == nullptr)
    {
        UE_LOG(LogAssetGen, Error, TEXT("Tint collection generation failed."));
        return 1;
    }
    if (!RunGenerators(All, Only, Context)) return 1;
    UE_LOG(LogAssetGen, Display, TEXT("Done."));
    return 0;
}
