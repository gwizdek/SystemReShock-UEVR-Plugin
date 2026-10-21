"""Traces button shapes out of a reference sheet and writes their outlines as point lists.

draw_vr_button_icons.py draws the triggers and grips from the outlines in
vr_button_shapes.json, which this script writes. The outlines came from a prompt sheet with
60 pixel cells: each cell is segmented into its shape (the near-black fill, the light outline
touching it, holes filled), upscaled, smoothed, traced with potrace into Bezier curves, and
the curves are sampled into a closed polygon in atlas cell coordinates (256 x 256, the shape
100 pixels wide and centred). The polygon is what the atlas script needs; it draws the rim
and the glow itself.

Needs potrace on the path (scoop install potrace), numpy and Pillow.
Run:  python trace_button_shapes.py <sheet.png> [--cell NAME=COL,ROW ...]
The sheet is read with 8 columns and 5 rows. Without --cell the four cells below are used.
"""
import json
import os
import re
import subprocess
import sys
import tempfile
from collections import deque

import numpy as np
from PIL import Image, ImageFilter

HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, 'vr_button_shapes.json')
COLUMNS, ROWS = 8, 5
DEFAULT_CELLS = {'RT': (2, 3), 'LG': (6, 0), 'RG': (7, 0)}   # LT is RT mirrored
UP = 8              # upscale before tracing
MARGIN = 6          # pixels around a cell, so a shape that touches the cell edge is whole
TARGET = 100.0      # width of a shape in the atlas cell
CELL = 256
STEP = 2.0          # spacing of the sampled outline points in atlas pixels


def cell_image(sheet, col, row):
    """One cell with a margin around it. The margin outside the sheet is magenta, a colour
    that is neither the dark fill nor the light outline."""
    w, h = sheet.size
    cw, ch = w / float(COLUMNS), h / float(ROWS)
    padded = Image.new('RGB', (w + 2 * MARGIN, h + 2 * MARGIN), (255, 0, 255))
    padded.paste(sheet, (MARGIN, MARGIN))
    box = (int(col * cw), int(row * ch), int((col + 1) * cw) + 2 * MARGIN, int((row + 1) * ch) + 2 * MARGIN)
    return padded.crop(box)


def shape_mask(cell):
    """The shape: the near-black fill plus the light outline touching it, holes filled, and
    only the piece under the cell centre (the margin can catch the neighbours)."""
    a = np.array(cell).astype(int)
    fill = a.max(axis=2) < 80
    light = (a.min(axis=2) > 140) & (np.ptp(a, axis=2) < 45)
    near = np.array(Image.fromarray((fill * 255).astype(np.uint8)).filter(ImageFilter.MaxFilter(7))) > 0
    solid = fill | (light & near)
    outside = flood(~solid, border_seeds(solid.shape))
    return component(~outside, (solid.shape[0] // 2, solid.shape[1] // 2))


def border_seeds(shape):
    h, w = shape
    return [(y, x) for y in range(h) for x in (0, w - 1)] + [(y, x) for x in range(w) for y in (0, h - 1)]


def flood(free, seeds):
    """Pixels of 'free' reachable from the seeds."""
    h, w = free.shape
    seen = np.zeros_like(free)
    q = deque(s for s in seeds if free[s])
    for s in q:
        seen[s] = True
    while q:
        y, x = q.popleft()
        for n in ((y - 1, x), (y + 1, x), (y, x - 1), (y, x + 1)):
            if 0 <= n[0] < h and 0 <= n[1] < w and free[n] and not seen[n]:
                seen[n] = True
                q.append(n)
    return seen


def component(mask, seed):
    if not mask[seed]:
        raise SystemExit('no shape under the cell centre')
    return flood(mask, [seed])


def trace(mask):
    """Upscales and smooths the mask, traces it with potrace, returns the SVG path data."""
    big = Image.fromarray((mask * 255).astype(np.uint8)).resize((mask.shape[1] * UP, mask.shape[0] * UP), Image.LANCZOS)
    big = big.filter(ImageFilter.GaussianBlur(UP * 0.9))
    bw = big.point(lambda v: 0 if v > 128 else 255).convert('1')    # potrace traces black
    with tempfile.TemporaryDirectory() as tmp:
        pbm, svg = os.path.join(tmp, 'shape.pbm'), os.path.join(tmp, 'shape.svg')
        bw.save(pbm)
        subprocess.run(['potrace', pbm, '-s', '-o', svg, '-a', '1.3', '-O', '0.4', '-t', '40'], check=True)
        text = open(svg, encoding='utf-8').read()
    paths = re.findall(r'<path[^>]*d="([^"]+)"', text)
    height = float(re.search(r'height="([\d.]+)pt"', text).group(1))
    return paths, height


def bezier(p0, p1, p2, p3, t):
    u = 1.0 - t
    return (u * u * u * p0[0] + 3 * u * u * t * p1[0] + 3 * u * t * t * p2[0] + t * t * t * p3[0],
            u * u * u * p0[1] + 3 * u * u * t * p1[1] + 3 * u * t * t * p2[1] + t * t * t * p3[1])


def sample_path(d, height):
    """Samples potrace's path (an absolute M, then relative c, l and z, in 1/10 pt with y up)
    into points in upscaled mask pixels, y down. Only the outer contour is used."""
    tokens = re.findall(r'[MmCcLlZz]|-?[\d.]+', d)
    pts, cur, i = [], (0.0, 0.0), 0
    while i < len(tokens):
        cmd = tokens[i]
        i += 1
        if cmd in 'Zz':
            break
        nums = []
        while i < len(tokens) and tokens[i] not in 'MmCcLlZz':
            nums.append(float(tokens[i]))
            i += 1
        absolute = cmd.isupper()
        if cmd in 'Mm':
            cur = (nums[0], nums[1]) if absolute else (cur[0] + nums[0], cur[1] + nums[1])
            pts.append(cur)
            nums = nums[2:]
            cmd = 'L' if absolute else 'l'
        if cmd in 'Ll':
            for k in range(0, len(nums), 2):
                cur = (nums[k], nums[k + 1]) if absolute else (cur[0] + nums[k], cur[1] + nums[k + 1])
                pts.append(cur)
        elif cmd in 'Cc':
            for k in range(0, len(nums), 6):
                base = (0.0, 0.0) if absolute else cur
                p1 = (base[0] + nums[k], base[1] + nums[k + 1])
                p2 = (base[0] + nums[k + 2], base[1] + nums[k + 3])
                p3 = (base[0] + nums[k + 4], base[1] + nums[k + 5])
                for s in range(1, 9):
                    pts.append(bezier(cur, p1, p2, p3, s / 8.0))
                cur = p3
    return [(x / 10.0, height - y / 10.0) for x, y in pts]


def area(points):
    return abs(sum(a[0] * b[1] - b[0] * a[1] for a, b in zip(points, points[1:] + points[:1]))) / 2.0


def to_cell(points):
    """Scales the outline to TARGET pixels wide, centres it in the cell, and resamples it at
    STEP pixel spacing."""
    xs, ys = [p[0] for p in points], [p[1] for p in points]
    scale = TARGET / (max(xs) - min(xs))
    cx, cy = (max(xs) + min(xs)) / 2.0, (max(ys) + min(ys)) / 2.0
    scaled = [((x - cx) * scale + CELL / 2.0, (y - cy) * scale + CELL / 2.0) for x, y in points]
    out, acc = [scaled[0]], 0.0
    for a, b in zip(scaled, scaled[1:] + scaled[:1]):
        acc += ((b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2) ** 0.5
        if acc >= STEP:
            out.append(b)
            acc = 0.0
    return [(round(x, 2), round(y, 2)) for x, y in out]


def main():
    if len(sys.argv) < 2:
        raise SystemExit(__doc__)
    sheet = Image.open(sys.argv[1]).convert('RGB')
    cells = dict(DEFAULT_CELLS)
    for arg in sys.argv[2:]:
        if arg.startswith('--cell'):
            continue
        name, pos = arg.split('=')
        cells[name] = tuple(int(v) for v in pos.split(','))
    shapes = {}
    for name, (col, row) in cells.items():
        paths, height = trace(shape_mask(cell_image(sheet, col, row)))
        # potrace may list a speck first; the shape is the contour with the largest area
        outline = max((sample_path(d, height) for d in paths), key=area)
        shapes[name] = to_cell(outline)
        print(name, len(shapes[name]), 'points')
    with open(OUT, 'w', encoding='utf-8', newline='\r\n') as f:
        json.dump(shapes, f, indent=1)
    print('Wrote', OUT)


if __name__ == '__main__':
    main()
