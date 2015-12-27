
#include <stdio.h>

#include "grille.h"
int i_width = 500;
int i_height =500;

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
	screen=SDL_SetVideoMode(i_width + 10,i_height + 10,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
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
			
		return res;
}
		
		
void afficher(pion grille[N][M]){
	//initialisation des variables
	int i,j;
	//déclarations des couleur
	/* exemples de couleur avec leurs trois composantes RGB */
	
	for(i=0; i<7; i++)
	//trace plateau de case
	tracePlateauCaseTransparante(screen, 0, 0, 8, i_width, i_height, 2);

	// affichage
	for(i=0;i<N;i++){
		printf("\n");
		for(j=0;j<M;j++){
			if (grille[i][j]==0)
				tracePion(screen, 0, 0, i, j, 8, i_width, i_height, 6, 100);
			else if (grille[i][j]==1)
				tracePion(screen, 0, 0, i, j, 8, i_width, i_height, 1, 100);
			else if (grille[i][j]==2)
				tracePion(screen, 0, 0, i, j, 8, i_width, i_height, 2, 100);
			else if (grille[i][j]==3)
				tracePion(screen, 0, 0, i, j, 8, i_width, i_height, 3, 50);
			else if (grille[i][j]==4)
				tracePion(screen, 0, 0, i, j, 8, i_width, i_height, 3, 25);
		}
	}

SDL_Flip(screen);
}
t_coor_case resultcoor(int corx,int cory, int i_nb_intervales, int i_width, int i_height)
{
	//diviser la grille
	// déclaration variable
	int coorx,coory;
	// déclaration structure coordonnées case
	t_coor_case coord_case;
	// déclaration taillev case largeur et hauteur
	int i_width_case = ((i_width-i_nb_intervales+1) / i_nb_intervales);
	int i_height_case = ((i_height-i_nb_intervales+1) / i_nb_intervales);
	// calcul a quelle cordonnées de case appartient celle de la souris
	coorx=corx/i_width_case;
	coory=cory/i_height_case;
	// transfert dans structure
	coord_case.x=coorx;
	coord_case.y=coory;
	return coord_case;
} 

t_coor_case caseClicSouris()
{
	// détermine la case du plateau de jeu cliquer par la souris
	// déclaration des variables
	int i,j;
	SDL_Event evenement;
	t_coor_case t_coord_case;
	int continuer=1;
	// corps de la fonction
	// boucle attente evenement
	while(continuer)
	{	SDL_WaitEvent(&evenement);
		switch(evenement.type)
		{
			case SDL_QUIT:
				continuer=0;
				printf ("\n on quitte");
				break;
			case SDL_MOUSEBUTTONUP : /*clic de souris*/
				// clic gauche de souris
				if(evenement.button.button==SDL_BUTTON_LEFT)
				{
					i = evenement.button.x;
					j = evenement.button.y;
					t_coord_case = resultcoor(i,j, 8, i_width, i_height);
					continuer = 0;
					
					return t_coord_case;
					break;
				}
				
			default :
				continuer =1;
				break;
		}
		
	}
	return t_coord_case;		
}
