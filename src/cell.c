#include "cell.h"

void mode_cell(Cell *cell, int mode, char ch)
{
	cell->state = mode;
	if(mode) {
		cell->c = ch;
	} else {
		cell->c = ch;
	}
}

int check_cell(Cell *cell)
{
	return cell->state;
}