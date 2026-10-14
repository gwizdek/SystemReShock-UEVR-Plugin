#pragma once

#include <cstdint>

namespace SDK
{
    class UWorld;
    class ACON_Hacker_C;
}

namespace uevr
{
    class API;
}

// Makes the button icons inside texts take the gamepad path while the game stays in keyboard
// and mouse mode.
//
// The plugin keeps CON_Hacker.ActiveControllerType at 0 (keyboard and mouse), because gamepad
// mode changes how the game plays; documentation\controller-type.md explains why. The key
// widgets that draw a button icon inside a text (WIDGET_ButtonLegend_KeyComposite and
// WIDGET_ButtonLegend_Key, created by a TextMeshWidget for every {placeholder}) copy that
// value into their own ControllerMode in two places: their initialize function, run from the
// Construct event, and GetDecoratorSizeFromPayload, run when the text mesh is built. Both
// resolve the key for that mode right away, and a rebuild of the text creates the widgets
// anew, so setting the mode on a widget afterwards does not last.
//
// This class hooks GetDecoratorSizeFromPayload, Construct and PreConstruct of both widgets.
// Before each call it writes 1 (gamepad) into the controller's field and after the call it
// writes the old value back. The call runs on the
// game thread, so nothing else sees the gamepad value, and no change event is broadcast. Only
// widgets that a text mesh created are affected: the key widgets of menu legends sit in a
// widget tree, the decorators have the game instance as outer.
//
// The hook is installed with UEVR's UFunction hook, which the plugin hot loader cannot remove.
// A plugin with this hook installed cannot be swapped by the hot loader; use "Reload Plugins"
// in the UEVR overlay instead (documentation\plugin-hot-reload.md).
class ButtonLegendMode final
{
public:
    // Called once per engine tick, on the game thread. Installs the hooks once the widget
    // classes are loaded, and remembers the world for the hooks.
    static void handle(SDK::UWorld* world);

private:
    static void try_install();
    static bool install_hook(const wchar_t* function_name);

    // The two callbacks the hooks share. obj is the widget the function runs on.
    static bool on_pre(void* function, void* obj, void* params, void* result);
    static bool on_post(void* function, void* obj, void* params, void* result);

    static bool is_text_decorator(const void* widget);
    static void log_call(const char* where, void* function, void* obj, bool decorator, const void* hacker);
    static SDK::ACON_Hacker_C* controller(void* widget);

    static SDK::UWorld* s_world;
    static bool s_installed;
    static int s_ticks_until_retry;

    // Nesting depth of hooked calls and the value to restore when the outermost call ends.
    static int s_depth;
    static uint8_t s_saved_type;
};
