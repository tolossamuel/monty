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


/**
 * addBeginning - Inserts a node at the beginning of a stack_t customStack.
 *
 * @customStack: The head of the customStack.
 * @n: The value for the new node.
 *
 * Returns: The newly created node; if creation is unsuccessful,
 * the function will return NULL.
 * Return: stack_t new
 */
stack_t *addBeginning(stack_t **customStack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	new->n = n;

	new->next = *customStack;
	new->prev = NULL;
	if (*customStack)
	(*customStack)->prev = new;

	*customStack = new;

	return (new);
}
