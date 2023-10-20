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
		fprintf(stderr, "L%d: can't f_pchar, customStack empty\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	if (isascii((*customStack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't f_pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*customStack)->n);
}
