// page_utilities.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_PAGE_UTILITIES

#include <cstdint>
#include <cstring>  // For std::strcpy
#include <string>
#include "esphome/core/defines.h"
#include "nextion_components.h"  // For HMIComponent
#include "pages.h"               // For page_names and get_page_id

/**
 * @file page_utilities.h
 * @brief Nextion component definitions for the Utilities page.
 *
 * This file contains all component constants specific to the Utilities dashboard
 * of the NSPanel interface.
 */

namespace nspanel_ha_blueprint {

  extern bool page_utilities_enabled;
  extern uint16_t page_utilities_icon_color;

  struct UtilitiesGroupValues {
    char group_id[8];  // 7 characters + null terminator
    char value1[11];   // 10 characters + null terminator
    char value2[11];   // 10 characters + null terminator
    int8_t direction;
  };

  extern UtilitiesGroupValues *UtilitiesGroups;

  void resetUtilitiesGroups();
  inline void cleanupUtilitiesGroups() {
    if (UtilitiesGroups != nullptr) {
      free(UtilitiesGroups);      // Compatible with both heap_caps_malloc and ps_malloc
      UtilitiesGroups = nullptr;  // Prevent dangling pointers
    }
  };
  uint8_t findUtilitiesGroupIndex(const char* group_id);

  /**
  * Copies the contents of a std::string to a fixed-size char array, ensuring
  * null termination. The destination array size is automatically deduced.
  * Designed for fixed-size char arrays only.
  * 
  * @param dest A reference to the destination char array.
  * @param src The source std::string to copy.
  */
  template <unsigned int N>
  void copyStringToCharArray(char (&dest)[N], const std::string& src) {
    // Ensure we do not exceed the buffer size, leaving space for the null terminator
    size_t length = std::min(src.size(), N - 1);

    // Copy the string data into the destination buffer
    std::strncpy(dest, src.c_str(), length);

    // Explicitly null-terminate the destination buffer
    dest[length] = '\0';
  }

  namespace hmi {
    namespace utilities {

      /**
       * @namespace utilities
       * @brief Components for the Utilities dashboard page.
       *
       * Component ID mapping for the Utilities page (index 27 in page_names array)
       * Based on the typical Nextion HMI design patterns.
       */

      // Page definition
      constexpr HMIComponent PAGE = {"utilities", 27};  ///< Utilities page (index 27 in page_names array)

      // Title components (global scope - accessible from other pages)
      constexpr HMIComponent TITLE = {"utilities.title", 1};        ///< Page title display
      constexpr HMIComponent TITLE_ICON = {"utilities.title_icon", 2};  ///< Title icon

      // Grid group components
      constexpr HMIComponent GRID_LABEL = {"utilities.grid_label", 10};      ///< Grid area label
      constexpr HMIComponent GRID_ICON = {"utilities.grid_icon", 11};        ///< Grid area icon
      constexpr HMIComponent GRID_VALUE1 = {"utilities.grid_value1", 12};    ///< Grid value 1
      constexpr HMIComponent GRID_VALUE2 = {"utilities.grid_value2", 13};    ///< Grid value 2

      // Home group components
      constexpr HMIComponent HOME_LABEL = {"utilities.home_label", 20};      ///< Home area label
      constexpr HMIComponent HOME_ICON = {"utilities.home_icon", 21};        ///< Home area icon
      constexpr HMIComponent HOME_VALUE1 = {"utilities.home_value1", 22};    ///< Home value 1
      constexpr HMIComponent HOME_VALUE2 = {"utilities.home_value2", 23};    ///< Home value 2

      // Group 1 components
      constexpr HMIComponent GROUP01_LABEL = {"utilities.group01_label", 30};   ///< Group 1 label
      constexpr HMIComponent GROUP01_ICON = {"utilities.group01_icon", 31};     ///< Group 1 icon
      constexpr HMIComponent GROUP01_VALUE1 = {"utilities.group01_value1", 32}; ///< Group 1 value 1
      constexpr HMIComponent GROUP01_VALUE2 = {"utilities.group01_value2", 33}; ///< Group 1 value 2
      constexpr HMIComponent GROUP01_LINE = {"utilities.group01_line", 34};     ///< Group 1 flow line

      // Group 2 components
      constexpr HMIComponent GROUP02_LABEL = {"utilities.group02_label", 40};   ///< Group 2 label
      constexpr HMIComponent GROUP02_ICON = {"utilities.group02_icon", 41};     ///< Group 2 icon
      constexpr HMIComponent GROUP02_VALUE1 = {"utilities.group02_value1", 42}; ///< Group 2 value 1
      constexpr HMIComponent GROUP02_VALUE2 = {"utilities.group02_value2", 43}; ///< Group 2 value 2
      constexpr HMIComponent GROUP02_LINE = {"utilities.group02_line", 44};     ///< Group 2 flow line

      // Group 3 components
      constexpr HMIComponent GROUP03_LABEL = {"utilities.group03_label", 50};   ///< Group 3 label
      constexpr HMIComponent GROUP03_ICON = {"utilities.group03_icon", 51};     ///< Group 3 icon
      constexpr HMIComponent GROUP03_VALUE1 = {"utilities.group03_value1", 52}; ///< Group 3 value 1
      constexpr HMIComponent GROUP03_VALUE2 = {"utilities.group03_value2", 53}; ///< Group 3 value 2
      constexpr HMIComponent GROUP03_LINE = {"utilities.group03_line", 54};     ///< Group 3 flow line

      // Group 4 components
      constexpr HMIComponent GROUP04_LABEL = {"utilities.group04_label", 60};   ///< Group 4 label
      constexpr HMIComponent GROUP04_ICON = {"utilities.group04_icon", 61};     ///< Group 4 icon
      constexpr HMIComponent GROUP04_VALUE1 = {"utilities.group04_value1", 62}; ///< Group 4 value 1
      constexpr HMIComponent GROUP04_VALUE2 = {"utilities.group04_value2", 63}; ///< Group 4 value 2
      constexpr HMIComponent GROUP04_LINE = {"utilities.group04_line", 64};     ///< Group 4 flow line

      // Group 5 components
      constexpr HMIComponent GROUP05_LABEL = {"utilities.group05_label", 70};   ///< Group 5 label
      constexpr HMIComponent GROUP05_ICON = {"utilities.group05_icon", 71};     ///< Group 5 icon
      constexpr HMIComponent GROUP05_VALUE1 = {"utilities.group05_value1", 72}; ///< Group 5 value 1
      constexpr HMIComponent GROUP05_VALUE2 = {"utilities.group05_value2", 73}; ///< Group 5 value 2
      constexpr HMIComponent GROUP05_LINE = {"utilities.group05_line", 74};     ///< Group 5 flow line

      // Group 6 components
      constexpr HMIComponent GROUP06_LABEL = {"utilities.group06_label", 80};   ///< Group 6 label
      constexpr HMIComponent GROUP06_ICON = {"utilities.group06_icon", 81};     ///< Group 6 icon
      constexpr HMIComponent GROUP06_VALUE1 = {"utilities.group06_value1", 82}; ///< Group 6 value 1
      constexpr HMIComponent GROUP06_VALUE2 = {"utilities.group06_value2", 83}; ///< Group 6 value 2
      constexpr HMIComponent GROUP06_LINE = {"utilities.group06_line", 84};     ///< Group 6 flow line

      // Navigation button
      constexpr HMIComponent BUTTON_BACK = {"button_back", 90};  ///< Back button (local scope)

    }  // namespace utilities
  }    // namespace hmi
}  // namespace nspanel_ha_blueprint

#endif // NSPANEL_HA_BLUEPRINT_PAGE_UTILITIES
