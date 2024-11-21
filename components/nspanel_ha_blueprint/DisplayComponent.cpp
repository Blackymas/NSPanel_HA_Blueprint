// DisplayComponent.cpp

#include "DisplayComponent.h"

namespace nspanel_ha_blueprint {

    bool DisplayComponentInitialized = false;

    // Vector for managing pointers to components, allocated dynamically in PSRAM
    using ComponentVector = std::vector<DisplayComponent*, esphome::ExternalRAMAllocator<DisplayComponent*>>;
    ComponentVector* components;

    // Constructor for DisplayComponent
    DisplayComponent::DisplayComponent(uint8_t page_id, const char* component, const char* content,
                                        uint16_t color, uint8_t font, bool visibility)
        : page_id(page_id), color(color), font(font), visible(visibility), initialized(false) {
        // Copy the component name safely
        strncpy(this->component, component, sizeof(this->component) - 1);
        this->component[sizeof(this->component) - 1] = '\0';

        // Store the content (text or icon code)
        strncpy(this->text, content, sizeof(this->text) - 1);
        this->text[sizeof(this->text) - 1] = '\0';
    }

    // Function to set up the components management structure
    void setup_components() {
        if (!DisplayComponentInitialized) {
            // Allocate memory for the components vector in PSRAM
            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
                esphome::ESP_LOGD(TAG_COMPONENTS, "Allocating memory for components vector");
            #endif

            esphome::ExternalRAMAllocator<ComponentVector> vector_allocator(
                esphome::ExternalRAMAllocator<ComponentVector>::ALLOW_FAILURE);

            components = vector_allocator.allocate(1);  // Allocate memory for 1 vector object

            if (!components) {
                #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_ERROR
                    esphome::ESP_LOGE(TAG_COMPONENTS, "Failed to allocate memory for components vector.");
                #endif
                return;  // Memory allocation failed, do not proceed
            }

            // Use placement new to initialize the vector in allocated memory
            new (components) ComponentVector(esphome::ExternalRAMAllocator<DisplayComponent*>());

            DisplayComponentInitialized = true;
            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
                esphome::ESP_LOGD(TAG_COMPONENTS, "Memory allocated for components vector in PSRAM");
            #endif
        }
    }

    // Function to find a component based on page ID and component ID
    DisplayComponent* find_component(uint8_t page_id, const char* component) {
        if (components != nullptr) {
            for (auto* comp : *components) {
                if (comp->page_id == page_id &&
                    strncmp(comp->component, component, sizeof(comp->component)) == 0) {
                    return comp;
                }
            }
        }
        return nullptr; // Component not found
    }

    // Function to add a new component or update an existing one, and return a pointer to the component
    DisplayComponent* add_component(uint8_t page_id, const char* component, const char* content,
                                    uint16_t color, uint8_t font, bool visibility) {
        if (!DisplayComponentInitialized)
            setup_components();

        DisplayComponent* existing_component = find_component(page_id, component);
        if (existing_component != nullptr) {
            // Update the existing component
            strncpy(existing_component->text, content, sizeof(existing_component->text) - 1);
            existing_component->text[sizeof(existing_component->text) - 1] = '\0';
            existing_component->color = color;
            existing_component->font = font;
            existing_component->visible = visibility;
            existing_component->initialized = false;  // Mark as needing re-initialization
            return existing_component;
        } else {
            // Allocate memory for the new component in PSRAM
            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
                esphome::ESP_LOGD(TAG_COMPONENTS, "Allocating memory for new component %s on page %s",
                                    component, page_names[page_id]);
            #endif

            esphome::ExternalRAMAllocator<DisplayComponent>
                component_allocator(esphome::ExternalRAMAllocator<DisplayComponent>::ALLOW_FAILURE);
            // Allocate memory for 1 DisplayComponent in PSRAM
            DisplayComponent* new_component = component_allocator.allocate(1);

            if (!new_component) {
                #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_ERROR
                    esphome::ESP_LOGE(TAG_COMPONENTS, "Failed to allocate memory for new component.");
                #endif
                return nullptr;  // Memory allocation failed
            }

            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
                esphome::ESP_LOGD(TAG_COMPONENTS, "Memory allocated for new component in PSRAM");
            #endif

            // Use placement new to construct the component in the allocated memory
            new (new_component) DisplayComponent(page_id, component, content, color, font, visibility);

            // Mark the component as initialized
            new_component->initialized = false;

            // Add the newly created component pointer (stored in PSRAM) to the vector
            components->push_back(new_component);
            return new_component; // Return a pointer to the newly added component
        }
    }

    // Function to find a component or add it if it doesn't exist, with default values
    DisplayComponent* get_component(uint8_t page_id, const char* component) {
        DisplayComponent* comp = find_component(page_id, component);
        if (comp == nullptr) {
            if (!DisplayComponentInitialized)
                setup_components();
            // Add a new component with default values
            comp = add_component(page_id, component, "", UINT16_MAX, UINT8_MAX, true);
        }
        return comp;
    }

    // Function to list all components on a specific page by page ID
    std::vector<DisplayComponent*> list_components_by_page(uint8_t page_id) {
        std::vector<DisplayComponent*> page_components;

        if (components != nullptr) {
            for (auto* comp : *components) {
                if (comp->page_id == page_id) {
                    page_components.push_back(comp);
                }
            }
        }

        return page_components;
    }

    // Destructor for cleanup, if needed
    void cleanup_components() {
        if (components != nullptr) {
            // Free each component
            for (auto* comp : *components) {
                comp->~DisplayComponent(); // Explicitly call the destructor
                free(comp);                // Free the allocated memory for each component
            }
            components->~ComponentVector(); // Explicitly call the destructor for the vector
            free(components);               // Free the allocated memory for the vector
            components = nullptr;
        }
    }

}  // namespace nspanel_ha_blueprint
