#include "OtaHandler.h"

void OtaHandler::init() {
    if (server == nullptr) {
        server = new WebServer(80);
        ESP2SOTA.begin(server);
        server->begin();
    }
    Serial.println("\nESP server initialized");

    String _deviceId = deviceId.generateId();

    // Initialize mDNS
    if (!MDNS.begin(_deviceId.c_str())) {   
        Serial.println("Error setting up MDNS responder!");
        while(1) {
            delay(1000);
        }
    }

    // Add service to MDNS-SD
    MDNS.addService("http", "tcp", 23);
}

void OtaHandler::handleRequest() {
    server->handleClient();                // Handle update requests
    delay(50);
}