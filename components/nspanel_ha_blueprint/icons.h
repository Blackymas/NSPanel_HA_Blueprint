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
 * - Enums: Climate action and mode enumerations
 * - Lookup tables: Const arrays for efficient icon/color selection
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
        // Climate icons
        constexpr const char* AUTORENEW = "\uE069";      ///< mdi:autorenew - Auto/heat-cool mode
        constexpr const char* SNOWFLAKE = "\uE716";      ///< mdi:snowflake - Cooling mode
        constexpr const char* FIRE = "\uE237";           ///< mdi:fire - Heating mode
        constexpr const char* FAN = "\uE20F";            ///< mdi:fan - Fan mode
        constexpr const char* WATER_PERCENT = "\uE58D";  ///< mdi:water-percent - Dry/dehumidify mode
        constexpr const char* CALENDAR_SYNC = "\uEE8D";  ///< mdi:calendar-sync - Auto mode
        constexpr const char* THERMOMETER = "\uE50E";    ///< mdi:thermometer - Idle state
        constexpr const char* NONE = "\uFFFF";           ///< Hidden/no icon (blank character)
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
        constexpr uint16_t BLACK = 0;            ///< Hidden/invisible (RGB565: 0x0000)
        constexpr uint16_t GREY = 35921;         ///< Inactive/off state (RGB565: 0x8C51)
        constexpr uint16_t BLUE = 1055;          ///< Cooling action (RGB565: 0x041F)
        constexpr uint16_t DEEP_ORANGE = 64164;  ///< Heating action (RGB565: 0xFAA4)
        constexpr uint16_t ORANGE = 64704;       ///< Drying action (RGB565: 0xFCC0)
        constexpr uint16_t CYAN = 1530;          ///< Fan action (RGB565: 0x05FA)
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
