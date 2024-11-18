// nextion.h

#include <string>
#include <vector>
#include "esphome/core/log.h"

namespace nspanel_ha_blueprint {


    bool PageButtonsButtonInitilized = false;

    // Structure representing a button on a Nextion page
    struct PageButtonsButton {
        bool visible;         // Indicates if the button is visible or not
        bool state;           // Represents the button's state, influencing background and other visual aspects
        char icon[5];         // Icon codepoint from HASwitchPlate Material Design Icons (e.g., "\uE6E8" for mdi:lightbulb-on-outline)
        uint16_t icon_color;  // RGB565 color value for the icon (e.g., red, blue, etc.)
        uint8_t icon_font;    // Nextion font identifier for the icon, default is typically 8
        char bri[15];         // Pointer for brightness level or other dynamic information to be displayed near the icon (allocated dynamically)
        char label[50];       // Pointer for the main text label for the button (allocated dynamically)

        // Constructor to initialize the button structure
        PageButtonsButton() {
            // Initialize with empty strings to avoid undefined behavior
            visible = false;
            state = false;
            icon[0] = '\0';
            icon_color = 0;
            icon_font = 8;
            bri[0] = '\0';
            label[0] = '\0';
        }
    };

    // Pointer to the static button's array, allocated in PSRAM if possible
    PageButtonsButton* buttonpage_buttons;

    // Function to set up all buttons in the PSRAM
    void setup_pagebuttons_buttons() {
        if (!PageButtonsButtonInitilized) {
            // Allocate memory for 32 buttons, placing them in PSRAM if available
            esphome::ESP_LOGD("nspanel_ha_blueprint.nextion.setup_buttons", "Allocating memory");
            // Allocate PageButtonsButton dynamically
            esphome::ExternalRAMAllocator<PageButtonsButton> allocator(esphome::ExternalRAMAllocator<PageButtonsButton>::ALLOW_FAILURE);
            buttonpage_buttons = allocator.allocate(32 * sizeof(PageButtonsButton));
            if (!buttonpage_buttons or buttonpage_buttons == nullptr) {
                esphome::ESP_LOGE("nspanel_ha_blueprint.nextion.setup_buttons",
                                    "Failed to allocate memory for buttonpage_buttons.");
                return;  // Memory allocation failed, do not proceed
            }
            esphome::ESP_LOGD("nspanel_ha_blueprint.nextion.setup_buttons", "Memory allocated");

            // Initialize each button with default settings
            for (uint8_t i = 0; i < 32; ++i) {
                new (&buttonpage_buttons[i]) PageButtonsButton(); // Placement new to call the constructor
            }

            PageButtonsButtonInitilized = true;
        }
    }

    // Example of how to calculate page and button ID within the page based on index
    inline uint8_t get_page_from_index(uint8_t index) {
        return (index / 8) + 1;  // Calculate the page based on the index (1-based page numbering)
    }

    inline uint8_t get_button_id_from_index(uint8_t index) {
        return (index % 8) + 1;  // Calculate the button ID within the page (1-based button numbering)
    }

    inline uint16_t color565(const std::vector<int> &color888) {
        return ((color888[0] & 0xF8) << 8) | ((color888[1] & 0xFC) << 3) | (color888[2] >> 3);
    }

}  // namespace nspanel_ha_blueprint
