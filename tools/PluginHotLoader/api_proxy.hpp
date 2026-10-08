#pragma once

#include "uevr/API.h"

namespace plugin_hot_load {

// The UEVR_PluginInitializeParam handed to the inner plugin. It carries the same pointers as
// the one UEVR gave this loader, except for the parts that would let the inner plugin leave
// something behind in UEVR after it is unloaded:
//
// - the two callback tables register into this loader's slots, which forward to the inner
//   plugin while it is loaded and are emptied before it is unloaded;
// - remove_callback removes from those slots;
// - register_inline_hook and ufunction->hook_ptr still install the hook, but mark the inner
//   plugin as pinned, because the loader has no way to remove such a hook. A pinned plugin
//   is not swapped; UEVR's own "Reload Plugins" in the overlay removes those hooks.
class ApiProxy {
public:
    // Builds the proxy tables from the real parameter. Call once.
    void initialize(const UEVR_PluginInitializeParam* real);

    const UEVR_PluginInitializeParam* param() const { return &m_param; }

private:
    UEVR_PluginInitializeParam m_param{};
    UEVR_PluginCallbacks m_callbacks{};
    UEVR_PluginFunctions m_functions{};
    UEVR_SDKData m_sdk{};
    UEVR_SDKCallbacks m_sdk_callbacks{};
    UEVR_UFunctionFunctions m_ufunction{};
};

// True once the inner plugin installed a hook the loader cannot remove.
bool is_pinned();
// Forgets the pin. Call after UEVR itself unloaded the plugins, which removes those hooks.
void clear_pin();

} // namespace plugin_hot_load
