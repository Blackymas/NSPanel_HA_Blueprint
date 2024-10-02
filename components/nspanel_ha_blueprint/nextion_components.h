// nextion_components.h

#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace nspanel_ha_blueprint {

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
    inline uint16_t rgbTo565(const int8_t rgb[3]) {
        return ((rgb[0] & 0xF8) << 8) |
               ((rgb[1] & 0xFC) << 3) |
                (rgb[2] >> 3);
    }
    inline uint16_t rgbTo565(const int16_t rgb[3]) {
        return ((rgb[0] & 0xF8) << 8) |
               ((rgb[1] & 0xFC) << 3) |
                (rgb[2] >> 3);
    }
    inline uint16_t rgbTo565(const int32_t rgb[3]) {
        return ((rgb[0] & 0xF8) << 8) |
               ((rgb[1] & 0xFC) << 3) |
                (rgb[2] >> 3);
    }
    inline uint16_t rgbTo565(const std::vector<int8_t>& rgb) {
        return ((static_cast<uint8_t>(rgb[0]) & 0xF8) << 8) |
               ((static_cast<uint8_t>(rgb[1]) & 0xFC) << 3) |
               (static_cast<uint8_t>(rgb[2]) >> 3);
    }
    inline uint16_t rgbTo565(const std::vector<int16_t>& rgb) {
        return ((static_cast<uint8_t>(rgb[0]) & 0xF8) << 8) |
               ((static_cast<uint8_t>(rgb[1]) & 0xFC) << 3) |
               (static_cast<uint8_t>(rgb[2]) >> 3);
    }
    inline uint16_t rgbTo565(const std::vector<int32_t>& rgb) {
        return ((static_cast<uint8_t>(rgb[0]) & 0xF8) << 8) |
               ((static_cast<uint8_t>(rgb[1]) & 0xFC) << 3) |
               (static_cast<uint8_t>(rgb[2]) >> 3);
    }

}  // namespace nspanel_ha_blueprint
