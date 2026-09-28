using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Input;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.ViewModels;

public sealed class ResultViewModel : ViewModelBase
{
    private ResultViewModel(InstallPlan plan, IReadOnlyList<StepResult> results, Action finish, string headline, string finishText, IReadOnlyList<string> nextSteps)
    {
        Results = results;
        Succeeded = results.All(r => r.Succeeded);
        Headline = headline;
        FinishText = finishText;
        NextSteps = nextSteps;
        ProfileTargetDir = plan.ProfileTargetDir;
        PaksTargetDir = plan.PaksTargetDir;
        FinishCommand = new RelayCommand(finish);
    }

    public static ResultViewModel ForInstall(InstallPlan plan, IReadOnlyList<StepResult> results, Action finish)
    {
        var succeeded = results.All(r => r.Succeeded);
        return new ResultViewModel(plan, results, finish,
            succeeded ? "Installation complete" : "Installation failed",
            succeeded ? "Continue" : "Close",
            InstallNextSteps);
    }

    /// <summary>After an uninstall there is nothing left to launch, so the only way out is Close.</summary>
    public static ResultViewModel ForUninstall(InstallPlan plan, IReadOnlyList<StepResult> results, Action close)
    {
        var succeeded = results.All(r => r.Succeeded);
        return new ResultViewModel(plan, results, close,
            succeeded ? "Mod removed" : "Removal failed",
            "Close",
            System.Array.Empty<string>());
    }

    public IReadOnlyList<StepResult> Results { get; }
    public bool Succeeded { get; }
    public string Headline { get; }
    public string FinishText { get; }
    public string ProfileTargetDir { get; }
    public string PaksTargetDir { get; }
    public ICommand FinishCommand { get; }

    public IReadOnlyList<string> NextSteps { get; }

    private static readonly string[] InstallNextSteps =
    {
        "Press Continue to open the launcher. It starts the game and injects UEVR at the main menu for you.",
        "In the game options, reset the controller bindings to defaults.",
        "Save to new slots often.",
    };
}
