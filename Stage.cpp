#include "Stage.h"

Stage::Stage(Gameboard* gameboard) {
	this->pgameboard = gameboard;
	timer_animation = millis();
}



void Stage::getEvent() {
	
	for (byte button = 0; button < 20; button++) {
		events[button] = pgameboard->risingEdge(button);
	}
}

byte Stage::run() {
	return EXIT;
}

void Stage::animation_defilement()
{
	for (byte i = 0; i < 1; i++) {
		delay(delai_animation);
		
		pgameboard->toggle_light(i);
		pgameboard->toggle_light(i + 10);
	}
}

void Stage::animation_toggle_all()
{
	delay(delai_animation);
	pgameboard->toggle_all_lights();
}
