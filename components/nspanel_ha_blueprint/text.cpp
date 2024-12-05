// text.cpp

#include "text.h"
#include <algorithm>
#include <cctype>
#include <cstring>

namespace nspanel_ha_blueprint {

    std::string adjustDecimalSeparator(const std::string& input, char decimalSeparator) {
        if (decimalSeparator == '.') {
            return input;
        }

        size_t numericEnd = 0;
        for (; numericEnd < input.size() && isNumberChar(input[numericEnd]); ++numericEnd);

        std::string numericPart = input.substr(0, numericEnd);
        std::string suffix = input.substr(numericEnd);

        char* end;
        double val = strtod(numericPart.c_str(), &end);

        if (end != numericPart.c_str() && *end == '\0') {
            size_t decimalPointPos = numericPart.find('.');
            if (decimalPointPos != std::string::npos) {
                numericPart[decimalPointPos] = decimalSeparator;
            }
            return numericPart + suffix;
        } else {
            return input;
        }
    }

    std::string process_time_format(const std::string &time_format, int current_hour,
                                    const std::string &meridiem_am, const std::string &meridiem_pm) {
        std::string processed_time_format = time_format;

        if (processed_time_format.find("%-H") != std::string::npos) {
            processed_time_format = processed_time_format.replace(
                processed_time_format.find("%-H"), sizeof("%-H") - 1, std::to_string(current_hour)
            );
        }

        if (processed_time_format.find("%-I") != std::string::npos) {
            if (current_hour > 12) {
                processed_time_format = processed_time_format.replace(
                    processed_time_format.find("%-I"), sizeof("%-I") - 1, std::to_string(current_hour - 12)
                );
            } else if (current_hour == 0) {
                processed_time_format = processed_time_format.replace(
                    processed_time_format.find("%-I"), sizeof("%-I") - 1, "12"
                );
            } else {
                processed_time_format = processed_time_format.replace(
                    processed_time_format.find("%-I"), sizeof("%-I") - 1, std::to_string(current_hour)
                );
            }
        }

        return processed_time_format;
    }

    uint32_t decode_utf8(const char* bytes) {
        if (!bytes || bytes[0] == '\0') {
            return 0;
        }
        uint32_t code_point = 0;
        unsigned char byte = static_cast<unsigned char>(bytes[0]);
        if ((byte & 0x80) == 0x00) {
            code_point = byte;
        } else if ((byte & 0xE0) == 0xC0 && bytes[1] != '\0') {
            code_point = ((byte & 0x1F) << 6) | (static_cast<unsigned char>(bytes[1]) & 0x3F);
        } else if ((byte & 0xF0) == 0xE0 && bytes[1] != '\0' && bytes[2] != '\0') {
            code_point = ((byte & 0x0F) << 12) |
                            ((static_cast<unsigned char>(bytes[1]) & 0x3F) << 6) |
                            (static_cast<unsigned char>(bytes[2]) & 0x3F);
        } else if ((byte & 0xF8) == 0xF0 && bytes[1] != '\0' && bytes[2] != '\0' && bytes[3] != '\0') {
            code_point = ((byte & 0x07) << 18) |
                            ((static_cast<unsigned char>(bytes[1]) & 0x3F) << 12) |
                            ((static_cast<unsigned char>(bytes[2]) & 0x3F) << 6) |
                            (static_cast<unsigned char>(bytes[3]) & 0x3F);
        } else {
            code_point = 0;
        }
        return code_point;
    }


}  // namespace nspanel_ha_blueprint
