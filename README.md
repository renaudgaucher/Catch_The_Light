# Catch-The-Light
Jeu implémenté dans une arduino MEGA pour créer une borne d'arcade dans la salle d'arcade de l'école Polytechnique

Le programme fonctionne comme suit : 


Une class Gameboard permet de contrôler tout le hardware (i.e lights, buttons & display)

Une class StageManager est l'enveloppe du programme, celui ci enregistre une instance du GameBoard et le fait interagir avec les Stage (=mode de jeu). Une variable permet de savoir quel est le stage actuellement en cours, s'il faut en lancer un autre ou repasser au menu.

Les class StageMenu, StageGameVersus et Stage GameHightScore héritent de Stage, leur nom est explicite

POUR FAIRE PLUS PROPREMENT :
Ici les Stage "empruntent" le gameboard au StageManager, ce qui est d'une propreté douteuse. Dans un autre projet, on pourrait créer un gestionnaire d'événements : à chaque boucle le Stage enverrait les event au Stage en cours, puis récupérerait les actions à effectuer en les envoyant au gameboard. 


INSTALLATION:

Pour les connections avec l'arduino, il faut respecter les règles suivantes:
-On connecte toujours la light sur une pin paire, et un bouton sur un pin impair (donc par exemple, on connecte le Lightbouton 1 du J1 en mettant la lumière sur 2 et le bouton sur 3)
-les pins dédiés au joueur 1 sont de 2 à 9, puis de 22 à 33

-les pins dédiés au joueur 2 sont de 34 à 53

-on connecte le reste des cables des lumières et des boutons au GND (ground)

-Les display (matrices) se connectent en dérivation avec les ports SDA et SCL, le GND avec le GND, et les +5V et V_10 avec le +5V

-il faut laisser le pin analogique A0 libre (pour la génération de nombre aléatoire)



PROJET FAISABLE MAIS NON IMPLEMENTE:
-Ajout d'un high-score (en utilisant une EEPROM - il y en a dans l'atelier)

-Modifier le Game design des mods de jeux déjà présents (ajuster les animations, les scores, etc.)

-Ajouter des mods de jeu

-Ajout d'un gestionnaire de son (carte son déjà achetée, à voir pour l'ampli et le haut-parleur).
