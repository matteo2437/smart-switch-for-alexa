#include "SmartSwitch.h"

SmartSwitch smartSwitch({
  ssid: "",
  password: "",
  deviceName: "",
  outputPin: 0,
  switchPin: 4,  
});

void setup() {
  smartSwitch.init();  
}

void loop() {  
  smartSwitch.run();
}
