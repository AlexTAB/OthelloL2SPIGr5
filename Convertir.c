#include<stdio.h>
#include<stdlib.h>
#include "Convertir.h"

//pour la test
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
}

void affiche(pion matrice[N][N])
{
        int i,j;
        for(i=0;i<N;i++)
                {
                for(j=0;j<N;j++)
                        printf(" %i ", matrice[i][j]);
                printf("\n");
                }       
}*/
		
t_coor path_A(pion matrice[N][M],int i,int j, int dx, int dy)
{
	int icur,jcur;
	icur=i;
	jcur=j;
    pion coul_courant=matrice[i][j];
    pion coul_opose=(coul_courant==blanc)?noire:blanc;
	//fprintf(stderr, "On joue en (%d,%d)\n", i, j);
	//fprintf(stderr,"On garde la direction(%d,%d)",dx,dy);
	if(matrice[i][j]==coul_courant) // la case courante est blanche, on cherche les pions noirs
	{
		do
		{
			icur+=dx;
			jcur+=dy;
			}
		while(matrice[icur][jcur]==coul_opose);
	}	
		// (icur,jcur) est une case non noire (soir vide soit blanche)
		// si elle est vide -> on ne fait rien
		// si elle est blanche : on retourne les pions entre (i,j) et (icur, jcur)
		coor.x=icur;
		coor.y=jcur;
		puts("");
		printf("on examine les coor(%d,%d)\n",coor.x,coor.y);
	return coor;
}

int conver_coul_dire(pion matrice[N][N],int i,int j,int dx,int dy){
        path_A(matrice,i,j,dx,dy);
        int icur,jcur;
        icur=coor.x;
        jcur=coor.y;  
	pion coul_courant=matrice[i][j];
	pion coul_opose=(matrice[i][j]==blanc)?noire:blanc;
	if(matrice[icur][jcur] == coul_courant)
	{
		icur -= dx; jcur -= dy;
		while(icur != i || jcur!=j &&(icur<N)&&(jcur<N) && (icur>0)&&(jcur>0)){
			matrice[icur][jcur] = coul_courant;
			icur -= dx; jcur -= dy;
		}
	}
	return 0;
}
			
int convertir_coul(pion matrice[N][N],int i,int j){
	int dx,dy;
	for(dx=-1; dx<=1; dx++)
		for(dy=-1; dy<=1; dy++)
			if(dx!=0 || dy!=0)
				conver_coul_dire(matrice,i,j, dx, dy);
	
	return 0;
}

/*int main()
{
	initgrille(grille);
	affiche(grille);
	int col,lig;
	puts("Please input your pion");
	
	while(1)
	{
	scanf("%i%i",&lig,&col);
	grille[lig][col]=noire;
	affiche(grille);
	puts("");
	path_tous(grille,lig,col);
	affiche(grille);
	}
	return 0;
}*/
