#pragma once

// The plugin version and the build index, for display. The values come from
// build_version_generated.hpp, which scripts\bump-build-index.ps1 writes before every build.
// The version is the installer's InformationalVersion; the index is build_index.txt.
namespace BuildVersion
{
    const char* version();   // "2.0-beta.3"
    int index();             // 45
    const char* text();      // "2.0-beta.3 [45]"
}
