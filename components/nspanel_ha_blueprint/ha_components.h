// ha_components.h
#pragma once

#include <string>

namespace nspanel_ha_blueprint {

    struct HomeAssistantEntity {
        std::string domain;
        std::string id;
    };

    /**
     * Extracts the domain name and unique ID from a given Home Assistant entity string.
     * Handles a special case where "alarm_control_panel" should be shortened to "alarm".
     *
     * @param entity_id The input string containing either the combined domain and unique ID or just the unique ID.
     * @return A HomeAssistantEntity struct containing the extracted domain and the unique ID.
     */
    HomeAssistantEntity extractHomeAssistantEntity(const std::string& entity_id) {
        size_t dotPos = entity_id.find(".");
        HomeAssistantEntity result;
        
        if (dotPos != std::string::npos) {
            // Extract domain and id from the entity_id string
            result.domain = entity_id.substr(0, dotPos);
            result.id = entity_id.substr(dotPos + 1);
        } else {
            // No dot found, the entire entity_id is considered as id.
            result.domain = "invalid";
            result.id = entity_id;
        }
        return result;
    }

}  // namespace nspanel_ha_blueprint
