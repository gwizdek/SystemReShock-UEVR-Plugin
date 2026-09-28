using SystemReShockInstaller.Models;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class VrRuntimeTests
{
    [Theory]
    [InlineData(null, VrRuntime.OpenXR)]
    [InlineData("", VrRuntime.OpenXR)]
    [InlineData("garbage", VrRuntime.OpenXR)]
    [InlineData("openxr", VrRuntime.OpenXR)]
    [InlineData("OpenVR", VrRuntime.OpenVR)]
    public void Parses_settings_key_with_openxr_default(string? key, VrRuntime expected)
    {
        Assert.Equal(expected, VrRuntimes.Parse(key));
    }

    [Fact]
    public void Maps_to_uevr_loader_dlls_and_round_trips_keys()
    {
        Assert.Equal("openxr_loader.dll", VrRuntimes.DllName(VrRuntime.OpenXR));
        Assert.Equal("openvr_api.dll", VrRuntimes.DllName(VrRuntime.OpenVR));
        Assert.Equal(VrRuntime.OpenVR, VrRuntimes.Parse(VrRuntimes.Key(VrRuntime.OpenVR)));
    }
}
