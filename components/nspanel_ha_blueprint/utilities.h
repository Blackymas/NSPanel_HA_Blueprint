// utilities.h

#pragma once

#include <cstdint>
#include <cstring>  // For std::strcpy
#include <string>

namespace nspanel_ha_blueprint {

    struct UtilitiesGroupValues {
        char group_id[8];  // 7 characters + null terminator
        char value1[11];   // 10 characters + null terminator
        char value2[11];   // 10 characters + null terminator
        int8_t direction;
    };

    extern UtilitiesGroupValues *UtilitiesGroups;

    void resetUtilitiesGroups();
    void cleanupUtilitiesGroups();
    uint8_t findUtilitiesGroupIndex(const char* group_id);

    /**
     * Copies the contents of a std::string to a fixed-size char array, ensuring
     * null termination. The destination array size is automatically deduced.
     * Designed for fixed-size char arrays only.
     * 
     * @param dest A reference to the destination char array.
     * @param src The source std::string to copy.
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

}  // namespace nspanel_ha_blueprint
