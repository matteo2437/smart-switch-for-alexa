#include "Switch.h"

Switch::Switch(){
  Switch(-1);
}

Switch::Switch(int buttonPin){
  this->buttonPin = buttonPin;
}

void Switch::init(){
  pinMode(buttonPin, INPUT);
  updateState();
}

void Switch::onStateChange(std::function<void()> action){
  if(getState()){
    if((millis() - t) > debounceDelay){
      t = millis();
      action(); 
    }
  }
  updateState();
}

/**Private methods***/

bool Switch::getCurrentState(){
  return digitalRead(buttonPin);  
}

bool Switch::getState(){
  return lastButtonState != getCurrentState();  
}

void Switch::updateState(){
  lastButtonState = getCurrentState();
}
