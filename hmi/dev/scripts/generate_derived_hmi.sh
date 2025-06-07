#!/usr/bin/env bash
#
# Generates US_landscape HMI from EU version.
# Afterwards generates all three CJK variants from the non-CJK version

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
HMI_DIR=$SCRIPT_DIR/../..

call_with_retries () {
  COMMAND=$1
  INPUT=$2
  OUTPUT=$3
  RETRIES=${4:-0}
  OUTPUT_TFT=${OUTPUT%.*}.tft

  if [ "$RETRIES" -gt 3 ]; then
      echo "Too many retries"
      exit 1
  fi

  echo "Converting file $INPUT try $RETRIES"

  TEMP_DIR=$(mktemp -d 2>/dev/null || mktemp -d -t 'mytmpdir')

  chmod 777 "$TEMP_DIR"

  cp "$INPUT" "$TEMP_DIR/input.hmi"
  cp -r "$HMI_DIR/dev/ui/fonts/cjk" "$TEMP_DIR/fonts"

  # shellcheck disable=SC2086
  docker run --rm -v "$TEMP_DIR:/app/input" sztupy/nextion-scripts $COMMAND || true

  if [ -f "$TEMP_DIR/output.tft" ]; then
      cp "$TEMP_DIR/output.tft" "$OUTPUT_TFT"
      cp "$TEMP_DIR/output.hmi" "$OUTPUT"
  else
      call_with_retries "$COMMAND" "$INPUT" "$OUTPUT" $((RETRIES + 1))
  fi

  rm -rf "$TEMP_DIR"
}

call_with_retries "./run-script.sh UsLandscapeConvert.ahk" "$HMI_DIR/nspanel_eu.HMI" "$HMI_DIR/nspanel_us_land.HMI"

call_with_retries "./update_fonts.sh" "$HMI_DIR/nspanel_eu.HMI" "$HMI_DIR/nspanel_CJK_eu.HMI"
call_with_retries "./update_fonts.sh" "$HMI_DIR/nspanel_us.HMI" "$HMI_DIR/nspanel_CJK_us.HMI"
call_with_retries "./update_fonts.sh" "$HMI_DIR/nspanel_us_land.HMI" "$HMI_DIR/nspanel_CJK_us_land.HMI"
