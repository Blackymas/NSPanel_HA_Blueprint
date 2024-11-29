// core_boot.h

#pragma once  // Include guard to prevent multiple inclusions of this header file

#ifdef NSPANEL_HA_BLUEPRINT_CORE_BOOT

#include <stdint.h>  // Include standard integer types
#include <string.h>  // Include for handling strings
#include <vector>    // Include for using vector to store boot steps
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace nspanel_ha_blueprint {
    // Structure to define a boot step
    struct BootStep {
        uint8_t id;               // Unique identifier for the boot step (bit to be flagged)
        char name[21];            // Name of the boot step (max 20 chars + null terminator)
        bool completed = false;   // Status indicating if the boot of that item was completed

        BootStep(uint8_t id_, const char* name_) : id(id_) {
            strncpy(name, name_, sizeof(name) - 1);
            name[sizeof(name) - 1] = '\0'; // Ensure null-termination
        }
    };

    // Vector to store the boot steps in PSRAM
    using BootStepVector = std::vector<BootStep, esphome::ExternalRAMAllocator<BootStep>>;
    extern BootStepVector* boot_steps;

    // Function to set up the boot steps vector
    void setup_boot_steps();

    // Function to register an application for boot.
    // Parameters:
    //   id - The unique identifier (bit) for the application to be registered.
    //   name - The name of the application.
    // Returns:
    //   true if the application has been successfully registered;
    //   false if the application is already registered or invalid.
    bool register_application(uint8_t id, const char* name);

    // Function to mark a boot step as completed.
    // Parameters:
    //   id - The unique identifier for the boot step to be marked as completed.
    // Returns:
    //   true if the boot step has been successfully marked completed;
    //   false if the id does not exist.
    bool complete_boot_step(uint8_t id);

    // Function to calculate the boot progress percentage with rounding.
    // Returns:
    //   The boot progress percentage as a uint8_t between 0 and 100.
    uint8_t get_boot_progress_percentage();

    // Function to check if all registered applications have completed boot.
    // Returns:
    //   true if all registered applications have completed boot, false otherwise.
    bool is_boot_complete();

    // Function to reset the completed boot steps to the initial state.
    void reset_boot_steps();

    // Function to check if a specific boot step has been completed.
    // Parameters:
    //   id - The unique identifier for the boot step to check.
    // Returns:
    //   true if the boot step has been completed; false otherwise.
    bool is_boot_step_completed(uint8_t id);

    // Function to get the total number of registered boot steps
    uint8_t get_total_registered_boot_steps();

    // Function to get the total number of completed boot steps
    uint8_t get_completed_boot_steps();

    // Function to get a pointer to a specific boot step by its ID
    BootStep* get_boot_step(uint8_t id);

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_CORE_BOOT
