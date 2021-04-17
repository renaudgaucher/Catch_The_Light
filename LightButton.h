#ifndef DEF_LIGHTBUTTON
#define DEF_LIGHTBUTTON

#include <Arduino.h>
#include "Button.h"


class LightButton{
  
   private:
    Button button;
   
    //Pour la LED
    int l_pin;
    bool l_state;

    //Modifie l'état de la LED
    void l_writeState(bool state);
    
   
   public:

    //constructeur
    LightButton(int pinLight, int pinButton);
    //True si le bouton est pressé
    bool b_get_button_State();
    //True si détection de front montant (changement de LOW à HIGH)
    bool b_risingEdge();
    //etat du bouton
    bool b_getState();

    // Gestion de la lampe
    //Retourne l'état de la LED (allumée/éteinte)
    bool l_getState();
    //Allume la LED
    void l_on();
    void l_off();
    void l_toggle();
};

#endif
