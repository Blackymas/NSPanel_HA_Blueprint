// ha_to_nextion.h

#pragma once

#include <string>
#include <vector>
#include "esp_attr.h"  // Include for PSRAM attributes
#include "esphome/core/log.h"
#include "esphome/components/api/api_server.h"
#include "text.h"

namespace nspanel_ha_blueprint {

    static const char* TAG_HA_TO_NEXTION = "nspanel_ha_blueprint.ha_to_nextion";

    extern uint64_t callback_counter;

    struct EntityTarget {
        char entity_id[256];       // The Home Assistant entity_id to subscribe to
        char page[15];             // The target page on the Nextion display
        char component[15];        // The target component on the specified page
        bool is_global;            // If true, always send update regardless of the current page
        bool nextion_updated;      // Is Nextion updated with the latest state
        char last_state_sent[256]; // Track the last state sent to avoid duplicate updates
    };

    class HaToNextionManager {
    public:
        static HaToNextionManager& getInstance();

        void addSubscription(const std::string &entity_id, const std::string &page,
                                const std::string &component, bool is_global);

        void setupSubscriptions();
        void resetSubscriptions();

    private:
        HaToNextionManager();
        ~HaToNextionManager();

        EntityTarget* findSubscription(const std::string &page, const std::string &component);

        static std::vector<EntityTarget*> subscriptions_;

        bool isCurrentPage(const std::string &page);
        void updateNextionDisplay(EntityTarget* subscription, const std::string &state);
    };

}  // namespace nspanel_ha_blueprint
