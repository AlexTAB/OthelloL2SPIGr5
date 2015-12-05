#ifndef ORDI_H
#define ORDI_H

#include "Partie.h" // Informations de partie
#include "possible.h" // Test de possibilité d'un coup
#include "jouer.h" // Mise en application d'un coup
#include <time.h> // Génération de nombres aléatoires

void jouer_ordi_alea (struct Partie* partie); // Laisse l'ordinateur jouer un coup aléatoire
void jouer_ordi_glouton (struct Partie* partie); // Laisse l'ordinateur jouer un coup de manière gloutonne

#endif