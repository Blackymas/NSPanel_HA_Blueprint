#pragma once
#include <math.h>

namespace esphome {
namespace ns_panel_ha_blueprint_helper {

int *getMinMaxPositionByAngle(int, int);
float getAngle(int[], int[]);
float getFullAngle(int, int);
float getThermostatRelativePosition(int, int, int, int);
float getTemperature(float, int, int, float);
int *getCoordinatesOnThermostat(int, int, int, int, int);
int *getCoordinatesByTemperature(float, float, float, int, int, int);

} // namespace ns_panel_ha_blueprint_helper
} // namespace esphome
