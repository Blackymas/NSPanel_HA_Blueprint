// addon_climate.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_ADDON_CLIMATE_BASE

#include <string>

namespace nspanel_ha_blueprint {

    // Global var for the friendly name of the embedded climate entity
    extern std::string addon_climate_friendly_name;

    
    extern bool is_addon_climate_visible;

}  // namespace nspanel_ha_blueprint

#endif  //NSPANEL_HA_BLUEPRINT_ADDON_CLIMATE_BASE
