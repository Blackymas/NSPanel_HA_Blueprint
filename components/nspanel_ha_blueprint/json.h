// json.h
#pragma once

#include "cJSON.h"
#include <cmath>
#include <cstdio>
#include <cstring>

// The `nspanel_ha_blueprint` namespace encapsulates utility functions for JSON manipulation
// tailored for the NSPanel Home Assistant Blueprint project.
namespace nspanel_ha_blueprint {

    /**
     * Compares the string value of a cJSON object with a target C-string.
     * 
     * This function checks if the given cJSON object is not NULL, is a string type,
     * and its value matches the target string provided.
     * 
     * @param json_item The cJSON object whose string value is to be compared.
     * @param target_str The target C-string to compare against the cJSON object's value.
     * @return True if the cJSON object's string value matches the target string, false otherwise.
     */
    bool json_cmp_string(const cJSON* json_item, const char* target_str) {
        if (json_item != NULL && cJSON_IsString(json_item) && json_item->valuestring != NULL) {
            return strcmp(json_item->valuestring, target_str) == 0;
        }
        return false;
    }

    /**
     * Compares the integer value of a cJSON object with a target unsigned integer.
     * 
     * This function checks if the given cJSON object is not NULL, represents a number,
     * and its integer value matches the target unsigned integer provided. It's particularly
     * useful for JSON fields that are expected to contain numeric boolean values (e.g., 0 or 1)
     * or other unsigned integer values.
     * 
     * @param json_item The cJSON object whose integer value is to be compared.
     * @param target_uint The target unsigned integer to compare against the cJSON object's value.
     * @return True if the cJSON object's integer value matches the target unsigned integer, false otherwise.
     */
    bool json_cmp_uint(const cJSON* json_item, unsigned int target_uint) {
        if (json_item != NULL && cJSON_IsNumber(json_item)) {
            return (unsigned int)json_item->valueint == target_uint;
        }
        return false;
    }

    /**
     * Retrieves a floating-point value from a cJSON object.
     *
     * @param json_item The cJSON object from which to retrieve the value.
     * @return The floating-point value of the cJSON object if it is a number, NaN otherwise.
     */
    float json_get_float(const cJSON* json_item) {
        if (json_item != NULL && cJSON_IsNumber(json_item)) {
            return static_cast<float>(json_item->valuedouble);
        }
        return std::nan(""); // Return NaN if not a valid number
    }

    /**
    * Converts a JSON integer percentage value to a string representing a floating-point number between 0.00 and 1.00.
    *
    * @param json_item The cJSON object containing the integer percentage value.
    * @return A string representation of the floating-point number, or an empty string if the input is invalid.
    */
    std::string json_percentage_to_float_string(const cJSON* json_item) {
        // Ensure the item is a valid number
        if (json_item != NULL && cJSON_IsNumber(json_item)) {
            // Convert the integer percentage to a float between 0.00 and 1.00
            float percentage = static_cast<float>(json_item->valueint) / 100.0f;
            
            // Buffer to hold the formatted string, large enough for "0.00" plus null terminator
            char buffer[8];
            
            // Format the floating-point number with two decimal places
            snprintf(buffer, sizeof(buffer), "%.2f", percentage);
            
            // Return the formatted string
            return std::string(buffer);
        }
        
        // Return an empty string to indicate invalid input or non-numeric JSON item
        return "";
    }

}  // namespace nspanel_ha_blueprint
