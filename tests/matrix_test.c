#include <ctest.h>
#include <matrix.h>
#include <cell.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(matrix, init_matrix_1)
{
	Matrix *matx = malloc(sizeof(Matrix));

	ASSERT_NOT_NULL(matx);
}

CTEST(matrix, init_matrix_2)
{
	Matrix *matx = malloc(sizeof(Matrix));

	int x = 10;
	matx->size_x = x;
	
	ASSERT_EQUAL(matx->size_x, x);
}


CTEST(matrix, init_matrix_3)
{
	Matrix *matx = malloc(sizeof(Matrix));

	int y = 10;
	matx->size_y = y;

	ASSERT_EQUAL(matx->size_y, y);
}

CTEST(matrix, init_matrix_4)
{
	Matrix *matx = malloc(sizeof(Matrix));

	char life = '0';
	matx->empty_cell = life;

	ASSERT_STR(&matx->empty_cell, &life);
}

CTEST(matrix, init_matrix_5)
{
	Matrix *matx = malloc(sizeof(Matrix));

	char empty = '.';
	matx->life_cell = empty;

	ASSERT_STR(&matx->life_cell, &empty);
}

CTEST(matrix, init_matrix_6)
{
	Matrix *matx = malloc(sizeof(Matrix));

	int x = 1, y = 1;
	matx->cell = calloc(x * y, sizeof(Cell));
	
	ASSERT_NULL(matx->cell);
}

CTEST(matrix, init_matrix_7)
{
	Matrix *matx = malloc(sizeof(Matrix));

	int x = 1, y = 1;
	char life = '0', empty = '.';

	matx->cell = calloc(x * y, sizeof(Cell));
	for (int i = 0; i < x * y; i++) {
		matx->cell[i] = init_cell(0, life, empty); 
	}
	ASSERT_EQUAL(matx->cell[0].state, 0);
}

CTEST(matrix, init_matrix_8)
{
	Matrix *matx = malloc(sizeof(Matrix));

	int x = 1, y = 1;
	char life = '0', empty = '.';

	matx->cell = calloc(x * y, sizeof(Cell));
	for (int i = 0; i < x * y; i++) {
		matx->cell[i] = init_cell(0, life, empty); 
	}
	ASSERT_STR(&matx->cell[0].life_char_cell, &life);
}

CTEST(matrix, init_matrix_9)
{
	Matrix *matx = malloc(sizeof(Matrix));

	int x = 1, y = 1;
	char life = '0', empty = '.';

	matx->cell = calloc(x * y, sizeof(Cell));
	for (int i = 0; i < x * y; i++) {
		matx->cell[i] = init_cell(0, life, empty); 
	}
	ASSERT_STR(&matx->cell[0].empty_char_cell, &empty);
}
/*
CTEST(matrix, copy_matrix)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 10;

	Matrix *matx_orig = init_matrix(size_x, size_y, life_cell, empty_cell);

	Matrix *matx_cpy = init_matrix(size_x, size_y, life_cell, empty_cell);
	copy_matrix(matx_cpy, matx_orig);

	char arr_orig[size_x * size_y];
	for (int i = 0; i < size_x * size_y; i++) {
		arr_orig[i] = (char)matx_orig->cell[i].state;
	}
	char arr_cpy[size_x * size_y];
	for (int i = 0; i < size_x * size_y; i++) {
		arr_cpy[i] = (char)matx_cpy->cell[i].state;
	}
	ASSERT_DATA(arr_cpy, size_x * size_y, arr_orig, size_x * size_y);
}
*/
CTEST(matrix, read_file_1)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 10;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	FILE *write_test = fopen("test.txt", "w");
	fprintf(write_test, "%c %c %d %d", '.', '0', 5, 1);
	fprintf(write_test, "%d %d %d %d %d", 1, 1, 1, 1, 1);
	fclose(write_test);

	read_file("test.txt", matx);

	system("rm test.txt");

	ASSERT_STR(&matx->empty_cell, ".");
}

CTEST(matrix, read_file_2)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 10;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	FILE *write_test = fopen("test.txt", "w");
	fprintf(write_test, "%c %c %d %d", '.', '0', 5, 1);
	fprintf(write_test, "%d %d %d %d %d", 1, 1, 1, 1, 1);
	fclose(write_test);

	read_file("test.txt", matx);

	system("rm test.txt");

	ASSERT_STR(&matx->life_cell, "0");
}

CTEST(matrix, read_file_3)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 10;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	FILE *write_test = fopen("test.txt", "w");
	fprintf(write_test, "%c %c %d %d", '.', '0', 5, 1);
	fprintf(write_test, "%d %d %d %d %d", 1, 1, 1, 1, 1);
	fclose(write_test);

	read_file("test.txt", matx);

	system("rm test.txt");

	ASSERT_EQUAL(matx->size_x, 5);
}

CTEST(matrix, read_file_4)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 10;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	FILE *write_test = fopen("test.txt", "w");
	fprintf(write_test, "%c %c %d %d", '.', '0', 5, 1);
	fprintf(write_test, "%d %d %d %d %d", 1, 1, 1, 1, 1);
	fclose(write_test);

	read_file("test.txt", matx);

	system("rm test.txt");

	ASSERT_EQUAL(matx->size_x, 1);
}
/*
CTEST(matrix, read_file_5)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 10;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	FILE *write_test = fopen("test.txt", "w");
	fprintf(write_test, "%c %c %d %d", '.', '0', 5, 1);
	fprintf(write_test, "%d %d %d %d %d", 1, 1, 1, 1, 1);
	fclose(write_test);

	read_file("test.txt", matx);

	int array[] = {1, 1, 1, 1, 1};

	system("rm test.txt");

	ASSERT_DATA(matx_cpy->cell, 5, array, 5);
}
*/
CTEST(matrix, write_file_1)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 5;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	write_file("test.txt", matx);

	FILE *test = fopen("test.txt", "r");

	char empty;
	fscanf(test, "%c", &empty);
	fclose(test);
	system("rm test.txt");

	ASSERT_STR(&empty, ".");
}

CTEST(matrix, write_file_2)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 5;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	write_file("test.txt", matx);

	FILE *test = fopen("test.txt", "r");

	char life;
	fseek(test, 2, SEEK_SET);
	fscanf(test, "%c", &life);

	system("rm test.txt");
	fclose(test);
	ASSERT_STR(&life, "0");
}

CTEST(matrix, write_file_3)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 5;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	write_file("test.txt", matx);

	FILE *test = fopen("test.txt", "r");

	char test_x;
	fseek(test, 4, SEEK_SET);
	fscanf(test, "%c", &test_x);
	fclose(test);
	system("rm test.txt");

	ASSERT_EQUAL(test_x, size_x);
}

CTEST(matrix, write_file_4)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 5;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	write_file("test.txt", matx);

	FILE *test = fopen("test.txt", "r");

	char test_y;
	fseek(test, 6, SEEK_SET);
	fscanf(test, "%c", &test_y);
	fclose(test);
	system("rm test.txt");

	ASSERT_EQUAL(test_y, size_y);
}
/*
CTEST(matrix, write_file_5)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 5;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	write_file("test.txt", matx);

	FILE *test = fopen("test.txt", "r");

	char test_x;
	fseek(test, 7, SEEK_SET);

	int test_array[5];

	fscanf(test, "%d %d %d %d %d", test_array[0], test_array[1], test_array[2], test_array[3], test_array[4]);
	fclose(test):
	system("rm test.txt");

	int array[] = {0, 0, 0, 0, 0};

	ASSERT_DATA(matx_cpy->cell, 5, array, 5);
}
*/
CTEST(matrix, resize_matx_1)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 5;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	int new_size_x = 6;
	int new_size_y = 2;

	resize_matx(matx, new_size_x, new_size_y);

	ASSERT_EQUAL(matx->size_x, new_size_x);
}

CTEST(matrix, resize_matx_2)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 5;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	int new_size_x = 6;
	int new_size_y = 2;

	resize_matx(matx, new_size_x, new_size_y);

	ASSERT_EQUAL(matx->size_y, new_size_y);
}
/*
CTEST(matrix, resize_matx_3)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 5;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	int new_size_x = 6;
	int new_size_y = 2;

	resize_matx(matx, new_size_x, new_size_y);

	int array[] = {0, 0, 0, 0, 0, 0};

	ASSERT_DATA(matx_cpy.cell + 0 + new_size_y + 1, 6, array, 6);
}
*/