#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * f_mod - reminder of devisor
 * @customStack: customStack given by main
 * @line_num: line counter
 */
void f_mod(stack_t **customStack, unsigned int line_num)
{
	int answer;

	if (!customStack || !*customStack || !((*customStack)->next))
	{
		fprintf(stderr, "L%d: can't f_mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*customStack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}

	answer = ((*customStack)->next->n) % ((*customStack)->n);
	pop(customStack, line_num);/*For top node*/
	(*customStack)->n = answer;
}
