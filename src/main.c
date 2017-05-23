#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "cell.h"
#include <string.h>

void print_help()
{
	printf("Commands:\n");
	printf("next\t: This command executes the game step\n");
	printf("write\tThis command writes the matrix to a file (you must specify a file name)\n");
	printf("read\tThis command reads the file containing the matrix and its settings (you must specify a file name)\n");
}

void print_get_name_file(char *name_file)
{
	printf("Enter to name of file:\n");
	scanf("%s", name_file);
	//return name_file;
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
		char answer[10];
		printf("command: ");
		scanf("%s", answer);
		if (!strcmp(answer, "next")) {
			system("clear");
			rules_matx(matx);
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
			char *name_file = malloc(sizeof(char) * 10);
			print_get_name_file(name_file);
			write_file(name_file, matx);
			printf("Complete.");
			free(name_file);
			continue;
		}
		if (!strcmp(answer, "read")) {
			system("clear");
			char *name_file = malloc(sizeof(char) * 10);
			print_get_name_file(name_file);
			read_file(name_file, matx);
			printf("Complete.");
			free(name_file);
			continue;
		}
		if (!strcmp(answer, "exit")) {
			break;
		}
		
	}

	free_matrix(matx);
	return 0;
}
