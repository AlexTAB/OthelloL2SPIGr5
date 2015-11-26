#include<stdio.h>
#include<stdlib.h>


#define N 8
typedef enum {vide, blanc, noire, possible, le_plus} pion;

int grille[N][N];

int nombre_blanc=0;
int nombre_noire=0;
int nombre_blancAUTRE=0;
int nombre_noireAUTRE=0;

void initgrille(int matrice[N][N])
{
	int i,j;
	for(i=0;i<=N;i++)
		for(j=0;j<=N;j++)
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
void affiche(int matrice[N][N])
{
        int i,j;
        for(i=0;i<N;i++)
                {
                for(j=0;j<N;j++)
                        printf(" %i ", matrice[i][j]);
                printf("\n");
                }       
}
/*de colone chercher les même couleur et entre deux même couleur il y a au minimum 1 pion diffirent, on peut changer les couleurs entre deux mêmes pions */
	
int path_diago_A(int matrice[N][N],int i,int j, int dx, int dy)
{
	int icur,jcur;
	icur=i;
	jcur=j;
	//fprintf(stderr, "On joue en (%d,%d)\n", i, j);
	//fprintf(stderr,"On garde la direction(%d,%d)",dx,dy);
	if(matrice[i][j]==blanc) // la case courante est blanche, on cherche les pions noirs
	{
		do
		{
			icur+=dx;
			jcur+=dy;
			//fprintf(stderr, "On regarde la case (%d,%d) qui vaut %d \n", icur, jcur,matrice[icur][jcur] );
			 
			}
		while(matrice[icur][jcur]==noire);
		//fprintf(stderr, "On s'arrete sur la case (%d,%d)\n", icur, jcur);
		
		// (icur,jcur) est une case non noire (soir vide soit blanche)
		// si elle est vide -> on ne fait rien
		// si elle est blanche : on retourne les pions entre (i,j) et (icur, jcur)
		if(matrice[icur][jcur] == blanc){
			icur -= dx; jcur -= dy;
			//fprintf(stderr,"Examine seconde (%d,%d)\n",icur,jcur);
			while(icur != i || jcur!=j){
				//fprintf(stderr, "On retourne la case (%d,%d)\n", icur, jcur);
				matrice[icur][jcur] = blanc;
				icur -= dx; jcur -= dy;
			}
		
		}
		
	}
	return 1;
}

int path_tous(int matrice[N][N],int i,int j){
	int dx,dy;
	for(dx=-1; dx<=1; dx++)
		for(dy=-1; dy<=1; dy++)
			if(dx!=0 || dy!=0)
				path_diago_A(matrice,i,j, dx, dy);
	
	return 0;
}

int main()
{
	/*puts("tset");
	printf("%d\n",judge_dia(1,1,4,3));
	printf("%d\n",judge_dia(4,4,1,1));
	printf("%d\n",judge_dia(4,4,6,2));
	puts("test");
	*/
	
	initgrille(grille);
	affiche(grille);
	int col,lig;
	puts("Please input your pion");
	
	while(1)
	{
	scanf("%i%i",&lig,&col);
	grille[lig][col]=blanc;
	affiche(grille);
	puts("");
	//path_col(grille,lig,col);
	//path_lig(grille,lig,col);
	path_tous(grille,lig,col);
	affiche(grille);
	scanf("%d%d",&lig,&col);
	puts("");
	grille[lig][col]=noire;
	affiche(grille);
	}
	return 0;
}
