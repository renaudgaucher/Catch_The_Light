#ifndef DEF_STAGE
#define DEF_STAGE

#define DELAI_ANIMATION 50 //Le delai entre chaque toogle de light au sein des animations

enum {RUN, EXIT, LAUNCH_GAME_HIGH_SCORE, LAUNCH_GAME_VERSUS, PAUSE};

#include "Gameboard.h"

/*
	Class correspondant à une scène ( ou plutôt un acte )  de théâtre ( scène du menu, scène de jeu, scène de chargement un peu une entre-scène, etc
	Ici est fait l'interaction entre les evenement geres par le Gameboard et le jeu en question.
*/

class Stage {
private:
	unsigned long timer_animation;
	unsigned long delai_animation = DELAI_ANIMATION; //le delai entre chaque toggle de light au sein des animations
protected:
	Gameboard* pgameboard; //le tableau de jeu de Stage est celui de StageManager, il lui est donnee en argument en constructeur.
	virtual void getEvent(); //recupere les boutons presses en fonction de ce qui nous interresse
	bool events[20] = { 0 }; // là on on les stocke

	void animation_defilement(); // toggle toutes les lights une part une
	void animation_toggle_all();// toggle toutes les lights en même temps, avec un delai depuis la derniere animation
public:
	//byte state=EXIT; //Etat du Stage : au choix RUN / EXIT / LAUNCH_GAME_HIGH_SCORE / LAUNCH_GAME_VERSUS

	Stage(Gameboard* pgameboard);
	virtual byte run(); //appellee par le StageManager quand le stage commence. Renvoie L'etat du Stage. En fonction de cet Etat le StageManager ferme le Stage, en lance un autre ou non.
	


};


#endif
