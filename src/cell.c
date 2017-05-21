#include "cell.h"
#include <stdlib.h>

Cell init_cell(int mode, char life_char, char empty_char)
{
	Cell cell;

	cell.life_char_cell = life_char;
	cell.empty_char_cell = empty_char;
	
	mode_cell(&cell, mode);
	
	return cell;
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