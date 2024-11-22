// pages.cpp

#include "pages.h"

namespace nspanel_ha_blueprint {

    // Definition of the global current_page_id
    uint8_t current_page_id = 0;

    // Definition of the global previous_page_id
    DRAM_ATTR uint8_t previous_page_id = 0;

    // Move page names to PSRAM by using DRAM_ATTR
    DRAM_ATTR char page_names[29][15] = {
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
        "utilities",
        "home_smpl"
    };

    // Move masks to PSRAM by using DRAM_ATTR or other similar attributes for ESP32
    DRAM_ATTR uint32_t ENTITY_PAGE_MASK = (1 << 18) | (1 << 19) | (1 << 20) | (1 << 21);
    DRAM_ATTR uint32_t BUTTON_PAGE_MASK = (1 << 12) | (1 << 13) | (1 << 14) | (1 << 15);
    DRAM_ATTR uint32_t WEATHER_PAGE_MASK = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6);
    DRAM_ATTR uint32_t ENTITY_ID_PAGE_MASK = (1 << 24) | (1 << 7) | (1 << 11) | (1 << 22) |
                                            (1 << 10) | (1 << 25) | (1 << 27) | (1 << 23);

    // Implementation of is_page_in_group
    bool is_page_in_group(uint32_t group_mask, uint8_t page_id) {
        if (page_id >= sizeof(page_names) / sizeof(page_names[0])) {
            return false;  // Invalid page_id, safely return false
        }
        return (group_mask & (1 << page_id)) != 0;
    }

    // Implementation of get_page_id
    uint8_t get_page_id(const std::string& page_name) {
        for (uint8_t i = 0; i < sizeof(page_names) / sizeof(page_names[0]); ++i) {
            if (strcmp(page_names[i], page_name.c_str()) == 0) {
                return i;
            }
        }
        return UINT8_MAX;
    }

}  // namespace nspanel_ha_blueprint
