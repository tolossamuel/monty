#include "monty.h"

/**
 * pint - Print last list
 * @stack_list: A doubly linked list
 * @line_num: The line number in the file being executed
 */
void pint(stack_t **stack_list, unsigned int line_num)
{
if (!*stack_list)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
free_all();
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack_list)->n);
}

/**
 * pall - Print the elements in a doubly linked list
 * @stack_list: A doubly linked list
 * @line_num: The line number in the file being executed
 */
void pall(stack_t **stack_list, unsigned int line_num)
{
stack_t *temporary_size = *stack_list;
(void) line_num;

if (!temporary_size)
return;
while (temporary_size)
{
printf("%d\n", temporary_size->n);
temporary_size = temporary_size->next;
}
}
