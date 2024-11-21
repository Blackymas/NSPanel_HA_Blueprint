// nextion_command_queue.h

#pragma once

#include <string>
#include <vector>
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace nspanel_ha_blueprint {

    static const char* TAG_NEXTION_COMMAND_QUEUE = "nspanel_ha_blueprint.nextion_command_queue";

    enum class CommandType {
        TEXT,
        COLOR,
        VISIBILITY,
        FONT,
        // Add more types as needed
    };

    struct NextionCommand {
        uint64_t id;               // Unique identifier for the command
        uint8_t page_id;           // The page id for the command
        char component[15];        // Component associated with the command
        CommandType attribute;     // Command type identifier
        char command[128];         // The command to be sent (fixed size for PSRAM allocation)
    };

    class NextionCommandQueue {
    public:
        static NextionCommandQueue& getInstance();

        void addCommand(uint8_t page_id, const std::string &component,
                        CommandType attribute, const std::string &command);
        void deleteCommandsForPage(uint8_t page_id);
        NextionCommand* getNextCommand();
        void removeCommandById(uint64_t command_id);

    private:
        NextionCommandQueue();
        ~NextionCommandQueue();

        void removeDuplicateCommands(uint8_t page_id, const std::string &component, CommandType attribute);

        static std::vector<NextionCommand*> command_queue_;
    };

}  // namespace nspanel_ha_blueprint
