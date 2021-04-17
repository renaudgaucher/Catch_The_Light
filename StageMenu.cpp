#include "StageMenu.h"
#include "StageGameHighScore.h"
#include "StageGameVersus.h"


StageMenu::StageMenu(Gameboard* gameboard) :Stage(gameboard)
{
}

byte StageMenu::run() {
	
	bool events[20] = { 0 };
	
	getEvent();
	if (events[0]) {
		return LAUNCH_GAME_HIGH_SCORE;
	}
	else if (events[10]) {
		return LAUNCH_GAME_VERSUS;
	}
	else return RUN;
}
