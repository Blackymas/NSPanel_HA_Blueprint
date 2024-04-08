// subscriptions.h
#pragma once

#include <vector>
#include <string>
#include <optional>

namespace nspanel_ha_blueprint {

    struct Subscription {
        std::string component_id;
        std::string entity_id;
        int subscription_id;
    };

    std::vector<Subscription> subscriptions;
    std::string subs_component_id;
    std::string subs_entity_id;

}  // namespace nspanel_ha_blueprint
