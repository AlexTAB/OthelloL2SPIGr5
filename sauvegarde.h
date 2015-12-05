#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H

#include "Partie.h" // Informations de partie
#include <stdio.h> // Accès aux fichiers

void sauvegarde_fichier(struct Partie partie); // Effectue une sauvegarde
void initialise_fichier(struct Partie* partie); // Charge une sauvegarde

#endif