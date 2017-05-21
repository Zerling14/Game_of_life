#ifndef CELL_H
#define CELL_H

typedef struct {
	int state;
	char empty_char_cell = '.';
	char life_char_cell = '0';
	char char_cell;
} Cell;

void mode_cell(Cell *cell, int mode, char ch);

int check_cell(Cell *cell);

#endif