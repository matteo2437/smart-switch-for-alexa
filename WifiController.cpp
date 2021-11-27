#include "WifiController.h"

WifiController::WifiController(){
  WifiController("", "", -1);
}

WifiController::WifiController(char* ssid, char* password, int statusPin){    
  this->ssid = ssid;
  this->password = password;
  this->statusPin = statusPin;
}

void WifiController::onConnected(std::function<void()> action){
  connect();
  if(isConnected())
    action();  
}

void WifiController::connect(){
  WifiController::setIsConnected(true);

  WifiController::initWifi();
  
  Serial.println("");
  Serial.println("Connecting to WiFi");
  Serial.print("Connecting...");
  
  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20) {
      ledBlink(statusPin, 1500, 3);
      WifiController::setIsConnected(false);
      break;
    }
    i++;
  }
  
  Serial.println("");
  
  if (WifiController::isConnected()) {
    ledBlink(statusPin, 500, 3);
    WifiController::printWifiInfo();
  }
  else {
    Serial.println("Connection failed.");
  }
}

void WifiController::printWifiInfo(){
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

boolean WifiController::isConnected(){
  return isWifiConnected;  
}

/**Private methods***/

void WifiController::setIsConnected(bool status){isWifiConnected = status;}

void WifiController::initWifi(){
  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  WiFi.begin(ssid, password);
}
