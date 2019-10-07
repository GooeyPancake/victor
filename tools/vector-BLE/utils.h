//
//  utils.h
//  Anki-1
//
//  Created by Randall Maas on 10/3/19.
//  Copyright © 2019 Randall Maas. All rights reserved.
//

#ifndef utils_h
#define utils_h

extern "C"
{
    void bleScan();
    void bleRecv(uint8_t const* bytes, size_t length);
    void bleSend(void const* bytes, size_t length);
};

/// This is used to map a 16-bit little endian to the native format
#define LEU16_decode(p) (((p)[0] & 0xFFuL)| (((p)[1] << 8) & 0xFF00uL))
#define LEU32_decode(p) (LEU16_decode(p)|((uint32_t)LEU16_decode(p+2)<<16))

/// The version of the protocol and message formats
extern int protoVersion;


/** This is called to interpret message
    @param tag    the message code
    @param size   the number of bytes in the message
 */
extern void sendMsg(uint8_t tag, size_t size);

// This is called when the lower layers are ready
extern void CLAD_ready(void);

/** This is called to interpret message
    @param type    the type of message received
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 */
extern void CLAD_interpret(uint8_t type, uint8_t const* msg, size_t size, uint8_t version);


/// This is used to map a 16-bit little endian to the native format
#define LEU16_decode(p) (((p)[0] & 0xFFuL)| (((p)[1] << 8) & 0xFF00uL))

#endif /* utils_h */
