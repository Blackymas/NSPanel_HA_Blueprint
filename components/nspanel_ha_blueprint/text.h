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

}  // namespace nspanel_ha_blueprint
