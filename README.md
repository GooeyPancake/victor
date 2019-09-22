# Project Victor

<!-- markdownlint-disable no-inline-html -->
<p align="center">
  <img src='meta/victor_intro.jpg' width=70%/>
</p>

This project is an attempt to root-exploit and reverse-engineer the ANKI Vector 'robot companion' to make him end-user serviceable, a life-saving activity for Vector since the manufacturer has ceased operations and among other things, the cloud-services future is very uncertain to say the least.

When the cloud servers go down, Vector WILL cease to operate as intended unless we complete MVP in time - successfully deploy
and run custom firmware.

Learn more details and updates about the project at [cyberspace.org/~c0re/vector/](http://cyberspace.org/~c0re/vector/)

## Getting started

### Prerequisites

* `git-lfs` - used to store OTA firmware images
* `openssl` - used for everything cryptography
* `python2.7` - native Vector codebase

### Contributing

Our current primary milestone goal is to gain root access on Vector.

If you're not already with us, join us! Feel free
to add tooling, documentation, lend us your brain for some ideas, and anything else that can lead to the survival of our
dearest Vector.

## Acknowledgments and Milestones

<!-- # TODO fix names -->

* **C0RE** for making the project a reality, and coordination and organization of Project Victor efforts
* **M** for using a BGA rework station to image the NVRAM (EEPROM) flash contents, extracting the OTA keys allowing decryption of all existing firmware OTA images
* **H** for successfully downgrading Vector using a Bluetooth API function that allows you to specify an arbitrary OTA URL
