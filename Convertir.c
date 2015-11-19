#include<stdio.h>

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
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			matrice[i][j]=vide;
	matrice[2][3]=blanc;
	matrice[3][3]=noire;
	matrice[3][4]=noire;
	matrice[4][3]=noire;
	matrice[4][4]=blanc;
	matrice[4][2]=noire;
	matrice[3][2]=blanc;
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
int path_col(int matrice[N][N],int i,int j)
{
        int col;int lig;
        int marque_nb_blanc=1;
        int marque_nb_noire=1;
        for(lig=0;lig<N;lig++)
        {
                if(lig<i)
                {
                        if(matrice[lig][j]==blanc)
                                nombre_blanc++;
                        else if(matrice[lig][j]==noire)
                                nombre_noire++;// la côté sur (i,j)
                }
                
                if(lig>i&&lig<N)
                {
                        if(matrice[lig][j]==blanc)
                                nombre_blancAUTRE++;
                        else if(matrice[lig][j]==noire)
                                nombre_noireAUTRE++; // la côté desous (i,j)       
                }
        }
        //test
        printf("%i %i %i %i \n",nombre_blanc,nombre_noire,nombre_blancAUTRE,nombre_noireAUTRE);
        if(matrice[i][j]==blanc && nombre_blancAUTRE>0)//entre deux pions blancs
        {
                for(lig=N-1;lig>i;lig--)
                {
                	if(matrice[lig][j]==blanc)
                		if(matrice[lig-1][j]==noire)
                			marque_nb_blanc++;
                	if(marque_nb_blanc>=2)
                        matrice[lig][j]=blanc;
                }
        }
        if(matrice[i][j]==blanc && nombre_blanc>0)
        {
                for(lig=0;lig<i;lig++)
                	{
                	if(matrice[lig][j]==blanc)
                		if(matrice[lig+1][j]==noire)
                		marque_nb_blanc++;
                	if(marque_nb_blanc>=2)
                        matrice[lig+1][j]=blanc;
                    }
        }
        else if(matrice[i][j]==noire && nombre_noireAUTRE>0)//entre deux pions noires
        {
                for(lig=N-1;lig>i;lig--)
                {
                	if(matrice[lig][j]==noire)
                		if(matrice[lig-1][j]==blanc)
                			marque_nb_noire++;
                	if(marque_nb_noire>=2)
                        matrice[lig][j]=noire;
                }
        }
        else if(matrice[i][j]==noire && nombre_noire>0)
        {
        	for(lig=0;lig<i;lig++)
        		{
        			if(matrice[lig][j]==noire)
        				if(matrice[lig+1][j]==blanc)
        					marque_nb_noire++;
        			if(marque_nb_noire>=2)
        				matrice[lig+1][j]=noire;
        		}
        }
        return 0;
}

int path_lig(int matrice[N][N],int i,int j)
{
	int lig,col;
	int marque_nb_pion=1;
	for(col=0;col<N;col++)
		{
			if(col<j)//à gouche
			{
				if(matrice[i][col]==blanc)
					nombre_blanc++;
					else if(matrice[i][col]==noire)
					nombre_noire++;
			}
			else if(col>j&&col<N)//à droite
			{
				if(matrice[i][col]==noire)
					nombre_noireAUTRE++;
					else if(matrice[i][col]==blanc)
					nombre_blancAUTRE++;
			}
		}
	for(col=0;col<j;col++)
		{
			if(matrice[i][col]==matrice[i][j]==blanc && nombre_blanc>0)
				if(matrice[i][col+1]==noire)
					matrice[i][col+1]=blanc;
			if(matrice[i][col]==matrice[i][j]==noire && nombre_noire>0)
				if(matrice[i][col+1]==blanc)
					matrice[i][col+1]=noire;
		}
	for(col=N-1;col>j;col--)
	{
		if(matrice[i][col]==matrice[i][j]==blanc && nombre_blancAUTRE>0)
			if(matrice[i][col-1]==noire)
				matrice[i][col-1]=blanc;
		if(matrice[i][col]==matrice[i][j]==noire && nombre_noireAUTRE>0)
			if(matrice[i][col-1]==blanc)
				matrice[i][col-1]=noire;
	}
	return 0;
}
int convertir(int matrice[N][N],int i, int j)
{
          return 0;      
}

int main()
{
	initgrille(grille);
	affiche(grille);
	int col,lig;
	puts("Please input your pion");
	scanf("%i%i",&lig,&col);
	grille[lig][col]=blanc;
	affiche(grille);
	path_col(grille,lig,col);
	path_lig(grille,lig,col);
	affiche(grille);
	return 0;
}