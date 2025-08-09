// base.cpp

#include "base.h"

#ifdef NSPANEL_HA_BLUEPRINT_CORE_BASE

namespace nspanel_ha_blueprint {

    // Global panel state variable - starts as UNKNOWN
    PanelState current_panel_state = PanelState::UNKNOWN;

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_CORE_BASE
