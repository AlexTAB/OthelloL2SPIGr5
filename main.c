	
#include <stdio.h>
#include <stdlib.h>

#define N 8
#define M 8
#define P N*M



#include "GestionFichier.h"
#include "grille.h"
#include "score.h"

typedef struct {int x;int y;} t_coor;
t_coor coor;
t_coor path_A(pion matrice[N][M],int i,int j, int dx, int dy);

void enlever3(pion matrice[N][M]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if (matrice[i][j]==possible || matrice[i][j]==le_plus)
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
                if(((abs(icur-i)>1) || (abs(jcur-j)>1 ))&& (icur<N)&&(jcur<N) && (icur>=0) && (jcur>=0))
                       { matrice[icur][jcur]=possible;}
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
void laPlacePossible(int joueur,pion matrice[N][M])// (1)on parcour le tableau et à chaque foi que l'on voit le pion du joueur (2) on regarde dans tout les direction *(3)si on a une serie de pions d'un autre joueur puis un vide (4) sa deviens une place possible
{
    int i,j;
    enlever3(matrice);
        for(i=0;i<N;i++)
                for(j=0;j<M;j++)
                        if(matrice[i][j]==joueur)
                                conver_possi(matrice,i,j);
     
}

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
	return coor;
}

int conver_coul_dire(pion matrice[N][N],int i,int j,int dx,int dy){
        path_A(matrice,i,j,dx,dy);
        int icur,jcur;
        icur=coor.x;
        jcur=coor.y;  
	pion coul_courant=matrice[i][j];
	if(matrice[icur][jcur] == coul_courant)
	{
		icur -= dx; jcur -= dy;
		while(((icur != i) || (jcur!=j))&&((icur<N)&&(jcur<N) && (icur>0)&&(jcur>0))){
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


int VerifieFinPartie()
{
	// Modification et renvoie : Verifie si la partie de Othello est finie. Ce qui veut dire pas de case de type 3 ou 4 
	//présentes dans la grille . Renvoie 0 si partie finie , 1 sinon. 
	
	int i , j;


	int somme_case_Plus;
	int somme_case_Possible;
	int somme_case_Ajouer;
	
	// Initialisation des variables de la fonction
	i = 0;
	j = 0;
	somme_case_Plus =0;
	somme_case_Possible =0;
	somme_case_Ajouer = 0;
	

	for (i=0 ; i < N ; i++) {
		
 		for (j=0 ; j < M ; j++) {
				
			if (grille[i][j] == 3)  {

				somme_case_Possible++;
				
			}
			else if (grille[i][j] == 4) {

				somme_case_Plus++;
				
			}
		}
	}
	somme_case_Ajouer = somme_case_Possible + somme_case_Plus;
	
	return somme_case_Ajouer;
}


void pose_plus(int joueur){
		int i,j;
		int point;
		int test_plus = 0;
		pion temp[N][M] = {{0}};
		modif_ScorePre(temp);
			
		for(i=0;i<N;i++){ //création d'un matrice temporaire identique a la grille 
      	for(j=0;j<M;j++){
           	temp[i][j]=grille[i][j];
       	 }
   }
   			

  	
  
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
        	
            if (grille[i][j]==possible){ //on simule un plassage de pion dans la matrice si on trouve un case possible
            
            	temp[i][j]=joueur;
        				convertir_coul(temp,i,j);
        				point = PointGagne(temp,joueur);
        				
        						if (test_plus < point){//si on trouve un meillieur score tout les le_plus redevienne just possible
        									int k,l;
        							 		for(k=0;k<N;k++){
        												for(l=0;l<M;l++){
           								 					if (grille[k][l]==le_plus){
           								 								grille[k][l]=possible;
           								 					}
           								 		}
           							}
           							grille[i][j]=le_plus;
		        							test_plus = point;
		        				}
		        				
		        				else if( test_plus == point){
							        					grille[i][j]=le_plus;
		        					}
		        					
		        				int k,l;
        						for(k=0;k<N;k++){
        									for(l=0;l<M;l++){
           										 temp[k][l]=grille[k][l];
       										 }
   									}
		        	}
        }
    }
	
	}

void passJoueur(int *iJoueur,int *nbJoueur){
    if(*iJoueur==*nbJoueur)//passage joueur
        {(*iJoueur) =1;}
    else
        {(*iJoueur)++;}
}


void NomJoueur(char sNomJ1[30],char sNomJ2[30]){//initialise les noms
    printf("Nom du joueur: ");
    scanf ("%s", sNomJ1);
    printf("adversaire: ");
    scanf ("%s", sNomJ2);
}


void Tour(int joueur,char sNomJ1[30],char sNomJ2[30],char nomSave[20]){//les tours de jeux
    	int score1,score2;
    	
    if (joueur == 1){
        printf("C'est au tour de %s de jouer \n", sNomJ1); //afficher joueur à jouer
    }
    else if(joueur ==2){
        printf("C'est à vous %s \n", sNomJ2);
    }
    
    score(grille,&score1,&score2);
    pose_plus(joueur);
    
	
    printf ("score de %s: %i		 score de %s: %i \n",sNomJ1,score1,sNomJ2,score2); //affiche score
    afficher(grille);
    
    int col,lig;
    puts("Please input your pion");//gere l'entré des joueurs
    scanf("%i%i",&lig,&col);
    
    while ( (grille[lig][col] != 3) && (grille[lig][col] != 4)){
		printf("entré incorect veulliez resaisir: ");
		scanf("%i%i",&lig,&col);
	
	}
    
    grille[lig][col]=joueur;
    
    puts("");
        convertir_coul(grille,lig,col);
    
    sauvegarde(nomSave);

}

int main(){
    initgrille();
    char* nomSave;

    int bChargement; //gere le chargemant
    printf ("entrez le nom de votre sauvegarde: (entrez 1 pour charger et visioner une encienne partie) ");
    scanf("%i",&bChargement);
    if (bChargement){
        chargement();
        if (!parcourir())
            return 0;
    }
    
    
    
	int iJoueur=1;
	int nbJoueur=2;
	int score1,score2;
	char sNomJ1[30], sNomJ2[30];

    addgrille(3,3,noire);
    addgrille(4,4,noire);
    addgrille(4,3,blanc);
    addgrille(3,4,blanc);
	
    nomSave = FirstSauvegarde();
    
	NomJoueur(sNomJ1,sNomJ2);
	while(1){
        laPlacePossible(iJoueur,grille);
        if(VerifieFinPartie()==0){
            passJoueur(&iJoueur,&nbJoueur);
            laPlacePossible(iJoueur,grille);
            if(VerifieFinPartie()==0){
                break;//si aucun joueur ne peut jouer on sort du while (fin de jeux)
            }
        }
		Tour(iJoueur,sNomJ1,sNomJ2,nomSave);
        passJoueur(&iJoueur,&nbJoueur);
	}
	
		score(grille,&score1,&score2);
		printf("Le gagnant est : \n");
		if (score1>=score2){
			printf(" sNomJ1 \n");
			}
		if (score2>=score1){
			printf(" sNomJ2 \n");
			}
		if(score1==score2){
			printf("Egalité!\n");
		}
			
	printf (" score de %s: %i... score de %s: %i \n",sNomJ1,score1,sNomJ2,score2); //affiche score
    return 0;
    
}

