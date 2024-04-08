// ha_components.cpp

#include "ha_components.h"

namespace nspanel_ha_blueprint {

    // Function Definition
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
