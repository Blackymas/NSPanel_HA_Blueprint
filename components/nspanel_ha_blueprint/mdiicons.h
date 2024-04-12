// mdiicons.h

#ifndef MDI_ICONS_H
#define MDI_ICONS_H

#include "esphome/core/component.h"
#include <cstring>

// Struct to hold individual icon data
struct MdiIcon {
    char name[32];  // Icon name, max length of 31 characters + null terminator
    char code[5];   // Icon code, max length of 4 bytes + null terminator (UTF-8 supported)
};

// Class to manage a dynamic pool of MDI icons stored in PSRAM
class MdiIcons : public esphome::Component {
 public:
    MdiIcons() : iconPool(nullptr), iconPoolSize(0), iconPoolCapacity(100) {}

    // Component setup override, initializes the icon pool
    void setup() override {
        iconPool = new MdiIcon[iconPoolCapacity];  // Allocate initial pool in PSRAM
        if (!iconPool) {
            ESP_LOGE("MdiIcons", "Failed to allocate memory for icons in PSRAM");
            return;
        }
        memset(iconPool, 0, iconPoolCapacity * sizeof(MdiIcon));  // Zero out the memory
        ESP_LOGI("MdiIcons", "Initialized icon pool with capacity %u", iconPoolCapacity);
    }

    // Logs the component configuration
    void dump_config() override {
        ESP_LOGCONFIG("MdiIcons", "MDI Icons: Initialized with pool capacity %u", iconPoolCapacity);
    }

    // Finds an icon by name, returns a pointer to the icon or nullptr if not found
    const MdiIcon* find_icon(const char* name) const {
        for (size_t i = 0; i < iconPoolSize; ++i) {
            if (strcmp(iconPool[i].name, name) == 0) {
                return &iconPool[i];
            }
        }
        return nullptr;
    }

    // Adds a new icon to the pool, returns true if successful, false if icon already exists
    bool add_icon(const char* name, const char* code) {
        if (find_icon(name) != nullptr) {
            ESP_LOGW("MdiIcons", "Icon %s is already in the pool", name);
            return false;
        }

        if (iconPoolSize >= iconPoolCapacity) {
            resize_pool();
        }

        strncpy(iconPool[iconPoolSize].name, name, sizeof(MdiIcon::name) - 1);
        strncpy(iconPool[iconPoolSize].code, code, sizeof(MdiIcon::code) - 1);
        iconPool[iconPoolSize].name[sizeof(MdiIcon::name) - 1] = '\0';
        iconPool[iconPoolSize].code[sizeof(MdiIcon::code) - 1] = '\0';
        iconPoolSize++;
        return true;
    }

 private:
    MdiIcon* iconPool;           // Pointer to the icon pool array
    size_t iconPoolSize;         // Current number of icons in the pool
    size_t iconPoolCapacity;     // Current maximum capacity of the pool

    // Resizes the icon pool to accommodate more icons, called when the current pool is full
    void resize_pool() {
        size_t newCapacity = iconPoolCapacity * 2;
        MdiIcon* newPool = new MdiIcon[newCapacity];
        if (!newPool) {
            ESP_LOGE("MdiIcons", "Failed to resize icon pool");
            return;
        }
        memcpy(newPool, iconPool, iconPoolSize * sizeof(MdiIcon));
        delete[] iconPool;
        iconPool = newPool;
        iconPoolCapacity = newCapacity;
        ESP_LOGI("MdiIcons", "Resized icon pool to capacity %u", iconPoolCapacity);
    }
};

#endif  // MDI_ICONS_H
