// pages.h
#pragma once

#include <array>
#include <cstring>
#include <cstdint>
#include <utility>
#include <string>
#include <initializer_list>

namespace nspanel_ha_blueprint {

    /**
    * @file pages.h
    * Defines constants and functions related to page names for "NSPanel HA Blueprint" project..
    */

    // Constants
    /**
    * A compile-time constant array containing the names of pages.
    * These names correspond to various pages of the Nextion TFT file in use,
    * such as settings, home, weather information, and more.
    */
    constexpr std::array<const char*, 28> page_names = {
        "home",
        "weather01",
        "weather02",
        "weather03",
        "weather04",
        "weather05",
        "climate",
        "settings",
        "boot",
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
                return i;  // Return the index if found
            }
        }
        return UINT8_MAX;  // Return UINT8_MAX if not found
    }

    /**
    * Checks if a given string is present within a list of strings.
    * 
    * This function provides a convenient way to search for the presence of a specific string
    * within a variably sized list of strings. It iterates through each string in the provided
    * list, comparing it against the target string for an exact match. This utility is particularly
    * useful for validating if a certain value matches any item from a predefined set of allowed
    * values.
    *
    * @param strToSearch The string to search for within the list. This is the target string
    *                    that the function will attempt to find an exact match for within the
    *                    provided list of strings.
    * @param list An initializer list of strings to search within. This list contains the strings
    *             against which the target string will be compared. The list is flexible in size,
    *             allowing for a variable number of strings to be specified.
    *
    * @return Returns `true` if the target string is found within the list, indicating an exact
    *         match was encountered. Returns `false` if the target string is not present in the
    *         list, indicating no matches were found.
    *
    * Usage Example:
    * ```cpp
    * std::string page = "alarm";
    * bool isPresent = isStringInList(page, {"alarm", "climate", "cover", "fan", "light", "media_player", "confirm", "keyb_num"});
    * if (!isPresent) {
    *     // The string 'page' was not found in the list
    * }
    * ```
    */
    bool isStringInList(const std::string& strToSearch, std::initializer_list<std::string> list) {
        for (const auto& str : list) {
            if (strToSearch == str) {
                return true;
            }
        }
        return false;
    }

}  // namespace nspanel_ha_blueprint
