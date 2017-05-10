#include "matrix.h"
#include "cell.h"
#include <stdlib.h>

int init_matrix(Matrix *matx, int size_x, int size_y)
{
	matx->cell = calloc(size_x * size_y, sizeof(Cell));
	if (matx->cell) {
		return 0;
	}
	return 1;
}

int add_cells_to_matrix(Matrix *matx, Cell *cell, int size_x, int size_y)
{
	
}