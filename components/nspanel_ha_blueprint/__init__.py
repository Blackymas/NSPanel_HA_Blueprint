# __init__.py

import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components.esp32 import add_idf_sdkconfig_option
from esphome.core import CORE, coroutine_with_priority

CODEOWNERS = ["@edwardtfn"]

nspanel_ha_blueprint_ns = cg.esphome_ns.namespace('nspanel_ha_blueprint')
# MdiIcons = nspanel_ha_blueprint_ns.class_('MdiIcons', cg.Component)

CONFIG_SCHEMA = cv.All(
    cv.Schema({}),
)


@coroutine_with_priority(1.0)
async def to_code(config):
    if CORE.using_arduino:
        cg.add_build_flag("-DCONFIG_D0WD_PSRAM_CLK_IO=5")
        cg.add_build_flag("-DCONFIG_D0WD_PSRAM_CS_IO=18")

    if CORE.using_esp_idf:
        add_idf_sdkconfig_option("CONFIG_D0WD_PSRAM_CLK_IO", 5)
        add_idf_sdkconfig_option("CONFIG_D0WD_PSRAM_CS_IO", 18)
        add_idf_sdkconfig_option("CONFIG_BT_ALLOCATION_FROM_SPIRAM_FIRST", True)
        add_idf_sdkconfig_option("CONFIG_BT_BLE_DYNAMIC_ENV_MEMORY", True)
        add_idf_sdkconfig_option("CONFIG_ESP32_REV_MIN_3", True)
        add_idf_sdkconfig_option("CONFIG_ESPTOOLPY_FLASHSIZE", "4MB")  # https://github.com/esphome/issues/issues/5404
        add_idf_sdkconfig_option("CONFIG_ESPTOOLPY_FLASHSIZE_4MB", True)  # https://github.com/esphome/issues/issues/5404
        # add_idf_sdkconfig_option("CONFIG_LWIP_MAX_SOCKETS", 5)  # This breaks web_server
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_BUFFER", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_FREE_CA_CERT", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_DYNAMIC_FREE_CONFIG_DATA", True)
        add_idf_sdkconfig_option("CONFIG_MBEDTLS_EXTERNAL_MEM_ALLOC", True)
        add_idf_sdkconfig_option("CONFIG_SPIRAM_ALLOW_BSS_SEG_EXTERNAL_MEMORY", True)
        add_idf_sdkconfig_option("CONFIG_SPIRAM_RODATA", True)
        add_idf_sdkconfig_option("CONFIG_SPIRAM_TRY_ALLOCATE_WIFI_LWIP", True)
        add_idf_sdkconfig_option("CONFIG_ESPTOOLPY_FLASHSIZE_4MB", True)

    cg.add_define("USE_NSPANEL_HA_BLUEPRINT")
    cg.add_global(nspanel_ha_blueprint_ns.using)

    # Setup the MdiIcons class instance
    # mdi_icons = cg.new_Pvariable('mdi_icons')
    # yield cg.register_component(mdi_icons, config)
