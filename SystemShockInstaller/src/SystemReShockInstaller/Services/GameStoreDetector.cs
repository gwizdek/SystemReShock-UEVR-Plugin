using System;
using System.IO;
using System.Linq;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>
/// Decides which store a game folder came from by looking at the folder itself.
/// GOG installs carry a goggame-*.info file at the root. Steam installs live under steamapps\common.
/// Anything else is a copied or moved install.
/// </summary>
public static class GameStoreDetector
{
    public static GameStore Detect(string? gameFolder)
    {
        if (string.IsNullOrWhiteSpace(gameFolder))
            return GameStore.Other;
        if (HasGogMarker(gameFolder!))
            return GameStore.GOG;
        if (IsInSteamLibrary(gameFolder!))
            return GameStore.Steam;
        return GameStore.Other;
    }

    private static bool HasGogMarker(string folder) =>
        Directory.Exists(folder) && Directory.EnumerateFiles(folder, ModPaths.GogInfoFilePattern).Any();

    private static bool IsInSteamLibrary(string folder) =>
        folder.Replace('/', '\\').IndexOf(ModPaths.SteamCommonSegment, StringComparison.OrdinalIgnoreCase) >= 0;
}
