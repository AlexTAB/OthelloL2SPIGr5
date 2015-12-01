#include <stdio.h>
#define N 8
#define M 8
typedef enum {vide, blanc, noire, possible, le_plus} pion;

pion grille[N][M];



void initgrille()
{
	int i,j;
	for(i=0;i<=N;i++)
		for(j=0;j<=M;j++)
			grille[i][j]=vide;		
}

void addgrille(int iPosi,int iPosj,int color){
		
		grille[iPosi][iPosj]=color;
		if (iPosj<0 || iPosj>N || iPosi<0 || iPosi>N)
				printf("position hors grille");
		
		}
		
		
void afficher(){
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
		
		
/*void main(){
	initgrille();
	afficher();
	addgrille(4,4,1);
	addgrille(3,4,2);
	addgrille(4,3,2);
	addgrille(3,3,1);
	afficher();
	
	}*/