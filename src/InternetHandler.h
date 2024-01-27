#ifndef INTERNET_HANDLER_H
#define INTERNET_HANDLER_H

#include "wifi_credentials.h"
#include <WiFi.h>

class InternetHandler{
    public:
     bool init();
     
     bool reconnect();
     bool isConnected();

    private:
     bool connect();
     unsigned long now;
     unsigned long lastChecked;
};

extern InternetHandler internetHandler;

#endif
