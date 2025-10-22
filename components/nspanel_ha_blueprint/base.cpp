// base.cpp
#include "base.h"
#include "esphome/core/application.h"

namespace nspanel_ha_blueprint {

    static const char *TAG_COMPONENT_BASE = "nspanel.component.base";

    // Define the global system flags variable (starts with all flags false via default constructor)
    SystemFlags system_flags{};

    // Define the global blueprint status flags variable (starts with all flags false via default constructor)
    BlueprintStatusFlags blueprint_status_flags{};

    // Cached device name to avoid repeated lookups and string copies
    std::string cached_device_name;

    // Fire a Home Assistant event for NSPanel HA Blueprint
    void fire_ha_event(const std::string &type, std::map<std::string, std::string> data) {
        // Add device name and type to the event data
        data["device_name"] = cached_device_name;
        data["type"] = type;

        // Log the event being fired
        ESP_LOGD(TAG_COMPONENT_BASE, "Firing HA event: %s", type.c_str());

        // Log additional data if verbose logging is enabled
        #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_VERBOSE
        for (const auto &[key, value] : data) {
            ESP_LOGVV(TAG_COMPONENT_BASE, "  Event data: %s=%s", key.c_str(), value.c_str());
        }
        #endif

        // Create API device and fire the event
        esphome::api::CustomAPIDevice ha_event;
        ha_event.fire_homeassistant_event("esphome.nspanel_ha_blueprint", data);

        ESP_LOGV(TAG_COMPONENT_BASE, "HA event 'esphome.nspanel_ha_blueprint' sent successfully");
    }

}  // namespace nspanel_ha_blueprint
