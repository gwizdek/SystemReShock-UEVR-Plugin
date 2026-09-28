using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using SystemReShockInstaller.ViewModels;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class UninstallFlowTests
{
    [Fact]
    public async Task Confirmed_uninstall_removes_everything_and_reports_each_step()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = Installed(root, bundle);
        var dialogs = new FakeDialogs { Answer = true };

        var results = await new UninstallFlow(Services(bundle, dialogs, gameRunning: false)).RunAsync(plan);

        Assert.NotNull(results);
        Assert.Equal(3, results!.Count);
        Assert.All(results, r => Assert.True(r.Succeeded));
        Assert.False(File.Exists(Path.Combine(plan.PaksTargetDir, "SystemShockVRModCore_P.pak")));
        Assert.False(Directory.Exists(plan.ProfileTargetDir));
        Assert.False(File.Exists(plan.SettingsPath));
        Assert.Contains("SystemShockVRModAddon_P.pak", dialogs.LastMessage);
        Assert.Contains(plan.ProfileTargetDir, dialogs.LastMessage);
        Assert.Contains(plan.SettingsPath, dialogs.LastMessage);
    }

    [Fact]
    public async Task Declined_confirmation_changes_nothing()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = Installed(root, bundle);

        var results = await new UninstallFlow(Services(bundle, new FakeDialogs { Answer = false }, gameRunning: false)).RunAsync(plan);

        Assert.Null(results);
        Assert.True(File.Exists(plan.SettingsPath));
        Assert.True(Directory.Exists(plan.ProfileTargetDir));
    }

    [Fact]
    public async Task Running_game_is_refused_before_the_question()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = Installed(root, bundle);
        var dialogs = new FakeDialogs { Answer = true };

        var results = await new UninstallFlow(Services(bundle, dialogs, gameRunning: true)).RunAsync(plan);

        Assert.Null(results);
        Assert.True(dialogs.Warned);
        Assert.False(dialogs.Asked);
        Assert.True(File.Exists(plan.SettingsPath));
    }

    private static InstallPlan Installed(TempDir root, IModBundle bundle)
    {
        var plan = InstallVerifierTests.Install(root, bundle);
        new SettingsSaveStep(new SettingsStore(), "2.0").Execute(plan);
        return plan;
    }

    private static WizardServices Services(IModBundle bundle, IDialogs dialogs, bool gameRunning) => new()
    {
        Uninstaller = new InstallService(new IInstallStep[] { new PakRemoveStep(bundle), new ProfileRemoveStep(), new SettingsRemoveStep() }),
        Dialogs = dialogs,
        ProcessChecker = new FakeProcessChecker { Running = gameRunning },
    };

    private sealed class FakeDialogs : IDialogs
    {
        public bool Answer { get; set; }
        public bool Asked { get; private set; }
        public bool Warned { get; private set; }
        public string LastMessage { get; private set; } = string.Empty;

        public bool Confirm(string title, string message)
        {
            Asked = true;
            LastMessage = message;
            return Answer;
        }

        public void Warn(string title, string message)
        {
            Warned = true;
            LastMessage = message;
        }
    }

    private sealed class FakeProcessChecker : IProcessChecker
    {
        public bool Running { get; set; }
        public bool IsGameRunning() => Running;
    }
}
