import esphome.codegen as cg
import esphome.config_validation as cv

helper_ns = cg.esphome_ns.namespace("ns_panel_ha_blueprint_helper")

CONFIG_SCHEMA = cv.All(
    cv.Schema({}),
)

async def to_code(config):
  cg.add_global(helper_ns.using)
  