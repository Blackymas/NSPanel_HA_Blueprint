# __init__.py

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components.esp32 import add_idf_sdkconfig_option
from esphome.core import CORE, coroutine_with_priority
from esphome import pins

CODEOWNERS = ["@edwardtfn"]

nspanel_ha_blueprint_ns = cg.esphome_ns.namespace('nspanel_ha_blueprint')

PSRAM_CLK_PIN = "psram_clk_pin"
PSRAM_CS_PIN  = "psram_cs_pin"

CONFIG_SCHEMA = cv.Schema({
    cv.Optional(PSRAM_CLK_PIN): pins.internal_gpio_output_pin_number,
    cv.Optional(PSRAM_CS_PIN):  pins.internal_gpio_output_pin_number,
})


@coroutine_with_priority(1.0)
async def to_code(config):
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

    if CORE.using_esp_idf:
        add_idf_sdkconfig_option("CONFIG_BT_ALLOCATION_FROM_SPIRAM_FIRST", True)
        add_idf_sdkconfig_option("CONFIG_BT_BLE_DYNAMIC_ENV_MEMORY", True)
        add_idf_sdkconfig_option("CONFIG_ESP32_REV_MIN_3", True)
        # add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_BUFFER", True)
        # add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_FREE_CA_CERT", True)
        # add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_FREE_CONFIG_DATA", True)
        # add_idf_sdkconfig_option("CONFIG_MBEDTLS_EXTERNAL_MEM_ALLOC", True)
        # add_idf_sdkconfig_option("CONFIG_SPIRAM_ALLOW_BSS_SEG_EXTERNAL_MEMORY", True)
        # add_idf_sdkconfig_option("CONFIG_SPIRAM_RODATA", True)
        # add_idf_sdkconfig_option("CONFIG_SPIRAM_TRY_ALLOCATE_WIFI_LWIP", True)

    cg.add_define("USE_NSPANEL_HA_BLUEPRINT")
    cg.add_global(nspanel_ha_blueprint_ns.using)
