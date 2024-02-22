// versioning.h
#pragma once
#include <cstdio> // For sscanf

namespace nspanel_ha_blueprint {

    /**
     * Compares two version strings by major and minor version numbers.
     * Assumes version strings are in the format "major.minor".
     *
     * @param version1 First version string to compare.
     * @param version2 Second version string to compare.
     * @return true if the major and minor versions are equal, false otherwise.
     */
    inline bool compare_versions(const char* version1, const char* version2) {
        int major1 = 0, minor1 = 0;
        int major2 = 0, minor2 = 0;

        sscanf(version1, "%d.%d", &major1, &minor1);
        sscanf(version2, "%d.%d", &major2, &minor2);

        return (major1 == major2) && (minor1 == minor2);
    }

}  // namespace nspanel_ha_blueprint
