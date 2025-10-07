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
    // Climate Enumerations
    // =============================================================================

    /**
    * @enum ClimateAction
    * @brief Current action of the climate device.
    *
    * Represents what the climate device is currently doing.
    * Values match ESPHome's climate component definitions.
    */
    enum ClimateAction : uint8_t {
        CLIMATE_ACTION_OFF = 0,      ///< Climate device is off (inactive or no power)
        CLIMATE_ACTION_COOLING = 2,  ///< Climate device is actively cooling
        CLIMATE_ACTION_HEATING = 3,  ///< Climate device is actively heating
        CLIMATE_ACTION_IDLE = 4,     ///< Climate device is idle (monitoring but no action needed)
        CLIMATE_ACTION_DRYING = 5,   ///< Climate device is drying
        CLIMATE_ACTION_FAN = 6       ///< Climate device is in fan only mode
    };

    /**
    * @enum ClimateMode
    * @brief Mode the climate device is set to.
    *
    * Represents the operating mode selected for the climate device.
    * Values match ESPHome's climate component definitions.
    */
    enum ClimateMode : uint8_t {
        CLIMATE_MODE_OFF = 0,        ///< Climate device is set to off
        CLIMATE_MODE_HEAT_COOL = 1,  ///< Climate device is set to auto (heat/cool)
        CLIMATE_MODE_COOL = 2,       ///< Climate device is set to cool only
        CLIMATE_MODE_HEAT = 3,       ///< Climate device is set to heat only
        CLIMATE_MODE_FAN_ONLY = 4,   ///< Climate device is set to fan only
        CLIMATE_MODE_DRY = 5,        ///< Climate device is set to dry/dehumidify
        CLIMATE_MODE_AUTO = 6        ///< Climate device is set to automatic mode
    };

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

    // =============================================================================
    // Climate Icon Lookup Tables
    // =============================================================================

    /**
    * @brief Lookup table for CLIMATE_ACTION_OFF with different modes.
    *
    * Array indices correspond to ClimateMode enum values (0-6):
    * - [0] CLIMATE_MODE_OFF
    * - [1] CLIMATE_MODE_HEAT_COOL
    * - [2] CLIMATE_MODE_COOL
    * - [3] CLIMATE_MODE_HEAT
    * - [4] CLIMATE_MODE_FAN_ONLY
    * - [5] CLIMATE_MODE_DRY
    * - [6] CLIMATE_MODE_AUTO
    *
    * When the climate device is OFF, the icon reflects the selected mode
    * but uses grey color to indicate inactive state.
    */
    constexpr IconData climate_off_mode_icons[] = {
        {Icons::NONE, Colors::BLACK},           // CLIMATE_MODE_OFF (0)
        {Icons::AUTORENEW, Colors::GREY},       // CLIMATE_MODE_HEAT_COOL (1)
        {Icons::SNOWFLAKE, Colors::GREY},       // CLIMATE_MODE_COOL (2)
        {Icons::FIRE, Colors::GREY},            // CLIMATE_MODE_HEAT (3)
        {Icons::FAN, Colors::GREY},             // CLIMATE_MODE_FAN_ONLY (4)
        {Icons::WATER_PERCENT, Colors::GREY},   // CLIMATE_MODE_DRY (5)
        {Icons::CALENDAR_SYNC, Colors::GREY}    // CLIMATE_MODE_AUTO (6)
    };

    /**
    * @brief Lookup table for active climate action states.
    *
    * Array indices correspond to ClimateAction enum values:
    * - [0-1] Unused (reserved)
    * - [2] CLIMATE_ACTION_COOLING
    * - [3] CLIMATE_ACTION_HEATING
    * - [4] CLIMATE_ACTION_IDLE
    * - [5] CLIMATE_ACTION_DRYING
    * - [6] CLIMATE_ACTION_FAN
    *
    * When the climate device is actively operating, the icon and color
    * reflect the current action being performed.
    *
    * @note Indices 0-1 are unused to maintain alignment with the
    *       ClimateAction enum values.
    */
    constexpr IconData climate_action_icons[] = {
        {Icons::NONE, Colors::BLACK},           // Unused index 0
        {Icons::NONE, Colors::BLACK},           // Unused index 1
        {Icons::SNOWFLAKE, Colors::BLUE},       // CLIMATE_ACTION_COOLING (2)
        {Icons::FIRE, Colors::DEEP_ORANGE},     // CLIMATE_ACTION_HEATING (3)
        {Icons::THERMOMETER, Colors::GREY},     // CLIMATE_ACTION_IDLE (4)
        {Icons::WATER_PERCENT, Colors::ORANGE}, // CLIMATE_ACTION_DRYING (5)
        {Icons::FAN, Colors::CYAN}              // CLIMATE_ACTION_FAN (6)
    };

}  // namespace nspanel_ha_blueprint
