// page_buttons.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_STANDARD_PAGE_BUTTONS

#include <string>
#include <vector>
#include "esphome/core/log.h"
#include "hw_display.h"

namespace nspanel_ha_blueprint {

    bool PageButtonsButtonInitilized = false;
    uint32_t PageButtonsMaskEnabled = 0;
    uint32_t PageButtonsMaskConfirm = 0;

    // Structure representing a button on a Nextion page
    struct PageButtonsButton {
        bool state;               // Represents the button's state, influencing background and other visual aspects
        DisplayComponent* bri;    // Pointer for the short status text component
        DisplayComponent* icon;   // Pointer for the icon component
        DisplayComponent* label;  // Pointer for the main text label component

        // Constructor to initialize the button structure
        PageButtonsButton()
            : state(false), bri(nullptr), icon(nullptr), label(nullptr) {}
    };

    // Pointer to the static button's array, allocated in PSRAM if possible
    PageButtonsButton* buttonpage_buttons;

    char* get_button_name(const uint8_t button_id) {
        // Determine the base component name
        static char base_component[9];
        snprintf(base_component, sizeof(base_component), "button%02d", (button_id % 8) + 1);
        return base_component;
    }

    // Function to set up all buttons in the PSRAM
    void setup_pagebuttons_buttons() {
        if (!PageButtonsButtonInitilized) {
            // Allocate memory for 32 buttons, placing them in PSRAM if available
            ESP_LOGD(TAG_COMPONENT, "Allocating memory");
            // Allocate PageButtonsButton dynamically
            esphome::ExternalRAMAllocator<PageButtonsButton>
                allocator(esphome::ExternalRAMAllocator<PageButtonsButton>::ALLOW_FAILURE);
            buttonpage_buttons = allocator.allocate(32*sizeof(PageButtonsButton));
            if (!buttonpage_buttons || buttonpage_buttons == nullptr) {
                ESP_LOGE(TAG_COMPONENT, "Failed to allocate memory for buttonpage_buttons.");
                return;  // Memory allocation failed, do not proceed
            }
            ESP_LOGD(TAG_COMPONENT, "Memory allocated");

            // Initialize each button with default settings and assign DisplayComponent pointers
            for (uint8_t i = 0; i < 32; ++i) {
                new (&buttonpage_buttons[i]) PageButtonsButton(); // Placement new to call the constructor
                
                // Calculate page and button identifiers
                const uint8_t page_id = (i / 8) + 12;  // PAGE_ID_BUTTONPAGE01: '12'

                // Use the component ID to identify each component in the Nextion, with suffixes
                char bri_component[20];
                char icon_component[20];
                char label_component[20];

                snprintf(bri_component, sizeof(bri_component), "%sbri", get_button_name(i));
                snprintf(icon_component, sizeof(icon_component), "%sicon", get_button_name(i));
                snprintf(label_component, sizeof(label_component), "%stext", get_button_name(i));

                // Assign pointers to the respective DisplayComponent using get_component
                buttonpage_buttons[i].bri = get_component(page_id, bri_component);
                buttonpage_buttons[i].icon = get_component(page_id, icon_component);
                buttonpage_buttons[i].label = get_component(page_id, label_component);
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

    bool is_button_page_enabled(const uint8_t buttonpage_index, const uint32_t mask) {
        // Ensure the buttonpage_index is within the valid range (1-4)
        if (buttonpage_index < 1 || buttonpage_index > 4) {
            return false;
        }

        // Calculate the range of buttons for the specified page
        const uint8_t start_button = (buttonpage_index - 1) * 8; // Page 1: buttons 0-7, Page 2: buttons 8-15, etc.
        const uint8_t end_button = start_button + 8;

        // Iterate through each button on the page to check if any are enabled
        for (uint8_t i = start_button; i < end_button; i++) {
            if (mask & (1 << i)) {
                return true; // If any bit corresponding to a button is set, return true
            }
        }

        // If no buttons are enabled, return false
        return false;
    }

    bool is_button_in_mask(const uint8_t button_id, const uint32_t mask) {
        // Ensure the button ID is within the valid range (1-32)
        if (button_id < 1 || button_id > 32) {
            return false;
        }

        // Check if the bit corresponding to button_id is set in the mask
        return mask & (1 << (button_id - 1));
    }

}  // namespace nspanel_ha_blueprint

#endif // NSPANEL_HA_BLUEPRINT_STANDARD_PAGE_BUTTONS
