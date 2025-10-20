// page_home.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_PAGE_HOME

#include "nextion_components.h"

/**
 * @file page_home.h
 * @brief Nextion component definitions for the Home page.
 *
 * This file contains all component constants specific to the Home page
 * of the NSPanel interface.
 */

namespace nspanel_ha_blueprint {
  namespace hmi {
    namespace home {

      /**
       * @namespace home
       * @brief Components for the Home page.
       *
       * Component ID mapping for the Home page (ID: 0)
       * Based on the Nextion HMI design file.
       */

      // Page definition
      constexpr HMIComponent PAGE = {"home", 1};  ///< Home page

      // Time and date components
      constexpr HMIComponent TIME = {"home.time", 3};            ///< Time display (5 chars max)
      constexpr HMIComponent DATE = {"home.date", 6};            ///< Date display (25 chars max)
      constexpr HMIComponent MERIDIEM = {"home.meridiem", 32};   ///< AM/PM indicator (6 chars max)

      // Temperature and weather components
      constexpr HMIComponent INDR_TEMP = {"home.indr_temp", 4};            ///< Indoor temperature (8 chars max)
      constexpr HMIComponent INDR_TEMP_ICON = {"home.indr_temp_icon", 27}; ///< Indoor temp icon (3 chars max)
      constexpr HMIComponent OUTDOOR_TEMP = {"home.outdoor_temp", 5};       ///< Outdoor temperature (8 chars max)
      constexpr HMIComponent WEATHER = {"home.weather", 7};                 ///< Weather picture

      // Value display components
      constexpr HMIComponent VALUE01 = {"home.value01", 8};           ///< Value 1 text (30 chars max)
      constexpr HMIComponent VALUE01_ICON = {"home.value01_icon", 21}; ///< Value 1 icon (3 chars max)
      constexpr HMIComponent VALUE02 = {"home.value02", 25};          ///< Value 2 text (30 chars max)
      constexpr HMIComponent VALUE02_ICON = {"home.value02_icon", 24}; ///< Value 2 icon (3 chars max)
      constexpr HMIComponent VALUE03 = {"home.value03", 45};          ///< Value 3 text (30 chars max)
      constexpr HMIComponent VALUE03_ICON = {"home.value03_icon", 44}; ///< Value 3 icon (3 chars max)
      constexpr HMIComponent VALUE04 = {"home.value04", 22};          ///< Value 4 text (30 chars max)
      constexpr HMIComponent VALUE04_ICON = {"home.value04_icon", 23}; ///< Value 4 icon (3 chars max)

      // Chip components (top row)
      constexpr HMIComponent CHIP_RELAY1 = {"home.chip_relay1", 11};   ///< Relay 1 chip (3 chars max)
      constexpr HMIComponent CHIP_RELAY2 = {"home.chip_relay2", 12};   ///< Relay 2 chip (3 chars max)
      constexpr HMIComponent CHIP_CLIMATE = {"home.chip_climate", 13}; ///< Climate chip (3 chars max)
      constexpr HMIComponent CHIP01 = {"home.chip01", 14};             ///< Chip 1 (3 chars max)
      constexpr HMIComponent CHIP02 = {"home.chip02", 15};             ///< Chip 2 (3 chars max)
      constexpr HMIComponent CHIP03 = {"home.chip03", 16};             ///< Chip 3 (3 chars max)
      constexpr HMIComponent CHIP04 = {"home.chip04", 17};             ///< Chip 4 (3 chars max)
      constexpr HMIComponent CHIP05 = {"home.chip05", 18};             ///< Chip 5 (3 chars max)
      constexpr HMIComponent CHIP06 = {"home.chip06", 19};             ///< Chip 6 (3 chars max)
      constexpr HMIComponent CHIP07 = {"home.chip07", 20};             ///< Chip 7 (3 chars max)

      // Button components
      constexpr HMIComponent BUTTON01 = {"home.button01", 35};        ///< Button 1 (3 chars max)
      constexpr HMIComponent BUTTON02 = {"home.button02", 36};        ///< Button 2 (3 chars max)
      constexpr HMIComponent BUTTON03 = {"home.button03", 37};        ///< Button 3 (3 chars max)
      constexpr HMIComponent BUTTON04 = {"home.button04", 40};        ///< Button 4 (3 chars max)
      constexpr HMIComponent BUTTON05 = {"home.button05", 41};        ///< Button 5 (3 chars max)
      constexpr HMIComponent BUTTON06 = {"home.button06", 42};        ///< Button 6 (3 chars max)
      constexpr HMIComponent BUTTON07 = {"home.button07", 31};        ///< Button 7 (3 chars max)

      // Bottom navigation buttons
      constexpr HMIComponent BT_NOTIFIC = {"home.bt_notific", 28};     ///< Notifications button (3 chars max)
      constexpr HMIComponent BT_QRCODE = {"home.bt_qrcode", 29};       ///< QR code button (3 chars max)
      constexpr HMIComponent BT_ENTITIES = {"home.bt_entities", 30};   ///< Entities button (3 chars max)
      constexpr HMIComponent BT_UTILITIES = {"home.bt_utilities", 43}; ///< Utilities button (3 chars max)

      // Footer text components
      constexpr HMIComponent LEFT_BT_TEXT = {"home.left_bt_text", 9};   ///< Left button text (20 chars max)
      constexpr HMIComponent RIGHT_BT_TEXT = {"home.right_bt_text", 10}; ///< Right button text (20 chars max)

      // System indicators
      constexpr HMIComponent WIFI_ICON = {"home.wifi_icon", 26}; ///< WiFi status icon (5 chars max)
      constexpr HMIComponent BT_ICON = {"home.bt_icon", 46};     ///< Bluetooth/system icon (5 chars max)

      // Variables (for reference - these are not visual components)
      constexpr HMIComponent VAR_LASTCLICK = {"home.lastclick", 33};   ///< Last click variable
      constexpr HMIComponent VAR_CLICK_COMP = {"home.click_comp", 38}; ///< Clicked component variable

      // Touch components
      constexpr HMIComponent SWIPE = {"home.swipe", 1}; ///< Swipe gesture handler

      // Timers (for reference)
      constexpr HMIComponent TIMER_SWIPESTORE = {"home.swipestore", 2};       ///< Swipe store timer
      constexpr HMIComponent TIMER_SETTINGS = {"home.settings_timer", 34};    ///< Settings timer
      constexpr HMIComponent TIMER_CLICK = {"home.click_timer", 39};          ///< Click timer
      constexpr HMIComponent TIMER_SHORT_CLICK = {"home.short_click_tm", 47}; ///< Short click timer

    }  // namespace home
  }    // namespace hmi
}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_PAGE_HOME
