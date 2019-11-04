//
//  CLAD-req.cpp
//  vector-BLE
//
//  Created by Randall Maas on 11/2/19.
//  Copyright © 2019 Blackwood Designs, LLC. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include "utils.h"

/** A helper to convert ASCII hex to binary
    @param c characte to convert
    @returns the converted value
 */
uint8_t ascii2hex(char c)
{
    if (c >= '0' && c <= '9') return c-'0';
    if (c >= 'a' && c <= 'f') return 10+(c-'a');
    if (c >= 'A' && c <= 'F') return 10+(c-'A');
    return 0;
}

#pragma mark --- Status --------------------------------------------------------
/** This is called to request status info from Vector
 */
void status_req(void)
{
    // Send a request for status info
    sendMsg(0xa,0);
}


#pragma mark --- Log ----------------------------------------------------------
/** This is called to request a log from Vector
 
    The follow up should call log_resp() and fileDownload_recv()
 */
void log_req(void)
{
    // mode (enumeration unknown)
    out_msg[0] = 0;

    // num filters
    LEU16_encode(out_msg, 0);

    // each filter
    // none for now
    
    // Send a request for log info
    sendMsg(0x18,3);
}


#pragma mark --- WIFI ----------------------------------------------------------

/** This is called to request a cloud session
    @param token         The session token from the cloud service
    @param clientName    The name of the computer[?]
    @param applicationId The name of the application software
 */
void CloudSession_req(char const* token, char const* clientName, char const* applicationId)
{
    uint16_t len = strlen(token);
    LEU16_encode(out_msg, len);
    uint16_t ofs = 2;
    memcpy(out_msg+ofs,token, len);
    ofs+= len;
    len = strlen(clientName);
    out_msg[ofs] = len;
    ofs++;
    memcpy(out_msg+ofs,clientName, len);
    ofs+= len;
    len = strlen(applicationId);
    out_msg[ofs] = len;
    ofs++;
    memcpy(out_msg+ofs,applicationId, len);
    ofs+= len;

    // Send a request for Cloud session
    sendMsg(0x1d,ofs);
}




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
void WiFi_AP_req(uint8_t enable)
{
    // enable / disable the WIFI access point
    out_msg[0] = enable?1:0;
    
    // Send a request for WiFI Access point
    sendMsg(0x13,1);
}

