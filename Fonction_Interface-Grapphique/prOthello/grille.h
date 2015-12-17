
#include "pion.h"
#include <SDL/SDL.h>
#include "SDL_draw.h"
#include <math.h>
#include <stdlib.h>
#define N 8
#define M 8
SDL_Event evenement;
SDL_Surface * screen;

Uint32 couleur[100];
	
pion grille[N][M];

void tracePlateauCaseTransparante(SDL_Surface * surf, int i_posY,
 int i_posX, int i_nb_intervales, int i_width, int i_height, int i_choixCouleur);
void tracePion(SDL_Surface * surf, int i_posX, int i_posY, int i_cordonnee_grille_i, int i_cordonnee_grille_j, int i_nb_intervales, int i_width, int i_height, int i_choixCouleur,
 float f_proportion_cercle);
void initgrille();
int addgrille(int iPosi,int iPosj,int color);
void afficher(pion grille[N][M]);

