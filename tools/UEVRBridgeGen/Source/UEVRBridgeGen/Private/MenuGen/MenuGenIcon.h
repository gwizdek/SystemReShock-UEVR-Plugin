#pragma once

#include "CoreMinimal.h"

struct FMenuGenOptions;
struct FMenuGenStore;

// The VR category icon: a dummy of the game's tint parameter collection (chunk 0, never
// shipped), the icon texture and the icon material (chunk 10). Stores the material in
// Store.IconMaterial for the page's Install function.
namespace MenuGenIcon
{
bool Generate(FMenuGenStore& Store, const FMenuGenOptions& Options);
}
