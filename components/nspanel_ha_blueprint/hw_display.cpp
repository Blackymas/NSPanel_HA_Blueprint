// hw_display.cpp

#ifdef NSPANEL_HA_BLUEPRINT_HW_DISPLAY

#include "hw_display.h"

namespace nspanel_ha_blueprint {

    static const char *TAG_COMPONENT_HW_DISPLAY = "nspanel.component.hw_display";

    uint8_t display_mode = UINT8_MAX;
    uint8_t display_charset = UINT8_MAX;

    bool ComponentVisibilityInitialized = false;

    // Vector for managing pointers to components, allocated dynamically in PSRAM
    using ComponentVector = std::vector<ComponentVisibility*, esphome::RAMAllocator<ComponentVisibility*>>;
    ComponentVector* components;

    // Constructor for ComponentVisibility
    ComponentVisibility::ComponentVisibility(uint8_t page_id, const char* component, bool visibility)
        : page_id(page_id), visible(visibility) {
        // Copy the component name safely
        strncpy(this->component, component, sizeof(this->component) - 1);
        this->component[sizeof(this->component) - 1] = '\0';
    }

    // Function to set up the components management structure
    void setup_components_visibility() {
        if (!ComponentVisibilityInitialized) {
            // Allocate memory for the components vector in PSRAM
            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
                ESP_LOGD(TAG_COMPONENT_HW_DISPLAY, "Alloc components vector");
            #endif

            esphome::RAMAllocator<ComponentVector> vector_allocator;

            components = vector_allocator.allocate(1);  // Allocate memory for 1 vector object

            if (!components) {
                #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_ERROR
                    ESP_LOGE(TAG_COMPONENT_HW_DISPLAY, "Components vector alloc failed");
                #endif
                return;  // Memory allocation failed, do not proceed
            }

            // Use placement new to initialize the vector in allocated memory
            new (components) ComponentVector(esphome::RAMAllocator<ComponentVisibility*>());

            ComponentVisibilityInitialized = true;
            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
                ESP_LOGD(TAG_COMPONENT_HW_DISPLAY, "Components vector ready (PSRAM)");
            #endif
        }
    }

    // Function to find a component based on page ID and component ID
    ComponentVisibility* find_component_visibility(uint8_t page_id, const char* component) {
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
    ComponentVisibility* add_component_visibility(uint8_t page_id, const char* component, bool visibility) {
        if (!ComponentVisibilityInitialized)
            setup_components_visibility();

        ComponentVisibility* existing_component = find_component_visibility(page_id, component);
        if (existing_component != nullptr) {
            // Update the existing component
            existing_component->visible = visibility;
            return existing_component;
        } else {
            // Allocate memory for the new component in PSRAM
            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_VERBOSE
                ESP_LOGV(TAG_COMPONENT_HW_DISPLAY, "New component: %s.%s", page_names[page_id], component);
            #endif

            esphome::RAMAllocator<ComponentVisibility> component_allocator;
            // Allocate memory for 1 ComponentVisibility in PSRAM
            ComponentVisibility* new_component = component_allocator.allocate(1);

            if (!new_component) {
                #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_ERROR
                    ESP_LOGE(TAG_COMPONENT_HW_DISPLAY, "Component alloc failed");
                #endif
                return nullptr;  // Memory allocation failed
            }

            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_VERY_VERBOSE
                ESP_LOGVV(TAG_COMPONENT_HW_DISPLAY, "Component ready (PSRAM)");
            #endif

            // Use placement new to construct the component in the allocated memory
            new (new_component) ComponentVisibility(page_id, component, visibility);

            // Add the newly created component pointer (stored in PSRAM) to the vector
            components->push_back(new_component);
            return new_component; // Return a pointer to the newly added component
        }
    }

    // Function to find a component or add it if it doesn't exist, with default values
    ComponentVisibility* get_component_visibility(uint8_t page_id, const char* component) {
        ComponentVisibility* comp = find_component_visibility(page_id, component);
        if (comp == nullptr) {
            if (!ComponentVisibilityInitialized)
                setup_components_visibility();
            // Add a new component with default visibility (true)
            comp = add_component_visibility(page_id, component, true);
        }
        return comp;
    }

    // Function to list all components on a specific page by page ID
    std::vector<ComponentVisibility*> list_components_visibility_by_page(uint8_t page_id) {
        std::vector<ComponentVisibility*> page_components;

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
    void cleanup_components_visibility() {
        if (components != nullptr) {
            // Free each component using the same allocator that allocated them
            esphome::RAMAllocator<ComponentVisibility> component_allocator;
            for (auto* comp : *components) {
                comp->~ComponentVisibility(); // Explicitly call the destructor
                component_allocator.deallocate(comp, 1); // Use RAMAllocator deallocate
            }
            
            // Free the vector itself
            components->~ComponentVector(); // Explicitly call the destructor for the vector
            esphome::RAMAllocator<ComponentVector> vector_allocator;
            vector_allocator.deallocate(components, 1); // Use RAMAllocator deallocate
            components = nullptr;
            ComponentVisibilityInitialized = false;
        }
    }

}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_HW_DISPLAY
