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

// Déclaration et initialisation des constantes et variables globales
#define N 8
#define M 8
typedef enum {vide,blanc,noire,possible,le_plus} pion;
pion grille[N][M] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0},{0,0,2,2,0,0,0,0},{0,1,2,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,2,0,0,0,0},{0,0,0,0,0,0,0,0}};
const int i_type_casePossible = 3;
const int i_type_casePlus = 4;
const int i_type_caseVide = 0;

//struct {char nom[16], int couleur} joueur;

//Déclaration des fonctions

//fonctions externes

void afficher(){
	int i,j;
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++){
			if (grille[i][j]==0)
				printf("| |");
			else if (grille[i][j]==1)
				printf("|1|");
			else if (grille[i][j]==2)
				printf("|2|");
			else if (grille[i][j]==3)
				printf("|3|");
			else if (grille[i][j]==4)
				printf("|4|");
		}
	}
}

// fonction internes
void determinePlacePossible(int Couleur_joueur)
{
	// Modification et renvoie :
	
	// Déclaration des variables de la fonction
	// variables compteur
	int i , j;
	
	// variable communes
	
	// variables propres à la fonction
	
	//int somme_lig_j1;
	//int somme_lig_j2;

	// Initialisation des variables de la fonction
	i = 0;
	j = 0;

	// Corps de la fonction
	for (i=0 ; i < N ; i++) {
		//Assert 1 dans determinePlacePossible pour une boucle For
 		for (j=0 ; j < M ; j++) {
			// boucle parcours colonne tableau
			//Assert 4 dans determinePlacePossible pour une boucle For
		
			if (grille[i][j] == 0) {
				// boucle recherche de voisins
				//déclaration des variables inter de compteur
				int ci_bis = 0;
				int cj_bis = 0;
				//int k_bis = 0;
				//Initialisation des variables de compteurs internes
				ci_bis =i;
				cj_bis = j;
				// parcours
				//parcours vers la gauche
				if (cj_bis>0) {
					cj_bis--;
					if ((grille[i][cj_bis] != Couleur_joueur) && (grille[i][cj_bis] != i_type_caseVide) && (grille[i][cj_bis] != i_type_casePossible) && (grille[i][cj_bis] != i_type_casePlus) ) 
					// détermine si pion a coté de de même  couleur que le joueur, rentre dans if si pas 
					{
						while ((cj_bis >0) && (grille[i][cj_bis] != i_type_caseVide) && (grille[i][cj_bis] != i_type_casePossible) && (grille[i][cj_bis] != i_type_casePlus) && (grille[i][cj_bis] != Couleur_joueur))
						{
							cj_bis--;
							if (grille[i][cj_bis] == Couleur_joueur) {
								(grille[i][j] = i_type_casePossible );
							}
						}
					}
				}

				// retour à la case vide pour explorer autres parcours
				cj_bis = j;
				
				//parcours vers la droite
				if (cj_bis<M-1) {
					cj_bis++;
					if ((grille[i][cj_bis] != Couleur_joueur) && (grille[i][cj_bis] != i_type_caseVide) && (grille[i][cj_bis] != i_type_casePossible) && (grille[i][cj_bis] != i_type_casePlus) ) 
					// détermine si pion a coté de de même  couleur que le joueur, rentre dans if si pas 
					{
						while ((cj_bis <M-1) && (grille[i][cj_bis] != i_type_caseVide) && (grille[i][cj_bis] != i_type_casePossible) && (grille[i][cj_bis] != i_type_casePlus) && (grille[i][cj_bis] != Couleur_joueur))
						{
							cj_bis++;
							if (grille[i][cj_bis] == Couleur_joueur) {
								(grille[i][j] = i_type_casePossible);
							}
						}
					}
				}

				//retour à la case vide pour exploration verticale
				ci_bis =i;
				cj_bis = j;
				// parcours
				//parcours vers le haut
				if (ci_bis>0) {
					ci_bis--;
					if ((grille[ci_bis][j] != Couleur_joueur) && (grille[ci_bis][j] != i_type_caseVide) && (grille[ci_bis][j] != i_type_casePossible) && (grille[ci_bis][j] != i_type_casePlus) ) 
					// détermine si pion a coté de de même  couleur que le joueur, rentre dans if si pas 
					{
						while ((ci_bis >0) && (grille[ci_bis][j] != i_type_caseVide) && (grille[ci_bis][j] != i_type_casePossible) && (grille[ci_bis][j] != i_type_casePlus) && (grille[ci_bis][j] != Couleur_joueur))
						{
							ci_bis--;
							if (grille[ci_bis][j] == Couleur_joueur) {
								(grille[i][j] = i_type_casePossible );
							}
						}
					}
				}

				// retour à la case vide pour explorer autres parcours
				ci_bis = i;
				
				//parcours vers le bas
				if (ci_bis<N-1) {
					ci_bis++;
					if ((grille[ci_bis][j] != Couleur_joueur) && (grille[ci_bis][j] != i_type_caseVide) && (grille[ci_bis][j] != i_type_casePossible) && (grille[ci_bis][j] != i_type_casePlus) ) 
					// détermine si pion a coté de de même  couleur que le joueur, rentre dans if si pas 
					{
						while ((ci_bis <N-1) && (grille[ci_bis][i] != i_type_caseVide) && (grille[ci_bis][j] != i_type_casePossible) && (grille[ci_bis][j] != i_type_casePlus) && (grille[ci_bis][j] != Couleur_joueur))
						{
							ci_bis++;
							if (grille[ci_bis][j] == Couleur_joueur) {
								(grille[i][j] = i_type_casePossible);
							}
						}
					}
				}
				// Parcours de diagonale
				// retour à la case vide pour explorer autres parcours diagonaux
				ci_bis = i;
				cj_bis = j;
				
				//parcours vers la droite haut
				if ((cj_bis<M-1) && (ci_bis>0)) {
					ci_bis--;
					cj_bis++;
					if ((grille[ci_bis][cj_bis] != Couleur_joueur) && (grille[ci_bis][cj_bis] != i_type_caseVide) && (grille[ci_bis][cj_bis] != i_type_casePossible) && (grille[ci_bis][cj_bis] != i_type_casePlus) ) 
					// détermine si pion a coté de de même  couleur que le joueur, rentre dans if si pas 
					{
						while ((cj_bis <M-1) && (ci_bis>0) && (grille[i][cj_bis] != i_type_caseVide) && (grille[i][cj_bis] != i_type_casePossible) && (grille[i][cj_bis] != i_type_casePlus) && (grille[i][cj_bis] != Couleur_joueur))
						{
							ci_bis--;
							cj_bis++;
							if (grille[ci_bis][cj_bis] == Couleur_joueur) {
								(grille[i][j] = i_type_casePossible);
							}
						}
					}
				}

				//retour à la case vide pour exploration gauche
				ci_bis =i;
				cj_bis = j;
				// parcours
				//parcours vers la diagonale haut gauche
				if (ci_bis>0 && cj_bis>0) {
					ci_bis--;
					cj_bis--;
					if ((grille[ci_bis][cj_bis] != Couleur_joueur) && (grille[ci_bis][cj_bis] != i_type_caseVide) && (grille[ci_bis][cj_bis] != i_type_casePossible) && (grille[ci_bis][cj_bis] != i_type_casePlus) ) 
					// détermine si pion a coté de de même  couleur que le joueur, rentre dans if si pas 
					{
						while ((ci_bis >0) && (cj_bis > 0) && (grille[ci_bis][cj_bis] != i_type_caseVide) && (grille[ci_bis][cj_bis] != i_type_casePossible) && (grille[ci_bis][cj_bis] != i_type_casePlus) && (grille[ci_bis][cj_bis] != Couleur_joueur))
						{
							ci_bis--;
							cj_bis--;
							if (grille[ci_bis][cj_bis] == Couleur_joueur) {
								// case vide de départ mis en type possible
								(grille[i][j] = i_type_casePossible );
							}
						}
					}
				}

				// retour à la case vide pour explorer autres parcours
				ci_bis = i;
				cj_bis = j;
				
				//parcours vers le bas gauche
				if (ci_bis<N-1 && cj_bis>0) {
					ci_bis++;
					cj_bis--;
					if ((grille[ci_bis][cj_bis] != Couleur_joueur) && (grille[ci_bis][cj_bis] != i_type_caseVide) && (grille[ci_bis][cj_bis] != i_type_casePossible) && (grille[ci_bis][cj_bis] != i_type_casePlus) ) 
					// détermine si pion a coté de de même  couleur que le joueur, rentre dans if si pas 
					{
						while ((ci_bis <N-1) && (cj_bis>0) && (grille[ci_bis][cj_bis] != i_type_caseVide) && (grille[ci_bis][cj_bis] != i_type_casePossible) && (grille[ci_bis][cj_bis] != i_type_casePlus) && (grille[ci_bis][cj_bis] != Couleur_joueur))
						{
							ci_bis++;
							cj_bis--;
							if (grille[ci_bis][cj_bis] == Couleur_joueur) {
								(grille[i][j] = i_type_casePossible);
							}
						}
					}
				}
			}
		}
	}
}

int main(void)
{
	// Renvoie : execute la fonction determinePlacePossible
	
	// Déclaration des variables

	int Couleur_joueur = 1;
	// Corps
	
	afficher();
	determinePlacePossible(Couleur_joueur);
	printf("\n grille transformée \n");
	afficher();
	printf("\n");
	return 0;

	

}
