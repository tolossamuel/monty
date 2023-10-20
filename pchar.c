#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * f_pchar - Print character.
 *
 * @customStack: The customStack provided by main.
 * @line_num: The number of lines.
 */
void f_pchar(stack_t **customStack, unsigned int line_num)
{
	if (!customStack || !(*customStack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*customStack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*customStack)->n);
}

/**
 * pint - Displays the value at the head of the customStack
 * @customStack: The customStack originating from the main function in start.c
 * @line_num: The total lines
 */
void pint(stack_t **customStack, unsigned int line_num)
{
	if (!customStack || !(*customStack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);

	}
	printf("%d\n", (*customStack)->n);
}
