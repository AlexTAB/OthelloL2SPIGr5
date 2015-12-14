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
/*#include <stdio.h>
#include <stdlib.h>

// Déclaration et initialisation des constantes et variables globales
#define N 8
#define M 8
typedef enum {vide,blanc,noire,possible,le_plus} pion;
pion grille[N][M] = {{0,0,0,0,0,0,0,0},{0,0,3,0,0,0,0,0},{0,0,0,0,1,0,0,0},{0,0,2,2,0,0,0,0},{0,1,2,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,2,0,0,0,0},{0,0,0,0,0,0,0,0}};*/
//struct {char nom[16], int couleur} joueur;

//Déclaration des fonctions

//fonctions externes

#include <stdio.h>
#include <stdlib.h>
#include "Convertir.h"

//les fonction exterieur
/*void initgrille(pion matrice[N][N])
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			matrice[i][j]=vide;
        matrice[2][2]=blanc;
	matrice[2][3]=blanc;
	matrice[3][3]=noire;
	matrice[3][4]=noire;
	matrice[4][3]=noire;
	matrice[4][2]=noire;
	matrice[3][2]=blanc;
	matrice[1][1]=blanc;
	matrice[0][1]=noire;
	matrice[0][2]=noire;
}

void afficher(pion matrice[N][M]){
	int i,j;
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++){
			if (matrice[i][j]==0)
				printf("| |");
			else if (matrice[i][j]==1)
				printf("|1|");
			else if (matrice[i][j]==2)
				printf("|2|");
			else if (matrice[i][j]==3)
				printf("|3|");
			else if (matrice[i][j]==4)
				printf("|4|");
		}
	}
}*/

void enlever3(pion matrice[N][M]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if (matrice[i][j]==possible)
                matrice[i][j]=vide;
        }
    }
}

void conver_possi_dire(pion matrice[N][M],int i, int j, int dx, int dy)
{
        path_A(matrice,i,j,dx,dy);
        int icur,jcur;
        icur=coor.x;jcur=coor.y;
        if(matrice[icur][jcur]==vide)
                if(abs(icur-i)>1 || abs(jcur-j)>1 &&(icur<N)&&(jcur<N) && (icur>=0)&&(jcur>=0))
                       {printf("(icur,jcur):(%d,%d)\t",icur,jcur); matrice[icur][jcur]=possible;}
}

void conver_possi(pion matrice[N][M],int i,int j){//fonction qui créer tout le possibilité de direction pour vertical et horrisontal en fonction de k
  int dx,dy;
	for(dx=-1; dx<=1; dx++)
		for(dy=-1; dy<=1; dy++)
			if(dx!=0 || dy!=0){
				conver_possi_dire(matrice,i,j,dx,dy);
				}
}

// fonction internes
void laPlacePossible(pion joueur,pion matrice[N][M])// (1)on parcour le tableau et à chaque foi que l'on voit le pion du joueur (2) on regarde dans tout les direction *(3)si on a une serie de pions d'un autre joueur puis un vide (4) sa deviens une place possible
{
    int i,j;
    enlever3(matrice);
        for(i=0;i<N;i++)
                for(j=0;j<M;j++)
                        if(matrice[i][j]==joueur)
                                conver_possi(matrice,i,j);
     
}

//pour la test
/*int main()
{
        pion joueur; 
	initgrille(grille);
	afficher(grille);
	int col,lig;
	puts("Please input your pion");
	while(1)
	{
	puts("la joueur noire");
	joueur=noire;
	laPlacePossible(joueur,grille);
	afficher(grille);
	puts("la joueur blanche");
	joueur=blanc;
	laPlacePossible(joueur,grille);
	afficher(grille);
	puts("");
	afficher(grille);
	break;
	}
	return 0;
}*/
