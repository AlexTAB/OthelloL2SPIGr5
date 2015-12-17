
#include <stdio.h>

#include "grille.h"

void tracePlateauCaseTransparante(SDL_Surface * surf, int i_posY,
 int i_posX, int i_nb_intervales, int i_width, int i_height, int i_choixCouleur)
{
	/*! fonction de tracer du plateau de jeu */
	
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
 

// Fonctions du programme principal


void initgrille()
{
	int i,j;
	// Initialisation fonctions Dessin SDL
	screen=SDL_SetVideoMode(810,810,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	couleur[0]=SDL_MapRGB(screen->format,255,200,255); /** white black */
	couleur[1]=SDL_MapRGB(screen->format,255,255,255); /** white */
	couleur[2]=SDL_MapRGB(screen->format,0,0,0); /** black */
	couleur[3]=SDL_MapRGB(screen->format,255,0,0);/** red */
	couleur[4]=SDL_MapRGB(screen->format,100,120,50); /** color unknown */
	couleur[5]=SDL_MapRGB(screen->format,0,250,0); /** green */
	couleur[6]=SDL_MapRGB(screen->format,94,110,40); /** green soft */
	SDL_Init(SDL_INIT_VIDEO);
	SDL_FillRect(screen,0,couleur[6]); /* une seule fenetre peut etre créée, a mettre dans le main*/
	/* donne un fond green soft à la fenêtre */
		/* intialisation de couleur avec leurs trois composantes RGB */

	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			grille[i][j]=vide;
SDL_Flip(screen);			
}

int addgrille(int iPosi,int iPosj,int color){
		int res = 1;
		
		
		if (iPosj>=0  && iPosj<N && iPosi>=0 && iPosi<N)
			grille[iPosi][iPosj]=color; // tout est ok !
		else
			res = 0; // ça s'est mal passé, ajout impossible
			
		
		/*if (iPosj<0 || iPosj>=M || iPosi<0 || iPosi>=N)
				res = 0; // ça s'est mal passé, ajout impossible
		else
			grille[iPosi][iPosj]=color; // tout est ok !*/
		return res;
}
		
		
void afficher(pion grille[N][M]){
	//initialisation des variables
	int i,j;
	//déclarations des couleur
	/* exemples de couleur avec leurs trois composantes RGB */
	
	for(i=0; i<7; i++)
	//trace plateau de case
	tracePlateauCaseTransparante(screen, 0, 0, 8, 800, 800, 2);

	// affichage
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++){
			if (grille[i][j]==0);
			else if (grille[i][j]==1)
				tracePion(screen, 0, 0, i, j, 8, 800, 800, 1, 100);
			else if (grille[i][j]==2)
			tracePion(screen, 0, 0, i, j, 8, 800, 800, 2, 100);
			else if (grille[i][j]==3)
				tracePion(screen, 0, 0, i, j, 8, 800, 800, 3, 50);
			else if (grille[i][j]==4)
				tracePion(screen, 0, 0, i, j, 8, 800, 800, 3, 25);
		}
	}

SDL_Flip(screen);
}
