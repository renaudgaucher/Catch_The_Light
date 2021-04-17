#ifndef DEF_STAGEGAMEHIGHSCORE
#define DEF_STAGEGAMEHIGHSCORE

#define DELAI_INITIAL 8000
#define ROUND_DURATION 30000
#define PAUSE_DURATION 15000

#define DELAI_ROUND1_ALLUMAGE_LAMPE 1000

#include "Stage.h"



/*
	Jeu o� le but n'est pas de d�passer l'autre mais tout simplement de faire un high score : les deux joueurs jounet sans interaction l'un avec l'autre.
	Le jeu se d�roule en un nombre ind�fini de manche, � chaque manche cela va plus vite.
	les lampes du tableau du joueur s'allument les unes apr�s les autres, le joueur doit taper dessus pour les �teindre, cela lui fait des points. (fois le round au carr�
	Si toutes les limui�res du board sont allum�es sauf 2, le joueur perd.
	La vitesse d'allumage de la prochaine lumi�re suit la formule :
	delai_base / sqrt (currentRound)                ///// *(1 + (nb_light_allumees - nb_light_max)/nb_lights_max)) 
*/
class StageGameHighScore : public Stage
{
public:
	StageGameHighScore(Gameboard* gameboard);
	virtual byte run();
private:
	int score1;
	int score2;
	bool gameOverJ1;
	bool gameOverJ2;
	unsigned long timeBegin;

	
	const unsigned long roundDuration=ROUND_DURATION;
	const unsigned long pauseDuration=PAUSE_DURATION;
	
	byte currentRound = 1;
	unsigned long light_delay_round;
	const unsigned long light_delay_round_base = DELAI_ROUND1_ALLUMAGE_LAMPE;
	unsigned long timer_light_round;
	

	byte gameState;
	bool lightsOn[20] = { 0 };
	byte nbLightsOnJ1;
	byte nbLightsOnJ2;

	void runRound(); 
	void runPause();

	void handleEvents();
	void printScore();
	void handleLights(); //g�re le nombre de lumi�res allum�es simultan�ment : si il y en a trop le joueur a perdu, sinon on rajoute un lumi�re
	void newLight(); //ajoute une nouvelle lumi�re aleatoirement aux joueurs encore en jeu
	void shutDownLight(byte light); //Eteint la lumiere light

	void animationPause(); // animation classique
};


#endif

