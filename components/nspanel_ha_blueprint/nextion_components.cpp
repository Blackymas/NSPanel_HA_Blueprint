// nextion_components.cpp

#include "nextion_components.h"
#include <algorithm>
#include <cstring>

namespace nspanel_ha_blueprint {

    NextionComponent extractNextionComponent(const std::string& input, const std::string& defaultPage) {
        NextionComponent result{};
        size_t dotPos = input.find(".");

        if (dotPos != std::string::npos) {
            // Handling special case and standard extraction
            strncpy(result.page, input.substr(0, std::min<size_t>(dotPos, 14)).c_str(), 14);
            result.page[14] = '\0';  // Ensure null termination
            strncpy(result.component_id, input.substr(dotPos + 1, 14).c_str(), 14);
            result.component_id[14] = '\0';  // Ensure null termination
            result.is_current_page = false;
        } else {
            // Default page case
            strncpy(result.page, defaultPage.c_str(), 14);
            result.page[14] = '\0';  // Ensure null termination
            strncpy(result.component_id, input.c_str(), 14);
            result.component_id[14] = '\0';  // Ensure null termination
            result.is_current_page = true;
        }

        if (strcmp(result.page, defaultPage.c_str()) == 0) {
            result.is_current_page = true;
        }

        return result;
    }

}  // namespace nspanel_ha_blueprint
