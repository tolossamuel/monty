#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./monty.h"

/**
 * opcode - Executes a function.
 *
 * @customStack: The customStack provided by main.
 * @str: The string to compare.
 * @line_num: The number of lines.
 */
void opcode(stack_t **customStack, char *str, unsigned int line_num)
{
	int counters = 0;

	instruction_t op[] = INSTRUCTIONS;

	if (!strcmp(str, "customStack"))
	{
		global.stackMode = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.stackMode = 0;
		return;
	}

	while (op[counters].opcode)
	{
		if (strcmp(op[counters].opcode, str) == 0)
		{
			op[counters].f(customStack, line_num);
			return;
		}
		counters++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, str);
	exit(EXIT_FAILURE);
}
