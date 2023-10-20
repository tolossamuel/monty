#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * swap - Swaps data from the top node with the one below it.
 *
 * @customStack: The customStack provided by main.
 * @line_num: The number of lines.
 */
void swap(stack_t **customStack, unsigned int line_num)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!customStack || !*customStack || !((*customStack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *customStack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
