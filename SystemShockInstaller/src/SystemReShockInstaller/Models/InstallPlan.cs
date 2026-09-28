using System.IO;

namespace SystemReShockInstaller.Models;

/// <summary>Resolved target locations for one installation run.</summary>
public sealed class InstallPlan
{
    public InstallPlan(string uevrPath, string gamePath, string appDataRoot, GameStore store)
    {
        UevrPath = uevrPath;
        GamePath = gamePath;
        Store = store;
        ProfileTargetDir = Path.Combine(appDataRoot, ModPaths.UevrProfilesDirName, ModPaths.ProfileDirName);
        PaksTargetDir = Path.Combine(gamePath, ModPaths.PaksDirRelative);
        SettingsPath = Path.Combine(appDataRoot, ModPaths.SettingsDirName, ModPaths.SettingsFileName);
    }

    public string UevrPath { get; }
    public string GamePath { get; }
    public GameStore Store { get; }
    public string ProfileTargetDir { get; }
    public string PaksTargetDir { get; }
    public string SettingsPath { get; }
}
