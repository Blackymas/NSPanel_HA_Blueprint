// pages.cpp

#include "pages.h"
#include <cstring>

namespace nspanel_ha_blueprint {

    uint8_t current_page_id = 0;
    uint8_t last_page_id = UINT8_MAX;

    uint8_t get_page_id(const std::string& page_name) {
        for (uint8_t i = 0; i < page_names.size(); ++i) {
            if (strcmp(page_names[i], page_name.c_str()) == 0) {
                return i;
            }
        }
        return UINT8_MAX;
    }

    bool isStringInList(const std::string& strToSearch, std::initializer_list<std::string> list) {
        for (const auto& str : list) {
            if (strToSearch == str) {
                return true;
            }
        }
        return false;
    }

}  // namespace nspanel_ha_blueprint
