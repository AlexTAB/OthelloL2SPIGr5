#ifndef POSSIBLE_H
#define POSSIBLE_H

#include "Partie.h" // Informations de partie
#include "Vector.h" // Utilis� pour transmettre des coordonn�es et des directions

int coup_possible_direction(struct Partie partie, struct Vector coord, struct Vector dir); // Un coup est il possible pour le joueur courant � partir d'une certaine case et dans une certaine directions
int coup_possible (struct Partie partie, struct Vector coord); // Un coup est il possible pour le joueur courant � partir d'une certaine case
int possible (struct Partie partie); // Un coup est il possible pour le joueur courant

#endif

