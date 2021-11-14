#include "Random.h"
#include "StageManager.h"




StageManager stageManager = StageManager();
int score1 = 0;
int score2 = 0;

void setup() { 
    Serial.begin(9600);
    stageManager.init();
}


void loop() {
    
    stageManager.run();


    /*
    for (int light = 0; light < 20; light++) {
    

      if (stageManager.gameboard.risingEdge(light)){
        stageManager.gameboard.toggle_light(light);
        if(light <10){
          score1++;
          stageManager.gameboard.afficher_score(1, score1);
        }
        else{
          score2++;
          stageManager.gameboard.afficher_score(2, score2);
        }
      }
    }
    */
    /*
    if (stageManager.gameboard.risingEdge(10)) {
        score1++;
        stageManager.gameboard.toggle_light(10);
        stageManager.gameboard.afficher_score(2, score1);
    }
    if (stageManager.gameboard.risingEdge(0)) {
        score2++;
        stageManager.gameboard.toggle_light(0);
        stageManager.gameboard.afficher_score(1, score2);
    }
    */
}


/*


Gameboard gameboard = Gameboard();


int score=0;

void setup() {
  Serial.begin(9600); 
  gameboard.init();
}

void loop() {

  if (gameboard.risingEdge(0)){
    score++;
    gameboard.toggle_light(0);
    gameboard.afficher_score(1,score);
    Serial.println(score);
  } 
}

*/
