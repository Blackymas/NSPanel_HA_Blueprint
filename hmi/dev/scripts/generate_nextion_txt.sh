#!/usr/bin/env bash

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
HMI_DIR=$SCRIPT_DIR/../..

docker run --rm -ti -v "${HMI_DIR}:/usr/src/app" sztupy/nextion-hmi2txt -i /usr/src/app/nspanel_blank.HMI -o /usr/src/app/dev/nspanel_blank_code -p visual unknown
docker run --rm -ti -v "${HMI_DIR}:/usr/src/app" sztupy/nextion-hmi2txt -i /usr/src/app/nspanel_CJK_eu.HMI -o /usr/src/app/dev/nspanel_CJK_eu_code -p visual unknown
docker run --rm -ti -v "${HMI_DIR}:/usr/src/app" sztupy/nextion-hmi2txt -i /usr/src/app/nspanel_CJK_us_land.HMI -o /usr/src/app/dev/nspanel_CJK_us_land_code -p visual unknown
docker run --rm -ti -v "${HMI_DIR}:/usr/src/app" sztupy/nextion-hmi2txt -i /usr/src/app/nspanel_CJK_us.HMI -o /usr/src/app/dev/nspanel_CJK_us_code -p visual unknown
docker run --rm -ti -v "${HMI_DIR}:/usr/src/app" sztupy/nextion-hmi2txt -i /usr/src/app/nspanel_eu.HMI -o /usr/src/app/dev/nspanel_eu_code  -p visual unknown 
docker run --rm -ti -v "${HMI_DIR}:/usr/src/app" sztupy/nextion-hmi2txt -i /usr/src/app/nspanel_us_land.HMI -o /usr/src/app/dev/nspanel_us_land_code -p visual unknown 
docker run --rm -ti -v "${HMI_DIR}:/usr/src/app" sztupy/nextion-hmi2txt -i /usr/src/app/nspanel_us.HMI -o /usr/src/app/dev/nspanel_us_code -p visual unknown 