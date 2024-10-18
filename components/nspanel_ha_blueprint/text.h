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

}  // namespace nspanel_ha_blueprint