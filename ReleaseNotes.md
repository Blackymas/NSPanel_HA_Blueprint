# v4.3.37 - Service Call Fix and Weather Integration Improvements

## Summary

This release fixes a critical service call issue that prevented panel controls from working
and modernizes weather integration for better reliability across different weather providers.

## Critical Fixes

### Service Call Functionality Restored

**Fixed service calls broken in recent versions** - resolved issue preventing users from controlling
devices (lights, covers, climate, etc.) from their panels.

**Issue details:**
- Service call functionality was inadvertently broken in recent optimization releases
- Users unable to control lights, covers, and other entities from the panel
- Panel interface appeared to work but commands weren't being executed

**Issues Reference:** 
- #2905
- #2923

**Result:** Full device control functionality restored. Users can now control all entities from their panels again.

### Weather Integration Modernization

**Cleaned up weather implementation** by removing legacy AccuWeather-specific code
and adopting Home Assistant's standardized weather forecast approach.

**Weather improvements:**
- **Removed AccuWeather-specific legacy code** - old implementation tied to specific integration quirks
- **Standardized forecast retrieval** - now uses only `weather.get_forecast` action from Home Assistant
- **Universal compatibility** - works consistently across multiple weather integrations
- **Improved reliability** - more robust weather data handling

**Benefits:**
- Better compatibility with various weather integrations (AccuWeather, Met.no, OpenWeatherMap, etc.)
- More consistent behavior across different weather providers
- Simplified maintenance through standardized Home Assistant API usage

## Technical Details

The service call fix addresses a regression introduced during recent optimization work,
restoring full entity control functionality. The weather modernization aligns the project
with Home Assistant's standardized weather integration approach, improving long-term maintainability.

**Result:** Restored device control functionality with modernized, more reliable weather integration
that works consistently across different weather providers.

---

*Critical service call fix and improved weather integration compatibility.*
