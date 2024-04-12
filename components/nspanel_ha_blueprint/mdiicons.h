// mdiicons.h

#ifndef MDI_ICONS_H
#define MDI_ICONS_H

#include "esphome/core/component.h"
#include "esphome/core/log.h"
#include <cstring>

struct MdiIcon {
    char name[32];  // Icon name, assuming max length of 31 characters + null terminator
    char code[5];   // Icon code, 4 bytes + null terminator (UTF-8 characters)
};

class MdiIcons : public esphome::Component {
 public:
    MdiIcons();  // Constructor declaration

    void setup() override;      // Setup method declaration
    void dump_config() override;  // Dump config method declaration

    const MdiIcon* find_icon(const char* name) const;  // Method to find an icon by name
    bool add_icon(const char* name, const char* code);  // Method to add an icon

 private:
    MdiIcon* iconPool;  // Dynamic array of MdiIcons
    size_t iconPoolSize;  // Number of icons currently in the pool
    size_t iconPoolCapacity;  // Current capacity of the pool

    void resize_pool();  // Method to resize the icon pool
};

#endif  // MDI_ICONS_H
