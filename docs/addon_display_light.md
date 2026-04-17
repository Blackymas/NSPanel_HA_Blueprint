# Add-on: Display Light

## Description
You can set your display as a light in Home Assistant, allowing you to control the brightness
and turn on/off just like any other light. This is useful for automations that control when
your panel is on with the same automation you use for your lights.

**To enable this add-on**, uncomment the following line in your ESPHome YAML packages section:
```yaml
packages:
  remote_package:
    url: https://github.com/Blackymas/NSPanel_HA_Blueprint
    ref: main
    files:
      - nspanel_esphome.yaml
      # Optional add-ons
      - esphome/nspanel_esphome_addon_display_light.yaml  # Uncomment to enable
```

**Features:**
- Control display brightness through Home Assistant
- Turn display on/off like any other light entity
- Include display in lighting automations
- Schedule display sleep/wake times
