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

DISABLE_BOOTLOADER_LOGS = "disable_bootloader_logs"
LWIP_TCP_MSS = "lwip_tcp_mss"
MAIN_TASK_STACK_SIZE = "main_task_stack_size"
PSRAM_CLK_PIN = "psram_clk_pin"
PSRAM_CS_PIN = "psram_cs_pin"
REQUIRE_DISARM_BEFORE_REARM = "require_disarm_before_rearm"
TASK_WDT_TIMEOUT_S = "task_wdt_timeout_s"

CONFIG_SCHEMA = cv.Schema({
    cv.Optional(DISABLE_BOOTLOADER_LOGS): cv.boolean,
    cv.Optional(LWIP_TCP_MSS): cv.int_range(min=536, max=1460),
    cv.Optional(MAIN_TASK_STACK_SIZE): cv.int_range(8192, 32768),
    cv.Optional(PSRAM_CLK_PIN): pins.internal_gpio_output_pin_number,
    cv.Optional(PSRAM_CS_PIN): pins.internal_gpio_output_pin_number,
    cv.Optional(REQUIRE_DISARM_BEFORE_REARM): cv.boolean,
    cv.Optional(TASK_WDT_TIMEOUT_S): cv.int_range(min=5, max=300),
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
        add_idf_sdkconfig_option("CONFIG_ESP_PHY_REDUCE_TX_POWER", True)
        add_idf_sdkconfig_option("CONFIG_ESP32_REV_MIN_3", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_BUFFER", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_FREE_CA_CERT", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_FREE_CONFIG_DATA", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_EXTERNAL_MEM_ALLOC", True)
        add_idf_sdkconfig_option("CONFIG_SPIRAM_ALLOW_BSS_SEG_EXTERNAL_MEMORY", True)
        add_idf_sdkconfig_option("CONFIG_SPIRAM_RODATA", True)
        add_idf_sdkconfig_option("CONFIG_SPIRAM_TRY_ALLOCATE_WIFI_LWIP", True)
        if MAIN_TASK_STACK_SIZE in config:
            add_idf_sdkconfig_option("CONFIG_ESP_MAIN_TASK_STACK_SIZE", config[MAIN_TASK_STACK_SIZE])
        if TASK_WDT_TIMEOUT_S in config:
            add_idf_sdkconfig_option("CONFIG_ESP_TASK_WDT_TIMEOUT_S", config[TASK_WDT_TIMEOUT_S])
        if LWIP_TCP_MSS in config:
            add_idf_sdkconfig_option("CONFIG_LWIP_TCP_MSS", config[LWIP_TCP_MSS])

    if REQUIRE_DISARM_BEFORE_REARM in config and config[REQUIRE_DISARM_BEFORE_REARM]:
        cg.add_define("USE_REQUIRE_DISARM_BEFORE_REARM")

    cg.add_define("USE_NSPANEL_HA_BLUEPRINT")
    cg.add_global(nspanel_ha_blueprint_ns.using)
