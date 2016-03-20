#include "generators/generator.h"
#include "io/tui.h"
#include "io/arquivador.h"

int main(int argc, char **argv){
	int linhas, colunas;
	int metodo = 0;
	if(argc >= 3){
		sscanf(argv[1], "%d", &linhas);
		sscanf(argv[2], "%d", &colunas); 
		if(argc>=4){
			sscanf(argv[3], "%d", &metodo);
		}
	} else {
		puts("quantidade de argumentos invalido");
		exit(1);
	}
	
	Labirinto labirinto = novoLabirinto(linhas,colunas);
	
	srand (time(NULL));

	if(metodo == 0){
		dfsGenerate(labirinto);
	} else if(metodo == 1){
		btreeGenerate(labirinto);
	} else {
		puts("metodo não implementado");
		return 1;
	}
	
	saveLabirinto("labirinto.txt", labirinto);
	printstd(labirinto);
	
	destroiLabirinto(labirinto);
	return 0;
}
