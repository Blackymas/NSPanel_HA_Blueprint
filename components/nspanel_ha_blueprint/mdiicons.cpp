// mdiicons.cpp

#include "MdiIcons.h"
#include "esphome/core/log.h"

using namespace esphome;

// Setup method to allocate and initialize the icon pool
void MdiIcons::setup() {
    iconPool = new MdiIcon[iconPoolCapacity];  // Allocate memory for the icon pool
    if (!iconPool) {
        ESP_LOGE("MdiIcons", "Failed to allocate memory for icons in PSRAM");
        return;
    }
    memset(iconPool, 0, iconPoolCapacity * sizeof(MdiIcon));  // Initialize memory to zero
    ESP_LOGI("MdiIcons", "Icon pool initialized with capacity %u", iconPoolCapacity);
}

// Method to log the configuration of the icon pool
void MdiIcons::dump_config() {
    ESP_LOGCONFIG("MdiIcons", "MDI Icons component initialized with a pool capacity of %u", iconPoolCapacity);
}

// Method to find an icon by name. Returns a pointer to the icon if found, otherwise nullptr
const MdiIcon* MdiIcons::find_icon(const char* name) const {
    for (size_t i = 0; i < iconPoolSize; ++i) {
        if (strcmp(iconPool[i].name, name) == 0) {
            return &iconPool[i];
        }
    }
    return nullptr;
}

// Method to add a new icon to the pool. Checks for duplicates, resizes the pool if necessary, and adds the icon
bool MdiIcons::add_icon(const char* name, const char* code) {
    if (find_icon(name) != nullptr) {
        ESP_LOGW("MdiIcons", "Icon '%s' is already in the pool. Not adding again.", name);
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
    ESP_LOGI("MdiIcons", "New icon '%s' added to the pool.", name);
    return true;
}

// Method to double the capacity of the icon pool when it is full
void MdiIcons::resize_pool() {
    size_t newCapacity = iconPoolCapacity * 2;
    MdiIcon* newPool = new MdiIcon[newCapacity];
    if (!newPool) {
        ESP_LOGE("MdiIcons", "Failed to resize the icon pool");
        return;
    }
    memcpy(newPool, iconPool, iconPoolSize * sizeof(MdiIcon));
    delete[] iconPool;
    iconPool = newPool;
    iconPoolCapacity = newCapacity;
    ESP_LOGI("MdiIcons", "Icon pool resized to %u.", iconPoolCapacity);
}
