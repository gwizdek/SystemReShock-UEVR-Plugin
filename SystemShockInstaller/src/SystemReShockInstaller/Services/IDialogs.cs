namespace SystemReShockInstaller.Services;

/// <summary>Modal message boxes, behind an interface so the pages can be tested without a window.</summary>
public interface IDialogs
{
    /// <summary>Yes/No question. True when the user picks Yes.</summary>
    bool Confirm(string title, string message);

    /// <summary>A notice with a single OK button.</summary>
    void Warn(string title, string message);
}
