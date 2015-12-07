// 
// Alexandre TABOT L2 SPI Université du Mans 2015-2016
// Date :
// Compilation : exemple :alexandre@alexandre-tabot7:~/Documents/pbc$ gcc affiche var ex001.c -o afficheEx001 -Wall
// Execution :
//

//note
//	valeurs de case matrice grille
// 0 -> vide
// 1-> noir : pion du joueur 1 j1
// 2-> blanc: pion du joueur 2 j2 
// 3 -> possible
// 4-> plus

// Inclusion des bibliothèques
#include <stdio.h> 
#include <stdlib.h>

#define N 8
typedef enum {vide, blanc, noire, possible, le_plus} pion;




//
int gererNomJoueur()
{
	// Modification et renvoie : Mémorise le nom des joueurs et leur couleur de pion dans une structure str_id_Joueur
	
	
	// Déclaration des variables de la fonction
	struct st_id_Joueur
	{
		char tc_nomJoueur[N];
		int couleur_Joueur;
	};
	char tc_nomJoueur1[N] ='J1';
	char tc_nomJoueur2[N] ='J2';
	struct st_id_Joueur Joueur1;
	struct st_id_Joueur Joueur2;
	//
	// Corps de la fonction
	//
	// saisie du nom du joueur 1
	printf("\n Quel est le nom du joueur 1 représenté par les pions blancs : ");
	scanf("%s", tc_nomJoueur1);
	Joueur1.tc_nomJoueur = tc_nomJoueur1;
	Joueur1.couleur_Joueur = blanc;
	// saisie du nom du joueur 2
	printf("\n Quel est le nom du joueur 2 représenté par les pions noirs : ");
	scanf("%s", tc_nomJoueur2);
	Joueur2.tc_nomJoueur = tc_nomJoueur2;
	Joueur2.couleur_Joueur = noire;

	return 0;

	

}
