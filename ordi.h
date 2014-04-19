#ifndef ORDI_H
#define ORDI_H

#include "Partie.h" // Informations de partie
#include "possible.h" // Test de possibilit� d'un coup
#include "jouer.h" // Mise en application d'un coup
#include <time.h> // G�n�ration de nombres al�atoires

void jouer_ordi_alea (struct Partie* partie); // Laisse l'ordinateur jouer un coup al�atoire
void jouer_ordi_glouton (struct Partie* partie); // Laisse l'ordinateur jouer un coup de mani�re gloutonne

#endif