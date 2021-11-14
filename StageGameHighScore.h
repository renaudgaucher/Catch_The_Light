#ifndef DEF_STAGEGAMEHIGHSCORE
#define DEF_STAGEGAMEHIGHSCORE

#define ROUND_DURATION_HS 20000
#define PAUSE_DURATION_HS 4000


#define DELAI_ROUND1_ALLUMAGE_LAMPE 500

#include "Stage.h"


/*
	Jeu où le but n'est pas de dépasser l'autre mais tout simplement de faire un high score : les deux joueurs jounet sans interaction l'un avec l'autre.
	Le jeu se déroule en un nombre indéfini de manche, à chaque manche cela va plus vite.
	les lampes du tableau du joueur s'allument les unes après les autres, le joueur doit taper dessus pour les éteindre, cela lui fait des points. (fois le round au carré
	Si toutes les lumières du board sont allumées sauf 2, le joueur perd.
	La vitesse d'allumage de la prochaine lumière suit la formule :
	delai_base / sqrt (currentRound)                ///// *(1 + (nb_light_allumees - nb_light_max)/nb_lights_max)) 
*/

class StageGameHighScore : public Stage
{
public:
	StageGameHighScore(Gameboard* gameboard);
	~StageGameHighScore();
	virtual byte run();
private:
	int score1;
	int score2;
	bool gameOverJ1;
	bool gameOverJ2;
	unsigned long timeBegin;

	
	const unsigned long roundDuration=ROUND_DURATION_HS;
	const unsigned long pauseDuration=PAUSE_DURATION_HS;
	
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
	void handleLights(); //gère le nombre de lumières allumées simultanément : si il y en a trop le joueur a perdu, sinon on rajoute un lumière
	void newLight(); //ajoute une nouvelle lumière aleatoirement aux joueurs encore en jeu
	void shutDownLight(byte light); //Eteint la lumiere light
};


#endif

