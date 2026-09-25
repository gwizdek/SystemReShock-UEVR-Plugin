using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Input;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.ViewModels;

public sealed class ResultViewModel : ViewModelBase
{
    public ResultViewModel(InstallPlan plan, IReadOnlyList<StepResult> results, Action finish)
    {
        Results = results;
        Succeeded = results.All(r => r.Succeeded);
        Headline = Succeeded ? "Installation complete" : "Installation failed";
        FinishText = Succeeded ? "Continue" : "Close";
        ProfileTargetDir = plan.ProfileTargetDir;
        PaksTargetDir = plan.PaksTargetDir;
        FinishCommand = new RelayCommand(finish);
    }

    public IReadOnlyList<StepResult> Results { get; }
    public bool Succeeded { get; }
    public string Headline { get; }
    public string FinishText { get; }
    public string ProfileTargetDir { get; }
    public string PaksTargetDir { get; }
    public ICommand FinishCommand { get; }

    public IReadOnlyList<string> NextSteps { get; } = new[]
    {
        "Press Continue to open the launcher. It starts the game and injects UEVR at the main menu for you.",
        "In the game options, reset the controller bindings to defaults.",
        "Save to new slots often.",
    };
}
