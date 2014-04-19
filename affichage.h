#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <stdlib.h> // Appel a la fonction system
#include <stdio.h> // Appelle a printf
#include "Partie.h" // Structure d'une partie

void initialise (struct Partie* partie); // Initialise une nouvelle partie
void affiche_plateau (struct Partie partie); // Affiche le plateau
void affiche_nombre_pions (struct Partie partie); // Affiche le nombre de pions de chaque joueur
void affiche (struct Partie partie); // Appelle les deux fonctions d'affichage


#endif