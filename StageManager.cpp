#include "StageManager.h"
#include "StageMenu.h"
#include "StageGameHighScore.h"
#include "StageGameVersus.h"

#include "Random.h"

StageManager::StageManager() :gameboard()
{
}

StageManager::~StageManager() {
	delete pMenu;
	delete pGame;
	pMenu = NULL;
	pGame = NULL;
}



void StageManager::init() {
	gameboard.init();
	pMenu = new StageMenu(&gameboard);
	backToMenu();
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
		Serial.println(F("StgMan Launching game high score"));
	}
	else if (etatStage == LAUNCH_GAME_VERSUS) {
		launchVersus();
		Serial.println(F("StgMan Launching game versus"));
	}
	else {
		Serial.println(F("STAGEMANAGER ERROR")); 
	}
}

void StageManager::backToMenu() {
	if (pGame != NULL) {
		delete pGame;
		pGame = NULL;
	}
	currentStage = MENU;
	pMenu->launch();
}

void StageManager::launchVersus() {
	gameboard.off_all_lights();
	pGame = new StageGameVersus(&gameboard);
	currentStage = GAME;
	randomSeed(getSeed());
	
}

void StageManager::launchHighScore() {
	gameboard.off_all_lights();
	pGame = new StageGameHighScore(&gameboard);
	currentStage = GAME;
	randomSeed(getSeed());
}
