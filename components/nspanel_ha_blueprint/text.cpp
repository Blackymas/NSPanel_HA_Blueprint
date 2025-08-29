// text.cpp

#include "text.h"
#include <algorithm>
#include <cctype>
#include <cstring>

namespace nspanel_ha_blueprint {

    bool isNumberChar(char c) {
        return std::isdigit(static_cast<unsigned char>(c)) || c == '.' || c == '-' || c == ',';
    }

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

}  // namespace nspanel_ha_blueprint
