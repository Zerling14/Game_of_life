#ifndef MATRIX_H
#define MATRIX_H
#include "cell.h"

typedef struct {
	char empty_cell;
	char life_cell;
	int size_x;
	int size_y;
	Cell *cell;
} Matrix;

Matrix *init_matrix(int size_x, int size_y, char life_cell, char empty_cell);

#endif
	