// base.h - Generic flag system for NSPanel HA Blueprint
#pragma once

#include "esphome/components/api/custom_api_device.h"  // For API HA event call
#include "esphome/core/application.h"  // For App
#include "esphome/core/hal.h"          // For delay()
#include "esphome/core/log.h"
#include <cstdint>

namespace nspanel_ha_blueprint {

    /**
     * @brief System-wide flags for NSPanel HA Blueprint component state tracking
     * 
     * Uses bitfields to pack 16 boolean states into 2 bytes (uint16_t).
     * Each flag represents a specific component state throughout the system lifecycle.
     * Memory efficient: 16 individual bools would use 16 bytes; this uses only 2 bytes.
     */
    struct SystemFlags {
        // Boot/initialization flags (bits 0-8)
        uint16_t wifi_ready : 1;                 ///< WiFi connection established
        uint16_t api_ready : 1;                  ///< Home Assistant API connection ready
        uint16_t baud_rate_set : 1;              ///< UART baud rate configured
        uint16_t nextion_ready : 1;              ///< Nextion display communication ready
        uint16_t blueprint_ready : 1;            ///< Blueprint component initialized
        uint16_t tft_ready : 1;                  ///< TFT display ready
        uint16_t boot_completed : 1;             ///< Boot script completed
        uint16_t version_check_ok : 1;           ///< All component versions verified
        uint16_t display_settings_received : 1;  ///< All display settings received

        // Runtime operation flags (bits 9-12)
        uint16_t tft_upload_active : 1;          ///< TFT firmware upload in progress
        uint16_t safe_mode_active : 1;           ///< System running in safe mode
        uint16_t ota_in_progress : 1;            ///< Over-the-air update active
        uint16_t display_sleep : 1;              ///< Display is in sleep mode

        // Reserved flags (bits 13-15)
        uint16_t reserved : 3;                   ///< Reserved for future expansion

        // Default constructor - all flags start as false (zero-initialized)
        SystemFlags() : wifi_ready(0), api_ready(0), baud_rate_set(0), nextion_ready(0),
                        blueprint_ready(0), tft_ready(0), boot_completed(0), version_check_ok(0),
                        display_settings_received(0), tft_upload_active(0), safe_mode_active(0),
                        ota_in_progress(0), display_sleep(0), reserved(0) {}
    };

    /**
     * @brief Blueprint status flags for settings step tracking
     * 
     * Uses bitfields to pack 8 boolean states into 1 byte (uint8_t).
     * These flags track specific blueprint initialization steps.
     * Bits 1-5 are active flags used in percentage calculation.
     * Bits 0, 6, 7 are reserved and not used in calculations.
     */
    struct BlueprintStatusFlags {
        uint8_t page_home : 1;            ///< Home page initialization completed
        uint8_t qrcode : 1;               ///< QR code configuration completed
        uint8_t relay_settings : 1;       ///< Relay settings configuration completed
        uint8_t version : 1;              ///< Blueprint version received
        uint8_t hw_buttons_settings : 1;  ///< Hardware buttons settings completed
        uint8_t reserved : 3;             ///< Reserved (not used in percentage calculation)

        // Default constructor - all flags start as false (zero-initialized)
        BlueprintStatusFlags() : page_home(0), qrcode(0), relay_settings(0),
                                version(0), hw_buttons_settings(0), reserved(0) {}

        /**
         * @brief Check if all active flags (bits 1-5) are set
         * @return true if all active flags are set, false otherwise
         */
        bool all_active_flags_set() const {
            // All 5 active flags must be set
            return page_home && qrcode && relay_settings && version && hw_buttons_settings;
        }

        /**
         * @brief Count active flags (bits 1-5) set
         * @return Number of flags set
         */
        uint8_t count_active_flags_set() const {
            return page_home + qrcode + relay_settings + version + hw_buttons_settings;
        }

        /**
         * @brief Calculate percentage of active flags that are set
         * @return Percentage (0.0-100.0) of active flags set (bits 1-5 only)
         */
        float get_completion_percentage() const {
            static constexpr uint8_t TOTAL_ACTIVE_FLAGS = 5;
            return (static_cast<float>(count_active_flags_set()) / TOTAL_ACTIVE_FLAGS) * 100.0f;
        }

        /**
         * @brief Reset all blueprint status flags to their initial state (false)
         *
         * Clears all active flags (bits 0-4) and reserved bits, returning the
         * struct to its default-constructed state.
         */
        void reset() {
            page_home = false;
            qrcode = false;
            relay_settings = false;
            version = false;
            hw_buttons_settings = false;
            reserved = 0;
        }
    };

    // Global system flags - initialized to all flags false
    extern SystemFlags system_flags;

    // Global blueprint status flags - initialized to all flags false
    extern BlueprintStatusFlags blueprint_status_flags;

    /**
     * @brief Check if device is ready to accept new tasks
     * @return true if device is ready (no blocking operations active), false otherwise
     */
    inline bool is_device_ready_for_tasks() {
        return
            system_flags.boot_completed &&  // Boot flag must be set to consider the system ready
            // Device is NOT ready if any of these blocking operations are active
            !system_flags.ota_in_progress &&
            !system_flags.tft_upload_active &&
            !system_flags.safe_mode_active;
    }

    /**
     * @brief Check if all non-reserved blueprint status flags are set
     * @return true if all active flags (bits 1-5) are set, false otherwise
     */
    inline bool is_blueprint_fully_ready() {
        bool fully_ready = blueprint_status_flags.all_active_flags_set();

        // Update system flag only if it changed
        if (fully_ready != system_flags.blueprint_ready) {
            system_flags.blueprint_ready = fully_ready;
        }

        return fully_ready;
    }

    /// @brief Feed the watchdog timer with an optional delay
    ///
    /// This utility function combines a delay with a watchdog timer feed operation.
    /// It's commonly used in long-running operations to prevent watchdog timeouts
    /// while giving the system time to process other tasks.
    ///
    /// @param ms Delay duration in milliseconds before feeding the watchdog (default: 5ms)
    ///
    /// @note This function is blocking - execution will pause for the specified duration
    /// @note Minimum recommended delay is 5ms to allow system task processing
    ///
    /// @code
    /// // Example usage with default 5ms delay
    /// feed_wdt_delay();
    ///
    /// // Example usage with custom 25ms delay
    /// feed_wdt_delay(25);
    ///
    /// // Common pattern in loops
    /// for (uint8_t i = 0; i < 10; ++i) {
    ///   // ... do work ...
    ///   feed_wdt_delay(5);  // Prevent watchdog timeout
    /// }
    /// @endcode
    ///
    /// @see delay()
    /// @see App.feed_wdt()
    inline void feed_wdt_delay(uint32_t ms = 5) {
        esphome::delay(ms);       // Block execution for specified milliseconds
        esphome::App.feed_wdt();  // Reset the watchdog timer
    }

    // Cached device name to avoid repeated lookups and string copies
    extern std::string cached_device_name;

    /**
    * @brief Fire a Home Assistant event for NSPanel HA Blueprint
    *
    * Automatically adds device_name and type to the event data.
    *
    * @param type Event type (e.g., "button_click", "page_changed", "boot")
    * @param data Additional event data (device_name and type added automatically)
    *
    * @note The event name is automatically set to "esphome.nspanel_ha_blueprint"
    * @note Call init_device_name_cache() during boot before using this function
    *
    * @code
    * fire_ha_event("button_click", {
    *   {"page", "home"},
    *   {"component", "bt_left"}
    * });
    * @endcode
    */
    inline void fire_ha_event(const std::string& type, std::map<std::string, std::string> data = {}) {
        data["device_name"] = cached_device_name;
        data["type"] = type;

        esphome::api::CustomAPIDevice ha_event;
        ha_event.fire_homeassistant_event("esphome.nspanel_ha_blueprint", data);
    }

}  // namespace nspanel_ha_blueprint
