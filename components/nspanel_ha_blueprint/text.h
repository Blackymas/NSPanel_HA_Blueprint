// text.h
#pragma once

#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

namespace nspanel_ha_blueprint {

    /**
     * Copies the contents of a std::string to a fixed-size char array, ensuring
     * null termination of the string within the array. This function template
     * automatically deduces the size of the destination char array at compile time,
     * minimizing the risk of buffer overflow. It's designed for use with fixed-size
     * char arrays only, not pointers or dynamically allocated memory.
     * 
     * Template Parameter:
     * N - The size of the destination char array. This value is deduced automatically
     *     and must be greater than 0.
     * 
     * Parameters:
     * dest - A reference to the destination char array where the string should be copied.
     *        The array must have a size that can accommodate the source string plus a
     *        null terminator. If the source string is longer than the destination array,
     *        it will be truncated.
     * src - The source std::string to copy. This string's contents are copied into the
     *       destination array up to the array's capacity minus one, to leave space for
     *       the null terminator.
     * 
     * Usage Example:
     * char destination[11];
     * std::string source = "Hello";
     * nspanel_ha_blueprint::copyStringToCharArray(destination, source);
     * 
     * Note: The destination array is always null-terminated, even if the source string
     * is truncated to fit into the array.
     */
    template <unsigned int N>
    void copyStringToCharArray(char (&dest)[N], const std::string& src) {
        // Ensure we do not exceed the buffer size, leaving space for the null terminator
        size_t length = std::min(src.size(), N - 1);

        // Copy the string data into the destination buffer
        std::strncpy(dest, src.c_str(), length);

        // Explicitly null-terminate the destination buffer
        dest[length] = '\0';
    }

    // Helper function to determine if a character is part of a number
    bool isNumberChar(char c) {
        return std::isdigit(c) || c == '.' || c == '-' || c == ',';
    }

    /**
    * Adjusts the decimal separator in a numeric string to a specified character.
    * This function identifies and modifies the decimal separator of a number within a string,
    * ensuring that only the first occurrence is replaced if it is a valid number followed by
    * any non-numeric characters (e.g., units of measurement). If the input string does not 
    * start with a valid number, it is returned unchanged.
    * 
    * @param input The string potentially containing a numeric value followed by text.
    * @param decimalSeparator The character to use as the decimal separator.
    * @return A string with the decimal separator adjusted if the input is a valid number,
    *         otherwise the original input string.
    */
    std::string adjustDecimalSeparator(const std::string& input, char decimalSeparator) {
        // Immediately return the original string if the desired decimal separator is "."
        if (decimalSeparator == '.') {
            return input;
        }

        // Find the end of the numeric part of the string
        size_t numericEnd = 0;
        for (; numericEnd < input.size() && isNumberChar(input[numericEnd]); ++numericEnd);

        // Extract the numeric part and the suffix (if any)
        std::string numericPart = input.substr(0, numericEnd);
        std::string suffix = input.substr(numericEnd);

        // Attempt to convert the numeric part to a double
        char* end;
        double val = strtod(numericPart.c_str(), &end);

        // Check if conversion was successful (end points to a null terminator if so)
        if (end != numericPart.c_str() && *end == '\0') {
            // Find and replace only the first occurrence of '.' with the specified decimalSeparator
            size_t decimalPointPos = numericPart.find('.');
            if (decimalPointPos != std::string::npos) {
                numericPart[decimalPointPos] = decimalSeparator;
            }
            return numericPart + suffix;
        } else {
            // If the input is not a number, return it as is
            return input;
        }
    }

}  // namespace nspanel_ha_blueprint
