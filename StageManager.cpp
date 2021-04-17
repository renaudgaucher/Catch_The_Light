#include "StageManager.h"
#include "StageMenu.h"
#include "StageGameHighScore.h"
#include "StageGameVersus.h"

#include "Random.h"

StageManager::StageManager() :gameboard()
{
}

void StageManager::init() {
	gameboard.init();
	pMenu = new StageMenu(&gameboard);
	currentStage = MENU;
}

void StageManager::run() {
	byte etatStage;
	if (currentStage == MENU) {
		etatStage = pMenu->run();
	}
	else if (currentStage == GAME) {
		etatStage = pGame->run();
	}


	if (etatStage == RUN || etatStage == PAUSE) {
		//on ne fait rien
	}
	else if (etatStage == EXIT) {
		backToMenu();
	}
	else if (etatStage == LAUNCH_GAME_HIGH_SCORE) {
		launchHighScore();
	}
	else if (etatStage == LAUNCH_GAME_VERSUS) {
		launchVersus();
	}
	else {
		Serial.println(F("STAGEMANAGER ERROR")); 
	}
}

void StageManager::backToMenu() {
	delete pGame;
	pGame = NULL;
	currentStage = MENU;
}
void StageManager::launchVersus() {
	pGame = new StageGameVersus(&gameboard);
	currentStage = GAME;
	randomSeed(getSeed());
	gameboard.off_all_lights();
}
void StageManager::launchHighScore() {
	pGame = new StageGameHighScore(&gameboard);
	currentStage = GAME;
	randomSeed(getSeed());
	gameboard.off_all_lights();
}