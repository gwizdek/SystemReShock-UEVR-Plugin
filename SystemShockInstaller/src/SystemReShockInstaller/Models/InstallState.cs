namespace SystemReShockInstaller.Models;

public enum InstallStatus
{
    /// <summary>No settings, a folder no longer validates, or a mod file is missing. Run the wizard.</summary>
    NotInstalled,

    /// <summary>Everything matches this setup. Show the launcher.</summary>
    Installed,

    /// <summary>Files present but installed with a different setup version. Offer an update.</summary>
    VersionDiffers,

    /// <summary>Same version but a plugin or pak no longer matches. Run the wizard and say why.</summary>
    FilesChanged,
}

/// <summary>What the startup check found. Plan and Settings are set whenever the game can be launched.</summary>
public sealed class InstallState
{
    private InstallState(InstallStatus status, InstallPlan? plan, InstallerSettings? settings, string? reason)
    {
        Status = status;
        Plan = plan;
        Settings = settings;
        Reason = reason;
    }

    public InstallStatus Status { get; }
    public InstallPlan? Plan { get; }
    public InstallerSettings? Settings { get; }
    public string? Reason { get; }

    public bool IsLaunchable => Plan != null && Settings != null;

    public static InstallState NotInstalled(string? reason = null) =>
        new(InstallStatus.NotInstalled, null, null, reason);

    public static InstallState Installed(InstallPlan plan, InstallerSettings settings) =>
        new(InstallStatus.Installed, plan, settings, null);

    public static InstallState VersionDiffers(InstallPlan plan, InstallerSettings settings, string reason) =>
        new(InstallStatus.VersionDiffers, plan, settings, reason);

    public static InstallState FilesChanged(string reason) =>
        new(InstallStatus.FilesChanged, null, null, reason);
}
