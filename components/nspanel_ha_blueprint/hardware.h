// hardware.h

#pragma once

#include <cstdint>

namespace nspanel_ha_blueprint {

    /**
     * @brief Combined hardware settings using bitfields
     * 
     * Packs BOTH button and relay settings into a single byte (uint8_t).
     * Bits 0-3: Button settings (left enabled, left state, right enabled, right state)
     * Bits 4-7: Relay settings (relay1 local, relay1 fallback, relay2 local, relay2 fallback)
     * 
     * Memory efficient: Saves 1 byte compared to separate button/relay bytes.
     * Previous: 2 bytes (1 for buttons + 1 for relays)
     * Now: 1 byte (contains both)
     */
    struct HardwareSettings {
        // Button settings (bits 0-3)
        uint8_t button_left_enabled : 1;   ///< Bit 0: Left button visualization enabled
        uint8_t button_left_state : 1;     ///< Bit 1: Left button state (0=off, 1=on)
        uint8_t button_right_enabled : 1;  ///< Bit 2: Right button visualization enabled
        uint8_t button_right_state : 1;    ///< Bit 3: Right button state (0=off, 1=on)
        
        // Relay settings (bits 4-7)
        uint8_t relay1_local : 1;          ///< Bit 4: Relay 1 local control enabled
        uint8_t relay1_fallback : 1;       ///< Bit 5: Relay 1 fallback mode enabled
        uint8_t relay2_local : 1;          ///< Bit 6: Relay 2 local control enabled
        uint8_t relay2_fallback : 1;       ///< Bit 7: Relay 2 fallback mode enabled

        // Default constructor - all flags start as false (zero-initialized)
        HardwareSettings() : button_left_enabled(0), button_left_state(0),
                            button_right_enabled(0), button_right_state(0),
                            relay1_local(0), relay1_fallback(0),
                            relay2_local(0), relay2_fallback(0) {}
    };

    // Note: hardware_settings_raw is declared as uint8_t in ESPHome YAML with restore_value: true
    // Use the helper function below to access it as a HardwareSettings struct
    
    /**
     * @brief Get hardware settings as a struct reference from the raw uint8_t
     * @param raw_value Reference to the uint8_t global variable from YAML
     * @return Reference to HardwareSettings struct (same memory location)
     */
    inline HardwareSettings& get_hardware_settings(uint8_t& raw_value) {
        return reinterpret_cast<HardwareSettings&>(raw_value);
    }

}  // namespace nspanel_ha_blueprint
