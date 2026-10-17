using System.Windows;
using System.Windows.Media;

namespace SystemReShockInstaller.Views;

/// <summary>
/// Draws the frame of a button from the game's options menu (RESET / APPLY / BACK): a thick bar
/// on the left with cut corners, thin lines at the top and bottom, and a dark fill. Lines and fill
/// fade out to the right and there is no right edge. The sizes are in pixels, measured at 1:1 from
/// a 1920 x 1080 screenshot of the menu, so they stay the same at any button size.
/// </summary>
public sealed class ButtonChrome : FrameworkElement
{
    private const double BarWidth = 6.8;
    private const double TopLine = 1.75;
    private const double BottomLine = 1.9;
    private const double OuterTopCut = 5.5;
    private const double OuterBottomCut = 6.0;
    private const double InnerTopCutX = 3.4;
    private const double InnerTopCutY = 2.75;
    private const double InnerBottomCutX = 4.4;
    private const double InnerBottomCutY = 4.1;

    public static readonly DependencyProperty EdgeBrushProperty = DependencyProperty.Register(
        nameof(EdgeBrush), typeof(Brush), typeof(ButtonChrome),
        new FrameworkPropertyMetadata(Brushes.Green, FrameworkPropertyMetadataOptions.AffectsRender));

    public static readonly DependencyProperty FillBrushProperty = DependencyProperty.Register(
        nameof(FillBrush), typeof(Brush), typeof(ButtonChrome),
        new FrameworkPropertyMetadata(Brushes.Black, FrameworkPropertyMetadataOptions.AffectsRender));

    /// <summary>Where the fade starts, as a part of the width. The game's buttons start at 0.55.</summary>
    public static readonly DependencyProperty FadeStartProperty = DependencyProperty.Register(
        nameof(FadeStart), typeof(double), typeof(ButtonChrome),
        new FrameworkPropertyMetadata(0.55, FrameworkPropertyMetadataOptions.AffectsRender));

    public Brush EdgeBrush
    {
        get => (Brush)GetValue(EdgeBrushProperty);
        set => SetValue(EdgeBrushProperty, value);
    }

    public Brush FillBrush
    {
        get => (Brush)GetValue(FillBrushProperty);
        set => SetValue(FillBrushProperty, value);
    }

    public double FadeStart
    {
        get => (double)GetValue(FadeStartProperty);
        set => SetValue(FadeStartProperty, value);
    }

    protected override void OnRender(DrawingContext dc)
    {
        double width = ActualWidth, height = ActualHeight;
        if (width <= BarWidth * 3 || height <= OuterTopCut + OuterBottomCut) return;
        var inner = InnerFigure(width, height);
        dc.PushOpacityMask(FadeMask());
        dc.DrawGeometry(FillBrush, null, new PathGeometry(new[] { inner }));
        dc.DrawGeometry(EdgeBrush, null, new PathGeometry(new[] { OuterFigure(width, height), inner }) { FillRule = FillRule.EvenOdd });
        dc.Pop();
    }

    private LinearGradientBrush FadeMask()
    {
        var mask = new LinearGradientBrush { StartPoint = new Point(0, 0), EndPoint = new Point(1, 0) };
        mask.GradientStops.Add(new GradientStop(Colors.White, 0));
        mask.GradientStops.Add(new GradientStop(Colors.White, FadeStart));
        mask.GradientStops.Add(new GradientStop(Colors.Transparent, 1));
        return mask;
    }

    private static PathFigure OuterFigure(double width, double height) => Figure(
        new Point(OuterTopCut, 0),
        new Point(width, 0),
        new Point(width, height),
        new Point(OuterBottomCut, height),
        new Point(0, height - OuterBottomCut),
        new Point(0, OuterTopCut));

    /// <summary>The area inside the bar and the two lines, which also carries the fill.</summary>
    private static PathFigure InnerFigure(double width, double height)
    {
        double top = TopLine, bottom = height - BottomLine;
        return Figure(
            new Point(BarWidth + InnerTopCutX, top),
            new Point(width, top),
            new Point(width, bottom),
            new Point(BarWidth + InnerBottomCutX, bottom),
            new Point(BarWidth, bottom - InnerBottomCutY),
            new Point(BarWidth, top + InnerTopCutY));
    }

    private static PathFigure Figure(Point start, params Point[] points)
    {
        var figure = new PathFigure { StartPoint = start, IsClosed = true, IsFilled = true };
        figure.Segments.Add(new PolyLineSegment(points, false));
        return figure;
    }
}
