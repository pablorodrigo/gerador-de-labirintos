#ifndef LABIRINTO_H
#define LABIRINTO_H

#include <stdlib.h>
#include <string.h>
#include "error.h"

#define INVALID 0X00
#define SPACE 0x01
#define WALL 0x02
#define BEGIN 0x04
#define END 0x08

typedef struct {
	int linhas, colunas;
	char *mapa;
} Labirinto;

Labirinto novoLabirinto(int linhas, int colunas);
void destroiLabirinto(Labirinto labirinto);

#endif
