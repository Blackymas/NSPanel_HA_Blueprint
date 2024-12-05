// core_boot.h

#pragma once  // Include guard to prevent multiple inclusions of this header file

#ifdef NSPANEL_HA_BLUEPRINT_CORE_BOOT

#include <stdint.h>  // Include standard integer types
#include <string.h>  // Include for handling strings
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "core_base.h"

namespace nspanel_ha_blueprint {

    // Structure to define a boot step
    struct BootStep {
        char key[21];             // Unique key name to identify the boot step (max 20 chars + null terminator)
        char name[21];            // Name of the boot step (max 20 chars + null terminator)
        bool completed = false;   // Status indicating if the boot of that item was completed
        bool registered = false;  // Status indicating if the boot step is registered for boot process

        BootStep() {
            key[0] = '\0';  // Initialize key with an empty string
            name[0] = '\0';  // Initialize name with an empty string
        }
    };

    // Fixed array to store the boot steps
    static constexpr size_t MAX_BOOT_STEPS = 32;
    extern BootStep boot_steps[MAX_BOOT_STEPS];

    // Function to set up the boot steps array
    void setup_boot_steps();

    // Function to register an application for boot.
    bool register_application(uint8_t index, const char* key, const char* name);

    // Function to mark a boot step as completed.
    bool complete_boot_step(uint8_t index);

    // Function to calculate the boot progress percentage with rounding.
    uint8_t get_boot_progress_percentage();

    // Function to check if all registered applications have completed boot.
    bool is_boot_complete();

    // Function to reset the completed boot steps to the initial state.
    void reset_boot_steps();

    // Function to check if a specific boot step has been completed.
    bool is_boot_step_completed(uint8_t index);

    // Function to get the total number of registered boot steps
    uint8_t get_total_registered_boot_steps();

    // Function to get the total number of completed boot steps
    uint8_t get_completed_boot_steps();

    // Function to get a pointer to a specific boot step by its index
    BootStep* get_boot_step(uint8_t index);

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_CORE_BOOT
