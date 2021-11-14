#include "StageGameVersus.h"



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

StageGameVersus::~StageGameVersus()
{
	//a Remplir pour plus propre mais pas important
}

byte StageGameVersus::run() {
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
			animation_0();
			gameState = EXIT;
			Serial.println("gameState=EXIT");
		}
	}

}

void StageGameVersus:: runPause() {
	unsigned long currentTime = millis();
	if (currentTime > timeBegin + pauseDuration) {
		gameState = RUN;
		timeBegin = millis();
		animationPause();
		changeLight();
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
	pgameboard->off_light(lightOn);
	pgameboard->off_light(lightOn+10);
	
	byte newLightOn = 0; 
	do{
		newLightOn = random(0, 10);
		Serial.println(newLightOn);
	}
	while (newLightOn == lightOn);
	lightOn = newLightOn;
	
	pgameboard->on_light(lightOn);
	pgameboard->on_light(lightOn + 10);
}

void StageGameVersus::printScore() {
	pgameboard->afficher_score(1, score1);
	pgameboard->afficher_score(2, score2);
}
