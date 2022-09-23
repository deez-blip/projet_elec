#
# Projet elec

## Le projet est un jeu qui est un mic entre un **morpion** et un **puissance 4**.

* Les regles sont donc simple :
    * Les joueurs jouent chacun leur tour, et pour ce faire ils peuvent utiliser le joystick pour deplacer le pointeur bleu et le bouton pour choisir la case à mettre de leur couleur, quand un joueur a *posé* sa case, le tour passe au joueur suivant.
    * Comme pour un morpion, *à la difference que les ronds et les croix sont remplacé par des couleurs*, le premier joueur à avoir un alignement de 3 couleurs (diagonales comprises) gagne la partie.
#

## Fonctionnement joystick
Le bouton est composé de 5 branche, mais pour mon projet je n'en ai utilisé que 4.
* Les branches VCC et GND
* Une branche pour l'axe "x" qui donne une valeur entre 0 et 1023 (d'ou l'utilisation de l'analog, en l'occurence le A0 et A1)
* Une branche pour l'axe "y" qui donne aussi une valeur entre 0 et 1023

## Fonctionnement bouton
Le bouton est composé de 4 branche mais 3 sont utilisé :
* Une branche relier au VCC, et celle dans son alignement n'est pas branché
* Une branche liée au GND, avec celle dans son alignement qui est liée au un pin digital (dans notre cas le 10). Quand le bouton est cliqué il renvoie 1 jusqu'à qu'il soit relaché, dans ce cas il renvoie 0.

## Fonctionnement matrice de LED
Pour utiliser la matrice de LED je me suis servi de la librairie **Adafruit_NeoPixel.h**. Dans un premier temps j'ai donc defini le pin digital qui était relié (ici le 6). Puis j'ai branché la matrice avec les port VCC et GND. J'ai aussi defini le nombre de LED, et donc le nombre de pixel, qui compose la matrice, dans notre cas 64. 

Chaque LED posede une "position" dans la matrice, de ce fait la 1ere est a la position 0 et la derniere a la position 63.

Pour savoir quelle LED devait etre à quelle moment il nous suffisait donc d'inquer son numéro dans la matrice.

Ainsi, grace à la fonction Convert(), qui prend un parametre x et un parametre y, j'ai pu cadriller la matrice et recuperer la position actuel du pointeur grace a un fonction : f(x) = x + 8*y.

La postion de chaque LED etant defini et la position du(des) joueur(s) maintenant connu, je n'avais plus qu'à utiliser les fonctions de la librairie **Adafruit_NeoPixel.h** et d'algorithme pour réaliser mon projet. 

*(Pour plus d'info sur le code voir les commentaires dans le fichier)*
