#pragma once

#include "CoreMinimal.h"

struct FMenuGenOptions;
struct FMenuGenStore;

// Creates the mod's own widgets: the VR options page, its list and its rows. Cooked into chunk 10.
namespace MenuGenModWidgets
{
bool Generate(FMenuGenStore& Store, const FMenuGenOptions& Options);
}
