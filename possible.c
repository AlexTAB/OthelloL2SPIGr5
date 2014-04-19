#include "possible.h"

int coup_possible_direction(struct Partie partie, struct Vector coord, struct Vector dir) {
	int i, encadre = 0;
	

	// Part de la case coord et itère sur toutes les cases dans la direction dir jusqu'a rencontrer le bord du plateau
	for(i = 1; (coord.X + dir.X*i) >= 0 && (coord.X + dir.X*i) < 8 && (coord.Y + dir.Y*i) >= 0 && (coord.Y + dir.Y*i) < 8; i++) {
		if(partie.plateau[coord.X + dir.X*i][coord.Y + dir.Y*i] == 0) { // Si on arrive sur une case vide, alors les pions ne sont pas encadrés
			return 0;
		} else if(partie.plateau[coord.X + dir.X*i][coord.Y + dir.Y*i] == partie.nextPlayer && i > 1) { // En revanche, si on arrive sur une case apprtenant au joueur en cours (et qu'il y a au moins une case entr les deux), alors les pions sont encadrés
			encadre = 1;
			break;
		}
	}

	// Si les pions sont encadrés, que la case actuelle est vide et que les coordonées se trouvent entre 0 et 8, alors le coup est possible
	return (encadre && (partie.plateau[coord.X][coord.Y] == 0) && (coord.X + dir.X >= 0) && (coord.X + dir.X < 8) && (coord.Y + dir.Y >= 0) && (coord.Y + dir.Y < 8));
}

int coup_possible (struct Partie partie, struct Vector coord) {
	int i, j;
	for(i = -1; i <= 1; i++) { // Itère sur les neuf cases voisines de la case a tester
		for(j = -1; j <= 1; j++) {
			if(i != 0 || j != 0) { // Elimine la case elle même
				struct Vector dir; // Construit un vecteur a partir de la direction a tester
				dir.X = i;
				dir.Y = j;
				if(coup_possible_direction(partie, coord, dir))
					return 1; // Si le coup est possible dans cette direction, alors le coup est tout simplement possible
			}
		}
	}
	return 0; // En revanche si après avoir vérifié toutes les directions aucune n'est valide, alors le coup n'est pas possible
}

int possible (struct Partie partie) {
	int i, j;
	for(i = 0; i < 8; i++) // Teste toutes les cases du plateau
		for(j = 0; j < 8; j++) {
			struct Vector coord;
			coord.X = i;
			coord.Y = j;
			if(coup_possible(partie, coord)) // Si au moins une case peux être jouée, alors le joueur courant peux jouer
				return 1;
		}
	return 0; // Sinon, il doit passer son tour
}