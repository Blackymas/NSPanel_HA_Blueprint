#include "base.h"
#include "esphome/core/application.h"

namespace nspanel_ha_blueprint {

    // Define the global system flags variable (starts with all flags false)
    uint16_t system_flags = 0;

    // Define the global blueprint status flags variable (starts with all flags false)
    uint8_t blueprint_status_flags = 0;

    // Blueprint status flag functions

    uint8_t get_blueprint_status_raw_value() {
        // Return only the active flags value (bits 1-5)
        static constexpr uint8_t ACTIVE_FLAGS_MASK = 0x3E;  // 00111110
        return blueprint_status_flags & ACTIVE_FLAGS_MASK;
    }

}  // namespace nspanel_ha_blueprint
