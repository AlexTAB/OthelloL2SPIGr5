#include "ordi.h"
#include "Debug.h"

void jouer_ordi_alea(struct Partie* partie) {
	int i, j, k = 0; // i et j sont des itérateurs, mais k contiens le nombre de cases valides trouvées
	struct Vector possible [(8 * 8) - 4]; // Le tableau possible est un tableau de vecteur contenant les coordonnées des cases sur lesquelles il est possible de jouer. Il contient autant de valeur qu'il y a ce cases sur le plateau, moins les 4 déjà attribuées au départ.

	srand(time(NULL)); // Initialise la fonction aléatoire

	for(i = 0; i < 8; i++) // Pour chaque case du plateau
		for(j = 0; j < 8; j++) {
			struct Vector coord; // Construit un vecteur a partir des coordonnées en cours
			coord.X = i;
			coord.Y = j;
			if(coup_possible(*partie, coord)) { // Si le coup est possible sur cette case
				possible[k] = coord; // Ajoute cette case au tableau
				k++; // Et incrémente le nombre de cases validées
			}
		}

	jouer_case(partie, possible[rand()%k]); // Joue aléatoirement une des coordonnées du tableau, à un index situé entre 0 et k
}

int note(struct Partie* partie, struct Vector coord) { // Cette fonction attirube une note a une case
	if(coup_possible(*partie, coord)) { // Si il est possible de jouer sur cette case
		struct Partie copie = *partie; // Effectue uen copie de la partie en cours
		jouer_case(&copie, coord); // Joue la case dans la partie copiée
		return copie.pions[partie->nextPlayer] - partie->pions[partie->nextPlayer]; // Et renvoie la différence de scores pour le jouer actuel entre la partie en cours et la copie
	} else
		return 0; // Si le coup n'est pas possible, alors la note est de 0
}

void jouer_ordi_glouton(struct Partie* partie) {
	int i, j, maxVal = 0;
	struct Vector maxCoord; // maxCoord sert a stocker les coordonnées de la case ayant obtenu la plus haute note.

	maxCoord.X = -1;
	maxCoord.Y = -1;

	for(i = 0; i < 8; i++) // Pour chacune des cases du plateau
		for(j = 0; j < 8; j++) {
			struct Vector coord; // Construit un vecteur a partir des coordonnées en cours
			int tempVal;

			coord.X = i;
			coord.Y = j;

			tempVal = note(partie, coord); // tempVal vaut la note de la case en cours

			if(tempVal > maxVal) { // si tempVal est supérieur a la note maximum connue
				maxCoord = coord; // Alors les coordnées actuelles sont les nouvelels coordonnées maximales
				maxVal = tempVal; // Idem pour la note
			}
		}

	jouer_case(partie, maxCoord); // Joue la case ayant obtenue la meilleure note
}


