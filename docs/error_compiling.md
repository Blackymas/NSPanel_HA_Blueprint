# Compiling Errors Guide

The most common cases for compiling errors are related to build files needing to be cleaned up and to lack of resourced on your ESPHome comoiler host.
These are our suggestions for both cases:

## Clean-up build files

Go to your ESPHome Dashboard, click the 3-dot meny related to your device and then "**Clean Build Files**":

![image](https://raw.githubusercontent.com/Blackymas/NSPanel_HA_Blueprint/dev/docs/pics/esphome_dashboard_clean_build_files.png)

## Limited resources on ESPHome compiler host
### Free Up Server Resources
1. Add the following to your device's YAML to reduce resource usage (this may slow down the compilation process):

    ```yaml
    # Limit the amount of resources used for compiling
    esphome:
      compile_process_limit: 1
    ```

    > [!TIP]
    > Place this in a dedicated customization section in your YAML for easier maintenance,
    similar to [this example](https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/customization.md#instructions).

2. Restart your host system, not just Home Assistant. Use the advanced options to **Reboot system**, which also restarts add-ons and can free up memory.

3. Temporarily stop non-essential add-ons in Home Assistant, especially resource-intensive ones like Studio Code Server.

4. [Clean up build files](#clean-up-build-files)

5. Try compiling again.

6. After completion, restart your host system to reactivate the stopped add-ons.

### Compile Using Your Computer
1. Install ESPHome on your computer (Windows, Mac, or Linux) following this guide: [Installing ESPHome Manually](https://esphome.io/guides/installing_esphome.html).

2. With ESPHome installed locally, you can use the ESPHome Dashboard or the [ESPHome Command Line Interface](https://esphome.io/guides/cli.html#command-line-interface) for compilation.
