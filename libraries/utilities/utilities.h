// utilities.h

#ifndef UTILITIES_H
#define UTILITIES_H

#pragma once

#include <cstdint>
#include <cstring>  // For std::strcpy
#include <string>

struct UtilitiesGroupValues {
    char group_id[8];  // 7 characters + null terminator
    char value1[11];   // 10 characters + null terminator
    char value2[11];   // 10 characters + null terminator
    int8_t direction;
};

extern UtilitiesGroupValues *UtilitiesGroups;

void resetUtilitiesGroups();
void cleanupUtilitiesGroups();
uint8_t findUtilitiesGroupIndex(const char* group_id);

#endif // UTILITIES_H
