//
//  Vector-BLE.m
//  Anki-1
//
//  Created by Randall Maas on 10/1/19.
//  Copyright © 2019 Randall Maas. All rights reserved.
//
#import <CoreBluetooth/CoreBluetooth.h>
#import "Vector-BLE.h"

VectorProxy* vectorProxy;
// The characteristic to write to
static CBCharacteristic* vectorWrite;

@interface BLE:NSObject<CBCentralManagerDelegate>
{
    // this is needed ; otherwise the peripheral disappears and the connection
    // is lost
    id thingy;
}
@end
@implementation BLE
#pragma mark - CBCentralManager delegate methods
/** Invoked whenever the central manager's state is updated.
 */
- (void) centralManagerDidUpdateState:(CBCentralManager*) central
{
    [central scanForPeripheralsWithServices:@[[CBUUID UUIDWithString:@"FEE3"]]
                                    options:nil];
}


/** This is invoked when the central discovers a peripheral while scanning.
 */
- (void) centralManager:(CBCentralManager *) central
  didDiscoverPeripheral:(CBPeripheral     *) aPeripheral
      advertisementData:(NSDictionary     *) advertisementData
                   RSSI:(NSNumber         *) RSSI
{
    if (thingy) return;
    thingy = aPeripheral;
    // Automatically connect with the peripheral
    [central connectPeripheral: aPeripheral
                       options: nil];
}


/** Invoked whenever a connection is succesfully created with the peripheral.
    Discover available services on the peripheral
 */
- (void) centralManager:(CBCentralManager *) central
   didConnectPeripheral:(CBPeripheral     *) peripheral
{
    vectorProxy = [[VectorProxy alloc] initWithPeripheral:peripheral];
}


/** Invoked whenever an existing connection with the peripheral is torn down.
    Reset local variables
 */
- (void) centralManager:(CBCentralManager*) central
didDisconnectPeripheral:(CBPeripheral*    ) aPeripheral
                  error:(NSError*         ) Error
{
}


/** Invoked whenever the central manager fails to create a connection with the peripheral.
 */
- (void)    centralManager:(CBCentralManager *)central
didFailToConnectPeripheral:(CBPeripheral *)aPeripheral
                     error:(NSError*) error
{
    NSLog(@"Fail to connect to peripheral: %@ with error = %@", aPeripheral, [error localizedDescription]);
    aPeripheral . delegate = nil;
}
@end

@implementation VectorProxy


/** Initialize the structure with the bluetooth device
    @param BPeripheral The Bluetooth peripheral we are to use
    @returns nil on error, othwerise the wrapper
 */
- (id)initWithPeripheral:(CBPeripheral*) BPeripheral
{
    if (!(self=[self init]))
        return self;
    _peripheral = BPeripheral;
    self.peripheral.delegate = self;
    // Get the characteristics for the peripheral service
    // This will call peripheral:didDiscoverCharacteristicsForService:error:
   [self.peripheral discoverServices: @[[CBUUID UUIDWithString:@"FEE3"]]];
    return self;
}


#pragma mark - CBPeripheral delegate methods
/** Invoked upon completion of a -[discoverServices:] request.
    Discover available characteristics on interested services
 */
- (void) peripheral:(CBPeripheral *) aPeripheral
didDiscoverServices:(NSError      *) error
{
    for (CBService* service in aPeripheral.services)
    {
        // Get the characteristics for the peripheral service
        // This will call peripheral:didDiscoverCharacteristicsForService:error:
        [aPeripheral discoverCharacteristics: @[[CBUUID UUIDWithString:@"7D2A4BDA-D29B-4152-B725-2491478C5CD7"],
                                                [CBUUID UUIDWithString:@"30619F2D-0F54-41BD-A65A-7588D8C85B45"]]
                                  forService: service];
    }
}

/*
 Invoked upon completion of a -[discoverCharacteristics:forService:] request.
 Perform appropriate operations on interested characteristics
 */
- (void)                  peripheral:(CBPeripheral *)aPeripheral
didDiscoverCharacteristicsForService:(CBService    *)service
                               error:(NSError       *)error
{
    CBCharacteristic* recv=nil;
    for (CBCharacteristic *aChar in service.characteristics)
    {
        if ([aChar.UUID isEqual:[CBUUID UUIDWithString:@"7D2A4BDA-D29B-4152-B725-2491478C5CD7"]])
        {
            vectorWrite = aChar;
        }
        else if ([aChar.UUID isEqual:[CBUUID UUIDWithString:@"30619F2D-0F54-41BD-A65A-7588D8C85B45"]])
        {
            recv = aChar;
        }
    }
    [self.peripheral setNotifyValue:YES
                  forCharacteristic:recv];
}


#pragma mark -
#pragma mark Characteristics interaction

- (void)            peripheral:(CBPeripheral     *) aPeripheral
didWriteValueForCharacteristic:(CBCharacteristic *) characteristic
                         error:(NSError          *) error
{
    if (error)
    {
        NSLog(@"%s: %@: error %@", __FUNCTION__, characteristic.UUID, error);
        return;
    }
}



/** This is invoked upon completion of a -[readValueForCharacteristic:] request or
    on the reception of a notification/indication.
 */
- (void)             peripheral:(CBPeripheral     *) aPeripheral
didUpdateValueForCharacteristic:(CBCharacteristic *) characteristic
                          error:(NSError          *) error
{
    void bleRecv(void const* bytes, size_t length);
    if (error)
    {
        NSLog(@"%s: %@: error %@", __FUNCTION__, characteristic.UUID, error);
        return;
    }
    bleRecv(characteristic.value.bytes,characteristic.value.length);
}
@end


/** Writes a given value to the characteristics
    @param value  The values to write
 */

/** This is called when the Bluetoth LE stack receives a charatristic
    @param bytes  the received bytes
    @param length the number of bytes received
 */
void bleSend(void const* bytes, size_t length)
{
    NSData* data = [NSData dataWithBytes: bytes
                                  length:length];
    [vectorProxy.peripheral writeValue: data
                     forCharacteristic: vectorWrite
                                  type: CBCharacteristicWriteWithResponse];
}


/** This is called to start scanning for and conect to the first Vector it sees
 */
void bleScan()
{
    static CBCentralManager* centralManager;
    static BLE* a;
    a = [[BLE alloc] init];
    centralManager = [[CBCentralManager alloc] initWithDelegate: a
                                                          queue:nil];
    @autoreleasepool
    {
        [[NSRunLoop currentRunLoop] run];
    }
}

