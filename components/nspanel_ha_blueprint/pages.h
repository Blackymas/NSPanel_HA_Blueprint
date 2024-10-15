// pages.h

#pragma once

#include <array>
#include <cstdint>
#include <cstring>
#include <string>

namespace nspanel_ha_blueprint {

    /**
    * @file pages.h
    * Defines constants and functions related to page names for the NSPanel HA Blueprint project.
    */

    // Constants
    /**
    * A compile-time constant array containing the names of pages.
    * These names correspond to various pages of the Nextion TFT file in use,
    * such as settings, home, weather information, and more.
    */
    constexpr std::array<const char*, 28> page_names = {
        "boot",
        "home",
        "weather01",
        "weather02",
        "weather03",
        "weather04",
        "weather05",
        "climate",
        "settings",
        "screensaver",
        "light",
        "cover",
        "buttonpage01",
        "buttonpage02",
        "buttonpage03",
        "buttonpage04",
        "notification",
        "qrcode",
        "entitypage01",
        "entitypage02",
        "entitypage03",
        "entitypage04",
        "fan",
        "alarm",
        "keyb_num",
        "media_player",
        "confirm",
        "utilities"
    };

    /**
    * Retrieves the index of a given page name within the page_names array.
    * 
    * @param page_name The name of the page to find.
    * @return The index of the page_name in the page_names array. If the page_name
    *         is not found, returns UINT8_MAX as an indicator that no matching page was found.
    */
    inline uint8_t get_page_id(const std::string& page_name) {
        for (uint8_t i = 0; i < page_names.size(); ++i) {
            if (strcmp(page_names[i], page_name.c_str()) == 0) {
                return i;
            }
        }
        return UINT8_MAX;
    }

}  // namespace nspanel_ha_blueprint
