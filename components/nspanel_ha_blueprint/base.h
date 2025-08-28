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
    enum class NSPanelFlag : uint8_t {
        // Boot/initialization flags (0-8)
        WIFI_READY = 0,                 ///< WiFi connection established
        API_READY = 1,                  ///< Home Assistant API connection ready
        BAUD_RATE_SET = 2,              ///< UART baud rate configured
        NEXTION_READY = 3,              ///< Nextion display communication ready
        BLUEPRINT_READY = 4,            ///< Blueprint component initialized
        TFT_READY = 5,                  ///< TFT display ready
        BOOT_COMPLETED = 6,             ///< Boot script is completed
        VERSION_CHECK_OK = 7,           ///< All component versions (TFT, ESPHome, Blueprint) verified as synchronized
        DISPLAY_SETTINGS_RECEIVED = 8,  ///< All display settings received

        // Runtime operation flags (9-15)
        TFT_UPLOAD_ACTIVE = 9,          ///< TFT firmware upload in progress
        SAFE_MODE_ACTIVE = 10,          ///< System running in safe mode
        OTA_IN_PROGRESS = 11,           ///< Over-the-air update active
        DISPLAY_SLEEP = 12,             ///< Display is in sleep mode
        RESERVED_13 = 13,               ///< Reserved for future expansion
        RESERVED_14 = 14,               ///< Reserved for future expansion
        RESERVED_15 = 15                ///< Reserved for future expansion
    };

    /**
    * @brief Blueprint status flags for settings step tracking
    *
    * These flags correspond to the specific blueprint initialization steps.
    * Based on the bit mapping used in the blueprint_status sensor.
    */
    enum class BlueprintStatusFlag : uint8_t {
        RESERVED_0 = 0,         ///< Reserved bit (not used in percentage calculation)
        PAGE_HOME = 1,          ///< Home page initialization completed
        QRCODE = 2,             ///< QR code configuration completed
        PAGE_SETTINGS = 3,      ///< Settings page initialization completed
        RELAY_SETTINGS = 4,     ///< Relay settings configuration completed
        GLOBAL_SETTINGS = 5,    ///< Global settings configuration completed
        RESERVED_6 = 6,         ///< Reserved bit (not used in percentage calculation)
        RESERVED_7 = 7          ///< Reserved bit (not used in percentage calculation)
    };

    // Global system flags - initialized to 0 (all flags false)
    extern uint16_t system_flags;

    // Global blueprint status flags - initialized to 0 (all flags false)
    extern uint8_t blueprint_status_flags;

    // System flag functions (work directly with global system_flags)

    /**
    * @brief Set a specific system flag
    * @param flag The flag to set
    */
    void set_system_flag(NSPanelFlag flag);

    /**
    * @brief Clear a specific system flag  
    * @param flag The flag to clear
    */
    void clear_system_flag(NSPanelFlag flag);

    /**
    * @brief Check if a specific system flag is set
    * @param flag The flag to check
    * @return true if flag is set, false otherwise
    */
    bool is_system_flag_set(NSPanelFlag flag);

    /**
    * @brief Check if all specified system flags are set
    * @param required_flags List of flags that must all be set
    * @return true if all flags are set, false otherwise
    */
    bool are_all_system_flags_set(std::initializer_list<NSPanelFlag> required_flags);

    /**
    * @brief Check if any of the specified system flags are set
    * @param check_flags List of flags to check
    * @return true if any flag is set, false if none are set
    */
    bool are_any_system_flags_set(std::initializer_list<NSPanelFlag> check_flags);

    /**
    * @brief Check if device is ready to accept new tasks
    * @return true if device is ready (no blocking operations active), false otherwise
    */
    bool is_device_ready_for_tasks();

    // Blueprint status flag functions (work directly with global blueprint_status_flags)

    /**
    * @brief Set a specific blueprint status flag
    * @param flag The blueprint status flag to set
    */
    void set_blueprint_status_flag(BlueprintStatusFlag flag);

    /**
    * @brief Clear a specific blueprint status flag
    * @param flag The blueprint status flag to clear
    */
    void clear_blueprint_status_flag(BlueprintStatusFlag flag);

    /**
    * @brief Check if a specific blueprint status flag is set
    * @param flag The blueprint status flag to check
    * @return true if flag is set, false otherwise
    */
    bool is_blueprint_status_flag_set(BlueprintStatusFlag flag);

    /**
    * @brief Check if all non-reserved blueprint status flags are set
    * @return true if all active flags (bits 1-5) are set, false otherwise
    */
    bool is_blueprint_fully_ready();

    /**
    * @brief Calculate percentage of non-reserved blueprint status flags that are set
    * @return Percentage (0.0-100.0) of active flags set, excluding reserved bits
    */
    float get_blueprint_status_percentage();

    /**
    * @brief Get the raw value of active blueprint status flags (excluding reserved bits)
    * @return Raw value with only active bits (1-5), matching blueprint_status sensor raw_state
    */
    uint8_t get_blueprint_status_raw_value();

}  // namespace nspanel_ha_blueprint
