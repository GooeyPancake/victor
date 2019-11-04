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

/// The version of the protocol and message formats
extern int protoVersion;

/// A pointer into the payload area of the message
extern uint8_t* out_msg;

/// This is used to map a 16-bit little endian to the native format
#define LEU16_decode(p) (((p)[0] & 0xFFuL)| (((p)[1] << 8) & 0xFF00uL))

/// This is used to map a 32-bit little endian to the native format
#define LEU32_decode(p) (LEU16_decode(p)|((uint32_t)LEU16_decode(p+2)<<16))


/** This is used to encode a 16-bit number into the little endian order
    @param buf  The buffer to populate
    @param v    The 16-bit value to place into the buffer
 
    Note: this is done by the explicit (tedious) method of populating the
    buffer instead of casting a pointer (e.g. *(uint16_t)*buf=v;)  That approach
    bus faults on some architectures if the buffer isn't aligned just right.
 */
inline void LEU16_encode(void* buf, uint16_t v)
{
    uint8_t* _buf = (uint8_t*) buf;
    *_buf++ = v&0xff; v>>=8;
    *_buf++ = v&0xff; v>>=8;
}

/** This is used to encode a 32-bit number into the little endian order
    @param buf  The buffer to populate
    @param v    The 32-bit value to place into the buffer
 
    Note: this is done by the explicit (tedious) method of populating the
    buffer instead of casting a pointer (e.g. *(uint32_t)*buf=v;)  That approach
    bus faults on some architectures if the buffer isn't aligned just right.
 */
inline void LEU32_encode(void* buf, uint32_t v)
{
    uint8_t* _buf = (uint8_t*) buf;
    *_buf++ = v&0xff; v>>=8;
    *_buf++ = v&0xff; v>>=8;
    *_buf++ = v&0xff; v>>=8;
    *_buf++ = v&0xff; v>>=8;
}

/** A helper to convert ASCII hex to binary
    @param c characte to convert
    @returns the converted value
 */
extern uint8_t ascii2hex(char c);


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

/** This is called to request status info from Vector
 */
extern void status_req(void);

/** This is called to request a log from Vector
 
    The follow up should call log_resp() and fileDownload_recv()
 */
extern void log_req(void);

/** This is called to request a cloud session
    @param token         The session token from the cloud service
    @param clientName    The name of the computer[?]
    @param applicationId The name of the application software
 */
extern void CloudSession_req(char const* token, char const* clientName, char const* applicationId);


/** This is called to request Vector become a WIFI access point
    @param enable  0 to disable the WIFI access point, otherwuse to enable the
                access point

    If not cloud authorized, this will give a response 0x21 (response message)
    with an error message that this is not cloud authorized.

    Under other conditions (TBD) an "access point" response will come back and
    explain what is going on
 
    The hypothesis is that enabling the WIFI access point will enable a UDP
    server on Vector that is similar to the one on Cozmo; the pycozmo figured
    much of Cozmo's protocol.
 */
extern void WiFi_AP_req(uint8_t enable);
#endif /* utils_h */
