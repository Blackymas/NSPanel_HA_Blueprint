// nextion.h

#include <string>
#include <vector>
#include "esphome/core/log.h"          // Ensure the correct logging functionality is included
#include "esphome/components/api/api_server.h"
#include "text.h"

namespace nspanel_ha_blueprint {

    struct PageButtonsButton {
        bool enabled;         // Is the button enabled?
        char page[15];        // The target page on the Nextion display.
        char button_id[15];   // Unique identifier for the button.
        bool state;           // Determines the button's state, influencing background and other visual aspects.
        char icon[5];         // Icon codepoint from HASwitchPlate Material Design Icons. Example: "\uE6E8" for mdi:lightbulb-on-outline.
        uint16_t icon_color;  // RGB565 color for the icon
        uint8_t icon_font;    // Nextion font identifier for the icon, default is 8.
        char bri[15];         // Brightness level or other dynamic info to be displayed close to the icon.
        char label[50];       // Main text label for the button.
    };

    // Initialize the static button's array
    PageButtonsButton buttonpage_buttons[32];

}  // namespace nspanel_ha_blueprint
