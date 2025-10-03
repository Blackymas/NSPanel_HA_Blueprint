# v4.3.36 - Critical Blueprint Loading Hotfix

## Summary

This hotfix resolves a critical bug introduced in v4.3.35 that prevented the Blueprint from loading properly.

## Critical Fix

### Blueprint Loading Failure Resolved

**Fixed critical issue preventing Blueprint from loading** - resolved problem introduced in v4.3.35
that broke Blueprint initialization and prevented normal operation.

**Issue details:**
- v4.3.35 alarm fix inadvertently introduced a Blueprint loading failure
- Users updating to v4.3.35 experienced Blueprint initialization problems
- System unable to load configuration from Home Assistant

**Issue Reference:** #2918

**Result:** Blueprint loading restored to normal operation. Users affected by v4.3.35 should update immediately.

## Recommendation

**If you updated to v4.3.35, please update to v4.3.36 immediately** to restore Blueprint functionality.

## Technical Details

This hotfix addresses the regression introduced during the alarm PIN code action fix in v4.3.35,
ensuring Blueprint initialization works correctly while maintaining the alarm functionality improvements.

**Result:** Stable Blueprint operation with working alarm PIN code functionality.

---

*Critical hotfix restoring Blueprint loading functionality.*
