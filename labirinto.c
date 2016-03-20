#include "labirinto.h"


Labirinto novoLabirinto(int linhas, int colunas){
	if(linhas == 0 || colunas == 0){
		error("novoLabirinto(int,int): numero de linhas ou colunas nao pode ser zero");
	}
	Labirinto labirinto;
	labirinto.linhas = linhas;
	labirinto.colunas = colunas;
	labirinto.mapa = (char*) malloc(linhas*colunas);
	if(labirinto.mapa == NULL){
		error("novoLabirinto(int,int): falha ao alocar memoria");
	}
	memset(labirinto.mapa, WALL, labirinto.linhas*labirinto.colunas);
	return labirinto;
}


void destroiLabirinto(Labirinto labirinto){
	free(labirinto.mapa);
	labirinto.linhas = labirinto.colunas = 0;
}

