using System;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class SingleInstanceGuardTests
{
    private static string UniqueName() => @"Local\SystemReShockVRModTest-" + Guid.NewGuid().ToString("N");

    [Fact]
    public void Second_guard_with_the_same_name_is_not_the_first_instance()
    {
        var name = UniqueName();
        using var first = new SingleInstanceGuard(name);
        using var second = new SingleInstanceGuard(name);

        Assert.True(first.IsFirstInstance);
        Assert.False(second.IsFirstInstance);
    }

    [Fact]
    public void Name_is_free_again_after_the_first_guard_is_disposed()
    {
        var name = UniqueName();
        new SingleInstanceGuard(name).Dispose();

        using var next = new SingleInstanceGuard(name);

        Assert.True(next.IsFirstInstance);
    }
}
