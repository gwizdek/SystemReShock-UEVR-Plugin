"""Writes the texts of the game's tutorial popups as an ini file.

The texts are the rows of the data table /Game/Blueprints/Interactables/Triggers/DT_Tutorials.
Each row has one FText, DisplayMessage, whose source string is what the popup shows (the
English locres has no entry for these texts). The script reads the cooked asset from the
repository's asset dump and writes one line per row, "RowName = text", under [tutorials].

Run from the repository root:
    python scripts\\export-tutorial-texts.py [out.ini]
Without a path the ini goes to standard output. profile\\tutorial_messages.ini was made this
way and is edited by hand after that, so do not overwrite it without looking at its changes.
"""
import os
import struct
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ASSET = os.path.join(REPO, 'dumps', 'assets', 'SystemShock', 'Content', 'Blueprints', 'Interactables',
                     'Triggers', 'DT_Tutorials')
PACKAGE_TAG = 0x9E2A83C1

HEADER = """; Tutorial popup texts, one line per row of the game's table DT_Tutorials.
; Written by scripts\\export-tutorial-texts.py from the game's asset; the texts are the game's own.
; Edit the text after '=' to change what a popup shows. Keep the row name as it is.
; {Real_Interact} and the like are button placeholders; documentation\\tutorial-popups.md
; explains them.
"""


def i32(data, at):
    return struct.unpack_from('<i', data, at)[0]


def fstring(data, at):
    """An FString: int32 length (negative for UTF-16), the characters, a zero terminator."""
    n = i32(data, at)
    at += 4
    if n < 0:
        return data[at:at - 2 * n - 2].decode('utf-16-le'), at - 2 * n
    return (data[at:at + n - 1].decode('latin-1') if n else ''), at + n


def read_names(uasset):
    """The name table of a UE 4.27 package: its count and offset are in the summary."""
    if struct.unpack_from('<I', uasset, 0)[0] != PACKAGE_TAG:
        raise SystemExit('not a package: ' + ASSET + '.uasset')
    at = 8 if i32(uasset, 4) == -4 else 12       # tag, legacy version, [UE3 version]
    at += 8                                       # UE4 version, licensee version
    at += 4 + 20 * i32(uasset, at)                # custom versions
    at += 4                                       # total header size
    _, at = fstring(uasset, at)                   # folder name
    at += 4                                       # package flags
    count, offset = i32(uasset, at), i32(uasset, at + 4)
    names = []
    for _ in range(count):
        name, offset = fstring(uasset, offset)
        offset += 4                               # two 16 bit hashes
        names.append(name)
    return names


def fname(data, at, names):
    index, number = i32(data, at), i32(data, at + 4)
    name = names[index]
    return (name if number == 0 else '%s_%d' % (name, number - 1)), at + 8


def ftext(data, at):
    """An FText payload: flags, history type, then namespace, key and source string."""
    at += 4
    history = struct.unpack_from('<b', data, at)[0]
    at += 1
    if history == 0:
        _, at = fstring(data, at)
        _, at = fstring(data, at)
        return fstring(data, at)[0]
    if history == -1:
        if i32(data, at):
            return fstring(data, at + 4)[0]
        return ''
    raise SystemExit('unexpected FText history type %d' % history)


def skip_properties(data, at, names, on_text=None):
    """Walks tagged properties up to the None terminator. on_text gets each TextProperty."""
    while True:
        name, at = fname(data, at, names)
        if name == 'None':
            return at
        kind, at = fname(data, at, names)
        size = i32(data, at)
        at += 8                                   # size, array index
        at += 1                                   # property guid flag
        if kind == 'TextProperty' and on_text:
            on_text(ftext(data, at))
        at += size


def read_rows():
    names = read_names(open(ASSET + '.uasset', 'rb').read())
    uexp = open(ASSET + '.uexp', 'rb').read()
    at = skip_properties(uexp, 0, names)          # the table's own properties (RowStruct)
    at += 4                                       # no object guid
    count = i32(uexp, at)
    at += 4
    rows = []
    for _ in range(count):
        row_name, at = fname(uexp, at, names)
        texts = []
        at = skip_properties(uexp, at, names, texts.append)
        rows.append((row_name, texts[0] if texts else ''))
    return rows


def main():
    lines = [HEADER, '[tutorials]']
    lines += ['%s = %s' % (name, text) for name, text in read_rows()]
    out = '\n'.join(lines) + '\n'
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'w', encoding='utf-8', newline='\r\n') as f:
            f.write(out)
        print('Wrote', sys.argv[1], 'with', len(lines) - 2, 'rows')
    else:
        sys.stdout.write(out)


if __name__ == '__main__':
    main()
