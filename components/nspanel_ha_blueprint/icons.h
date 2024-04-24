// icons.h
#pragma once

#include <cstdint>
#include <cstring>  // For strncpy and strcmp
#include <vector>

namespace nspanel_ha_blueprint {

    struct Icon {
        uint8_t page_id;           // Page ID, placed logically before the component
        char component[15];        // Component name (max 14 chars + null terminator)
        char last_icon_code[5];    // UTF-8 code (4 bytes + null terminator)
        uint16_t last_icon_color;  // Color value
        bool visible;              // Visibility of the icon

        // Constructor with default values
        Icon(uint8_t pid, const char* comp, const char* code = "\xEF\xBF\xBF", uint16_t color = UINT16_MAX, bool vis = true)
            : page_id(pid), last_icon_color(color), visible(vis) {
            strncpy(const_cast<char*>(component), comp, 14);  // Use const_cast to bypass const for initialization
            const_cast<char*>(component)[14] = '\0';          // Ensure null termination safely
            strncpy(last_icon_code, code, 4);
            last_icon_code[4] = '\0';
        }

        void updateIcon(const char* code, uint16_t color, bool vis);
    };

    extern std::vector<Icon> icons;  // Global list of icons

    Icon* findIcon(uint8_t page_id, const char* component);
}
