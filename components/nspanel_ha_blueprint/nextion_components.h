// nextion_components.h
#pragma once

#include <string>

namespace nspanel_ha_blueprint {

    struct NextionComponent {
        std::string page;
        std::string component_id;
        bool is_current_page;
    };

    /**
     * Extracts the page name and component ID from a given input string.
     * Handles a special case where "alarm_control_panel" should be shortened to "alarm".
     *
     * @param input The input string containing either the combined page and component ID or just the component ID.
     * @param defaultPage The default page name to use if the input string does not specify a page.
     * @return A NextionComponent struct containing the extracted or default page name, the component ID, and a flag indicating if it's the current page.
     */
    NextionComponent extractNextionComponent(const std::string& input, const std::string& defaultPage) {
        size_t dotPos = input.find(".");
        NextionComponent result;
        
        if (dotPos != std::string::npos) {
            // Extract page and component_id from the input string
            result.page = input.substr(0, dotPos);
            result.component_id = input.substr(dotPos + 1);
            result.is_current_page = false; // Since there's a dot, it's assumed not to be the current page

            // Check for the special case of "alarm_control_panel"
            if (result.page == "alarm_control_panel") {
                result.page = "alarm";
            }
        } else {
            // No dot found, the entire input is considered as component_id
            result.page = defaultPage;
            result.component_id = input;
            result.is_current_page = true; // No specific page mentioned, so it's the current page
        }

        // Check if the resolved page matches the defaultPage indicating it's the current page
        if (result.page == defaultPage) {
            result.is_current_page = true;
        }

        return result;
    }

}  // namespace nspanel_ha_blueprint
