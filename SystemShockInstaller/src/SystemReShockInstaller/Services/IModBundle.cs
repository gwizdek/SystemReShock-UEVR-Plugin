using System.Collections.Generic;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

public interface IModBundle
{
    IReadOnlyList<BundleEntry> ProfileEntries { get; }
    IReadOnlyList<BundleEntry> PakEntries { get; }
}
