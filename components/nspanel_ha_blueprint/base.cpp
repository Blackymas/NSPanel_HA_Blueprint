#include "base.h"
#include "esphome/core/application.h"

namespace nspanel_ha_blueprint {

    // Define the global system flags variable (starts with all flags false)
    uint16_t system_flags = 0;

    // Define the global blueprint status flags variable (starts with all flags false)
    uint8_t blueprint_status_flags = 0;

    // System flag functions

    void set_system_flag(NSPanelFlag flag) {
        uint16_t mask = 1 << static_cast<uint8_t>(flag);
        system_flags |= mask;
    }

    void clear_system_flag(NSPanelFlag flag) {
        uint16_t mask = 1 << static_cast<uint8_t>(flag);
        system_flags &= ~mask;
    }

    bool is_system_flag_set(NSPanelFlag flag) {
        return (system_flags & (1 << static_cast<uint8_t>(flag))) != 0;
    }

    bool are_all_system_flags_set(std::initializer_list<NSPanelFlag> required_flags) {
        for (auto flag : required_flags) {
            if (!is_system_flag_set(flag)) {
                return false;
            }  // if any flag not set
        }  // for each required flag
        return true;
    }

    bool are_any_system_flags_set(std::initializer_list<NSPanelFlag> check_flags) {
        for (auto flag : check_flags) {
            if (is_system_flag_set(flag)) {
                return true;
            }  // if any flag is set
        }  // for each flag to check
        return false;
    }

    bool is_device_ready_for_tasks() {
        // Device is NOT ready if any of these blocking operations are active
        return !are_any_system_flags_set({
            NSPanelFlag::OTA_IN_PROGRESS,
            NSPanelFlag::TFT_UPLOAD_ACTIVE,
            NSPanelFlag::SAFE_MODE_ACTIVE
        });
    }

    // Blueprint status flag functions

    void set_blueprint_status_flag(BlueprintStatusFlag flag) {
        uint8_t mask = 1 << static_cast<uint8_t>(flag);
        blueprint_status_flags |= mask;
    }

    void clear_blueprint_status_flag(BlueprintStatusFlag flag) {
        uint8_t mask = 1 << static_cast<uint8_t>(flag);
        blueprint_status_flags &= ~mask;
    }

    bool is_blueprint_status_flag_set(BlueprintStatusFlag flag) {
        return (blueprint_status_flags & (1 << static_cast<uint8_t>(flag))) != 0;
    }

    bool is_blueprint_fully_ready() {
        // Check if all non-reserved blueprint status flags are set (bits 1-5)
        // Active flags mask: 0x3E = 00111110 = bits 1-5
        static constexpr uint8_t ACTIVE_FLAGS_MASK = 0x3E;
        bool fully_ready = (blueprint_status_flags & ACTIVE_FLAGS_MASK) == ACTIVE_FLAGS_MASK;

        // Automatically manage system BLUEPRINT_READY flag based on blueprint completion status
        if (fully_ready) {
            set_system_flag(NSPanelFlag::BLUEPRINT_READY);
        } else {
            clear_system_flag(NSPanelFlag::BLUEPRINT_READY);
        }  // if fully_ready

        return fully_ready;
    }

    float get_blueprint_status_percentage() {
        // Active flags mask: bits 1-5 (PAGE_HOME, QRCODE, PAGE_SETTINGS, RELAY_SETTINGS, GLOBAL_SETTINGS)
        static constexpr uint8_t ACTIVE_FLAGS_MASK = 0x3E;  // 00111110
        static constexpr uint8_t MAX_ACTIVE_VALUE = 62;     // 2^1+2^2+2^3+2^4+2^5

        uint8_t active_flags = blueprint_status_flags & ACTIVE_FLAGS_MASK;
        return active_flags > 0 ? (static_cast<float>(active_flags) / MAX_ACTIVE_VALUE) * 100.0f : 0.0f;
    }

    uint8_t get_blueprint_status_raw_value() {
        // Return only the active flags value (bits 1-5)
        static constexpr uint8_t ACTIVE_FLAGS_MASK = 0x3E;  // 00111110
        return blueprint_status_flags & ACTIVE_FLAGS_MASK;
    }

}  // namespace nspanel_ha_blueprint
