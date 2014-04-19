#include "Partie.h"

int nextPlayer(int index)  {
	int nextPlayer[] = {0, 2, 1};
	return nextPlayer[index];
}

int playerPion(int index)  {
	int nextPlayer[] = {0, 0, 1};
	return nextPlayer[index];
}