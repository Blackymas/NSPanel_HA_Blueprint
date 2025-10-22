// text.h

#pragma once

#include <string>

namespace nspanel_ha_blueprint {

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

    /**
    * Checks if a given string is present within a list of strings.
    * 
    * @param strToSearch The string to search for within the list.
    * @param list An initializer list of strings to search within.
    * @return `true` if the target string is found within the list, `false` otherwise.
    */
    bool isStringInList(const std::string& strToSearch, std::initializer_list<std::string> list);

    uint32_t decode_utf8(const char* bytes);

    /**
    * @brief Compile-time string comparison for C++17/20.
    *
    * Compares two null-terminated C-strings at compile time.
    * This function is constexpr-compatible and can be used in
    * compile-time contexts where std::strcmp is not available
    * (std::strcmp becomes constexpr only in C++23).
    *
    * @param a First null-terminated string to compare.
    * @param b Second null-terminated string to compare.
    * @return true if strings are identical, false otherwise.
    *
    * @note Both pointers must be valid and point to null-terminated strings.
    * @note Comparison stops at the first difference or null terminator.
    *
    * Example usage:
    * @code
    * constexpr bool is_home = strings_equal(page_names[1], "home");
    * static_assert(strings_equal("test", "test"));  // Compile-time check
    * @endcode
    */
    constexpr bool strings_equal(const char* a, const char* b) {
        // Compare characters while both strings have non-null characters
        while (*a && *b) {
            if (*a != *b) return false;  // Different characters found
            ++a;
            ++b;
        }
        // Strings are equal only if both reached null terminator
        return *a == *b;
    }

}  // namespace nspanel_ha_blueprint
