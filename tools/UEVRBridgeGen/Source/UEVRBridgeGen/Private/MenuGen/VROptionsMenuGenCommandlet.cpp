#include "VROptionsMenuGenCommandlet.h"

#include "AssetRegistryModule.h"
#include "BridgeGenLog.h"
#include "MenuGenDummies.h"
#include "MenuGenIcon.h"
#include "MenuGenModWidgets.h"
#include "MenuGenStore.h"
#include "Modules/ModuleManager.h"

UVROptionsMenuGenCommandlet::UVROptionsMenuGenCommandlet()
{
    IsClient = false;
    IsServer = false;
    IsEditor = true;
    LogToConsole = true;
}

int32 UVROptionsMenuGenCommandlet::Main(const FString& Params)
{
    FMenuGenOptions Options;
    Options.ModRoot = TEXT("/Game/Mods/UI/Options");
    FParse::Value(*Params, TEXT("ModRoot="), Options.ModRoot);
    Options.bOverwrite = FParse::Param(*Params, TEXT("Overwrite"));
    UE_LOG(LogUEVRBridgeGen, Display, TEXT("VR options menu generator: mod root %s, overwrite %d"), *Options.ModRoot, Options.bOverwrite);

    FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get().SearchAllAssets(true);

    FMenuGenStore Store;
    if (!MenuGenDummies::Generate(Store, Options))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Dummy generation failed."));
        return 1;
    }
    if (!MenuGenIcon::Generate(Store, Options))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Icon generation failed."));
        return 1;
    }
    if (!MenuGenModWidgets::Generate(Store, Options))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Mod widget generation failed."));
        return 1;
    }
    UE_LOG(LogUEVRBridgeGen, Display, TEXT("Done: %d classes."), Store.Classes.Num());
    return 0;
}
