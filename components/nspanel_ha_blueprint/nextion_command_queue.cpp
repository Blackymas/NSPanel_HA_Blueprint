// nextion_command_queue.cpp

#include "nextion_command_queue.h"

namespace nspanel_ha_blueprint {

    // Singleton instance of NextionCommandQueue
    NextionCommandQueue& NextionCommandQueue::getInstance() {
        static NextionCommandQueue instance;
        return instance;
    }

    NextionCommandQueue::NextionCommandQueue() = default;

    NextionCommandQueue::~NextionCommandQueue() {
        for (auto* command : command_queue_) {
            if (command != nullptr) {
                free(command);
            }
        }
        command_queue_.clear();
    }

    void NextionCommandQueue::addCommand(uint8_t page_id, const std::string &component, CommandType attribute,
                                            const std::string &command) {
        removeDuplicateCommands(page_id, component, attribute);

        #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_DEBUG
        esphome::ESP_LOGD(TAG_NEXTION_COMMAND_QUEUE,
                          "Adding new command to queue: page_id=%u, component='%s', attribute=%d, command='%s'",
                          page_id, component.c_str(), static_cast<int>(attribute), command.c_str());
        #endif

        esphome::ExternalRAMAllocator<NextionCommand>
            allocator(esphome::ExternalRAMAllocator<NextionCommand>::ALLOW_FAILURE);
        NextionCommand* new_command = allocator.allocate(sizeof(NextionCommand));
        if (!new_command || new_command == nullptr) {
            #if ESPHOME_LOG_LEVEL >= ESPHOME_LOG_LEVEL_ERROR
            esphome::ESP_LOGE(TAG_NEXTION_COMMAND_QUEUE, "Failed to allocate memory for new command.");
            #endif
            return;
        }

        new_command->id = command_queue_.empty() ? 1 : command_queue_.back()->id + 1;
        new_command->page_id = page_id;
        strncpy(new_command->component, component.c_str(), sizeof(new_command->component) - 1);
        new_command->component[sizeof(new_command->component) - 1] = '\0';
        new_command->attribute = attribute;
        strncpy(new_command->command, command.c_str(), sizeof(new_command->command) - 1);
        new_command->command[sizeof(new_command->command) - 1] = '\0';

        command_queue_.push_back(new_command);
    }

    void NextionCommandQueue::deleteCommandsForPage(uint8_t page_id) {
        command_queue_.erase(std::remove_if(command_queue_.begin(), command_queue_.end(),
                                            [page_id](NextionCommand* cmd) {
            if (cmd != nullptr && cmd->page_id != page_id) {
                free(cmd);
                return true;
            }
            return false;
        }), command_queue_.end());
        if (command_queue_.empty()) {
            // Reset unique ID when the queue is empty
        }
    }

    void NextionCommandQueue::removeDuplicateCommands(uint8_t page_id, const std::string &component,
                                                        CommandType attribute) {
        command_queue_.erase(std::remove_if(command_queue_.begin(), command_queue_.end(),
                                            [page_id, component, attribute](NextionCommand* cmd) {
            if (cmd != nullptr &&
                cmd->page_id == page_id &&
                strcmp(cmd->component, component.c_str()) == 0 &&
                cmd->attribute == attribute) {
                free(cmd);
                return true;
            }
            return false;
        }), command_queue_.end());
    }

    NextionCommand* NextionCommandQueue::getNextCommand() {
        if (command_queue_.empty()) {
            return nullptr;
        }
        return command_queue_.front();
    }

    void NextionCommandQueue::removeCommandById(uint64_t command_id) {
        command_queue_.erase(std::remove_if(command_queue_.begin(), command_queue_.end(),
                                            [command_id](NextionCommand* cmd) {
            if (cmd != nullptr && cmd->id == command_id) {
                free(cmd);
                return true;
            }
            return false;
        }), command_queue_.end());
        if (command_queue_.empty()) {
            // Reset unique ID when the queue is empty
        }
    }

    std::vector<NextionCommand*> NextionCommandQueue::command_queue_;

}  // namespace nspanel_ha_blueprint
