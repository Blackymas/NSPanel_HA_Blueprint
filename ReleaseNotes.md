# v2026015 – Hotfix for Blueprint Load Crash

## Summary

This is a **hotfix release** that resolves an issue causing the **blueprint to crash or fail to load on some systems**.
The problem was introduced in **v2026010** as part of changes made
to accommodate the new blueprint input validation introduced by **Home Assistant 2026.1.0**.

## Bug Fixes

### Blueprint Crash on Load (Introduced in v2026010)

**Fixed a bug where the blueprint could crash or fail to load on certain systems.**

**Details:**
- The issue was introduced in **v2026010**
- It was related to adjustments made to handle the new blueprint input validation rules introduced in **Home Assistant 2026.1.0**
- In some environments, these changes caused the blueprint to fail during loading or initialization

**Result:** The blueprint now loads correctly across affected systems, restoring normal operation.

---

*Hotfix release addressing a blueprint load crash introduced in v2026010 while adapting to Home Assistant 2026.1.0 input validation changes.*
