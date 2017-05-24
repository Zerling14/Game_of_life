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

char **tokenize(char *str, int *token_num)
{
	char **tokens = calloc(10, sizeof(char*));
	int tok_p = 0;
	tokens[tok_p] = strtok(str, " ");
	tok_p++;
	while (tokens[tok_p - 1] != NULL) {
		//printf("%s\n", tokens[tok_p - 1]);
		tokens[tok_p] = strtok (NULL, " ");
		tok_p++;
	}
	*token_num = tok_p - 1;
	return tokens;
}

void menu(Matrix *matx)
{
	char answer[200];
	char tmp_answer[200];
	while (1) {
		printf("command: ");
		//scanf("%s", answer);
		fgets(answer, 200, stdin);
		
		if (answer[strlen(answer) - 1] == '\n') {
			answer[strlen(answer) - 1] = 0;
		}
		if (!strcmp(answer, "next") || answer[0] == '\0') {
			strcpy(answer, tmp_answer);
		}
		strcpy(tmp_answer, answer);
		if (!strcmp(answer, "help")) {
			print_help();
			continue;
		}

		if (!strcmp(answer, "calc")) {
			rules_matx(matx);
			continue;
		}

		if (!strcmp(answer, "print")) {
			//system("clear");
			print_matrix(matx);
			continue;
		}

		if (!strcmp(answer, "write")) {

			char name_file[100];

			printf("Enter to name of file: ");
			fgets(name_file, 100, stdin);
			write_file(name_file, matx);

			printf("Complete.\n");

			continue;
		}
		if (!strcmp(answer, "read")) {

			char name_file[100];

			printf("Enter to name of file: ");
			fgets(name_file, 100, stdin);
			read_file(name_file, matx);

			printf("Complete.\n");

			continue;
		}
		if (!strcmp(answer, "exit")) {
			break;
		}
		print_help();
	}
}

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

	menu(matx);

	free_matrix(matx);
	return 0;
}
