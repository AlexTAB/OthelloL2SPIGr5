
#include <stdio.h>
#include <stdlib.h>

#define N 8
#define M 8

#include "score.h"
#include "GestionFichier.h"
#include "initialisation_grille.h"
#include "verifieFinPartie.h"
#include "Convertir.h"
#include "determinePlacePossible.h"


typedef enum {vide, blanc, noire, possible, le_plus} pion;

pion grille[N][M];

void passJoueur(int *iJoueur,int *nbJoueur){
    if(*iJoueur==*nbJoueur)//passage joueur
        {(*iJoueur) =1;}
    else
        {(*iJoueur)++;}
}


void NomJoueur(char sNomJ1[30],char sNomJ2[30]){//initialise les noms
    printf("Nom du joueur: ");
    scanf ("%s", sNomJ1);
    printf("adversaire: ");
    scanf ("%s", sNomJ2);
}


void Tour(int joueur,char sNomJ1[30],char sNomJ2[30],int *score1,int *score2){//les tours de jeux
    
    if (joueur == 1){
        printf("C'est au tour de %s de jouer \n", sNomJ1);
    }
    else if(joueur ==2){
        printf("C'est à vous %s \n", sNomJ2);
    }
    
	score(score1,score2);
	printf ("score de %s: %i... score de %s: %i \n",sNomJ1,*score1,sNomJ2,*score2);
    afficher();
    
    int col,lig;
    puts("Please input your pion");
    scanf("%i%i",&lig,&col);
    
    while ( grille[lig][col] != 3){
		printf("entré incorect veulliez resaisir: ");
		scanf("%i%i",&lig,&col);
	
	}
    
    grille[lig][col]=joueur;
    
    puts("");
        path_tous(grille,lig,col);

}

int main(){
	int iJoueur=1;
	int nbJoueur=2;
	int score1,score2;
	char sNomJ1[30], sNomJ2[30];
    initgrille();
    addgrille(3,3,noire);
    addgrille(4,4,noire);
    addgrille(4,3,blanc);
    addgrille(3,4,blanc);
	
	NomJoueur(sNomJ1,sNomJ2);
	while(1){
        afficher();
        determinePlacePossible(iJoueur);
        if(VerifieFinPartie()==0){
            passJoueur(&iJoueur,&nbJoueur);
            determinePlacePossible(iJoueur);
            if(VerifieFinPartie()==0){
                break;//si aucun joueur ne peut jouer on sort du while (fin de jeux)
            }
        }
		Tour(iJoueur,sNomJ1,sNomJ2,&score1,&score2);
        passJoueur(&iJoueur,&nbJoueur);
	}
    return 0;
    
}
