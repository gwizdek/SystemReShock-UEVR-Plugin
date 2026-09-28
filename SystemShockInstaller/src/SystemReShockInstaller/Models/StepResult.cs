namespace SystemReShockInstaller.Models;

public sealed class StepResult
{
    private StepResult(string title, bool succeeded, string? error)
    {
        Title = title;
        Succeeded = succeeded;
        Error = error;
    }

    public string Title { get; }
    public bool Succeeded { get; }
    public string? Error { get; }

    public static StepResult Success(string title) => new StepResult(title, true, null);
    public static StepResult Failure(string title, string error) => new StepResult(title, false, error);
    public static StepResult Skipped(string title) => new StepResult(title, false, "Skipped because an earlier step failed.");
}
