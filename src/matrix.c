#include "matrix.h"
#include "cell.h"
#include <stdlib.h>
#include <stdio.h>

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

int read_file(char *name_file, Matrix *matx)
{
	FILE *in = fopen(name_file, "r");
	if (in == NULL) {
		return 1;
	}
	int new_x, new_y;
	fscanf(in, "%c %c %d %d", &matx->empty_cell, &matx->life_cell, &new_x, &new_y);

	if (resize_matx(matx, new_x, new_y) == NULL) {
		return 1;
	}

	for (int y = 0; y < matx->size_y; y++) {
		for (int x = 0; x < matx->size_x; x++) {
			int tmp;
			fscanf(in, "%d", &tmp);
			mode_cell(matx->cell + (x + matx->size_y * y), tmp);
			if (tmp == '\n') {
				x--;
			}	
		}
	}
	fclose(in);
	return 0;
}

int write_file(char *name_file, Matrix *matx)
{
	FILE *out = fopen(name_file, "w");	
	if (out == NULL) {
		return 1;
	}
	fprintf(out, "%c %c %d %d\n", matx->empty_cell, matx->life_cell, matx->size_x, matx->size_y);
	for (int y = 0; y < matx->size_y; y++) {
		for (int x = 0; x < matx->size_x; x++) {
			fprintf(out, "%d", matx->cell[x + matx->size_y * y].state);
		}
		fprintf(out, "\n");
	}
	fclose(out);
	return 0;
}

Matrix *resize_matx(Matrix *matx, int x, int y)
{
	matx->size_x = x;
	matx->size_y = y;

	matx->cell = realloc(matx->cell, x * y * sizeof(Cell));

	if (!matx->cell) {
		return NULL;
	}

	return matx;
}

void print_matrix(Matrix *matx)
{
	printf("%c %c %d %d\n", matx->empty_cell, matx->life_cell, matx->size_x, matx->size_y);
	
	for (int y = 0; y < matx->size_y; y++) {
		for (int x = 0; x < matx->size_x; x++) {
			printf("%d", matx->cell[x + matx->size_y * y].char_cell);
		}
		printf("\n");
	}
}