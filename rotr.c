#include "monty.h"

/**
 * rotr - Performs a right rotation on the last node of a stack_t customStack.
 * @customStack: The head of the customStack.
 * @line_count: The count of lines.
 */
void rotr(stack_t **customStack, unsigned int line_count)
{
	stack_t *right;
	stack_t *prev;

	(void) line_count;
	if (!customStack || !*customStack || !(*customStack)->next)
		return;

	right = *customStack;

	while (right->next)
	right = right->next;

	prev = right->prev;
	right->next = *customStack;
	right->prev = NULL;
	prev->next = NULL;
	(*customStack)->prev = right;
	*customStack = right;
}
