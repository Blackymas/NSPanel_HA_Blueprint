// icons.cpp
#include "icons.h"
#include <vector>
#ifdef USE_PSRAM
    #ifdef USE_ARDUINO
        #include <esp32-hal-psram.h>
    #else  // ESP-IDF
        #include <esp_heap_caps.h>  // Required for heap capabilities functions
    #endif  // ARDUINO vs ESP-IDF
#endif  // USE_PSRAM

namespace nspanel_ha_blueprint {

    std::vector<Icon> icons;  // This declaration may not be necessary; see below

    bool initializeIconsVector() {
        Icon* allocatedMemory = nullptr;

        // Try to allocate the vector in PSRAM
        #ifdef USE_PSRAM
            #if defined(USE_ARDUINO)
                if (psramFound())
                    allocatedMemory = static_cast<Icon*>(ps_malloc(10 * sizeof(Icon)));
            #else // ESP-IDF
                allocatedMemory = static_cast<Icon*>(heap_caps_malloc(10 * sizeof(Icon), MALLOC_CAP_SPIRAM));
            #endif

            if (allocatedMemory != nullptr) {
                new (&icons) std::vector<Icon>(allocatedMemory, allocatedMemory + 10); // Placement new to initialize vector
                return true; // Successfully allocated in PSRAM
            }
        #endif

        // Fallback to DRAM if PSRAM allocation fails or if PSRAM is not used
        allocatedMemory = static_cast<Icon*>(malloc(10 * sizeof(Icon)));
        if (allocatedMemory != nullptr) {
            new (&icons) std::vector<Icon>(allocatedMemory, allocatedMemory + 10); // Placement new to initialize vector
            return true;  // Successfully allocated in DRAM
        }

        return false;  // Allocation failed
    }

    void Icon::updateIcon(const char* code, uint16_t color, bool vis) {
        if (strcmp(last_icon_code, code) != 0 || last_icon_color != color || visible != vis) {
            strncpy(last_icon_code, code, 4);
            last_icon_code[4] = '\0';
            last_icon_color = color;
            visible = vis;
        }
    }

    Icon* findIcon(uint8_t page_id, const char* comp) {
        for (auto& icon : icons) {
            if (icon.page_id == page_id && strcmp(icon.component, comp) == 0) {
                return &icon;
            }
        }
        return nullptr;
    }
}
