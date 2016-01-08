#include <SDL/SDL.h>
#include "SDL_draw.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>

void chargement(SDL_Color textColor,SDL_Color fondColor, char phrase2_affiche[]);
void sauvegarde();
void afficher3(int k, int i_width, int i_height);
int parcourir(SDL_Color textColor,SDL_Color fondColor, char phrase2_affiche[]);
char* FirstSauvegarde(SDL_Color textColor,SDL_Color fondColor,char phrase2_affiche[]);
