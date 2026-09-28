using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using Microsoft.Win32;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Finds the Steam install of System Shock Remake by scanning every Steam library folder.</summary>
public static class SteamLocator
{
    private static readonly Regex LibraryPathPattern =
        new("^\\s*\"path\"\\s+\"(?<path>[^\"]+)\"", RegexOptions.Multiline | RegexOptions.IgnoreCase);

    public static string? FindGameFolder()
    {
        var steamRoot = ReadSteamRoot();
        if (steamRoot == null)
            return null;
        return LibraryRoots(steamRoot)
            .Select(GameFolderIn)
            .FirstOrDefault(PathValidator.IsGameFolder);
    }

    /// <summary>Extracts the "path" values of libraryfolders.vdf, unescaping the doubled backslashes.</summary>
    public static IEnumerable<string> ParseLibraryPaths(string vdfContent) =>
        LibraryPathPattern.Matches(vdfContent)
            .Cast<Match>()
            .Select(m => m.Groups["path"].Value.Replace("\\\\", "\\"));

    public static string GameFolderIn(string libraryRoot) =>
        Path.Combine(libraryRoot, "steamapps", "common", ModPaths.SteamGameFolderName);

    private static IEnumerable<string> LibraryRoots(string steamRoot)
    {
        yield return steamRoot;
        var vdf = Path.Combine(steamRoot, "steamapps", "libraryfolders.vdf");
        if (!File.Exists(vdf))
            yield break;
        foreach (var path in ParseLibraryPaths(File.ReadAllText(vdf)))
            yield return path;
    }

    private static string? ReadSteamRoot()
    {
        using var user = Registry.CurrentUser.OpenSubKey(@"Software\Valve\Steam");
        var fromUser = user?.GetValue("SteamPath") as string;
        if (!string.IsNullOrEmpty(fromUser))
            return fromUser!.Replace('/', '\\');
        using var machine = Registry.LocalMachine.OpenSubKey(@"SOFTWARE\WOW6432Node\Valve\Steam");
        return machine?.GetValue("InstallPath") as string;
    }
}
