// base.h - Updated with Nextion waiting state

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_CORE_BASE

#ifndef CORE_BASE_H
#define CORE_BASE_H

#include <cstdint>

namespace nspanel_ha_blueprint {

    static const char *TAG_COMPONENT = "nspanel_ha_blueprint";

    enum class PanelState : uint8_t {
        UNKNOWN = 0,
        WAITING_FOR_NEXTION = 1,    // Waiting for Nextion display to be ready
        BOOTING = 2,                // Boot sequence in progress
        RUNNING = 3,                // Normal operation
        RUNNING_DIMMED = 4,         // Dimmed operation
        SLEEPING = 5,               // Screensaver/sleep mode
        UPDATING_TFT = 6,           // During TFT upload
        RESTARTING = 7,             // During restart operations
        SAFE_MODE = 8               // When in safe mode
    };

    // Inline function to convert enum to string
    inline const char *panel_state_to_string(PanelState state) {
        switch (state) {
            case PanelState::UNKNOWN: return "Unknown";
            case PanelState::WAITING_FOR_NEXTION: return "Waiting for Nextion";
            case PanelState::BOOTING: return "Booting";
            case PanelState::RUNNING: return "Running";
            case PanelState::RUNNING_DIMMED: return "Running (Dimmed)";
            case PanelState::SLEEPING: return "Sleeping";
            case PanelState::UPDATING_TFT: return "Updating TFT";
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
