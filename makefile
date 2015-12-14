
CC=gcc
CFLAGS=-Wall -O

OBJ=grille.o GestionFichier.o score.o main.o


othello: $(OBJ)
	$(CC) -o othello $(OBJ)

main.o: main.c pion.h grille.h GestionFichier.h score.h
	$(CC) -c main.c $(CFLAGS)

grille.o:grille.c 
	$(CC) -c grille.c $(CFLAGS)

GestionFichier.o: GestionFichier.c 
	$(CC) -c GestionFichier.c $(CFLAGS)

score.o: score.c 
	$(CC) -c score.c $(CFLAGS)

clean:
	rm -f *.o core
mrproper: clean
	rm -f $(EXEC)
