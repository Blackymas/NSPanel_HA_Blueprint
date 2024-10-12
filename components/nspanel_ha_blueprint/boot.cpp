// boot.cpp

#include "boot.h"  // Include the header file for function and variable declarations.

namespace nspanel_ha_blueprint {

    // Definition of the global variable to track completed boot steps.
    // Each bit in this variable represents whether a boot step has been completed.
    uint32_t completed_boot_steps = 0;

    // Function to mark a boot step as completed.
    // Parameters:
    //   step - The boot step constant representing the step to be marked as completed.
    bool complete_boot_step(uint32_t step) {
        // Validate that the step is a power of two (i.e., only one bit is set).
        // This ensures that only valid boot step constants are accepted.
        if (step == 0 || (step & (step - 1)) != 0) {
            // If the step is zero or not a power of two, it's invalid.
            return false;
        }
        // Use bitwise OR to set the corresponding bit in completed_boot_steps.
        // This marks the boot step as completed.
        completed_boot_steps |= step;
        return true;
    }

    // Helper function to count the number of bits set to '1' in a uint32_t value.
    // Parameters:
    //   value - The uint32_t value whose bits are to be counted.
    // Returns:
    //   The number of bits set to '1' as an integer.
    uint8_t count_bits_set(uint32_t value) {
        uint8_t count = 0;
        while (value) {
            // Increment count if the least significant bit is '1'.
            count += value & 1;
            // Right-shift the value to check the next bit.
            value >>= 1;
        }
        return count;
    }

    // Function to get the number of unique boot steps that have been completed.
    // Returns:
    //   The count of completed boot steps as an integer.
    uint8_t get_boot_steps_completed() {
        return count_bits_set(completed_boot_steps);
    }

    // Function to calculate the boot progress percentage with rounding.
    // Returns:
    //   The boot progress percentage as a uint8_t between 0 and 100.
    uint8_t get_boot_progress_percentage() {
        // Calculate the percentage with rounding
        return static_cast<uint8_t>((get_boot_steps_completed() * 100 + TOTAL_BOOT_STEPS / 2) / TOTAL_BOOT_STEPS);
    }

    // Function to check if all boot steps have been completed.
    // Returns:
    //   true if all boot steps are completed, false otherwise.
    bool is_boot_complete() {
        return get_boot_steps_completed() == TOTAL_BOOT_STEPS;
    }

    // Function to reset the completed boot steps to zero.
    // This clears all tracked boot steps.
    void reset_boot_steps() {
        completed_boot_steps = 0;
    }

    // Function to check if a specific boot step has been completed.
    // Parameters:
    //   step - The boot step constant representing the step to check.
    // Returns:
    //   true if the boot step has been completed; false otherwise.
    bool is_boot_step_completed(uint32_t step) {
        return (completed_boot_steps & step) != 0;
    }

}  // namespace nspanel_ha_blueprint
