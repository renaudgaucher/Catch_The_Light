
#pragma once
#include <Arduino.h>

class Button{
  private:
    int pin;
    bool buttonState=false; // current state of the button
    bool lastButtonState=false; // previous state of the button
    unsigned long temps=0; // Delay to avoid bouncing
    unsigned long delai=50;
 
   public:
   
   Button(byte pin);
   Button(int pin);
   void init();
   bool readState();
   bool risingEdge();
   
};
