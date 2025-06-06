#include "hw_wifi.h"

#ifdef NSPANEL_HA_BLUEPRINT_CORE_HW_WIFI

#include <cstring>
#include <cstdio>
#include <cctype>

namespace nspanel_ha_blueprint {

    // Internal buffer for storing the generated device name
    static char device_name_[32] = "nspanel-unset";

    void set_device_name(const char* raw_name) {
        char temp[64] = {0};
        std::snprintf(temp, sizeof(temp), "%s", raw_name);

#ifdef ESP_MAC_WIFI_STA
        uint8_t mac[6];
        if (esp_read_mac(mac, ESP_MAC_WIFI_STA) == ESP_OK) {
            char suffix[8];
            std::snprintf(suffix, sizeof(suffix), "-%02x%02x%02x", mac[3], mac[4], mac[5]);
            std::strncat(temp, suffix, sizeof(temp) - std::strlen(temp) - 1);
        }
#endif

        // Slugify for HA: lowercase, alphanumeric or '_', max 31
        size_t j = 0;
        bool last_was_underscore = false;
        for (size_t i = 0; temp[i] != '\0' && j < sizeof(device_name_) - 1; ++i) {
        char c = std::tolower(temp[i]);
        if (std::isalnum(c)) {
            device_name_[j++] = c;
            last_was_underscore = false;
        } else if (!last_was_underscore) {
            device_name_[j++] = '_';
            last_was_underscore = true;
        }
        }

        // Trim trailing underscore
        while (j > 0 && device_name_[j - 1] == '_') --j;
        device_name_[j] = '\0';
    }

    const char* get_device_name() {
        return device_name_;
    }

}

#endif  // NSPANEL_HA_BLUEPRINT_CORE_HW_WIFI
