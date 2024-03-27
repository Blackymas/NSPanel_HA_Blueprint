// utilities.h
#pragma once

#include <cstdint>

namespace nspanel_ha_blueprint {

    struct UtilitiesGroupValues {
        char group_id[8];  // 7 characters + null terminator
        char value1[11];  // 10 characters + null terminator
        char value2[11];  // 11 characters + null terminator
        int8_t direction;
    };

    extern UtilitiesGroupValues UtilitiesGroups[8];

    void resetUtilitiesGroups();
    uint8_t findUtilitiesGroupIndex(const char* group_id);

}  // namespace nspanel_ha_blueprint
