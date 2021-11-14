#include "Stage.h"

Stage::Stage(Gameboard* gameboard) {
	this->pgameboard = gameboard;
	timer_animation = millis();
}



void Stage::getEvent(bool events[]) {	
	for (byte button = 0; button < 20; button++) {
		if (pgameboard->risingEdge(button)) {
			events[button] = true;
			Serial.println(F("button!"));
		}
	}
}

byte Stage::run() {
	return EXIT;
}

void Stage::animation_defilement()
{
	for (byte i = 0; i < 10; i++) {
		delay(delai_animation);
		
		pgameboard->toggle_light(i);
		pgameboard->toggle_light(i + 10);
	}
}

void Stage::animation_defilement_2() {
	for (byte i = 0; i < 10; i++) {
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

void Stage::animation_0() {
	pgameboard->off_all_lights();
	animation_defilement();
	animation_toggle_all();
	animation_toggle_all();
	animation_defilement();
	animation_toggle_all();
	animation_toggle_all();
	pgameboard->off_all_lights();
}

void Stage::animationPause() {
	pgameboard->off_all_lights();
	animation_defilement();
	animation_defilement();
	animation_toggle_all();
	animation_toggle_all();
	pgameboard->off_all_lights();
}

Stage::~Stage()
{
	pgameboard = NULL; //On ne détruit pas le Gameboard : celui-ci est toujours stocké dans le StageManager
}