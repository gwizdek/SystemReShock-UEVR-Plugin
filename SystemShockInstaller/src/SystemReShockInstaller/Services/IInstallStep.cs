using System.Collections.Generic;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>One unit of installation work. Steps run in list order and stop at the first failure.</summary>
public interface IInstallStep
{
    string Title { get; }

    /// <summary>Human-readable lines shown on the confirmation page.</summary>
    IEnumerable<string> Describe(InstallPlan plan);

    void Execute(InstallPlan plan);
}
