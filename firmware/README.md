# Firmware

Handling of signed firmware OTA images.

## OTA

The OTA firmware images in this repository are stored using `git lfs` and are not downloaded by default due to their size.

The `.ota` files can be downloaded with this command:

```sh
git lfs pull --exclude="" --include="prod/1.6.0.3331.ota"
```

Or if you prefer, you can download all `.ota` files (~11 gigabytes) with the following:

```sh
git lfs pull --exclude="" --include="*.ota"
```

## Onboard Signature Verification

Vector verifies the manifest file signature by shelling to `openssl` and validating the return code, like this:

```sh
openssl dgst \
    -sha256 \
    -verify /anki/etc/ota.pub \
    -signature /run/update-engine/manifest.sha256 \
    /run/update-engine/manifest.ini
```

## Offboard OTA Image Decryption and Extraction

OTA images are `tar.gz` files with an `.ota` extension containing four files within:

```sh
└── latest.ota
    ├── apq8009-robot-boot.img.gz (encrypted)
    ├── apq8009-robot-sysfs.img.gz (encrypted)
    ├── manifest.ini
    └── manifest.sha256
```

The `boot.img` and `sysfs.img` files are compressed and encrypted with `AES256-CTR` cipher.

You can use the [extract.py](tools/extract.py) script to decrypt and extract an OTA image as such:

```sh
python firmware/tools/extract.py firmware/dev/1.0.1.1768.ota /tmp/extracted_firmware detail/keys/ota.pas
```

The resulting sysfs image is an ext4 filesystem and can be mounted.

MacOS example:

```sh
sudo ext4fuse /tmp/test/apq8009-robot-sysfs.img /tmp/mount -o allow_other,defer_permissions
```

The resulting boot image is an android bootimage.

TODO: Add a tooling recommendation for bootimage files

## ResetOS

The `ResetOS` (version `0.9.0`) (booted by holding the 'backpack button') is configured differently and will likely be
important, and should be closely investigated.

### Known disparities

* The `UPDATE_ENGINE_ALLOW_DOWNGRADE` environment variable is set as `True` which allows for firmware downgrading.

## Downgrading Vector

TODO: Downgrading Vector will likely be crucial for some exploit, we should put some instructions here.
