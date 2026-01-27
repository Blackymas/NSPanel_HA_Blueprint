# v2026014 – Hotfix for Indoor Temperature Sensor Blueprint Crash

## Summary

This is a **hotfix release** that resolves a critical issue causing the **blueprint to crash when an indoor temperature sensor is selected**.

## Bug Fixes

### Blueprint Crash with Indoor Temperature Sensor (Issue #3215)

**Fixed a bug where selecting an indoor temperature sensor caused the blueprint to crash.**

**Details:**
- The issue occurred when an indoor temperature sensor entity was selected in the blueprint
- This caused the automation to fail during loading or execution

**Result:** The blueprint now handles indoor temperature sensors correctly, preventing crashes and restoring normal operation.  
(Tracked as **#3215**)

---

*Hotfix release addressing a blueprint crash when using an indoor temperature sensor.*
