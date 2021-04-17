#include "Button.h"



Button::Button(byte pin){
  this->pin = pin;
  init();
}
Button::Button(int pin){
  this->pin = pin;
  init();
}

void Button::init(){
  pinMode(pin, INPUT_PULLUP);
}
bool Button::readState(){
  return buttonState;
}

bool Button::risingEdge(){
  bool result = false;
  // Si le boutton a ete presse depuis la derniere fois renvoie vrai, sinon
  buttonState = digitalRead(pin);

  // Delay a little bit to avoid bouncing
  unsigned long currentTime=millis();
  
  if (currentTime-temps>delai){
    temps=currentTime;
    // compare the buttonState to its previous state
    if (buttonState != lastButtonState) {
      if (buttonState == LOW) {
        // if the current state is LOW then the button went from off to on:
        result = true;
      }
    }
  
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  }
  return result;
}
