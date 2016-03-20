#include "arquivador.h"


Labirinto readLabirinto(char* pathToFile){
	Labirinto labirinto;
	FILE *file = fopen(pathToFile, "r");
	fscanf(file,"%d %d", &labirinto.linhas, &labirinto.colunas);
	labirinto.mapa = malloc(labirinto.linhas*labirinto.colunas);
	int i=0;
	while(i<labirinto.linhas*labirinto.colunas){
		char c = fgetc(file);
		if(c == WALL_CHAR || c == SPACE_CHAR){
			labirinto.mapa[i] = c;
			i+=1;
		}
	}
	return labirinto;
}


void saveLabirinto(char* pathToFile, Labirinto labirinto){
	FILE *file = fopen(pathToFile,"w");
	fprintf(file, "%d %d", labirinto.linhas, labirinto.colunas);
	int y,x;
	for(y=0;y<labirinto.linhas;y++){
		fputc('\n',file);
		for(x=0;x<labirinto.colunas;x++){
			char c = labirinto.mapa[y*labirinto.colunas+x]==WALL? WALL_CHAR : SPACE_CHAR;
			fputc(c,file);
		}
	}
	fclose(file);
}
