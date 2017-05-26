#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "cell.h"
#include <string.h>
#include <ctype.h>

#ifdef WIN32
	#include <conio.h>
#elif __linux__
	#define CSI "\x1B\x5B"	
	
	char colors[][5] = {
	"0;30", /* Black */ "1;30", /* Dark Gray */
	"0;31", /* Red */ "1;31", /* Bold Red */
	"0;32", /* Green */ "1;32", /* Bold Green */
	"0;33", /* Yellow */ "1;33", /* Bold Yellow */
	"0;34", /* Blue */ "1;34", /* Bold Blue */
	"0;35", /* Purple */ "1;35", /* Bold Purple */
	"0;36", /* Cyan */ "1;36" /*Bold Cyan */ };
	int colors_sz = sizeof(colors) / sizeof(colors[0]);
#endif





void print_help()
{
	#ifdef __linux__
		printf("%s%sm", CSI, colors[9]);
	#endif
	printf("help\t: displays help.\n");

	printf("next\t: repeats the previous command.\n");
	
	printf("write [file_name]\t: writes the matrix to a file (you must specify a file name)\n");
	
	printf("read [file_name]\t: reads the file containing the matrix and its settings (you must specify a file name)\n");

	printf("loop [repeat_num] [delay]\t: repeats \"calc\" and \"print\", \"repeat_num\" times and with a \"delay\" in sec, delay is maybe float, repeat_num can be zero then the loop will be infinite \n");
	
	printf("calc\t: makes one game step.\n");

	printf("print\t: print matrix in console.\n");
	
	printf("step\t: makes one game step and print matrix in console.\n");
	
	printf("clear\t: clear console.\n");
	
	printf("exit\t: completes the game.\n");
	#ifdef __linux__
		printf("%s0m", CSI);
	#endif
}

void print_get_name_file(char *name_file)
{
	printf("Enter to name of file: ");
	scanf("%s", name_file);
}

int isdigit_str(char *str)
{
	while (*str != 0 && *str != '\n') {
		if (!isdigit(*str)) {
			return 0;
		}
		str++;
	}
	return 1;
}

int isfloat_str(char *str)
{
	int check = 0;
	while (*str != 0 && *str != '\n') {
		if (!isdigit(*str)) {
			if (*str == '.') {
				check++;
			} else {
				return 0;
			}
		}
		str++;
	}
	if (check == 1) {
	return 1;
	} else {
		return 0;
	}
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
		int token_num;
		char **tokens = tokenize(answer, &token_num);
		for (int i = 0; i < token_num; i++) {
			if (!strcmp(tokens[i], "help")) {
				print_help();
				continue;
			}
			
			if (!strcmp(tokens[i], "loop")) {
				float delay_time = 0.5;
				#ifdef WIN32
					int iter_num = 0;
				#elif __linux__ 
					int iter_num = 5;
				#endif
				

				if (token_num - i >= 2 && isdigit_str(tokens[i + 1])) {
					iter_num = atof(tokens[i + 1]);
				}
				if (token_num - i >= 3 && (isdigit_str(tokens[i + 2]) || isfloat_str(tokens[i + 2]))) {
					delay_time = atof(tokens[i + 2]);
				}
				for (int i = 0; (iter_num == 0 || i < iter_num); i++) {
					rules_matx(matx);
					print_matrix(matx);
					char tmp_char[200];
					sprintf(tmp_char, "sleep %f", delay_time);
					system(tmp_char);
					#ifdef WIN32
						if (kbhit()) {
							i = iter_num + 1;
							break;
						}
					#endif
					
				}
				i = i + 2;
				continue;
			}
			
			if (!strcmp(tokens[i], "calc")) {
				rules_matx(matx);
				continue;
			}

			if (!strcmp(tokens[i], "print")) {
				print_matrix(matx);
				continue;
			}
			
			if (!strcmp(tokens[i], "step")) {
				rules_matx(matx);
				print_matrix(matx);
				continue;
			}
			
			if (!strcmp(tokens[i], "clear")) {
				system("clear");
				continue;
			}

			if (!strcmp(tokens[i], "write")) {

				char name_file[100];
				if (token_num - i == 1) {
					printf("Enter to name of file: ");
					fgets(name_file, 100, stdin);
				} else {
					strcpy(name_file, tokens[i + 1]);
					i++;
				}
				
				if (name_file[strlen(name_file) - 1] == '\n') {
						name_file[strlen(name_file) - 1] = 0;
				}
				write_file(name_file, matx);

				printf("Complete.\n");

				continue;
			}
			if (!strcmp(tokens[i], "read")) {

				char name_file[100];
				if (token_num - i == 1) {
					printf("Enter to name of file: ");
					fgets(name_file, 100, stdin);
				} else {
					strcpy(name_file, tokens[i + 1]);
					i++;
				}
				
				if (name_file[strlen(name_file) - 1] == '\n') {
					name_file[strlen(name_file) - 1] = 0;
				}
				read_file(name_file, matx);

				printf("Complete.\n");

				continue;
			}
			if (!strcmp(tokens[i], "exit") || !strcmp(tokens[i], "quit")) {
				return;
			}
			print_help();
		}
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
