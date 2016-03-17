/*
 * algoritmo de geracao por busca em profundidade. O algoritimo "cava" o labirinto ate chegar numa deadend, e entao faz um backtrack ate ser possivel cavar novamente. Neste codigo utiliza-se recursao como pilha para o backtrack.
 */

#include "tui.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SPACE 0
#define WALL 1
#define INVALIDO 2
#define NORTE 0
#define SUL 1
#define OESTE 2
#define LESTE 3
#define DEAD_END 4

int LINHAS = 24, COLUNAS = 30;
char *map = NULL;

char mapAt(int y, int x){
	if(x < 0 || x >= COLUNAS || y < 0 || y >= LINHAS){
		return INVALIDO;
	}
	return map[y*COLUNAS +x];
}

char getRandDirection(int y, int x){	
	int size = 0;
	char directions[4];
	if(mapAt(y+1,x) == WALL && mapAt(y+2,x) == WALL && mapAt(y+1,x+1) == WALL && mapAt(y+1,x-1) == WALL){
		directions[size] = SUL;
		size += 1;
	}
	if(mapAt(y-1,x) == WALL && mapAt(y-2,x) == WALL && mapAt(y-1,x+1) == WALL && mapAt(y-1,x-1) == WALL){
		directions[size] = NORTE;
		size += 1;
	}
	if(mapAt(y,x-1) == WALL && mapAt(y,x-2) == WALL && mapAt(y+1,x-1) == WALL && mapAt(y-1,x-1) == WALL){
		directions[size] = OESTE;
		size += 1;
	}
	if(mapAt(y,x+1) == WALL && mapAt(y,x+2) == WALL && mapAt(y-1,x+1) == WALL && mapAt(y+1,x+1) == WALL){
		directions[size] = LESTE;
		size += 1;
	}
	
	if(size == 0)return DEAD_END;
	else {
		return directions[rand()%size];
	}
}

void dig(int y, int x){
	int i;
	map[y*COLUNAS +x] = SPACE;
	for(i=0;i<4;i++){
		int direction = getRandDirection(y,x);
		if(direction == NORTE){
			dig(y-1,x);
		} else if(direction == SUL){
			dig(y+1,x);
		} else if(direction == LESTE){
			dig(y,x+1);
		} else if(direction == OESTE){
			dig(y,x-1);
		} else return;
	}
}

int main(int argc, char **argv){
	sscanf(argv[1], "%d", &LINHAS);
	sscanf(argv[2], "%d", &COLUNAS); 
	map = malloc(LINHAS*COLUNAS);
	memset(map, !SPACE, LINHAS*COLUNAS);
	srand (time(NULL));

	dig(2,2);
	starttui();
	print(LINHAS, COLUNAS, map);
	getch();
	closetui();
	
	free(map);
	return 0;
}