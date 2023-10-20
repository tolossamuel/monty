#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * sub - Performs subtraction on the first two nodes of the customStack.
 *
 * @customStack: The customStack provided by main.
 * @line_num: Line count.
 */
void sub(stack_t **customStack, unsigned int line_num)
{
	int answer;

	if (!customStack || !*customStack || !((*customStack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	answer = ((*customStack)->next->n) - ((*customStack)->n);
	pop(customStack, line_num);
	(*customStack)->n = answer;
}
