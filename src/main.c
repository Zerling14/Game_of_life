#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int main()
{
	// Create to matrix
	srand(time(0));
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 80;
	int size_y = 60;
	Cell matrix[size_y][size_x];
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x	; j++) {
			Cell tmp;
			tmp.state = 0;
			tmp.c = empty_cell;
			matrix[i][j] = tmp;
		}
	}
	return 0;
}