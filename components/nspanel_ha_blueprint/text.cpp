// text.cpp

#include "text.h"
#include <algorithm>
#include <cctype>
#include <cstring>

namespace nspanel_ha_blueprint {

    template <unsigned int N>
    void copyStringToCharArray(char (&dest)[N], const std::string& src) {
        size_t length = std::min(src.size(), static_cast<size_t>(N - 1));
        std::strncpy(dest, src.c_str(), length);
        dest[length] = '\0';
    }

    // Explicit template instantiation might be needed depending on usage
    // template void copyStringToCharArray<YOUR_SIZE_HERE>(char (&)[YOUR_SIZE_HERE], const std::string&);

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
