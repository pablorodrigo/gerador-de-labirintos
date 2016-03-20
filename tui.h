#ifndef TUI_H
#define TUI_H

#include "labirinto.h"
#include "arquivador.h"
#include <stdio.h>

//metodo para imprimir uma matriz
void print(Labirinto labirinto);

//metodos para iniciar e terminar o ncurses
void starttui();
void closetui();

void printstd(Labirinto labirinto);
#endif
