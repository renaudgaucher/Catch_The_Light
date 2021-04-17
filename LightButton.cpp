#include "LightButton.h"



//Modifie l'état de la LED
void LightButton::l_writeState(bool state) {
  l_state = state;
  digitalWrite(l_pin, l_state);
}


LightButton::LightButton(int pinLight, int pinButton):button(pinButton)
{

  l_pin = pinLight;
  pinMode(l_pin, OUTPUT);
  l_state = LOW;
}

//Gestion du bouton

bool LightButton::b_get_button_State() {
  return (button.readState());
}

//True si détection de front montant (changement de LOW à HIGH)
bool LightButton::b_risingEdge() {
  return button.risingEdge();
}


// Gestion de la lampe

//Retourne l'état de la LED (allumée/éteinte)
bool LightButton::l_getState() {
  return (l_state);
}

//Allume la LED
void LightButton::l_on() {
  l_writeState(HIGH);
}

void LightButton::l_off() {
  l_writeState(LOW);
}

void LightButton::l_toggle() {
  l_writeState(!l_state);
}
