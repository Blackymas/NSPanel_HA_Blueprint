// upload_tft.h
#pragma once

#include <string>

namespace nspanel_ha_blueprint_upload_tft {

    /**
    * Constructs the TFT file URL based on branch, model, default URL, and base URL.
    *
    * @param branchInput The input branch version, which might contain special keywords like "beta" or "dev".
    * @param model The model of the device, used to determine the specific TFT file name.
    * @param defaultUrl The default URL to use if no specific file is associated with the model.
    * @param baseUrl The base URL to which branch and file names are appended to construct the full URL.
    * @return The fully constructed URL as a string.
    */
    std::string construct_tft_url(const std::string& branch, const std::string& model,
                                const std::string& defaultUrl, const std::string& baseUrl) {
        // Determine the branch based on the input
        std::string relative_branch = branch;
        if (branch.find("b") != std::string::npos) relative_branch = "beta";
        else if (branch.find("d") != std::string::npos) relative_branch = "dev";

        // Mapping model to the corresponding TFT file name
        std::string file_name;
        if (model == "NSPanel Blank") file_name = "nspanel_blank.tft";
        else if (model == "NSPanel EU") file_name = "nspanel_eu.tft";
        else if (model == "NSPanel US") file_name = "nspanel_us.tft";
        else if (model == "NSPanel US Landscape") file_name = "nspanel_us_land.tft";
        else if (model == "NSPanel EU (CJK languages)") file_name = "nspanel_CJK_eu.tft";
        else if (model == "NSPanel US (CJK languages)") file_name = "nspanel_CJK_us.tft";
        else if (model == "NSPanel US Landscape (CJK languages)") file_name = "nspanel_CJK_us_land.tft";

        // Construct the URL based on the determined file name
        std::string url;
        if (file_name.empty()) {
            url = defaultUrl; // Use the default URL if no specific file name is matched
        } else {
            url = baseUrl + relative_branch + "/hmi/" + file_name; // Construct the full URL
        }

        return url; // Return the constructed URL
    }

}  // namespace nspanel_ha_blueprint_upload_tft
