using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;

namespace SystemReShockInstaller.Views;

/// <summary>
/// Shows a text in a TextBlock with every version number in it, such as "v2.0-beta.3" or
/// "2.0-beta.4", in the Highlight brush and the rest unchanged. Use it in place of Text:
/// <c>views:VersionHighlight.Text="{Binding Notice}"</c>.
/// </summary>
public static class VersionHighlight
{
    private static readonly Regex VersionPattern =
        new(@"\bv?\d+(?:\.\d+)+(?:-[0-9A-Za-z]+(?:\.[0-9A-Za-z]+)*)?", RegexOptions.Compiled);

    public static readonly DependencyProperty TextProperty = DependencyProperty.RegisterAttached(
        "Text", typeof(string), typeof(VersionHighlight), new PropertyMetadata(null, OnTextChanged));

    public static string? GetText(DependencyObject element) => (string?)element.GetValue(TextProperty);

    public static void SetText(DependencyObject element, string? value) => element.SetValue(TextProperty, value);

    private static void OnTextChanged(DependencyObject element, DependencyPropertyChangedEventArgs e)
    {
        if (element is not TextBlock block) return;
        block.Inlines.Clear();
        var text = e.NewValue as string ?? string.Empty;
        var start = 0;
        foreach (Match match in VersionPattern.Matches(text))
        {
            if (match.Index > start) block.Inlines.Add(new Run(text.Substring(start, match.Index - start)));
            var version = new Run(match.Value);
            version.SetResourceReference(TextElement.ForegroundProperty, "Highlight");
            block.Inlines.Add(version);
            start = match.Index + match.Length;
        }
        if (start < text.Length) block.Inlines.Add(new Run(text.Substring(start)));
    }
}
