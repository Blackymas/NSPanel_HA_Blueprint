// nextion_components.h

#pragma once

namespace nspanel_ha_blueprint {

    /**
     * Converts RGB color components to the 16-bit 5-6-5 format supported by Nextion displays.
     *
     * This function takes individual red, green, and blue components, each in the range 0-255,
     * and converts them into a single uint16_t value in 5-6-5 format, commonly used for color displays.
     * The conversion process masks and shifts the components to fit into 5 bits for red, 6 bits for green,
     * and 5 bits for blue.
     *
     * @param red The red component of the RGB color, in the range 0-255.
     * @param green The green component of the RGB color, in the range 0-255.
     * @param blue The blue component of the RGB color, in the range 0-255.
     * @return The color encoded in 16-bit 5-6-5 format.
     */
    inline uint16_t rgbTo565(const uint8_t red, const uint8_t green, const uint8_t blue) {
        return ((red & 0xF8) << 8) |
               ((green & 0xFC) << 3) |
                (blue >> 3);
    }

}  // namespace nspanel_ha_blueprint
