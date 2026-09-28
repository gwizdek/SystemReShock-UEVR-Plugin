using System;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Input;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;

namespace SystemReShockInstaller.ViewModels;

public sealed class LauncherActions
{
    public Action Reinstall { get; set; } = () => { };
    public Action Uninstall { get; set; } = () => { };
    public Action Exit { get; set; } = () => { };
}

public sealed class LauncherViewModel : ViewModelBase
{
    private readonly WizardServices _services;
    private readonly InstallPlan _plan;
    private readonly InstallerSettings _settings;
    private readonly RelayCommand _launchCommand;
    private readonly RelayCommand _reinstallCommand;
    private readonly RelayCommand _uninstallCommand;
    private readonly RelayCommand _exitCommand;
    private string _status = "Ready to launch.";
    private bool _isBusy;
    private bool _injected;

    public LauncherViewModel(WizardServices services, InstallState state, LauncherActions actions)
    {
        if (!state.IsLaunchable)
            throw new ArgumentException("A launchable state is required.", nameof(state));
        _services = services;
        _plan = state.Plan!;
        _settings = state.Settings!;
        InstalledVersionText = "Mod v" + (_settings.InstalledVersion ?? "unknown") + " installed";
        StoreText = GameStores.Describe(_plan.Store);
        DelayText = "UEVR is injected " + DelaySeconds + " seconds after the game window appears.";
        _launchCommand = new RelayCommand(() => _ = LaunchAsync(), () => !IsBusy && !_injected);
        _reinstallCommand = new RelayCommand(actions.Reinstall, () => !IsBusy);
        _uninstallCommand = new RelayCommand(actions.Uninstall, () => !IsBusy);
        _exitCommand = new RelayCommand(actions.Exit, () => !IsBusy);
    }

    public string InstalledVersionText { get; }
    public string StoreText { get; }
    public string DelayText { get; }
    public ICommand LaunchCommand => _launchCommand;
    public ICommand ReinstallCommand => _reinstallCommand;
    public ICommand UninstallCommand => _uninstallCommand;
    public ICommand ExitCommand => _exitCommand;

    public string Status
    {
        get => _status;
        private set => Set(ref _status, value);
    }

    public bool IsBusy
    {
        get => _isBusy;
        private set
        {
            if (!Set(ref _isBusy, value))
                return;
            _launchCommand.RaiseCanExecuteChanged();
            _reinstallCommand.RaiseCanExecuteChanged();
            _uninstallCommand.RaiseCanExecuteChanged();
            _exitCommand.RaiseCanExecuteChanged();
        }
    }

    public bool IsOpenXr
    {
        get => Runtime == VrRuntime.OpenXR;
        set
        {
            if (value)
                SetRuntime(VrRuntime.OpenXR);
        }
    }

    public bool IsOpenVr
    {
        get => Runtime == VrRuntime.OpenVR;
        set
        {
            if (value)
                SetRuntime(VrRuntime.OpenVR);
        }
    }

    private VrRuntime Runtime => VrRuntimes.Parse(_settings.Runtime);

    private int DelaySeconds => _settings.InjectDelaySeconds ?? ModPaths.DefaultInjectDelaySeconds;

    private void SetRuntime(VrRuntime runtime)
    {
        if (Runtime == runtime)
            return;
        _settings.Runtime = VrRuntimes.Key(runtime);
        _services.SettingsStore.Save(_plan.SettingsPath, _settings);
        Raise(nameof(IsOpenXr));
        Raise(nameof(IsOpenVr));
    }

    private async Task LaunchAsync()
    {
        IsBusy = true;
        try
        {
            var request = new LaunchRequest(_plan.UevrPath, _plan.GamePath, _plan.Store, Runtime, DelaySeconds);
            await _services.Launcher.RunAsync(request, new Progress<string>(s => Status = s), CancellationToken.None);
            _injected = true;
            Status = "UEVR injected. Put on your headset.";
        }
        catch (Exception ex)
        {
            Status = LaunchErrorFormatter.Format(ex);
        }
        finally
        {
            IsBusy = false;
        }
    }
}
