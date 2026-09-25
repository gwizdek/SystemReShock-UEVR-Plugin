using System;
using SystemReShockInstaller.Services;

namespace SystemReShockInstaller.ViewModels;

/// <summary>Everything the pages need, composed once at startup in App.xaml.cs.</summary>
public sealed class WizardServices
{
    public InstallService Installer { get; set; } = null!;
    public ISettingsStore SettingsStore { get; set; } = null!;
    public IFolderPicker FolderPicker { get; set; } = null!;
    public IProcessChecker ProcessChecker { get; set; } = null!;
    public Func<string?> LocateSteamGame { get; set; } = null!;
    public InstallStateResolver StateResolver { get; set; } = null!;
    public GameLaunchService Launcher { get; set; } = null!;
    public string AppDataRoot { get; set; } = string.Empty;
    public string Version { get; set; } = string.Empty;
}
