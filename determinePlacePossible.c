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

/*void afficher(){
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
}*/





#include <stdio.h>
#define N 8
#define M 8

typedef enum {vide, blanc, noire, possible, le_plus} pion;

pion grille[N][M];

void enlever3(){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if (grille[i][j]==3)
                grille[i][j]=0;
        }
    }
}

void verification(int k,int *vertical,int *horrisontal){//fonction qui créer tout le possibilité de direction pour vertical et horrisontal en fonction de k
    
    k=k-3;//determine vertical et creer un module pour k
    if (k<0){
        *vertical=-1;
    }
    else{
        k=k-3;
        if(k<0){
            *vertical=1;
        }
        else {
            k=k-3;
            *vertical=0;
        }
    }
    //determine horrisontal
    if (k==-3){
        *horrisontal=-1;
    }
    else if(k==-2){
        *horrisontal=1;
    }
    else if(k==-1){
        *horrisontal=0;
    }
    else{
        printf("erreur");
    }
    
}

// fonction internes
void determinePlacePossible(int joueur)// (1)on parcour le tableau et à chaque foi que l'on voit le pion du joueur (2) on regarde dans tout les direction *(3)si on a une serie de pions d'un autre joueur puis un vide (4) sa deviens une place possible
{
    int vertical;
    int horrisontal;
    int i,j,k;
    int I,J;
    enlever3();

    //(1)
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(grille[i][j]==joueur){
                //(2)
                for (k=0;k<8;k++){
                    int bPremierpassage =0;
                    
                    verification(k,&vertical,&horrisontal);
                    //(3)
                    I=i+vertical;
                    J=j+horrisontal;
                    while ((grille[I][J] >0) && (grille[I][J] <3) && (grille[I][J]!=joueur) && (J<M) && (I <N) && (I>0) && (J>0)){
                        I=I+vertical;
                        J=J+horrisontal;
                        bPremierpassage=1;
                        
                    }//(4)
                    
                    if (I==N || J==M || I==-1 || J==-1){
                        //rien ne ce passe car hors tableau
                    }
                    else if (bPremierpassage == 0){
                        //encor rien car il faut au moin un pion de l'autre joueur
                    }
                    else if(grille[I][J] != 0){
                        //tjrs rien car non vide
                    }
                    else {
                        grille[I][J]=3;
                    }
                }
                
            }
        }
    }
}




 /*   int main(void)
{
	// Renvoie : execute la fonction determinePlacePossible
	
	// Déclaration des variables

	// Corps
    
    int joueur =2;
	afficher();
	determinePlacePossible(joueur);
	printf("\n grille transformée \n");
	afficher();
	printf("\n");
	return 0;

	

}*/

