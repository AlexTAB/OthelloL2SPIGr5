 #include<stdio.h>
/*#define N 8
#define M 8
typedef enum {vide,blanc,noire,possible,le_plus} pion;
pion grille[N][M] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,0},{0,0,2,2,0,0,0,0},{0,1,2,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,2,0,0,0,0},{0,0,0,0,0,0,0,0}};

void afficher(){
	int i,j;
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++){
			if (grille[i][j]==vide)
				printf("| |");
			else if (grille[i][j]==blanc)
				printf("|-|");
			else if (grille[i][j]==noire)
				printf("|+|");
		}
	}
}*/
#define N 8
#define M 8

typedef enum {vide, blanc, noire, possible, le_plus} pion;

pion grille[N][M];

void score(int * score1, int * score2){
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
/*
int main() {
	int score1,score2;
	afficher();
	score(&score1,&score2);
	printf ("score j1: %i... score j2: %i \n",score1,score2);
	return 0;
}*/
