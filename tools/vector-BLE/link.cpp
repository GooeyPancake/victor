//
//  link.cpp
//  Anki-1
//
//  Created by Randall Maas on 10/1/19.
//  Copyright © 2019 Randall Maas. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "/usr/local/include/sodium.h"
#include "utils.h"

/// The version of the protocol and message formats
int protoVersion;


/// The maximum size of a message at the "CLAD" layer
#define CLAD_MAX_SIZE (65536+1024)

/// The maximum number of bytes that can be put into a BLE payload
#define PAYLOAD_MAX_SIZE (19)

/// The kind of frame
enum
{
    VBLE_continue= 0<<6,
    VBLE_end     = 1<<6,
    VBLE_start   = 2<<6,
    VBLE_solo    = 3<<6
};

uint8_t out_buf[4+CLAD_MAX_SIZE];
uint8_t* out_msg=out_buf+3;

void LEU32_encode(void* buf, uint32_t v)
{
    uint8_t* _buf = (uint8_t*) buf;
    *_buf++ = v&0xff; v>>=8;
    *_buf++ = v&0xff; v>>=8;
    *_buf++ = v&0xff; v>>=8;
    *_buf++ = v&0xff; v>>=8;
}

#pragma mark credentials
/// The credentials for communicating with vector
uint8_t Vector_publicKey[crypto_kx_PUBLICKEYBYTES];


/** A place for the operator to enter the pin code
    @param pin    A buffer to hold the pin code
    @param pinLen The size of the buffer
    This can be overridden by another module
 */
__attribute__((weak)) void UI_getPin(char* pin, int pinLen)
{
    printf("enter pin: "); fflush(stdout);
    pin[0]=0;
    fgets(pin, pinLen, stdin);
    pin[pinLen]=0;
    // get rid of newline
    for (auto I = 0; I < pinLen && pin[I]; I++)
        if ('\n' == pin[I])
        {
            pin[I] = 0;
            break;
        }
}

/// This is set once we are supposed to start using the encryption
uint8_t useEncryption = 0;
uint8_t publicKey [crypto_kx_PUBLICKEYBYTES];
uint8_t secretKey [crypto_kx_SECRETKEYBYTES];
uint8_t encryptionKey[crypto_kx_SESSIONKEYBYTES];
uint8_t encryptionNonce[24];
uint8_t decryptionKey[crypto_kx_SESSIONKEYBYTES];
uint8_t decryptionNonce[24];





#pragma mark Link related message processing

/// This is use to track whether we've done the handshake yet
static int didHandshake=0;


/** This is called to interpret the connect-request message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 */
static void connRequest_recv(uint8_t const* msg, size_t size, uint8_t version)
{
    (void) size;
    // A connection message is a public key
    memcpy(Vector_publicKey, msg, 32);

    // first time vs other
    // Before running this program, you will have to press the button his back
    // twice, while he is on the charger
    crypto_kx_keypair(publicKey, secretKey);
    
    // create message
    out_msg[0] = 0; // first time
    memcpy(out_msg+1, publicKey, crypto_kx_PUBLICKEYBYTES);
    sendMsg(2, 1+crypto_kx_PUBLICKEYBYTES);

    // IF not the first time, can reuse the publicKey / etc rom the past
}


/** This is called to interpret the disconnect message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 */
static void disconnect_recv(uint8_t const* msg, size_t size, uint8_t version)
{
    (void) size;
    (void) msg;
    (void) version;
    fprintf(stderr, "Vector: link closed by Vector\n");
}


/** This is called to interpret the disconnect message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 */
static void nonce_recv(uint8_t const* msg, size_t size, uint8_t version)
{
    (void) size;
    (void) msg;
    (void) version;

    // Set up the nonces
    memcpy(encryptionNonce, msg   , 24); // the to robot nonce
    memcpy(decryptionNonce, msg+24, 24); // the to application nonce

    // set up the session keys
    char pin[16];
    UI_getPin(pin, sizeof(pin)-1);
    pin[sizeof(pin)-1]=0;

    (void) crypto_kx_client_session_keys(decryptionKey, encryptionKey, publicKey, secretKey, Vector_publicKey);
    size_t pin_length = strlen((char*)pin);
    crypto_generichash(encryptionKey, sizeof(encryptionKey), encryptionKey, sizeof(encryptionKey), (uint8_t*) pin, pin_length);
    crypto_generichash(decryptionKey, sizeof(decryptionKey), decryptionKey, sizeof(decryptionKey), (uint8_t*) pin, pin_length);

    // send an ack
    out_msg[0] = 3; // What does this mean?
    sendMsg(0x12, 1);
    // Now that we have the nonce, everything we do should use the encryption
    useEncryption = 1;
}

/** This is called to test the encryption by Vector
    @param msg        the received bytes in the message
    @param size       the number of bytes in the message
    @param msgVersion The format version the message was encoded in
 */
static void challenge_recv(uint8_t const* msg, size_t size, uint8_t msgVersion)
{
    // get the challenge value
    uint32_t challenge = LEU32_decode(msg);
    // increment it and sent it back
    LEU32_encode(out_msg, challenge+1);
    sendMsg(4, 4);
}


/** This is called to interpret the challenge success message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 */
static void success_recv(uint8_t const* msg, size_t size, uint8_t version)
{
    (void) size;
    (void) msg;
    (void) version;
    // let the next leve know that we are ready
    CLAD_ready();
}

#pragma mark receive, defragement decrypt

/** This is called when the Bluetoth LE stack receives a charatristic
    @param frame  the received bytes (a frame)
    @param length the number of bytes received
 */
void bleRecv(uint8_t const* frame, size_t length)
{
    // Perform reassembly on the packet
    // This buffer should be big enough for the worst case
    static uint8_t _buffer[CLAD_MAX_SIZE];
    auto buffer = _buffer;
    static off_t buf_ofs = 0;
    
    // get the number of bytes in the fragment
    // todo: sanity check the received bytes with the length embedded
    auto payloadSize = frame[0]&0x3f;

    // check to see how to reassemble
    switch(frame[0]&~0x3f)
    {
        case VBLE_start:
        case VBLE_solo: buf_ofs = 0; break;
    }

    // append the payload to the CLAD message buffer
    memcpy(buffer+buf_ofs,frame+1,payloadSize);
    buf_ofs += payloadSize;

    // see if there is more to do
    switch(frame[0]&~0x3f)
    {
        default:
            return;
        case VBLE_solo:
        case VBLE_end:
            // reassembly complete, pass onto next stage
            break;
    }

    // Have we done a handshake?
    if (!didHandshake)
    {
        // Process the bytes as a handshake, if we haven't done so already
        // decode versions and such
        didHandshake = 1;
        protoVersion = LEU32_decode(buffer+1);
        // send the bytes back
        bleSend(frame, length);
        return;
    }
    
    // check to see if we should decrypt it now
    uint8_t message[CLAD_MAX_SIZE];
    if (useEncryption)
    {
        // decrypt
        unsigned long long destLen=0;
        (void) crypto_aead_xchacha20poly1305_ietf_decrypt(message, &destLen, NULL, buffer, buf_ofs,  NULL, 0L, decryptionNonce, decryptionKey);

        // update the nonce
        sodium_increment(decryptionNonce, sizeof decryptionNonce);
        
        buffer  = message;
        buf_ofs = destLen;
    }
    
    
    // The next part is a little tricky.
    // There are 1 to 2 bytes that indicte the message format version
    int  msgVersion = 1;
    auto msgBody    = buffer+1;
    auto msgSize    = buf_ofs-1;
    // buffer[0] is either 1 or 4
    if (4 == buffer[0])
    {
        // The message version  is embedded
        msgVersion = *msgBody++;
        msgSize--;
    }

    // The next byte is the tag indicating type of message
    auto msgType = *msgBody++;
    msgSize --;

    // process the link-related messages
    switch(msgType)
    {
        case 1:
            // A connection message
            connRequest_recv(msgBody, msgSize, msgVersion);
            return;
        case 0x11:
            // A close connection
            disconnect_recv(msgBody, msgSize, msgVersion);
            return;
        case 3:
            // A nonce message
            nonce_recv(msgBody, msgSize, msgVersion);
            return;
        case 4:
            // A challenge message
            challenge_recv(msgBody, msgSize, msgVersion);
            return;
        case 5:
            // A challenge success
            success_recv(msgBody, msgSize, msgVersion);
            return;
            
        default:
            // pass control to the higher level processing
            CLAD_interpret(msgType, msgBody, msgSize, msgVersion);
            break;
    }
}


#pragma mark encrypt, fragement and send
/** This is called to interpret message
    @param tag    the message code
    @param size   the number of bytes in the message
 */
void sendMsg(uint8_t tag, size_t size)
{
    uint8_t _cipher[CLAD_MAX_SIZE];
    // Fill in the version of protocol that we are using...
    out_buf[0]= 4;
    out_buf[1]= protoVersion;
    out_buf[2]= tag;
    
    uint8_t* cipher = out_buf;
    unsigned long long cipherLength = size+3;
    if (useEncryption)
    {
        // encrypt it
        crypto_aead_xchacha20poly1305_ietf_encrypt(_cipher, &cipherLength, out_buf, size+3, NULL, 0L, NULL, encryptionNonce, encryptionKey);
        cipher=_cipher;
        
        // update the nonce
        sodium_increment(encryptionNonce, sizeof encryptionNonce);
    }

    // fragment and send encrypted data
    int8_t buf[PAYLOAD_MAX_SIZE+1];
    for (off_t ofs = 0; ofs < cipherLength;)
    {
        uint8_t messageType = VBLE_continue;
        auto payloadSize = cipherLength-ofs;
        if (0 == ofs)
        {
            messageType = (payloadSize <= PAYLOAD_MAX_SIZE) ? messageType = VBLE_solo: messageType = VBLE_start;
        }
        else if ((ofs+PAYLOAD_MAX_SIZE) >= cipherLength)
        {
            messageType = VBLE_end;
        }
        // clamp the patload size
        if (payloadSize > PAYLOAD_MAX_SIZE)
        {
            payloadSize = PAYLOAD_MAX_SIZE;
        }
        
        // put the frame together
        memcpy(buf+1,cipher+ofs, payloadSize);
        buf[0] = messageType | payloadSize;
        ofs += payloadSize;

        // pass it to the BLE stck
        bleSend(buf,payloadSize+1);
    }
}


