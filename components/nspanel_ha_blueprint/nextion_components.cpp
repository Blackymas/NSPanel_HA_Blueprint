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

    template <typename Container>
    uint16_t rgbTo565(const Container& rgb) {
        if (rgb.size() != 3) {
            return UINT16_MAX;
        }
        return ((rgb[0] & 0xF8) << 8) | ((rgb[1] & 0xFC) << 3) | (rgb[2] >> 3);
    }

    // Template instantiation for std::vector<int>
    template uint16_t rgbTo565<std::vector<int>>(const std::vector<int>& rgb);

}  // namespace nspanel_ha_blueprint
