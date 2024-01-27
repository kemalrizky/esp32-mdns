#include "Global.h"
#include "InternetHandler.h"
#include "OtaHandler.h"
#include "DeviceId.h"

InternetHandler internetHandler;
OtaHandler otaHandler;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  internetHandler.init();
  otaHandler.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!internetHandler.isConnected()) {
    Serial.println("Wifi connection lost");
    internetHandler.reconnect();
  }

  otaHandler.handleRequest();
  delay(100);
}

