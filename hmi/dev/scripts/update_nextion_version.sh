#!/usr/bin/env bash
# Usage: ./update_nextion_version.sh <new_version>

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
HMI_DIR=$SCRIPT_DIR/../..

VERSION=$1

update_version () {
    INPUT=$1
    RETRIES=${2:-0}
    OUTPUT=${INPUT%.*}.tft

    if [ "$RETRIES" -gt 3 ]; then
        echo "Too many retries"
        exit 1
    fi

    echo "Converting file $INPUT try $RETRIES"

    TEMP_DIR=$(mktemp -d 2>/dev/null || mktemp -d -t 'mytmpdir')

    chmod 777 "$TEMP_DIR"

    cp "$INPUT" "$TEMP_DIR/input.hmi"

    docker run --rm -v "$TEMP_DIR:/app/input" sztupy/nextion-scripts ./update_version.sh "$VERSION" || true

    if [ -f "$TEMP_DIR/output.tft" ]; then
        cp "$TEMP_DIR/output.tft" "$OUTPUT"
        cp "$TEMP_DIR/output.hmi" "$INPUT"
    else
        update_version "$INPUT" $((RETRIES + 1))
    fi

    rm -rf "$TEMP_DIR"
}

update_version "$HMI_DIR/nspanel_blank.HMI"
update_version "$HMI_DIR/nspanel_CJK_eu.HMI"
update_version "$HMI_DIR/nspanel_CJK_us_land.HMI"
update_version "$HMI_DIR/nspanel_CJK_us.HMI"
update_version "$HMI_DIR/nspanel_eu.HMI"
update_version "$HMI_DIR/nspanel_us.HMI"
update_version "$HMI_DIR/nspanel_us_land.HMI"