#include <Espalexa.h>
#include <Arduino.h>

class AlexaDevice {
  private:
    Espalexa espalexa;
    String name;
    int outputPin;
    bool lightState = false;
    
  public:
    AlexaDevice();
    AlexaDevice(String name, int outputPin);
    void init();    
    void setLight(uint8_t);
    void toggleLight();
    
    void turnOn();
    void turnOff();
    void loop();
    
  private:
    void setLightStatus(bool);
    bool getLightStatus();
    bool toggleLightStatus();   

};
