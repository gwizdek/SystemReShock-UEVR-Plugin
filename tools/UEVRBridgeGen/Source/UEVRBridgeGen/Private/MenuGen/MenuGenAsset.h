#pragma once

#include "BridgeGenLog.h"
#include "CoreMinimal.h"
#include "UObject/UObjectGlobals.h"

// Package and file helpers shared by every generated asset.
namespace MenuGenAsset
{
// "/Game/A/B" -> "B"
FString NameOf(const FString& PackagePath);

// "/Game/A/B" -> "/Game/A/B.B"
FString ObjectPath(const FString& PackagePath);

// Loads an asset that an earlier run made, when it is kept instead of created again.
template <class AssetType>
AssetType* LoadExisting(const FString& PackagePath)
{
    AssetType* Asset = LoadObject<AssetType>(nullptr, *ObjectPath(PackagePath));
    if (Asset == nullptr)
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot load %s"), *PackagePath);
        return nullptr;
    }
    UE_LOG(LogUEVRBridgeGen, Display, TEXT("Kept existing %s"), *PackagePath);
    return Asset;
}

bool Exists(const FString& PackagePath);

UPackage* NewPackage(const FString& PackagePath);

// With -Overwrite an old version of an asset may already be in memory. Moves it out of the
// package under a unique name, so a new asset can take the name.
void Evict(UPackage* Package, const FString& Name);

// Marks the package with the chunk ids (empty means chunk 0), registers the asset and saves the .uasset.
bool Save(UObject* Asset, const TArray<int32>& ChunkIds);
} // namespace MenuGenAsset
