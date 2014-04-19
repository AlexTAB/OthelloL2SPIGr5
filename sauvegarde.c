#include "sauvegarde.h"

void sauvegarde_fichier(struct Partie partie) {
	FILE* fichier = fopen("sauvegarde", "w"); // Ouvre le fichier de sauvegarde en ecriture seule
	int i, j;

	if(fichier == NULL) // Quitte si le fichier n'a pas pu s'ouvrir
		return;

	fprintf(fichier, "%d\n%d\n%d\n", partie.nextPlayer, partie.role_ordi, partie.mode_ordi); // Enregistre les différentes variables de la partie

	for(i = 0; i< 8; i++) { // Ecrit l'état du plateau
		for(j = 0; j < 8; j++)
			fprintf(fichier, "%d", partie.plateau[i][j]);
		fprintf(fichier, "\n");
	}

	fclose(fichier); // Ferme le fichier
}

void initialise_fichier(struct Partie* partie) {
	FILE* fichier = fopen("sauvegarde", "r"); // Ouvre le fichier de sauvegarde en lecture seule
	int i = 0, j = 0;
	char curr = 0;

	if(fichier == NULL) { // Si le fichier n'a pas pu s'ouvrir, initialise une nouvelle partie
		initialise(partie);
		return;
	}

	partie->pions[0] = partie->pions[1] = 0; // Initialise le nombre de pions a 0
	partie->fini = 0; // Ainsi que l'état de la partie

	partie->nextPlayer = getc(fichier) - '0'; // Lit la valeur des différentes variables dans la sauvegarde
	getc(fichier);
	partie->role_ordi = getc(fichier) - '0';
	getc(fichier);
	partie->mode_ordi = getc(fichier) - '0';
	getc(fichier);

	do { // Puis lit la valeur du tableau
		curr = getc(fichier); // Lit un caractère
		if(curr == '\n') { // Si le caractère est un retour a la ligne, incrémente le numéro de la ligne et remet a 0 la colonne
			i++;
			j = 0;
		} else if(curr >= '0' && curr <= '2') { // Sinon, assigne la valeur lue au plateau
			partie->plateau[i][j] = curr - '0';
			if(partie->plateau[i][j] != 0) // Incrémente le nombre de pions
				partie->pions[partie->plateau[i][j]]++;
			j++; // Et la colonne
		}
	} while(curr != EOF); // Continue jusqu'a la fin du fichier

	fclose(fichier); // Et ferme le fichier
}
