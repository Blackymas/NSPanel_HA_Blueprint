// icons.h

#pragma once

#include <cstdint>

/**
 * @file icons.h
 * @brief Display icon constants and color definitions for NSPanel interface elements.
 *
 * This file contains compile-time constants for icon Unicode characters and display colors
 * used throughout the NSPanel interface. All constants are defined as constexpr to ensure
 * they are stored in flash memory rather than RAM, optimizing memory usage.
 *
 * Organization:
 * - Icons: Unicode characters for display icons (MDI)
 * - Colors: RGB565 color values for state visualization
 * - IconData: Structure pairing icons with colors
 */

namespace nspanel_ha_blueprint {

    // =============================================================================
    // Icon Constants
    // =============================================================================

    /**
    * @namespace Icons
    * @brief MDI icon Unicode characters for display visualization.
    *
    * These constants represent Material Design Icons (MDI) used to display
    * different device states and modes on the NSPanel display.
    */
    namespace Icons {
        // Alarm icons
        constexpr const char* SHIELD_ALERT_OUTLINE = "\uEECC";     ///< mdi:shield-alert-outline - Triggered
        constexpr const char* SHIELD_OFF_OUTLINE = "\uE99B";       ///< mdi:shield-off-outline - Disarmed
        constexpr const char* SHIELD_HOME_OUTLINE = "\uECCA";      ///< mdi:shield-home-outline - Armed home
        constexpr const char* SHIELD_LOCK_OUTLINE = "\uECCB";      ///< mdi:shield-lock-outline - Armed away
        constexpr const char* SHIELD_MOON_OUTLINE = "\uF828";      ///< mdi:shield-moon-outline - Armed night
        constexpr const char* SHIELD_AIRPLANE_OUTLINE = "\uECC6";  ///< mdi:shield-airplane-outline - Armed vacation
        constexpr const char* SHIELD_HALF_FULL = "\uE77F";         ///< mdi:shield-half-full - Armed custom bypass
        constexpr const char* SHIELD_OUTLINE = "\uE498";           ///< mdi:shield-outline - Pending/arming

        // Climate icons
        constexpr const char* AUTORENEW = "\uE069";      ///< mdi:autorenew - Auto/heat-cool mode
        constexpr const char* SNOWFLAKE = "\uE716";      ///< mdi:snowflake - Cooling mode
        constexpr const char* FIRE = "\uE237";           ///< mdi:fire - Heating mode
        constexpr const char* FAN = "\uE20F";            ///< mdi:fan - Fan mode
        constexpr const char* WATER_PERCENT = "\uE58D";  ///< mdi:water-percent - Dry/dehumidify mode
        constexpr const char* CALENDAR_SYNC = "\uEE8D";  ///< mdi:calendar-sync - Auto mode (deprecated)
        constexpr const char* REFRESH_AUTO = "\uF8F1";   ///< mdi:refresh-auto - Auto mode
        constexpr const char* THERMOMETER = "\uE50E";    ///< mdi:thermometer - Idle state
        constexpr const char* NONE = "\uFFFF";           ///< Hidden/no icon (blank character)

        // System/WiFi icons
        constexpr const char* WIFI = "\uE5A8";                 ///< mdi:wifi - WiFi connected
        // Renamed to avoid collision with Arduino WiFiType.h macro WIFI_OFF
        constexpr const char* WIFI_DISCONNECTED = "\uE5A9";    ///< mdi:wifi-off - WiFi disconnected
        // constexpr const char* WIFI_OFF = "\uE5A9";             ///< mdi:wifi-off - WiFi disconnected
        constexpr const char* API_OFF = "\uF256";              ///< mdi:api-off - API disconnected
        constexpr const char* HOME_ASSISTANT = "\uE7CF";       ///< mdi:home-assistant - Blueprint disconnected
        constexpr const char* RESTART = "\uE708";              ///< mdi:restart - System restart
    }  // namespace Icons

    // =============================================================================
    // Color Constants
    // =============================================================================

    /**
    * @namespace Colors
    * @brief RGB565 color values for state visualization.
    *
    * Color constants used to indicate different device states.
    * Values are in RGB565 format (16-bit color depth) compatible with
    * the Nextion display hardware.
    */
    namespace Colors {
        constexpr uint16_t BLACK = 0;              ///< Hidden/invisible (RGB565: 0x0000)
        constexpr uint16_t BLUE = 1055;            ///< Cooling action (RGB565: 0x041F)
        constexpr uint16_t BLUE_BLUETOOTH = 1279;  ///< Bluetooth blue (RGB565: 0x04FF)
        constexpr uint16_t BLUE_INDIGO = 10597;    ///< Indigo blue (RGB565: 0x2965)
        constexpr uint16_t CYAN = 1530;            ///< Fan action (RGB565: 0x05FA)
        constexpr uint16_t CYAN_BRIGHT = 7519;     ///< Bright cyan (RGB565: 0x1D5F)
        constexpr uint16_t DEEP_ORANGE = 64164;    ///< Heating action (RGB565: 0xFAA4)
        constexpr uint16_t GREEN = 19818;          ///< Armed/active state (RGB565: 0x4D6A)
        constexpr uint16_t GRAY = 35921;           ///< Inactive/off state (RGB565: 0x8C51)
        constexpr uint16_t GRAY_DARK = 16904;       ///< Hidden/disabled buttons
        constexpr uint16_t GRAY_LIGHT = 52857;     ///< Gray light/silver (RGB565: 0xCE79)
        constexpr uint16_t GRAY_MOSS = 33808;      ///< Moss gray/green (RGB565: 0x8410)
        constexpr uint16_t YELLOW_GREEN = 48631;   ///< Inactive buttons
        constexpr uint16_t ORANGE = 64704;         ///< Drying action (RGB565: 0xFCC0)
        constexpr uint16_t PURPLE_MEDIUM = 38004;  ///< Medium purple (RGB565: 0x9474)
        constexpr uint16_t RED = 63488;            ///< Alert/triggered state (RGB565: 0xF800)
        constexpr uint16_t WHITE = 65535;          ///< White/default (RGB565: 0xFFFF)
        constexpr uint16_t YELLOW = 65024;         ///< Warning/pending state (RGB565: 0xFE00)
        constexpr uint16_t YELLOW_GOLDEN = 64992;  ///< Golden yellow (RGB565: 0xFDE0)
    }  // namespace Colors

    // =============================================================================
    // Display Data Structures
    // =============================================================================

    /**
    * @struct IconData
    * @brief Associates an icon character with its display color.
    *
    * This structure pairs a pointer to an icon Unicode character with
    * a corresponding RGB565 color value for display on the NSPanel.
    * Used for various entity types including climate, light, cover, etc.
    */
    struct IconData {
        const char* icon;  ///< Pointer to icon Unicode character string
        uint16_t color;    ///< RGB565 color value for icon display
    };

}  // namespace nspanel_ha_blueprint
