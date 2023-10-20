#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pop - Removes the top element of the customStack.
 *
 * @customStack: The customStack provided by main in start.c.
 * @line_num: The line number for error messages.
 */
void pop(stack_t **customStack, unsigned int line_num)
{
	stack_t *temporary = NULL;

	if (!customStack || !*customStack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	temporary = (*customStack)->next;
	free(*customStack);
	*customStack = temporary;
	if (!*customStack)
	return; /* prevents errors cause next line might assign a NULL */
	(*customStack)->prev = NULL;
}
