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
	int size_y = 10;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);
	if (matx == NULL) {
		printf("Error init matrix\n");
		return 1;
	}

	if (read_file("test_out.txt", matx) == 1) {
		printf("Error read file\n");
		return 1;
	}

	print_matrix(matx);

	free_matrix(matx);
	return 0;
}