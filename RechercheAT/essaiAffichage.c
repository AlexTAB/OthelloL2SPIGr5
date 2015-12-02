// Structure générale d’un programme sous C et SDL
#include <SDL/SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#define ... éventuellement

void pause(void);
void putpixel(int xe, int ye, Uint32 c);
Uint32 getpixel(int xe, int ye);
//et declarations d’autres fonctions éventuellement

SDL_Surface * screen;
Uint32 white, black, couleur[100];

//déclarations des couleurs
//déclaration de variables globales éventuellement
int main(int argc, char ** argv)
	{
	//déclaration des variables locales
	SDL_Init(SDL_INIT_VIDEO);
	screen=SDL_SetVideoMode(800,600,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	/* exemples de couleurs avec leurs trois composantes RGB */
	couleur[0]=SDL_MapRGB(screen->format,255,255,255); /** white */
	couleur[1]=SDL_MapRGB(screen->format,255,0,0);/** red */
	couleur[2]=SDL_MapRGB(screen->format,0,250,0); /** vert */
	SDL_FillRect(screen,0,couleur[0]);
	/* donne un fond blanc à la fenêtre */
	//..... mettre ici le programme concerné
	SDL_Flip(screen);
	/* Cette fonction affiche l’image issue du programme sur l’écran. SI on ne le fait pas, onne verra rien. On sera souvent amené à l’utiliser plusieurs fois dans le programme pour voir ce qui se passe */
	pause();
	return 0;
}

void pause(void)
{
	SDL_Event evenement;
	do SDL_WaitEvent(&evenement);
	while(evenement.type != SDL_QUIT && evenement.type != SDL_KEYDOWN);
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
