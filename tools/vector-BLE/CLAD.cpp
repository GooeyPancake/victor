//
//  CLAD.cpp
//  Anki-1
//
//  Created by Randall Maas on 10/3/19.
//  Copyright © 2019 Randall Maas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void CLAD_nextStep();


/** This is called to display a string embedded in nybbles
    @param str   The nybbles
    @param len   The number of bytes in the str buffer
 */
static void printHexString(uint8_t const* str, size_t len)
{
    while (len > 0)
    {
        uint8_t c = ascii2hex(*str++); c<<=4;
        c|=ascii2hex(*str++);
        len-=2;
        fputc(c, stdout);
    }
}


/** This is called to display a string
    @param str   The nybbles
    @param len   The number of bytes in the str buffer
 */
static void printString(uint8_t const* str, size_t len)
{
    fwrite(str, len, 1, stdout);
}

/** This is called to interpret the response message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
*/
void response_recv(uint8_t const* msg, size_t size, uint8_t version)
{
    uint16_t code = LEU16_decode(msg);
    uint8_t  len  = msg[2];
    printf("\nResponse");
    printf("\n\tcode        : %d", code);
    if (0 == code)
        printf("  not cloud authorized"); // otherwise authorized
    //printf("\n\tlen         : %d", len);
    printf(" [");
    fwrite(msg+3,1,len,stdout);
    printf("]\n\n");
    fflush(stdout);
}

#pragma mark --- Status --------------------------------------------------------
/** This is called to interpret the stats message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 
    This is the response to a status info request
        status_req()
    or
        sendMsg(0xa,0);
 */
void status_recv(uint8_t const* msg, size_t size, uint8_t version)
{
    printf("\nStatus");
    auto SSID_len = *msg++;
    printf("\n\tSSID              : "); printHexString(msg,SSID_len); msg+= SSID_len;
    printf("\n\tWIFI state        : %d", *msg++);
    printf("\n\taccess point      : %d", *msg++);
    printf("\n\tBluetooth LE state: %d", *msg++);
    printf("\n\tBattery state     : %d", *msg++);
    if (version >= 2)
    {
        auto ver_len = *msg++;
        printf("\n\tVersion           : "); printString(msg,ver_len); msg+= ver_len;
    }
    if (version >= 4)
    {
        auto ESN_len = *msg++;
        printf("\n\tESN               : "); printString(msg,ESN_len); msg+= ESN_len;
    }
    if (version >= 2) printf("\n\tOTA in progress   : %d", *msg++);
    if (version >= 3) printf("\n\thas owner         : %d", *msg++);
    if (version >= 5) printf("\n\tcloud authorized  : %d", *msg++);

    printf("\n\n");fflush(stdout);
}


#pragma mark --- Log ----------------------------------------------------------
/// The file to store the log into
FILE* logFile;

/** This is called to interpret the file download message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 
    This is the response to a log request
        log_req()
     or
        sendMsg(0x18,0);
 
    The file download will be a .tar.bz2, with contents like:
        data/diagnostics/logs/connman-services.txt
        data/diagnostics/logs/dmesg.txt
        data/diagnostics/logs/ifconfig.txt
        data/diagnostics/logs/iwconfig.txt
        data/diagnostics/logs/log.txt
        data/diagnostics/logs/netstat-ptlnu.txt
        data/diagnostics/logs/ping-anki.txt
        data/diagnostics/logs/ping-gateway.txt
        data/diagnostics/logs/ps.txt
        data/diagnostics/logs/top.txt
        data/boot.log
        factory/log0
        factory/log1
        run/update-engine/error

    These might differ based on the firmware version on Vector.
 
    These may be selectable by log filter
 */
void fileDownload_recv(uint8_t const* msg, size_t size, uint8_t version)
{
    // Decode the fields
    uint8_t  status   = msg[0];
    uint32_t fileId   = LEU32_decode(msg+1);
    uint32_t pktNum   = LEU32_decode(msg+5);
    // The total number of packets to be sent for this file download
    uint32_t pktTotal = LEU32_decode(msg+9);
    // The number of bytes to follow (can be 0)
    uint16_t length   = LEU16_decode(msg+13);
    
    // Things that could be done
    //  * look up the file pointer for the fileId
    //  * check the packet number
    fwrite(msg+15, 1, length, logFile);
    
    // see if e're done
    if (pktNum == pktTotal)
    {
        fprintf(stdout, "log: file download complete.\n");
        fflush(logFile);
        fclose(logFile);
    }
}


/** This is called to interpret the log response message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 
    This is the response to a log request
        log_req()
     or
        sendMsg(0x18,0);
 */
void log_recv(uint8_t const* msg, size_t size, uint8_t version)
{
    // Decode the fields
    uint8_t  status   = msg[0];
    uint32_t fileId   = LEU32_decode(msg+1);
    fprintf(stderr, "log: downloading file\n");
}


#pragma mark --- WIFI ----------------------------------------------------------
/** This is called to interpret the Cloud Session response message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 
    This is the response to a WiFi access point request
        CloudSession_req()
 */
void CloudSession_recv(uint8_t const* msg, size_t size, uint8_t version)
{
    uint8_t success = msg[0];
    uint16_t len    = LEU16_decode(msg+1);
    // The GUID is held in the rest of the message
    uint8_t const* GUID = msg +3;
}


/** This is called to interpret the WIFI access point response message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 
    This is the response to a WiFi access point request
        WiFi_AP_req()
     or
        sendMsg(0x13,0);
 */
void WiFi_AP_recv(uint8_t const* msg, size_t size, uint8_t version)
{
    // Decode the fields
    // enabled 0 if the WiFi access point is disabled, otherwise enabled
    uint8_t  enabled    = msg[0];

    // The number of bytes in the SSID string; may be 0
    uint8_t SSID_len    = msg[1];
    // The WiFI SSID, as a hex string (hex string)
    // uint8_t[SSID length]
    auto SSID_hex       = msg+2;

    // The number of bytes in the password string; may be 0
    uint8_t Password_len= msg[1];
    // The WiFI password string
    // uint8_t[Password length]
    auto Password_str   = msg+2;

    // Print the info out
    printf("\nWIFI Access Point Mode");
    printf("\n\nenabled            : %s", enabled?"yes":"no");
    printf("\n\tSSID              : "); printHexString(SSID_hex,SSID_len);
    printf("\n\tpassword          : "); printString   (Password_str, Password_len);
    printf("\n\n");fflush(stdout);
}


#pragma mark --- CLAD interface ------------------------------------------------
/** This is called to interpret the disconnect message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 */
void CLAD_disconnect(uint8_t const* msg, size_t size, uint8_t version)
{
    (void) size;
    (void) msg;
    (void) version;
    fprintf(stderr, "Vector: link closed by Vector\n");
    exit(0);
}


/** This is called to interpret message
    @param type    the type of message received
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
 */
void CLAD_interpret(uint8_t type, uint8_t const* msg, size_t size, uint8_t version)
{
    switch(type)
    {
        case 0:
            fprintf(stderr, "Vector: error, disconnected\n");
            exit(-1);
            break;
        case 0x0b:
            // Status info
            status_recv(msg, size, version);
            break;
        case 0x14:
            // WIFI access point response
            WiFi_AP_recv(msg,size,version);
            break;
        case 0x19:
            // log response
            log_recv(msg,size,version);
            break;
        case 0x1a:
            // file download
            fileDownload_recv(msg,size,version);
            break;
        case 0x1e:
            // cloud session
            CloudSession_recv(msg,size,version);
            break;
        case 0x21:
            // response
            response_recv(msg, size, version);
            break;
        default:
            break;
    }
    
    // Add a receive done to trigger the next stuff
    CLAD_nextStep();
}

// This is called when the lower layers are ready
void CLAD_ready()
{
    // Send a request for status info
    status_req();
}

static int _argc;
static const char** _argv;
static int _myState = 0;

// This is called after something else was received so that I can send out a
// further command line-triggered action
void CLAD_nextStep()
{
    //if (_myState) return;
    if (_argc == 3 && 0==strcasecmp(_argv[1], "ap"))
    {
        if (_myState ==1)
        {
            _myState = 2;
            // access point mode
            WiFi_AP_req(0==strcasecmp(_argv[2], "enable")?1:0);
            return;
        }
        if (_myState == 2) exit(0);
        _myState = 1;
        // Request a cloud session first
        CloudSession_req("2ky3cjcJPmmcjHWd9AQ9FZS", "lappy2000", "companion-app");
        return ;
    }
    else if (_argc == 3 && 0==strcasecmp(_argv[1], "log"))
    {
        if (_myState ==1) return;
        _myState = 1;
        // download the logs
        // set the file name
        // file name = _argv[2]
        logFile = fopen(_argv[2],"w");
        log_req();
    }
    else
    {
        exit(0);
    }
    // Todo:
    // see if we should trigger an OTA download
    // see if we should try to enable SSH
    // WIFI ip address
    // WIFI scan
    // Other wifi management
}

/* Some of the commands that can be done
      "ap enable" to enable access point
      "log FILENAME" to retrieve the logs
 */
int main(int argc, const char * argv[])
{
    _argc = argc;
    _argv = argv;
    // Scan for Vector
    bleScan();
    return 0;
}
