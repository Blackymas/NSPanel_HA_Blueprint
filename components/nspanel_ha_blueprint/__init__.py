# __init__.py

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components.esp32 import add_idf_sdkconfig_option
from esphome.core import CORE, coroutine_with_priority
from esphome import pins
import logging

CODEOWNERS = ["@edwardtfn"]

_LOGGER = logging.getLogger(__name__)

nspanel_ha_blueprint_ns = cg.esphome_ns.namespace('nspanel_ha_blueprint')

PSRAM_CLK_PIN = "psram_clk_pin"
PSRAM_CS_PIN = "psram_cs_pin"
DISABLE_BOOTLOADER_LOGS = "disable_bootloader_logs"

CONFIG_SCHEMA = cv.Schema({
    cv.Optional(PSRAM_CLK_PIN): pins.internal_gpio_output_pin_number,
    cv.Optional(PSRAM_CS_PIN): pins.internal_gpio_output_pin_number,
    cv.Optional(DISABLE_BOOTLOADER_LOGS): cv.boolean,
})


@coroutine_with_priority(1.0)
async def to_code(config):
    # Arduino framework deprecation warning
    if CORE.using_arduino:
        _LOGGER.warning("Arduino framework deprecated in v4.3.22. Migrate to ESP-IDF: https://github.com/Blackymas/NSPanel_HA_Blueprint/blob/main/docs/customization.md#frameworks")

    if PSRAM_CLK_PIN in config:
        clk_pin = config[PSRAM_CLK_PIN]

        if CORE.using_arduino:
            cg.add_build_flag(f"-DCONFIG_D0WD_PSRAM_CLK_IO={clk_pin}")

        if CORE.using_esp_idf:
            add_idf_sdkconfig_option("CONFIG_D0WD_PSRAM_CLK_IO", clk_pin)

    if PSRAM_CS_PIN in config:
        cs_pin = config[PSRAM_CS_PIN]

        if CORE.using_arduino:
            cg.add_build_flag(f"-DCONFIG_D0WD_PSRAM_CS_IO={cs_pin}")

        if CORE.using_esp_idf:
            add_idf_sdkconfig_option("CONFIG_D0WD_PSRAM_CS_IO", cs_pin)

    # Handle bootloader logs configuration - Only when explicitly disabled
    if DISABLE_BOOTLOADER_LOGS in config and config[DISABLE_BOOTLOADER_LOGS]:
        if CORE.using_esp_idf:
            add_idf_sdkconfig_option("CONFIG_BOOTLOADER_LOG_LEVEL_NONE", True)
            add_idf_sdkconfig_option("CONFIG_BOOTLOADER_LOG_LEVEL", 0)
        else:
            # Arduino framework - add build flags for compatibility
            cg.add_build_flag("-DCONFIG_BOOTLOADER_LOG_LEVEL_NONE")
            cg.add_build_flag("-DCONFIG_BOOTLOADER_LOG_LEVEL=0")

    if CORE.using_esp_idf:
        add_idf_sdkconfig_option("CONFIG_BT_ALLOCATION_FROM_SPIRAM_FIRST", True)
        add_idf_sdkconfig_option("CONFIG_BT_BLE_DYNAMIC_ENV_MEMORY", True)
        add_idf_sdkconfig_option("CONFIG_ESP32_REV_MIN_3", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_BUFFER", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_FREE_CA_CERT", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_FREE_CONFIG_DATA", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_EXTERNAL_MEM_ALLOC", True)
        add_idf_sdkconfig_option("CONFIG_SPIRAM_ALLOW_BSS_SEG_EXTERNAL_MEMORY", True)
        add_idf_sdkconfig_option("CONFIG_SPIRAM_RODATA", True)
        add_idf_sdkconfig_option("CONFIG_SPIRAM_TRY_ALLOCATE_WIFI_LWIP", True)

    cg.add_define("USE_NSPANEL_HA_BLUEPRINT")
    cg.add_global(nspanel_ha_blueprint_ns.using)
