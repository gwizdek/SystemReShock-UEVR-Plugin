using System.Windows;
using System.Windows.Controls;

namespace SystemReShockInstaller.Views;

/// <summary>
/// Frame shared by every page: a top bar with the page title as a breadcrumb, the page content
/// (optionally next to the Shodan artwork), and a bottom bar with the UEVR logo, an optional
/// status and the page's buttons. Its template lives in Frames.xaml.
/// </summary>
public sealed class PageFrame : ContentControl
{
    public static readonly DependencyProperty TitleProperty =
        DependencyProperty.Register(nameof(Title), typeof(string), typeof(PageFrame));

    public static readonly DependencyProperty ButtonBarProperty =
        DependencyProperty.Register(nameof(ButtonBar), typeof(object), typeof(PageFrame));

    public static readonly DependencyProperty StatusProperty =
        DependencyProperty.Register(nameof(Status), typeof(object), typeof(PageFrame));

    public static readonly DependencyProperty ShowsArtworkProperty =
        DependencyProperty.Register(nameof(ShowsArtwork), typeof(bool), typeof(PageFrame));

    public string? Title
    {
        get => (string?)GetValue(TitleProperty);
        set => SetValue(TitleProperty, value);
    }

    public object? ButtonBar
    {
        get => GetValue(ButtonBarProperty);
        set => SetValue(ButtonBarProperty, value);
    }

    /// <summary>Shown in the bottom bar next to the UEVR logo, for example "Installing...".</summary>
    public object? Status
    {
        get => GetValue(StatusProperty);
        set => SetValue(StatusProperty, value);
    }

    public bool ShowsArtwork
    {
        get => (bool)GetValue(ShowsArtworkProperty);
        set => SetValue(ShowsArtworkProperty, value);
    }
}
