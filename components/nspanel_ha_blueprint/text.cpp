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

    std::string wrapText(const std::string& text_to_display,
                        uint16_t line_length_limit,
                        uint8_t bytes_per_char) {
        // Safety check for overly long text
        if (text_to_display.length() > 1000) {
            return "ERROR: Text too long";
        }

        // Early exit for already formatted text
        if (text_to_display.find("\\r") != std::string::npos) {
            return text_to_display;
        }

        const uint16_t max_line_length = line_length_limit * bytes_per_char;
        const uint16_t text_len = static_cast<uint16_t>(text_to_display.length());

        // If text is short enough, no wrapping needed
        if (text_len <= max_line_length) {
            return text_to_display;
        }

        // Pre-allocate string to avoid reallocations - optimize for flash memory
        std::string wrapped_text;
        wrapped_text.reserve(text_len + 20);  // Reserve space for line breaks

        uint16_t start = 0;

        while (start < text_len) {
            // Skip leading spaces
            while (start < text_len && text_to_display[start] == ' ') {
                ++start;
            }

            if (start >= text_len) {
                break;  // End of text reached
            }  // if

            // Find end position
            uint16_t end = start + max_line_length;
            if (end >= text_len) {
                end = text_len;
            } else {
                // Find word boundary by looking backwards for space
                uint16_t word_end = end;
                while (word_end > start && text_to_display[word_end] != ' ') {
                    --word_end;
                }

                // If we found a space within reasonable distance, use it
                if (word_end > start) {
                    end = word_end;
                }
                // Otherwise force break at max_line_length (handles long words)
            }  // else

            // Add text segment
            wrapped_text.append(text_to_display, start, end - start);

            // Add line break if not at end of text
            if (end < text_len) {
                wrapped_text += "\\r";

                // Skip spaces at the break point to avoid leading spaces on next line
                while (end < text_len && text_to_display[end] == ' ') {
                    ++end;
                }
            }  // if

            start = end;
        }  // while

        return wrapped_text;
    }

}  // namespace nspanel_ha_blueprint
