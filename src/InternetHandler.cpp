#include "InternetHandler.h"
#include "Global.h"

bool InternetHandler::isConnected() {
    if (WiFi.status() == WL_CONNECTED) {
        return true;
    }
    else {
        return false;
    }
}
bool InternetHandler::connect() {
    Serial.println("\nConnecting to WiFi");
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    
    lastChecked = millis();
    while (!isConnected() && millis() - lastChecked < 5000) {}

    if (!isConnected()) {
        Serial.println("\nWiFi connection failed");
        return false;
    }
    else {
        Serial.println("\nWiFi connected");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        return true;
    } 
}

bool InternetHandler::init() {
    WiFi.mode(WIFI_STA);
    return connect() == true;
}


bool InternetHandler::reconnect() {
    WiFi.disconnect();
    return connect() == true;
}