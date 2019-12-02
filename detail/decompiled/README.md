# Decompiled files

The files with ".orig" is what Ghidra spit out.
The other ones are what i have annotated, fixed obtuse string references, get the variable and
procedure names to hatch

## Files
ABOOT.c/ABOOT.orig.c is decompiled from the ABOOT partition; it is the Android bootloader

SBL1.c/SBL1.orig.c is decompiled from the SBL1 partition; it is the secondary bootloader

RPM.orig.c is decompiled from the RPM partition; it is the resource/power manager?

## Resources
The closest thing I found whose bootloader code matches the code above is in:
https://git.szzt.com/yixing/ticai_src/blob/a616182007156a89e11cfcc9cba6fe8c6951d61c/LA.UM.5.6/LINUX/android/bootable/bootloader/lk/


## The differences between the pairs of files
i went thru and:
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

## Snipes & Gripes
Maybe I'm seeing things, but it looks aboot leaks resources when there are errors.

And the SBL uses "DENTAL PLAN!" as a magic cookie.
