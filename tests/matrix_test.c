#include <ctest.h>
#include <matrix.h>
#include <cell.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

CTEST(matrix, init_matrix_1)
{
	Matrix *matx = init_matrix(10, 10, '0', '.');

	ASSERT_NOT_NULL(matx);
}

CTEST(matrix, init_matrix_2)
{
	Matrix *matx = init_matrix(10, 10, '0', '.');

	int x = 10;
	
	ASSERT_EQUAL(matx->size_x, x);
}

CTEST(matrix, init_matrix_3)
{
	Matrix *matx = init_matrix(10, 10, '0', '.');

	int y = 10;

	ASSERT_EQUAL(matx->size_y, y);
}

CTEST(matrix, init_matrix_4)
{
	Matrix *matx = init_matrix(10, 10, '0', '.');

	char life = '0';

	ASSERT_EQUAL(matx->life_cell, life);
}

CTEST(matrix, init_matrix_5)
{
	Matrix *matx = init_matrix(10, 10, '0', '.');

	char empty = '.';

	ASSERT_EQUAL(matx->empty_cell, empty);
}

CTEST(matrix, init_matrix_6)
{
	Matrix *matx = malloc(sizeof(Matrix));

	int x = 1, y = 1;
	matx->cell = calloc(x * y, sizeof(Cell));
	
	ASSERT_NOT_NULL(matx->cell);
}

CTEST(matrix, init_matrix_7)
{
	Matrix *matx = init_matrix(10, 10, '0', '.');

	int count = 0;
	for (int i = 0; i < matx->size_y * matx->size_x; i++) {
		if (matx->cell[i].state == 1) {
			count++;
		}
	}

	ASSERT_EQUAL(count, 0);
}

CTEST(matrix, copy_matrix)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 10;

	Matrix *matx_orig = init_matrix(size_x, size_y, life_cell, empty_cell);

	for (int i = 0; i < 5; i++) {
		matx_orig->cell[i].state = 1;
	}

	Matrix *matx_cpy = init_matrix(size_x, size_y, life_cell, empty_cell);

	copy_matrix(matx_cpy, matx_orig);

	int count = 0;
	for (int i = 0; i < 5; i++) {
		if (matx_cpy->cell[i].state == 0) {
			count++;
		}
	}
	ASSERT_EQUAL(count, 0);
}

CTEST(matrix, read_file_1)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 10;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	FILE *write_test = fopen("test.txt", "w");
	fprintf(write_test, "%c %c %d %d\n", '.', '0', 5, 1);
	fprintf(write_test, "%d %d %d %d %d\n", 1, 1, 1, 1, 1);
	fclose(write_test);

	read_file("test.txt", matx);

	system("rm test.txt");

	ASSERT_EQUAL(matx->empty_cell, '.');
}

CTEST(matrix, read_file_2)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 10;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	FILE *write_test = fopen("test.txt", "w");
	fprintf(write_test, "%c %c %d %d\n", '.', '0', 5, 1);
	fprintf(write_test, "%d %d %d %d %d\n", 1, 1, 1, 1, 1);
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
	fprintf(write_test, "%c %c %d %d\n", '.', '0', 5, 1);
	fprintf(write_test, "%d %d %d %d %d\n", 1, 1, 1, 1, 1);
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
	fprintf(write_test, "%c %c %d %d\n", '.', '0', 5, 1);
	fprintf(write_test, "%d %d %d %d %d\n", 1, 1, 1, 1, 1);
	fclose(write_test);

	read_file("test.txt", matx);

	system("rm test.txt");

	ASSERT_EQUAL(matx->size_x, 5);
}

CTEST(matrix, read_file_5)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 10;
	int size_y = 10;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	FILE *write_test = fopen("test.txt", "w");
	fprintf(write_test, "%c %c %d %d\n", '.', '0', 5, 1);
	fprintf(write_test, "%d %d %d %d %d\n", 1, 1, 1, 1, 1);
	fclose(write_test);

	read_file("test.txt", matx);

	system("rm test.txt");

	int count = 0;
	for (int i = 0; i < 5; i++) {
		if (matx->cell[i].state == 0) {
			count++;
		}
	}

	ASSERT_EQUAL(count, 0);
}

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

	ASSERT_EQUAL(empty, '.');
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
	ASSERT_EQUAL(life, '0');
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

	int test_x;
	fseek(test, 4, SEEK_SET);
	fscanf(test, "%d", &test_x);
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

	int test_y;
	fseek(test, 6, SEEK_SET);
	fscanf(test, "%d", &test_y);
	fclose(test);
	system("rm test.txt");

	ASSERT_EQUAL(test_y, size_y);
}

CTEST(matrix, write_file_5)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 5;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	write_file("test.txt", matx);

	FILE *test = fopen("test.txt", "r");

	fseek(test, 7, SEEK_SET);

	int test_array[5];

	fscanf(test, "%d %d %d %d %d", &test_array[0], &test_array[1], &test_array[2], &test_array[3], &test_array[4]);
	fclose(test);
	system("rm test.txt");

	int count = 0;
	for (int i = 0; i < 5; i++) {
		if (test_array[i] == 1) {
			count++;
		}
	}

	ASSERT_EQUAL(count, 0);
}

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

	int count = 0;
	for (int i = new_size_x + 1; i < new_size_x * new_size_y; i++) {
		if (matx->cell[i].state == 1) {
			count++;
		}
	}

	ASSERT_EQUAL(count, 0);
}

CTEST(matrix, rules_matx)
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 3;
	int size_y = 3;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);

	matx->cell[1].state = 1;
	matx->cell[3].state = 1;
	matx->cell[5].state = 1;

	rules_matx(matx);

	int res[] = {0, 1, 0, 0, 1, 0, 0, 0, 0};

	int count = 0;
	for (int i = 0; i < size_y * size_x; i++) {
		if (matx->cell[i].state != res[i]) {
			count++;
		}
	}

	ASSERT_EQUAL(count, 0);
}