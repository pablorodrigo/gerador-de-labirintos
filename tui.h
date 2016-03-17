#ifndef TUI_H
#define TUI_H

#include <ncurses.h>

//metodo para imprimir uma matriz
void print(int lines, int columns, char *map);

//metodos para iniciar e terminar o ncurses
void starttui();
void closetui();

#endif