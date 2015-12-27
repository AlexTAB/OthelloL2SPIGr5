// Structure générale d’un programme sous C et SDL
#include <SDL/SDL.h>
#include "SDL_draw.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#define ... éventuellement
#define N 8
#define M 8

typedef enum {vide, blanc, noire, possible, le_plus} pion;
typedef struct {int x;int y} t_coor;
t_coor coor;

pion grille[N][M];


void pause(void);
void putpixel(int xe, int ye, Uint32 c);
void drawFullRect(SDL_Surface * surf, int i_posX, int i_posY, int i_width, int i_length, int i_choixCouleur);
Uint32 getpixel(int xe, int ye);
void tracePlateauCaseTransparante(SDL_Surface * surf, int i_posY,
 int i_posX, int i_nb_intervales, int i_width, int i_height, int i_choixCouleur);
void tracePion(SDL_Surface * surf, int i_posX, int i_posY, int i_cordonnee_grille_i, int i_cordonnee_grille_j, int i_nb_intervales, int i_width, int i_height, int i_choixCouleur, float f_proportion_cercle);

// fonction du programme principale
void initgrille();
void addgrille(int iPosi,int iPosj,int color);
void afficher(SDL_Surface * surf);

t_coor resultcoor(int corx,int cory, int i_nb_intervales, int i_width, int i_height)
{
	//diviser la grille
	// déclaration variable
	int coorx,coory;
	// déclaration taillev case largeur et hauteur
	int i_width_case = ((i_width-i_nb_intervales+1) / i_nb_intervales);
	int i_height_case = ((i_height-i_nb_intervales+1) / i_nb_intervales);
	// calcul a quelle cordonnées de case appartient celle de la souris
	coorx=corx/i_width_case;
	coory=cory/i_height_case;
	// transfert dans structure
	coor.x=coorx;
	coor.y=coory;
	return coor;
} 
	
//Declarations d’autres fonctions éventuellement

SDL_Surface * screen;
Uint32 white, black, couleur[100];

//déclarations des couleurs
//déclaration de variables globales éventuellement
int main(int argc, char ** argv)
{
	//déclaration des variables locales
	SDL_Init(SDL_INIT_VIDEO);
	screen=SDL_SetVideoMode(900,900,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	
	char lettreFin;
	int i_choixCouleur, i_posX, i_posY, i_width, i_length;
	
	// Initialisation variables
	i_choixCouleur = 0;
	i_posX = 0;
	i_posY = 0;
	i_width = 100;
	i_length = 100;

	// Initialisation fonctions Dessin SDL
	/* exemples de couleurs avec leurs trois composantes RGB */
	couleur[1]=SDL_MapRGB(screen->format,255,255,255); /** white */
	couleur[3]=SDL_MapRGB(screen->format,255,0,0);/** red */
	couleur[5]=SDL_MapRGB(screen->format,0,250,0); /** green */
	couleur[2]=SDL_MapRGB(screen->format,0,0,0); /** black */
	couleur[6]=SDL_MapRGB(screen->format,94,110,40); /** green soft */

	//drawFullRect(screen, i_posX, i_posY, i_width, i_length, i_choixCouleur);
	//
	SDL_FillRect(screen,0,couleur[6]); /* nune seul fenetre peut etre crée, a mettre dans le main*/
	SDL_Flip(screen);
	/* donne un fond green soft à la fenêtre */
	//..... mettre ici le programme concerné
	//tracePlateauCaseTransparante(screen, 0, 0, 8, 800, 800, 255);
	// initialisation debut jeu
	initgrille();
    addgrille(3,3,noire);
    addgrille(4,4,noire);
    addgrille(4,3,blanc);
    addgrille(3,4,blanc);
    // affichage plateau depart
      afficher(screen);
      SDL_Flip(screen);
      pause();
	SDL_Flip(screen);
	return 0;
}

void tracePlateauCaseTransparante(SDL_Surface * surf, int i_posY,
 int i_posX, int i_nb_intervales, int i_width, int i_height, int i_choixCouleur)
{
	int i;
	
	int i_width_case = ((i_width-i_nb_intervales+1) / i_nb_intervales);
	int i_height_case = ((i_height-i_nb_intervales+1) / i_nb_intervales);
	
	for (i=0 ; i <= i_nb_intervales; i++) {
		// tracer les lignes horizontales
		SDL_Rect ligneHorizontale;
		ligneHorizontale.x = i_posX;
		ligneHorizontale.y = (i_posY + (i * i_width_case)); /* Espace entre ligne à chaque tour */
		ligneHorizontale.w = i_height;
		ligneHorizontale.h = 1;
 
		SDL_FillRect(surf, &ligneHorizontale, couleur[i_choixCouleur]);
		
		// tracer les lignes verticales
		SDL_Rect ligneVerticale;
		ligneVerticale.x = i_posX + (i * i_height_case);
		ligneVerticale.y = i_posY ; /* Espace entre ligne à chaque tour */
		ligneVerticale.w = 1;
		ligneVerticale.h = i_width;
 
		SDL_FillRect(surf, &ligneVerticale, couleur[i_choixCouleur]);
		
	}
	
	
	

}
void tracePion(SDL_Surface * surf,int i_posX, int i_posY, int i_cordonnee_grille_i, int i_cordonnee_grille_j, int i_nb_intervales, int i_width, int i_height, int i_choixCouleur, float f_proportion_cercle)
{
	// trace le pion
	
	// determination taille case
	int i_width_case = ((i_width-i_nb_intervales+1) / i_nb_intervales);
	int i_height_case = ((i_height-i_nb_intervales+1) / i_nb_intervales);
	float f_rayon = (((i_width_case-2) / 2)*(f_proportion_cercle/100));
	// initialisation coordonnes pion
	int i_cordX_centre = ((i_posX + (i_height_case/2)) +(i_cordonnee_grille_i * i_height_case));
	int i_cordY_centre = ((i_posY + (i_width_case/2)) +(i_cordonnee_grille_j * i_width_case));

	
	Draw_FillCircle(screen, i_cordX_centre, i_cordY_centre, f_rayon, couleur[i_choixCouleur]);
	
}
void drawEmptyRect(SDL_Surface * surf,int i_posX, int i_posY, int i_width, int i_length, int i_choixCouleur)
{
	SDL_Rect ligneHaut;
	ligneHaut.x = i_posX-1;
	ligneHaut.y = i_posY-1;
	ligneHaut.w = i_length;
	ligneHaut.h = 1;
 
	SDL_FillRect(surf, &ligneHaut, couleur[i_choixCouleur]);
 
	SDL_Rect ligneDroite;
	ligneDroite.x = i_posX + i_length-1;
	ligneDroite.y = i_posY-1;
	ligneDroite.w = 1;
	ligneDroite.h = i_width;
 
	SDL_FillRect(surf, &ligneDroite, couleur[i_choixCouleur]);
 
	SDL_Rect ligneGauche;
	ligneGauche.x = i_posX-1;
	ligneGauche.y = i_posY-1;
	ligneGauche.w = 1;
	ligneGauche.h = i_width;
 
	SDL_FillRect(surf, &ligneGauche, couleur[i_choixCouleur]);
 
	SDL_Rect ligneBas;
	ligneBas.x = i_posX - 1;
	ligneBas.y = i_posY + i_width-1;
	ligneBas.w = i_length;
	ligneBas.h = 1;
 
	SDL_FillRect(surf, &ligneBas, couleur[i_choixCouleur]);
}
void drawFullRect(SDL_Surface * surf, int i_posX, int i_posY, int i_width, int i_length, int i_choixCouleur)
{
	SDL_Rect Rect;
	Rect.x = i_posX;
	Rect.y = i_posY;
	Rect.w = i_length-1;
	Rect.h = i_width-1;
 
	SDL_FillRect(surf, &Rect, couleur[i_choixCouleur]);
}

void pause(void)
{
	int i,j;
	SDL_Event evenement;
	int continuer=1;
	while(continuer)
	{	SDL_WaitEvent(&evenement);
		switch(evenement.type)
		{
			case SDL_QUIT:
				continuer=0;
				printf ("\n on quitte");
				break;
			case SDL_MOUSEBUTTONUP : /*clic de souris*/
				printf("\n un clic de souris");
				if(evenement.button.button==SDL_BUTTON_LEFT)
				{
					i = evenement.button.x;
					j = evenement.button.y;
					resultcoor(i,j, 8, 900, 900);
					tracePion(screen, 0, 0, coor.x, coor.y, 8, 900, 900, 1, 50);
					printf("\n La souris a été cliquée en bouton gauche au cordonnée case x : %i et y : %i ", coor.x, coor.y);
					printf("\n La souris a été cliquée en bouton gauche au cordonnée x : %i et y : %i ", i, j);
					SDL_Flip(screen);
				}
				
			default :
				continuer =1;
				printf("\nun eve");
				break;
		}
		
	}
		
}
void putpixel(int xe, int ye, Uint32 c)
{
	 Uint32 * numerocase;
	numerocase= (Uint32 *)(screen->pixels)+xe+ye*screen->w; *numerocase=c;
}
Uint32 getpixel(int xe, int ye)
{ 
	Uint32 * numerocase;
	numerocase= (Uint32 *)(screen->pixels)+xe+ye*screen->w; 
	return (*numerocase);
}
// Fonctions du programme principal


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
		
		
void afficher(SDL_Surface * surf){
	int i,j;
	
	//trace plateau de case
	tracePlateauCaseTransparante(screen, 0, 0, 8, 900, 900, 0);


	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++){
			if (grille[i][j]==0){
				printf("| |");
				}
			else if (grille[i][j]==1){
				tracePion(screen, 0, 0, i, j, 8, 900, 900, 1, 50);
				printf("|-|");
			}
			else if (grille[i][j]==2){
				tracePion(screen, 0, 0, i, j, 8, 900, 900, 2, 50);
				printf("|+|");
			}
			else if (grille[i][j]==3)
				printf("|*|");
			else if (grille[i][j]==4)
				printf("|°|");
		}
	}


}
