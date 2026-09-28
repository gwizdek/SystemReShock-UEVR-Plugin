using System;
using System.Windows.Input;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.ViewModels;

public sealed class WelcomeActions
{
    public Action Next { get; set; } = () => { };

    /// <summary>Set only when a working install exists and the page offers an update.</summary>
    public Action? Launch { get; set; }

    /// <summary>Set only when a settings file exists, so there is something to remove.</summary>
    public Action? Uninstall { get; set; }

    public Action Cancel { get; set; } = () => { };
}

/// <summary>First wizard page. In update mode it also offers to launch the installed version.</summary>
public sealed class WelcomeViewModel : ViewModelBase
{
    public WelcomeViewModel(string version, InstallState state, WelcomeActions actions)
    {
        VersionText = "Version " + version;
        Notice = state.Reason;
        IsUpdateOffer = actions.Launch != null;
        CanUninstall = actions.Uninstall != null;
        NextCommand = new RelayCommand(actions.Next);
        LaunchCommand = new RelayCommand(actions.Launch ?? (() => { }));
        UninstallCommand = new RelayCommand(actions.Uninstall ?? (() => { }));
        CancelCommand = new RelayCommand(actions.Cancel);
    }

    public string VersionText { get; }
    public string? Notice { get; }
    public bool HasNotice => Notice != null;
    public bool IsUpdateOffer { get; }
    public bool CanUninstall { get; }
    public string NextText => IsUpdateOffer ? "Update" : "Next";
    public string CancelText => IsUpdateOffer ? "Close" : "Cancel";
    public ICommand NextCommand { get; }
    public ICommand LaunchCommand { get; }
    public ICommand UninstallCommand { get; }
    public ICommand CancelCommand { get; }
}
