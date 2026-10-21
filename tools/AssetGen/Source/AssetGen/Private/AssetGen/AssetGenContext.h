#pragma once

#include "CoreMinimal.h"

class UMaterialParameterCollection;

namespace AssetGen
{
// The chunk of the mod's Core pak. Assets in chunk 0 are stand-ins that are never shipped.
constexpr int32 ModChunk = 10;
} // namespace AssetGen

// What the ModAssetGen commandlet hands to every generator.
struct FAssetGenContext
{
    // Create an asset again although its package already exists.
    bool bOverwrite = false;
    // The dummy of the game's tint collection, made before any generator runs. Materials that
    // follow the UI colour the player picks read it. See AssetGenTint.h.
    UMaterialParameterCollection* TintCollection = nullptr;
};
