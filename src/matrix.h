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

int init_matrix(Matrix *matx, int size_x, int size_y);

#endif
