 #include<stdio.h>
#include"grille.h"
#define N 8
#define M 8
#define P N*M

int ScorePre1, ScorePre2;


void score(pion grille[N][M],int * score1, int * score2){
	int i,j;
	*score1=0;
	*score2=0;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if (grille[i][j] == 1){
				(*score1)++;
				}
			else if (grille[i][j] == 2){
				(*score2)++;
				}
		}
	
	}
	
}

void modif_ScorePre(pion grille[N][M]){
		int score1,score2;
		score (grille,&score1, &score2);
		ScorePre1 = score1;// sauvegarde les scores dans les variables ScorePre
		ScorePre2 = score2;
		
}
int PointGagne(pion grille[N][M], int joueur){ // fonction qui retourn le gaint de score que le joueur a gagné après la dernière demande Score
		int score1,score2;	
		score (grille,&score1, &score2);
		
		int point;
		if (joueur == 1){
			point = score1 - ScorePre1;
			
		}
		else{
			point = score2 - ScorePre2;
		}
		return point;
	}
