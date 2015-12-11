
CC=gcc

LIB=
INC=-I/usr/local/include


# obtenu avec sdl-config --cflags --libs
SDLFLAGS_mac= -I/usr/local/include/SDL -D_GNU_SOURCE=1 -D_THREAD_SAFE -L/usr/local/lib -lSDLmain -lSDL -Wl,-framework,Cocoa
SDLFALGS_unix=-I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -lSDL -lpthread

SDLFLAGS=$(SDLFALGS_unix)

FLAGS=-g -Wall $(LIB) $(INC) $(SDLFLAGS)

all: essaiAffichage


essaiAffichage: essaiAffichage.c
	$(CC) essaiAffichage.c -o essaiAff $(FLAGS)  

clean:
	rm -f *.o

