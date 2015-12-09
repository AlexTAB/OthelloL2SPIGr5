
CC=gcc
CFLAGS=-Wall -O


othello: determinePlacePossible.o Convertir.o verifieFinPartie.o initialisation_grille.o GestionFichier.o score.o main.o
	$(CC) -o othello determinePlacePossible.o Convertir.o verifieFinPartie.o initialisation_grille.o GestionFichier.o score.o main.o 

main.o: main.c determinePlacePossible.h Convertir.h verifieFinPartie.h initialisation_grille.h GestionFichier.h score.h
	$(CC) -o main.o -c main.c $(CFLAGS)

determinePlacePossible.o: determinePlacePossible.c
	$(CC) -o determinePlacePossible.o -c determinePlacePossible.c $(CFLAGS)

Convertir.o: Convertir.c
	$(CC) -o Convertir.o -c Convertir.c $(CFLAGS)

verifieFinPartie.o: verifieFinPartie.c
	$(CC) -o verifieFinPartie.o -c verifieFinPartie.c $(CFLAGS)

initialisation_grille.o: initialisation_grille.c
	$(CC) -o initialisation_grille.o -c initialisation_grille.c $(CFLAGS)

GestionFichier.o: GestionFichier.c
	$(CC) -o GestionFichier.o -c GestionFichier.c $(CFLAGS)

score.o: score.c
	$(CC) -o score.o -c score.c $(CFLAGS)

clean:
	rm -f *.o core
mrproper: clean
	rm -f $(EXEC)
