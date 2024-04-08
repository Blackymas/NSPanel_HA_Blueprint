// versioning.h

#pragma once

namespace nspanel_ha_blueprint {

    /**
     * Compares two version strings by major and minor version numbers, assuming the version
     * strings are formatted as "major.minor". This function parses both version strings and
     * compares their major and minor components.
     *
     * @param version1 The first version string to compare, in "major.minor" format.
     * @param version2 The second version string to compare, in "major.minor" format.
     * @return True if both the major and minor versions of version1 and version2 are equal,
     *         false otherwise.
     */
    bool compare_versions(const char* version1, const char* version2);

}  // namespace nspanel_ha_blueprint
