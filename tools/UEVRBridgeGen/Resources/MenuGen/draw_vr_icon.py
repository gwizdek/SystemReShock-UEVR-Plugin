"""Draws T_OptionsIcons_VR.png, the VR category icon of the options screen.

The game's category icons are white silhouettes on black, 256 x 256, filling the square to a
few pixels from the edge. Each game icon sits in one colour channel of a packed texture; this
one is written to R, G and B alike, with alpha 255, and the material reads R.

The shape: a chamfered headset body, strap tabs on both sides behind an 8 px gap ring (the
ring of the game's Gameplay icon), two round lenses and a nose notch, all cut as negative space.

Run with plain Python 3, no packages needed:
    python draw_vr_icon.py
The PNG is written next to this script. GenerateMenu.ps1 imports it.
"""
import math
import os
import struct
import zlib

SIZE = 256


def sd_poly(p, pts):
    """Signed distance to a polygon, negative inside."""
    x, y = p
    d = 1e9
    s = 1.0
    for i in range(len(pts)):
        ax, ay = pts[i]
        bx, by = pts[i - 1]
        ex, ey = bx - ax, by - ay
        wx, wy = x - ax, y - ay
        t = max(0.0, min(1.0, (wx * ex + wy * ey) / (ex * ex + ey * ey)))
        dx, dy = wx - ex * t, wy - ey * t
        d = min(d, dx * dx + dy * dy)
        c1, c2, c3 = y >= ay, y < by, ex * wy > ey * wx
        if (c1 and c2 and c3) or (not c1 and not c2 and not c3):
            s = -s
    return s * math.sqrt(d)


def sd_circle(p, c, r):
    return math.hypot(p[0] - c[0], p[1] - c[1]) - r


def chamfer(x0, y0, x1, y1, c):
    return [(x0 + c, y0), (x1 - c, y0), (x1, y0 + c), (x1, y1 - c), (x1 - c, y1), (x0 + c, y1), (x0, y1 - c), (x0, y0 + c)]


def coverage(d):
    """One pixel of anti-aliasing across the edge."""
    return max(0.0, min(1.0, 0.5 - d))


BODY = chamfer(28, 64, 228, 192, 30)
TAB_LEFT = chamfer(4, 100, 40, 156, 10)
TAB_RIGHT = chamfer(216, 100, 252, 156, 10)
NOSE = [(98, 193), (116, 150), (140, 150), (158, 193)]
GAP = 8


def shape(p):
    body = sd_poly(p, BODY)
    a = coverage(min(sd_poly(p, TAB_LEFT), sd_poly(p, TAB_RIGHT)))
    a = min(a, 1 - coverage(body - GAP))
    a = max(a, coverage(body))
    nose = min(sd_poly(p, NOSE), sd_circle(p, (128, 154), 12))
    a = min(a, 1 - coverage(nose))
    lenses = min(sd_circle(p, (80, 116), 27), sd_circle(p, (176, 116), 27))
    return min(a, 1 - coverage(lenses))


def write_png(path, rows):
    raw = b''.join(b'\x00' + bytes(r) for r in rows)

    def chunk(tag, data):
        return struct.pack('>I', len(data)) + tag + data + struct.pack('>I', zlib.crc32(tag + data) & 0xffffffff)

    header = struct.pack('>IIBBBBB', SIZE, SIZE, 8, 6, 0, 0, 0)  # 8 bit RGBA
    with open(path, 'wb') as f:
        f.write(b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', header) + chunk(b'IDAT', zlib.compress(raw, 9)) + chunk(b'IEND', b''))


def main():
    rows = []
    for y in range(SIZE):
        row = bytearray()
        for x in range(SIZE):
            v = int(round(255 * shape((x + 0.5, y + 0.5))))
            row += bytes((v, v, v, 255))
        rows.append(row)
    path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'T_OptionsIcons_VR.png')
    write_png(path, rows)
    print('Wrote', path)


if __name__ == '__main__':
    main()
