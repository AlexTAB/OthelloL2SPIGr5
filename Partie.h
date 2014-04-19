#ifndef PARTIE_H
#define PARTIE_H

int nextPlayer(int index); // Cette fonction sert a connaitre la valeur du joueur suivant a partir du joueur actuel
int playerPion(int index); // Cette fonction sert a connaitre l'index de partie.pions pour le joueur actuel

struct Partie {
	int plateau[8][8]; // Le plateau de jeu
	int nextPlayer; // Le joueur en cours
	int pions[2]; // Le nombre de pions appartenant a chaque joueur
	int fini; // L'état de la partie
	int role_ordi; // Le role de l'ordinateur (noir ou blanc)
	int mode_ordi; // Le mode de l'ordinateur (aléatoire ou glouton)
};

#endif