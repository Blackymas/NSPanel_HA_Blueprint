// page_media_player.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_PAGE_MEDIA_PLAYER

#include <cstdint>

namespace nspanel_ha_blueprint {

    extern uint8_t last_volume_level;     // Last volume level from Home Assistant
    extern uint32_t last_media_duration;  // Last duration from Home Assistant
    extern uint32_t last_media_position;  // Last position from Home Assistant

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_PAGE_MEDIA_PLAYER
