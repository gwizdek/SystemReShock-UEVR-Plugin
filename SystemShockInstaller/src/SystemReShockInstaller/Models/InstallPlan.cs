using System.IO;

namespace SystemReShockInstaller.Models;

/// <summary>Resolved target locations for one installation run.</summary>
public sealed class InstallPlan
{
    public InstallPlan(string uevrPath, string gamePath, string appDataRoot)
    {
        UevrPath = uevrPath;
        GamePath = gamePath;
        ProfileTargetDir = Path.Combine(appDataRoot, ModPaths.UevrProfilesDirName, ModPaths.ProfileDirName);
        PaksTargetDir = Path.Combine(gamePath, ModPaths.PaksDirRelative);
        SettingsPath = Path.Combine(appDataRoot, ModPaths.SettingsDirName, ModPaths.SettingsFileName);
    }

    public string UevrPath { get; }
    public string GamePath { get; }
    public string ProfileTargetDir { get; }
    public string PaksTargetDir { get; }
    public string SettingsPath { get; }
}
