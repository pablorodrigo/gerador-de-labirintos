#include "tui.h"

void print(int lines, int columns, char *map){
	int y,x;
	for(y=0;y<lines;y++){
		int offset = y*columns;
		for(x=0;x<columns;x++){
			long character = map[offset +x]? ACS_BLOCK: ' ';
			mvaddch(y,x,character);
		}
	}
	
	refresh();
}

void starttui(){
	initscr();
	attron(A_ALTCHARSET);
}

void closetui(){
	endwin();
}