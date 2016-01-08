
#include <stdio.h>

#include "grille.h"

	

int i_width = 900;
int i_height =500;
char s_titre_jeu[100]="othello";
int i_large_zone_texte = 400;

int init_Fonction_SDL(char s_titre_jeu[])
{ 
	//Initialisation de tous les sous-systèmes de SDL 
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) { 
		return 0; 
	} 

	//Mise en place de l'écran 
	screen=SDL_SetVideoMode(i_width + 10,i_height + 10,32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_Color textColor={255, 255, 255};
	//S'il y a une erreur dans la mise en place de l'écran 
	if( screen == NULL ) { 
		return 0; 
	} 

	//Initialisation de SDL_TTF 
	if( TTF_Init() == -1 ) { 
		return 0; 
	} 

	//Mise en place de la barre caption 
	SDL_WM_SetCaption( s_titre_jeu, NULL ); 

	//Si tout s'est bien passé 
	return 1;
}
int load_files_Ouverture_stylePolice() 
{
	
	//Ouverture du Font 
	font = TTF_OpenFont( "caslon_b.ttf", 14 ); 
	
	//S'il y a une erreur dans le chargement du Font 
	if( font == NULL ) { 
		return 0; 
	} 
	
	//Si tout s'est bien chargé 
	return 1; 
}
void clean_up_Fermeture_SDL() 
{ 
	//Libération des surfaces 
	SDL_FreeSurface( background ); 
	SDL_FreeSurface( message ); 

	//Fermeture des Fonts qu'on a utilisé 
	TTF_CloseFont( font ); 

	//On quitte SDL_ttf 
	TTF_Quit(); 

	//On quitte SDL 
	SDL_Quit(); 
}
 
void tracePlateauCaseTransparante(SDL_Surface * surf, int i_posY,
 int i_posX, int i_nb_intervales, int i_width, int i_height, int i_choixCouleur)
{
	/*! fonction de tracer du plateau de jeu */
	
	int i;
	
	int i_width_case = ((i_width-(i_nb_intervales+1+i_large_zone_texte)) / i_nb_intervales);
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
	int i_width_case = ((i_width-(i_nb_intervales+1+i_large_zone_texte)) / i_nb_intervales);
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
	if (!(init_Fonction_SDL(s_titre_jeu))) {
		printf("\n Erreur Initialisation fonctions Dessin SDL");
	}
	if (!(load_files_Ouverture_stylePolice())){
		printf("\n Erreur Chargement Police de caractère TTF");
	}
		
	/* intialisation de couleur avec leurs trois composantes RGB */
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
	SDL_FreeSurface(message);
	//trace plateau de case
	tracePlateauCaseTransparante(screen, 0, 0, 8, i_width, i_height, 2);

	// affichage
	for(i=0;i<N;i++){
		
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
int afficher_message_interface_SDL (SDL_Surface *screen, SDL_Surface *message, char phrase2_affiche[], TTF_Font *font, SDL_Rect position,	SDL_Color textColor, SDL_Color fondColor)
{
	// affiche texte
	SDL_FreeSurface(message); /* On supprime la surface précédente */
	//Mise en place du texte sur la surface message 
	message = TTF_RenderText_Shaded( font, phrase2_affiche, textColor, fondColor ); 

	//S'il y a une erreur dans la mise en place du texte 
			if( message == NULL ) {
				printf("\n erreur message \n"); 
				return 1; 
			} 
        		
        		SDL_BlitSurface(message, NULL, screen, &position); /* Blit du texte */
        		SDL_Flip(screen);

			//apply_surface( 0, 0, background, screen 

			//Mise à jour de l'écran 
			if( SDL_Flip( screen ) == -1 ) { 
				printf("\n erreur mise à jour écran \n"); 
				return 1; 
			}
	return 1;
}

int saisie_chiffre_interface_SDL()
{
	// saisie chiffre par le pavé
	// Déclaration des variables
	SDL_Event evenement;
	int i_continuer_saisie = 1;
	
	//corps fonction
	// Boucle
	while(i_continuer_saisie){
	// 	
		SDL_WaitEvent(&evenement);	
		switch(evenement.type) {
			case SDL_QUIT:
				i_continuer_saisie = 0;
				return -1;
				break;
			case SDL_KEYDOWN:
				switch(evenement.key.keysym.sym) {
					case SDLK_KP0: //touche 0
						i_continuer_saisie = 0;
						return 0;
						break;
					case SDLK_KP1: //touche 1
            					i_continuer_saisie = 0;
						return 1;
						break;
					case SDLK_KP2: //touche 2
            			//Mise à jour de l'écran 
			if( SDL_Flip( screen ) == -1 ) { 
				printf("\n erreur mise à jour écran \n"); 
				return 1; 
			}		i_continuer_saisie = 0;
						return 2;
						break;
					case SDLK_KP3: //touche 3
            					i_continuer_saisie = 0;
						return 3;
						break;
					case SDLK_KP4: //touche 4
            					i_continuer_saisie = 0;
						return 4;
						break;
					case SDLK_KP5: //touche 5
            					i_continuer_saisie = 0;
						return 5;
						break;
					case SDLK_KP6: //touche 6
            					i_continuer_saisie = 0;
						return 6;
						break;
					case SDLK_KP7: //touche 7
            					i_continuer_saisie = 0;
						return 7;
						break;
					case SDLK_KP8: //touche 8
            					i_continuer_saisie = 0;
						return 8;
						break;
					case SDLK_KP9: //touche 9
            					i_continuer_saisie = 0;
						return 9;
						break;
					default :
						break;
				}

        		default :
        			break;
		}
	}
return -1;
}

int saisie_nombre_interface_SDL()
{
	// saisie nombre par le pavé
	// Déclaration des variables
	SDL_Event evenement;
	int i_continuer_saisie = 1;
	int i_nombre_saisi =0;
	int i_nombre_negatif = 1;
	//corps fonction
	// Boucle
	while(i_continuer_saisie){
	
			
		SDL_WaitEvent(&evenement);	
		switch(evenement.type) {
			case SDL_QUIT:
				i_continuer_saisie = 0;
				break;
			case SDL_KEYDOWN:
				// 	
				if (i_nombre_saisi !=0) {
					// condition
					i_nombre_saisi=i_nombre_saisi*10;
				}
				switch(evenement.key.keysym.sym) {
					case SDLK_MINUS: //touche -
						i_nombre_negatif = -1;
						break;
					case SDLK_KP0: //touche 0
						i_nombre_saisi = i_nombre_saisi + 0;
						break;
					case SDLK_KP1: //touche 1
            					i_nombre_saisi = i_nombre_saisi+1;
            					// affichage saisie
            					
						break;
					case SDLK_KP2: //touche 2
            					i_nombre_saisi = i_nombre_saisi +2;
						break;
					case SDLK_KP3: //touche 3
            					i_nombre_saisi = i_nombre_saisi+3;
						break;
					case SDLK_KP4: //touche 4
            					i_nombre_saisi = i_nombre_saisi+4;
						break;
					case SDLK_KP5: //touche 5
            					i_nombre_saisi = i_nombre_saisi+5;
						break;
					case SDLK_KP6: //touche 6
            					i_nombre_saisi = i_nombre_saisi +6;
						break;
					case SDLK_KP7: //touche 7
            					i_nombre_saisi = i_nombre_saisi +7;
						
						break;
					case SDLK_KP8: //touche 8
            					i_nombre_saisi = i_nombre_saisi+8;
						break;
					case SDLK_KP9: //touche 9
            					i_nombre_saisi = i_nombre_saisi +9;
						break;
					case SDLK_RETURN: /*return*/
						i_nombre_saisi = i_nombre_saisi/10;
            					i_continuer_saisie = 0;
						break;
					default :
						break;
				}

        		default :
        			break;
		}
	}
	i_nombre_saisi=i_nombre_saisi* i_nombre_negatif;
	printf("\n le nombre saisi est %i \n", i_nombre_saisi);
	return i_nombre_saisi;
}

void mot_saisi_Clavier_SDL(char s_mot_saisi[], SDL_Surface *screen, SDL_Surface *message, TTF_Font *font, SDL_Rect position, SDL_Color textColor, SDL_Color fondColor)
{
	char c_lettre_saisie;
	int i_index=0;
	int i_continuer_saisie=0;
	SDL_Event evenement;
	
     	// initialisation - mis a vide des variable
     	sprintf(s_mot_saisi, " ");
     	
     	// boucle
	while (!i_continuer_saisie) {
		afficher_message_interface_SDL (screen, message, s_mot_saisi, font, position, textColor, fondColor);
		SDL_WaitEvent(&evenement);
		 
		if (evenement.type==SDL_KEYDOWN){
			/*si on appuie sur une touche*/
			c_lettre_saisie=evenement.key.keysym.sym;
			if (c_lettre_saisie>=SDLK_a && c_lettre_saisie<=SDLK_z){
				// si entre a et z
				s_mot_saisi[i_index]=c_lettre_saisie;/*on met la lettre saisie dans la chaine s_mot_saisi*/
				
				// affichage de la lettre
				
				i_index++;/*on se prépare à recevoir la prochaine lettre*/
			}
             		if (c_lettre_saisie==SDLK_BACKSPACE && i_index) {
             			/*corerction si on se trompe*/
				i_index--;
 			}            
			if (c_lettre_saisie==SDLK_RETURN) {
				/*return*/
				s_mot_saisi[i_index]='\0';/*on met la fin de chaine*/              
				i_continuer_saisie=1;
			}
		}
	}
	
}

void pause_fin_affichage_SDL(SDL_Surface *screen, SDL_Surface *message, TTF_Font *font, SDL_Rect position, SDL_Color textColor, SDL_Color fondColor)
{
	// Fait une pause de fin de partie pour permettre de voir l'affgichage et demande confirmation
	// pour la cloture du programme	
	
	// Déclaration des variables
	char c_lettre_saisie;
	int i_continuer_saisie=0;
	char s_phrase_fin_prog[300] = "Appuyer sur entree pour quitter";
	SDL_Event evenement;
    
    //Corps de la fonction
    //Affichage texte de fin 
	afficher_message_interface_SDL (screen, message, s_phrase_fin_prog, font, position, textColor, fondColor);
	
	//boucle
	while (!i_continuer_saisie) {

		SDL_WaitEvent(&evenement);
         
		if (evenement.type==SDL_QUIT){
			// si on appui sur fermer pour quitter
			i_continuer_saisie = 1;
		}	
		if (evenement.type==SDL_KEYDOWN){
			/*si on appuie sur une touche*/
			c_lettre_saisie=evenement.key.keysym.sym;           
			if (c_lettre_saisie==SDLK_RETURN) {
				/*return*/
				             
				i_continuer_saisie=1;
			}
		}
	}
	
}
void efface_texte_carre_gomme(SDL_Surface * screen, int i_posY,
 int i_posX, int i_width, int i_height, int i_choixCouleur)
{
	// efface en recouvrant une zone
	SDL_Rect zoneGomme;
	zoneGomme.x = i_posX;
	zoneGomme.y = i_posY;
	// taille zone 
	zoneGomme.w = i_width;
	zoneGomme.h = i_height;
		
	//mis en tampon
 	SDL_FillRect(screen, &zoneGomme, couleur[i_choixCouleur]);
 		
 	// affichage tampon à l'écran
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
	int i_width_case = ((i_width-(i_nb_intervales+1+i_large_zone_texte)) / i_nb_intervales);
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
		switch(evenement.type) {
			case SDL_QUIT:
				continuer=0;

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
