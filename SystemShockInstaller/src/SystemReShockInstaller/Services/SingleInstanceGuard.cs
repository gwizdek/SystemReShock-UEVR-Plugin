using System;
using System.Threading;

namespace SystemReShockInstaller.Services;

/// <summary>
/// Holds a named mutex for as long as the app runs, so that a second copy can tell that one is
/// already open. Create it on the UI thread at startup and dispose it on exit, on the same thread.
/// </summary>
public sealed class SingleInstanceGuard : IDisposable
{
    private readonly Mutex _mutex;

    public SingleInstanceGuard(string name)
    {
        _mutex = new Mutex(initiallyOwned: true, name, out var createdNew);
        IsFirstInstance = createdNew;
    }

    /// <summary>False when another copy of the app already holds the mutex.</summary>
    public bool IsFirstInstance { get; }

    public void Dispose()
    {
        if (IsFirstInstance)
            _mutex.ReleaseMutex();
        _mutex.Dispose();
    }
}
