#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

void fileErrorHandel(char *argv);
void HandelError(void);
int presentStatus = 0;
OpcodeInfo global = {0, NULL};

/**
 * main - The starting point of the program.
 *
 * @argv: A list of arguments provided to the program.
 * @argc: The number of arguments.
 * Return: nothings
 */
int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	unsigned int line_cnt = 1;

	global.stackMode = 1;
	if (argc != 2)
	HandelError();

	file = fopen(argv[1], "r");

	if (!file)
	fileErrorHandel(argv[1]);

	while ((getline(&buffer, &buf_len, file)) != (-1))
	{
	if (presentStatus)
	break;
	if (*buffer == '\n')
	{
	line_cnt++;
	continue;
	}
	str = strtok(buffer, " \t\n");
	if (!str || *str == '#')
	{
	line_cnt++;
	continue;
	}
	global.argument = strtok(NULL, " \t\n");
	opcode(&stack, str, line_cnt);
	line_cnt++;
	}
	free(buffer);
	freeStack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

/**
 * fileErrorHandel - Displays a file error message and terminates the program.
 *
 * @argv: The argv provided by main().
 *
 * Description: Prints a message if it's not possible to open the file.
 */
void fileErrorHandel(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

/**
 * HandelError - Displays a usage message and terminates the program.
 *
 * Description: If the user doesn't provide a file or provides more than one
 * argument to the program.
 */
void HandelError(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
