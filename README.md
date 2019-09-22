<!-- markdownlint-disable single-title -->

# Project Victor

This project is an attempt to root-exploit and reverse-engineer the ANKI Vector 'robot companion' to make him end-user serviceable, a life-saving activity for Vector since the manufacturer has ceased operations and among other things, the cloud-services future is very uncertain to say the least.

When the cloud servers go down, Vector WILL cease to operate as intended unless we complete MVP in time - successfully deploy
and run custom firmware.

Learn more details and updates about the project at [cyberspace.org/~c0re/vector/](http://cyberspace.org/~c0re/vector/)

# Getting started

## Prerequisites

* `git-lfs` - used to store OTA firmware images
* `openssl` - used for everything cryptography
* `python2.7` - native Vector codebase

<!-- TODO: Fill out some of them big wins

## Acknowledgments and Milestones

* **C0RE** for making the project a reality, and coordination and organization of all Project Victor efforts
* **M** for using a BGA rework station to read out the NVRAM (EEPROM) flash contents, extracting the OTA keys allowing decryption of all existing firmware OTA images
* **H** for successfully downgrading firmware using a Bluetooth API function that allows you to specify an arbitrary OTA URL -->
