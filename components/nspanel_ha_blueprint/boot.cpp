// boot.cpp

#include "boot.h"  // Include the header file for function and variable declarations.
#include "esp_log.h"

namespace nspanel_ha_blueprint {

    // Definition of the global variable to track completed boot steps.
    // Each bit in this variable represents whether a boot step has been completed.
    BootStepType completed_boot_steps = 0;

    // Function to mark a boot step as completed.
    // Parameters:
    //   step - The boot step constant representing the step to be marked as completed.
    void complete_boot_step(BootStepType step) {
        // Validate that the step is a power of two (i.e., only one bit is set).
        // This ensures that only valid boot step constants are accepted.
        if (step == 0 || (step & (step - 1)) != 0) {
            // If the step is zero or not a power of two, it's invalid.
            // Print an error message and exit the function.
            ESP_LOGE("boot", "Error: Invalid boot step provided.");
            return;
        }
        // Use bitwise OR to set the corresponding bit in completed_boot_steps.
        // This marks the boot step as completed.
        completed_boot_steps |= step;
    }

    // Helper function to count the number of bits set to '1' in a BootStepType value.
    // Parameters:
    //   value - The BootStepType value whose bits are to be counted.
    // Returns:
    //   The number of bits set to '1' as an integer.
    uint8_t count_bits_set(BootStepType value) {
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
    inline uint8_t get_boot_steps_completed() {
        return count_bits_set(completed_boot_steps);
    }

    // Function to reset the completed boot steps to zero.
    // This clears all tracked boot steps.
    inline void reset_boot_steps() {
        completed_boot_steps = 0;
    }

}  // namespace nspanel_ha_blueprint
