#include "monty.h"

/**
 * main - Entry point for the LIFO/FILO program
 * @ac: Number of command-line arguments
 * @av: Array of command-line arguments
 * Return: 0 for Success, 1 for Failure
 */
int main(int ac, char **av)
{
char *opcode;

if (ac != 2)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
if (start_vars(&var) != 0)
{
	return (EXIT_FAILURE);
}
var.file_pointer = fopen(av[1], "r");
if (!var.file_pointer)
{
	fprintf(stderr, "Error: Can't open file %s\n", av[1]);
	free_all();
	return (EXIT_FAILURE);
}
while (getline(&var.buffer, &var.temporary_size, var.file_pointer) != EOF)
{
	opcode = strtok(var.buffer, " \r\t\n");
	if (opcode != NULL)
	{
		if (call_funct(&var, opcode) == EXIT_FAILURE)
		{
			free_all();
			return (EXIT_FAILURE);
		}
	}
	var.current_line_number++;
}
free_all();
return (EXIT_SUCCESS);
}
