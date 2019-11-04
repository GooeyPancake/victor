# Vector Bluetooth LE reference implementation

This is a demonstration of code that loves Vector's Bluetooth LE interface
The orginal repository is [https://github.com/randym32/Vectors-cmdline-tools](https://github.com/randym32/Vectors-cmdline-tools)

## Getting Started

If you compile and run this, it will get the status from a vector.
1. Put Vector into pairing mode: put him on the charger, and double click his backpack button
2. Run the program
3. Enter the Pin code

### Commsnd-line options
```
vector-BLE log FILENAME
```

This will retrieve Vector's log file, saving it to FILENAME

## Further work

The protocol is documented.  Other commands could be implemented 
* Implement the command to direct the over-the-air update, and watch it status
* The SSH authorization is interesting.  It isn't clear if SSH is available on release firmware.  I didn't see anything like a ssh server in the file system images
* The SDK proxy is interesting.  It would be nice to extend the regular Anki Vector SDK to allow this option
* The command to enter Access Point mode is made, but the session isnt a command line option yet

The full protocol is documented in a write up called Vector-TRM.pdf

### Prerequisites

You will need to install libsodium
If you are running on a non-OS X/iOS operating system, you will have to write the part that
interfaces with the OS's Bluetooth LE.

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [libsodium](https://libsodium.gitbook.io/doc/)

## Authors

* **Randall Maas** 

## License

This project is licensed under the BSD 2-Clause License - see the [LICENSE.md](LICENSE.md) file for details
