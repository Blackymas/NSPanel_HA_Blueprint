# Release Instructions

This document provides step-by-step instructions for releasing a new version of the project. Follow these guidelines carefully to ensure a smooth and consistent release process.

## Prerequisites

1. Ensure you have the latest version of the `dev` branch checked out.
2. Ensure all tests are passing locally.
3. Ensure you have the appropriate permissions to push to the main branch and create releases.

## Step-by-Step Release Process

### 1. Update Version Number

1. **Update the version number**:
   - Modify the version number in the following files:
     - **ESPHome**:
       - `nspanel_esphome_version.yaml`: Update the `substitutions` section with the new version number.
       - `nspanel_esphome_core.yaml`: Update the `external_components` section with the new version number.
     - **Blueprint**:
       - `nspanel_blueprint.yaml`: Update the version number in both the blueprint description and the `variables` area.
     - **TFT**:
       - For all `.hmi` files (e.g., `nspanel_xxx.hmi`), update the `version` variable on the boot page. You can use `scripts/update_nextion_version.sh <new_version>` for that.

2. **Generate new TFT files**:
   - Compile each modified `.hmi` file to generate the updated `.tft` files. Use the Nextion Editor or any applicable tool for this process.
   - Run `scripts/generate_nextion_txt.sh` to generate the text files showing what's updated from the HMI.

3. **Update the Release Notes**:
   - Open `ReleaseNotes.md` in the root of the repository.
   - Add a new section for the current release at the top, summarizing all changes, new features, bug fixes, and updates.
   - Include a link to the previous release notes (tags) for easy reference.

4. **Create a new branch with the version name**:
   - After updating the version in all required files, create a new branch from the `dev` branch with the new version number prefixed with `v`:
     ```bash
     git checkout dev
     git pull origin dev
     git checkout -b vX.X.X
     git push origin vX.X.X
     ```
   - This branch ensures the `external_components` are validated correctly during testing.

5. **Merge changes back to `dev`**:
   - After making the changes, merge them back into the `dev` branch to trigger the CI/CD actions and validate the build process:
     ```bash
     git checkout dev
     git merge vX.X.X
     git push origin dev
     ```

### 2. Pre-Build Firmware Validation

1. **Verify pre-build firmware**:
   - Check the CI/CD actions on the `dev` branch to ensure the `pre-build` firmware file is successfully created.
   - If the `pre-build` firmware is missing or failed, investigate and resolve the issues before proceeding.

### 3. Merge Workflow (`dev` -> `beta` -> `main`)

1. **Merge `dev` into `beta`**:
   - Ensure all changes from the `dev` branch are correctly merged into `beta`.
   - Validate that all tests pass on the `beta` branch.

2. **Merge `beta` into `main`**:
   - Once `beta` is validated, merge `beta` into `main`.
   - Ensure all changes are properly reflected and ready for release.

### 4. Prepare Release

1. **Create a GitHub Release and Tag**:
   - Use GitHub’s UI to draft a new release:
     - Go to the [Releases](https://github.com/Blackymas/NSPanel_HA_Blueprint/releases) page.
     - Click on "Draft a new release".
     - Select "Choose a tag" and create a new tag with the version number (e.g., `vX.X.X`).
     - Set the release title to the version number (e.g., `vX.X.X`).
     - Copy the relevant section of the `ReleaseNotes.md` into the release notes.
     - Flag the option to automatically create the tag when releasing.

2. **Delete temporary branches (`beta` and version branches)**:
   - After tagging, you can delete the `beta` and version branches to keep the repository clean:
     ```bash
     git push origin --delete beta
     git push origin --delete vX.X.X
     ```
   - If `dev` was also deleted, recreate it from the latest `main`:
     ```bash
     git checkout main
     git checkout -b dev
     git push origin dev
     ```

### 5. Share Release Notes

1. **Post the release notes in discussions**:
   - Post the release notes in the project’s discussions area on GitHub to notify users of the latest changes.

2. **Announce on Home Assistant Community**:
   - Share the release notes in the Home Assistant Community forum discussion thread related to the project to inform users of the new release.

### 6. Post-Release Tasks

1. **Update the documentation**:
   - Ensure that all relevant documentation is updated to reflect the new version.
   - If necessary, update any online documentation or API references.

2. **Announce the release**:
   - Post the release announcement on your project's communication channels (e.g., Slack, Discord, internal mailing lists).
   - Consider posting on social media or community forums if applicable.

3. **Monitor for issues**:
   - Keep an eye on the issue tracker for any bugs or issues reported by users after the release.
