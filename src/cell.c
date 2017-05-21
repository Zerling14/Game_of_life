#include "cell.h"

void mode_cell(Cell *cell, int mode, char ch)
{
	cell->state = mode;
	cell->c = ch;
}

int check_cell(Cell *cell)
{
	return cell->state;
}