#ifndef CELL_H
#define CELL_H

typedef struct {
	int state;
	char empty_char_cell;
	char life_char_cell;
	char char_cell;
} Cell;

Cell *init_cell(int mode, char life_char, char empty_char);

void mode_cell(Cell *cell, int mode);

int check_cell(Cell *cell);

char char_cell(Cell *cell);

#endif