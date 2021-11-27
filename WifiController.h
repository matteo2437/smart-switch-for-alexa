#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "Utilities.h"

class WifiController {
  private:
    char* ssid;
    char* password;
    int statusPin;
    bool isWifiConnected = false;

  public:
    WifiController();
    WifiController(char*, char*, int);
    void onConnected(std::function<void()> action);
    void connect();
    void printWifiInfo();
    bool isConnected();

 private:   
    void setIsConnected(bool);
    void initWifi();
};
