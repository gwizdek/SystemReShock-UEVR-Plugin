using System;
using System.Collections.Generic;

namespace SystemReShockInstaller.Models;

public enum VrRuntime
{
    OpenXR,
    OpenVR,
}

/// <summary>Maps each runtime to its settings key and the UEVR loader DLL injected before the backend.</summary>
public static class VrRuntimes
{
    public const VrRuntime Default = VrRuntime.OpenXR;

    private static readonly Dictionary<VrRuntime, (string Key, string Dll)> Table = new()
    {
        [VrRuntime.OpenXR] = ("openxr", "openxr_loader.dll"),
        [VrRuntime.OpenVR] = ("openvr", "openvr_api.dll"),
    };

    public static string Key(VrRuntime runtime) => Table[runtime].Key;

    public static string DllName(VrRuntime runtime) => Table[runtime].Dll;

    public static VrRuntime Parse(string? key)
    {
        foreach (var pair in Table)
        {
            if (string.Equals(pair.Value.Key, key, StringComparison.OrdinalIgnoreCase))
                return pair.Key;
        }
        return Default;
    }
}
