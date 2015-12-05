#ifndef JEU_H
#define JEU_H

#include "affichage.h" // Affichage du plateau
#include "jouer.h" // Actions d'un jouer sur la partie
#include "possible.h" // Test de possibilité d'un coup
#include "sauvegarde.h" // Chargement d'une partie
#include "ordi.h" // Actions d'un bot sur la partie

void jeu_deux (); // Lance un jeu a 2 joueurs
void jeu_ordi (); // Lance un jeu a 1 joueur

#endif