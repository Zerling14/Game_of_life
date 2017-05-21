#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "cell.h"

int main()
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 1;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);
	if (matx) {
		printf("OK\n");
	}

	write_file("test_out.txt", matx);

	read_file("test_out.txt", matx);

	write_file("test_out_1.txt", matx);

	return 0;
}