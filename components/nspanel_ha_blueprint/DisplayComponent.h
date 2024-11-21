// DisplayComponent.h

#ifndef DISPLAY_COMPONENT_H
#define DISPLAY_COMPONENT_H

#include <vector>
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "pages.h"

namespace nspanel_ha_blueprint {

    static const char* TAG_COMPONENTS = "nspanel_ha_blueprint.components";

    struct DisplayComponent {
        uint8_t page_id = UINT8_MAX;   // The page ID this component belongs to, default to MAX_UINT8
        char component[15] = {'\0'};   // Component identifier, default to an empty string
        char text[101] = {'\0'};       // Text content, default to an empty string
        uint16_t color = UINT16_MAX;   // RGB565 color value, default to MAX_UINT16
        uint8_t font = UINT8_MAX;      // Font identifier, default to MAX_UINT8
        bool visible = true;           // Visibility flag, default to true
        bool initialized = false;      // Indicates if the component has been properly initialized

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
    void cleanup_components();

}  // namespace nspanel_ha_blueprint

#endif // DISPLAY_COMPONENT_H
