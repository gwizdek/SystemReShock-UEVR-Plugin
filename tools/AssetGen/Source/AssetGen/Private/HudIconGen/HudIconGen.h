#pragma once

#include "CoreMinimal.h"

struct FAssetGenContext;

// The HUD's unread media (email) icon: replacements for the game's envelope texture and its
// material, at the game's own asset paths (chunk 10), so the mod pak overrides them. The
// game's material is additive and writes no alpha, so UEVR's UI layer drops the icon; the
// replacement is translucent and writes alpha. The game's HUD widget draws it unchanged.
namespace HudIconGen
{
bool Generate(const FAssetGenContext& Context);
}
