#ifndef DEF_STAGE
#define DEF_STAGE

#define DELAI_ANIMATION 100 //Le delai entre chaque toogle de light au sein des animations

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
	void getEvent(bool events[]); //recupere les boutons presses en fonction de ce qui nous interresse
	bool events[20] = { false }; // là on on les stocke

	void animation_defilement(); // toggle toutes les lights une part une
	void animation_toggle_all();// toggle toutes les lights en même temps, avec un delai depuis la derniere animation
	void animation_defilement_2();

public:
	//byte state=EXIT; //Etat du Stage : au choix RUN / EXIT / LAUNCH_GAME_HIGH_SCORE / LAUNCH_GAME_VERSUS

	Stage(Gameboard* pgameboard);
	virtual ~Stage();
	virtual byte run(); //appellee par le StageManager quand le stage commence. Renvoie L'etat du Stage. En fonction de cet Etat le StageManager ferme le Stage, en lance un autre ou non.
	
	void animation_0(); //animation de base
	void animationPause();//un autre animation

};


#endif
