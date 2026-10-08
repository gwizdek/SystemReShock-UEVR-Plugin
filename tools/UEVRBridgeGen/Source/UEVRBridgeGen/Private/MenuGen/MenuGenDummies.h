#pragma once

#include "CoreMinimal.h"

struct FMenuGenOptions;
struct FMenuGenStore;

// Creates the dummy copies of the game's menu classes at the game's own paths. They hold only
// the members the mod's widgets use and are cooked into chunk 0, which is never shipped.
namespace MenuGenDummies
{
bool Generate(FMenuGenStore& Store, const FMenuGenOptions& Options);
}
