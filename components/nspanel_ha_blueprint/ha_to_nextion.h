// ha_to_nextion.h

#pragma once  // Include guard to prevent multiple inclusions of this header file

#include "esphome/components/api/api_server.h"  // Include for api_server
#include "esphome/core/component.h"             // Include for Component class
#include "esphome/core/log.h"                   // Include for logging functions
#include <vector>

namespace nspanel_ha_blueprint {

    uint64_t callback_counter = 0;

    class ha_to_nextion : public esphome::Component {
    public:
        ha_to_nextion(const std::string &entity_id, const std::string &target)
            : my_entity_id_(entity_id), target_(target) {}

        void subscribe() {
        esphome::ESP_LOGW("ha_to_nextion", "Subscribing to entity: %s with target: %s", my_entity_id_.c_str(), target_.c_str());

        // Assuming api_server is a global or externally accessible object
        if (esphome::api::global_api_server != nullptr) {
            esphome::api::global_api_server->subscribe_home_assistant_state(
                my_entity_id_, {}, [&](const std::string &state) {
                    callback_counter++;
                });
                esphome::ESP_LOGW("ha_to_nextion", "Done!");
        } else {
            esphome::ESP_LOGW("ha_to_nextion", "API server is not available.");
        }
        }

        static void add_instance(const std::string &entity_id, const std::string &target) {
        instances_.emplace_back(entity_id, target);
        instances_.back().subscribe();
        }

    private:
        std::string my_entity_id_;
        std::string target_;
        static std::vector<ha_to_nextion> instances_;
    };

    // Definition of the static vector
    std::vector<ha_to_nextion> ha_to_nextion::instances_;

}  // namespace nspanel_ha_blueprint
