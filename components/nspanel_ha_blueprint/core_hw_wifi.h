// core_hw_wifi.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_CORE_HW_WIFI

#ifndef CORE_HW_WIFI_H
#define CORE_HW_WIFI_H

#include <algorithm>
#include <cctype>
#include <string>
#include "esphome/core/log.h"

namespace nspanel_ha_blueprint {

    // Method to slugify a raw name
    std::string slugify(const std::string &raw_name) {
        std::string result;
        bool last_was_underscore = false;

        for (const char& c : raw_name) {
            if (isalnum(c)) {
                result += tolower(c);  // Add alphanumeric characters as lowercase
                last_was_underscore = false;
            } else if (!last_was_underscore) {  // Replace non-alphanumeric with '_', avoiding consecutive '_'
                result += '_';
                last_was_underscore = true;
            }
        }

        // Trim leading and trailing underscores
        if (!result.empty() && result.front() == '_') result.erase(0, 1);
        if (!result.empty() && result.back() == '_') result.pop_back();

        return result;
    }

    /**
    * Generate a device name based on a raw name, optionally appending a MAC address suffix.
    *
    * This function constructs a device name by taking the provided `raw_name` and appending
    * the last three bytes of the Wi-Fi MAC address as a suffix if available. If the MAC
    * address cannot be fetched or if Wi-Fi is not used, the function returns the raw name
    * unchanged.
    *
    * @param raw_name The base name for the device, provided as input.
    * @return A slugified string representing the generated device name.
    */
    std::string generate_device_name(const std::string &raw_name) {
        std::string full_name = raw_name;  // Start with the raw name

#ifdef ESP_MAC_WIFI_STA
        uint8_t mac[6];
        if (esp_read_mac(mac, ESP_MAC_WIFI_STA) == ESP_OK) {
            // Add MAC suffix if it can be read
            char hex_suffix[7];
            snprintf(hex_suffix, sizeof(hex_suffix), "%02X%02X%02X", mac[3], mac[4], mac[5]);
            full_name += "-" + std::string(hex_suffix);
#if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_WARNING
        } else {
            ESP_LOGW("generate_device_name", "Failed to read MAC address! Suffix not added.");
#endif  // ESPHOME_LOG_LEVEL
        }
#endif  // ESP_MAC_WIFI_STA

        return slugify(full_name);  // Slugify the name
    }

}  // namespace nspanel_ha_blueprint

#endif // CORE_HW_WIFI_H

#endif // NSPANEL_HA_BLUEPRINT_CORE_HW_WIFI
