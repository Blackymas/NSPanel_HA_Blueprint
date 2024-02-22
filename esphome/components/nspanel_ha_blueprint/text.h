// text.h
#pragma once

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
    template<size_t N>
    void copyStringToCharArray(char (&dest)[N], const std::string& src) {
        static_assert(N > 0, "Destination array size must be greater than 0.");

        // Copy up to N - 1 characters to ensure there's room for the null terminator
        std::strncpy(dest, src.c_str(), N - 1);

        // Manually null-terminate the destination array
        dest[N - 1] = '\0';
    }

}  // namespace nspanel_ha_blueprint
