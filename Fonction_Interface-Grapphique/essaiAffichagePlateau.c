// Structure générale d’un programme sous C et SDL
#include <SDL/SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//#define ... éventuellement

void pause(void);
void putpixel(int xe, int ye, Uint32 c);
void drawFullRect(SDL_Surface * surf, int i_posX, int i_posY, int i_width, int i_length, int i_choixCouleur);
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
	screen=SDL_SetVideoMode(900,900,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	
	char lettreFin;
	int i_choixCouleur, i_posX, i_posY, i_width, i_length;
	
	// Initialisation fonctions Dessin SDL
	/* exemples de couleurs avec leurs trois composantes RGB */
	couleur[0]=SDL_MapRGB(screen->format,255,255,255); /** white */
	couleur[1]=SDL_MapRGB(screen->format,255,0,0);/** red */
	couleur[2]=SDL_MapRGB(screen->format,0,250,0); /** vert */
	SDL_FillRect(screen,0,couleur[0]);
	/* donne un fond blanc à la fenêtre */
	
	//..... mettre ici le programme concerné
	
	SDL_Flip(screen);
	/* Cette fonction affiche l’image issue du programme sur l’écran. SI on ne le fait pas, on
	 * ne verra rien. On sera souvent amené à l’utiliser plusieurs fois dans le programme pour voir ce qui se passe */
	// Affichage console
	
	// Tracer un rectangle plein
	
	printf("\n Quelle est la couleur du fond rectangle? : ");
	scanf("%i", &i_choixCouleur);
	printf("\n Quelle est la cordonnée x du coin sup gauche du rectangle? : ");
	scanf("%i", &i_posX);
	printf("\n Quelle est la cordonnée x du coin sup gauche du rectangle? : ");
	scanf("%i", &i_posY);
	printf("\n Quelle est la largeur du rectangle? : ");
	scanf("%i", &i_width);
	printf("\n Quelle est la longueur du rectangle? : ");
	scanf("%i", &i_length);
	
	// test tracer rectangle
	drawFullRect(screen, i_posX, i_posY, i_width, i_length, i_choixCouleur);
	// envoie image tampon sur ecran
	SDL_Flip(screen);
	
	// test fin
	printf("\n Bonjour");
	printf("\n Le bas");
	printf("\n hello\n");
	scanf ("%c", &lettreFin);
	printf( "\n Buffer vider.\n Fin du test graphique .\n Au revoir \n Appuyer sur une lettre puis entrée pour clore le programme ");
	scanf ("%c", &lettreFin);
	
	 
	//pause();
	return 0;
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
