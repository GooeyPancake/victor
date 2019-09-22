# Source

This is the source code obtained from Anki vector development firmware image, `1.6.0.3331.ota`.

If there comes a point where we officially "open source" Vector and have the resources to start modifying source code,
this can serve as a starting point.

For now, this allows us to defer to the code for discussions.

## Bin

Contains the runtime binaries. The scripts are in

**Note:** The "advanced" vector code in the form of C(++?) cross-compiled ELF binaries/libraries were removed for
security reasons but are still present in the original OTA images.

## Assets

Contains the numerous amount of asset files such as animations and sprites.

<!-- markdownlint-disable no-emphasis-as-heading -->
| WARNING: There is something is weird about some of the sprite sequence files, be super careful with this directory.
| --- |
**The [spriteSequences](assets/cozmo_resources/assets/sprites/spriteSequences) directory contains a few symlinks pointing to different system files present on vector, but are absolute and may properly resolve. That means you may mess up your system if you try to write to these files (especially as sudo).**

The symlinks can be removed at a later date if we find out the reason for their existence as I have never seen
something like this before. It may be a red-herring and corruption in the extraction process.

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
