#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mul - Multiplies values in the customStack.
 *
 * @customStack: The customStack provided by main.
 * @line_num: Line counter.
 */
void mul(stack_t **customStack, unsigned int line_num)
{
	int answer;

	if (!customStack || !*customStack || !((*customStack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	answer = ((*customStack)->next->n) * ((*customStack)->n);
	pop(customStack, line_num);/*For top node*/
	(*customStack)->n = answer;
}
