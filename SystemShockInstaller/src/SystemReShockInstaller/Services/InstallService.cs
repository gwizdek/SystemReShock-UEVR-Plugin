using System;
using System.Collections.Generic;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Runs install or uninstall steps in order and stops at the first failure. No rollback.</summary>
public sealed class InstallService
{
    public InstallService(IReadOnlyList<IInstallStep> steps) => Steps = steps;

    public IReadOnlyList<IInstallStep> Steps { get; }

    public IReadOnlyList<StepResult> Run(InstallPlan plan)
    {
        var results = new List<StepResult>(Steps.Count);
        var failed = false;
        foreach (var step in Steps)
        {
            var result = failed ? StepResult.Skipped(step.Title) : RunStep(step, plan);
            results.Add(result);
            failed |= !result.Succeeded;
        }
        return results;
    }

    private static StepResult RunStep(IInstallStep step, InstallPlan plan)
    {
        try
        {
            step.Execute(plan);
            return StepResult.Success(step.Title);
        }
        catch (Exception ex)
        {
            return StepResult.Failure(step.Title, InstallErrorFormatter.Format(ex));
        }
    }
}
