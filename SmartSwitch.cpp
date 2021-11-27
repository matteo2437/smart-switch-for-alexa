#include "SmartSwitch.h"

SmartSwitch::SmartSwitch(SmartSwitchSettings settings){
  this->settings = settings;
  
  wifiController = WifiController(
    settings.ssid, 
    settings.password, 
    settings.outputPin
  );
   
  device = AlexaDevice(
    settings.deviceName, 
    settings.outputPin
  );
   
  switchComponent = Switch(settings.switchPin);
};

void SmartSwitch::init(){
  pinMode(settings.outputPin, OUTPUT);  
  switchComponent.init();
  
  Serial.begin(115200);
  
  wifiController.onConnected([&](){
    device.init();
  });
}

void SmartSwitch::run(){
  switchComponent.onStateChange([&](){
    if(!wifiController.isConnected()){
      wifiController.onConnected([&](){
        device.init();
      }); 
    }

    device.toggleLight();
  });
  
  device.loop();
  delay(1);
}
