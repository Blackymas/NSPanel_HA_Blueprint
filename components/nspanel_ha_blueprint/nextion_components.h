// nextion_components.h

#pragma once

#include <string>
#include <vector>
#include <cstdint>

namespace nspanel_ha_blueprint {

    struct NextionComponent {
        char page[15];         // 14 characters + null terminator, representing the Nextion display page
        char component_id[15]; // 14 characters + null terminator, representing the component ID within the page
        bool is_current_page;  // Flag indicating whether the component is on the current page
    };

    /**
     * Extracts the page name and component ID from a given input string.
     * If the input string omits the page, a default page name is used.
     * Handles a special case for "alarm_control_panel" by shortening it to "alarm".
     *
     * @param input The input string containing the component ID, optionally prefixed by the page name and a dot.
     * @param defaultPage The default page name to use if the input string does not specify a page.
     * @return A NextionComponent struct with the extracted or default page name, component ID, and current page status.
     */
    NextionComponent extractNextionComponent(const std::string& input, const std::string& defaultPage);

    /**
     * Converts an RGB color represented as a vector of integers to the 16-bit 5-6-5 format supported by Nextion displays.
     * 
     * @param rgb A vector of integers with exactly three elements: [red, green, blue].
     * @return The color encoded in 16-bit 5-6-5 format, or UINT16_MAX if the input vector does not contain exactly three elements.
     */
    template <typename Container>
    uint16_t rgbTo565(const Container& rgb);

}  // namespace nspanel_ha_blueprint
