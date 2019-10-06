//
//  Vector-BLE.h
//  Anki-1
//
//  Created by Randall Maas on 10/1/19.
//  Copyright © 2019 Randall Maas All rights reserved.
//


#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface VectorProxy : NSObject<CBPeripheralDelegate>
{
    /// The bluetooth peripheral that we are wrapping
    CBPeripheral* volatile _peripheral;
}
/// The name of the device
@property(readonly) NSString *    deviceName;


/// The bluetooth peripheral that we are wrapping
@property(atomic)   CBPeripheral* peripheral;


/** Initialize the structure with the bluetooth device
    @param peripheral The Bluetooth peripheral we are to use
    @returns nil on error, othwerise the wrapper
 */
- (id)initWithPeripheral:(CBPeripheral*) peripheral;

@end

