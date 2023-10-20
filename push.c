#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - Inserts an element into the customStack.
 *
 * @customStack: The customStack provided by main.
 * @line_num: The total number of lines.
 */
void push(stack_t **customStack, unsigned int line_num)
{
	char *n = global.argument;

	if ((isDigit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	if (global.stackMode == 1)
	{
		if (!addBeginning(customStack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!Queue(customStack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}
