//㉤
#include <stdio.h>
#include <stdlib.h>


typedef struct joueur{char* nom; int victoires; int defaites; int egalites;struct joueur * succ;} t_joueur;//on utilise une liste a sens unic pour stocker tout le classemant
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

void ajout_droit(char nom[20], int victoires, int defaites, int egalites){
    t_joueur * nouv;
	if(liste_vide() || !hors_liste()) {
        
		nouv = malloc(sizeof(t_joueur));
        
		nouv->nom=nom;
        nouv-> victoires=victoires ;
        nouv-> defaites=defaites ;
        nouv-> egalites=egalites ;
        
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

void valeur_elt(char* nom[20], int* victoires, int* defaites, int* egalites) {
    if(!hors_liste()){
        *nom=ec->nom;
        *victoires=ec->victoires;
        *egalites=ec->egalites;
        *defaites=ec->defaites;
    }
}


void savescore(char newnom[20],int resultat){ //fonction qui modifie le tableau des victoires en rajoutant le resultat (1=victoire,0= egalite,-1=defaite)
    FILE * fic;
    char nom[20];
    int victoires, defaites, egalites;
    int bNomTrouve = 0;
    init_liste();
    fic = fopen("Tableau_des_Victoires.txt","r");
    while(!feof(fic)){
        fscanf(fic,"%s ㉤ ", nom);
        fscanf(fic,"%i ㉤ ", &victoires);
        fscanf(fic,"%i ㉤ ", &defaites);
        fscanf(fic,"%i\n", &egalites);
        ajout_droit(nom, victoires, defaites, egalites); //on met la sauvegarde du tableau des victoires dans la list prédifini
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
		
		ajout_droit(newnom, victoires, defaites, egalites);
		}
	fclose(fic);
	fic = fopen("Tableau_des_Victoires.txt","w");//on créer anouveau le tableau des victoires
	en_tete();
	
	while(!hors_liste()){
		valeur_elt(&nom, &victoires, &defaites, &egalites); //on rejout dedans toute la liste 
		fprintf(fic,"%s ㉤ ", nom);
        fprintf(fic,"%i ㉤ ", victoires);
        fprintf(fic,"%i ㉤ ", defaites);
        fprintf(fic,"%i\n", egalites);
	}
	fclose(fic);
	
}
