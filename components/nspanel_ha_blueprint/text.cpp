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

        // Find the end of the numeric part
        size_t numericEnd = 0;
        for (; numericEnd < input.size(); ++numericEnd) {
            const char c = input[numericEnd];
            if (!((c >= '0' && c <= '9') || c == '.' || c == '-' || c == ',')) {
                break;
            }
        }

        // If no numeric part found, return original
        if (numericEnd == 0) {
            return input;
        }

        std::string numericPart = input.substr(0, numericEnd);

        // Validate that numericPart is actually a valid number
        char* end;
        strtod(numericPart.c_str(), &end);  // Result unused, only checking validity

        if (end != numericPart.c_str() && *end == '\0') {
            // Find and replace decimal point
            size_t decimalPointPos = numericPart.find('.');
            if (decimalPointPos != std::string::npos) {
                numericPart[decimalPointPos] = decimalSeparator;
            }

            // Append suffix if any
            if (numericEnd < input.size()) {
                numericPart += input.substr(numericEnd);
            }
            return numericPart;
        }

        return input;
    }

    std::string wrapText(const std::string& text_to_display,
                        uint8_t line_length_limit,
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

    bool isStringInList(const std::string& strToSearch, std::initializer_list<std::string> list) {
        for (const auto& str : list) {
            if (strToSearch == str) {
                return true;
            }
        }
        return false;
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
