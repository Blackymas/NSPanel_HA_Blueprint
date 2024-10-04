// boot.h

#pragma once  // Include guard to prevent multiple inclusions of this header file

#include <stdint.h>  // Include standard integer types

namespace nspanel_ha_blueprint {

    // Define a type for boot step representation using a 32-bit unsigned integer.
    // This allows for up to 32 unique boot steps, each represented by a unique bit.
    typedef uint32_t BootStepType;

    // Boot Step Constants
    // Each boot step is represented by a unique bit in the BootStepType variable.
    // Using bit shifting to assign unique bits to each boot step.
    const BootStepType BOOT_STEP_BASE                = 1UL << 0;
    const BootStepType BOOT_STEP_BOOT                = 1UL << 1;
    const BootStepType BOOT_STEP_DATETIME            = 1UL << 2;
    const BootStepType BOOT_STEP_HW_BUTTONS          = 1UL << 3;
    const BootStepType BOOT_STEP_HW_BUZZER           = 1UL << 4;
    const BootStepType BOOT_STEP_HW_DISPLAY          = 1UL << 5;
    const BootStepType BOOT_STEP_HW_MEMORY           = 1UL << 6;
    const BootStepType BOOT_STEP_HW_RELAYS           = 1UL << 7;
    const BootStepType BOOT_STEP_HW_TEMPERATURE      = 1UL << 8;
    const BootStepType BOOT_STEP_HW_WIFI             = 1UL << 9;
    const BootStepType BOOT_STEP_PAGE_ALARM          = 1UL << 10;
    const BootStepType BOOT_STEP_PAGE_BLANK          = 1UL << 27;
    const BootStepType BOOT_STEP_PAGE_BUTTONS        = 1UL << 11;
    const BootStepType BOOT_STEP_PAGE_CLIMATE        = 1UL << 12;
    const BootStepType BOOT_STEP_PAGE_CONFIRM        = 1UL << 13;
    const BootStepType BOOT_STEP_PAGE_COVER          = 1UL << 14;
    const BootStepType BOOT_STEP_PAGE_ENTITIES       = 1UL << 15;
    const BootStepType BOOT_STEP_PAGE_FAN            = 1UL << 16;
    const BootStepType BOOT_STEP_PAGE_HOME           = 1UL << 17;
    const BootStepType BOOT_STEP_PAGE_KEYBOARD_NUM   = 1UL << 18;
    const BootStepType BOOT_STEP_PAGE_LIGHT          = 1UL << 19;
    const BootStepType BOOT_STEP_PAGE_MEDIA_PLAYER   = 1UL << 20;
    const BootStepType BOOT_STEP_PAGE_NOTIFICATION   = 1UL << 21;
    const BootStepType BOOT_STEP_PAGE_QRCODE         = 1UL << 22;
    const BootStepType BOOT_STEP_PAGE_SCREENSAVER    = 1UL << 23;
    const BootStepType BOOT_STEP_PAGE_SETTINGS       = 1UL << 28;
    const BootStepType BOOT_STEP_PAGE_UTILITIES      = 1UL << 24;
    const BootStepType BOOT_STEP_PAGE_WEATHER        = 1UL << 25;
    const BootStepType BOOT_STEP_VERSION             = 1UL << 26;

    // Add more boot steps here, ensuring each has a unique bit position.

    // Total number of defined boot steps.
    const uint8_t TOTAL_BOOT_STEPS = 29; // Update as needed.

    // Extern declaration of the global variable to track completed boot steps.
    // This variable is defined in boot.cpp.
    extern BootStepType completed_boot_steps;

    // Function to mark a boot step as completed.
    // Parameters:
    //   step - The boot step constant representing the step to be marked as completed.
    void complete_boot_step(BootStepType step);

    // Function to get the number of unique boot steps that have been completed.
    // Returns:
    //   The count of completed boot steps as an integer.
    inline uint8_t get_boot_steps_completed();

    // Function to calculate the boot progress percentage with rounding.
    // Returns:
    //   The boot progress percentage as a uint8_t between 0 and 100.
    inline uint8_t get_boot_progress_percentage() {
        // Calculate the percentage with rounding
        return static_cast<uint8_t>((get_boot_steps_completed() * 100 + TOTAL_BOOT_STEPS / 2) / TOTAL_BOOT_STEPS);
    }

    // Function to check if all boot steps have been completed.
    // Returns:
    //   true if all boot steps are completed, false otherwise.
    inline bool is_boot_complete() {
        return get_boot_steps_completed() == TOTAL_BOOT_STEPS;
    }

    // Function to reset the completed boot steps to zero.
    // This clears all tracked boot steps.
    inline void reset_boot_steps();

    // Function to check if a specific boot step has been completed.
    // Parameters:
    //   step - The boot step constant representing the step to check.
    // Returns:
    //   true if the boot step has been completed; false otherwise.
    inline bool is_boot_step_completed(BootStepType step) {
        return (completed_boot_steps & step) != 0;
    }

}  // namespace nspanel_ha_blueprint
