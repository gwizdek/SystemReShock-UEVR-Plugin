#pragma once

#include "CoreMinimal.h"

struct FAssetGenContext;

// The assets of the VR options page: dummy copies of the game's menu classes, the VR category
// icon and the mod's own page, list and rows. See documentation/vr-options-menu.md.
namespace MenuGen
{
// ModRoot is the content path that receives the mod's widgets, for example /Game/Mods/UI/Options.
bool Generate(const FAssetGenContext& Context, const FString& ModRoot);
}
