#!/usr/bin/env bash
#
# Usage: ./generate_images <background_file_to_use> <eu*|us*>
#
# Default values are: ./generate_images pics/0.png eu

set -e

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
IMAGES_DIR=$SCRIPT_DIR/../ui

BACKGROUND=${1-"$IMAGES_DIR/pics/0.png"}
VARIANT=${2-"eu"}

magick_command() {
  if command -v magick >/dev/null 2>&1; then
    pushd "$IMAGES_DIR"
      magick "$@"
    popd
  elif command -v convert >/dev/null 2>&1; then
    pushd "$IMAGES_DIR"
      convert "$@"
    popd
  else
    docker run --rm -v "${IMAGES_DIR}:/imgs" dpokidov/imagemagick "$@"
  fi
}

# Cleanup
rm -f "$IMAGES_DIR"/"$VARIANT"/*.png "$IMAGES_DIR"/"$VARIANT"/*.jpg || true
mkdir -p "$IMAGES_DIR/$VARIANT"

if [[ $VARIANT = eu* ]]; then
  echo "Generating Landscape images"
else
  echo "Generating Portrait images"
fi

# 0: Background
cp "$BACKGROUND" "$IMAGES_DIR/$VARIANT/0.png"

# 1-15 Weather icons
for i in {1..15}; do
  if [[ $VARIANT = eu* ]]; then
    magick_command "$VARIANT/0.png" "pics/$i.png" -geometry +20+45 -composite -background black -flatten -crop 100x100+20+45 +repage "$VARIANT/$i.png"
  else
    magick_command "$VARIANT/0.png" "pics/$i.png" -geometry +20+154 -composite -background black -flatten -crop 100x100+20+154 +repage "$VARIANT/$i.png"
  fi
done

# 19,20 Cover controls
# 34,35 Fan settings

for i in 19 20 34 35; do
  if [[ $VARIANT = eu* ]]; then
    magick_command "$VARIANT/0.png" "pics/$i.png" -geometry +183+67 -composite -background black -flatten -crop 83x233+183+67 +repage "$VARIANT/$i.png"
  else
    magick_command "$VARIANT/0.png" "pics/$i.png" -geometry +119+143 -composite -background black -flatten -crop 83x233+119+143 +repage "$VARIANT/$i.png"
  fi
done

# 30,31 Settings page
# 37 Climate controls
# 41,42 Home Alt / Buttons background
for i in 30 31 32 41 42; do
  if [[ $VARIANT = eu* ]]; then
    magick_command "$VARIANT/0.png" "pics/$i.png" -geometry +0+0 -composite -background black -flatten -crop 480x320 +repage "$VARIANT/$i.png"
  else
    magick_command "$VARIANT/0.png" "pics/$i-portrait.png" -geometry +0+0 -composite -background black -flatten -crop 320x480 +repage "$VARIANT/$i.png"
  fi
done

# Keep these with black background, either as they are on a black screen or they don't have transparency (e.g. sliders)

# 16: Slider on Settings page
# 17: Colour page
# 18: Slider on Cover, Fan & Colour pages
# 21-29: Colour page
# 33: Slider on Climate page
# 39,40: Alarm
# 36,37,38: Unused, can be used on Alarm as alternative colours

for i in {16..18} {21..29} 33 {36..40}; do
  cp "${IMAGES_DIR}/pics/$i.png" "${IMAGES_DIR}/$VARIANT/$i.png"
done
