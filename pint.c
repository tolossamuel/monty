#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * pint - Displays the value at the head of the customStack
 * @customStack: The customStack originating from the main function in start.c
 * @line_num: The total lines
 */
void pint(stack_t **customStack, unsigned int line_num)
{
	if (!customStack || !(*customStack))
	{
		fprintf(stderr, "L%d: can't pint, customStack empty\n", line_num);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*customStack)->n);
}
