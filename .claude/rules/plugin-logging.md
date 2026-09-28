# Plugin Logging Rules

> These rules apply to all C++ code in `SystemShockVR\`.

## Use warn level for messages that must show up in the log

UEVR does not write plugin `info` messages to its `log.txt`. Only `warn` and `error` from the
plugin reach the file. So:

- Use `API::get()->log_warn(...)` for every message a person should see: state changes, setup
  steps, values applied, "not found, retrying" and similar.
- Use `API::get()->log_error(...)` only for failures, including the `catch (...)` blocks.
- Do not use `API::get()->log_info(...)` for anything that matters. It is silent in the shipped
  UEVR build. `PLUGIN_LOG_ONCE` uses `log_info` and is therefore silent too.

The log file is `%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\log.txt`.

## Message format

Prefix every message with the file and function in brackets, so the log can be grepped:

```cpp
API::get()->log_warn("[plugin_utils][set_material_two_sided] %s TwoSided=%d", name, value);
```

Keep per-tick logging behind a flag or a counter. A message every engine tick fills the log in
seconds and hides everything else.
