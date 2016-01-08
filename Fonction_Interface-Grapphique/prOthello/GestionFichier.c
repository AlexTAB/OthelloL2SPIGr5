#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include "SDL_draw.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include"GestionFichier.h"
#include"grille.h"
#define N 8
#define M 8
#define P N*M



pion grille[N][M];

SDL_Rect position;
SDL_Surface *message; 
SDL_Surface *screen;
SDL_Rect position;

TTF_Font *font;



int matrice3[P][N][M]={{{0}}};//le but ici est de créer un tableau de matrices qu'on utilisera comme une liste de matrices

void afficher3(int k){
    int i,j;
    for(i=0;i<N;i++){
        printf("\n");
        for(j=0;j<M;j++){
            if (matrice3[k][i][j]==0)
                printf("| |");
            else if (matrice3[k][i][j]==1)
                printf("|-|");
            else if (matrice3[k][i][j]==2)
                printf("|+|");
            else if (matrice3[k][i][j]==3)
                printf("|*|");
            else if (matrice3[k][i][j]==4)
                printf("|°|");
        }
    }
}


char* FirstSauvegarde(SDL_Color textColor,SDL_Color fondColor,char phrase2_affiche[]){//on met la grille dans un fichier entrer par l'utilisateur
	FILE * fic;
	int bSupfic=0;
	int iDemande=0;
	char* sNom;
	sNom = malloc(20*sizeof(char));
	
	
	while (!bSupfic){ 
	//ici sont les option qui vérifie que l'utilisateur sauvegarde bien ou il veut sans suprimer des sauvegardes si il ne voulait pas.
		// Affichage partie à sauvegarde
		sprintf(phrase2_affiche, "entrez le nom de votre sauvegarde et ");
	// terminé par Entree:  "); 
		position.x = 520;
		position.y = 10;
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		sprintf(phrase2_affiche, "terminer par Entree pour valider votre saisie : ");
		position.x = 520;
		position.y = 30;
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		// saisie utilisateur nom du fichier
		position.x = 520;
		position.y = 50;
		mot_saisi_Clavier_SDL(sNom, screen, message, font, position, textColor, fondColor); 

	if (fopen(sNom,"r")!=NULL){
		//Condition
		// Affichage partie déja sauvegarde
		sprintf(phrase2_affiche, "cette sauvegarde existe deja voulez vous la supprimer?:"); 
		position.x = 520;
		position.y = 10;
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		
		// affichage choix suppression
		sprintf(phrase2_affiche, "1:oui                                                                               "); 
		position.x = 520;
		position.y = 30;
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		sprintf(phrase2_affiche, "2:non                                                                        "); 
		position.x = 520;
		position.y = 50;
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		
		// saisie utilisateur du choix
		iDemande=saisie_chiffre_interface_SDL();
		while(iDemande==0){
			//v affichage re essai choix
			sprintf(phrase2_affiche, "Rentrez 1 ou 2  "); 
			position.x = 520;
			position.y = 70;
			afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
			// nouvelle saisie
			iDemande=saisie_chiffre_interface_SDL();
		}
    
            if (iDemande==1)
                bSupfic=1;
            else
                bSupfic=0;

        }
        else{
            bSupfic=1;
        }
    }
    if (bSupfic==1){
		fic = fopen(sNom,"w");
    

		int i,j;//on met les données de la grille dans la sauvegarde
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
				fprintf(fic,"%i ",grille[i][j]);
			}
		}
		sprintf(phrase2_affiche, " sauvegarde cree :  %s                                                                  \n", sNom); 
		position.x = 520;
		position.y = 10;
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		
		fclose(fic);
	}
    return sNom;
}

void sauvegarde(char sNom[20]){
	
	// déclaration des variable
        FILE * fic;
        fic = fopen(sNom,"a");
        
        int i,j;//on met les données de la grille dans la sauvegarde
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                fprintf(fic,"%i ",grille[i][j]);
            }
        }
        
        fclose(fic);
}




void chargement(SDL_Color textColor,SDL_Color fondColor, char phrase2_affiche[]){
	//on charge un fichier que l'utilisateur à choisit dans une file
    	FILE * fic;
    	char sNom[20]={0};
    
    	do{
    		//verification si sauvegarde existe
    
    		// Affichage sauvegarde à charger
		sprintf(phrase2_affiche, "quelle sauvegarde voulez vous charger?                                     "); 
		position.x = 520;
		position.y = 10;
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
		// saisie utilisateur nom du fichier
		position.x = 700;
		position.y = 10;
		mot_saisi_Clavier_SDL(sNom, screen, message, font, position, textColor, fondColor); 
		
		fic = fopen(sNom,"r");
        	if (fic==NULL) {
				// Affichage sauvegarde à charger
				sprintf(phrase2_affiche, "cette sauvegarde n'existe pas                  \n "); 
				position.x = 520;
				position.y = 30;
		afficher_message_interface_SDL (screen, message, phrase2_affiche, font, position, textColor, fondColor);
				
			
			}
			
		}
    	while(fic==NULL);
    
    int i,j;
    int k =0;
   

    do{
      
          for(i=0;i<N;i++)//met la matrice k à la case k du tablea
              for(j=0;j<M;j++){
                  fscanf(fic,"%i ",&matrice3[k][i][j]);
              }
        k++;
        
    }while(!feof(fic));
        
        
    fclose(fic);
        
}
    
    int parcourir(){//retourn 1 si l'utilisateur à charger une partie 0 sinon
    int i,j;
    int k = 0;
    afficher3(k);
    int iCommande=0;
    printf (" entrez 6 pour avancer, 4 pour reculer, 2 pour aller à la fin, 8 pour revenir au début 5 pour charger -1 pour quiter : \n");
    while (iCommande != -1){
        scanf("%i", &iCommande);
        switch (iCommande) {
            case 6:
                
                if (k<(N*M)){
                    k ++;
                    afficher3(k);
                }
                else{
                    afficher3(k);
                    printf("partie terminé");
                }
                break;
            
            case 4:
                if (k>0){
                k --;
                afficher3(k);
                }
                else{
                    afficher3(k);
                    printf("partie terminé");
                }
                break;
                    
           
                    
            case 2:
                    k = P;
                    while (matrice3[k][4][4] == 0){
                        k--;
                    }
                    afficher3(k);
                    break;
                    
                    
            case 8:
                    k =0;
                    afficher3(k);
                    break;
                    
            case 5:
                    for(i=0;i<N;i++){//on met dans la grille les données de la sauvegarde
                        for(j=0;j<M;j++){
                            grille[i][j]=matrice3[k][i][j];
                        }
                    }
                    return 1;
                    
            
            default:
                printf(" erreur d'entré : \n entrez 6 pour avancer, 4 pour reculer, 2 pour aller à la fin, 8 pour revenir au début 5 pour charger -1 pour quiter : \n");
                break;
        }
    }
    return 0;
}


    
