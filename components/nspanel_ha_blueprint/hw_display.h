// hw_display.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_HW_DISPLAY

#include <cstdint>
#include <vector>
#include "esphome/core/defines.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "pages.h"
#include "base.h"

namespace nspanel_ha_blueprint {

    extern uint8_t display_mode;
    extern uint8_t display_charset;

    /**
     * @brief Component visibility state with page association
     */
    struct ComponentVisibility {
        uint8_t page_id = UINT8_MAX;   // The page ID this component belongs to, default to MAX_UINT8
        char component[15] = {'\0'};   // Component identifier, default to an empty string
        bool visible = true;           // Visibility flag, default to true

        /**
         * @brief Constructor for ComponentVisibility
         * @param page_id The page ID this component belongs to
         * @param component Component identifier
         * @param visibility Visibility state
         */
        ComponentVisibility(uint8_t page_id, const char* component, bool visibility);
    };

    // Function declarations
    void setup_components_visibility();
    ComponentVisibility* find_component_visibility(uint8_t page_id, const char* component);
    ComponentVisibility* add_component_visibility(uint8_t page_id, const char* component, bool visibility);
    ComponentVisibility* get_component_visibility(uint8_t page_id, const char* component);
    std::vector<ComponentVisibility*> list_components_visibility_by_page(uint8_t page_id);
    void cleanup_components_visibility();

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_HW_DISPLAY
