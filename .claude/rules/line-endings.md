# Line Ending Rules

> These rules apply whenever a file is created or edited in this repository.

## How the repository stores line endings

`.gitattributes` sets `* text=auto`. Git stores every text file with LF and converts on
checkout to the line ending of the machine:

| Machine | `core.autocrlf` | Working copy |
|---|---|---|
| This Windows machine | `true` | CRLF |
| Linux, macOS | unset | LF |

So the same file is CRLF here and LF on a Linux checkout, and both are correct. What matters
is that a file keeps one ending throughout and that a new file matches the files next to it.
A mixed file or an LF file among CRLF files shows up as a whole-file change in diffs and in
Visual Studio.

## Before writing a new file

1. Check the ending of a sibling file of the same kind:

   ```powershell
   git ls-files --eol SystemShockVR\plugin.cpp
   ```

   `w/crlf` means the working copy uses CRLF, `w/lf` means LF. `i/lf` is the stored form
   and is always LF here.

2. Write the new file with that ending. The Write tool and most scripts write LF, so on this
   machine convert after writing, for example in Python with `newline=''` on read and write,
   or with `(Get-Content f -Raw) -replace "`r?`n", "`r`n" | Set-Content f -NoNewline` in
   PowerShell.

3. Check the result the same way. `git status` showing the file as modified right after the
   conversion is only stale stat data; `git diff` must be empty.

## When editing an existing file

Keep the file's ending. Read and write with `newline=''` in Python, and use `\r\n` in
replacement strings when the file is CRLF. Never let a tool rewrite the whole file with a
different ending; that hides the real change in the diff.

## Exceptions

The generated files under `SystemShockVR\BridgeSDK\` are written by the generator, most of
them with LF. Leave them as the generator makes them. The Dumper-7 files under
`SystemShockVR\SDK\` are CRLF like the rest of the plugin.
