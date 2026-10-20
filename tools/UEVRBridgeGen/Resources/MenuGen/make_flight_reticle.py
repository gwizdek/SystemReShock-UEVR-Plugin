"""Writes CyberHud/T_CyberspaceFlightReticle.png, the cyberspace flight reticle for VR.

The game's T_CyberspaceFlightReticle is a 2048 x 2048 DXT5 texture: a large ring with side
bars, a small circle in the middle, two small triangles over the side bars and one triangle at
the top of the ring, the "up" marker. In VR only the top triangle is kept; every other pixel
is cleared. The plugin turns the reticle so the triangle points to world up.

The texture is read from the repository's asset dump. Its width and height are the two ints
16 and 12 bytes before the "PF_DXT5" format string, and its pixel data starts 32 bytes after
the string's end, the same layout export-cooked-texture.ps1 relies on for BGRA8 textures. The result is scaled to 1024 x 1024, which is the reticle's size in HUD units.

Needs Pillow:
    python make_flight_reticle.py
The PNG is written under CyberHud/ next to this script. GenerateMenu.ps1 imports it.
"""
import io
import os
import struct
import sys

from PIL import Image

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", "..", "..", ".."))
UEXP = os.path.join(REPO, "dumps", "assets", "SystemShock", "Content", "Art", "Cyberspace", "GUI",
                    "T_CyberspaceFlightReticle.uexp")
OUT = os.path.join(HERE, "CyberHud", "T_CyberspaceFlightReticle.png")
OUT_SIZE = 1024

# A point inside the top triangle and the alpha below which a pixel is empty, in the
# 2048 x 2048 source.
TRIANGLE_SEED = (1023, 320)
EMPTY_ALPHA = 8
MARGIN = 4


def read_dxt5(path):
    data = open(path, "rb").read()
    at = data.find(b"PF_DXT5")
    if at < 0:
        sys.exit(f"{path} is not a PF_DXT5 texture")
    # Width and height are the two ints before the string's length field.
    width, height = struct.unpack("<2i", data[at - 16:at - 8])
    start = at + len(b"PF_DXT5") + 1 + 32
    size = width * height  # DXT5: 16 bytes per 4 x 4 block
    if len(data) < start + size:
        sys.exit(f"{path} is smaller than {width}x{height} DXT5 needs")
    dds = b"DDS " + struct.pack("<7I", 124, 0x1 | 0x2 | 0x4 | 0x1000 | 0x80000, height, width, size, 0, 1)
    dds += b"\0" * 44 + struct.pack("<2I", 32, 0x4) + b"DXT5" + b"\0" * 20
    dds += struct.pack("<4I", 0x1000, 0, 0, 0) + b"\0" * 4
    image = Image.open(io.BytesIO(dds + data[start:start + size]))
    image.load()
    return image.convert("RGBA")


def triangle_box(alpha):
    """The box around every pixel connected to TRIANGLE_SEED, plus MARGIN."""
    pixels = alpha.load()
    width, height = alpha.size
    if pixels[TRIANGLE_SEED] <= EMPTY_ALPHA:
        sys.exit("The seed point is not inside the triangle; the texture has changed")
    seen = {TRIANGLE_SEED}
    stack = [TRIANGLE_SEED]
    while stack:
        x, y = stack.pop()
        for nx in (x - 1, x, x + 1):
            for ny in (y - 1, y, y + 1):
                if (nx, ny) not in seen and 0 <= nx < width and 0 <= ny < height and pixels[nx, ny] > EMPTY_ALPHA:
                    seen.add((nx, ny))
                    stack.append((nx, ny))
    xs = [p[0] for p in seen]
    ys = [p[1] for p in seen]
    return min(xs) - MARGIN, min(ys) - MARGIN, max(xs) + MARGIN + 1, max(ys) + MARGIN + 1


def main():
    source = read_dxt5(UEXP)
    box = triangle_box(source.getchannel("A"))
    result = Image.new("RGBA", source.size, (0, 0, 0, 0))
    result.paste(source.crop(box), box[:2])
    # Scaling with premultiplied alpha keeps the colour of the cleared pixels out of the edges.
    result = result.convert("RGBa").resize((OUT_SIZE, OUT_SIZE), Image.LANCZOS).convert("RGBA")
    os.makedirs(os.path.dirname(OUT), exist_ok=True)
    result.save(OUT)
    print(f"Triangle box in the {source.size[0]}x{source.size[1]} source: {box}. Wrote {OUT}")


if __name__ == "__main__":
    main()
