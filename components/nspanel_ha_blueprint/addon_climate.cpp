#ifdef NSPANEL_HA_BLUEPRINT_ADDON_CLIMATE_BASE

#include "addon_climate.h"

namespace nspanel_ha_blueprint {

    // Climate addon variables definitions
    bool is_addon_climate_visible{false};                   // Is embedded thermostat visible on climate page?
    std::string addon_climate_friendly_name{"Thermostat"};  // Embedded climate friendly name
    DisplayComponent *chip_climate{nullptr};                // Climate chip shown on page Home

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_ADDON_CLIMATE_BASE
