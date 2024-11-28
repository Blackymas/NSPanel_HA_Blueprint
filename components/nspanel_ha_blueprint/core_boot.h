// core_boot.h

#pragma once  // Include guard to prevent multiple inclusions of this header file

#ifdef NSPANEL_HA_BLUEPRINT_CORE_BOOT

#include <stdint.h>  // Include standard integer types

namespace nspanel_ha_blueprint {
    // Total number of defined boot steps.
    extern uint8_t total_boot_steps;
    extern uint32_t completed_boot_steps;
    extern uint32_t registered_applications;

    // Function to mark a boot step as completed.
    // Parameters:
    //   step - The boot step constant representing the step to be marked as completed.
    // Returns:
    //   true if the boot step has been successfully marked completed;
    //   false otherwise (like in the case of an invalid step constant).
    bool complete_boot_step(const uint32_t step);

    // Function to register an application for boot.
    // Parameters:
    //   app_bit - The application bit representing the application to be registered.
    // Returns:
    //   true if the application has been successfully registered;
    //   false otherwise (e.g., invalid bit).
    bool register_application(const uint32_t app_bit);

    // Function to get the number of unique boot steps that have been completed.
    // Returns:
    //   The count of completed boot steps as an integer.
    uint8_t get_boot_steps_completed();

    // Function to calculate the boot progress percentage with rounding.
    // Returns:
    //   The boot progress percentage as a uint8_t between 0 and 100.
    uint8_t get_boot_progress_percentage();

    // Function to check if all registered applications have completed boot.
    // Returns:
    //   true if all registered applications have completed boot, false otherwise.
    bool is_boot_complete();

    // Function to reset the completed boot steps and registered applications to zero.
    // This clears all tracked boot steps and applications.
    void reset_boot_steps();

    // Function to check if a specific boot step has been completed.
    // Parameters:
    //   step - The boot step constant representing the step to check.
    // Returns:
    //   true if the boot step has been completed; false otherwise.
    bool is_boot_step_completed(uint32_t step);

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_CORE_BOOT
