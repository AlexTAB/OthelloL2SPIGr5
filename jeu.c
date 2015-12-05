#include "jeu.h"
#include "Debug.h"

// Les deux premières fonctions sont les parties communnes aux deux modes de jeu

void fini (struct Partie partie) { // Code executé en fin de partie
	if(!partie.fini) { // Si le jeu s'est terminé par un plateau rempli
		printf("Le plateau est rempli.\n");

		affiche_nombre_pions(partie);

		if(partie.pions[0] > partie.pions[1])
			printf("Les noirs gagnent.\n");
		else if(partie.pions[1] > partie.pions[0])
			printf("Les blancs gagnent.\n");
		else
			printf("Match nul.\n");
	}
}

void init (struct Partie* partie) { // Code d'initialisation d'une partie
	char charger = 0;

	/* Demande au joueur s'il veux initiliaser une nouvelle partie, ou en charger une depuis la sauvegarde.
	 * Les deux modes utilisent la même fonction, il est donc possible de commencer une partie en mode 2 joueurs et de la terminer contre l'ordinateur. */
	do {
		fflush(stdin);
		printf("Voulez vous commencer une nouvelle partie (n) ou en charger une (c) ? ");
		scanf("%c", &charger);
	} while(charger != 'c' && charger != 'n'); // Vérification des entrée du joueur

	if(charger == 'n') // Initialise la partie en conséquence
		initialise(partie);
	else
		initialise_fichier(partie);
}

void jeu(int mode) {
	struct Partie partie;
	int passe = 0;
	
	init(&partie); // Initialise la partie

	if(mode == 1) {
		while(partie.role_ordi == 0) { // Choix du role de l'ordinateur (doit il jouer en premier ou en deuxième ?)
			char role = 0;
			fflush(stdin);
			printf("L'ordinateur doit il jouer les blancs (b) ou les noirs (n), les noirs jouant en premier ? ");
			scanf("%c", &role);
			if(role == 'b')
				partie.role_ordi = 2;
			else if(role == 'n')
				partie.role_ordi = 1;
		}

		while(partie.mode_ordi == 0) { // Choix du mode de l'ordinateur (aléatoire ou glouton)
			char mode = 0;
			fflush(stdin);
			printf("L'ordinateur doit il jouer au hasard (h) ou de maniere gloutonne (g) ? ");
			scanf("%c", &mode);
			if(mode == 'h')
				partie.mode_ordi = 1;
			else if(mode == 'g')
				partie.mode_ordi = 2;
		}
	}

	do {
		if(possible(partie)) { // Si le joueur actuel peut joueur
			passe = 0; // Remet a 0 le nombre de tours passés
			affiche(partie);
			if(mode == 2 || (mode == 1 && partie.nextPlayer != partie.role_ordi))
				jouer(&partie); // Demande au joueur actuel d'effectuer une action
			else if(partie.mode_ordi == 1)
				jouer_ordi_alea(&partie);
			else if(partie.mode_ordi == 2)
				jouer_ordi_glouton(&partie);
		} else
			passe++; // Sinon incrémente le nombre de tours passés

		partie.nextPlayer = nextPlayer(partie.nextPlayer); // Passe au joueur suivant
	} while(passe < 2 && !partie.fini); // Si le 2 joueurs ont passé leur tour (plus aucun coup possible), ou si la partie est finie (une sauvegarde a été effectuée)

	fini(partie); // Affiche les scores si besoin est
}

void jeu_ordi () {
	jeu(1);
}

void jeu_deux() {
	jeu(2);
}