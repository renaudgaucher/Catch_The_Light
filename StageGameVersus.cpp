#include "StageGameVersus.h"

#define ROUNDDURATION 45000 //45s jeu + 15s pause * 3 par partie
#define PAUSEDURATION 15000
#define NUMBER_OF_ROUND 3

#define BONUS_SCORE_RIGHT_LIGHT 3
#define MALUS_SCORE_FALSE_LIGHT 1

StageGameVersus::StageGameVersus(Gameboard* gameboard) :Stage(gameboard)
{
	roundDuration = ROUNDDURATION;
	pauseDuration = PAUSEDURATION;
	maxRound = NUMBER_OF_ROUND;
	gameState = RUN;
	
	lightOn = 0;
	changeLight();
	
	timeBegin = millis();
}

byte StageGameVersus::run() {
	getEvent();

	if (gameState == RUN) {
		runRound();
	}
	else if (gameState == PAUSE) {
		runPause();
	}
	return gameState;
}

void StageGameVersus::runRound() {
	unsigned long currentTime = millis();

	handleEvents();
	printScore();

	if (currentTime > timeBegin + roundDuration) {
		if (currentRound < maxRound) {
			currentRound++;
			gameState = PAUSE;
			timeBegin = millis();
			animationPause();
		}
		else {
			gameState = EXIT;
		}
	}
}

void StageGameVersus:: runPause() {
	unsigned long currentTime = millis();
	if (currentTime > timeBegin + pauseDuration) {
		gameState = RUN;
		timeBegin = millis();
	}
}

void StageGameVersus::handleEvents() {
	for (byte i = 0; i < 10; i++) {
		if (events[i]) {
			if (lightOn == i) {
				changeLight();
				score1 += BONUS_SCORE_RIGHT_LIGHT;
			}
			else {
				score1 -= MALUS_SCORE_FALSE_LIGHT;
			}
		}
		if (events[i + 10]) {
			if (lightOn == i) {
				changeLight();
				score2 += BONUS_SCORE_RIGHT_LIGHT;
			}
			else {
				score2 -= MALUS_SCORE_FALSE_LIGHT;
			}
		}
	}
}

void StageGameVersus::changeLight() {
	pgameboard->toggle_light(lightOn);
	pgameboard->toggle_light(lightOn+10);
	
	byte newLightOn = 0; 
	do{
		newLightOn = random(0, 10);
	}
	while (newLightOn != lightOn);
	lightOn = newLightOn;
	
	pgameboard->toggle_light(lightOn);
	pgameboard->toggle_light(lightOn + 10);
}

void StageGameVersus::printScore() {
	pgameboard->afficher_score(1, score1);
	pgameboard->afficher_score(2, score2);
}

void StageGameVersus::animationPause() {
	pgameboard->off_all_lights();
	animation_defilement();
	animation_defilement();
	animation_toggle_all();
	animation_toggle_all();
	pgameboard->off_all_lights();
}
