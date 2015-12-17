
#include <stdio.h>

#include "grille.h";

void initgrille()
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			grille[i][j]=vide;		
}

void addgrille(int iPosi,int iPosj,int color){
		
		grille[iPosi][iPosj]=color;
		if (iPosj<0 || iPosj>N || iPosi<0 || iPosi>N)
				printf("position hors grille");
		
		}
		
		
void afficher(pion grille[N][M]){
	int i,j;
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++){
			if (grille[i][j]==0)
				printf("| |");
			else if (grille[i][j]==1)
				printf("|-|");
			else if (grille[i][j]==2)
				printf("|+|");
			else if (grille[i][j]==3)
				printf("|*|");
			else if (grille[i][j]==4)
				printf("|°|");
		}
	}
}
		

