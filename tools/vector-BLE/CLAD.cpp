//
//  CLAD.cpp
//  Anki-1
//
//  Created by Randall Maas on 10/3/19.
//  Copyright © 2019 Randall Maas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


static void printHexString(uint8_t const* str, size_t len)
{
    while (len > 0)
    {
        uint8_t c = *str++; c<<=4;
        c|=*str++;
        len-=2;
        fputc(c, stdout);
    }
}
static void printStr(uint8_t const* str, size_t len)
{
    fwrite(str, len, 1, stdout);
}


/** This is called to interpret the stats message
    @param msg     the received bytes of a message
    @param size    the number of bytes in the message
    @param version the format version of the message
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
        printf("\n\tVersion           : "); printStr(msg,ver_len); msg+= ver_len;
    }
    if (version >= 4)
    {
        auto ESN_len = *msg++;
        printf("\n\tESN               : "); printStr(msg,ESN_len); msg+= ESN_len;
    }
    if (version >= 2) printf("\n\tOTA in progress   : %d", *msg++);
    if (version >= 3) printf("\n\thas owner         : %d", *msg++);
    if (version >= 5) printf("\n\tcloud authorized  : %d", *msg++);

    printf("\n\n");fflush(stdout);
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
        case 0x0b:
            // Status info
            status_recv(msg, size, version);
            break;
        default:
            break;
    }
}

// This is called when the lower layers are ready
void CLAD_ready()
{
    // Send a request for status info
    sendMsg(0xa,0);
}

int main(int argc, const char * argv[])
{
    extern char pin[];
    bleScan();
    return 0;
}
