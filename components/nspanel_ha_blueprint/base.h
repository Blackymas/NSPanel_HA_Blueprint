// base.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_CORE_BASE

#ifndef CORE_BASE_H
#define CORE_BASE_H

#include <cstdint>

namespace nspanel_ha_blueprint {

    static const char *TAG_COMPONENT = "nspanel_ha_blueprint";

    enum class PanelState : uint8_t {
        UNKNOWN = 0,

        // Boot sequence states
        WAIT_NEXTION = 1,           // Waiting for Nextion (baud scan)
        NEXTION_SETUP = 2,          // Nextion setup, waiting for version
        WAIT_WIFI = 3,              // Waiting for Wi-Fi connection
        WAIT_API = 4,               // Waiting for Home Assistant API
        WAIT_BLUEPRINT = 5,         // Waiting for Blueprint connection
        BOOT_PARAMS = 6,            // Blueprint startup parameters in progress
        BOOT_DISPLAY = 7,           // Display settings configuration
        BOOT_COMPLETE = 8,          // Boot sequence finishing

        // Runtime states
        RUNNING = 10,               // Normal operation
        RUNNING_DIMMED = 11,        // Dimmed operation
        SLEEPING = 12,              // Screensaver/sleep mode

        // Special states
        UPDATING_TFT = 20,          // During TFT upload
        RESTARTING = 21,            // During restart operations
        SAFE_MODE = 22              // When in safe mode
    };

    // Inline function to convert enum to string (minimal text to save flash)
    inline const char *panel_state_to_string(PanelState state) {
        switch (state) {
            case PanelState::UNKNOWN: return "Unknown";
            case PanelState::WAIT_NEXTION: return "Wait Nextion";
            case PanelState::NEXTION_SETUP: return "Setup";
            case PanelState::WAIT_WIFI: return "WiFi";          // Won't reach HA anyway
            case PanelState::WAIT_API: return "API";            // Won't reach HA anyway
            case PanelState::WAIT_BLUEPRINT: return "Blueprint";
            case PanelState::BOOT_PARAMS: return "Params";
            case PanelState::BOOT_DISPLAY: return "Display";
            case PanelState::BOOT_COMPLETE: return "Complete";
            case PanelState::RUNNING: return "Running";
            case PanelState::RUNNING_DIMMED: return "Dimmed";
            case PanelState::SLEEPING: return "Sleeping";
            case PanelState::UPDATING_TFT: return "Update TFT";
            case PanelState::RESTARTING: return "Restarting";
            case PanelState::SAFE_MODE: return "Safe Mode";
            default: return "Unknown";
        }
    }

    // Global panel state variable declaration
    extern PanelState current_panel_state;

}  // namespace nspanel_ha_blueprint

#endif  // CORE_BASE_H

#endif  // NSPANEL_HA_BLUEPRINT_CORE_BASE
