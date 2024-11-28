// core_boot.cpp

#ifdef NSPANEL_HA_BLUEPRINT_CORE_BOOT

#include "core_boot.h"  // Include the header file for function and variable declarations.

namespace nspanel_ha_blueprint {

    // Total number of defined boot steps.
    uint8_t total_boot_steps = 0;
    uint32_t completed_boot_steps = 0;
    uint32_t registered_applications = 0;

    // Function to mark a boot step as completed.
    bool complete_boot_step(const uint32_t step) {
        // Validate that the step is a power of two (i.e., only one bit is set).
        if (step == 0 || (step & (step - 1)) != 0) {
            return false;
        }
        // Use bitwise OR to set the corresponding bit in completed_boot_steps.
        completed_boot_steps |= step;
        return true;
    }

    // Function to register an application for boot.
    bool register_application(const uint32_t app_bit) {
        // Validate that the app_bit is a power of two (i.e., only one bit is set).
        if (app_bit == 0 || (app_bit & (app_bit - 1)) != 0) {
            return false;
        }
        // Check if the application is already registered, if not, increment total_boot_steps.
        if ((registered_applications & app_bit) == 0) {
            total_boot_steps++;
        }
        // Use bitwise OR to set the corresponding bit in registered_applications.
        registered_applications |= app_bit;
        return true;
    }

    // Helper function to count the number of bits set to '1' in a uint32_t value.
    uint8_t count_bits_set(uint32_t value) {
        uint8_t count = 0;
        while (value) {
            count += value & 1;
            value >>= 1;
        }
        return count;
    }

    // Function to get the number of unique boot steps that have been completed.
    uint8_t get_boot_steps_completed() {
        return count_bits_set(completed_boot_steps);
    }

    // Function to calculate the boot progress percentage with rounding.
    uint8_t get_boot_progress_percentage() {
        if (total_boot_steps == 0) {
            return 0;
        }
        return static_cast<uint8_t>((get_boot_steps_completed() * 100 + total_boot_steps / 2) / total_boot_steps);
    }

    // Function to check if all registered applications have completed boot.
    bool is_boot_complete() {
        // Boot is complete if all bits set in registered_applications are also set in completed_boot_steps.
        return (registered_applications & completed_boot_steps) == registered_applications;
    }

    // Function to reset the completed boot steps and registered applications to zero.
    void reset_boot_steps() {
        total_boot_steps = 0;
        completed_boot_steps = 0;
        registered_applications = 0;
    }

    // Function to check if a specific boot step has been completed.
    bool is_boot_step_completed(uint32_t step) {
        return (completed_boot_steps & step) != 0;
    }

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_CORE_BOOT
