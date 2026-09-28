using System.IO;
using System.Linq;
using System.Security.Cryptography;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>The first problem found when checking an installation, or null when everything is in place.</summary>
public sealed class InstallIssue
{
    public InstallIssue(string message, bool isMissing)
    {
        Message = message;
        IsMissing = isMissing;
    }

    public string Message { get; }

    /// <summary>True when a file is absent; false when it exists but its content differs.</summary>
    public bool IsMissing { get; }
}

/// <summary>
/// Compares the embedded bundle with the installed files. Paks and plugins must match byte for byte.
/// Other profile files only have to exist, because UEVR rewrites them while the player changes settings.
/// </summary>
public sealed class InstallVerifier
{
    private readonly IModBundle _bundle;

    public InstallVerifier(IModBundle bundle) => _bundle = bundle;

    public InstallIssue? Verify(InstallPlan plan)
    {
        var paks = _bundle.PakEntries.Select(e => Check(e, Path.Combine(plan.PaksTargetDir, e.FileName)));
        var profile = _bundle.ProfileEntries.Select(e => Check(e, Path.Combine(plan.ProfileTargetDir, e.RelativePath)));
        return paks.Concat(profile).FirstOrDefault(issue => issue != null);
    }

    private static InstallIssue? Check(BundleEntry entry, string target)
    {
        if (!File.Exists(target))
            return new InstallIssue(entry.RelativePath + " is missing.", isMissing: true);
        if (entry.HasStableContent && !SameContent(entry, target))
            return new InstallIssue(entry.RelativePath + " differs from the version in this setup.", isMissing: false);
        return null;
    }

    private static bool SameContent(BundleEntry entry, string target)
    {
        using var sha = SHA256.Create();
        using var bundled = entry.Open();
        using var installed = File.OpenRead(target);
        var expected = sha.ComputeHash(bundled);
        return expected.SequenceEqual(sha.ComputeHash(installed));
    }
}
