// mdiicons.cpp

#include "mdiicons.h"
#include "esphome/core/log.h"

using namespace esphome;

MdiIcons::MdiIcons() : iconPool(nullptr), iconPoolSize(0), iconPoolCapacity(100) {}

void MdiIcons::setup() {
    iconPool = new MdiIcon[iconPoolCapacity];
    if (!iconPool) {
        ESP_LOGE("MdiIcons", "Failed to allocate memory for icons in PSRAM");
        return;
    }
    memset(iconPool, 0, iconPoolCapacity * sizeof(MdiIcon));
    ESP_LOGI("MdiIcons", "Icon pool initialized with capacity %u", iconPoolCapacity);
}

void MdiIcons::dump_config() {
    ESP_LOGCONFIG("MdiIcons", "MDI Icons: Initialized with pool capacity %u", iconPoolCapacity);
}

const MdiIcon* MdiIcons::find_icon(const char* name) const {
    for (size_t i = 0; i < iconPoolSize; ++i) {
        if (strcmp(iconPool[i].name, name) == 0) {
            return &iconPool[i];
        }
    }
    return nullptr;
}

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
