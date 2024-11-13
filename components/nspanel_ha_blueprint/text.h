// text.h

#pragma once

#include <string>

namespace nspanel_ha_blueprint {

    /**
     * Copies the contents of a std::string to a fixed-size char array, ensuring
     * null termination. The destination array size is automatically deduced.
     * Designed for fixed-size char arrays only.
     * 
     * @param dest A reference to the destination char array.
     * @param src The source std::string to copy.
     */
    template <unsigned int N>
    void copyStringToCharArray(char (&dest)[N], const std::string& src);

    /**
     * Determines if a character is part of a numeric string. This includes digits,
     * a period (.), a minus sign (-), or a comma (,).
     * 
     * @param c The character to check.
     * @return True if the character is part of a number; false otherwise.
     */
    inline bool isNumberChar(char c);

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
     * Processes the given time format string by replacing specific placeholders with actual values.
     *
     * @param time_format The input time format string containing placeholders such as "%-H" and "%-I".
     * @param current_hour The current hour in 24-hour format (0-23).
     * @param meridiem_am The string representation for AM.
     * @param meridiem_pm The string representation for PM.
     * @return The processed time format string with placeholders replaced by the actual values.
      */
    std::string process_time_format(const std::string &time_format, int current_hour,
                                    const std::string &meridiem_am, const std::string &meridiem_pm);

    /**
    * @brief Decode the first UTF-8 character from a C-style string and return its Unicode code point.
    *
    * This function extracts and decodes the first character of a UTF-8 encoded string.
    * It determines how many bytes the UTF-8 character takes (1 to 4 bytes), and computes 
    * the corresponding Unicode code point.
    *
    * @param bytes A pointer to the UTF-8 encoded character (C-style string).
    * @return uint32_t The Unicode code point of the first character in the input string.
    */
    inline uint32_t decode_utf8(const char* bytes) {
        // Ensure the input is not null and not an empty string
        if (!bytes || bytes[0] == '\0') {
            return 0;  // Invalid input or empty string, return 0 as an error value
        }
        uint32_t code_point = 0;
        unsigned char byte = static_cast<unsigned char>(bytes[0]);
        if ((byte & 0x80) == 0x00) {
            // 1-byte UTF-8 character (ASCII), 0xxxxxxx
            code_point = byte;
        } else if ((byte & 0xE0) == 0xC0 && bytes[1] != '\0') {
            // 2-byte UTF-8 character, 110xxxxx 10xxxxxx
            code_point = ((byte & 0x1F) << 6) | (static_cast<unsigned char>(bytes[1]) & 0x3F);
        } else if ((byte & 0xF0) == 0xE0 && bytes[1] != '\0' && bytes[2] != '\0') {
            // 3-byte UTF-8 character, 1110xxxx 10xxxxxx 10xxxxxx
            code_point = ((byte & 0x0F) << 12) |
                          ((static_cast<unsigned char>(bytes[1]) & 0x3F) << 6) |
                          (static_cast<unsigned char>(bytes[2]) & 0x3F);
        } else if ((byte & 0xF8) == 0xF0 && bytes[1] != '\0' && bytes[2] != '\0' && bytes[3] != '\0') {
            // 4-byte UTF-8 character, 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
            code_point = ((byte & 0x07) << 18) |
                          ((static_cast<unsigned char>(bytes[1]) & 0x3F) << 12) |
                          ((static_cast<unsigned char>(bytes[2]) & 0x3F) << 6) |
                          (static_cast<unsigned char>(bytes[3]) & 0x3F);
        } else {
            // Invalid UTF-8 sequence, return 0 to indicate an error
            code_point = 0;
        }
        return code_point;  // Return the decoded Unicode code point
    }

}  // namespace nspanel_ha_blueprint
