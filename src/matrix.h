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

Cell *get_cell_from_matrix(Matrix *matx, int x, int y);

void free_matrix(Matrix *matx);

void copy_matrix(Matrix *matx_des, Matrix *matx_src);

void read_file(char *name_file, Matrix *matx);

void write_file(char *name_file, Matrix *matx);

Matrix *resize_matx(Matrix *matx, int x, int y);

#endif