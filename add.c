#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * addNode - Adds a node to the head of the customStack.
 *
 * @customStack: The customStack provided by main.
 * @line_num: Line counter.
 */
void addNode(stack_t **customStack, unsigned int line_num)
{
	int answer;

	if (!customStack || !*customStack || !((*customStack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

		answer = ((*customStack)->next->n) + ((*customStack)->n);
		pop(customStack, line_num); /*For top node*/
	(*customStack)->n = answer;
}
