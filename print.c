#include "monty.h"

/**
 * pint - Print last list
 * @stack_list: A doubly linked list
 * @line_num: The line number in the file being executed
 */
void pint(stack_t **stack_list, unsigned int line_num)
{
if (*stack_list == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
fclose(bus.file);
free(bus.content);
free_stack(*stack_list);
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
stack_t *h;
(void)line_num;

h = *stack_list;
if (h == NULL)
return;
while (h)
{
printf("%d\n", h->n);
h = h->next;
}
}

/**
  *nop- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void nop(stack_t **head, unsigned int counter)
{
(void) counter;
(void) head;
}
