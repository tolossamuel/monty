#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * f_pstr - Displays the contents of a stack_t customStack as a string.
 *
 * @customStack: The customStack provided by main.
 * @line_num: Line counter for error messages.
 */
void f_pstr(stack_t **customStack,
unsigned int line_num __attribute__((unused)))
{
	stack_t *current = *customStack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
		{
			break;
		}
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}
