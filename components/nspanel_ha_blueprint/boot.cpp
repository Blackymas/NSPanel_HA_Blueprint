#include "boot.h"
#include "esphome/core/application.h"

namespace nspanel_ha_blueprint {

    void set_boot_flag(uint8_t &flags, BootFlag flag) {
        uint8_t mask = 1 << static_cast<uint8_t>(flag);
        if (!(flags & mask)) {
            flags |= mask;
        }
    }

    void clear_boot_flag(uint8_t &flags, BootFlag flag) {
        uint8_t mask = 1 << static_cast<uint8_t>(flag);
        if (flags & mask) {
            flags &= ~mask;
        }
    }

    bool is_boot_flag_set(uint8_t flags, BootFlag flag) {
        return (flags & (1 << static_cast<uint8_t>(flag))) != 0;
    }

    bool are_all_boot_flags_set(uint8_t flags, std::initializer_list<BootFlag> required_flags) {
        for (auto flag : required_flags) {
            if (!is_boot_flag_set(flags, flag)) {
                return false;
            }
        }
        return true;
    }

}  // namespace nspanel_ha_blueprint
