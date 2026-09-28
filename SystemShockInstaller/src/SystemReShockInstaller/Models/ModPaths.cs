using System;

namespace SystemReShockInstaller.Models;

/// <summary>Fixed names shared by validation, planning, installation, and launching.</summary>
public static class ModPaths
{
    public const string GameExeName = "SystemReShock-Win64-Shipping";
    public const string ProfileDirName = GameExeName;
    public const string UevrProfilesDirName = "UnrealVRMod";
    public const string SettingsDirName = "SystemReShockVR";
    public const string SettingsFileName = "settings.json";
    public const string UevrInjectorExe = "UEVRInjector.exe";
    public const string UevrBackendDll = "UEVRBackend.dll";
    public const string GameExeRelative = @"SystemShock\Binaries\Win64\" + GameExeName + ".exe";
    public const string PaksDirRelative = @"SystemShock\Content\Paks";
    public const string BundlePaksFolder = "paks";
    public const string BundlePluginsFolder = "plugins";
    public const string SteamGameFolderName = "System Shock Remake";
    public const string SteamAppId = "482400";
    public const string SteamLaunchUri = "steam://rungameid/" + SteamAppId;
    /// <summary>Every Steam library keeps its games under this path, so it marks a Steam install.</summary>
    public const string SteamCommonSegment = @"\steamapps\common\";
    public const string GogGameId = "1439637285";
    /// <summary>Under HKLM. Read through the 32-bit registry view, where GOG writes it.</summary>
    public const string GogGameRegistryKey = @"SOFTWARE\GOG.com\Games\" + GogGameId;
    /// <summary>GOG writes this file into the root of every game it installs.</summary>
    public const string GogInfoFilePattern = "goggame-*.info";
    public const string UevrNightlyUrl = "https://github.com/praydog/UEVR-nightly/releases/latest";
    public const int DefaultInjectDelaySeconds = 15;
    public static readonly TimeSpan GameWindowTimeout = TimeSpan.FromMinutes(2);
}
