#ifndef MATRIX_H
#define MATRIX_H
#include "cell.h"

typedef struct {
	int size_x;
	int size_y;
	Cell *matrix;
} Matrix;



#endif