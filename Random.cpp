// 
// Permet de générer de l'aléatoire.
// 

#include "Random.h"


byte getSeed()
{
  byte seed = 0;
  byte i = 8;
  while (i > 0) {
    byte firstBit = analogRead(A0) & 0x01;
    byte secondBit = analogRead(A0) & 0x01;
    if (firstBit != secondBit) {
      seed = (seed << 1) | firstBit;
      i--;
    }
  }
  return seed;
}