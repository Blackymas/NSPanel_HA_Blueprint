// pages.h

#pragma once

#include <array>
#include <cstdint>
#include <cstring>
#include <string>
#include "esp_attr.h"  // Include for PSRAM attributes

namespace nspanel_ha_blueprint {

    // Used to register the current page id
    // Updated by Nextion `on_page` on nspanel_esphome_core_hw_display.yaml
    extern uint8_t current_page_id;

    // Used to register the next page id
    // Updated by script `goto_page` on nspanel_esphome_core_hw_display.yaml
    extern uint8_t next_page_id;

    // Used to register the previous page id
    // Updated by script `page_changed` on nspanel_esphome_core_hw_display.yaml
    extern uint8_t previous_page_id;

    /**
    * @file pages.h
    * Defines constants and functions related to page names for the NSPanel HA Blueprint project.
    */

    // Constants
    /**
    * A runtime array containing the names of pages, stored in PSRAM to save internal SRAM.
    * These names correspond to various pages of the Nextion TFT file in use,
    * such as settings, home, weather information, and more.
    */
    extern char page_names[29][15];

    // Define bitmasks for the different groups of repeating pages
    // Entity Pages: IDs 18, 19, 20, 21 (entitypage01 to entitypage04)
    extern uint32_t ENTITY_PAGE_MASK;
    // Button Pages: IDs 12, 13, 14, 15 (buttonpage01 to buttonpage04)
    extern uint32_t BUTTONS_PAGE_MASK;
    // Weather Pages: IDs 2, 3, 4, 5, 6 (weather01 to weather05)
    extern uint32_t WEATHER_PAGE_MASK;
    // Pages using `entity_id`: Alarm, Climate, Cover, Fan, Light, Media Player, Confirm, Keyb Num
    extern uint32_t ENTITY_ID_PAGE_MASK;
    // Pages not requiring API to be connected: Blank, Boot, Confirm, Home, Screen saver, Settings
    extern uint32_t NON_API_ID_PAGE_MASK;

    // Generic function to check if a page ID belongs to a specific group, based on the provided mask
    bool is_page_in_group(uint32_t group_mask, uint8_t page_id = current_page_id);

    /**
    * Retrieves the index of a given page name within the page_names array.
    * 
    * @param page_name The name of the page to find.
    * @return The index of the page_name in the page_names array. If the page_name
    *         is not found, returns UINT8_MAX as an indicator that no matching page was found.
    */
    uint8_t get_page_id(const std::string& page_name);

}  // namespace nspanel_ha_blueprint
