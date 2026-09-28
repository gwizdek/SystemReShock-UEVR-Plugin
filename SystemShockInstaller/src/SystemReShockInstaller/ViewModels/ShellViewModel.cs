using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.ViewModels;

/// <summary>Owns the current page. Routes between the launcher and the install wizard. There is no Back.</summary>
public sealed class ShellViewModel : ViewModelBase
{
    private const string SetupTitle = "System Shock Remake VR Mod Setup";
    private const string LauncherTitle = "System Shock Remake VR Mod";

    private readonly WizardServices _services;
    private readonly Action _closeApp;
    private object _currentPage = new object();
    private string _windowTitle = SetupTitle;
    private bool _canReturnToLauncher;

    public ShellViewModel(WizardServices services, Action closeApp, bool forceInstall)
    {
        _services = services;
        _closeApp = closeApp;
        var state = forceInstall ? InstallState.NotInstalled() : services.StateResolver.Resolve();
        if (state.Status == InstallStatus.Installed)
            ShowLauncher(state);
        else
            ShowWelcome(state);
    }

    public object CurrentPage
    {
        get => _currentPage;
        private set => Set(ref _currentPage, value);
    }

    public string WindowTitle
    {
        get => _windowTitle;
        private set => Set(ref _windowTitle, value);
    }

    private void ShowWelcome(InstallState state)
    {
        var offersUpdate = state.Status == InstallStatus.VersionDiffers && state.IsLaunchable;
        var actions = new WelcomeActions
        {
            Next = ShowPaths,
            Launch = offersUpdate ? () => ShowLauncher(state) : null,
            Uninstall = state.CanUninstall ? () => _ = UninstallAsync(state.Plan!) : null,
            Cancel = offersUpdate ? _closeApp : CancelWizard,
        };
        SetPage(new WelcomeViewModel(_services.Version, state, actions), SetupTitle);
    }

    private void ShowLauncher(InstallState state)
    {
        _canReturnToLauncher = true;
        var actions = new LauncherActions
        {
            Reinstall = ShowPaths,
            Uninstall = () => _ = UninstallAsync(state.Plan!),
            Exit = _closeApp,
        };
        SetPage(new LauncherViewModel(_services, state, actions), LauncherTitle);
    }

    private void ShowPaths() =>
        SetPage(new PathsViewModel(_services, ShowConfirm, CancelWizard), SetupTitle);

    private void ShowConfirm(InstallPlan plan) =>
        SetPage(new ConfirmViewModel(_services, plan, results => ShowResult(plan, results), CancelWizard), SetupTitle);

    private void ShowResult(InstallPlan plan, IReadOnlyList<StepResult> results)
    {
        var succeeded = results.All(r => r.Succeeded);
        SetPage(ResultViewModel.ForInstall(plan, results, succeeded ? ReturnToLauncherOrClose : _closeApp), SetupTitle);
    }

    /// <summary>Stays on the current page when the flow is refused or declined.</summary>
    private async Task UninstallAsync(InstallPlan plan)
    {
        var results = await new UninstallFlow(_services).RunAsync(plan);
        if (results != null)
            SetPage(ResultViewModel.ForUninstall(plan, results, _closeApp), SetupTitle);
    }

    private void CancelWizard()
    {
        if (_canReturnToLauncher)
            ReturnToLauncherOrClose();
        else
            _closeApp();
    }

    private void ReturnToLauncherOrClose()
    {
        var state = _services.StateResolver.Resolve();
        if (state.IsLaunchable)
            ShowLauncher(state);
        else
            _closeApp();
    }

    private void SetPage(object page, string title)
    {
        CurrentPage = page;
        WindowTitle = title;
    }
}
