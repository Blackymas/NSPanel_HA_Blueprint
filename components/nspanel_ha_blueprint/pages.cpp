// pages.cpp

#include "pages.h"
#include <cstring>
#include <string>

namespace nspanel_ha_blueprint {

    uint8_t get_page_id(const std::string& page_name) {
        for (uint8_t i = 0; i < page_names.size(); ++i) {
            if (strcmp(page_names[i], page_name.c_str()) == 0) {
                return i;
            }
        }
        return UINT8_MAX;
    }

}  // namespace nspanel_ha_blueprint
