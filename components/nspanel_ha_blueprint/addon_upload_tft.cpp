// addon_upload_tft.cpp - TFT component state definitions

#ifdef NSPANEL_HA_BLUEPRINT_ADDON_UPLOAD_TFT

#include "addon_upload_tft.h"

namespace nspanel_ha_blueprint {

    // TFT upload state variables (previously YAML globals)
    uint8_t tft_upload_attempt = 0;
    bool tft_upload_result = false;

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_ADDON_UPLOAD_TFT
