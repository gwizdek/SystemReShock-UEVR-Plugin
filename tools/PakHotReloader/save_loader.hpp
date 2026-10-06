#pragma once

#include <string>

#include "config.hpp"

namespace pak_hot_reload {

// Starts a save-game load through the game's GameInstance, using the Blueprint
// functions QuickLoad, AutoLoad or ManualLoad. Must run on the game thread.
// Returns false, and logs the reason, when the GameInstance or the function is missing.
bool load_save(LoadMode mode, const std::wstring& save_name);

} // namespace pak_hot_reload
