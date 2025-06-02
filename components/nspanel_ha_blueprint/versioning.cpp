// versioning.cpp

#include "versioning.h"
#include <cstdio>  // For sscanf

namespace nspanel_ha_blueprint {

    bool compare_versions(const char* version1, const char* version2) {
        int major1 = 0, minor1 = 0;
        int major2 = 0, minor2 = 0;

        // Parse the version strings into major and minor numbers
        sscanf(version1, "%d.%d", &major1, &minor1);
        sscanf(version2, "%d.%d", &major2, &minor2);

        // Compare the parsed major and minor numbers
        return (major1 == major2) && (minor1 == minor2);
    }

}  // namespace nspanel_ha_blueprint
