# v4.3.41 - Critical Button Page Format Fix

## Summary

This hotfix resolves a critical issue where button pages were still using the old JSON format
after the CSV conversion in v4.3.40, causing button page functionality to fail.

## Critical Fix

### Button Page Format Conversion Completed

**Fixed button pages still using JSON format** - resolved issue where button pages weren't converted
to the new CSV format during the v4.3.40 protocol overhaul, causing button page failures.

**Issue details:**
- Button pages retained old JSON communication format after v4.3.40 update
- Button pages would fail to load or display correctly
- Inconsistency between button page format and rest of system using CSV
- Affected all users who updated to v4.3.40

**Issue Reference:** #2957

**Result:** Button pages now use CSV format consistently with the rest of the system,
restoring full button page functionality.

## Technical Details

This hotfix completes the JSON to CSV migration started in v4.3.40 by converting
the button page communication that was inadvertently missed during the initial conversion.

**Result:** Complete and consistent CSV-based communication across all pages and components.

---

*Critical hotfix completing the CSV protocol conversion for button pages.*
