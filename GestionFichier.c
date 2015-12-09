#include<stdio.h>/*
#define N 8
#define M 8

typedef enum {vide,blanc,noire,possible,le_plus} pion;
pion grille[N][M] = {{0,0,0,0,0,0,0,0},{0,2,0,0,0,0,0,0},{0,0,0,0,1,0,0,0},{0,0,2,2,0,0,0,0},{0,1,2,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,2,0,0,0,0},{0,0,0,0,0,0,0,0}};*/


//int grille[N][M] = {{0,0,0,0,2,2,2,2},{0,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{0,0,2,2,0,0,0,0},{0,1,2,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,2,0,0,0,0},{0,0,0,0,2,2,2,2}};

#define N 8
#define M 8

typedef enum {vide, blanc, noire, possible, le_plus} pion;

pion grille[N][M];

void sauvegarde(){//on met la grille dans un fichier entrer par l'utilisateur
    FILE * fic;
    int bSupfic=0;
    int iDemande=0;
    char sNom[20];
    
    
    while (!bSupfic){ //ici sont les option qui vérifie que l'utilisateur sauvegarde bien ou il veut sans suprimer des sauvegardes si il ne voulait pas.
        printf("entrez le nom de votre sauvegarde:  ");
        scanf("%s",sNom);
        if (fopen(sNom,"r")!=NULL){
            printf("cette sauvegarde existe déjé voulez vous la supprimer? \n1:oui\n2:non\n");
            while(iDemande!=1 && iDemande!=2){
                printf("entrez 1 ou 2\n");
                scanf("%i",&iDemande);
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
		printf("sauvegarde réussie \n");
		fclose(fic);
	}
}


void chargement(){//on charge un fichier que l'utilisateur à choisit
    FILE * fic;
    char sNom[20]={0};
    int int_to_pion;//prend le scanf en int pour le metre dans la matrice de pions
    
    do{//verification si sauvegarde existe
		printf("quelle sauvegarde voulez vous charger?\n");   
		scanf("%s",sNom);
		fic = fopen(sNom,"r");
        if (fic==NULL)
			printf("cette sauvegarde n'existe pas\n");
			
    }while(fic==NULL);
    
    int i,j;//on met dans la grille les données de la sauvegarde
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            fscanf(fic,"%i ",&int_to_pion);
            grille[i][j]=int_to_pion;
        }
    }
    fclose(fic);
        
}
    
        
        
       
   /* int main(){
    	//sauvegarde();
		afficher();
        chargement();
        afficher();
        
        return 0;
    }*/
    
