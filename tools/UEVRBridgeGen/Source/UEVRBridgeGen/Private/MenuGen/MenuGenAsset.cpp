#include "MenuGenAsset.h"

#include "AssetRegistryModule.h"
#include "BridgeGenLog.h"
#include "Misc/PackageName.h"
#include "UObject/Package.h"

namespace MenuGenAsset
{
FString NameOf(const FString& PackagePath)
{
    return FPackageName::GetShortName(PackagePath);
}

FString ObjectPath(const FString& PackagePath)
{
    return PackagePath + TEXT(".") + NameOf(PackagePath);
}

bool Exists(const FString& PackagePath)
{
    return FPackageName::DoesPackageExist(PackagePath);
}

// A package for a new asset. The file on disk, if any, is not loaded: with -Overwrite the old
// asset must stay out of memory, or creating the new one with the same name fails.
UPackage* NewPackage(const FString& PackagePath)
{
    return CreatePackage(*PackagePath);
}

bool Save(UObject* Asset, const TArray<int32>& ChunkIds)
{
    UPackage* Package = Asset->GetOutermost();
    Package->SetChunkIDs(ChunkIds);
    Package->MarkPackageDirty();
    FAssetRegistryModule::AssetCreated(Asset);

    const FString FileName = FPackageName::LongPackageNameToFilename(Package->GetName(), FPackageName::GetAssetPackageExtension());
    const bool bSaved = UPackage::SavePackage(Package, Asset, RF_Public | RF_Standalone, *FileName, GError, nullptr, false, true, SAVE_NoError);
    if (!bSaved)
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot save %s"), *FileName);
        return false;
    }
    UE_LOG(LogUEVRBridgeGen, Display, TEXT("Saved %s (chunks: %d)"), *FileName, ChunkIds.Num() > 0 ? ChunkIds[0] : 0);
    return true;
}
} // namespace MenuGenAsset
