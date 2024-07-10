// upload_tft.h

#pragma once

// #ifdef NSPANEL_HA_BLUEPRINT_ADDON_UPLOAD_TFT

#include <string>

namespace nspanel_ha_blueprint {

    /**
     * Constructs the TFT file URL based on branch, model, default URL, and base URL.
     * 
     * @param branch The branch version input, potentially containing keywords like "beta" or "dev".
     * @param model The device model, determining the specific TFT file name.
     * @param defaultUrl The fallback URL if no specific file is associated with the model.
     * @param baseUrl The base URL, to which branch and file names are appended to create the full URL.
     * @return A string representing the fully constructed URL.
     */
    std::string construct_tft_url(const std::string& branch, const std::string& model,
                                    const std::string& defaultUrl, const std::string& baseUrl);

    /**
     * Generates a descriptive text for the NSPanel based on display mode and charset.
     * 
     * @param displayMode Numeric code for the NSPanel's display mode: 1 for "EU", 2 for "US", 3 for "US Landscape".
     * @param charset Numeric code for the character set: 1 for "International (original)", 2 for "CJK languages".
     * @return A string describing the NSPanel configuration, or an empty string if inputs don't match any configuration.
     */
    std::string getNSPanelText(int displayMode, int charset);

}  // namespace nspanel_ha_blueprint

// #endif  // NSPANEL_HA_BLUEPRINT_ADDON_UPLOAD_TFT
