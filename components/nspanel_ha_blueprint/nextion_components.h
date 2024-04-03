// nextion_components.h
#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace nspanel_ha_blueprint {

    struct NextionComponent {
        char page[15]; // 14 characters + null terminator
        char component_id[15]; // 14 characters + null terminator
        bool is_current_page;
    };

    /**
     * Extracts the page name and component ID from a given input string.
     * If the input string omits the page, uses defaultPage. 
     * Special case: "alarm_control_panel" is shortened to "alarm".
     *
     * @param input The input string containing the component ID, optionally prefixed by the page name and a dot.
     * @param defaultPage The default page name to use if the input string does not specify a page, limited to 14 characters.
     * @return A NextionComponent struct with the extracted or default page name, the component ID, and a flag for current page status.
     */
    NextionComponent extractNextionComponent(const std::string& input, const std::string& defaultPage) {
        NextionComponent result{};
        size_t dotPos = input.find(".");

        if (dotPos != std::string::npos) {
            if (input.compare(0, 20, "alarm_control_panel.") == 0) {
                strncpy(result.page, "alarm", sizeof(result.page) - 1);
                result.page[sizeof(result.page) - 1] = '\0';
            } else {
                // Copy up to the dot or 14 characters, whichever is smaller
                size_t lengthToCopy = std::min(dotPos, static_cast<size_t>(14));
                strncpy(result.page, input.c_str(), lengthToCopy);
                result.page[lengthToCopy] = '\0'; // Ensure null termination
            }

            // Extract and copy component_id
            const char* componentStart = input.c_str() + dotPos + 1;
            strncpy(result.component_id, componentStart, std::min(input.length() - dotPos - 1, static_cast<size_t>(14)));
            result.component_id[14] = '\0'; // Ensure null termination
            result.is_current_page = false;
        } else {
            // No dot found, use defaultPage and assume it's the current page
            strncpy(result.page, defaultPage.c_str(), 14);
            result.page[14] = '\0'; // Ensure null termination

            // Input is the component_id
            strncpy(result.component_id, input.c_str(), std::min(input.length(), static_cast<size_t>(14)));
            result.component_id[14] = '\0'; // Ensure null termination
            result.is_current_page = true;
        }

        // Additional check to see if the current page matches defaultPage
        if (strncmp(result.page, defaultPage.c_str(), 14) == 0) {
            result.is_current_page = true;
        }

        return result;
    }

    /**
     * Converts an RGB color represented as a vector of integers to the 16-bit 5-6-5 format supported by Nextion displays.
     *
     * This function takes a vector containing three integer values representing
     * the red, green, and blue components of an RGB color, each in the range 0-255.
     * It then converts these values into a single uint16_t value in 5-6-5 format,
     * commonly used for color displays. The conversion process masks and shifts
     * the components to fit into the 5 bits for red, 6 bits for green, and 5 bits for blue.
     *
     * @param rgb A vector of integers with exactly three elements: [red, green, blue].
     * @return The color encoded in 16-bit 5-6-5 format, or UINT16_MAX if the input vector
     * does not contain at least three elements.
     */
    template <typename Container>
    inline uint16_t rgbTo565(const Container& rgb) {
        if (rgb.size() != 3) {
            return UINT16_MAX; // Use UINT16_MAX as an error indicator
        }
        return ((rgb[0] & 0xF8) << 8) | ((rgb[1] & 0xFC) << 3) | (rgb[2] >> 3);
    }

}  // namespace nspanel_ha_blueprint
