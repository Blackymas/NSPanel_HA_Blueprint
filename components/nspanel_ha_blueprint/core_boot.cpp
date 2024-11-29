// core_boot.cpp

#ifdef NSPANEL_HA_BLUEPRINT_CORE_BOOT

#include "core_boot.h"  // Include the header file for function and variable declarations.

namespace nspanel_ha_blueprint {
    BootStepVector* boot_steps = nullptr;

    // Function to set up the boot steps vector
    void setup_boot_steps() {
        if (!boot_steps) {
            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
                esphome::ESP_LOGD("boot_steps", "Allocating memory for boot steps vector in PSRAM");
            #endif

            esphome::ExternalRAMAllocator<BootStepVector> vector_allocator(
                esphome::ExternalRAMAllocator<BootStepVector>::ALLOW_FAILURE);
            boot_steps = vector_allocator.allocate(1);

            if (!boot_steps) {
                #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_ERROR
                    esphome::ESP_LOGE("boot_steps", "Failed to allocate memory for boot steps vector.");
                #endif
                return;
            }

            // Use placement new to initialize the vector in allocated memory
            new (boot_steps) BootStepVector(esphome::ExternalRAMAllocator<BootStep>());

            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
                esphome::ESP_LOGD("boot_steps", "Memory allocated for boot steps vector in PSRAM");
            #endif
        }
    }

    // Function to register an application for boot.
    bool register_application(uint8_t id, const char* name) {
        if (!boot_steps) {
            setup_boot_steps();
        }

        // Validate that the id is a power of two (i.e., only one bit is set)
        if (id == 0 || (id & (id - 1)) != 0) {
            return false;
        }
        // Check if the application is already registered
        for (const auto& step : *boot_steps) {
            if (step.id == id) {
                return false; // Already registered
            }
        }
        // Add new boot step to the list
        boot_steps->emplace_back(id, name);
        return true;
    }

    // Function to mark a boot step as completed.
    bool complete_boot_step(uint8_t id) {
        for (auto& step : *boot_steps) {
            if (step.id == id) {
                step.completed = true;
                return true;
            }
        }
        return false; // Step not found
    }

    // Function to calculate the boot progress percentage with rounding.
    uint8_t get_boot_progress_percentage() {
        if (boot_steps == nullptr || boot_steps->empty()) {
            return 0;
        }
        uint8_t completed_steps = 0;
        for (const auto& step : *boot_steps) {
            if (step.completed) {
                completed_steps++;
            }
        }
        return static_cast<uint8_t>((completed_steps * 100 + boot_steps->size() / 2) / boot_steps->size());
    }

    // Function to check if all registered applications have completed boot.
    bool is_boot_complete() {
        if (boot_steps == nullptr) {
            return false;
        }
        for (const auto& step : *boot_steps) {
            if (!step.completed) {
                return false;
            }
        }
        return true;
    }

    // Function to reset the completed boot steps to the initial state.
    void reset_boot_steps() {
        if (boot_steps == nullptr) {
            return;  // No boot steps to reset
        }
        for (auto& step : *boot_steps) {
            step.completed = false;
        }
    }

    // Function to check if a specific boot step has been completed.
    bool is_boot_step_completed(uint8_t id) {
        if (boot_steps == nullptr) {
            return false;
        }
        for (const auto& step : *boot_steps) {
            if (step.id == id) {
                return step.completed;
            }
        }
        return false;
    }

    // Function to get the total number of registered boot steps
    uint8_t get_total_registered_boot_steps() {
        if (boot_steps == nullptr) {
            return 0;
        }
        return static_cast<uint8_t>(boot_steps->size());
    }

    // Function to get the total number of completed boot steps
    uint8_t get_completed_boot_steps() {
        if (boot_steps == nullptr) {
            return 0;
        }
        uint8_t completed_steps = 0;
        for (const auto& step : *boot_steps) {
            if (step.completed) {
                completed_steps++;
            }
        }
        return completed_steps;
    }

    // Function to get a pointer to a specific boot step by its ID
    BootStep* get_boot_step(uint8_t id) {
        if (boot_steps == nullptr) {
            return nullptr;
        }
        for (auto& step : *boot_steps) {
            if (step.id == id) {
                return &step;
            }
        }
        return nullptr; // Step not found
    }

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_CORE_BOOT
