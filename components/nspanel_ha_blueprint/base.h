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
        BOOTING = 1,
        RUNNING = 2,
        RUNNING_DIMMED = 3,
        SLEEPING = 4,
        UPDATING_TFT = 5,
        RESTARTING = 6,
        SAFE_MODE = 7
    };

    // Inline function to convert enum to string
    inline const char *panel_state_to_string(PanelState state) {
        switch (state) {
            case PanelState::UNKNOWN: return "Unknown";
            case PanelState::BOOTING: return "Booting";
            case PanelState::RUNNING: return "Running";
            case PanelState::RUNNING_DIMMED: return "Running (Dimmed)";
            case PanelState::SLEEPING: return "Sleeping";
            case PanelState::UPDATING_TFT: return "Updating TFT";
            case PanelState::RESTARTING: return "Restarting";
            case PanelState::SAFE_MODE: return "Safe mode";
            default: return "Unknown";
        }
    }

    // Global panel state variable declaration
    extern PanelState current_panel_state;

}  // namespace nspanel_ha_blueprint

#endif  // CORE_BASE_H

#endif  // NSPANEL_HA_BLUEPRINT_CORE_BASE
