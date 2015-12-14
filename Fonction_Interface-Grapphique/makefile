
CC=gcc

LIB=
INC=-I/usr/local/include


# obtenu avec sdl-config --cflags --libs

SDLFLAGS_mac=-I/usr/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE -L/usr/local/lib -lSDLmain -lSDL -Wl,-framework,Cocoa

SDLFLAGS_unix=-I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -lSDL -lpthread

SDLFLAGS=$(SDLFLAGS_unix)
$(info $$SDLFLAGS is [${SDLFLAGS}])

SDLDRAW= -L/info/etu/l2spi/spi2144/Projet-Othello/OthelloL2SPIGr5/Fonction_Interface-Grapphique/SDL_draw-1.2.13/lib/  -lSDL_draw -I/info/etu/l2spi/spi2144/Projet-Othello/OthelloL2SPIGr5/Fonction_Interface-Grapphique/SDL_draw-1.2.13/include


FLAGS=-g -Wall  $(SDLFLAGS) $(LIB) $(INC) $(SDLDRAW)
$(info $$FLAGS is [${FLAGS}])

all: essaiAffichage essaiAffichageCase

essaiAffichage: essaiAffichage.c
	$(CC) essaiAffichage.c -o essaiAff ${FLAGS}  



essaiAffichageCase: essaiAffichageCase.c
	$(CC) essaiAffichageCase.c -o essaiAffCase ${FLAGS}  

clean:
	rm -f *.o

