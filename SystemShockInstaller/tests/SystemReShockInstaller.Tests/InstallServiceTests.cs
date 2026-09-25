using System;
using System.Collections.Generic;
using System.IO;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class InstallServiceTests
{
    private static readonly InstallPlan Plan = new(@"C:\uevr", @"C:\game", @"C:\appdata");

    [Fact]
    public void Runs_all_steps_in_order_when_everything_succeeds()
    {
        var log = new List<string>();
        var service = new InstallService(new[] { new FakeStep("a", log), new FakeStep("b", log) });

        var results = service.Run(Plan);

        Assert.Equal(new[] { "a", "b" }, log);
        Assert.All(results, r => Assert.True(r.Succeeded));
    }

    [Fact]
    public void Stops_after_first_failure_and_marks_rest_skipped()
    {
        var log = new List<string>();
        var service = new InstallService(new IInstallStep[]
        {
            new FakeStep("a", log),
            new FakeStep("b", log, new UnauthorizedAccessException("Access to the path is denied.")),
            new FakeStep("c", log),
        });

        var results = service.Run(Plan);

        Assert.Equal(new[] { "a", "b" }, log);
        Assert.True(results[0].Succeeded);
        Assert.False(results[1].Succeeded);
        Assert.Contains("administrator", results[1].Error);
        Assert.False(results[2].Succeeded);
        Assert.Contains("Skipped", results[2].Error);
    }

    [Fact]
    public void Formats_sharing_violation_as_file_in_use()
    {
        var ex = new IOException("locked", unchecked((int)0x80070020));

        Assert.StartsWith("A file is in use.", InstallErrorFormatter.Format(ex));
    }

    private sealed class FakeStep : IInstallStep
    {
        private readonly List<string> _log;
        private readonly Exception? _throw;

        public FakeStep(string title, List<string> log, Exception? toThrow = null)
        {
            Title = title;
            _log = log;
            _throw = toThrow;
        }

        public string Title { get; }

        public IEnumerable<string> Describe(InstallPlan plan) => Array.Empty<string>();

        public void Execute(InstallPlan plan)
        {
            _log.Add(Title);
            if (_throw != null)
                throw _throw;
        }
    }
}
