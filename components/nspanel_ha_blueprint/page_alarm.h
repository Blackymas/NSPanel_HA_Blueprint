#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_PAGE_ALARM

namespace esphome {
namespace nspanel {

  // Home Assistant alarm control panel supported features
  // Matches Home Assistant AlarmControlPanelEntityFeature values
  enum class AlarmFeature : uint8_t {
    ARM_HOME = 1,            // 0b00000001
    ARM_AWAY = 2,            // 0b00000010
    ARM_NIGHT = 4,           // 0b00000100
    ARM_CUSTOM_BYPASS = 16,  // 0b00010000
    ARM_VACATION = 32,       // 0b00100000
    ALWAYS_SHOW = 0          // Special value for always-visible buttons
  };

}  // namespace nspanel
}  // namespace esphome

#endif  // NSPANEL_HA_BLUEPRINT_PAGE_ALARM
