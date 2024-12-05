// standard_upload_tft.cpp

#ifdef NSPANEL_HA_BLUEPRINT_STANDARD_UPLOAD_TFT

#include "standard_upload_tft.h"

namespace nspanel_ha_blueprint {

    std::string construct_tft_url(const std::string& tag, const std::string& model, const std::string& baseUrl) {
        std::string file_name;
        if (model == "NSPanel EU") file_name = "nspanel_eu.tft";
        else if (model == "NSPanel US") file_name = "nspanel_us.tft";
        else if (model == "NSPanel US Landscape") file_name = "nspanel_us_land.tft";
        else if (model == "NSPanel EU (CJK languages)") file_name = "nspanel_CJK_eu.tft";
        else if (model == "NSPanel US (CJK languages)") file_name = "nspanel_CJK_us.tft";
        else if (model == "NSPanel US Landscape (CJK languages)") file_name = "nspanel_CJK_us_land.tft";
        else file_name = "nspanel_blank.tft";
        return baseUrl + tag + "/hmi/" + file_name;
    }

    std::string getNSPanelText(int displayMode, int charset) {
        if (displayMode < 1 || displayMode > 3 || charset < 1 || charset > 2) return "";
        std::string text = (displayMode == 1) ? "NSPanel EU" : (displayMode == 2) ? "NSPanel US" : "NSPanel US Landscape";
        if (charset == 2) text += " (CJK languages)";
        return text;
    }

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_STANDARD_UPLOAD_TFT
