// hw_display.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_HW_DISPLAY

#include <cstdint>
#include <vector>
#include "esphome/core/defines.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "pages.h"
#include "base.h"

namespace nspanel_ha_blueprint {

    extern uint8_t display_mode;
    extern uint8_t display_charset;

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_HW_DISPLAY
