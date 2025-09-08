// text.h

#pragma once

#include <string>

namespace nspanel_ha_blueprint {

    /**
     * Determines if a character is part of a numeric string. This includes digits,
     * a period (.), a minus sign (-), or a comma (,).
     *
     * @param c The character to check.
     * @return True if the character is part of a number; false otherwise.
     */
    bool isNumberChar(char c);

    /**
     * Adjusts the decimal separator in a numeric string to the specified character.
     * Only the first occurrence is replaced if it's a valid number followed by text.
     * Returns the original string if it doesn't start with a valid number.
     *
     * @param input The string containing a numeric value followed by text.
     * @param decimalSeparator The character to use as the decimal separator.
     * @return A string with the adjusted decimal separator if valid; otherwise, the original string.
     */
    std::string adjustDecimalSeparator(const std::string& input, char decimalSeparator);

    /**
     * Wraps text to fit within specified line length limits for Nextion displays.
     * Uses word boundaries when possible and adds "\\r" line breaks for Nextion compatibility.
     *
     * Performance optimized for ESP32 with minimal memory allocations and flash usage.
     * Supports both Arduino and ESP-IDF frameworks.
     *
     * @param text_to_display The input text to be wrapped. If already contains "\\r", returns as-is.
     * @param line_length_limit Maximum number of characters per line (will be multiplied by bytes_per_char).
     * @param bytes_per_char Multiplier for character width calculation (typically from mui_bytes_per_char).
     * @return Wrapped text with "\\r" line breaks as std::string.
     *
     * @note Uses "\\r" as line break separator for Nextion display compatibility.
     * @note Skips leading/trailing spaces and handles word boundaries intelligently.
     * @note Returns original text if already formatted or if no wrapping is needed.
     * @note Thread-safe: No shared state between calls.
     */
    std::string wrapText(const std::string& text_to_display,
                        uint8_t line_length_limit,
                        uint8_t bytes_per_char);

}  // namespace nspanel_ha_blueprint
