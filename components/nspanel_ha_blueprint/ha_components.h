// ha_components.h

#pragma once

#include <string>

// Defines structures and functions related to Home Assistant entities within the nspanel_ha_blueprint namespace.
namespace nspanel_ha_blueprint {

    // Represents a Home Assistant entity with a domain and an identifier.
    struct HomeAssistantEntity {
        std::string domain;  // The domain part of the entity, like "light" or "switch".
        std::string id;      // The unique identifier of the entity within its domain.
    };

    /**
     * Extracts the domain name and unique ID from a given Home Assistant entity string.
     * 
     * This function parses a Home Assistant entity string to extract and separate the domain
     * and ID components of the entity. If the string does not contain a valid entity format
     * (i.e., "domain.id"), the function will mark the domain as "invalid" and treat the entire
     * string as the ID. It also handles a special case where "alarm_control_panel" should be 
     * shortened to "alarm", though the implementation of this feature needs to be added in the 
     * function's definition in the corresponding .cpp file.
     *
     * Usage example:
     *   auto entity = extractHomeAssistantEntity("light.kitchen");
     *   // entity.domain would be "light"
     *   // entity.id would be "kitchen"
     *
     * @param entity_id The input string containing either the combined domain and unique ID or just the unique ID.
     * @return A HomeAssistantEntity struct containing the extracted domain and the unique ID.
     */
    HomeAssistantEntity extractHomeAssistantEntity(const std::string& entity_id);

}  // namespace nspanel_ha_blueprint
