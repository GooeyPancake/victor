# Decompiled files

The files with ".orig" is what Ghidra spit out.
The other ones are what I have annotated, fixed obtuse string references, get the variable and
procedure names to match likely original source.

## Files
ABOOT.c/ABOOT.orig.c is decompiled from the ABOOT partition; it is the Android bootloader

SBL1.c/SBL1.orig.c is decompiled from the SBL1 partition; it is the secondary bootloader

RPM.orig.c is decompiled from the RPM partition; it is the resource/power manager?

## Resources
The closest thing I found whose bootloader code matches the code above is in:
https://git.szzt.com/yixing/ticai_src/blob/a616182007156a89e11cfcc9cba6fe8c6951d61c/LA.UM.5.6/LINUX/android/bootable/bootloader/lk/


## The differences between the pairs of files
I went thru and:
1. filled in missing strings
2. Identified likely source file for procedures
3. Identified (and replaced) procedure names
4. Identified (and replaced) parameter names, local variables, the occasional #define

I kept the code that we have in the same order / format but make it understandable.
This lets me compare and identify the addresses of the procedures, labels, variables, so that I
can maybe test it using qemu

It's tempting to divide up the (large) code into modules so that multiple people can work on it
simultaneously.  (ie the division would follow the about/little kernel code tree for understanding.)
For now that made it harder to do all the cleanup above and again the idea of testing the
settings with qemu,

## What I hoped to find
### Reading DEVINFO partition
The aboot code in the other repos looks like it normally reads the DEVINFO partition for a structure.  It checks the header
of the structure for a magic string (“ANDROID-BOOT!”) — but does no other checks(!) — and then uses the structures values
internally to know if the device is unlocked, or has the tamper flag set, or verity-mode enabled or disabled.   With other
Qualcomm devices all one has to do is write a couple of those bytes to non-zero, ala:
https://alephsecurity.com/2018/01/22/qualcomm-edl-2/

(That structure is standard so the same format would work on all ARM 32/64 processors)

With Vector the DEVINFO partition is all zeros, and there is /no code to read it/.  There is nothing that I can find in aboot
that reads a partition and will put it into “fastboot" mode.  Maybe someone can find it.

### GPIO bypass
In most aboot a couple of keys (like volume up and down) are checked to see they are both pressed during boot.  If so,
“boot_into_fastboot” is set, causing the code to skip the signature checks and do a “fastboot”.
Vector’s aboot is different.  I didn’t find what looked like a GPIO check.  Maybe someone can find it.

### Reboot reason code
“boot_into_fastboot” is set, if the check_hard_reboot_mode() returns a 2.  I'm not sure how to get the hardware, primary or
secondary bootloader to set this to 2.

The fastboot code is still in aboot.  Given the deliberateness of Anki customizations -- adding an unbrick mode, removing the
known unlock/security bypass methods -- this could be intentional, and there is still a method to enable it.
Given the incomplete optimizations of the compiled code, this could be unintentional.

## Snipes & Gripes
Maybe I'm seeing things, but it looks aboot leaks resources when there are errors.

The lack of CRC or signatures on structures imported from nonvolatile storage is just poor skillscraft.

The compiler/linker leaves a lot of dead code around.

Ghidra occassionally screws up the decompile, e.g. getting the paramete order wrong, or strange dead code

And the SBL uses "DENTAL PLAN!" as a magic cookie.


