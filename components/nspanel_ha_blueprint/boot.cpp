// boot.cpp

#include "boot.h"  // Include the header file for function and variable declarations.

namespace nspanel_ha_blueprint {

    // Fixed array to store the boot steps
    BootStep boot_steps[MAX_BOOT_STEPS];

    // Function to set up the boot steps array
    void setup_boot_steps() {
        for (size_t i = 0; i < MAX_BOOT_STEPS; ++i) {
            boot_steps[i].completed = false;
            boot_steps[i].registered = false;
        }
    }

    // Function to register an application for boot
    bool register_application(uint8_t index, const char* key, const char* name) {
        if (index >= MAX_BOOT_STEPS) {
            return false;  // Invalid index
        }
        if (boot_steps[index].registered) {
            return true;  // Already registered
        }
        boot_steps[index].registered = true;
        strncpy(boot_steps[index].key, key, sizeof(boot_steps[index].key) - 1);
        boot_steps[index].key[sizeof(boot_steps[index].key) - 1] = '\0';  // Ensure null termination
        strncpy(boot_steps[index].name, name, sizeof(boot_steps[index].name) - 1);
        boot_steps[index].name[sizeof(boot_steps[index].name) - 1] = '\0';  // Ensure null termination
        return true;
    }

    // Function to mark a boot step as completed
    bool complete_boot_step(uint8_t index) {
        if (index >= MAX_BOOT_STEPS || !boot_steps[index].registered) {
            return false;  // Step not found or not registered
        }
        boot_steps[index].completed = true;
        return true;
    }

    // Function to calculate the boot progress percentage with rounding
    uint8_t get_boot_progress_percentage() {
        uint8_t registered_steps = 0;
        uint8_t completed_steps = 0;
        for (size_t i = 0; i < MAX_BOOT_STEPS; ++i) {
            if (boot_steps[i].registered) {
                ++registered_steps;
                if (boot_steps[i].completed) {
                    ++completed_steps;
                }
            }
        }
        if (registered_steps == 0) {
            return 0;
        }
        return static_cast<uint8_t>(round((completed_steps*100) / registered_steps));
    }

    // Function to check if all registered applications have completed boot
    bool is_boot_complete() {
        for (size_t i = 0; i < MAX_BOOT_STEPS; ++i) {
            if (boot_steps[i].registered && !boot_steps[i].completed) {
                return false;
            }
        }
        return true;
    }

    // Function to reset the completed boot steps to the initial state
    void reset_boot_steps() {
        for (size_t i = 0; i < MAX_BOOT_STEPS; ++i) {
            boot_steps[i].completed = false;
        }
    }

    // Function to check if a specific boot step has been completed
    bool is_boot_step_completed(uint8_t index) {
        if (index >= MAX_BOOT_STEPS || !boot_steps[index].registered) {
            return false;
        }
        return boot_steps[index].completed;
    }

    // Function to get the total number of registered boot steps
    uint8_t get_total_registered_boot_steps() {
        uint8_t count = 0;
        for (size_t i = 0; i < MAX_BOOT_STEPS; ++i) {
            if (boot_steps[i].registered) {
                ++count;
            }
        }
        return count;
    }

    // Function to get the total number of completed boot steps
    uint8_t get_completed_boot_steps() {
        uint8_t count = 0;
        for (size_t i = 0; i < MAX_BOOT_STEPS; ++i) {
            if (boot_steps[i].registered && boot_steps[i].completed) {
                ++count;
            }
        }
        return count;
    }

    // Function to get a pointer to a specific boot step by its index
    BootStep* get_boot_step(uint8_t index) {
        if (index >= MAX_BOOT_STEPS || !boot_steps[index].registered) {
            return nullptr;
        }
        return &boot_steps[index];
    }

}  // namespace nspanel_ha_blueprint
