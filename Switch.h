#include <Arduino.h>

class Switch {
  private:
    int buttonPin;
    bool lastButtonState;
    int debounceDelay = 200;
    long t = 0;

  public:
    Switch();
    Switch(int);
    void init();
    void onStateChange(std::function<void()> action);  

  private:
    bool getCurrentState(); 
    bool getState();
    void updateState();
};
