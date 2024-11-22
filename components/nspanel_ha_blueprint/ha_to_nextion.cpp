// ha_to_nextion.cpp

#include "ha_to_nextion.h"

namespace nspanel_ha_blueprint {

    DRAM_ATTR uint64_t callback_counter = 0;

    // Singleton instance of HaToNextionManager
    HaToNextionManager& HaToNextionManager::getInstance() {
        static HaToNextionManager instance;
        return instance;
    }

    HaToNextionManager::HaToNextionManager() = default;

    HaToNextionManager::~HaToNextionManager() {
        resetSubscriptions();
    }

    void HaToNextionManager::addSubscription(const std::string &entity_id, const std::string &page,
                                                const std::string &component, bool is_global) {
        esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "New subscription requested to '%s', page '%s', and component '%s'",
                            entity_id.c_str(), page.c_str(), component.c_str());
        if (findSubscription(page, component) != nullptr) {
            esphome::ESP_LOGW(TAG_HA_TO_NEXTION, "Subscription for page '%s', and component '%s' already exists!",
                                page.c_str(), component.c_str());
            return;
        }
        esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "No previous subscription found");

        // Allocate the buffer dynamically
        esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "Allocating memory");
        esphome::ExternalRAMAllocator<EntityTarget>
            allocator(esphome::ExternalRAMAllocator<EntityTarget>::ALLOW_FAILURE);
        EntityTarget *new_entity_target = allocator.allocate(sizeof(EntityTarget));
        if (!new_entity_target || new_entity_target == nullptr) {
            esphome::ESP_LOGE(TAG_HA_TO_NEXTION, "Failed to allocate memory for new EntityTarget.");
            return;
        }
        esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "Memory allocated");

        // Initialize the new entity target with the provided data
        copyStringToCharArray(new_entity_target->entity_id, entity_id);
        copyStringToCharArray(new_entity_target->page, page);
        copyStringToCharArray(new_entity_target->component, component);
        new_entity_target->is_global = is_global;
        new_entity_target->nextion_updated = false;
        copyStringToCharArray(new_entity_target->last_state_sent, "");

        // Add the newly created subscription to the list
        if (subscriptions_.max_size() == subscriptions_.size()) {
            esphome::ESP_LOGE(TAG_HA_TO_NEXTION, "Subscription list capacity reached. Failed to add new subscription.");
            free(new_entity_target);
            return;
        }
        subscriptions_.push_back(new_entity_target);
        esphome::ESP_LOGI(TAG_HA_TO_NEXTION,
                            "Successfully added subscription: entity_id='%s', page='%s', component='%s', global=%s",
                            entity_id.c_str(), page.c_str(), component.c_str(), is_global ? "true" : "false");
    }

    void HaToNextionManager::setupSubscriptions() {
        for (auto* subscription : subscriptions_) {
            if (subscription == nullptr) continue;
            esphome::api::global_api_server->subscribe_home_assistant_state(
                subscription->entity_id, {}, [this, subscription](const std::string &state) {
                    callback_counter++;
                    if (state == subscription->last_state_sent) {
                        esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "State for entity '%s' has not changed, no update sent.",
                                            subscription->entity_id);
                        return;
                    }
                    copyStringToCharArray(subscription->last_state_sent, state);
                    if (subscription->is_global || isCurrentPage(subscription->page)) {
                        updateNextionDisplay(subscription, state);
                    } else {
                        esphome::ESP_LOGD(TAG_HA_TO_NEXTION,
                            "Skipping update for entity '%s' as current page does not match target page '%s'.",
                            subscription->entity_id, subscription->page);
                    }
                });
            esphome::ESP_LOGI(TAG_HA_TO_NEXTION, "Subscribed to entity: %s for target component '%s' on page '%s'",
                                subscription->entity_id, subscription->component,
                                subscription->page);
        }
    }

    void HaToNextionManager::resetSubscriptions() {
        for (auto* subscription : subscriptions_) {
            if (subscription != nullptr) {
                free(subscription);
            }
        }
        subscriptions_.clear();
        esphome::ESP_LOGI(TAG_HA_TO_NEXTION, "All subscriptions have been reset. You can now add new subscriptions.");
    }

    EntityTarget* HaToNextionManager::findSubscription(const std::string &page, const std::string &component) {
        for (auto* subscription : subscriptions_) {
            if (subscription &&
                strcmp(subscription->page, page.c_str()) == 0 &&
                strcmp(subscription->component, component.c_str()) == 0) {
                return subscription;
            }
        }
        return nullptr;
    }

    bool HaToNextionManager::isCurrentPage(const std::string &page) {
        // Placeholder: replace this with actual logic to check the current Nextion page
        return true;  // Assume it's always true for now
    }

    void HaToNextionManager::updateNextionDisplay(EntityTarget* subscription, const std::string &state) {
        if (subscription->is_global) {
            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "Global Component: Sending update to Nextion for entity '%s' with value: %s",
                                subscription->entity_id, state.c_str());
        } else {
            esphome::ESP_LOGD(TAG_HA_TO_NEXTION, "Component '%s' on page '%s': Sending update to Nextion with value: %s",
                                subscription->component, subscription->page, state.c_str());
        }
        // Example Nextion command to update the component value (pseudo-code)
        // sendCommandToNextion(subscription->page, subscription->component, state);
    }

    std::vector<EntityTarget*> HaToNextionManager::subscriptions_;

}  // namespace nspanel_ha_blueprint
