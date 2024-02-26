// hardware.h
#pragma once

#include <cstdint>

namespace nspanel_ha_blueprint {

    /**
     * @enum ButtonsSettings
     * Represents the settings for hardware buttons as individual bits within a uint8_t value.
     * Each enum value corresponds to a specific bit position that represents a distinct setting
     * for the buttons. This allows for efficient storage and manipulation of multiple buttons
     * settings within a single byte.
     * 
     * Bits are allocated as follows:
     * - Bit 0: Left button - Enabled.
     * - Bit 1: Left button - Current state (0 for `off` or 1 for `on`)
     * - Bits 2-3: Reserved for future use.
     * - Bit 4: Right button - Enabled.
     * - Bit 5: Right button - Current state (0 for `off` or 1 for `on`)
     * - Bits 6-7: Reserved for future use.
     * 
     * Usage involves bitwise operations to set, clear, and check these settings within a
     * uint8_t variable. This approach enables compact representation and easy manipulation
     * of relay settings.
     */
    enum ButtonSettings {
        ButtonLeft_Enabled = 1 << 0,   ///< Bit 0: Enables left button visualization on screen.
        ButtonLeft_State = 1 << 1,     ///< Bit 1: Current state of left button.
        // Bits 2 and 3 are reserved for future expansion.
        ButtonRight_Enabled = 1 << 4,  ///< Bit 4: Enables right button visualization on screen.
        ButtonRight_State = 1 << 5,    ///< Bit 5: Current state of right button.
        // Bits 6 and 7 are reserved for future expansion.
    };

    /**
     * @enum RelaySettings
     * Represents the settings for relays as individual bits within a uint8_t value. Each
     * enum value corresponds to a specific bit position that represents a distinct setting
     * for the relays. This allows for efficient storage and manipulation of multiple relay
     * settings within a single byte.
     * 
     * Bits are allocated as follows:
     * - Bit 0: Relay 1 - Local control enabled.
     * - Bit 1: Relay 1 - Fallback mode enabled.
     * - Bits 2-3: Reserved for future use.
     * - Bit 4: Relay 2 - Local control enabled.
     * - Bit 5: Relay 2 - Fallback mode enabled.
     * - Bits 6-7: Reserved for future use.
     * 
     * Usage involves bitwise operations to set, clear, and check these settings within a
     * uint8_t variable. This approach enables compact representation and easy manipulation
     * of relay settings.
     */
    enum RelaySettings {
        Relay1_Local = 1 << 0,     ///< Bit 0: Enables local control for Relay 1.
        Relay1_Fallback = 1 << 1,  ///< Bit 1: Enables fallback mode for Relay 1.
        // Bits 2 and 3 are reserved for future expansion.
        Relay2_Local = 1 << 4,     ///< Bit 4: Enables local control for Relay 2.
        Relay2_Fallback = 1 << 5,  ///< Bit 5: Enables fallback mode for Relay 2.
        // Bits 6 and 7 are reserved for future expansion.
    };

    template<typename SettingsEnum>
    void update_bitwise_setting(uint8_t& settings, bool condition, SettingsEnum flag) {
        if (condition) {
            settings |= flag; // Set bit
        } else {
            settings &= ~flag; // Clear bit
        }
    }

}  // namespace nspanel_ha_blueprint
