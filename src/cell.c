#include "cell.h"

void mode_cell(Cell *cell, int mode)
{
	cell->state = mode;
	if(mode) {
		cell->c = '0';
	} else {
		cell->c = '.';
	}
}

int check_cell(Cell *cell)
{
	return cell->state;
}