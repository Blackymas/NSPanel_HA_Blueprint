// utilities.cpp

#include "utilities.h"
#include <cstdlib> // For malloc/free
#ifdef USE_ESP_IDF
#include "esp_heap_caps.h"
#elif defined(USE_ARDUINO)
#include "esp32-hal-psram.h"
#endif

namespace nspanel_ha_blueprint {

    UtilitiesGroupValues *UtilitiesGroups = nullptr;

    static constexpr size_t UTILITIES_GROUPS_COUNT = 8;

    void resetUtilitiesGroups() {
        #ifdef USE_ESP_IDF
        UtilitiesGroups = static_cast<UtilitiesGroupValues*>(
            heap_caps_malloc(UTILITIES_GROUPS_COUNT * sizeof(UtilitiesGroupValues), MALLOC_CAP_SPIRAM));
        #elif defined(USE_ARDUINO)
        UtilitiesGroups = static_cast<UtilitiesGroupValues*>(
            ps_malloc(UTILITIES_GROUPS_COUNT * sizeof(UtilitiesGroupValues)));
        #endif  // USE_ESP_IDF
        
        if (!UtilitiesGroups) UtilitiesGroups = new UtilitiesGroupValues[UTILITIES_GROUPS_COUNT];
        if (!UtilitiesGroups) return;
    
        static constexpr UtilitiesGroupValues INITIAL_UTILITIES_GROUPS[UTILITIES_GROUPS_COUNT] = {
            {"grid", "", "", 0},      // Use "" instead of "\0" for clarity
            {"group01", "", "", 0},
            {"group02", "", "", 0},
            {"group03", "", "", 0},
            {"group04", "", "", 0},
            {"group05", "", "", 0},
            {"group06", "", "", 0},
            {"home", "", "", 0}
        };
    
        std::memcpy(UtilitiesGroups, INITIAL_UTILITIES_GROUPS, UTILITIES_GROUPS_COUNT * sizeof(UtilitiesGroupValues));
    }

    uint8_t findUtilitiesGroupIndex(const char* group_id) {
        int low = 0;
        int high = 7;  // Directly use the number of elements in UtilitiesGroups - 1

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cmp = std::strcmp(UtilitiesGroups[mid].group_id, group_id);

            if (cmp < 0) {
                low = mid + 1;
            } else if (cmp > 0) {
                high = mid - 1;
            } else {
                return static_cast<uint8_t>(mid);  // Found
            }
        }

        return UINT8_MAX;  // Not found
    }

}  // namespace nspanel_ha_blueprint
