// upload_tft.cpp

#ifdef NSPANEL_HA_BLUEPRINT_ADDON_UPLOAD_TFT

#include "upload_tft.h"

namespace nspanel_ha_blueprint {

    std::string construct_tft_url(const std::string& branch, const std::string& model,
                                    const std::string& defaultUrl, const std::string& baseUrl) {
        std::string relative_branch = branch.find("b") != std::string::npos ? "beta" : branch.find("d") != std::string::npos ? "dev" : branch;
        std::string file_name;
        if (model == "NSPanel Blank") file_name = "nspanel_blank.tft";
        else if (model == "NSPanel EU") file_name = "nspanel_eu.tft";
        else if (model == "NSPanel US") file_name = "nspanel_us.tft";
        else if (model == "NSPanel US Landscape") file_name = "nspanel_us_land.tft";
        else if (model == "NSPanel EU (CJK languages)") file_name = "nspanel_CJK_eu.tft";
        else if (model == "NSPanel US (CJK languages)") file_name = "nspanel_CJK_us.tft";
        else if (model == "NSPanel US Landscape (CJK languages)") file_name = "nspanel_CJK_us_land.tft";
        return file_name.empty() ? defaultUrl : baseUrl + relative_branch + "/hmi/" + file_name;
    }

    std::string getNSPanelText(int displayMode, int charset) {
        if (displayMode < 1 || displayMode > 3 || charset < 1 || charset > 2) return "";
        std::string text = (displayMode == 1) ? "NSPanel EU" : (displayMode == 2) ? "NSPanel US" : "NSPanel US Landscape";
        if (charset == 2) text += " (CJK languages)";
        return text;
    }

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_ADDON_UPLOAD_TFT
