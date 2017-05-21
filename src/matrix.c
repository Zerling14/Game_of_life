#include "matrix.h"
#include "cell.h"
#include <stdlib.h>

Matrix *init_matrix(int size_x, int size_y, char life_cell, char empty_cell)
{
	Matrix *matx = calloc(1, sizeof(Matrix));

	if (matx == NULL) {
		return NULL;
	}

	matx->size_x = size_x;
	matx->size_y = size_y;
	matx->empty_cell = empty_cell;
	matx->life_cell = life_cell;

	matx->cell = calloc(size_x * size_y, sizeof(Cell));
	for (int i = 0; i < size_x * size_y; i++) {
		matx->cell[i] = init_cell(0, life_cell, empty_cell); 
	}
	return matx;
}

void free_matrix(Matrix *matx)
{
	free(matx->cell);
	free(matx);
}