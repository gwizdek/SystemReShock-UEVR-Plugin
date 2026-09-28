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

/// <summary>
/// What the startup check found. Plan and Settings are set whenever a settings file was read,
/// even when the install is broken, so that Uninstall knows what to remove.
/// </summary>
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

    public bool IsLaunchable => Status == InstallStatus.Installed || Status == InstallStatus.VersionDiffers;
    public bool CanUninstall => Plan != null;

    public static InstallState NotInstalled(string? reason = null, InstallPlan? plan = null, InstallerSettings? settings = null) =>
        new(InstallStatus.NotInstalled, plan, settings, reason);

    public static InstallState Installed(InstallPlan plan, InstallerSettings settings) =>
        new(InstallStatus.Installed, plan, settings, null);

    public static InstallState VersionDiffers(InstallPlan plan, InstallerSettings settings, string reason) =>
        new(InstallStatus.VersionDiffers, plan, settings, reason);

    public static InstallState FilesChanged(InstallPlan plan, InstallerSettings settings, string reason) =>
        new(InstallStatus.FilesChanged, plan, settings, reason);
}
