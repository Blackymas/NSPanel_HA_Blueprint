# Creating opaque images

The nextion panel doesn't support transparency in images, so images uploaded need to be converted to a non-transparent PNG first.

To do that there is a tool called `generate_images.sh` which will convert transparent images in the `pics` folder with the specified background into opaque images, that can then be imported to Nextion Editor.

To generate landscape images (EU, US-landcape):

```sh
./generate_images.sh pics/0.png eu
```

The generated images will end up in the `eu` folder.

For portrait version (US):

```sh
./generate_images.sh pics/0-portrait.png us
```

The generated images will end up in the `us` folder.

You can also specify any other background with a resolution of `480x320` (landscape) or `320x480` (portrait) as well.

You can also generate variants:

```sh
./generate_images pics/0-white.png eu-white
```

```sh
./generate_images pics/0-portrait-white.png us-white
```