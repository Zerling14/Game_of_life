#ifndef CELL_H
#define CELL_H

typedef struct {
	int state;
	char c;
} Cell;

void mode_cell(Cell *cell, int mode, char ch);

int check_cell(Cell *cell);

#endif