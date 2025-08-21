# v4.3.22 - Release notes

## 🎯 New Features

### GPIO Pin Customization System

Building on the foundation laid in v4.3.20, we've completed the **GPIO pin customization system** using ESPHome substitutions. All GPIO pins can now be reassigned through simple substitution keys, enabling seamless adaptation to custom hardware layouts without modifying core project files. This feature supports both basic pin reassignments and complex configurations with advanced options, making the blueprint compatible with a wide range of hardware variants while preserving all functionality.

**This feature is primarily intended for users running this firmware on devices other than the standard Sonoff NSPanel.** For complete documentation, configuration examples, and troubleshooting guidance, see the [GPIO Pin Customization Guide](docs/pins_customization.md).

## ⚠️ Breaking Changes

### Arduino Framework Support Deprecated

**Arduino framework support has been officially deprecated and is no longer tested in production builds.**

#### Impact
- **ESP-IDF is now the only officially supported framework** for this project
- Arduino framework builds may still work but are **not guaranteed**
- **No bug fixes or support** will be provided for Arduino framework issues
- Production CI pipeline now only tests ESP-IDF builds, significantly **reducing release time**

#### Why This Change?
- **Aligns with ESPHome recommendations** - ESP-IDF is the default/recommended framework for new users
- **Better memory optimization** - ESP-IDF provides superior flash memory management (critical for this project)
- **Enhanced feature support** - Modern ESPHome features are primarily developed for ESP-IDF
- **Simplified maintenance** - Reduces complexity and improves release reliability
- **Faster development cycle** - Reduced CI time allows for quicker releases

#### Migration Guide
If you're currently using Arduino framework:

1. **Remove from your YAML configuration:**
   ```yaml
   esp32:
     framework:
       type: arduino
   ```

2. **Review component compatibility** - Most components work seamlessly with ESP-IDF
3. **Test your configuration** - ESP-IDF generally provides better performance
4. **Update any custom components** if needed (rare)

#### For Advanced Users
- Daily development builds still include Arduino framework testing for compatibility monitoring
- Arduino framework files remain in the repository but are considered legacy
- Community contributions for Arduino-specific issues will be reviewed on a case-by-case basis

#### Need Help?
- Check the [ESPHome ESP-IDF documentation](https://esphome.io/guides/getting_started_command_line.html#esp-idf-framework)
- Open an issue if you encounter migration problems with ESP-IDF
- Join the discussion in our community channels

**We strongly recommend migrating to ESP-IDF framework for the best experience and future compatibility.**

### Beta Branch Discontinued

**The `beta` branch has been discontinued as it was not being used for its intended purpose.**

#### Key Changes
- **The `beta` branch will be deleted** and is no longer available
- Users referencing `ref: beta` in their configurations will need to update their references
- **Two supported branches remain:** `main` (stable) and `dev` (bleeding edge)

#### Migration for Beta Users
If you're currently using `ref: beta` in your `remote_package`:

**Change from:**
```yaml
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: beta  # Change this line
    refresh: 300s
    files:
      - nspanel_esphome.yaml
```

**Change to:**
```yaml
# For stable releases (recommended)
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main  # Use main for stable releases
    refresh: 300s
    files:
      - nspanel_esphome.yaml

# OR for latest development code (may be unstable)
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: dev  # Use dev for bleeding edge features
    refresh: 300s
    files:
      - nspanel_esphome.yaml
```

#### Branch Strategy Going Forward
- **`main`** - Stable releases, thoroughly tested, recommended for production use
- **`dev`** - Latest development code, may contain bugs, for testing new features

**Users currently on `beta` should migrate to `main` for stability or `dev` for the latest features.**
