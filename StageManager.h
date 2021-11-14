#ifndef DEF_STAGEMANAGER
#define DEF_STAGEMANAGER
/*
 * Class englobant tout : gere la transition entre les scenes (=mode de jeu, menu, etc)
 */

enum {MENU, GAME};


#include "Gameboard.h"
#include "Stage.h"
#include "StageMenu.h"

class StageManager{
  public: //private
    Gameboard gameboard;
    // 2 stages enregistres : le menu, et le jeu en cours || On enregistre sous forme de pointeur pour permettre le polymorphisme
    StageMenu* pMenu;
    Stage* pGame; 
    bool currentStage; // doit avoir la valeur MENU ou GAME
    
  public:
    StageManager(); //constructeur
    ~StageManager(); //destructeur
    void run(); //fait tourner le .run() du Stage, recupere son etat et change de stage en cours si besoin
    void init(); //Initialise le StageManager et le Menu
    void backToMenu();
    void launchVersus();
    void launchHighScore();
};


#endif
