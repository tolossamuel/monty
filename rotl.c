#include "monty.h"

/**
 * rotl - Rotates the first element of the customStack.
 *
 * @customStack: The head of the customStack.
 * @line_num: The line count.
 */
void rotl(stack_t **customStack, unsigned int line_num)
{
	stack_t *top;
	stack_t *end;

	(void) line_num;
	if (!customStack || !*customStack || !(*customStack)->next)
	return;

	top = end = *customStack;

	while (end->next)
	end = end->next;
	end->next = top;
	top->prev = end;
	*customStack = top->next;
	(*customStack)->prev->next = NULL;
	(*customStack)->prev = NULL;
}
