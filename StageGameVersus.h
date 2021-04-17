#ifndef DEF_STAGEGAMEVERSUS
#define DEF_STAGEGAMEVERSUS


#include "Stage.h"

//Class g�rant le jeu 1vs 1: deux lumi�res allum�es, en miroir, une dans chaque camp. quand on appuie dessus les deux lumi�res allum�es changent, on gagne des points
//Si on a juste, on en perd sinon

class StageGameVersus : public Stage
{
public:
	StageGameVersus(Gameboard* gameboard);
	virtual byte run();
private:
	int score1 = 0;
	int score2 = 0;
	unsigned long timeBegin; //correspond au temps initiant la s�quence actuelle : au d�but d'une PAUSE, d'un RUN, etc, il doit �tre maj
	unsigned long roundDuration;
	unsigned long pauseDuration;
	byte currentRound = 0; // le round en cours, quand on atteint max round on s'arrete
	byte maxRound;

	byte gameState;

	byte lightOn; // Correspond � la light actuellement allum�e (entre 0 et 9): si les joueurs tapent sur une autre light, ils perdent des points, sinon ils en gagnent et la light change.

	void runRound(); //appel�e dans run pour faire tourner le jeu
	void runPause(); //idem mais pause entre les parties

	void handleEvents(); //g�re les touches tapes : si c'est la bonne ajoute des ponts et appelle changeLight, sinon retire des points
	void changeLight(); //a appeler lorsque une light a ete pressee : l'eteint et allume une autre light
	void printScore(); // affiche le score des joueurs

	void animationPause(); //a lancer en meme temps que la pause : petit jeu de lumieres
};


#endif
