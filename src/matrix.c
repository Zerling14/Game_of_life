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

Cell *get_cell_from_matrix(Matrix *matx, int x, int y)
{
	return matx->cell + matx->size_y * y + x;
}

void free_matrix(Matrix *matx)
{
	free(matx->cell);
	free(matx);
}

void copy_matrix(Matrix *matx_des, Matrix *matx_src)
{
	for (int y = 0; y < matx_src->size_y; y++) {
		for (int x = 0; x < matx_src->size_x; x++) {
			matx_des->cell[x + matx_src->size_y * y] = matx_src->cell[x + matx_src->size_y * y];
		}
	}
}

void read_file(char *name_file, Matrix *matx)
{
	FILE *in = fopen(name_file, "r");

	for (int y = 0; y < matx->size_y; y++) {
		for (int x = 0; x < matx_size_x; x++) {
			fscanf(in, "%c", matx->cell[x + matx->size_y * y]);
			if (matx->cell[x + matx->size_y * y] == '\n') {
				x--;
				continue;
			}	
		}
	}
	
	fclose(in);
}