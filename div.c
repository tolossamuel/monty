#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * divTheValues - Divides the previous value in the custom stack.
 *
 * @customStack: The custom stack.
 * @line_num: Line counter.
 */
void divTheValues(stack_t **customStack, unsigned int line_num)
{
int answer;

if (!customStack || !*customStack || !((*customStack)->next))
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
exit(EXIT_FAILURE);
}
if (((*customStack)->n) == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_num);
exit(EXIT_FAILURE);
;
return;
}

answer = ((*customStack)->next->n) / ((*customStack)->n);
pop(customStack, line_num);/*For top node*/
(*customStack)->n = answer;
}
