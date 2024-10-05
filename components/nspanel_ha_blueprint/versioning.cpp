// versioning.cpp

#include "versioning.h"
#include <cstdio>  // For sscanf
#include "esphome/core/application.h"

namespace nspanel_ha_blueprint {

    bool compare_versions(const char* version1, const char* version2) {
        int major1 = 0, minor1 = 0;
        int major2 = 0, minor2 = 0;

        // Give a chance for other processes
        esphome::App.feed_wdt();
        esphome::yield();

        // Parse the version strings into major and minor numbers
        sscanf(version1, "%d.%d", &major1, &minor1);
        sscanf(version2, "%d.%d", &major2, &minor2);

        // Compare the parsed major and minor numbers
        return (major1 == major2) && (minor1 == minor2);
    }

}  // namespace nspanel_ha_blueprint
