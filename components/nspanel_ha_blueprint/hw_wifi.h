// hw_wifi.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_CORE_HW_WIFI

#include <algorithm>
#include <cctype>
#include <string>
#include "esphome/core/log.h"

namespace nspanel_ha_blueprint {

    /**
    * Sets the device name based on the provided raw name.
    * This should be called once during boot.
    * 
    * @param raw_name Base name used to generate the full device name (with MAC suffix if available).
    */
    void set_device_name(const char* raw_name);

    /**
        * Retrieves the generated device name.
        * The name is guaranteed to meet ESPHome constraints (lowercase, hyphenated, max 31 or 24 chars).
        *
        * @return Pointer to a null-terminated string with the device name.
        */
    const char* get_device_name();

}  // namespace nspanel_ha_blueprint

#endif // NSPANEL_HA_BLUEPRINT_CORE_HW_WIFI
