#ifndef FIELD_H
#define FIELD_H
#include "matrix.h"

typedef struct {
	char empty_cell;
	char life_cell;
	Matrix matrix;
} Field;



#endif