#pragma once

#include "CoreMinimal.h"

struct FMenuGenOptions;
struct FMenuGenStore;

// The cyberspace HUD's connection integrity widget: replacements for the four additive
// materials that UEVR's UI layer drops (the panel, the health bar, the SECURE and THREAT
// tags), at the game's own asset paths in chunk 10 so the Core pak overrides them. Their
// textures are copies of the game's in chunk 0, never shipped: the cooked materials refer to
// the paths, and in the game those resolve to the game's own textures.
// Also the flight reticle's texture, at the game's path in chunk 10, with only the top
// triangle of the ring left.
namespace MenuGenCyberHud
{
bool Generate(FMenuGenStore& Store, const FMenuGenOptions& Options);
}
