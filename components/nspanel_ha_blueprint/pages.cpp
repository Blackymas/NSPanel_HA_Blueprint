// pages.cpp

#include "pages.h"
#include <cstring>

namespace nspanel_ha_blueprint {

    uint8_t current_page_id = 0;
    uint8_t last_page_id = UINT8_MAX;
    uint8_t wakeup_page_id = 1;

}  // namespace nspanel_ha_blueprint
