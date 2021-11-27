#include "Utilities.h"

void ledBlink(int pin, int cycleDuration, int times){
  bool ledStatus = false;
  for(int i = 0; i < times * 2; i++){
    digitalWrite(pin, ledStatus);  
    delay(cycleDuration / 2);
    ledStatus = !ledStatus;
  }

  digitalWrite(pin, false);
}
