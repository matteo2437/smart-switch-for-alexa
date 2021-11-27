#include <Arduino.h>
#include "Utilities.h"
#include "WifiController.h"
#include "AlexaDevice.h"
#include "Switch.h"

struct SmartSwitchSettings {
  char* ssid;
  char* password;
  String deviceName;
  int outputPin;
  int switchPin;  
};

class SmartSwitch {
  private:
     WifiController wifiController;
     AlexaDevice device;
     Switch switchComponent;
     SmartSwitchSettings settings;
     
  public:
    SmartSwitch(SmartSwitchSettings);
    void init();
    void run();
};
