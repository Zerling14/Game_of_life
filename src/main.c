#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "cell.h"

int main()
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 5;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);
	if (matx == NULL) {
		printf("Error init matrix\n");
		return 1;
	}

	if (read_file("test_read.txt", matx) == 1) {
		printf("Error read file\n");
		return 1;
	}
	print_matrix(matx);
	
	/*
	for (int i = 0; i < matx->size_x * matx->size_y; i++) {
		if (i % matx->size_y == 0) {
			printf("\n");
		}
		printf("%d ", matx->cell[i].state);
	}
	printf("\n");
	*/
	while (1) {
		rules_matx(matx);

		print_matrix(matx);
		system("read");
	}

	free_matrix(matx);
	return 0;
}
