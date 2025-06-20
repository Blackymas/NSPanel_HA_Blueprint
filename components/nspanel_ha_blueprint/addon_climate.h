#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_ADDON_CLIMATE_BASE

#include "hw_display.h"

namespace nspanel_ha_blueprint {

    // Climate addon variables
    extern bool is_addon_climate_visible;              // Is embedded thermostat visible on climate page?
    extern std::string addon_climate_friendly_name;    // Embedded climate friendly name
    extern DisplayComponent *chip_climate;             // Climate chip shown on page Home

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_ADDON_CLIMATE_BASE
