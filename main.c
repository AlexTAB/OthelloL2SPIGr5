#include "jeu.h"

int main () {
	int replay = 0, mode = 0;
	do {

		do {
			printf("Voulez vous jouer contre l'ordinateur (1) ou a 2 joueurs (2) ? "); // Choix du mode de jeu
			scanf("%d", &mode);
		} while(mode != 1 && mode != 2); // Vérification de la validité de l'entrée du joueur

		if(mode == 2) // Appel de la fonction correspondante
			jeu_deux();
		else
			jeu_ordi();

		fflush(stdin);
		printf("Voulez vous rejouer (o/n) ? "); // Propose au joueur de creer un nouvelle partie
		scanf("%c", &replay);

		if(replay == 'o')
			replay = 1;
		else
			replay = 0;

	} while(replay); // Tant que le joueur veux continuer a jouer
	return 0;
}