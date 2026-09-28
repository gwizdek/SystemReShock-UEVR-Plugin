using System.IO;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class UninstallStepTests
{
    [Fact]
    public void Pak_step_deletes_mod_paks_and_leaves_other_paks_alone()
    {
        using var game = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = new InstallPlan(@"C:\uevr", game.Path, game.Path, GameStore.GOG);
        new PakInstallStep(bundle).Execute(plan);
        File.WriteAllText(Path.Combine(plan.PaksTargetDir, "pakchunk0-WindowsNoEditor.pak"), "game-data");

        new PakRemoveStep(bundle).Execute(plan);

        Assert.False(File.Exists(Path.Combine(plan.PaksTargetDir, "SystemShockVRModCore_P.pak")));
        Assert.False(File.Exists(Path.Combine(plan.PaksTargetDir, "SystemShockVRModAddon_P.pak")));
        Assert.Equal("game-data", File.ReadAllText(Path.Combine(plan.PaksTargetDir, "pakchunk0-WindowsNoEditor.pak")));
    }

    [Fact]
    public void Pak_step_tolerates_missing_files_and_folder()
    {
        using var game = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = new InstallPlan(@"C:\uevr", game.File("gone"), game.Path, GameStore.Other);

        new PakRemoveStep(bundle).Execute(plan);

        Assert.False(Directory.Exists(plan.PaksTargetDir));
    }

    [Fact]
    public void Profile_step_deletes_folder_with_read_only_files()
    {
        using var appData = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = new InstallPlan(@"C:\uevr", @"C:\game", appData.Path, GameStore.Steam);
        new ProfileInstallStep(bundle).Execute(plan);
        File.SetAttributes(Path.Combine(plan.ProfileTargetDir, "config.txt"), FileAttributes.ReadOnly);

        new ProfileRemoveStep().Execute(plan);

        Assert.False(Directory.Exists(plan.ProfileTargetDir));
        Assert.True(Directory.Exists(Path.Combine(appData.Path, ModPaths.UevrProfilesDirName)));
    }

    [Fact]
    public void Profile_step_tolerates_missing_folder()
    {
        using var appData = new TempDir();
        var plan = new InstallPlan(@"C:\uevr", @"C:\game", appData.Path, GameStore.Steam);

        new ProfileRemoveStep().Execute(plan);

        Assert.False(Directory.Exists(plan.ProfileTargetDir));
    }

    [Fact]
    public void Settings_step_deletes_file_and_its_empty_folder()
    {
        using var appData = new TempDir();
        var plan = new InstallPlan(@"C:\uevr", @"C:\game", appData.Path, GameStore.Steam);
        new SettingsSaveStep(new SettingsStore(), "2.0").Execute(plan);

        new SettingsRemoveStep().Execute(plan);

        Assert.False(File.Exists(plan.SettingsPath));
        Assert.False(Directory.Exists(Path.GetDirectoryName(plan.SettingsPath)));
    }

    [Fact]
    public void Settings_step_keeps_folder_that_holds_other_files()
    {
        using var appData = new TempDir();
        var plan = new InstallPlan(@"C:\uevr", @"C:\game", appData.Path, GameStore.Steam);
        new SettingsSaveStep(new SettingsStore(), "2.0").Execute(plan);
        var other = Path.Combine(Path.GetDirectoryName(plan.SettingsPath)!, "notes.txt");
        File.WriteAllText(other, "keep");

        new SettingsRemoveStep().Execute(plan);

        Assert.False(File.Exists(plan.SettingsPath));
        Assert.True(File.Exists(other));
    }
}
