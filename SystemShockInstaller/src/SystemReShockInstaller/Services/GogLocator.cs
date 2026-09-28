using System.Linq;
using Microsoft.Win32;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Finds the GOG install of System Shock Remake through the registry key that GOG Galaxy and the offline installer both write.</summary>
public static class GogLocator
{
    public static string? FindGameFolder() =>
        new[] { RegistryView.Registry32, RegistryView.Registry64 }
            .Select(ReadInstallPath)
            .FirstOrDefault(PathValidator.IsGameFolder);

    private static string? ReadInstallPath(RegistryView view)
    {
        using var localMachine = RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, view);
        using var game = localMachine.OpenSubKey(ModPaths.GogGameRegistryKey);
        return game?.GetValue("path") as string;
    }
}
