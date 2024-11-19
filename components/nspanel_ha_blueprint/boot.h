// boot.h

#pragma once  // Include guard to prevent multiple inclusions of this header file

#include <stdint.h>  // Include standard integer types

namespace nspanel_ha_blueprint {
    // Total number of defined boot steps.
    const uint8_t TOTAL_BOOT_STEPS = 30; // Update as needed.

    // Extern declaration of the global variable to track completed boot steps.
    // This variable is defined in boot.cpp.
    extern uint32_t completed_boot_steps;

    // Function to mark a boot step as completed.
    // Parameters:
    //   step - The boot step constant representing the step to be marked as completed.
    // Returns:
    //   true if the boot step has been sucessfuly marked completed;
    //   false otherwise (like in the case of an invalid step constant).
    bool complete_boot_step(const uint32_t step);

    // Function to get the number of unique boot steps that have been completed.
    // Returns:
    //   The count of completed boot steps as an integer.
    uint8_t get_boot_steps_completed();

    // Function to calculate the boot progress percentage with rounding.
    // Returns:
    //   The boot progress percentage as a uint8_t between 0 and 100.
    uint8_t get_boot_progress_percentage();

    // Function to check if all boot steps have been completed.
    // Returns:
    //   true if all boot steps are completed, false otherwise.
    bool is_boot_complete();

    // Function to reset the completed boot steps to zero.
    // This clears all tracked boot steps.
    void reset_boot_steps();

    // Function to check if a specific boot step has been completed.
    // Parameters:
    //   step - The boot step constant representing the step to check.
    // Returns:
    //   true if the boot step has been completed; false otherwise.
    bool is_boot_step_completed(uint32_t step);

}  // namespace nspanel_ha_blueprint
