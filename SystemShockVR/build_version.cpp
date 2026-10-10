#include "build_version.hpp"

#include <string>

// Only this file includes the generated header, so a new build index recompiles one file.
#include "build_version_generated.hpp"

namespace BuildVersion
{
    const char* version() { return PLUGIN_VERSION; }

    int index() { return PLUGIN_BUILD_INDEX; }

    const char* text()
    {
        static const std::string value = std::string(PLUGIN_VERSION) + " [" + std::to_string(PLUGIN_BUILD_INDEX) + "]";
        return value.c_str();
    }
}
