"""Writes the I.C.E. drill lock-on textures for VR next to this script.

The lock-on's arcs (T_ICEDrillReticle_LockOnBracket, 512 x 512) and chevrons
(T_ICEDrillReticle_LockOnPointer, 256 x 256) have a soft glow around the line in their alpha
(A) and a wide band around it in B. Where the glow has no line colour (R), the materials draw
black, so in VR, where the plugin shows the lock-on in the world, the glow looks like a thick
dark outline. Here A and B are cut down to a thin rim around the line: the line (R) widened by
a few pixels and softened, never more than the game's values. R and G stay as they are.

The textures are read from the repository's asset dump. They are uncompressed BGRA8 with one
mip, laid out as export-cooked-texture.ps1 describes.

Needs Pillow:
    python make_ice_drill_reticle.py
GenerateAssets.ps1 imports the PNGs.
"""
import os
import struct
import sys

from PIL import Image, ImageChops, ImageFilter

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", "..", "..", ".."))
GUI = os.path.join(REPO, "dumps", "assets", "SystemShock", "Content", "Art", "Cyberspace", "GUI")

# Texture name and how far the rim reaches beyond the line, in that texture's pixels.
TEXTURES = (
    ("T_ICEDrillReticle_LockOnBracket", 2),
    ("T_ICEDrillReticle_LockOnPointer", 1),
)
LINE_THRESHOLD = 64
SOFTEN_RADIUS = 0.5


def read_bgra8(path):
    data = open(path, "rb").read()
    tag = b"PF_B8G8R8A8"
    at = data.find(tag)
    if at < 0:
        sys.exit(f"{path} is not a PF_B8G8R8A8 texture")
    width, height = struct.unpack("<2i", data[at - 16:at - 8])
    start = at + len(tag) + 1 + 32
    if len(data) < start + width * height * 4:
        sys.exit(f"{path} is smaller than {width}x{height} BGRA8 needs")
    return Image.frombytes("RGBA", (width, height), data[start:start + width * height * 4], "raw", "BGRA")


def thin_rim(image, rim):
    r, g, b, a = image.split()
    line = r.point(lambda v: 255 if v > LINE_THRESHOLD else 0)
    widened = line.filter(ImageFilter.MaxFilter(2 * rim + 1)).filter(ImageFilter.GaussianBlur(SOFTEN_RADIUS))
    return Image.merge("RGBA", (r, g, ImageChops.darker(widened, b), ImageChops.darker(widened, a)))


def main():
    for name, rim in TEXTURES:
        result = thin_rim(read_bgra8(os.path.join(GUI, name + ".uexp")), rim)
        out = os.path.join(HERE, name + ".png")
        result.save(out)
        print(f"{name}: A and B cut to a {rim} px rim around the line. Wrote {out}")


if __name__ == "__main__":
    main()
