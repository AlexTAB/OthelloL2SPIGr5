// auteur : Keryann Bussereau

#include <stdlib.h>
#include "liste_ptr.h"
#define N 8
#define M 8
typedef struct element {int puiss[N][M]; struct element * pred; struct element * succ;}t_element;
t_element * drapeau;
t_element * ec;
typedef struct {t_element * drapeau; t_element * ec;}t_liste;

void init_liste (void) {
    /*Crée la liste constituée du seul drapeau */
    drapeau = (t_element *)malloc(sizeof(t_element));
    drapeau -> pred = drapeau;
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

void en_queue (void) {
    if(!liste_vide())
        ec=drapeau->pred;
}

void precedent(void) {
    if(!hors_liste())
        ec=ec->pred;
}

void suivant(void) {
    if(!hors_liste())
        ec=ec->succ;
}

void valeur_elt(int* c, int* p) {
    if(!hors_liste())
        *p=ec->puiss;
}

void modif_elt(int c, int p) {
    if(!hors_liste())
        ec->puiss=p;
}

void oter_elt(void) {
	t_element * temp;
    	if(!hors_liste()) {
        	/* Mise à jour des chainages des voisins */
        	(ec->succ)->pred = ec->pred;
        	(ec->pred)->succ = ec->succ;
        	/* Positionnement sur le prédécesseur */
		temp=ec;
		ec=ec->pred;
		/* Libération de l'élément courant */
        	free(temp);
    	}
}

/*Jusque là ok ensuite à modifier pour les pointeurs*/

void ajout_droit(int c, int p) {
	t_element * nouv;
	if(liste_vide() || !hors_liste()) {
		/* Création du nouvel élément */
		nouv = malloc(sizeof(t_element));
		/* Initialisation du nouvel élément */
		nouv->puiss = p;
		nouv->pred = ec;
		nouv->succ = ec->succ;
		/* Mise à jour des chaînages des voisins */
		(ec->succ)->pred = nouv;
		ec->succ = nouv;
		/* On se positionne sur le nouvel élément */
		ec = nouv;
	}
}

void ajout_gauche(int c, int p) {
    	t_element * nouv;
	if(liste_vide() || !hors_liste()) {
		/* Création du nouvel élément */
		nouv = malloc(sizeof(t_element));
		/* Initialisation du nouvel élément */
		nouv->puiss = p;
		nouv->succ = ec;
		nouv->pred = ec->pred;
		/* Mise à jour des chaînages des voisins */
		(ec->pred)->succ = nouv;
		ec->pred = nouv;
		/* On se positionne sur le nouvel élément */
		ec = nouv;
	}
}
