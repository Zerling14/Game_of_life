#include "matrix.h"
#include "cell.h"
#include <stdlib.h>
#include <stdio.h>

#define LIFE 1
#define DEAD 0

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
			if (tmp == '\n') {
				x--;
			}
			matx->cell[x + matx->size_y * y] = init_cell(tmp, matx->life_cell, matx->empty_cell);
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
			fprintf(out, "%d ", matx->cell[x + matx->size_y * y].state);
		}
		fprintf(out, "\n");
	}
	fclose(out);
	return 0;
}

Matrix *resize_matx(Matrix *matx, int x, int y)
{
	matx->cell = realloc(matx->cell, x * y * sizeof(Cell));

	if (!matx->cell) {
		return NULL;
	}

	for (int i = matx->size_y * matx->size_x; i < y * x; i++) {
		matx->cell[i] = init_cell(0, matx->life_cell, matx->empty_cell);
	}

	matx->size_x = x;
	matx->size_y = y;

	return matx;
}

void print_matrix(Matrix *matx)
{
	printf("%c %c %d %d\n", matx->empty_cell, matx->life_cell, matx->size_x, matx->size_y);
	
	for (int y = 0; y < matx->size_y; y++) {
		for (int x = 0; x < matx->size_x; x++) {
			printf("%c ", matx->cell[x + matx->size_y * y].char_cell);
		}
		printf("\n");
	}
}

Matrix *rules_matx(Matrix *matx)
{
	Matrix *tmp_matx = init_matrix(matx->size_x, matx->size_y, matx->life_cell, matx->empty_cell);
	if (!tmp_matx) {
		return NULL;
	}

	copy_matrix(tmp_matx, matx);

	for (int y = 0; y < matx->size_y; y++) {
		for (int x = 0; x < matx->size_x; x++) {
			int count = 0;
			int local = x + matx->size_y * y;
			for (int local_y = y - 1; local_y <= y + 1; local_y++) {
				if (local_y < 0) {
					continue;
				}
				if (local_y >= matx->size_y) {
					continue;
				}
				for (int local_x = x - 1; local_x <= x + 1; local_x++) {
					if (local_x < 0) {
						continue;
					}
					if (local_x >= matx->size_x) {
						continue;
					}

					if (local_x == x && local_y == y) {
						continue;
					}
					if (matx->cell[local_x + matx->size_y * local_y].state == 1) {
						count++;
					}
				}	
			}
			if (matx->cell[local].state == 0 && count == 3) {
				mode_cell(tmp_matx->cell + local, LIFE);
			}
			if (matx->cell[local].state == 1 && (count == 3 || count == 2)) {
				continue;
			}
			if (count < 2 || count > 3) {
				mode_cell(tmp_matx->cell + local, DEAD);
			}
		}
	}
	
	copy_matrix(matx, tmp_matx);

	return matx;
}
