using System.IO;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class InstallStepTests
{
    [Fact]
    public void Profile_step_wipes_old_folder_and_extracts_only_profile_files()
    {
        using var appData = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = new InstallPlan(@"C:\uevr", @"C:\game", appData.Path, GameStore.Steam);
        Directory.CreateDirectory(plan.ProfileTargetDir);
        File.WriteAllText(Path.Combine(plan.ProfileTargetDir, "stale_old_plugin.dll"), "old");

        new ProfileInstallStep(bundle).Execute(plan);

        Assert.False(File.Exists(Path.Combine(plan.ProfileTargetDir, "stale_old_plugin.dll")));
        Assert.Equal("VR_WorldScale=0.950000", File.ReadAllText(Path.Combine(plan.ProfileTargetDir, "config.txt")));
        Assert.True(File.Exists(Path.Combine(plan.ProfileTargetDir, @"plugins\SystemReShockVR.dll")));
        Assert.True(File.Exists(Path.Combine(plan.ProfileTargetDir, @"uobjecthook\camera_state.json")));
        Assert.False(Directory.Exists(Path.Combine(plan.ProfileTargetDir, "paks")));
    }

    [Fact]
    public void Profile_step_works_when_folder_does_not_exist_yet()
    {
        using var appData = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = new InstallPlan(@"C:\uevr", @"C:\game", appData.Path, GameStore.Steam);

        new ProfileInstallStep(bundle).Execute(plan);

        Assert.True(File.Exists(Path.Combine(plan.ProfileTargetDir, "ProfileMeta.json")));
    }

    [Fact]
    public void Pak_step_replaces_mod_paks_and_leaves_other_paks_alone()
    {
        using var game = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = new InstallPlan(@"C:\uevr", game.Path, game.Path, GameStore.Steam);
        Directory.CreateDirectory(plan.PaksTargetDir);
        File.WriteAllText(Path.Combine(plan.PaksTargetDir, "SystemShockVRModCore_P.pak"), "core-v1");
        File.WriteAllText(Path.Combine(plan.PaksTargetDir, "pakchunk0-WindowsNoEditor.pak"), "game-data");
        File.WriteAllText(Path.Combine(plan.PaksTargetDir, "SystemShock-VRFixes_p.pak"), "legacy");

        new PakInstallStep(bundle).Execute(plan);

        Assert.Equal("core-v2", File.ReadAllText(Path.Combine(plan.PaksTargetDir, "SystemShockVRModCore_P.pak")));
        Assert.Equal("addon-v2", File.ReadAllText(Path.Combine(plan.PaksTargetDir, "SystemShockVRModAddon_P.pak")));
        Assert.Equal("game-data", File.ReadAllText(Path.Combine(plan.PaksTargetDir, "pakchunk0-WindowsNoEditor.pak")));
        Assert.Equal("legacy", File.ReadAllText(Path.Combine(plan.PaksTargetDir, "SystemShock-VRFixes_p.pak")));
    }

    [Fact]
    public void Pak_step_overwrites_read_only_pak()
    {
        using var game = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = new InstallPlan(@"C:\uevr", game.Path, game.Path, GameStore.Steam);
        Directory.CreateDirectory(plan.PaksTargetDir);
        var target = Path.Combine(plan.PaksTargetDir, "SystemShockVRModAddon_P.pak");
        File.WriteAllText(target, "addon-v1");
        File.SetAttributes(target, FileAttributes.ReadOnly);

        new PakInstallStep(bundle).Execute(plan);

        Assert.Equal("addon-v2", File.ReadAllText(target));
    }
}
