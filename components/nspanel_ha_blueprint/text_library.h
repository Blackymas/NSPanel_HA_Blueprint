// text_library.h

#include <string>
#include <vector>
#include "esphome/core/log.h"
#include "esphome/components/api/api_server.h"

namespace nspanel_ha_blueprint {

    static const char* TAG_TEXTS = "nspanel_ha_blueprint.texts";

    bool PageTextInitialized = false;

    // Structure representing a text component on a Nextion page
    struct PageText {
        char page[15];        // The page this text belongs to
        char component[15];   // Component identifier for the text
        char text[101];       // The text content (max 100 characters + null terminator)
        uint16_t text_color;  // RGB565 color value for the text
        bool visible;         // Visibility flag for the text
        bool initiated;       // Has the text component been initiated?

        PageText(const char* page, const char* component, const char* text_content,
                    uint16_t color, bool visibility)
            : text_color(color), visible(visibility), initiated(false) {
            // Copy the page, component, and text content safely
            strncpy(this->page, page, sizeof(this->page) - 1);
            this->page[sizeof(this->page) - 1] = '\0';
            strncpy(this->component, component, sizeof(this->component) - 1);
            this->component[sizeof(this->component) - 1] = '\0';
            strncpy(this->text, text_content, sizeof(this->text) - 1);
            this->text[sizeof(this->text) - 1] = '\0';
        }
    };

    // Vector for managing pointers to text components, allocated dynamically in PSRAM
    using TextVector = std::vector<PageText*, esphome::ExternalRAMAllocator<PageText*>>;
    TextVector* texts;

    // Function to set up the texts management structure
    void setup_texts() {
        if (!PageTextInitialized) {
            // Allocate memory for the texts vector in PSRAM
            esphome::ESP_LOGD(TAG_TEXTS, "Allocating memory for texts vector");

            esphome::ExternalRAMAllocator<TextVector> vector_allocator(
                esphome::ExternalRAMAllocator<TextVector>::ALLOW_FAILURE);

            texts = vector_allocator.allocate(1);  // Allocate memory for 1 vector object

            if (!texts) {
                esphome::ESP_LOGE(TAG_TEXTS, "Failed to allocate memory for texts vector.");
                return;  // Memory allocation failed, do not proceed
            }

            // Use placement new to initialize the vector in allocated memory
            new (texts) TextVector(esphome::ExternalRAMAllocator<PageText*>());

            PageTextInitialized = true;
            esphome::ESP_LOGD(TAG_TEXTS, "Memory allocated for texts vector in PSRAM");
        }
    }

    // Function to find a text component based on page and component ID
    PageText* find_text(const char* page, const char* component) {
        if (texts != nullptr) {
            for (auto* text : *texts) {
                if (strncmp(text->page, page, sizeof(text->page)) == 0 &&
                    strncmp(text->component, component, sizeof(text->component)) == 0) {
                    return text;
                }
            }
        }
        return nullptr; // Text not found
    }

    // Function to add a new text component or update an existing one, and return a pointer to the text
    PageText* add_text(const char* page, const char* component, const char* text_content,
                        uint16_t color, bool visibility) {
        if (!PageTextInitialized)
            setup_texts();

        PageText* existing_text = find_text(page, component);
        if (existing_text != nullptr) {
            // Update the existing text component
            strncpy(existing_text->text, text_content, sizeof(existing_text->text) - 1);
            existing_text->text[sizeof(existing_text->text) - 1] = '\0';
            existing_text->text_color = color;
            existing_text->visible = visibility;
            existing_text->initiated = false;
            return existing_text;
        } else {
            // Allocate memory for the new text component in PSRAM
            esphome::ESP_LOGD(TAG_TEXTS, "Allocating memory for new text %s on page %s", component, page);
            
            esphome::ExternalRAMAllocator<PageText> text_allocator(esphome::ExternalRAMAllocator<PageText>::ALLOW_FAILURE);
            PageText* new_text = text_allocator.allocate(1);  // Allocate memory for 1 PageText in PSRAM

            if (!new_text) {
                esphome::ESP_LOGE(TAG_TEXTS, "Failed to allocate memory for new text.");
                return nullptr;  // Memory allocation failed
            }

            esphome::ESP_LOGD(TAG_TEXTS, "Memory allocated for new text in PSRAM");

            // Use placement new to construct the text in the allocated memory
            new (new_text) PageText(page, component, text_content, color, visibility);

            // Add the newly created text pointer (stored in PSRAM) to the vector
            texts->push_back(new_text);
            return new_text; // Return a pointer to the newly added text
        }
    }

    // Function to find a text or add it if it doesn't exist, with default values for the new text
    PageText* get_text(const char* page, const char* component) {
        PageText* text = find_text(page, component);
        if (text == nullptr) {
            if (!PageTextInitialized)
                setup_texts();
            // Add a new text with default values
            text = add_text(page, component, "Default Text", 0xFFFF, false);
        }
        return text;
    }

    // Function to list all text components on a specific page
    std::vector<PageText*> list_texts_by_page(const char* page) {
        std::vector<PageText*> page_texts;

        if (texts != nullptr) {
            for (auto* text : *texts) {
                if (strncmp(text->page, page, sizeof(text->page)) == 0) {
                    page_texts.push_back(text);
                }
            }
        }

        return page_texts;
    }

    // Destructor for cleanup, if needed
    void cleanup_texts() {
        if (texts != nullptr) {
            // Free each text component
            for (auto* text : *texts) {
                text->~PageText(); // Explicitly call the destructor
                free(text);        // Free the allocated memory for each text
            }
            texts->~TextVector(); // Explicitly call the destructor for the vector
            free(texts);          // Free the allocated memory for the vector
            texts = nullptr;
        }
    }

}  // namespace nspanel_ha_blueprint
