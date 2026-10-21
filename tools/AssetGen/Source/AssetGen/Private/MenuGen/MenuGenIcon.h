#pragma once

#include "CoreMinimal.h"

struct FMenuGenOptions;
struct FMenuGenStore;

// The VR category icon: the icon texture and the icon material (chunk 10). The material reads
// the tint collection dummy in Store.TintCollection. Stores the material in Store.IconMaterial
// for the page's Install function.
namespace MenuGenIcon
{
bool Generate(FMenuGenStore& Store, const FMenuGenOptions& Options);
}
