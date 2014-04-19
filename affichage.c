#include "affichage.h"

void initialise (struct Partie* partie) {
	int i, j;
	for(i = 0; i < 8; i++) // Initialse les cases du tableau a 0
		for(j = 0; j < 8; j++)
			if((i == 3 && j == 3) || (i == 4 && j == 4)) // Sauf les cases centrales
				partie->plateau[i][j] = 2;
			else if((i == 4 && j == 3) || (i == 3 && j == 4))
				partie->plateau[i][j] = 1;
			else
				partie->plateau[i][j] = 0;
	partie->nextPlayer = 1; // Le premier a jouer est le jouer blanc
	partie->pions[0] = 2; // Les deux jouers commencent avec 2 pions
	partie->pions[1] = 2;
	partie->fini = 0; // La partie n'est evidemment pas finie
	partie->role_ordi = 0; // Et le role et le mode de l'ordinateur ne sont pas définis
	partie->mode_ordi = 0;
}

void affiche_plateau (struct Partie partie) {
	int i, j;
	char lettres[] = {' ', 'N', 'B'}; // Ce tableau sert a faire correspondre la valeur d'une case (0, 1 ou 2) a un caractère (une espace, N ou B)
	printf("\n"); // Retour a la ligne
	for(i = 'a'; i <= 'h'; i++)
		printf("     %c  ", i); // Affiche les lettres en haut des colonnes
	printf("\n\n"); // Double saut de ligne
	for(i = 0; i < 8; i++) { // Pour chaque ligne
		for(j = 0; j <33; j++) // Affiche une premiere rangée d'étoiles
			printf(" *");
		printf("\n");
		for(j = 0; j < 9; j++) // Puis une seconde rangée, plus espacées
			printf(" *      ");
		printf("\n");
		for(j = 0; j < 8; j++) // Puis une troisième rangée avec les valeurs des cases
			printf(" *   %c  ", lettres[partie.plateau[i][j]]);
		printf(" *      %d\n", i + 1); // Affiche le numéro de l ligne a la fin
		for(j = 0; j < 9; j++) // Et enfin une dernière rangée espacée
			printf(" *      ");
		printf("\n");
	}
	for(j = 0; j <33; j++) // Ajoute une dernière rangée d'étoiles pour clore le tableau
		printf(" *");
	printf("\n");
}

void affiche_nombre_pions (struct Partie partie) {
	printf("Nombre de pions noirs : %d\nNombre de pions blancs : %d\n", partie.pions[0], partie.pions[1]); // Affiche simplement le nombre de pions
}

void affiche (struct Partie partie) {
	system("CLS"); // Efface l'écran
	affiche_plateau(partie); // Et appelle les deux fonctions d'affichage
	affiche_nombre_pions(partie);
}