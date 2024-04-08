// hardware.cpp

#include "hardware.h"

namespace nspanel_ha_blueprint {

    template<typename SettingsEnum>
    void update_bitwise_setting(uint8_t& settings, bool condition, SettingsEnum flag) {
        if (condition) {
            settings |= flag;   // Set bit
        } else {
            settings &= ~flag;  // Clear bit
        }
    }

    // Explicit template instantiation
    // Note: You need to explicitly instantiate templates for all enums used as SettingsEnum
    template void update_bitwise_setting<ButtonSettings>(uint8_t& settings, bool condition, ButtonSettings flag);
    template void update_bitwise_setting<RelaySettings>(uint8_t& settings, bool condition, RelaySettings flag);

}  // namespace nspanel_ha_blueprint
