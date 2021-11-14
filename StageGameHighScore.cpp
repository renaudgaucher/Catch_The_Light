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

StageGameHighScore::~StageGameHighScore() {
	//pas important
}

byte StageGameHighScore::run() {
	
	for (int i = 0; i < 20; i++) {
		events[i] = false;
	}
	getEvent(events);

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
	handleLights();
	
	if (gameOverJ1 && gameOverJ2) {
		animation_0();
		gameState = EXIT;
		return ;
	}

	if (currentTime > timeBegin + roundDuration) {
		Serial.println(F("Pause"));
		currentRound++;
		gameState = PAUSE;
		timeBegin = millis();
		nbLightsOnJ1 = 0;
		nbLightsOnJ2 = 0;

		pgameboard->off_all_lights();
		animationPause();
	}
}

void StageGameHighScore::runPause() {
	unsigned long currentTime = millis();
	if (currentTime > timeBegin + pauseDuration) {
		gameState = RUN;
		timeBegin = millis();
		light_delay_round = light_delay_round_base / sqrt(currentRound);
		Serial.println(F("RUN"));
		Serial.println(light_delay_round);
		for (int light = 0; light < 20; light++) {
			lightsOn[light] = false;
		}
		animationPause();
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

void StageGameHighScore::handleLights() {


	unsigned long currentTime = millis();

	if (currentTime > timer_light_round + light_delay_round) {

		timer_light_round = millis();
		newLight();

		if (!gameOverJ1 && nbLightsOnJ1 >= 7) {
			gameOverJ1 = true;
		}
		if (!gameOverJ2 && nbLightsOnJ2 >= 7) {
			gameOverJ2 = true;
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


void StageGameHighScore::shutDownLight(byte light) {
	pgameboard->off_light(light);
	lightsOn[light] = false;
}

void StageGameHighScore::printScore() { //doublon avec GV
	pgameboard->afficher_score(1, score1);
	pgameboard->afficher_score(2, score2);
}
