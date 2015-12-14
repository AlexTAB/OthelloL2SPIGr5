//
//  Convertir.h
//  
//
//  Created by Nicolai Murdo on 07/12/2015.
//
//
/*de colone chercher les même couleur et entre deux même couleur il y a au minimum 1 pion diffirent, on peut changer les couleurs entre deux mêmes pions */
#define N 8
#define M 8

typedef enum {vide, blanc, noire, possible, le_plus} pion;
typedef struct {int x;int y;} t_coor;

pion grille[N][M];
t_coor coor;

t_coor path_A(pion matrice[N][N],int i,int j, int dx, int dy);

int path_tous(pion matrice[N][N],int i,int j);


int path_A(pion,int,int, int, int);
