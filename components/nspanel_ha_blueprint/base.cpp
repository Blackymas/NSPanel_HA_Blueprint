#include "base.h"
#include "esphome/core/application.h"

namespace nspanel_ha_blueprint {

    // Define the global system flags variable (starts with all flags false)
    uint16_t system_flags = 0;

    void set_system_flag(uint16_t &flags, NSPanelFlag flag) {
        uint16_t mask = 1 << static_cast<uint8_t>(flag);
        if (!(flags & mask)) {
            flags |= mask;
        }  // if flag not set
    }

    void clear_system_flag(uint16_t &flags, NSPanelFlag flag) {
        uint16_t mask = 1 << static_cast<uint8_t>(flag);
        if (flags & mask) {
            flags &= ~mask;
        }  // if flag is set
    }

    bool is_system_flag_set(uint16_t flags, NSPanelFlag flag) {
        return (flags & (1 << static_cast<uint8_t>(flag))) != 0;
    }

    bool are_all_system_flags_set(uint16_t flags, std::initializer_list<NSPanelFlag> required_flags) {
        for (auto flag : required_flags) {
            if (!is_system_flag_set(flags, flag)) {
                return false;
            }  // if any flag not set
        }  // for each required flag
        return true;
    }

    bool are_any_system_flags_set(uint16_t flags, std::initializer_list<NSPanelFlag> check_flags) {
        for (auto flag : check_flags) {
            if (is_system_flag_set(flags, flag)) {
                return true;
            }  // if any flag is set
        }  // for each flag to check
        return false;
    }

    bool is_device_ready_for_tasks(uint16_t flags) {
        // Device is NOT ready if any of these blocking operations are active
        return !are_any_system_flags_set(flags, {
            NSPanelFlag::OTA_IN_PROGRESS,
            NSPanelFlag::TFT_UPLOAD_ACTIVE,
            NSPanelFlag::SAFE_MODE_ACTIVE
        });
    }

}  // namespace nspanel_ha_blueprint
