// page_qrcode.h

#pragma once

#ifdef NSPANEL_HA_BLUEPRINT_PAGE_NOTIFICATION

#include "nextion_components.h"  // For HMIComponent
#include "pages.h"               // For page_names and get_page_id

/**
 * @file page_qrcode.h
 * @brief Nextion component definitions for the QR Code page.
 *
 * This file contains all component constants specific to the QR Code page
 * of the NSPanel interface.
 */

namespace nspanel_ha_blueprint {
  namespace hmi {
    namespace qrcode {

      /**
       * @namespace qrcode
       * @brief Components for the QR Code page.
       *
       * Component ID mapping for the QR Code page
       * Based on the Nextion HMI design file.
       * Note: All components are local scope, so names don't include page prefix.
       */

      // Page definition
      constexpr HMIComponent PAGE = {"qrcode", 17};  ///< QR Code page (index 17 in page_names array)

      // Display components
      constexpr HMIComponent QRCODE_LABEL = {"qrcode_label", 3};  ///< QR code label text (100 chars max)

      // Button components
      constexpr HMIComponent BUTTON_BACK = {"button_back", 4};  ///< Back button (3 chars max) - returns to home

      // Touch components
      constexpr HMIComponent SWIPE = {"swipe", 1};  ///< Swipe gesture handler

      // Timers (for reference)
      constexpr HMIComponent TIMER_SWIPESTORE = {"swipestore", 2};  ///< Swipe store timer

      // All visual components for iteration
      constexpr HMIComponent ALL[] = {
          PAGE,
          QRCODE_LABEL,
          BUTTON_BACK
      };

      constexpr size_t COMPONENT_COUNT = sizeof(ALL) / sizeof(ALL[0]);

    }  // namespace qrcode
  }    // namespace hmi
}  // namespace nspanel_ha_blueprint

#endif  // NSPANEL_HA_BLUEPRINT_PAGE_NOTIFICATION
