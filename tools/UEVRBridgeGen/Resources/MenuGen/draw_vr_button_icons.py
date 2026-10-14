"""Draws T_VRButtonLayout.png, a button atlas for VR controllers in the style of the game's
gamepad atlases (T_XboxButtonLayout and the others in Art/UI/Icons/ControllerButtons).

The game's atlases are 4 x 4 cells of 256 x 256 pixels, read by MAT_PlatformButton with the
parameters ButtonIndex, ColCount and RowCount. This atlas has 4 columns and 6 rows, so a
material instance must set RowCount to 6. The channels mean the same as in the game's atlases:

    R      the rim of the button, its label and arrows (drawn in the highlight tint)
    G      the face of the button (drawn in the background tint)
    B + A  a soft glow around the shape; B is 255 where the glow is, A is its strength
    A      255 inside the shape

The cells, left to right, top to bottom (ButtonIndex in brackets):

    [0] A         [1] B          [2] X          [3] Y
    [4] LT        [5] RT         [6] LG         [7] RG          (triggers, grips)
    [8] LS        [9] LS press   [10] RS        [11] RS press
    [12] LS up    [13] LS down   [14] LS left   [15] LS right
    [16] RS up    [17] RS down   [18] RS left   [19] RS right
    [20] Menu     [21] Point     [22] Grip      [23] empty      (menu button, hand poses)

The face buttons, the menu button and the plain and pressed sticks are copied pixel for pixel
from the Xbox atlas, and the labels of the new cells use its letters, so the line weight and
the glow are the game's own. The pointing hand is a hand-edited cell, read from
T_VRButtonLayout_HandPoint.png next to this script. The triggers and grips are outlines
traced from a reference sheet by trace_button_shapes.py (vr_button_shapes.json). The rest
is drawn from signed distance fields.

Needs numpy and Pillow:  python -m pip install numpy pillow
Reads the Xbox atlas from the cooked texture in the repository's asset dump:
    dumps\\assets\\SystemShock\\Content\\Art\\UI\\Icons\\ControllerButtons\\T_XboxButtonLayout.uexp
Run:  python draw_vr_button_icons.py [--preview]
Writes T_VRButtonLayout.png next to this script; --preview also writes
T_VRButtonLayout_preview.png, the cells tinted and scaled as the HUD shows them.
"""
import json
import os
import sys

import numpy as np
from PIL import Image

CELL = 256
COLS, ROWS = 4, 6
HERE = os.path.dirname(os.path.abspath(__file__))
# Outlines traced from a reference sheet by trace_button_shapes.py: name -> closed polygon in
# cell coordinates, 100 pixels wide and centred.
SHAPES = json.load(open(os.path.join(HERE, 'vr_button_shapes.json'), encoding='utf-8'))
REPO = os.path.abspath(os.path.join(HERE, '..', '..', '..', '..'))
XBOX_UEXP = os.path.join(REPO, 'dumps', 'assets', 'SystemShock', 'Content', 'Art', 'UI', 'Icons',
                         'ControllerButtons', 'T_XboxButtonLayout.uexp')

# Pixel centres of one cell.
Y, X = (np.mgrid[0:CELL, 0:CELL] + 0.5).astype(np.float64)

# Glow strength (alpha) against the distance from the shape's edge, measured on the A button
# of the Xbox atlas. Zero beyond 37.5 pixels.
GLOW_D = [0.0, 1.5, 3.5, 5.5, 7.5, 9.5, 11.5, 13.5, 15.5, 17.5, 19.5, 21.5, 23.5, 25.5, 27.5,
          29.5, 31.5, 33.5, 35.5, 37.5]
GLOW_A = [178, 164, 145, 126, 108, 92, 77, 63, 51, 41, 32, 24, 18, 12, 9, 6, 3, 2, 2, 0]

RIM = 6.5  # rim width of the game's buttons at the sides


# --- signed distance fields, negative inside -------------------------------------------------

def sd_circle(cx, cy, r):
    return np.hypot(X - cx, Y - cy) - r


def sd_ellipse(cx, cy, a, b):
    """First order distance (f / |grad f|): exact on the axes, close enough elsewhere."""
    nx, ny = (X - cx) / a, (Y - cy) / b
    n = np.hypot(nx, ny)
    grad = np.hypot(nx / a, ny / b)
    return (n - 1.0) * n / np.maximum(grad, 1e-9)


def sd_rbox(cx, cy, hw, hh, r):
    qx = np.abs(X - cx) - hw + r
    qy = np.abs(Y - cy) - hh + r
    return np.hypot(np.maximum(qx, 0), np.maximum(qy, 0)) + np.minimum(np.maximum(qx, qy), 0) - r


def sd_capsule(ax, ay, bx, by, r):
    px, py = X - ax, Y - ay
    ex, ey = bx - ax, by - ay
    t = np.clip((px * ex + py * ey) / (ex * ex + ey * ey), 0.0, 1.0)
    return np.hypot(px - ex * t, py - ey * t) - r


def sd_poly(pts):
    d = np.full(X.shape, 1e18)
    inside = np.zeros(X.shape, dtype=bool)
    for i in range(len(pts)):
        ax, ay = pts[i]
        bx, by = pts[i - 1]
        ex, ey = bx - ax, by - ay
        wx, wy = X - ax, Y - ay
        t = np.clip((wx * ex + wy * ey) / (ex * ex + ey * ey), 0.0, 1.0)
        d = np.minimum(d, (wx - ex * t) ** 2 + (wy - ey * t) ** 2)
        crossing = (Y >= ay) != (Y >= by)
        left = ex * wy > ey * wx
        inside ^= crossing & (left == (by > ay))
    return np.where(inside, -1.0, 1.0) * np.sqrt(d)


def union(*ds):
    return np.minimum.reduce(list(ds))


def cut(d, hole):
    return np.maximum(d, -hole)


def band(d, width):
    """A stroke of the given width centred on the outline of d."""
    return np.abs(d) - width / 2.0


def coverage(d):
    return np.clip(0.5 - d, 0.0, 1.0)


# --- cell composition -------------------------------------------------------------------------

def compose(solid, fill=None, glyph=None):
    """Builds one RGBA cell. solid is the SDF of the whole shape, fill the SDF of its face,
    glyph a 0..1 mask drawn in the rim colour on top of the face."""
    a_solid = coverage(solid)
    a_fill = coverage(fill) if fill is not None else np.zeros_like(a_solid)
    if glyph is not None:
        a_fill = a_fill * (1.0 - glyph)
    a_fill = np.minimum(a_fill, a_solid)
    outside = np.maximum(solid, 0.0)
    g = np.interp(outside, GLOW_D, GLOW_A) / 255.0 * (solid > 0)
    r = a_solid - a_fill
    b = (1.0 - a_solid) * (g > 0)
    a = np.maximum(a_solid, g)
    return to_rgba(r, a_fill, b, a)


def to_rgba(r, g, b, a):
    out = np.stack([r, g, b, a], axis=-1)
    return np.clip(np.round(out * 255.0), 0, 255).astype(np.uint8)


def overlay(base, layer):
    """Draws a composed layer over a cell. The layer's solid parts replace the base; its glow
    only adds where the base has no solid pixels."""
    base = base.astype(np.float64) / 255.0
    layer = layer.astype(np.float64) / 255.0
    base_solid = np.clip(base[..., 0] + base[..., 1], 0, 1)
    layer_solid = np.clip(layer[..., 0] + layer[..., 1], 0, 1)
    r = np.maximum(base[..., 0], layer[..., 0])
    g = np.maximum(base[..., 1], layer[..., 1])
    b = np.maximum(base[..., 2] * (1.0 - layer_solid), layer[..., 2] * (1.0 - base_solid))
    a = np.maximum(base[..., 3], layer[..., 3])
    return to_rgba(r, g, b, a)


def paste_glyph(mask, glyph, x, y):
    """Adds a 0..1 glyph image to the mask with its top left corner at (x, y)."""
    h, w = glyph.shape
    mask[y:y + h, x:x + w] = np.maximum(mask[y:y + h, x:x + w], glyph)
    return mask


def mirror(cell):
    return cell[:, ::-1].copy()


# --- the Xbox atlas: copied cells and letters ---------------------------------------------------

def read_xbox_atlas(path):
    """Reads the cooked BGRA8 texture; the pixels start 44 bytes after 'PF_B8G8R8A8'."""
    data = open(path, 'rb').read()
    at = data.find(b'PF_B8G8R8A8')
    if at < 0:
        raise SystemExit(path + ' is not a PF_B8G8R8A8 texture')
    width = int.from_bytes(data[at - 16:at - 12], 'little')
    height = int.from_bytes(data[at - 12:at - 8], 'little')
    pixels = np.frombuffer(data, dtype=np.uint8, count=width * height * 4, offset=at + 44)
    bgra = pixels.reshape(height, width, 4)
    return bgra[..., [2, 1, 0, 3]].copy()


def xbox_cell(atlas, index):
    r, c = divmod(index, 4)
    return atlas[r * CELL:(r + 1) * CELL, c * CELL:(c + 1) * CELL].copy()


def xbox_letter(atlas, index, x, y, w, h):
    """One label letter of an Xbox cell as a 0..1 mask: the R channel inside the given box,
    with the stroke of any neighbour letter removed."""
    cell = xbox_cell(atlas, index)
    crop = cell[y:y + h, x:x + w, 0].astype(np.float64) / 255.0
    return crop


# Letters of the Xbox labels "LT" (cell 8) and "RT" (cell 9): box of each letter in its cell.
LETTERS = {
    'L': (8, 102, 136, 17, 28),
    'T': (8, 119, 136, 21, 28),
    'R': (9, 112, 136, 23, 28),
}


def letter_g():
    """A G in the style of the atlas letters: 23 x 28, stroke 5, square corners outside,
    a gap at the top right and a bar into the centre."""
    yy, xx = (np.mgrid[0:28, 0:23] + 0.5).astype(np.float64)

    def rbox(cx, cy, hw, hh, r):
        qx = np.abs(xx - cx) - hw + r
        qy = np.abs(yy - cy) - hh + r
        return np.hypot(np.maximum(qx, 0), np.maximum(qy, 0)) + np.minimum(np.maximum(qx, qy), 0) - r

    def box(x0, y0, x1, y1):
        return np.maximum(np.maximum(x0 - xx, xx - x1), np.maximum(y0 - yy, yy - y1))

    outer = rbox(11.5, 14.0, 11.5, 14.0, 6.0)
    inner = rbox(11.5, 14.0, 6.5, 9.0, 2.0)
    ring = np.maximum(outer, -inner)
    ring = np.maximum(ring, -box(14.0, 4.5, 24.0, 11.0))   # the opening at the top right
    bar = box(11.5, 11.5, 23.0, 16.5)
    d = np.minimum(ring, bar)
    return np.clip(0.5 - d, 0.0, 1.0)


def label(atlas, text, x, y):
    """A 0..1 mask of the given label with its top left corner at (x, y). The letters are the
    Xbox atlas ones, 28 pixels tall, with a 2 pixel gap."""
    mask = np.zeros((CELL, CELL))
    for ch in text:
        if ch == 'G':
            glyph = letter_g()
        else:
            glyph = xbox_letter(atlas, *LETTERS[ch])
        paste_glyph(mask, glyph, x, y)
        x += glyph.shape[1] + 2
    return mask


def label_width(atlas, text):
    widths = [23 if ch == 'G' else LETTERS[ch][3] for ch in text]
    return sum(widths) + 2 * (len(text) - 1)


# --- the drawn cells ----------------------------------------------------------------------------

def flip_x(x):
    return CELL - x


def dome(cx, cy):
    """The round button of the Xbox atlas: outer and face SDFs. The face sits a little high,
    so the rim is thicker at the bottom."""
    return sd_ellipse(cx, cy, 48, 50), sd_ellipse(cx - 0.5, cy - 4.5, 41.5, 38.5)


def trigger(atlas, text):
    """A plectrum, traced from the reference sheet, with the label in its upper half. Both
    triggers use the RT outline; LT is its mirror image."""
    points = SHAPES['RT'] if text == 'RT' else [(flip_x(x), y) for x, y in SHAPES['RT']]
    body = sd_poly(points)
    x = int(round(128 - label_width(atlas, text) / 2.0))
    return compose(body, body + RIM, label(atlas, text, x, 104))


def grip(atlas, text):
    """A grip pad, traced from the reference sheet: an arched top, a bulging outer side and a
    hollow inner side, with the label in the middle."""
    body = sd_poly(SHAPES[text])
    x = int(round(128 - label_width(atlas, text) / 2.0))
    return compose(body, body + RIM, label(atlas, text, x, 114))


def arrow(direction, cx, cy):
    """A solid triangle 28 wide and 23 tall like the d-pad arrows, pointing in direction
    ('up', 'down', 'left', 'right'), with its base centre at (cx, cy)."""
    pts = {
        'up': [(cx - 14, cy), (cx + 14, cy), (cx, cy - 23)],
        'down': [(cx + 14, cy), (cx - 14, cy), (cx, cy + 23)],
        'left': [(cx, cy - 14), (cx, cy + 14), (cx - 23, cy)],
        'right': [(cx, cy + 14), (cx, cy - 14), (cx + 23, cy)],
    }[direction]
    return compose(sd_poly(pts))


def stick_direction(stick_cell, direction):
    """The plain stick cell of the Xbox atlas (solid 80..175 x 92..180) with an arrow 6 pixels
    outside it on the given side."""
    place = {
        'up': ('up', 127.5, 86), 'down': ('down', 127.5, 186),
        'left': ('left', 74, 136), 'right': ('right', 181, 136),
    }[direction]
    return overlay(stick_cell, arrow(*place))


def rebuild_glow(cell):
    """Replaces the glow of a hand-edited cell: keeps the rim and face pixels (R and G) and
    draws a new glow around them from the measured falloff, so a moved shape leaves no old
    glow behind."""
    f = cell.astype(np.float64) / 255.0
    a_solid = np.clip(f[..., 0] + f[..., 1], 0.0, 1.0)
    inside = a_solid > 0.5
    edge = inside & ~(np.roll(inside, 1, 0) & np.roll(inside, -1, 0) & np.roll(inside, 1, 1) & np.roll(inside, -1, 1))
    ey, ex = np.nonzero(edge)
    dist = np.full(a_solid.shape, 1e9)
    for y in range(CELL):
        dist[y] = np.sqrt((X[y][:, None] - ex - 0.5) ** 2 + (Y[y][:, None] - ey - 0.5) ** 2).min(axis=1)
    dist = np.where(inside, 0.0, np.maximum(dist - 0.5, 0.0))
    g = np.interp(dist, GLOW_D, GLOW_A) / 255.0 * ~inside
    b = (1.0 - a_solid) * (g > 0)
    return to_rgba(f[..., 0], f[..., 1], b, np.maximum(a_solid, g))


def hand_point():
    """The pointing pose: a hand-edited cell, read from T_VRButtonLayout_HandPoint.png next
    to this script (256 x 256 RGBA with the channels of the atlas). Only its rim and face
    pixels are used; the glow is rebuilt."""
    cell = np.array(Image.open(os.path.join(HERE, 'T_VRButtonLayout_HandPoint.png')).convert('RGBA'))
    if cell.shape != (CELL, CELL, 4):
        raise SystemExit('T_VRButtonLayout_HandPoint.png must be %d x %d RGBA' % (CELL, CELL))
    return rebuild_glow(cell)


def hand_grip():
    """The back of a closed hand: a low wave of four knuckles on top, short seams between the
    folded fingers and the thumb across the bottom: the grip pose."""
    palm = sd_rbox(128, 150, 44, 34, 18)
    knuckles = [sd_circle(x, 126, 14) for x in (96, 117, 138, 159)]
    thumb = sd_capsule(90, 168, 152, 170, 12)
    solid = union(palm, thumb, *knuckles)
    fill = union(palm + RIM, thumb + RIM, *[k + RIM for k in knuckles])
    seams = union(sd_capsule(106.5, 124, 106.5, 148, 2.5), sd_capsule(127.5, 122, 127.5, 148, 2.5),
                  sd_capsule(148.5, 124, 148.5, 148, 2.5), sd_capsule(92, 156, 156, 158, 2.5))
    return compose(solid, cut(fill, seams))


# --- the atlas ---------------------------------------------------------------------------------

def build_cells(atlas):
    ls, rs = xbox_cell(atlas, 12), xbox_cell(atlas, 14)
    cells = [xbox_cell(atlas, i) for i in (0, 1, 2, 3)]
    cells += [trigger(atlas, 'LT'), trigger(atlas, 'RT'), grip(atlas, 'LG'), grip(atlas, 'RG')]
    cells += [ls, xbox_cell(atlas, 13), rs, xbox_cell(atlas, 15)]
    cells += [stick_direction(ls, d) for d in ('up', 'down', 'left', 'right')]
    cells += [stick_direction(rs, d) for d in ('up', 'down', 'left', 'right')]
    cells += [xbox_cell(atlas, 5), hand_point(), hand_grip(), np.zeros((CELL, CELL, 4), np.uint8)]
    return cells


def assemble(cells):
    sheet = np.zeros((ROWS * CELL, COLS * CELL, 4), np.uint8)
    for i, cell in enumerate(cells):
        r, c = divmod(i, COLS)
        sheet[r * CELL:(r + 1) * CELL, c * CELL:(c + 1) * CELL] = cell
    return sheet


# --- preview ------------------------------------------------------------------------------------

HIGHLIGHT = np.array([0, 250, 129], np.float64)
FACE = np.array([0, 92, 52], np.float64)
GLOW = np.array([0, 150, 90], np.float64)
BACK = np.array([10, 22, 20], np.float64)


def tint(cell):
    """Colours a cell roughly as the HUD does: R in the highlight tint, G in the face tint,
    the glow in a darker tint, over the panel background."""
    f = cell.astype(np.float64) / 255.0
    r, g, b, a = f[..., 0], f[..., 1], f[..., 2], f[..., 3]
    colour = r[..., None] * HIGHLIGHT + g[..., None] * FACE + (b * a * 0.6)[..., None] * GLOW
    alpha = np.clip(r + g + b * a * 0.6, 0, 1)[..., None]
    return np.clip(colour + (1 - alpha) * BACK, 0, 255).astype(np.uint8)


def preview_row(cells, size):
    tiles = [Image.fromarray(tint(c)).resize((size, size), Image.BOX) for c in cells]
    row = Image.new('RGB', (len(tiles) * (size + 8) + 8, size + 16), tuple(BACK.astype(int)))
    for i, t in enumerate(tiles):
        row.paste(t, (8 + i * (size + 8), 8))
    return row


def write_preview(cells, atlas, path):
    rows = []
    for size in (38, 76, 128):
        rows.append(preview_row(cells[:12], size))
        rows.append(preview_row(cells[12:], size))
    rows.append(preview_row([xbox_cell(atlas, i) for i in range(16)], 38))
    width = max(r.width for r in rows)
    sheet = Image.new('RGB', (width, sum(r.height for r in rows)), tuple(BACK.astype(int)))
    y = 0
    for r in rows:
        sheet.paste(r, (0, y))
        y += r.height
    sheet.save(path)
    print('Wrote', path)


def main():
    atlas = read_xbox_atlas(XBOX_UEXP)
    cells = build_cells(atlas)
    out = os.path.join(HERE, 'T_VRButtonLayout.png')
    Image.fromarray(assemble(cells)).save(out)
    print('Wrote', out)
    if '--preview' in sys.argv:
        write_preview(cells, atlas, os.path.join(HERE, 'T_VRButtonLayout_preview.png'))


if __name__ == '__main__':
    main()
