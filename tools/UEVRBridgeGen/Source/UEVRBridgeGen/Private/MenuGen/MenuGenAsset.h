#pragma once

#include "CoreMinimal.h"

// Package and file helpers shared by every generated asset.
namespace MenuGenAsset
{
// "/Game/A/B" -> "B"
FString NameOf(const FString& PackagePath);

// "/Game/A/B" -> "/Game/A/B.B"
FString ObjectPath(const FString& PackagePath);

bool Exists(const FString& PackagePath);

UPackage* NewPackage(const FString& PackagePath);

// Marks the package with the chunk ids (empty means chunk 0), registers the asset and saves the .uasset.
bool Save(UObject* Asset, const TArray<int32>& ChunkIds);
} // namespace MenuGenAsset
