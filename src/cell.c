#include "cell.h"

void mode_cell(Cell *cell, int mode, char ch)
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