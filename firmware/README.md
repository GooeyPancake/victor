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
└── 1.6.0.3331.ota
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

initramfs -- the boot ramdisk -- is a CPIO archive and can be extracted:

```gunzip <initramfs|cpio -vid
```

The resulting sysfs image is an gzipped ext4 filesystem and can be mounted.

MacOS example:

```sh
sudo ext4fuse /tmp/test/apq8009-robot-sysfs.img /tmp/mount -o allow_other,defer_permissions
```

Or the ext4 filesystem can be extracted to the local file system using [extfstools](https://github.com/nlitsme/extfstools)

```ext2rd  /tmp/test/apq8009-robot-sysfs.img  ./:extractionPath
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

## OTA File Discovery

<!-- markdownlint-disable no-emphasis-as-heading -->
| NOTE: There is something weird about the extracted OTA file.
| --- |
**The [spriteSequences](assets/cozmo_resources/assets/sprites/spriteSequences) directory from an OTA file contains a few
symlinks pointing to different system files present on vector, but are absolute and may properly resolve. That means you
may mess up your system if you try to write to these files (especially as sudo).**

<!-- markdownlint-disable no-inline-html -->
<details>
  <summary>Click here for the list of all abosolute symlinks</summary>
  <p>

```sh
spriteSequences/face_timercancel_getin_01 -> lvm
spriteSequences/face_timerleft_getin_01 -> lvm
spriteSequences/face_timerleft_getout_01 -> lvm
spriteSequences/face_snow01/face_snow01_00209.png -> /sbin/modprobe.kmod
spriteSequences/face_snow01/face_snow01_00210.png -> ../bin/kmod
spriteSequences/face_snow01/face_snow01_00212.png -> /usr/lib/busybox/sbin/nameif
spriteSequences/face_snow01/face_snow01_00213.png -> /usr/lib/busybox/sbin/nbd-client
spriteSequences/face_snow01/face_snow01_00214.png -> /usr/lib/busybox/sbin/ntpd
spriteSequences/face_snow01/face_snow01_00215.png -> /usr/lib/busybox/sbin/pivot_root
spriteSequences/face_snow01/face_snow01_00216.png -> /usr/lib/busybox/sbin/popmaildir
spriteSequences/face_snow01/face_snow01_00218.png -> /bin/systemctl
spriteSequences/face_snow01/face_snow01_00219.png -> /usr/lib/busybox/sbin/powertop
spriteSequences/face_snow01/face_snow01_00220.png -> /usr/lib/busybox/sbin/raidautorun
spriteSequences/face_snow01/face_snow01_00221.png -> /usr/lib/busybox/sbin/rdate
spriteSequences/face_snow01/face_snow01_00222.png -> /usr/lib/busybox/sbin/rdev
spriteSequences/face_snow01/face_snow01_00223.png -> /usr/lib/busybox/sbin/readahead
spriteSequences/face_snow01/face_snow01_00224.png -> /usr/lib/busybox/sbin/readprofile
spriteSequences/face_snow01/face_snow01_00225.png -> /bin/systemctl
spriteSequences/face_snow01/face_snow01_00228.png -> /usr/lib/busybox/sbin/remove-shell
spriteSequences/face_snow01/face_snow01_00229.png -> /usr/lib/busybox/sbin/rfkill
spriteSequences/face_snow01/face_snow01_00230.png -> /sbin/rmmod.kmod
spriteSequences/face_snow01/face_snow01_00231.png -> ../bin/kmod
spriteSequences/face_snow01/face_snow01_00233.png -> /usr/lib/busybox/sbin/route
spriteSequences/face_snow01/face_snow01_00236.png -> /usr/lib/busybox/sbin/rtcwake
spriteSequences/face_snow01/face_snow01_00239.png -> /bin/systemctl
spriteSequences/face_snow01/face_snow01_00240.png -> /usr/lib/busybox/sbin/sendmail
spriteSequences/face_snow01/face_snow01_00241.png -> /usr/lib/busybox/sbin/setconsole
spriteSequences/face_snow01/face_snow01_00242.png -> /usr/lib/busybox/sbin/setfont
spriteSequences/face_snow01/face_snow01_00243.png -> /usr/lib/busybox/sbin/setlogcons
spriteSequences/face_snow01/face_snow01_00244.png -> /bin/systemctl
spriteSequences/face_snow01/face_snow01_00245.png -> /usr/lib/busybox/sbin/slattach
spriteSequences/face_snow01/face_snow01_00246.png -> /usr/lib/busybox/sbin/start-stop-daemon
spriteSequences/face_snow01/face_snow01_00247.png -> /sbin/sulogin.util-linux
spriteSequences/face_snow01/face_snow01_00249.png -> /usr/lib/busybox/sbin/svlogd
spriteSequences/face_snow01/face_snow01_00250.png -> /usr/lib/busybox/sbin/swapoff
spriteSequences/face_snow01/face_snow01_00251.png -> /usr/lib/busybox/sbin/swapon
spriteSequences/face_snow01/face_snow01_00252.png -> /usr/lib/busybox/sbin/switch_root
spriteSequences/face_snow01/face_snow01_00253.png -> /usr/lib/busybox/sbin/sysctl
spriteSequences/face_snow01/face_snow01_00254.png -> /usr/lib/busybox/sbin/syslogd
spriteSequences/face_snow01/face_snow01_00256.png -> /usr/lib/busybox/sbin/telnetd
spriteSequences/face_snow01/face_snow01_00257.png -> /usr/lib/busybox/sbin/tftpd
spriteSequences/face_snow01/face_snow01_00258.png -> /usr/lib/busybox/sbin/tunctl
spriteSequences/face_snow01/face_snow01_00259.png -> /lib/systemd/systemd-udevd
spriteSequences/face_snow01/face_snow01_00260.png -> /usr/lib/busybox/sbin/udhcpc
spriteSequences/face_snow01/face_snow01_00261.png -> /usr/lib/busybox/sbin/udhcpd
spriteSequences/face_snow01/face_snow01_00305.png -> /usr/lib/busybox/sbin/vconfig
spriteSequences/face_snow01/face_snow01_00307.png -> /usr/lib/busybox/sbin/watchdog
spriteSequences/face_snow01/face_snow01_00309.png -> /usr/lib/busybox/sbin/zcip
spriteSequences/face_snow01/face_snow01_00310.png -> /mnt/sdcard
spriteSequences/face_snow01/face_snow01_00336.png -> /var/tmp
spriteSequences/face_snow01/face_snow01_00356.png -> aplay
spriteSequences/face_snow01/face_snow01_00362.png -> /usr/bin/gawk
spriteSequences/face_snow01/face_snow01_00368.png -> /usr/bin/bzip2
spriteSequences/face_snow01/face_snow01_00370.png -> /usr/bin/bzip2
spriteSequences/face_snow01/face_snow01_00371.png -> /usr/bin/bzdiff
spriteSequences/face_snow01/face_snow01_00373.png -> /usr/bin/bzgrep
spriteSequences/face_snow01/face_snow01_00374.png -> /usr/bin/bzgrep
spriteSequences/face_snow01/face_snow01_00378.png -> /usr/bin/bzmore
spriteSequences/face_snow01/face_snow01_00382.png -> /usr/bin/chvt.kbd
spriteSequences/face_snow01/face_snow01_00399.png -> /usr/bin/deallocvt.kbd
spriteSequences/face_snow01/face_snow01_00411.png -> /bin/env
```

</p></details>
