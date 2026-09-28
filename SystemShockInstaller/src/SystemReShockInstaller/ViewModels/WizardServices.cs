using System;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;

namespace SystemReShockInstaller.ViewModels;

/// <summary>Everything the pages need, composed once at startup in App.xaml.cs.</summary>
public sealed class WizardServices
{
    public InstallService Installer { get; set; } = null!;
    public InstallService Uninstaller { get; set; } = null!;
    public IDialogs Dialogs { get; set; } = null!;
    public ISettingsStore SettingsStore { get; set; } = null!;
    public IFolderPicker FolderPicker { get; set; } = null!;
    public IProcessChecker ProcessChecker { get; set; } = null!;
    /// <summary>Where a store installed the game, or null when that store has no install.</summary>
    public Func<GameStore, string?> LocateGame { get; set; } = null!;
    public InstallStateResolver StateResolver { get; set; } = null!;
    public GameLaunchService Launcher { get; set; } = null!;
    public string AppDataRoot { get; set; } = string.Empty;
    public string Version { get; set; } = string.Empty;
}
