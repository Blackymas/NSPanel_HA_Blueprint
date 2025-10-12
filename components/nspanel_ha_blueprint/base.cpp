// base.cpp
#include "base.h"
#include "esphome/core/application.h"

namespace nspanel_ha_blueprint {

    // Define the global system flags variable (starts with all flags false via default constructor)
    SystemFlags system_flags{};

    // Define the global blueprint status flags variable (starts with all flags false via default constructor)
    BlueprintStatusFlags blueprint_status_flags{};

    // Cached device name to avoid repeated lookups and string copies
    std::string cached_device_name;

}  // namespace nspanel_ha_blueprint
