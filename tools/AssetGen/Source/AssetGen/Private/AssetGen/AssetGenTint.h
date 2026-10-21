#pragma once

#include "CoreMinimal.h"

class UMaterialParameterCollection;

// A dummy of the game's tint parameter collection, MPC_UserTintParameters, at the game's path
// in chunk 0, never shipped. Materials that read it compile against it; in the game the
// reference resolves to the real collection, so they show the UI colour the player picks.
namespace AssetGenTint
{
UMaterialParameterCollection* MakeCollection(bool bOverwrite);
}
