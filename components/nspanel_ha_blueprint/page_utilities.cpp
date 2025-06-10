// page_utilities.cpp

#ifdef NSPANEL_HA_BLUEPRINT_STANDARD_PAGE_UTILITIES

#include "page_utilities.h"
#include "esphome/core/log.h"
#include "esphome/core/helpers.h"

namespace nspanel_ha_blueprint {

    UtilitiesGroupValues *UtilitiesGroups = nullptr;

    void resetUtilitiesGroups() {
        ESP_LOGD(TAG_COMPONENT, "Alloc UtilitiesGroups array (PSRAM)");
        // Allocate PageButtonsButton dynamically
        esphome::ExternalRAMAllocator<UtilitiesGroupValues> allocator(esphome::ExternalRAMAllocator<UtilitiesGroupValues>::ALLOW_FAILURE);
        UtilitiesGroups = allocator.allocate(sizeof(UtilitiesGroupValues));
        if (!UtilitiesGroups or UtilitiesGroups == nullptr) {
            ESP_LOGE(TAG_COMPONENT, "UtilitiesGroups alloc failed");
            return;  // Memory allocation failed, do not proceed
        }
        ESP_LOGD(TAG_COMPONENT, "UtilitiesGroups ready");

        if (!UtilitiesGroups) UtilitiesGroups = new (std::nothrow) UtilitiesGroupValues[8];  // Fallback to internal SRAM if PSRAM is not available or not supported
        if (!UtilitiesGroups) return;                                         // Fail nicely if no memory is available

        // Initialize UtilitiesGroups with default values
        const UtilitiesGroupValues initialUtilitiesGroups[8] = {
            {"grid", "\0", "\0", 0},
            {"group01", "\0", "\0", 0},
            {"group02", "\0", "\0", 0},
            {"group03", "\0", "\0", 0},
            {"group04", "\0", "\0", 0},
            {"group05", "\0", "\0", 0},
            {"group06", "\0", "\0", 0},
            {"home", "\0", "\0", 0}
        };

        for (size_t i = 0; i < 8; ++i) {
            std::strcpy(UtilitiesGroups[i].group_id, initialUtilitiesGroups[i].group_id);
            std::strcpy(UtilitiesGroups[i].value1, initialUtilitiesGroups[i].value1);
            std::strcpy(UtilitiesGroups[i].value2, initialUtilitiesGroups[i].value2);
            UtilitiesGroups[i].direction = initialUtilitiesGroups[i].direction;
        }
    }

    void cleanupUtilitiesGroups() {
        if (UtilitiesGroups != nullptr) {
            free(UtilitiesGroups);      // Compatible with both heap_caps_malloc and ps_malloc
            UtilitiesGroups = nullptr;  // Prevent dangling pointers
        }
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

#endif  // NSPANEL_HA_BLUEPRINT_STANDARD_PAGE_UTILITIES
