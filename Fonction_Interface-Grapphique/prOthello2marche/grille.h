
#include "pion.h"
#include <SDL/SDL.h>
#include "SDL_draw.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <stdlib.h>
#define N 8
#define M 8

//La structure d'événement 
SDL_Event evenement;

//Les surfaces 
SDL_Surface *background; 
SDL_Surface *message; 
SDL_Surface *screen;
SDL_Rect position;

//Le Font qu'on va utiliser
TTF_Font *font; 

// Les couleurs 
Uint32 couleur[100];

//La couleur du Font de la Police de caractere


// Les matrices de structures	
pion grille[N][M];

// Variables lié affichagz sdl



int init_Fonction_SDL(char s_titre_jeu[]);
int load_files_Ouverture_stylePolice();
void clean_up_Fermeture_SDL();
void tracePlateauCaseTransparante(SDL_Surface * surf, int i_posY,
 int i_posX, int i_nb_intervales, int i_width, int i_height, int i_choixCouleur);
void tracePion(SDL_Surface * surf, int i_posX, int i_posY, int i_cordonnee_grille_i, int i_cordonnee_grille_j, int i_nb_intervales, int i_width, int i_height, int i_choixCouleur,
 float f_proportion_cercle);
void initgrille();
int addgrille(int iPosi,int iPosj,int color);
void afficher(pion grille[N][M]);
t_coor_case resultcoor(int corx,int cory, int i_nb_intervales, int i_width, int i_height);
t_coor_case caseClicSouris();
int afficher_message_interface_SDL (SDL_Surface *screen, SDL_Surface *message, char phrase2_affiche[200], TTF_Font *font, SDL_Rect position,	SDL_Color textColor, SDL_Color fondColor);
int saisie_chiffre_interface_SDL();
int saisie_nombre_interface_SDL();
void mot_saisi_Clavier_SDL(char s_mot_saisi[], SDL_Surface *screen, SDL_Surface *message, TTF_Font *font, SDL_Rect position, SDL_Color textColor, SDL_Color fondColor);
void pause_fin_affichage_SDL(SDL_Surface *screen, SDL_Surface *message, TTF_Font *font, SDL_Rect position,	SDL_Color textColor, SDL_Color fondColor);
void efface_texte_carre_gomme(SDL_Surface * screen, int i_posY,
 int i_posX, int i_width, int i_height, int i_choixCouleur);
