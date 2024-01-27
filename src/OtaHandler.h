#ifndef OTA_HANDLER_H
#define OTA_HANDLER_H

#include <WebServer.h>
#include <ESP2SOTA.h>
#include <ESPmDNS.h>
#include "DeviceId.h"

class OtaHandler {
    public:
     void init();
     void handleRequest();
    
    private:
     WebServer *server = nullptr;
     DeviceId deviceId;

};

#endif
