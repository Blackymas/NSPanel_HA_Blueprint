// text.h

#pragma once

#include <array>
#include <cstring>
#include <string>
#include <algorithm>

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
    void copyStringToCharArray(char (&dest)[N], const std::string& src) {
        size_t length = std::min(src.size(), static_cast<size_t>(N - 1));
        std::strncpy(dest, src.c_str(), length);
        dest[length] = '\0';
    }

    inline bool starts_with(const char* str, const char* prefix) {
        return std::strncmp(str, prefix, std::strlen(prefix)) == 0;
    }

    inline bool isNumberChar(char c) {
        return std::isdigit(static_cast<unsigned char>(c)) || c == '.' || c == '-' || c == ',';
    }

    std::string adjustDecimalSeparator(const std::string& input, char decimalSeparator);

    std::string process_time_format(const std::string &time_format, int current_hour,
                                    const std::string &meridiem_am, const std::string &meridiem_pm);

    uint32_t decode_utf8(const char* bytes);

    inline std::string get_page_and_component(const std::string& page, const std::string& component) {
        return page + "." + component;
    }

}  // namespace nspanel_ha_blueprint
