	
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
t_coor_case coor_clic;
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

void conver_possi(pion matrice[N][M],int i,int j)
{//fonction qui créer tout le possibilité de direction pour vertical et horrisontal en fonction de k
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
	
	//Déclaration des variables
	int i , j;
	int continuer=1;
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
	somme_case_Ajouer = somme_case_Possible + somme_case_Plus * continuer;
	
	return somme_case_Ajouer;
}


void pose_plus(int joueur)
{
// determine les case a jouer rapportant le plus

	//déclaration des variables
	int i,j;
	int point;
	int test_plus = 0;
	int k,l;
	pion temp[N][M] = {{0}};
	modif_ScorePre(temp);
			
	for(i=0;i<N;i++){ //création d'un matrice temporaire identique a la grille 
      		for(j=0;j<M;j++){
           		temp[i][j]=grille[i][j];
       	 	}
   	}
  
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
        		if (grille[i][j]==possible){
             //on simule un placement de pion dans la matrice si on trouve un case possible
            			temp[i][j]=joueur;
        			convertir_coul(temp,i,j);
        			point = PointGagne(temp,joueur);
        			if (test_plus < point){
        				//si on trouve un meillieur score tout les le_plus redevienne just possible
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


void NomJoueur(char sNomJ1[20],char sNomJ2[20], SDL_Color textColor,SDL_Color fondColor, char phrase2_affiche[]){//initialise les noms
	// Affichage nom joueur 1
	sprintf(phrase2_affiche, "Nom du joueur:                                                                               \n"); 
	position.x = 520;
	position.y = 30;
	afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
	
	// effacement ligne en dessous avant affichage
	sprintf(phrase2_affiche, "                                                                                            \n"); 
	position.x = 520;
	position.y = 50;
	afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
	
	// saisie utilisateur nom du joueur 1
	position.x = 700;
	position.y = 30;
	mot_saisi_Clavier_SDL(sNomJ1, screen, message, font, position, textColor, fondColor);
	
	
	// Affichage nom joueur 2
	sprintf(phrase2_affiche, "adversaire:                                                  "); 
	position.x = 520;
	position.y = 50;
	afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
	// saisie utilisateur nom du joueur 2
	position.x = 700;
	position.y = 50;
	mot_saisi_Clavier_SDL(sNomJ2, screen, message, font, position, textColor, fondColor); 
}


void Tour(int joueur,char sNomJ1[20],char sNomJ2[20],char nomSave[20], SDL_Color textColor,SDL_Color fondColor, char phrase2_affiche[])
{
	// Declaration des variables
	int i_col,i_lig;
	//les tours de jeux
    	int score1,score2;
    	
    	// Corps de la fonction 	
	if (joueur == 1){
	
		// Affichage nom joueur
		position.x = 520;
		position.y = 50;
		SDL_FreeSurface(message);
		sprintf(phrase2_affiche, "                                                  ");
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		sprintf(phrase2_affiche, "C'est au tour de %s                                                   \n", sNomJ1);
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		//afficher joueur à jouer
	}
	else if(joueur ==2){
		// Affichage nom joueur
		position.x = 520;
		position.y = 50;
		SDL_FreeSurface(message);
		sprintf(phrase2_affiche, "                                                  ");
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		sprintf(phrase2_affiche, "C'est a vous %s                                                     \n", sNomJ2);
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);

	}
    
	score(grille,&score1,&score2);                     
	pose_plus(joueur);
    
	// Affichage score des joueurs
	// score joueur 1
	sprintf(phrase2_affiche, "score de %s :%i                                                                         ",sNomJ1,score1); 
	position.x = 520;
	position.y = 10;
	afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
	// score joueur 2
	sprintf(phrase2_affiche, "score de %s :%i                                                                           ",sNomJ2,score2); 
	position.x = 520;
	position.y = 30;
	afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
	//affiche score
	afficher(grille);
    
   
    
    // Affichage instruction de jeu
	sprintf(phrase2_affiche, "Please click where your pion                      \n");
	position.x = 520;
	position.y = 70;
	afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);

    //gere l'entré des joueurs
    coor_clic = caseClicSouris();
	i_lig = coor_clic.y;
	i_col = coor_clic.x;
	// boucle tant que la souris ne clic pas une case jouable à ce tour 
	while ( (grille[i_col][i_lig] != 3) && (grille[i_col][i_lig] != 4)){
		//affichage erreur de saisi
			sprintf(phrase2_affiche, "entree incorect veulliez ressayer ");
			position.x = 520;
			position.y = 70;
			afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		// essai de nouveau de clic souris
		coor_clic = caseClicSouris();
		i_lig = coor_clic.y;
		i_col = coor_clic.x;
	
	}
	// placement du pion du joueur sur la case choisie
    	grille[i_col][i_lig]=joueur;
    convertir_coul(grille, i_col, i_lig);
    sauvegarde(nomSave);

}

int main(){
	// Declaration des variables
	initgrille();
	char *nomSave;
	int bChargement; //gere le chargemant
	int iJoueur=1;
	int nbJoueur=2;
	int score1,score2;
	int continuer=1;
	char sNomJ1[20] =" ", sNomJ2[20]=" ";
	char phrase2_affiche[200];
	SDL_Color textColor = { 255, 255, 255 };
	SDL_Color fondColor = { 94, 110, 40 };
	//
	
    
	// positionnement texte dans interface
	/* On écrit dans la chaîne "phrase2_affiche" la nouvelle phrase */
	sprintf(phrase2_affiche, "entrez 1 pour charger et visioner une ancienne partie ");
	position.x = 520;
	position.y = 10;
	// envoie vers fonction affichage interface
	afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
    
	// autre affichage
	sprintf(phrase2_affiche, "entrez 2 pour charger jouer ");
	position.x = 520;
	position.y = 30;
	afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
    
	// saisie utilisateur
	bChargement=saisie_chiffre_interface_SDL();   	
	while((bChargement<1) || (bChargement>2)){
		if (bChargement== -1) {
			printf ("\n erreur fonction saisie\n");
		}
		bChargement=saisie_chiffre_interface_SDL();
			
	}
    
	if (bChargement==1){
        chargement(textColor, fondColor, phrase2_affiche);
        if (!parcourir())
            return 0;
    }
    
    
    
	
    addgrille(3,3,noire);
    addgrille(4,4,noire);
    addgrille(4,3,blanc);
    addgrille(3,4,blanc);
	
    nomSave = FirstSauvegarde(textColor,fondColor, phrase2_affiche);
    
	NomJoueur(sNomJ1,sNomJ2, textColor, fondColor, phrase2_affiche);
	
	while(continuer)
	{
		// on détermine le type, l'état de chaque case de la grille
        	laPlacePossible(iJoueur,grille);
        	if(VerifieFinPartie()!=0){
        	// si partie non finie, on fait tour de jeu
        		Tour(iJoueur, sNomJ1, sNomJ2, nomSave, textColor, fondColor, phrase2_affiche);
            		passJoueur(&iJoueur,&nbJoueur);
            	}
            	else{
            		continuer=0;
            		//affichage fin de partie
			sprintf(phrase2_affiche, "Fin de partie ");
			position.x = 520;
			position.y = 300;
			afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
                	break;//si aucun joueur ne peut jouer on sort du while (fin de jeux)
            }
		
	}
	
	
		score(grille,&score1,&score2);
		if (score1>score2){
			//affichage gagnant j1
			sprintf(phrase2_affiche, "Le gagnant est : %s \n",sNomJ1);
			position.x = 520;
			position.y = 190;
			afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);

			/*
			savescore(sNomJ1,1);
			savescore(sNomJ2,-1);
			*/
			}
		if (score2>score1){
			//affichage gagnant j2
			sprintf(phrase2_affiche, "Le gagnant est : %s \n",sNomJ2);
			position.x = 520;
			position.y = 190;
			afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);

			/*
			savescore(sNomJ1,-1);
			savescore(sNomJ2,1);
			*/
			}
			
	if(score1==score2){
		//affichage Egalité j1 et j2
		sprintf(phrase2_affiche, "Egalité!\n");
		position.x = 520;
		position.y = 190;
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);

			/*
			savescore(sNomJ1,0);
			savescore(sNomJ2,0);
			*/
	}
	//affichage affiche score
	sprintf(phrase2_affiche, " score de %s: %i... score de %s: %i \n",sNomJ1,score1,sNomJ2,score2);
	position.x = 520;
	position.y = 210;
	afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);	

	// fermeture programme
	position.x = 520;
	position.y = 480;
	pause_fin_affichage_SDL (screen, message, font, position, textColor, fondColor);	

	
    return 0;
    
}

