using System.Linq;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class ModBundleTests
{
    [Fact]
    public void Splits_paks_from_profile_entries()
    {
        using var bundle = TestBundle.Create();

        Assert.Equal(2, bundle.PakEntries.Count);
        Assert.Equal(4, bundle.ProfileEntries.Count);
        Assert.All(bundle.PakEntries, e => Assert.True(e.IsPak));
        Assert.DoesNotContain(bundle.ProfileEntries, e => e.IsPak);
    }

    [Fact]
    public void Entry_paths_use_backslashes_and_keep_subfolders()
    {
        using var bundle = TestBundle.Create();

        var plugin = bundle.ProfileEntries.Single(e => e.FileName == "SystemReShockVR.dll");
        Assert.Equal(@"plugins\SystemReShockVR.dll", plugin.RelativePath);
    }
}
