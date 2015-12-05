#ifndef JOUER_H
#define JOUER_H

#include "Vector.h" // Utilisé pour transmettre des coordonnées et des directions
#include "Partie.h" // informations de partie
#include "possible.h" // Test de possibilité d'un coup
#include "sauvegarde.h" // Sauvegarde d'une partie
#include <stdio.h> // Récupération des entrées d'un joueur pour connaitre la case a jouer

int jouer_case_direction (struct Partie* partie, struct Vector coord, struct Vector dir); // Joue un coup par le joueur actuel, a partir d'une certaine case et dans une certaine direction
void jouer_case (struct Partie* partie, struct Vector coord); // Joue un coup par le joueur actuel a partir d'une certaine case
void jouer(struct Partie* partie); // Joue un coup par le joueur actuel

#endif