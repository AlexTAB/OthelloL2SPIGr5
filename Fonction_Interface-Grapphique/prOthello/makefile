
CC=gcc

LIB=
INC=-I/usr/local/include


# obtenu avec sdl-config --cflags --libs

SDLFLAGS_mac=-I/usr/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE -L/usr/local/lib -lSDLmain -lSDL -Wl,-framework,Cocoa

SDLFLAGS_unix=-I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -lSDL -lpthread

SDLFLAGS=$(SDLFLAGS_unix)
$(info $$SDLFLAGS is [${SDLFLAGS}])

SDLDRAW_fac= -L/info/etu/l2spi/spi2144/Projet-Othello/OthelloL2SPIGr5/Fonction_Interface-Grapphique/SDL_draw-1.2.13/lib/  -lSDL_draw -I/info/etu/l2spi/spi2144/Projet-Othello/OthelloL2SPIGr5/Fonction_Interface-Grapphique/SDL_draw-1.2.13/include

SDLDRAW_maison = -L./SDL_draw-1.2.11/lib/  -lSDL_draw -I./SDL_draw-1.2.11/include/
FLAGS=-g -Wall  $(SDLFLAGS) $(LIB) $(INC) $(SDLDRAW_maison)
$(info $$FLAGS is [${FLAGS}])

all: othello


OBJ=grille.o GestionFichier.o score.o main.o Tabl_Vic.o


othello: $(OBJ)
	$(CC) -o othello $(OBJ) $(FLAGS)


main.o: main.c pion.h grille.h GestionFichier.h score.h Tabl_Vic.h
	$(CC) -c main.c $(FLAGS)

grille.o: grille.c grille.h pion.h
	$(CC) -c grille.c  ${FLAGS}

GestionFichier.o: GestionFichier.c 
	$(CC) -c GestionFichier.c $(FLAGS)

score.o: score.c 
	$(CC) -c score.c $(FLAGS)
	
Tabl_Vic.o: Tabl_Vic.c 
	$(CC) -c Tabl_Vic.c $(FLAGS)
	
  

test: ajoutesouris.c
	$(CC) ajoutesouris.c -o test $(FLAGS)

clean:
	rm -f *.o

