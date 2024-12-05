// core_hw_display.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_CORE_HW_DISPLAY

#ifndef CORE_HW_DISPLAY_H
#define CORE_HW_DISPLAY_H

#include <vector>
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "pages.h"
#include "core_base.h"

namespace nspanel_ha_blueprint {

    struct DisplayComponent {
        uint8_t page_id = UINT8_MAX;   // The page ID this component belongs to, default to MAX_UINT8
        char component[15] = {'\0'};   // Component identifier, default to an empty string
        char text[101] = {'\0'};       // Text content, default to an empty string
        uint16_t color = UINT16_MAX;   // RGB565 color value, default to MAX_UINT16
        uint8_t font = UINT8_MAX;      // Font identifier, default to MAX_UINT8
        bool visible = true;           // Visibility flag, default to true
        bool global = false;           // Is it a global variable from Nextion perspective
        bool text_is_updated = true;   // Indicates if text content has been updated, default to true
        bool color_is_updated = true;  // Indicates if color has been updated, default to true
        bool font_is_updated = true;   // Indicates if font has been updated, default to true
        bool visible_is_updated = true;// Indicates if visibility has been updated, default to true

        DisplayComponent(uint8_t page_id, const char* component, const char* content,
                            uint16_t color, uint8_t font, bool visibility);
    };

    // Function declarations
    void setup_components();
    DisplayComponent* find_component(uint8_t page_id, const char* component);
    DisplayComponent* add_component(uint8_t page_id, const char* component, const char* content,
                                    uint16_t color, uint8_t font, bool visibility);
    DisplayComponent* get_component(uint8_t page_id, const char* component);
    std::vector<DisplayComponent*> list_components_by_page(uint8_t page_id);

    // Function to flag all attributes as not updated for all components on a specific page
    void reset_updates_by_page(uint8_t page_id);

    void cleanup_components();

    inline uint16_t color565(const std::vector<int8_t> &color888) {
        return ((color888[0] & 0xF8) << 8) | ((color888[1] & 0xFC) << 3) | (color888[2] >> 3);
    }
    inline uint16_t color565(const std::vector<int16_t> &color888) {
        return ((color888[0] & 0xF8) << 8) | ((color888[1] & 0xFC) << 3) | (color888[2] >> 3);
    }
    inline uint16_t color565(const std::vector<int32_t> &color888) {
        return ((color888[0] & 0xF8) << 8) | ((color888[1] & 0xFC) << 3) | (color888[2] >> 3);
    }

}  // namespace nspanel_ha_blueprint

#endif // CORE_HW_DISPLAY_H

#endif // NSPANEL_HA_BLUEPRINT_CORE_HW_DISPLAY
