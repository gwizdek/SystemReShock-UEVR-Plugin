# Movement / body-detachment issue — analysis (hypotheses)

Status: **analysis only**, no fix yet. Based on the log at
`C:\Users\andyp\Downloads\log.txt` and gwizdek's notes.

## Reported symptoms

- Head is detached from the body.
- Right stick turns the **body** but not the HMD.
- Left stick moves in the right direction at first, then "something happens";
  after that the head is stuck to the body and the movement direction is off.

gwizdek's read: the mod is failing to detect game state (normal play vs. menu
vs. cyberspace) and therefore isn't setting the VR options that depend on it.
He also noticed it not detecting the intro apartment.

## Important: this may share a root cause with the bindings

Stick input is delivered by the same pipeline as the buttons:
`Frame thumbstick → OpenXR interaction profile → UEVR joystick action → Xbox
sticks → plugin`. On Frame there is **no UEVR binding profile**, so SteamVR
falls back to the Oculus Touch remap (Valve's docs). Sticks and triggers are
part of that remap. So it is plausible that **fixing the Frame binding profile
also fixes movement/turning**, and worth testing before deep-diving the engine
side. Do the bindings first.

## What the log actually shows

Environment: UEVR 1.05 + nightly (build 2026-08-30, commit `4ee5c6b`), OpenXR,
DirectX 11 (D3D12 init failed, fell back to DX11), plugin `SystemReShockVR.dll`
loaded from `...\UnrealVRMod\SystemReShock-Win64-Shipping\plugins\`.

| Observation | Detail |
|---|---|
| SDK bootstrap OK | `objects: SDK=57252 UEVR=57252`, `SDK bound to UEVR` |
| Game-state detection **worked** | `New Level: 00_Menu` → `Player Ghost`; then `New Level: CitadelStation` → `Hacker Implant` |
| VR body spawned | `initialize_vr_body` → `Attached to Hacker's root component`, `initialize_mcs Initialized MCs` |
| **Bridge warmup incomplete** | `[plugin_utils][warmup_bridge] Incomplete, see [bridge] lines above` |
| **UObjectHook JSON rejected** | 11× `[UObjectHook] Malfomed JSON file (missing path or state)`; `camera_state.json` and several `*_mc_state.json` "does not appear to be a valid persistent properties file" |
| **XInput hook partial** | `[XInputHook] Done (1_3)`, then `[XInputHook] Failed to find xinput1_4.dll after 10 seconds`; `[DInputHook] Timed out waiting for dinput8.dll` |
| OpenXR timing errors | `xrEndFrame failed: XR_ERROR_TIME_INVALID`, `xrBeginFrame failed: XR_FRAME_DISCARDED`, `display time diff: -25011200` |
| Session focus lost | `[VR] Failed to sync actions: XR_SESSION_NOT_FOCUSED` |
| Pattern-scan noise | many `Failed to find true vfunc`, `Emulation failed`, `Failed to find function start`, `Failed to find stereo rendering device` |

## Hypotheses, ranked, with tests

### H1 — Mod Blueprints (paks) missing or out of sync → bridge half-wired
`warmup_bridge` finishing "Incomplete" means some bridged Blueprint
properties/functions were not found. The mod ships **two** paks
(`SystemShockVRModCore_P.pak`, `SystemShockVRModAddon_P.pak`) that must be in
`...\Content\Paks` and in sync with the DLL. If one is missing/stale, body and
control components are missing or mismatched — which fits "head detached".
- **Test:** confirm both paks present and matching the DLL version; check the
  full log for `[bridge] ... not found` lines.
- **Cost:** low. Do this first.

### H2 — Profile `uobjecthook` JSONs rejected by this UEVR build
Every persistent-properties file failed to deserialize, including
`camera_state.json`. Those files define attachments between game components and
the VR controllers/camera. If they don't load, controller/camera attachment can
be wrong even though the plugin spawned the body.
- **Test:** compare the profile JSON schema against UEVR 1.05's expectations;
  try a run with an emptied `uobjecthook\` directory and observe.
- **Cost:** low.

### H3 — VR options never applied (inject timing / state detection)
The plugin applies VR options once, at the main menu (gwizdek's README). If
UEVR is injected late or a save is loaded directly, options may not be set,
leaving body/camera rotation decoupled incorrectly. gwizdek's own note points
here.
- **Test:** inject at the main menu on a fresh launch, then load; diff the UEVR
  option values (`VR_AimMethod`, `VR_DecoupledPitch`, roomscale) before/after.

### H4 — XInput stream is inconsistent (gwizdek's "extra XInputGetState calls")
gwizdek guessed the Frame's extra buttons cause more `XInputGetState` calls.
Button count itself doesn't drive call count (the game polls), **but** more
physical devices / a Steam Input virtual gamepad **can** create extra XInput
slots and calls. Concretely: the plugin's callback signature takes
`user_index` but **never uses it** (`plugin.cpp:176`; grep shows `user_index`
appears only in the signature). So if callbacks arrive for more than one index,
the memoized `MemoInput`/stick state flips between devices — erratic buttons and
turning.
- **Evidence:** `[XInputHook] ... xinput1_4.dll` timing out; un-filtered
  `user_index` in code.
- **Test:** add a runtime dump of `user_index`, callbacks-per-frame, and raw
  `wButton`/`sThumb`; compare against `vr->get_lowest_xinput_index()`.
- **Cost:** needs a build (Visual Studio Build Tools).

### H5 — OpenXR session / timing health
`XR_SESSION_NOT_FOCUSED` plus repeated `XR_ERROR_TIME_INVALID` /
`XR_FRAME_DISCARDED` mean the runtime is discarding frames and input actions
aren't syncing at points. This can cause visible desync/stutter and dropped
input, though probably not a persistent body detachment on its own.
- **Test:** ensure the game window is focused during play; confirm the OpenXR
  runtime is healthy; re-capture a log.

## Suggested order

1. H1 (paks/bridge) and H3 (inject at main menu) — no code, minutes.
2. Frame binding profile — may resolve movement too; no build required.
3. H4 diagnostic build — needs Build Tools; instrument `user_index` + state.
4. H2 (uobjecthook schema) and H5 (session health) as follow-ups.

## Note on the log's `xinput1_4.dll` line

Worth confirming which XInput the game actually loads. UEVR hooked 1.3 but
timed out on 1.4. If the game polls 1.4, the plugin's `on_xinput_get_state`
would never fire, and all button/stick remapping would silently do nothing.
The H4 diagnostic (log whether the callback fires at all, and with which index)
settles this.
