// Random.h

//Il faut laisser libre A0 

#ifndef _RANDOM_h
#define _RANDOM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

byte getSeed(); // retourne une Seed aleatoire: change a chaque debut de partie

#endif

