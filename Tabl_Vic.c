
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct joueur{char nom[20]; int victoires; int defaites; int egalites;struct joueur * succ;} t_joueur;//on utilise une liste a sens unic pour stocker tout le classemant
t_joueur * drapeau;
t_joueur * ec;

//primitive de liste
void init_liste (void) {
	drapeau = malloc(sizeof(t_joueur));
    drapeau -> succ = drapeau;
    ec = drapeau;
}

int liste_vide (void) {
    return(drapeau->succ == drapeau);
}

int hors_liste (void) {
    return (ec == drapeau);
}

void en_tete (void) {
    if(!liste_vide())
        ec=drapeau->succ;
}

void suivant(void) {
    if(!hors_liste())
        ec=ec->succ;
}
void ajout_droit(char nom[20], int victoires, int defaites, int egalites){
    t_joueur * nouv;
	if(liste_vide() || !hors_liste()) {
		nouv = malloc(sizeof(t_joueur));
		strcpy(nouv->nom, nom);
        nouv-> victoires=victoires ;
        nouv-> defaites=defaites ;
        nouv-> egalites=egalites ;
        assert(ec != NULL);
		ec->succ = nouv;
		
		ec = nouv;
	}
	

}


void modif_elt(int victoires, int defaites, int egalites) {
    if(!hors_liste()){
        ec->victoires=victoires;
        ec->egalites=egalites;
        ec->defaites=defaites;
    }
}

char* valeur_elt( int* victoires, int* defaites, int* egalites) {
		char* nom;
	    if(!hors_liste()){
		
		nom = malloc(20*sizeof(char));
        strcpy(nom, ec->nom);
        *victoires=ec->victoires;
        *egalites=ec->egalites;
        *defaites=ec->defaites;
        suivant();
        
    }
    return nom;
}


void savescore(char newnom[20],int resultat){ //fonction qui modifie le tableau des victoires en rajoutant le resultat (1=victoire,0= egalite,-1=defaite)
    FILE * fic;
    printf("1");
    fprintf(stderr, "debut savescore\n");
    char nom[20];
    char* nom_sort;
    int victoires, defaites, egalites;
    int bNomTrouve = 0;
    init_liste();
    fic = fopen("Tableau_des_Victoires.txt","r");
    while(!feof(fic)){
        fscanf(fic,"%s ㉤ ", nom);
        fscanf(fic,"%i ㉤ ", &victoires);
        fscanf(fic,"%i ㉤ ", &defaites);
        fscanf(fic,"%i\n", &egalites);
        printf("2");
        
        fprintf(stderr, "avant ajout droit\n");
        
       ajout_droit(nom, victoires, defaites, egalites); //on met la sauvegarde du tableau des victoires dans la list prédifini
		 
		fprintf(stderr, "apres ajout droit\n");
		if(nom==newnom){//si le nom rentre exist deja on modife ses valeurs
			
				if(resultat==1){
					victoires++;
				}
				else if(resultat==0){
					egalites++;
				}
				else{
					defaites++;
				}
					
				modif_elt(victoires,defaites,egalites);
				bNomTrouve=1;
			}
			
    }
    
    if (!bNomTrouve){//si le nom n'existe pas on le rentre avec ses premiers resultats
		victoires=0;
		defaites=0;
		egalites=0;
		
		if(resultat==1){
				victoires++;
				}
		else if(resultat==0){
				egalites++;
				}
		else{
				defaites++;
				}
		 fprintf(stderr, "avant ajout droit 2\n");
		ajout_droit(newnom, victoires, defaites, egalites);
		 fprintf(stderr, "apres ajout droit 2\n");
		}
	fclose(fic);
	fic = fopen("Tableau_des_Victoires.txt","w");//on créer anouveau le tableau des victoires
	fprintf(stderr, "avant en_tete 2\n");
	en_tete();
	fprintf(stderr, "apres fopen 2 \n");
	while(!hors_liste()){
		fprintf(stderr, "apres fopen 2 \n");
		nom_sort = valeur_elt(&victoires, &defaites, &egalites); //on ajout dedans toute la liste 
		fprintf(stderr, "apres valeur_elt 2\n");
		fprintf(fic,"%s ㉤ ", nom_sort);
        fprintf(fic,"%i ㉤ ", victoires);
        fprintf(fic,"%i ㉤ ", defaites);
        fprintf(fic,"%i\n", egalites);
        fprintf(stderr, "fin while 2 \n");
	}
	fprintf(stderr, "apres while");
	fclose(fic);
	fprintf(stderr, "fin savescore\n");
}


