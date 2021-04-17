# Catch_The_Light
Jeu implémenté dans une arduino MEGA pour créer une borne d'arcade dans la salle d'arcade de l'école Polytechnique

Le programme fonctionne comme suit : 

Une class Gameboard permet de contrôler tout le hardware (i.e lights, buttons & display)
Une class StageManager est l'enveloppe du programme, en son sein défilent des stages qui correspondent à des scènes du pièces de théatre. Typiquement un menu puis une partie.
Les class StageMenu, StageGameVersus et Stage GameHightScore héritent de Stage, leur nom est explicite

INSTALLATION:

Pour les connections avec l'arduino, il faut respecter les règles suivantes:
-On connecte toujours la light sur une pin paire, et un bouton sur un pin impair (donc par exemple, on connecte le Lightbouton 1 du J1 en mettant la lumière sur 2 et le bouton sur 3)
-les pins dédiés au joueur 1 sont de 2 à 9, puis de 22 à 33
-les pins dédiés au joueur 2 sont de 34 à 53
-on connecte le reste des cables des lumières et des boutons au GND (ground)
-Les display (matrices) se connectent en dérivation avec les ports SDA et SCL, le GND avec le GND, et les +5V et V_10 avec le +5V
-il faut laisser le pin analogique A0 libre (pour la génération de nombre aléatoire)

TODO minimal:
-Menu RAS
-finir les modes de jeu, ajuster les durées des parties


PROJET FAISABLE MAIS NON IMPLEMENTE:
-Ajout d'un high-score (en utilisant la EEPROM déjà présente)
-Ajout d'un gestionnaire de son (carte son déjà achetée, ainsi que de (trop) petits haut-parleur. Il faudrait plus de branchement pour utiliser un ampli)
