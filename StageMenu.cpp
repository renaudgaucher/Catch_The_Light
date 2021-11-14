#include "StageMenu.h"
#include "StageGameHighScore.h"
#include "StageGameVersus.h"


StageMenu::StageMenu(Gameboard* gameboard) :Stage(gameboard)
{
}

byte StageMenu::run() {

	for (int i = 0; i < 20; i++) {
		events[i] = false;
	}
	getEvent(events);

	
	if (events[0]) {
		Serial.println(F("LAUNCH_GAME_HIGH_SCORE"));
		return LAUNCH_GAME_HIGH_SCORE;
	}
	else if (events[10]) {
		Serial.println(F("LAUNCH_GAME_VERSUS"));
		return LAUNCH_GAME_VERSUS;
	}
	else return RUN;
}

void StageMenu::launch() {
	animation_0();
	pgameboard->on_light(0);
	pgameboard->on_light(10);
	pgameboard->afficher_menu();
}
