#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
