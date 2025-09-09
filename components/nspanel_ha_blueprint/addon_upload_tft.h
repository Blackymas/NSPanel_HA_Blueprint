// addon_upload_tft.h - Complete TFT component state management

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_ADDON_UPLOAD_TFT

#include <cstdint>

namespace nspanel_ha_blueprint {

    // TFT upload state variables (previously YAML globals)
    extern bool tft_is_valid;
    extern uint8_t tft_upload_attempt;
    extern bool tft_upload_result;

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_ADDON_UPLOAD_TFT
