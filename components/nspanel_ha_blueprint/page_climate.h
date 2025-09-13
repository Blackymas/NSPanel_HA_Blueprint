// page_climate.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_PAGE_CLIMATE

#include <cstdint>
#include <string>

namespace nspanel_ha_blueprint {

    extern float set_climate_current_temp;
    extern uint32_t set_climate_supported_features;
    extern float set_climate_target_temp;
    extern float set_climate_target_temp_high;
    extern float set_climate_target_temp_low;
    extern uint8_t set_climate_temp_step;
    extern uint8_t set_climate_total_steps;
    extern uint8_t set_climate_temp_offset;
    extern std::string set_climate_climate_icon;
    extern bool set_climate_embedded_climate;

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_PAGE_CLIMATE
