#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "cell.h"
#include <string.h>

#define MAX_LENGHT_STR 256

void print_help()
{
	printf("Commands:\n");
	printf("next\t: This command executes the game step\n");
	printf("write\t: This command writes the matrix to a file (you must specify a file name)\n");
	printf("read\t: This command reads the file containing the matrix and its settings (you must specify a file name)\n");
}

void print_get_name_file(char *name_file)
{
	printf("Enter to name of file: ");
	scanf("%s", name_file);
}

char *create_tmp_str(char *str)
{
	char *buf = malloc(sizeof(char) * strlen(str) + 1);
	strcpy(buf, str);

	return buf;
}

void start(char *answer)
{
	printf("command: ");
	scanf("%s", answer);
}

void first(char *name_file)
{
	print_get_name_file(name_file);
}

void menu(Matrix *matx)
{
	char *answer = malloc(sizeof(char) * MAX_LENGHT_STR);
	while (1) {
		start(answer);
		//char *buf = create_tmp_str(answer);
		if (!strcmp(answer, "next")) {
			system("clear");

			printf("OLD MATRIX:\n");
			print_matrix(matx);

			rules_matx(matx);

			printf("NOW MATRIX:\n");
			print_matrix(matx);
		
			continue;
		}
		if (!strcmp(answer, "help")) {
			system("clear");
			print_help();
			continue;
		}
		if (!strcmp(answer, "write")) {
			system("clear");

			char *name_file = malloc(sizeof(char) * MAX_LENGHT_STR);
			print_get_name_file(name_file);

			write_file(name_file, matx);

			printf("Complete.\n");

			print_matrix(matx);

			free(name_file);

			continue;
		}
		if (!strcmp(answer, "read")) {
			system("clear");

			char *name_file = malloc(sizeof(char) * MAX_LENGHT_STR);

			print_get_name_file(name_file);
			read_file(name_file, matx);

			printf("Complete.\n");

			print_matrix(matx);

			free(name_file);

			continue;
		}
		if (!strcmp(answer, "exit")) {
			break;
		}
		print_help();
		/*
		if (!strcmp(answer, "\n")) {
			
		}
		*/
	}
	free(answer);
}

int main()
{
	char empty_cell = '.';
	char life_cell = '0';
	int size_x = 1;
	int size_y = 1;

	Matrix *matx = init_matrix(size_x, size_y, life_cell, empty_cell);
	if (matx == NULL) {
		printf("Error init matrix\n");
		return 1;
	}

	char *name_file = malloc(sizeof(char) * MAX_LENGHT_STR);
	first(name_file);

	if (read_file(name_file, matx) == 1) {
		printf("Error read file\n");
		return 1;
	}
	system("clear");
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
	
	menu(matx);

	free_matrix(matx);
	return 0;
}
