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

// Déclaration constantes et variables globales
#define N 8
#define M 8
typedef enum {vide,blanc,noire,possible,le_plus} pion;
typedef struct
pion grille[N][M] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0},{0,0,2,2,0,0,0,0},{0,1,2,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,2,0,0,0,0},{0,0,0,0,0,0,0,0}};



// Déclaration des sous fonctions et des procédures du programme fonction

// fonction externes
void afficher(){
    int i,j;
    for(i=0;i<N;i++){
        printf("\n");
        for(j=0;j<M;j++){
            if (grille[i][j]==0)
                printf("| |");
            else if (grille[i][j]==1)
                printf("|+|");
            else if (grille[i][j]==2)
                printf("|-|");
               // modification par Alex T
			else if (grille[i][j]==3)
                printf("|3|");
            else if (grille[i][j]==4)
                printf("|4|");
        }
    }
}
// fonction internes
int gererNomJoueur()
{
	// Modification et renvoie : Verifie si la partie de Othello est finie. Ce qui veut dire pas de case de type 3 ou 4 
	//présentes dans la grille . Renvoie 0 si partie finie , 1 sinon. 
	// possible amelioration renvoie le nombre de cases restantes à jouer
	
	// Déclaration des variables de la fonction
	// variables compteur
	int i , j;
	
	// variable communes
	
	// variables propres à la fonction
	int somme_case_Plus;
	int somme_case_Possible;
	int somme_case_Ajouer;
	
	// Initialisation des variables de la fonction
	i = 0;
	j = 0;
	somme_case_Plus =0;
	somme_case_Possible =0;
	somme_case_Ajouer = 0;
	
	// Corps de la fonction
	for (i=0 ; i < N ; i++) {
		//Assert 1 dans determinePlacePossible pour une boucle For
		
 		for (j=0 ; j < M ; j++) {
			// boucle parcours colonne tableau
			//Assert 4 dans VerifieFinPartie pour une boucle For
				
			if (grille[i][j] == 3)  {
				// condition : si trouve une case Possible
				// Assert 2 dans VerifieFinPartie pour une condition IF
				somme_case_Possible++;
				
			}
			else if (grille[i][j] == 4) {
			
				// condition : si trouve une case Plus
				// Assert 3 dans VerifieFinPartie pour une condition IF
				somme_case_Plus++;
				
			}
			//Sinon  Pas de case Plus ou Possible (3 ou 4)
		}
	}
	// somme cases restantes à jouer
	somme_case_Ajouer = somme_case_Possible + somme_case_Plus;
	
	return somme_case_Ajouer;
}
int main(void)
{
	// Renvoie : execute la fonction VerifieFinPartie
	
	// Déclaration des variables
	

	// Corps
	
	afficher();
	
	if(VerifieFinPartie()== 0){
		
		printf("\n fin de partie  \n");
	}
	else {
		printf("\n  Il reste des cases à jouer  \n");
	}
	return 0;

	

}
