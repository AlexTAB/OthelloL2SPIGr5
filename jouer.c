#include "jouer.h"

int jouer_case_direction (struct Partie* partie, struct Vector coord, struct Vector dir) {
	int i;
	if(coup_possible_direction(*partie, coord, dir)) { // Si le coup est possible dans cette direction
		/* Cette boucle sert a iterer sur toutes les cases dans une certaine direction.
		 * Pour ce faire, on teste la case (coord + dir*i), ou coord est la case de d�part (celle ou on joue le coup), et dir est la direction souhait�e.
		 * Ainsi si dir vaut (0; -1), alors son testeras les cases (0; -1), (0; -2), (0; -3), etc ...
		 * La boucle continue tant que la case test�e n'appartien pas aujoueur courant.
		 * La fonction coup_possible_direction aura pr�alablement v�rifi� que le coup est valide, et donc que la direction se termine par une case appartenant au joueur courant. */
			for(i = 1; partie->plateau[coord.X + dir.X*i][coord.Y + dir.Y*i] != partie->nextPlayer;i++) {
				partie->plateau[coord.X + dir.X*i][coord.Y + dir.Y*i] = partie->nextPlayer; // On donne alors la case courante au jouer en cours
				partie->pions[playerPion(nextPlayer(partie->nextPlayer))]--; // Et on change les nombres de pions en cons�quence
				partie->pions[playerPion(partie->nextPlayer)]++;
			}
		return 1; // La fonction retourne 1 si le coup �tait possible, et 0 sinon.
	}
	return 0;
}

void jouer_case (struct Partie* partie, struct Vector coord) {
	int i, j, compt = 0;
	for(i = -1; i <= 1; i++) // Teste toutes les 9 directions possibles
		for(j = -1; j <= 1; j++)
			if(i != 0 || j != 0) { // Elimine la case en cours
				struct Vector dir; // Cr�e un vecteur a partir de la direction en cours
				dir.X = i;
				dir.Y = j;
				compt += jouer_case_direction(partie, coord, dir); // Incr�mente le compteur de directions jou�es de la valeur deretour de jouer_case_direction
			}
	if(compt > 0) { // Si une direction au moins �tait valide, et donc que le coup a �t� jou�
		partie->plateau[coord.X][coord.Y] = partie->nextPlayer; // Donne la case a jouer au joueur courant
		partie->pions[playerPion(partie->nextPlayer)]++; // Incr�mente son nombre de pions.
	}

}

void jouer(struct Partie* partie) {
	char col;
	struct Vector coord;

	if(partie->nextPlayer == 1)
		printf("C'est aux noirs de jouer.\n");
	else
		printf("C'est aux blancs de jouer.\n");

	
	do {
		do {
			fflush(stdin);
			printf("Entrez la ligne sur laquelle vous voulez jouer : ");
			scanf("%d", &coord.X);
			coord.X -= 1;
		} while(coord.X < -1 || coord.X >= 8); // V�rification de la validit� des entr�e du joueur (0 <= X <= 7)
		do {
			fflush(stdin); // Le fflush est ici tr�s important car sinon le caract�re de retour a la ligne entr� pr�c�demment sera captur� par le scanf.
			printf("Entrez la colonne sur laquelle vous voulez jouer : ");
			scanf("%c", &col);
			coord.Y = col - 'a';
		} while((coord.Y < 0 || coord.Y >= 8) && coord.Y != 'x' - 'a'); // V�rification de la validit� des entr�e du joueur (1 <= Y <= 7 ou Y = 'x')
	} while(coup_possible(*partie, coord) != 1 && (coord.X != -1 || coord.Y != 'x' - 'a')); // V�rifie que le coup demand� par le jouer est possible
	
	if(coord.X == -1 && coord.Y + 'a' == 'x') { // Si le joueur a demand� une sauvegard
		sauvegarde_fichier(*partie); // Enregistre la partie
		partie->fini = 1; // Et marque le jeu comme fini
	} else
		jouer_case(partie, coord); // Sinon, joue la case demand�e par le joueur
}
