// page_utilities.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_STANDARD_PAGE_UTILITIES

#include <cstdint>
#include <cstring>  // For std::strcpy
#include <string>
#include "base.h"

namespace nspanel_ha_blueprint {

    struct UtilitiesGroupValues {
        char group_id[8];  // 7 characters + null terminator
        char value1[11];   // 10 characters + null terminator
        char value2[11];   // 10 characters + null terminator
        int8_t direction;
    };

    extern UtilitiesGroupValues *UtilitiesGroups;

    void resetUtilitiesGroups();
    void cleanupUtilitiesGroups();
    uint8_t findUtilitiesGroupIndex(const char* group_id);

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_STANDARD_PAGE_UTILITIES
