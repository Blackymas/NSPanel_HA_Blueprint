// page_climate.cpp

#ifdef NSPANEL_HA_BLUEPRINT_PAGE_CLIMATE

#include "page_climate.h"

namespace nspanel_ha_blueprint {

    float set_climate_current_temp;
    uint32_t set_climate_supported_features;
    float set_climate_target_temp;
    float set_climate_target_temp_high;
    float set_climate_target_temp_low;
    uint8_t set_climate_temp_step;
    uint8_t set_climate_total_steps;
    uint8_t set_climate_temp_offset;
    std::string set_climate_climate_icon;
    bool set_climate_embedded_climate;

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_PAGE_CLIMATE
