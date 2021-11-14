#ifndef DEF_GAMEBOARD
#define DEF_GAMEBOARD
#pragma once

#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h> //regarder https://learn.adafruit.com/adafruit-led-backpack/1-2-inch-7-segment-backpack-arduino-wiring-and-setup pour installer les bonnes biblotheques
#include "Adafruit_LEDBackpack.h"
#include "LightButton.h"



class Gameboard
{
	/*
	 * Cette classe permet de contrôler le tableau de jeu : les boutons, les lights et les affichages de score
	 * les boutons de 0 à 9 correspondent au joueur 1 et de 10 à 19 au joueur 2
	 */
private:

	//lumieres/boutons joueur 1:
	LightButton* pLightsJoueur1[10] = { NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };
	//lumieres/boutons joueur 2;
	LightButton* pLightsJoueur2[10] = { NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL };

	// Definition des deux taleaux de score:
	Adafruit_7segment matrix1;
	Adafruit_7segment matrix2;

public:
	Gameboard();
	void init();
	//gestion des tableaux de score
	void afficher_score(int joueur, int message);
	void afficher_play(); //afficher le message play dans les deux display
	//gestion des lumières
	void toggle_light(byte num_light);
	void off_light(byte num_light);
	void on_light(byte num_light);
	void toggle_all_lights();
	void on_all_lights();
	void off_all_lights();
	//détection de l'utilisation d'un bouton
	bool risingEdge(byte num_boutton);
	//affichage de texte specifique
	void afficher_menu();

};

#endif
