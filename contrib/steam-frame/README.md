# Steam Frame controller support

UEVR has native Steam Frame support in recent builds (joeyhodge fork, October 2026).
The Frame registers its own OpenXR interaction profile
(`/interaction_profiles/valve/frame_controller_valve`) and UEVR maps its buttons to
Xbox input. The first build with this is `100626SteamFrameBindingsP1`; the
`101226HELLRAISERpl` build is the current one.

Requirements:

- UEVR build from 5 October 2026 or later (`UEVRBackend.dll` contains
  `XR_VALVE_frame_controller_interaction`).
- OpenXR runtime (the default).
- SteamVR running with the Frame connected before the game is injected.

See `frame-controller-mapping.md` for how input flows, the full game control list, and
the mapping we want.

## Files

- `frame-controller-mapping.md` - input flow, game bindings, and the proposed mapping.
- `_interaction_profiles_valve_frame_controller_valve.json` - UEVR override that moves
  the grab from the bumper to the squeeze (see section 6 of the mapping doc).
- `launch-vr.ps1` - launches the game through Steam, waits for SteamVR, injects UEVR.
- `movement-analysis.md` - separate movement/body-detachment investigation.
