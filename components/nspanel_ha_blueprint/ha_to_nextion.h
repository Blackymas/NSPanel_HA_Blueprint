// ha_to_nextion.h

#include <string>
#include <vector>
#include "esphome/core/log.h"          // Ensure the correct logging functionality is included
#include "esphome/components/api/api_server.h"
#include "text.h"
#include "esp_heap_caps.h"

#ifndef PSRAM_ATTR
#define PSRAM_ATTR __attribute__((section(".external_ram")))
#endif

namespace nspanel_ha_blueprint {

    static const char* TAG_HA_TO_NEXTION = "nspanel_ha_blueprint.ha_to_nextion";

    PSRAM_ATTR uint64_t callback_counter = 0;

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
        static HaToNextionManager& getInstance() {
            static HaToNextionManager instance;
            return instance;
        }

        // Method to add a subscription pair to the list
        void addSubscription(const std::string &entity_id, const std::string &page,
                                                const std::string &component, bool is_global) {
            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "New subscription requested to '%s', page '%s', and component '%s'",
                                                entity_id.c_str(), page.c_str(), component.c_str());
            // Check if subscription already exists
            if (findSubscription(page, component) != nullptr) {
                esphome::ESP_LOGW(TAG_HA_TO_NEXTION, "Subscription for page '%s', and component '%s' already exists!",
                                                    page.c_str(), component.c_str());
                return;
            }
            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "No previous subscription found");

            // Create a new EntityTarget dynamically using PSRAM
            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "Allocating memory");
            // Allocate the buffer dynamically
            esphome::ExternalRAMAllocator<EntityTarget> allocator(esphome::ExternalRAMAllocator<EntityTarget>::ALLOW_FAILURE);
            EntityTarget *new_entity_target = allocator.allocate(sizeof(EntityTarget));
            if (!new_entity_target or new_entity_target == nullptr) {
                esphome::ESP_LOGE(TAG_HA_TO_NEXTION, "Failed to allocate memory for new EntityTarget.");
                return;  // Memory allocation failed, do not proceed
            }
            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "Memory allocated");

            // Initialize the new entity target with the provided data
            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "Initialize the new entity target with the provided data");
            copyStringToCharArray(new_entity_target->entity_id, entity_id);
            copyStringToCharArray(new_entity_target->page, page);
            copyStringToCharArray(new_entity_target->component, component);
            new_entity_target->is_global = is_global;
            new_entity_target->nextion_updated = false;                     // Nextion isn't updated when this is initiated
            copyStringToCharArray(new_entity_target->last_state_sent, "");  // Initial state is empty

            // Add the newly created subscription to the list
            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "Add the newly created subscription to the list");
            if (subscriptions_.max_size() == subscriptions_.size()) {
                esphome::ESP_LOGE(TAG_HA_TO_NEXTION, "Subscription list capacity reached. Failed to add new subscription.");
                free(new_entity_target);
                return;
            }

            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "Pushing the newly created subscription to the list");
            subscriptions_.push_back(new_entity_target);

            esphome::ESP_LOGI(TAG_HA_TO_NEXTION, "Successfully added subscription: entity_id='%s', page='%s', component='%s', global=%s",
                                                entity_id.c_str(), page.c_str(), component.c_str(), is_global ? "true" : "false");
        }

        // Method to set up all subscriptions for the current client connection
        void setupSubscriptions() {
            for (auto* subscription : subscriptions_) {
                if (subscription == nullptr) continue;

                // Capture `this` for using instance methods
                esphome::api::global_api_server->subscribe_home_assistant_state(
                    subscription->entity_id, {}, [this, subscription](const std::string &state) {
                        callback_counter++;

                        // Check if the new state is different from the last one sent
                        if (state == subscription->last_state_sent) {
                            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "State for entity '%s' has not changed, no update sent.",
                                                                    subscription->entity_id);
                            return;
                        }

                        // Update the last sent state
                        copyStringToCharArray(subscription->last_state_sent, state);

                        // Determine if we should send the update based on page visibility and global status
                        if (subscription->is_global || isCurrentPage(subscription->page)) {
                            updateNextionDisplay(subscription, state);
                        } else {
                            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "Skipping update for entity '%s' as current page does not match target page '%s'.",
                                                                    subscription->entity_id, subscription->page);
                        }
                    });

                esphome::ESP_LOGI(TAG_HA_TO_NEXTION, "Subscribed to entity: %s for target component '%s' on page '%s'",
                                                        subscription->entity_id, subscription->component,
                                                        subscription->page);
            }
        }

        // Method to reset all subscriptions
        void resetSubscriptions() {
            // Free each dynamically allocated EntityTarget
            for (auto* subscription : subscriptions_) {
                if (subscription != nullptr) {
                    free(subscription);
                }
            }
            // Clear the subscription list
            subscriptions_.clear();

            esphome::ESP_LOGI(TAG_HA_TO_NEXTION, "All subscriptions have been reset. You can now add new subscriptions.");
        }

    private:
        HaToNextionManager() = default;
        ~HaToNextionManager() {
            // Ensure all allocated subscriptions are freed when destroyed
            resetSubscriptions();
        }

        EntityTarget* findSubscription(const std::string &page, const std::string &component) {
            for (auto* subscription : subscriptions_) {
                if (subscription &&
                    subscription->page == page &&
                    subscription->component == component) {
                    return subscription;
                }
            }
            return nullptr;
        }

        static std::vector<EntityTarget*> subscriptions_;

        // Mockup for checking if the current page matches the given page
        bool isCurrentPage(const std::string &page) {
            // Placeholder: replace this with actual logic to check the current Nextion page
            return true;  // Assume it's always true for now
        }

        // Method to update the Nextion display with the new state
        void updateNextionDisplay(EntityTarget* subscription, const std::string &state) {
            // Placeholder: Replace with actual logic to send data to the Nextion display
            if (subscription->is_global) {
                esphome::ESP_LOGI(TAG_HA_TO_NEXTION, "Global Component: Sending update to Nextion for entity '%s' with value: %s",
                                                        subscription->entity_id, state.c_str());
            } else {
                esphome::ESP_LOGI(TAG_HA_TO_NEXTION, "Component '%s' on page '%s': Sending update to Nextion with value: %s",
                                                        subscription->component, subscription->page, state.c_str());
            }

            // Example Nextion command to update the component value (pseudo-code)
            // sendCommandToNextion(subscription->page, subscription->component, state);
        }
    };

    // Initialize the static subscriptions vector
    std::vector<EntityTarget*> HaToNextionManager::subscriptions_;

}  // namespace nspanel_ha_blueprint
