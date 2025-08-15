# Release Notes

## Summary

This release focuses on simplifying the development and release process.
We are moving to **smaller, more frequent releases** to reduce bugs, improve testing, and make updates easier for users.
Key changes include **removing the BLE Tracker and Bluetooth Proxy add-ons** (now handled natively) and
reorganizing the codebase for better maintainability.

## Release Goals

Our last major feature release was over a year ago. Over time, the NSPanel project has grown in complexity,
and each release now requires significant effort to prepare.
This has led to fewer, larger releases — which are harder to test and more likely to accumulate critical bugs, ultimately reducing overall quality.

We have been working on a new main release for over a year but ended up getting stuck in a cycle of bugs and fixes.
To break this loop, one of the main goals of this release is to simplify the process:

- Shift towards smaller, more frequent releases with fewer changes per release, reducing the chance of critical bugs.
- Make the update process easier for users, so everyone can benefit from improvements sooner.
- Simplify parts of the codebase to make it more approachable for new contributors and encourage community involvement.

In the coming days, we’ll focus on making updates smoother for users and continuing code simplification,
setting the foundation for a healthier release cycle going forward.

---

As part of this simplification, we are removing the **BLE Tracker** and **Bluetooth Proxy** add-ons.
Previously, these add-ons wrapped ESPHome’s native components with a few extra lines to stop them
before starting a TFT upload (as full memory is required at that moment).

With this release, we have moved that stop routine to a lower level, using ESP-IDF’s native methods. This means the add-ons are no longer needed.
You can still use those components by following ESPHome’s official documentation (just be mindful of memory usage, as they are memory-hungry).
Removing them also reduces the number of files we have to maintain.

We are also reorganizing the project into smaller, more focused files so all code related to a specific functionality can be found in the same place.
Users will not notice any functional change and do not need to adjust their settings — unless you have custom modifications to this project’s files.
In that case, you may need to move your changes to the correct new file locations.

From now on, release notes will also be simplified to include only items relevant to the current release.

## Breaking Changes

- **Removed Add-ons:** BLE Tracker and Bluetooth Proxy add-ons have been removed.
- **Reason:** Improved Bluetooth memory management now happens at a lower level and no longer requires specific component IDs for TFT uploads.
- **Benefits:** Simplified setup, better user experience, reduced maintenance overhead.
- **Migration:** Use native ESPHome components directly:
  - [ESPHome BLE Tracker](https://esphome.io/components/esp32_ble_tracker.html)
  - [ESPHome Bluetooth Proxy](https://esphome.io/components/bluetooth_proxy.html)
