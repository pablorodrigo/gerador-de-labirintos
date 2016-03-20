#include "tui.h"

void printstd(Labirinto labirinto){
	int y,x;
	for(y=0;y<labirinto.linhas;y++){
		int offset = y*labirinto.colunas;
		for(x=0;x<labirinto.colunas;x++){
			long character = labirinto.mapa[offset +x] == WALL? WALL_CHAR: SPACE_CHAR;
			putchar(character);
		}
		puts("");
	}
}
