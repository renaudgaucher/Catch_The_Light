#include "StageGameHighScore.h"


#define BONUS_SCORE_RIGHT_LIGHT 3
#define MALUS_SCORE_FALSE_LIGHT 1

StageGameHighScore::StageGameHighScore(Gameboard* gameboard) :Stage(gameboard)
{
	score1 = 0;
	score2 = 0;
	gameOverJ1 = false;
	gameOverJ2 = false;
	nbLightsOnJ1 = 0;
	nbLightsOnJ2 = 0;

	gameState = RUN;

	light_delay_round = light_delay_round_base;
	timer_light_round = millis();

	timeBegin = millis();
}

byte StageGameHighScore::run() {
	getEvent();

	if (gameState == RUN) {
		runRound();
	}
	else if (gameState == PAUSE) {
		runPause();
	}
	return gameState;
}


void StageGameHighScore::runRound() {
	unsigned long currentTime = millis();


	handleEvents();
	printScore();

	if (currentTime > timeBegin + roundDuration) {
		if (!gameOverJ1 && !gameOverJ2) {
			currentRound++;
			gameState = PAUSE;
			timeBegin = millis();
			nbLightsOnJ1 = 0;
			nbLightsOnJ2 = 0;
			animationPause();
		}
		else {
			gameState = EXIT;
		}
	}

	handleLights();
}

void StageGameHighScore::runPause() {
	unsigned long currentTime = millis();
	if (currentTime > timeBegin + pauseDuration) {
		animationPause();
		gameState = RUN;
		timeBegin = millis();
		light_delay_round = light_delay_round_base / sqrt(currentRound);
	}
}

void StageGameHighScore::handleEvents() {
	for (byte i = 0; i < 10; i++) {
		if (!gameOverJ1 && events[i]) {
			if (lightsOn[i]) {
				shutDownLight(i);
				score1 += BONUS_SCORE_RIGHT_LIGHT;
				nbLightsOnJ1--;
			}
			else {
				score1 -= MALUS_SCORE_FALSE_LIGHT;
			}
		}
		if (!gameOverJ2 && events[i + 10]) {
			if (lightsOn[i+10]) {
				shutDownLight(i + 10);
				score2 += BONUS_SCORE_RIGHT_LIGHT;
				nbLightsOnJ2--;
			}
			else {
				score2 -= MALUS_SCORE_FALSE_LIGHT;
			}
		}
	}
}

void StageGameHighScore::newLight() {
	if (!gameOverJ1) {
		byte newLightOn = 0;
		do {
			newLightOn = random(0, 10);
		} while (lightsOn[newLightOn]);
		lightsOn[newLightOn] = true;
		nbLightsOnJ1++;
		pgameboard->on_light(newLightOn);
	}
	
	if (!gameOverJ2) {
		byte newLightOn = 0;
		do {
			newLightOn = random(10, 20);
		} while (lightsOn[newLightOn]);
		lightsOn[newLightOn] = true;
		nbLightsOnJ2++;
		pgameboard->on_light(newLightOn);
	}
}

void StageGameHighScore::handleLights() {
	unsigned long currentTime = millis();

	if (currentTime > timer_light_round + light_delay_round) {
		newLight();
		if (!gameOverJ1 && nbLightsOnJ1 >= 9) {
			gameOverJ1 = true;
		}
		if (!gameOverJ2 && nbLightsOnJ2 >= 9) {
			gameOverJ2 = true;
		}
	}

}

void StageGameHighScore::shutDownLight(byte light) {
	pgameboard->off_light(light);
}

void StageGameHighScore::printScore() { //doublon avec GV
	pgameboard->afficher_score(1, score1);
	pgameboard->afficher_score(2, score2);
}

void StageGameHighScore::animationPause() { //doubloin avec GameVersus
	pgameboard->off_all_lights();
	animation_defilement();
	animation_defilement();
	animation_toggle_all();
	animation_toggle_all();
	pgameboard->off_all_lights();
}