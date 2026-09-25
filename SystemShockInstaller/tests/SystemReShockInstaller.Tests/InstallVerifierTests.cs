using System.IO;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class InstallVerifierTests
{
    [Fact]
    public void Fresh_install_passes()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = Install(root, bundle);

        Assert.Null(new InstallVerifier(bundle).Verify(plan));
    }

    [Fact]
    public void Player_edits_to_mutable_profile_files_are_ignored()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = Install(root, bundle);
        File.WriteAllText(Path.Combine(plan.ProfileTargetDir, "config.txt"), "VR_WorldScale=1.100000");
        File.WriteAllText(Path.Combine(plan.ProfileTargetDir, @"uobjecthook\camera_state.json"), "{\"x\":42}");

        Assert.Null(new InstallVerifier(bundle).Verify(plan));
    }

    [Fact]
    public void Changed_plugin_is_reported_as_differing()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = Install(root, bundle);
        File.WriteAllText(Path.Combine(plan.ProfileTargetDir, @"plugins\SystemReShockVR.dll"), "old-dll");

        var issue = new InstallVerifier(bundle).Verify(plan);

        Assert.NotNull(issue);
        Assert.False(issue!.IsMissing);
        Assert.Contains("SystemReShockVR.dll", issue.Message);
    }

    [Fact]
    public void Changed_pak_is_reported_as_differing()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = Install(root, bundle);
        File.WriteAllText(Path.Combine(plan.PaksTargetDir, "SystemShockVRModCore_P.pak"), "core-v1");

        var issue = new InstallVerifier(bundle).Verify(plan);

        Assert.False(issue!.IsMissing);
        Assert.Contains("SystemShockVRModCore_P.pak", issue.Message);
    }

    [Fact]
    public void Missing_file_is_reported_as_missing()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = Install(root, bundle);
        File.Delete(Path.Combine(plan.ProfileTargetDir, "ProfileMeta.json"));

        var issue = new InstallVerifier(bundle).Verify(plan);

        Assert.True(issue!.IsMissing);
        Assert.Contains("ProfileMeta.json", issue.Message);
    }

    internal static InstallPlan Install(TempDir root, IModBundle bundle)
    {
        var plan = new InstallPlan(root.File("uevr"), root.File("game"), root.File("appdata"));
        new PakInstallStep(bundle).Execute(plan);
        new ProfileInstallStep(bundle).Execute(plan);
        return plan;
    }
}
