# v4.3.44 - Cover Add-on Fix

## Summary

This release fixes a critical issue with the cover add-on where opening and closing operations
were both incorrectly calling the closing routine.

## Critical Fix

### Cover Add-on Open/Close Actions Corrected

**Fixed cover add-on action routing** - resolved issue where both opening and closing operations
were incorrectly calling the closing routine instead of their respective routines.

**Issue details:**
- Cover add-on opening action was calling the closing routine (script)
- Cover add-on closing action was correctly calling the closing routine
- Opening operations would execute closing behavior instead
- Affected all users using the cover add-on

**Fix implemented:**
- Open action now correctly calls the opening routine (script)
- Close action continues to correctly call the closing routine
- Both operations now execute their intended behavior

**Result:** Cover add-on now operates correctly with opening and closing actions
executing their proper routines.

## Technical Details

This fix corrects the action routing in the cover add-on, ensuring that opening and closing
operations call their respective scripts rather than both calling the same closing routine.

**Result:** Proper cover add-on operation with correctly routed opening and closing actions.

---

*Critical fix for cover add-on action routing.*
