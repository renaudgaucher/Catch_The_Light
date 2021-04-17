#include "Gameboard.h"

Gameboard::Gameboard(): matrix1(), matrix2()
{

  // Les pins dédiés au joueur 1 sont de 2 à 9, puis de 22 à 33, pin pair light, pin impair boutton
  for (int counter = 0; counter < 4; counter++)
  {
    pLightsJoueur1[counter] = new LightButton(2 + 2 * counter, 3 + 2 * counter);
  }
  for (int counter = 0; counter < 6; counter++) {
    pLightsJoueur1[counter+4] = new LightButton(22 + 2 * counter, 23 + 2 * counter);
  }

  // Les pins dédiés au joueur 2 sont de 34 à 53, les paires pour les light et impaires pour les bouttons
  for (int counter = 0; counter < 10; counter++) {
    pLightsJoueur2[counter] = new LightButton(34 + 2 * counter, 35 + 2 * counter);
  }

}


void Gameboard::init() {
  // Ici les fonctions qui ont besoin que l'Arduino soit initialisée pour être appelées
  matrix1.begin(0x70);
  matrix2.begin(0x71);
}


// une fois les boutons branchés et les pins attribués, on notera les boutons de 0 à 9 pour le joueur 1 et de 10 à 19 pour le joueur 2

//gestion des tableaux de score
void Gameboard::afficher_score(int joueur, int message) {
  if (joueur == 1) {
    matrix1.print(message, DEC);
    matrix1.writeDisplay();
  }
  else {
    matrix2.print(message, DEC);
    matrix2.writeDisplay();
  }
}

//gestion des lumières
void Gameboard::toggle_light(byte num_light) {
  if (num_light < 10) {
    pLightsJoueur1[num_light]->l_toggle();
  }
  else {
    pLightsJoueur2[num_light - 10]->l_toggle();
  }
}

void Gameboard::off_light(byte num_light) {
    if (num_light < 10) {
        pLightsJoueur1[num_light]->l_off();
    }
    else {
        pLightsJoueur2[num_light - 10]->l_off();
    }
}

void Gameboard::on_light(byte num_light) {
    if (num_light < 10) {
        pLightsJoueur1[num_light]->l_on();
    }
    else {
        pLightsJoueur2[num_light - 10]->l_on();
    }
}

void Gameboard::toggle_all_lights() {
  for (int counter = 0; counter < 10; counter++) {
    pLightsJoueur1[counter]->l_toggle();
    pLightsJoueur2[counter]->l_toggle();
  }
}

void Gameboard::on_all_lights() {
  for (int counter = 0; counter < 10; counter++) {
    pLightsJoueur1[counter]->l_on();
    pLightsJoueur2[counter]->l_on();
  }
}


void Gameboard::off_all_lights() {
  for (int counter = 0; counter < 10; counter++) {
    pLightsJoueur1[counter]->l_off();
    pLightsJoueur2[counter]->l_off();
  }
}

//détection de l'utilisation d'un bouton
bool Gameboard::risingEdge(byte num_boutton) {
  if (num_boutton < 10) {
    return (pLightsJoueur1[num_boutton]->b_risingEdge());
  }
  else {
    return (pLightsJoueur2[num_boutton - 10]->b_risingEdge());
  }
}

void Gameboard::afficher_play() {
    //Ne fonctionne pas encore
    uint8_t lettreP;
    uint8_t lettreL;
    uint8_t lettreA;
    uint8_t lettreY;
}