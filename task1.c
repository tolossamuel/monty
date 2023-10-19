#include "monty.h"

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
printf("%d\n", temporary_size->value);
temporary_size = temporary_size->next;
}
}

/**
 * push - Insert a new value in list
 * @stack_list: A doubly linked list
 * @line_num: The line number in the file being executed
 */
void push(stack_t **stack_list, unsigned int line_num)
{
stack_t *tm = *stack_list;
char *num;
stack_t *temporary_size = NULL;

num = strtok(NULL, " \r\t\n");
if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
{
fprintf(stderr, "L%u: usage: push integer\n", line_num);
free_all();
exit(EXIT_FAILURE);
}
temporary_size = malloc(sizeof(stack_t));
if (!temporary_size)
{
fprintf(stderr, "Error: malloc failed\n");
free_all();
exit(EXIT_FAILURE);
}
temporary_size->value = atoi(num);
if (var.operation_mode == 0 || !*stack_list)
{
temporary_size->next = *stack_list;
temporary_size->prev = NULL;
if (*stack_list)
	(*stack_list)->prev = temporary_size;
*stack_list = temporary_size;
}
else
{
while (tm->next)
	tm = tm->next;
tm->next = temporary_size;
temporary_size->prev = tm;
temporary_size->next = NULL;
}
}
