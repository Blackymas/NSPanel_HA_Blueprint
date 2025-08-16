// boot.h - Just enum and utility functions
#pragma once

#include "esphome/core/log.h"
#include <initializer_list>

namespace nspanel_ha_blueprint {

    enum class BootFlag : uint8_t {
        WIFI = 0,
        API = 1, 
        BAUD_RATE = 2,
        NEXTION = 3,
        BLUEPRINT = 4,
        TFT = 5,
        CLIMATE = 6,
        // Bit 7 reserved
    };

    // Global boot flags variable - initialized to 0 (all flags false)
    extern uint8_t boot_flags;

    // Utility functions
    void set_boot_flag(uint8_t &flags, BootFlag flag);
    void clear_boot_flag(uint8_t &flags, BootFlag flag);
    bool is_boot_flag_set(uint8_t flags, BootFlag flag);
    bool are_all_boot_flags_set(uint8_t flags, std::initializer_list<BootFlag> required_flags);

}  // namespace nspanel_ha_blueprint
