using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using SystemReShockInstaller.ViewModels;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class LauncherViewModelTests
{
    [Fact]
    public void Game_with_uevr_injected_leaves_only_exit_enabled()
    {
        var launcher = Launcher(injected: true);

        Assert.Equal(LauncherViewModel.AlreadyInjectedStatus, launcher.Status);
        Assert.False(launcher.LaunchCommand.CanExecute(null));
        Assert.False(launcher.ReinstallCommand.CanExecute(null));
        Assert.False(launcher.UninstallCommand.CanExecute(null));
        Assert.False(launcher.CanChangeRuntime);
        Assert.True(launcher.ExitCommand.CanExecute(null));
    }

    [Fact]
    public void Game_without_uevr_leaves_everything_enabled()
    {
        var launcher = Launcher(injected: false);

        Assert.Equal(LauncherViewModel.ReadyStatus, launcher.Status);
        Assert.True(launcher.LaunchCommand.CanExecute(null));
        Assert.True(launcher.ReinstallCommand.CanExecute(null));
        Assert.True(launcher.UninstallCommand.CanExecute(null));
        Assert.True(launcher.CanChangeRuntime);
        Assert.True(launcher.ExitCommand.CanExecute(null));
    }

    private static LauncherViewModel Launcher(bool injected)
    {
        var plan = new InstallPlan(@"C:\uevr", @"C:\game", @"C:\appdata", GameStore.Steam);
        var settings = new InstallerSettings { UevrPath = @"C:\uevr", GamePath = @"C:\game", InstalledVersion = "2.0" };
        var services = new WizardServices { ProcessChecker = new FakeProcessChecker { Injected = injected } };
        return new LauncherViewModel(services, InstallState.Installed(plan, settings), new LauncherActions());
    }

    private sealed class FakeProcessChecker : IProcessChecker
    {
        public bool Injected { get; set; }
        public bool IsGameRunning() => Injected;
        public bool IsUevrInjected() => Injected;
    }
}
