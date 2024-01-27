#include "DeviceId.h"

String DeviceId::generateId() {
    String _macAddr = WiFi.macAddress();
    String _deviceId = "WBX-" + _macAddr.substring(0,2) + _macAddr.substring(6,8) + _macAddr.substring(12,14);
    Serial.print("\nWaterbox Id: ");
    Serial.println(_deviceId);
    return _deviceId;
}