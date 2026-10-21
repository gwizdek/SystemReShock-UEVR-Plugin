#include "MenuGen.h"

#include "AssetGen/AssetGenContext.h"
#include "AssetGenLog.h"
#include "MenuGenDummies.h"
#include "MenuGenIcon.h"
#include "MenuGenModWidgets.h"
#include "MenuGenStore.h"

bool MenuGen::Generate(const FAssetGenContext& Context, const FString& ModRoot)
{
    FMenuGenOptions Options;
    Options.ModRoot = ModRoot;
    Options.bOverwrite = Context.bOverwrite;
    FMenuGenStore Store;
    Store.TintCollection = Context.TintCollection;

    if (!MenuGenDummies::Generate(Store, Options))
    {
        UE_LOG(LogAssetGen, Error, TEXT("Dummy generation failed."));
        return false;
    }
    if (!MenuGenIcon::Generate(Store, Options))
    {
        UE_LOG(LogAssetGen, Error, TEXT("Icon generation failed."));
        return false;
    }
    if (!MenuGenModWidgets::Generate(Store, Options))
    {
        UE_LOG(LogAssetGen, Error, TEXT("Mod widget generation failed."));
        return false;
    }
    UE_LOG(LogAssetGen, Display, TEXT("VR options menu: %d classes."), Store.Classes.Num());
    return true;
}
