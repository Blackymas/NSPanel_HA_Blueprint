// base.h - Generic flag system for NSPanel HA Blueprint
#pragma once

#include "esphome/core/log.h"
#include <initializer_list>

namespace nspanel_ha_blueprint {

    /**
    * @brief System-wide flags for NSPanel HA Blueprint component state tracking
    *
    * These flags track various component states throughout the system lifecycle.
    * Uses uint16_t to provide 16 available flag positions.
    */
    namespace NSPanelFlag {
        // Boot/initialization flags (0-8)
        constexpr uint16_t WIFI_READY = (1 << 0);                 ///< WiFi connection established
        constexpr uint16_t API_READY = (1 << 1);                  ///< Home Assistant API connection ready
        constexpr uint16_t BAUD_RATE_SET = (1 << 2);              ///< UART baud rate configured
        constexpr uint16_t NEXTION_READY = (1 << 3);              ///< Nextion display communication ready
        constexpr uint16_t BLUEPRINT_READY = (1 << 4);            ///< Blueprint component initialized
        constexpr uint16_t TFT_READY = (1 << 5);                  ///< TFT display ready
        constexpr uint16_t BOOT_COMPLETED = (1 << 6);             ///< Boot script is completed
        constexpr uint16_t VERSION_CHECK_OK = (1 << 7);           ///< All component versions verified
        constexpr uint16_t DISPLAY_SETTINGS_RECEIVED = (1 << 8);  ///< All display settings received

        // Runtime operation flags (9-12)
        constexpr uint16_t TFT_UPLOAD_ACTIVE = (1 << 9);          ///< TFT firmware upload in progress
        constexpr uint16_t SAFE_MODE_ACTIVE = (1 << 10);          ///< System running in safe mode
        constexpr uint16_t OTA_IN_PROGRESS = (1 << 11);           ///< Over-the-air update active
        constexpr uint16_t DISPLAY_SLEEP = (1 << 12);             ///< Display is in sleep mode

        // Reserverd flags (13-15)
        constexpr uint16_t RESERVED_13 = (1 << 13);               ///< Reserved for future expansion
        constexpr uint16_t RESERVED_14 = (1 << 14);               ///< Reserved for future expansion
        constexpr uint16_t RESERVED_15 = (1 << 15);               ///< Reserved for future expansion
    }  // namespace NSPanelFlag

    /**
    * @brief Blueprint status flags for settings step tracking
    *
    * These flags correspond to the specific blueprint initialization steps.
    * Based on the bit mapping used in the blueprint_status sensor.
    */
    namespace BlueprintStatusFlag {
        constexpr uint8_t RESERVED_0 = (1 << 0);           ///< Reserved bit (not used in percentage calculation)
        constexpr uint8_t PAGE_HOME = (1 << 1);            ///< Home page initialization completed
        constexpr uint8_t QRCODE = (1 << 2);               ///< QR code configuration completed
        constexpr uint8_t RELAY_SETTINGS = (1 << 3);       ///< Relay settings configuration completed
        constexpr uint8_t VERSION = (1 << 4);              ///< Blueprint version received
        constexpr uint8_t HW_BUTTONS_SETTINGS = (1 << 5);  ///< Hardware buttons settings completed
        constexpr uint8_t RESERVED_6 = (1 << 6);           ///< Reserved bit (not used in percentage calculation)
        constexpr uint8_t RESERVED_7 = (1 << 7);           ///< Reserved bit (not used in percentage calculation)
    };

    // Global system flags - initialized to 0 (all flags false)
    extern uint16_t system_flags;

    // Global blueprint status flags - initialized to 0 (all flags false)
    extern uint8_t blueprint_status_flags;

    // System flag functions (work directly with global system_flags)

    /**
    * @brief Check if device is ready to accept new tasks
    * @return true if device is ready (no blocking operations active), false otherwise
    */
    inline bool is_device_ready_for_tasks() {
        return
            (system_flags & NSPanelFlag::BOOT_COMPLETED) and  // Boot flag must be set to consider the system ready
            // Device is NOT ready if any of these blocking operations are active
            !(system_flags & NSPanelFlag::OTA_IN_PROGRESS) and
            !(system_flags & NSPanelFlag::TFT_UPLOAD_ACTIVE) and
            !(system_flags & NSPanelFlag::SAFE_MODE_ACTIVE);
    };

    // Blueprint status flag functions (work directly with global blueprint_status_flags)

    /**
    * @brief Check if all non-reserved blueprint status flags are set
    * @return true if all active flags (bits 1-5) are set, false otherwise
    */
    inline bool is_blueprint_fully_ready() {
        // Check if all non-reserved blueprint status flags are set (bits 1-4)
        // Active flags mask: 0x1E = 00011110 = bits 1-4
        static constexpr uint8_t ACTIVE_FLAGS_MASK = 0x1E;
        bool fully_ready = (blueprint_status_flags & ACTIVE_FLAGS_MASK) == ACTIVE_FLAGS_MASK;
    
        // Update system flag only if it changed
        if (fully_ready != static_cast<bool>(system_flags & NSPanelFlag::BLUEPRINT_READY)) {
            if (fully_ready) {
                system_flags |= NSPanelFlag::BLUEPRINT_READY;
            } else {
                system_flags &= ~NSPanelFlag::BLUEPRINT_READY;
            }  // if fully_ready
        }  // if state changed
    
        return fully_ready;
    };

    /**
    * @brief Calculate percentage of non-reserved blueprint status flags that are set
    * @return Percentage (0.0-100.0) of active flags set, excluding reserved bits
    */
    inline float get_blueprint_status_percentage() {
        // Active flags mask: bits 1-4 (PAGE_HOME, QRCODE, RELAY_SETTINGS, VERSION, HW_BUTTONS_SETTINGS)
        static constexpr uint8_t ACTIVE_FLAGS_MASK = 0x3E;  // 00111110
        static constexpr uint8_t MAX_ACTIVE_VALUE = 62;     // 2^1+2^2+2^3+2^4+2^5 = 2+4+8+16+32 = 62

        uint8_t active_flags = blueprint_status_flags & ACTIVE_FLAGS_MASK;
        return active_flags > 0 ? (static_cast<float>(active_flags) / MAX_ACTIVE_VALUE) * 100.0f : 0.0f;
    };

    /**
    * @brief Get the raw value of active blueprint status flags (excluding reserved bits)
    * @return Raw value with only active bits (1-5), matching blueprint_status sensor raw_state
    */
    inline uint8_t get_blueprint_status_raw_value();

}  // namespace nspanel_ha_blueprint
