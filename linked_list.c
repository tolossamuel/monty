#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * Queue - Adds a node to a customStack in a queue-like manner.
 *
 * @customStack: The head of the customStack.
 * @n: The number of the node to be added.
 *
 * Return: The newly created node. If memory allocation fails, the function
 * returns NULL.
 */
stack_t *Queue(stack_t **customStack, const int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *current = *customStack;

	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->n = n;

	if (!*customStack)
	{
		new->next = NULL;
		new->prev = NULL;
		*customStack = new;
		return (new);
	}

	while (current)
	{
		if (!current->next)
		{
			new->next = NULL;
			new->prev = current;
			current->next = new;
		break;
	}
	current = current->next;
	}

	return (new);
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

/**
 * printStack - Displays the contents of a stack_t customStack.
 *
 * @customStack: The head of the customStack.
 *
 * Return: The number of elements in the list.
 */
size_t printStack(const stack_t *customStack)
{
	size_t c = 0;

	while (customStack)
	{
		printf("%d\n", customStack->n);
		customStack = customStack->next;
		c++;
	}

	return (c);
}

/**
 * freeStack - Deallocates memory for a customStack.
 *
 * @customStack: The head of the list.
 *
 * Returns: void
 */
void freeStack(stack_t *customStack)
{
	stack_t *current = customStack;
	stack_t *next;

	if (customStack)
	{
		next = customStack->next;
		while (current)
		{
			free(current);
			current = next;
			if (next)
			next = next->next;
		}
	}
}
