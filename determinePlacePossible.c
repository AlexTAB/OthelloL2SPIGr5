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

// Déclaration des fonctions et des procédures du programmes
void determinePlacePossible(int a; char grille[M][N])
{
	// Modification et renvoie :
	
	// Déclaration des variables de la fonction
	// variables compteur
	int i , j;
	
	// variable communes
	
	// variables propres à la fonction
	int i_somme-lig-j1;
	int i_somme-lig-j2;
	float f_x;
	int i_somme-col-j1;
	int i_somme-col-j2;
	char choix;

	// Initialisation des variables de la fonction
	i = 0;
	j = 0;
	i_somme-lig-j1 =0;
	i_somme-col-j1=0;
	i_somme-col-j2=0;

	// Corps de la fonction
	for (i=0 ; i < N ; i++) {
		//Assert 1 dans determinePlacePossible pour une boucle For
		if (grille[i][j] == 1)  {
			// condition : si trouve un pion noir
			// Assert 2 dans determinePlacePossible pour une condition IF
			somme_lig_j1++;
			i_somme_lig_vide = 0;
		}
		if (grille[i][j] == 2) {
			// condition : si trouve un pion blanc
			// Assert 3 dans determinePlacePossible pour une condition IF
			somme_lig_j2++;
			i_somme_lig_vide = 0;
		}
		//
 		for (j=0 ; j < M ; j++) {
			// boucle parcours colonne tableau
			//Assert 4 dans determinePlacePossible pour une boucle For
				
			if (grille[i][j] == 1)  {
				// condition : si trouve un pion noir
				// Assert 5 dans determinePlacePossible pour une condition IF
				somme_col_j1++;
				i_somme_col_vide = 0;
			}
			if (grille[i][j] == 2) {
				// condition : si trouve un pion blanc
				// Assert 6 dans determinePlacePossible pour une condition IF
				somme_col_j2++;
				i_somme_col_vide = 0;
			}
			// etape valeur case grille 0, 3 ou 4. Ceci nécessite mise des somme case pion des précédntes pour mémorisation.
			// Ces sommes sont nécessaires dans les condition de determination.
			if (grille[i][j] == 0) {
				// incrémentation des sommes de cases vides
				i_somme_col_vide++;
				i_somme_lig_vide++;
				// condition : si trouve une case vide 
				// Assert 7 dans determinePlacePossible pour une condition IF
				if (((somme_col_j2 >0) && (somme_col_j1 >0)) || ((somme_lig_j2 >0) && (somme_lig_j1 >0)) {
					// condition :  si trouve case vide et qu' il ya une somme de case pion sans case vide alors devient case possible
					grille[i][j] = 3;
					//mise à zéro des somme de case pion
					somme_col_j2 =0;
					somme_col_j1 =0;
					somme_lig_j2 =0;
					somme_lig_j1 =0;
				}					
			}
			if (grille[i][j] == 3) {
				// les case de type 3 "possible" sont aussi des cases vides, donc même traitement des sommes de type de cases
				i_somme_col_vide++;
				i_somme_lig_vide++;
				somme_col_j2 =0;
				somme_col_j1 =0;
				somme_lig_j2 =0;
				somme_lig_j1 =0;
			}
			if (grille[i][j] == ) {
				// les case de type 4 "plus" sont aussi des cases vides, donc même traitement des sommes de type de cases
				i_somme_col_vide++;
				i_somme_lig_vide++;
				somme_col_j2 =0;
				somme_col_j1 =0;
				somme_lig_j2 =0;
				somme_lig_j1 =0;
			}
		}
	}
}


