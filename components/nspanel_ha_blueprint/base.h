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
        // Boot/initialization flags (0-7)
        WIFI_READY = 0,         ///< WiFi connection established
        API_READY = 1,          ///< Home Assistant API connection ready
        BAUD_RATE_SET = 2,      ///< UART baud rate configured
        NEXTION_READY = 3,      ///< Nextion display communication ready
        BLUEPRINT_READY = 4,    ///< Blueprint component initialized
        TFT_READY = 5,          ///< TFT display ready
        BOOT_COMPLETED = 6,     ///< Boot script is completed
        RESERVED_7 = 7,         ///< Reserved for future expansion

        // Runtime operation flags (8-15)
        TFT_UPLOAD_ACTIVE = 8,  ///< TFT firmware upload in progress
        SAFE_MODE_ACTIVE = 9,   ///< System running in safe mode
        OTA_IN_PROGRESS = 10,   ///< Over-the-air update active
        DISPLAY_SLEEP = 11,     ///< Display is in sleep mode
        RESERVED_12 = 12,       ///< Reserved for future expansion
        RESERVED_13 = 13,       ///< Reserved for future expansion
        RESERVED_14 = 14,       ///< Reserved for future expansion
        RESERVED_15 = 15        ///< Reserved for future expansion
    };

    // Global system flags - initialized to 0 (all flags false)
    extern uint16_t system_flags;

    /**
    * @brief Set a specific system flag
    * @param flags Reference to the flags variable
    * @param flag The flag to set
    */
    void set_system_flag(uint16_t &flags, NSPanelFlag flag);

    /**
    * @brief Clear a specific system flag  
    * @param flags Reference to the flags variable
    * @param flag The flag to clear
    */
    void clear_system_flag(uint16_t &flags, NSPanelFlag flag);

    /**
    * @brief Check if a specific system flag is set
    * @param flags The flags variable to check
    * @param flag The flag to check
    * @return true if flag is set, false otherwise
    */
    bool is_system_flag_set(uint16_t flags, NSPanelFlag flag);

    /**
    * @brief Check if all specified flags are set
    * @param flags The flags variable to check
    * @param required_flags List of flags that must all be set
    * @return true if all flags are set, false otherwise
    */
    bool are_all_system_flags_set(uint16_t flags, std::initializer_list<NSPanelFlag> required_flags);

    /**
    * @brief Check if any of the specified flags are set
    * @param flags The flags variable to check
    * @param check_flags List of flags to check
    * @return true if any flag is set, false if none are set
    */
    bool are_any_system_flags_set(uint16_t flags, std::initializer_list<NSPanelFlag> check_flags);

    /**
    * @brief Check if device is ready to accept new tasks
    * @param flags The flags variable to check
    * @return true if device is ready (no blocking operations active), false otherwise
    */
    bool is_device_ready_for_tasks(uint16_t flags);

}  // namespace nspanel_ha_blueprint
