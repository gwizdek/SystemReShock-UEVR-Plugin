"""Builds a release of the mod as a UEVR profile zip.

Usage:
    python scripts\\release-plugin.py 2.0-beta.4 [--pak-dir <folder>]

Steps:
    1. Sets the version: InformationalVersion in the installer project (the plugin build reads
       it from there) and "remarks" and "modifiedDate" in profile\\ProfileMeta.json.
    2. Builds the plugin (Release x64).
    3. Stages the profile the way the installer build fills mod_files\\: every profile file except
       imgui.ini, the plugin DLL in plugins\\, and the Core pak in paks\\.
    4. Zips the staged files into
       releases\\<version>_<timestamp>\\SystemReShock-Win64-Shipping.zip.

The Unreal project is not packaged. The Core pak is taken as it is from --pak-dir.
"""

import argparse
import re
import shutil
import subprocess
import sys
import tempfile
import zipfile
from datetime import datetime
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
INSTALLER_PROJECT = REPO / "SystemShockInstaller" / "src" / "SystemReShockInstaller" / "SystemReShockInstaller.csproj"
PLUGIN_PROJECT = REPO / "SystemShockVR" / "SystemShockVR.vcxproj"
PLUGIN_DLL = REPO / "SystemShockVR" / "x64" / "Release" / "SystemReShockVR.dll"
BUILD_INDEX = REPO / "SystemShockVR" / "build_index.txt"
PROFILE_DIR = REPO / "profile"
PROFILE_META = PROFILE_DIR / "ProfileMeta.json"
RELEASES_DIR = REPO / "releases"
DEFAULT_PAK_DIR = Path(r"D:\Unreal Engine\Projects\SystemReShock-UE4-Project\WindowsNoEditor\SystemShock\Content\Paks")

CORE_PAK_SOURCE = "pakchunk10-WindowsNoEditor.pak"
CORE_PAK_TARGET = "SystemShockVRModCore_P.pak"
ADDON_PAK = "SystemShockVRModAddon_P.pak"
# Profile files that must not ship, as in the installer project. imgui.ini is UEVR's per-user window layout.
PROFILE_EXCLUDE = {"imgui.ini"}
ZIP_NAME = "SystemReShock-Win64-Shipping.zip"
VERSION_PATTERN = re.compile(r"^\d+\.\d+(\.\d+)?(-[0-9A-Za-z]+(\.[0-9A-Za-z]+)*)?$")


class ReleaseError(Exception):
    pass


def parse_args():
    parser = argparse.ArgumentParser(description="Build a release of the mod as a UEVR profile zip.")
    parser.add_argument("version", help="Release version, for example 2.0-beta.4")
    parser.add_argument("--pak-dir", type=Path, default=DEFAULT_PAK_DIR,
                        help=f"Folder with {CORE_PAK_SOURCE} (default: the Unreal project's packaged paks)")
    args = parser.parse_args()
    if not VERSION_PATTERN.match(args.version):
        parser.error(f"'{args.version}' is not a version like 2.0-beta.4")
    return args


def check_sources(pak_dir):
    required = [INSTALLER_PROJECT, PLUGIN_PROJECT, PROFILE_META, PROFILE_DIR / "paks" / ADDON_PAK, pak_dir / CORE_PAK_SOURCE]
    missing = [str(path) for path in required if not path.is_file()]
    if missing:
        raise ReleaseError("Missing files:\n  " + "\n  ".join(missing))


# Reads and writes a text file as it is, so its line endings and encoding stay unchanged.
def replace_in_file(path, pattern, replacement):
    has_bom = path.read_bytes().startswith(b"\xef\xbb\xbf")
    with open(path, encoding="utf-8-sig", newline="") as file:
        text = file.read()
    new_text, count = re.subn(pattern, replacement, text)
    if count != 1:
        raise ReleaseError(f"Expected one match of {pattern} in {path}, found {count}")
    with open(path, "w", encoding="utf-8-sig" if has_bom else "utf-8", newline="") as file:
        file.write(new_text)


def set_version(version):
    replace_in_file(INSTALLER_PROJECT, r"<InformationalVersion>[^<]*</InformationalVersion>",
                    f"<InformationalVersion>{version}</InformationalVersion>")
    now = datetime.now().astimezone().replace(microsecond=0).isoformat()
    replace_in_file(PROFILE_META, r'"remarks":\s*"[^"]*"', f'"remarks": "{version}"')
    replace_in_file(PROFILE_META, r'"modifiedDate":\s*"[^"]*"', f'"modifiedDate": "{now}"')
    print(f"Version set to {version} in {INSTALLER_PROJECT.name} and {PROFILE_META.name}")


def find_msbuild():
    vswhere = Path(r"C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe")
    if not vswhere.is_file():
        raise ReleaseError(f"vswhere not found: {vswhere}")
    result = subprocess.run([str(vswhere), "-latest", "-requires", "Microsoft.Component.MSBuild",
                             "-find", r"MSBuild\**\Bin\MSBuild.exe"], capture_output=True, text=True)
    lines = result.stdout.strip().splitlines()
    if result.returncode != 0 or not lines:
        raise ReleaseError("MSBuild not found through vswhere")
    return lines[0]


def build_plugin():
    command = [find_msbuild(), str(PLUGIN_PROJECT), "/p:Configuration=Release", "/p:Platform=x64",
               "/m", "/nologo", "/v:minimal"]
    print("Building the plugin (Release x64)")
    if subprocess.run(command).returncode != 0:
        raise ReleaseError("Plugin build failed")
    if not PLUGIN_DLL.is_file():
        raise ReleaseError(f"Plugin DLL not found after the build: {PLUGIN_DLL}")


# Skips PROFILE_EXCLUDE in the profile's top folder only, as the installer project does.
def ignore_excluded(folder, names):
    return [name for name in names if Path(folder) == PROFILE_DIR and name in PROFILE_EXCLUDE]


def stage_profile(staging):
    shutil.copytree(PROFILE_DIR, staging, ignore=ignore_excluded, dirs_exist_ok=True)


def stage_files(staging, pak_dir):
    stage_profile(staging)
    (staging / "plugins").mkdir(exist_ok=True)
    (staging / "paks").mkdir(exist_ok=True)
    shutil.copy2(PLUGIN_DLL, staging / "plugins" / PLUGIN_DLL.name)
    shutil.copy2(pak_dir / CORE_PAK_SOURCE, staging / "paks" / CORE_PAK_TARGET)
    for pak in (CORE_PAK_TARGET, ADDON_PAK):
        if not (staging / "paks" / pak).is_file():
            raise ReleaseError(f"Required pak missing after the copy: {pak}")


def write_zip(staging, zip_path):
    zip_path.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(zip_path, "w", zipfile.ZIP_DEFLATED) as archive:
        for path in sorted(staging.rglob("*")):
            if path.is_file():
                archive.write(path, path.relative_to(staging).as_posix())


def print_summary(version, zip_path, pak_dir):
    core_pak = pak_dir / CORE_PAK_SOURCE
    pak_time = datetime.fromtimestamp(core_pak.stat().st_mtime).strftime("%Y-%m-%d %H:%M")
    build_index = BUILD_INDEX.read_text().strip() if BUILD_INDEX.is_file() else "?"
    print(f"Release {version}, plugin build {build_index}")
    print(f"Core pak: {core_pak} ({pak_time})")
    print(f"Zip: {zip_path} ({zip_path.stat().st_size // 1024} KB)")


def main():
    # Python's own lines must appear in order with MSBuild's output.
    sys.stdout.reconfigure(line_buffering=True)
    args = parse_args()
    try:
        check_sources(args.pak_dir)
        set_version(args.version)
        build_plugin()
        timestamp = datetime.now().strftime("%Y-%m-%d_%H%M%S")
        zip_path = RELEASES_DIR / f"{args.version}_{timestamp}" / ZIP_NAME
        with tempfile.TemporaryDirectory() as temp:
            stage_files(Path(temp), args.pak_dir)
            write_zip(Path(temp), zip_path)
        print_summary(args.version, zip_path, args.pak_dir)
    except ReleaseError as error:
        print(f"ERROR: {error}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
