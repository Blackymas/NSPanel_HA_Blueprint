// hw_buttons.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_HW_BUTTONS

namespace nspanel_ha_blueprint {

    // ###### Buttons settings ######
    // # Bit # Settings             #
    // #  0  # Left Bt - Enabled    #
    // #  1  # Left Bt - State      #
    // #  2  # reserved             #
    // #  3  # reserved             #
    // #  4  # Right Bt - Enabled   #
    // #  5  # Right Bt - State     #
    // #  6  # reserved             #
    // #  7  # reserved             #
    // ##############################
    extern uint8_t buttons_settings;

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_HW_BUTTONS
