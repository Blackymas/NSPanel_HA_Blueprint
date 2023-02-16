#include "helpers.h"
#include <math.h>

namespace esphome {
namespace ns_panel_ha_blueprint_helper {

int *getMinMaxPositionByAngle(int angle, int thermostat_radius) {
  static int r[2] = {0, 0};
  angle = 360 - angle;
  float angleStart = angle + (180 - angle) / 2;
  float angleEnd = angleStart - angle;
  float pi = 22.0f / 7.0;

  r[0] = round(cos(angleStart * pi / 180) * thermostat_radius + 0);
  r[1] = round(sin(angleStart * pi / 180) * thermostat_radius + 0);

  return r;
}

float getAngle(int *p1, int *p2) {
  int center = 0;
  float pi = 22.0f / 7.0;

  float a = pow(center - p1[0], 2) + pow(center - p1[1], 2);
  float b = pow(center - p2[0], 2) + pow(center - p2[1], 2);
  float c = pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2);
  return acos((a + b - c) / sqrt(4 * a * b)) * 180 / pi;
}

float getFullAngle(int minX, int minY) {
  int a[2];
  int b[2];

  a[0] = minX;
  a[1] = minY;

  b[0] = minX * -1;
  b[1] = minY;

  return 360 - getAngle(a, b);
}

float getThermostatRelativePosition(int x, int y, int minX, int minY) {
  int a[2];
  int b[2];
  int c[2];

  a[0] = minX;
  a[1] = minY;

  b[0] = 0;
  b[1] = -1;

  c[0] = x;
  c[1] = y;

  float angle = getAngle(a, b);
  float fullAngle = getFullAngle(minX, minY);

  if (x < 0) {
    angle = getAngle(a, c);
  } else {
    angle += getAngle(b, c);
  }

  return angle / fullAngle;
}

float getTemperature(float thermostatRelativePosition, int minT, int maxT,
                     float step) {
  float temperature = (maxT - minT) * thermostatRelativePosition + minT;
  float div = floor(temperature / step);
  return div * step;
}

int *getCoordinatesOnThermostat(int x, int y, int radius, int minX, int minY) {
  static int r[2] = {0, 0};
  double hypotenuse = sqrt(double(x * x + y * y));
  double hypDiv = radius / (hypotenuse - radius);

  float coordTX = (0 + hypDiv * x) / (1 + hypDiv);
  float coordTY = (0 + hypDiv * y) / (1 + hypDiv);

  if (coordTY > minY) {
    coordTY = minY;
    if (coordTX < 0) {
      coordTX = minX;
    } else {
      coordTX = minX * -1;
    }
  }

  r[0] = int(coordTX);
  r[1] = int(coordTY);

  return r;
}

int *getCoordinatesByTemperature(float temperature, float minT, float maxT,
                                 int radius, int minX, int minY) {
  static int r[2] = {0, 0};
  float pi = 22.0f / 7.0;
  float fullAngle = getFullAngle(minX, minY);
  float midValue = (minT + maxT) / 2;

  if (temperature < minT) {
    temperature = minT;
  } else if (temperature > maxT) {
    temperature = maxT;
  }

  float angle =
      180 - ((fullAngle / 2) * (temperature - midValue)) / (maxT - midValue);
  r[0] = round(sin(angle * pi / 180) * radius + 0);
  r[1] = round(cos(angle * pi / 180) * radius + 0);

  return r;
}

} // namespace ns_panel_ha_blueprint_helper
} // namespace esphome