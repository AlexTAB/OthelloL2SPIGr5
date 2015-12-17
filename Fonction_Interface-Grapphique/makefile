
CC=gcc

LIB=
INC=-I/usr/local/include


# obtenu avec sdl-config --cflags --libs

SDLFLAGS_mac=-I/usr/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE -L/usr/local/lib -lSDLmain -lSDL -Wl,-framework,Cocoa

SDLFLAGS_unix=-I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -lSDL -lpthread

SDLFLAGS=$(SDLFLAGS_unix)
$(info $$SDLFLAGS is [${SDLFLAGS}])

#~/algoprog/projet_othello/OthelloL2SPIGr5/OthelloL2SPIGr5/Fonction_Interface-Grapphique

SDLDRAW= -L./SDL_draw-1.2.13/lib/  -lSDL_draw -I./SDL_draw-1.2.13/include/
SDLTTF= -L./SDL_ttf-2.0.11/lib/ -lSDL_ttf -I./SDL_ttf-2.0.11/include/

FLAGS=-g -Wall  $(SDLFLAGS) $(LIB) $(INC) $(SDLDRAW) $(SDLTTF)
$(info $$FLAGS is [${FLAGS}])

all: souristest

souristest: sdltest.c
	$(CC) sdltest.c -o souristest ${FLAGS}  

clean:
	rm -f *.o

