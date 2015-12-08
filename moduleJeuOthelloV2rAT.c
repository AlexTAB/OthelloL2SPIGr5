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
#include <initialisation grille.h>

// Déclaration et initialisation des constantes et variables globales
const int i_type_casePossible = 3;
const int i_type_casePlus = 4;
const int i_type_caseVide = 0;

//struct {char nom[16], int couleur} joueur;

//Déclaration des fonctions

//fonctions externes


		}
	}
}

// fonction internes
// Corps peogramme
int main(void)
{
	// Renvoie : execute la fonction determinePlacePossible
	
	// Déclaration des variables
	int i_couleur_Jcourant = 1

	// Corps
	// Initialisation
	//  
	// initialisation du plateau
	// 
	initgrille();

	// initialisatioon du jeu
	// 
	initJeuOthello();

	// Initialisation des nom des joueur
	// 
	gererNomJoueur();

	// Deroulement du jeu Othello
	// 
	while (verifieFinPartie() !=0) {
		// poursuite du jeu si partie pas fini
		afficher();
	}
	afficher();
	determinePlacePossible();
	printf("\n grille transformée \n");
	afficher();
	printf("\n");
	return 0;

	

}
