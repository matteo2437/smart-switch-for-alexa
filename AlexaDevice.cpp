#include "AlexaDevice.h"

AlexaDevice::AlexaDevice(){
  AlexaDevice("", -1);
}

AlexaDevice::AlexaDevice(String name, int outputPin){
  this->name = name;
  this->outputPin = outputPin;
}

void AlexaDevice::init(){
  espalexa.addDevice(name, [&](uint8_t brightness) { 
    setLight(brightness); 
  });
  espalexa.begin();
}

void AlexaDevice::setLight(uint8_t brightness){
  brightness == 255 
    ? turnOn()
    : turnOff();
}

void AlexaDevice::toggleLight(){
  toggleLightStatus() 
    ? turnOn()
    : turnOff();
}

void AlexaDevice::loop(){espalexa.loop();}

void AlexaDevice::turnOn(){
  setLightStatus(true);
  digitalWrite(outputPin, HIGH);
  Serial.println("Device1 ON");
}

void AlexaDevice::turnOff(){
  setLightStatus(false);
  digitalWrite(outputPin, LOW);
  Serial.println("Device1 OFF");
}

/**Private methods***/

bool AlexaDevice::getLightStatus(){return lightState;}
void AlexaDevice::setLightStatus(bool state){lightState = state;}
bool AlexaDevice::toggleLightStatus(){
  lightState = !lightState;
  return lightState;
}
