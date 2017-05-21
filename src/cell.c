#include "cell.h"

void init_cell(Cell *cell, int mode, char life_char, char empty_char)
{
	cell->life_char_cell = life_char;
	cell->empty_char_cell = empty_char;
	
	mode_cell(cell, mode);
}

void mode_cell(Cell *cell, int mode)
{
	cell->state = mode;
	if (mode) {
		cell->char_cell = cell->life_char_cell;
	} else {
		cell->char_cell = cell->empty_char_cell;
	}
}

int check_cell(Cell *cell)
{
	return cell->state;
}

char char_cell(Cell *cell)
{
	return cell->char_cell;
}